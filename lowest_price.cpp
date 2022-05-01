#include <bits/stdc++.h>
using namespace std;

map<string, pair<int, int>> discount_map;


int get_cost(vector<string>& product){
	int price = stoi(product[0]);
	int minPrice = price;
	for(int i = 1; i < product.size(); i++){
		string discount = product[i];
		
		if(discount != "" && discount != "EMPTY"){
			int type = discount_map[discount].first;
			int discounted_amount = discount_map[discount].second;
			if(type == 0){
				minPrice = min(minPrice, discounted_amount);
				//cout<<"price is now "<<minPrice<<endl;
			}else if(type == 1){
				int rp = round((double)((double)price * ((double)discounted_amount/100.0)));
				minPrice = min(minPrice, price - rp);
				//cout<<"price is now "<<minPrice<<endl;
				
			}else{
				minPrice = min(minPrice, price - discounted_amount);
				cout<<"price is now "<<minPrice<<endl;
			}
		}
	}
	//cout<<"price for "<<product[0]<<" is "<<minPrice<<endl;
	return minPrice;
	
}
pair<string, pair<int, int>> split_discount_string(vector<string>& s){
	return {s[0], {stoi(s[1]), stoi(s[2])}};
}

void load_discounts(vector<vector<string>> &discounts){
	int d = discounts.size();
	for(int i = 0; i < d; i++){
		pair<string, pair<int, int>> data = split_discount_string(discounts[i]);
		discount_map[data.first] = {data.second.first, data.second.second};
	}
	return;
}

int solution(){
	int n, m, d;
	cin>>n>>m>>d;
	vector<vector<string>> products(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			string p;
			cin>>p;
			products[i].push_back(p);
		}
	}
	vector<vector<string>> discounts(d);
	for(int i = 0; i < d; i++){
		for(int j = 0; j < 3; j++){
			string dis;
			cin>>dis;
			discounts[i].push_back(dis);
		}
	}
	//cout<<"input fine"<<endl;
	load_discounts(discounts);
	
	long long int totalPrice = 0;
	for(int i = 0; i < n; i++){
		totalPrice += get_cost(products[i]);
	}
	
	return totalPrice;
	
}

int main(){
	cout<<solution()<<endl;
	return 0;
}