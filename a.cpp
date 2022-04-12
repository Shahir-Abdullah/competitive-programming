#include <bits/stdc++.h>
using namespace std;

void solution(int caseN){
    vector<vector<unsigned long long int>> v(3, vector<unsigned long long int>(4));
    unsigned long long int sum = 0;
    for(int i = 0; i < 3; i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];
    }
    
    for(int i = 0; i < 4; i++){
        sum += min(v[0][i], min(v[1][i], v[2][i]));
    }
    
    
    
    if(sum < 1000000){
        cout<<"Case #"<<caseN<<": IMPOSSIBLE";
        return;
    }
    unsigned long long int s = 1000000;
    int i = 0;
    cout<<"Case #"<<caseN<<": ";
    while(i<4){
        unsigned long long int tt = min(v[0][i], min(v[1][i], v[2][i]));
        if(s > 0){
            cout<<tt<<" ";
            s -= tt;
        }else{
            cout<<0<<" ";
        }
        i++;
        
    }
    
    return;
}

int main(){
    int t;
    cin>>t;
    int i = 1;
    while(t--){
        solution(i);
        cout<<'\n';
        i++;
    }
    return 0;
}