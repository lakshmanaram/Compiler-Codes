#include <bits/stdc++.h>
using namespace std;
class prod{
public:
	char lhs;
	vector<string> rhs;
	set<char> first;
	set<char> follow;
	bool epsilon;
};
set<char> unions(set<char> first, set<char> second){
	// returns unions of two sets
	set<char>::iterator it;
	for(it = second.begin();it!= second.end();it++){
		first.insert(*it);
	}	
	return first;
}
int get_pos(string rule, int c){
	// to find if the rule contains the char c and return it's position
	for(int i=0;i<rule.size();i++)
		if(rule[i] == c)
			return i+1;
	return -1;
}
class Grammar{
public:
	vector<prod> productions;
	map<char, int> symbol_rule; // maintains which symbols belong to which rule
	vector<bool> first_vis; // to keep track of finding first
	vector<bool> follow_vis; // to keep track of finding follows
	Grammar(long n){
		productions.resize(n);
		first_vis.resize(n, false);
		follow_vis.resize(n, false);
		for(int i=0;i<n;i++){
			cout<<"Enter production lhs\n";
			cin>>productions[i].lhs;
			symbol_rule[productions[i].lhs] = i;
			cout<<"Enter number of rules in rhs\n";
			int j;
			cin>>j;
			while(j--){
				cout<<"Enter production rhs\n";
				string rule;
				cin>>rule;
				if(rule != "0")
					productions[i].rhs.push_back(rule);
				// takes care of epsilon production
				else productions[i].epsilon = true; 
			}
		}
	}
	void find_first_for_all(){
		for(int i=0;i<productions.size();i++){
			if(!first_vis[i]){
				first_vis[i] = true;
				productions[i].first = find_first(i);
			}
		}
		// adds epsilon to the first of all production rules that contain epsilon
		for(int i=0;i<productions.size();i++){
			if(productions[i].epsilon) 
				productions[i].first.insert('0');
		}
	}
	set<char> find_first(long i) {
		set<char> ans;
		vector<string> rules = productions[i].rhs;
		for(int j=0;j<rules.size();j++){
			for(int k=0;j<rules[j].size();k++) {
				if(rules[j][k] >= 'A' && rules[j][k] <= 'Z'){
					// non-terminal rules
					int l = symbol_rule[rules[j][0]];
					if(!first_vis[l]) productions[l].first = find_first(l);
					ans = unions(ans, productions[l].first);
					// if the Non-terminal doesn't contain epsilon, the process ends
					// if it contains epsilon, next index is checked
					if(!productions[l].epsilon) break;
				} else {	
					// terminal start
					ans.insert(rules[j][k]);
					break;
				}
			}
		}
		return ans;
	}
	void find_follow_for_all(){
		productions[0].follow.insert('$');
		for(int i=0;i<productions.size();i++){
			// as we insert $ for S
			if(!follow_vis[i]) {
				follow_vis[i] = true;
				productions[i].follow = unions(productions[i].follow, find_follow(i));
			}
		}	
	}
	set<char> find_follow(int n){
		set<char> fol;
		char lhs = productions[n].lhs; // Non-terminal for which follow is found
		for(int i=0;i<productions.size();i++){
			if(i == n)  continue;
			vector<string> rules = productions[i].rhs;
			for(int j = 0; j<rules.size();j++){
				int x = get_pos(rules[j], lhs);	// checks if Non-terminal is found
				if(x == -1) continue; // not found
				else {
					while(x < rules[j].size()) {
						if(rules[j][x] >= 'A' && rules[j][x] <= 'Z'){
							int l = symbol_rule[x];
							fol = unions(fol, productions[l].first);
							if(!productions[l].epsilon) break;
						} else {
							// terminal follow
							fol.insert(rules[j][x]);
							break;
						}
						x++;
					}
					if(x == rules[j].size()){
						if(!follow_vis[i]) productions[i].follow = find_follow(i);
						fol = unions(fol, productions[i].follow);
					}
				}
			}
		}
		return fol;
	}
	void output() {
		for(int i=0;i<productions.size();i++){
			cout<<productions[i].lhs<<" -> ";
			for(int j=0;j<productions[i].rhs.size();j++){
				cout<<productions[i].rhs[j]<<", ";
			}
			if(productions[i].epsilon) cout<<0;
			cout<<endl;
			cout<<"First : ";
			set<char>::iterator it;
			for(it = productions[i].first.begin();it!= productions[i].first.end();it++){
				cout<<*it<<" ";
			}
			cout<<endl;
			cout<<"Follow: ";
			for(it = productions[i].follow.begin();it!= productions[i].follow.end();it++){
				cout<<*it<<" ";
			}
			cout<<endl;
		}	
	}
};
int main(){
	cout<<"Enter number of productions\n";
	int n;
	cin>>n;
	Grammar g(n);
	g.find_first_for_all();
	g.find_follow_for_all();
	g.output();
	
	return 0;
}


/*
Grammar: 
S -> A
A -> Bb | Cd
B -> aB | epsilon
C -> cC | epsilon

Input Format:
4
S 1 A
A 2 Bb Cd
B 2 aB 0
C 2 cC 0
*/
