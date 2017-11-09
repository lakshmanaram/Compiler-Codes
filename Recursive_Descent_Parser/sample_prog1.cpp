#include <bits/stdc++.h>
using namespace std;
bool E();
int start, end;
string expression;
bool match_back(char i){
	if(expression[end] == i) {
		end--;
		return true;
	}
	return false;
}
bool match_front(char i){
	if(expression[start] == i) {
		start++;
		return true;
	}
	return false;
}
bool F(){
	if(!match_back(')')) {
		if(!match_back('i'))
			return false;
		else return true;	
	}
	if(!E()) return false;
	if(!match_back('(')) return false;
	return true;	
}
bool T(){
	if(!F()) return false;
	if(!match_back('*')) return true;
	return T();
}
bool E(){
	if(!T()) return false;
	if(!match_back('+')) return true;
	return E();
}
bool S(){
	if(!match_front('i')) return false;
	if(!match_front('=')) return false;
	return E();
}
int main(){
	cin>>expression;
	start = 0;
	end = expression.size()-1;
	if(S() && start > end){
		cout<<"valid";
	} else cout<<"invalid";
	return 0;
}

/*
Grammar:
S -> i = E
E -> E + T | T
T -> T * F | F
F -> (E) | i

Test case: 
1. i=(i+i)*i
2. i=(i+i)**i
*/