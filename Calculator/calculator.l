number [0-9]+\.?|[0-9]*\.[0-9]+
%{
char expval = '.';
float op1, op2;
int setval = 0;
char exp_stack[100];
float op_stack[100];
int stackval = -1;
%}
%%
[ ] {}
{number} {
	if(setval == 0){
		sscanf(yytext,"%f",&op1);
		printf("operand1 = %f\n",op1);
		setval = 1;
	} else {
		sscanf(yytext,"%f",&op2);
		printf("operand2 = %f\n",op2);
		float ans = 0;
		switch(expval){
			case '+':
				ans = op1+op2;
				break;
			case '-':
				ans = op1-op2;
				break;
			case '*':
				ans = op1*op2;
				break;
			case '/':
				ans = op1/op2;
		}
		// The program does not check for BODMAS 
		printf("The ans of the expression %f %c %f is %f\n", op1, expval, op2, ans);
		op1 = ans;
		expval = '.';
	}
}
[(] {
	if(expval != '.') {
		stackval++;
		op_stack[stackval] = op1;
		exp_stack[stackval] = expval;
		setval = 0;
		expval = '.';
	}
}
[)] {
	if(stackval >= 0) {
		float ans = 0;
		switch(exp_stack[stackval]){
			case '+':
				ans = op1 + op_stack[stackval];
				break;
			case '-':
				ans = op1 - op_stack[stackval];
				break;
			case '*':
				ans = op1 * op_stack[stackval];
				break;
			case '/':
				ans = op_stack[stackval] / op1;
		}
		printf("The ans of the expression (%f %c %f) is %f\n", op_stack[stackval], exp_stack[stackval], op1, ans);
		op1 = ans;
		stackval--;
	}
}
. {expval = yytext[0];}
\n {setval = 0;}
%%