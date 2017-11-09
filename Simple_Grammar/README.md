### Execution Instructions:

 - ```lex grammar.l```  
creates a lex.yy.c file  
 - ```yacc -d grammar.y```  
creates y.tab.c and y.tab.h  
 - ```cc lex.yy.c y.tab.c -o grammar -ll```  
creates executable calc file

