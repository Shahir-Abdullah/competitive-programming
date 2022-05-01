vector<int> list_numbers;

void build_sub_array(string s, int leftindex, int rightindex){
	if(rightindex >= s.length())return;
	if(leftindex > rightindex){
		build_sub_array(s, 0, rightindex+1);
	}else{
		
		int number = 0;
		long long int j = 1;
		for(int i = rightindex; i >= leftindex; i--){
			number += (s[i]-'0')*j;
			j *= 10;
		}
		list_numbers.push_back(number);
		
		build_sub_array(s, leftindex+1, rightindex);
	}
	return;
	
}
