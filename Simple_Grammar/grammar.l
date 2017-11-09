%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
[a] {
; printf(" A ");
return A;
}
[b] {
; printf(" B ");
return B;
}
[(] {
; printf(" ( ");
return BRACKETS_OPEN;
}
[)] {
; printf(" ) ");
return BRACKETS_CLOSED;
}
[*] {
; printf(" * ");
return STAR;
}
[+] {
; printf(" + ");
return PLUS;
}
[\t];
[\n] return 0;
. return yytext[0];
%%
int yywrap()
{
return 1;
}

