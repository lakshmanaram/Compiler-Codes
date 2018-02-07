%{ 
	int intcount=0, deccount=0;
%}
digit [0-9]
%%
{digit}+\.{digit}+ {deccount++;}
{digit}+ {intcount++;}
%%
int main() {
	yylex();
	printf("Number of integers : %d\nNumber of decimals : %d\n",intcount, deccount);
	return 0;
}

