#include <bits/stdc++.h>
#include <regex>
using namespace std;

bool solution(){
	string s;
	cin>>s;
	regex s_obj("a|b|(a.*a)|(b.*b)"); 
	if(regex_match(s, s_obj)){ // regex_match(string, regex_obj); 
		return true;
	}else{
		return false;
	}
}


int main(){
	bool ans = solution();
	
	if(ans){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}
	return 0;
}