int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      vector<int> ple(n, -1);
        vector<int> nle(n, -1);
        //load ple
        stack<int> p_in_stk;
        for(int i = 0; i < n; i++){
            while(!p_in_stk.empty() && arr[p_in_stk.top()] > arr[i]){
                p_in_stk.pop();
            }
            ple[i] = (p_in_stk.empty())?-1:p_in_stk.top();
            p_in_stk.push(i);
        }
        //load nle
        stack<int> n_in_stk;
        for(int i = 0; i < n; i++){
            while(!n_in_stk.empty() && arr[n_in_stk.top()] > arr[i]){
                nle[n_in_stk.top()] = i;
                n_in_stk.pop();
            }
            n_in_stk.push(i);
        }
        int mod = 1e9 +7;
        //for each element i, calculate arr[i]*(nledis*pledis)
        long long int sum = 0;
        for(int i = 0; i < n; i++){
            long long int left = (i-ple[i])%mod;
            long long int right = (nle[i] == -1)? (n-i)%mod : (nle[i]-i)%mod;
            sum = (sum + (left)*(right)*arr[i])%mod;
        }
        return sum;
        //sum 
    }