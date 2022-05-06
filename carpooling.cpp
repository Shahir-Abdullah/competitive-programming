
bool cmp(const pair<int, pair<int, int>>&a, const pair<int, pair<int, int>>&b){
        if(a.first == b.first){
            return a.second.first > b.second.first;
        }
        return a.first < b.first;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int cap = capacity;
        vector<pair<int, pair<int, int>>> trip(2*n);
        int j = 0;
        int open = 0;
        int close = 1;
        for(int i = 0; i < n; i++){
            trip[j++] = {trips[i][1], {open, trips[i][0]}};
            trip[j++] = {trips[i][2], {close, trips[i][0]}};
        }
        
        sort(trip.begin(), trip.end(), cmp);
        
        cout<<endl;
        int currentPassengerCnt = 0;
        for(int i = 0; i < 2*n; i++){
            if(trip[i].second.first == open){
                currentPassengerCnt += trip[i].second.second;
                
            }else{
                currentPassengerCnt -= trip[i].second.second;
            }
            //cout<<"Current "<<currentPassengerCnt<<endl;
            if(currentPassengerCnt > capacity)return false;
        }
        return true;
        
    }