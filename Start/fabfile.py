import imp
import os
import sys
import glob
import shutil

from fabric.api import *

def import_module(uri, absolute=False):
  if not absolute:
    uri = os.path.normpath(os.path.join(os.path.dirname(__file__), uri))
  path, fname = os.path.split(uri)
  mname, ext = os.path.splitext(fname)
    
  no_ext = os.path.join(path, mname)

  if os.path.exists(no_ext + '.py'):
    try:
      return imp.load_source(mname, no_ext + '.py')
    except Exception as e:
      print str(e)
  else:
    print 'WARNING - file does not exist'

def generate_tests(path):
  testcases = import_module(os.path.join(path, 'testcases.py'))

  test_directory = os.path.join(path, 'input');

  if not os.path.exists(test_directory):
    os.makedirs(test_directory)

  for i, case in enumerate(testcases.cases()):
    filename = 'input{:0>2d}.txt'.format(i)
    filepath = os.path.join(test_directory, filename)
    with open(filepath, 'w') as output:
      output.write(case)

def compile(path, target):
  with lcd(path):
    local('g++ -std=c++11 -O2 -o {0} {0}.cpp'.format(target))

def generate_outputs(path):
  config = import_module(os.path.join(path, 'config.py'))
  compile(path, config.output_generator);

  executable = os.path.join(path, config.output_generator)
  input_directory = os.path.join(path, 'input');
  output_directory = os.path.join(path, 'output');

  if not os.path.exists(output_directory):
    os.makedirs(output_directory)

  input_files = glob.glob(os.path.join(input_directory, 'input*'))

  for input_file in input_files:
    number = input_file[-6:-4]
    output_file = os.path.join(output_directory, 'output' + number + '.txt')
    local('time {0} < {1} > {2}'.format(executable, input_file, output_file))

def zip_testcases(path):
  with lcd(path):
    with settings(hide('everything'), warn_only=True):
      result = local('zip -u -r testcases.zip input output')
      if result.return_code == 12:
        print 'Tests have not changed. Skipping zipping.'

def validate(path, solution):
  compile(path, solution)

  config = import_module(os.path.join(path, 'config.py'))
  executable = os.path.join(path, solution)

  input_directory = os.path.join(path, 'input');
  output_directory = os.path.join(path, 'output-' + solution);
  true_output_directory = os.path.join(path, 'output');

  if not os.path.exists(output_directory):
    os.makedirs(output_directory)

  input_files = glob.glob(os.path.join(input_directory, 'input*'))

  for input_file in input_files:
    number = input_file[-6:-4]
    output_file = os.path.join(output_directory, 'output' + number + '.txt')
    true_output_file = os.path.join(true_output_directory, 'output' + number + '.txt')

    local('time {0} < {1} > {2}'.format(executable, input_file, output_file))
    local('diff -qs {0} {1}'.format(output_file, true_output_file))

  shutil.rmtree(output_directory)

def test_solutions(path):
  config = import_module(os.path.join(path, 'config.py'))

  for solution in config.solutions_to_validate:
    validate(path, solution)

def generate_pdf(path):
  print os.path.join('.', 'template', 'template.py')
  problem = import_module(os.path.join(path, 'problem.py'))
  
  template_file = os.path.join('.', 'template', 'template.tex')
  with open(template_file) as f: document = f.read()

  problem_properties = [item for item in dir(problem) if not item.startswith("__")]

  for problem_property in problem_properties:
    value = getattr(problem, problem_property)
    value = value.strip()
    document = document.replace('@@@{0}@@@'.format(problem_property), value);

  tex_filename = os.path.join('.', 'template', 'problem.tex')

  with open(tex_filename, 'w') as output:
    output.write(document)

  with lcd('template'):
    local('pdflatex problem.tex')
    local('rm *.log *.aux')
    local('rm problem.tex')

  local('mv template/problem.pdf {0}'.format(os.path.join(path, 'problem.pdf')))

def make(path):
  generate_tests(path)
  generate_outputs(path)
  zip_testcases(path)
  test_solutions(path)
  generate_pdf(path)

def rm(path, filename):
  local('rm ' + os.path.join(path, filename))

def clean(path):
  with lcd(path):
    local('rm problem.pdf')
    local('rm testcases.zip')
    local('rm *.pyc')
  
    config = import_module(os.path.join(path, 'config.py'))

    for solution in set(config.solutions_to_validate + [config.output_generator]):
      local('rm ' + solution)

  shutil.rmtree(os.path.join(path, 'input'))
  shutil.rmtree(os.path.join(path, 'output'))
