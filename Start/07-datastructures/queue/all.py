import glob
import os

EXEC = './a.out'

files = glob.glob('testcases/*.in')

for filename in files:
  os.system("{0} < {1}.in > {1}.out".format(EXEC, filename.strip(".in")))
