# -*- coding: utf-8 -*-

problem_name = '''Zadanie A:\\Hello World!'''

sample_output = '''
1 \\newline
1 \\newline
1 \\newline
1 \\newline
1 \\newline
'''

document_template = '''

\\documentclass[
  fontsize=12pt  %%
 ,english        %% 
 ,headinclude    %%
 ,headsepline    %% line between head an document text
%%,BCOR=12mm      %% 
]{scrbook}       %% twosided, A4 paper

\\usepackage[T1]{fontenc}

\\usepackage{polski}
\\usepackage[utf8]{inputenc}
\\usepackage[french,polutonikogreek,polish]{babel}

%%\\geometry{verbose,a4paper,tmargin=3cm,bmargin=2cm,lmargin=2cm,rmargin=2cm}


%%\\usepackage{blindtext} %% provides blindtext with sectioning

\\usepackage{scrpage2}  %% header and footer for KOMA-Script

\\usepackage{graphicx}

\\clearscrheadfoot                 %% deletes header/footer
\\pagestyle{scrheadings}           %% use following definitions for header/footer
%% definitions/configuration for the header
\\rehead[]{\\Large \\textbf{BitAlgo Start}}        %% equal page, right position (inner) 
\\lohead[]{\\Large \\textbf{BitAlgo Start}}        %% odd   page, left  position (inner) 
\\cehead[]{@@@problem_name@@@}
\\cohead[]{@@@problem_name@@@}
\\lehead[]{\\includegraphics[width=15mm]{logo.png}} %% equal page, left (outer) position
\\rohead[]{\\includegraphics[width=15mm]{logo.png}}
%% definitions/configuration for the footer
\\cofoot[\\pagemark]{\\pagemark}     %% odd   page, center position

\\begin{document}
\\vspace{50 mm}
\\hspace{50 mm}
\\newline

\\par{\\Large \\textbf{@@@problem_name@@@}} \\\\ \\\\
@@@problem_statement@@@
\\\\ \\\\
\par{\Large \\textbf{Format wejścia}} \\\\ \\\\
@@@input_format@@@
\\\\ \\\\
\\par{\\Large \\textbf{Format wyjścia}} \\\\ \\\\
@@@output_format@@@
\\\\ \\\\
\\par{\\Large \\textbf{Przykład}} \\\\ \\\\
\\begin{tabular}{ p{7cm} p{7cm} }
  Dla danych wejściowych: \\hspace{40mm}& Poprawną odpowiedzią jest \\\\
& \\\\
\\begin{verbatim}@@@sample_input@@@\\end{verbatim}
&   
%% define output here
\\begin{verbatim}@@@sample_output@@@\\end{verbatim}
\\\\

\\end{tabular}

@@@sample_explanation@@@

\\end{document}

'''