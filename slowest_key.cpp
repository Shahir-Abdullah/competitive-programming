#include <bits/stdc++.h>
using namespace std;

void key(){
	
	int n;
	cin>>n;
	vector<int> releaseTimes(n, 0);
	for(int i = 0; i < n; i++){
		cin>>releaseTimes[i];
	}
	string keysPressed;
	cin>>keysPressed;
	char keyPressed = keysPressed[0];
	int longestTime = 0;
	for(int i = 1; i < n; i++){
		if(longestTime <= releaseTimes[i]-releaseTimes[i-1]){
			if(longestTime == releaseTimes[i]-releaseTimes[i-1] && keyPressed < keysPressed[i]){
				longestTime = releaseTimes[i]-releaseTimes[i-1];
				keyPressed = keysPressed[i];
			}else if (longestTime < releaseTimes[i]-releaseTimes[i-1]){
				longestTime = releaseTimes[i]-releaseTimes[i-1];
				keyPressed = keysPressed[i];
			}
			
			
		}
		
	}
	cout<<keyPressed<<endl;
	return;
	
}

int main()
{
	key();
	return 0;
}