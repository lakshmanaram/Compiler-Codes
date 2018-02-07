%%
[0-9]+ {
	int ans = 0;
	int i=0;
	while(i < yyleng){
		ans *= 10;
		ans += (int)(yytext[i]-'0');
		i++;
	}
	printf("%d\n",ans);
	yyleng = 0;
	while(ans){
		if(ans %16 <10)
			yytext[yyleng] = ans%16+'0';
		else if (ans %16 == 10)
			yytext[yyleng] = 'A';
		else if (ans %16 == 11)
			yytext[yyleng] = 'B';
		else if (ans %16 == 12)
			yytext[yyleng] = 'C';
		else if (ans %16 == 13)
			yytext[yyleng] = 'D';
		else if (ans %16 == 14)
			yytext[yyleng] = 'E';
		else if (ans %16 == 15)
			yytext[yyleng] = 'F';
		ans /= 16;
		yyleng++;
	}
	yyleng--;
	while(yyleng >= 0){
		printf("%c",yytext[yyleng]);
		yyleng--;
	}
	printf("\n");

}
%%
