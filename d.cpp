#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

// int m = unique(s.begin(), s.end()) - s.begin(); //removes consecutive same elements and returns the number of unique elements 
//int intlog(double base, double x) { //log of x of base base
//    return (int)(log(x) / log(base));
//}
//int moduler(int base, int power, int mod){ // calculates base^power % mod
//        int x = 1;
//        int e = base%mod;
//        for(int i = 0; i <= 31; i++){
//                if(power & (1<<i)){
//                     x = (x*e)%mod;   
//                }
//                e = (e*e)%mod;
//        }
//        return x;
//}
//int gcd(int a, int b){
//        if(b==0)return a;
//        return gcd(b, a%b);
//}
//int lcm(int a, int b){
//	return (a*b)/gcd(a,b);
//}
//
//bool cmp(pair<long int, long int>& a,
//         pair<long int, long int>& b)
//{
//    return a.second < b.second;
//}
//
//bool cmpPair(pair<long int, long int>&a, pair<long int, long int>&b){
//	return a.first < b.first;
//}
//
//int sortMapOfPairs(vector<int> &A) {
//    unordered_map<long int, long int> m;
//    size_t a_size = A.size();
//    if(a_size == 0)return -1;
//    
//    for(size_t i = 0; i < a_size; i++){
//        m[A[i]]++;
//    }
//
//    vector<pair<long int, long int> > vector_A;
//
//    for (auto& it : m) {
//        vector_A.push_back(it);
//    }
//  
//    
//    sort(vector_A.begin(), vector_A.end(), cmp);
//    
//    
//    return 0;
//    
//}

//void updateNeighbors(vector<vector<int>> &grid, int i, int j){
//	int row = grid.size();
//	int col = grid[0].size();
//	vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//	auto inside = [&](int r, int c){
//		return r >= 0 && r < row && c >= 0 && c < col;
//	};
//	
//	for(pair<int, int> direction : directions){
//		int new_i = i + direction.first;
//		int new_j = j + direction.second;
//		
//		if(inside(new_i, new_j)){
//			grid[new_i][new_j] = 0; // change accordingly 
//		}
//	}
//}


//struct Point{
//	int x;
//	int y;
//};

// find an element in a vector int p = find(a.begin(), a.end(), 1) - a.begin();
// rotate left     rotate(a.begin(), a.begin() + p, a.end());
// rotate right     rotate(a.begin(), a.begin()+a.size() - p, a.end());
//bool checkPalindrome(string s, int i, int j){
//	int len = j-i+1;
//	if(len<2){
//		return false;
//	}
//	for(int k = 0; k < len/2; k++){
//		if(s[i+k] != s[j-k]){
//			return false;
//		}
//	}
//	return true;
//}

//bool checkValidBracket(string s, int i, int j){
//	stack<char> stk;
//	int len = j-i+1;
//	for(int k = i; k <= j; k++){
//		if(s[k] == '('){
//			stk.push(s[k]);
//		}else{
//			if(stk.empty()){
//				return false;
//			}
//			stk.pop();
//		}
//	}
//	if(!stk.empty()){
//		return false;
//	}
//	return true;
//}
// print with precision upto 10 decimal values :  cout<<fixed<<setprecision(10)<<ans<<endl;

//bool cmp(const pair<long long int, long long int> &a, const pair<long long int, long long int>&b){
//	return a.second > b.second;
//}
//
//
//bool isSquare(long long int n){
//	long long int x = sqrt(n);
//	if(x*x == n)return true;
//	return false;
//}


//set <long long> tprimes;
	
//bool isprime(long long int x){
//	if(x == 2)return true;
//	for(long long int i = 2; i*i <= x; i++){
//		if(x%i==0){
//			return false;
//		}
//	}
//	return true;
//}


void solve() {
	int n;
	cin>>n;
	double ans = 0.0;
	while(n>0){
		ans += (1.0/n);
		n--;
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return;
	
}


int main()
{
	IOS;
//	tprimes.insert(4);
//        for (int i = 3; i <= 1000000; i += 2) {
//            if (isprime(i)) {
//                tprimes.insert((long long)i * i);
//            }
//        }
	
//    int t;
//    cin>>t;
//    while(t--){
//    	solve();
//    }
	
	
	solve();
    
    return 0;
    
}

