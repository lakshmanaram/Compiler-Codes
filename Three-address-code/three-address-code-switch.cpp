#include <bits/stdc++.h>
using namespace std;
int main() { 
	cout<<"Enter number of lines: "; 
	long nol;
	cin>>nol;
	vector<string> code(nol);
	getline(cin, code[0]); // for the newlinw entered after entering nol
	for(long i=0;i<nol;i++) {
		getline(cin, code[i]); // so that we can input spaces
	}
	cout<<"Three Address code for the given input:\n\n";
	string condition = code[0].substr(code[0].find('(')+1);
	condition = condition.substr(0,condition.find(')'));
	cout<<"c = "<<condition<<endl;
	for(long i=1;i<nol;i++){
		if(code[i].find("case") != string::npos){
			// if found
			string label = code[i].substr(code[i].find("case ")+5);
			label = label.substr(0, label.find(':'));
			cout<<"If c == "<<label<<" goto L"<<label<<endl;
		}
	}
	for(long i=1;i<nol;i++){
		if(code[i].find("default") != string::npos){
			// if found
			string expression = code[i].substr(code[i].find(':')+2);
			cout<<expression<<endl;
		}
	}
	cout<<"Goto Last\n";
	for(long i=1;i<nol;i++){
		if(code[i].find("case") != string::npos){
			// if found
			string label = code[i].substr(code[i].find("case ")+5);
			label = label.substr(0, label.find(':'));
			cout<<"L"<<label<<":\n";
			string expression = code[i].substr(code[i].find(':')+2);
			cout<<expression<<endl;
		}
	}
	cout<<"Last:"<<endl;
}
/*
input:
6
switch(i+j){  
case 1: x = y+z;
case 2: x = y-z;
case 3: x = y*z;
default: x = y/z;
}
*/