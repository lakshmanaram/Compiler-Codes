%{
#include <stdio.h>
int flag = 0;
%}
%token NUMBER
%token A
%token B
%token BRACKETS_OPEN
%token BRACKETS_CLOSED
%token PLUS
%token STAR

%%

start: E 	{printf("Computed\n"); return 0;}
E:E PLUS T  	{printf("E->E+T\n");}
	| T 	{printf("E->T\n");}
T:T F   	{printf("T->TF\n");}
	| F 	{printf("T->F\n");}
F:F STAR	{printf("F->F*\n");}
	| BRACKETS_OPEN E BRACKETS_CLOSED {printf("F->(E)\n");}
	| A	 {printf("F->a\n");}
	| B	 {printf("F->b\n");}
	

%%

void main()
{
	printf("\nEnter Expression:\n");
	yyparse();
	if(flag == 0)
		printf("\nValid Expression\n");
}

void yyerror()
{
	printf("Invalid expression\n");
	flag = 1;
}

