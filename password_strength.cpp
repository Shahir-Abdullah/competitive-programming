int main() {
    string s = "good";
    int n = s.length(), count = 0;
    for(int i = 0; i < n; i++) {
        int v_count = 0, c_count = 0;
        while(i < n && (v_count == 0 || c_count == 0)) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                v_count++;
            }
            else
                c_count++;
            i++;
        }
        i--;
        if(v_count && c_count)
            count++;
    }
    cout<<"Strength is "<<count<<"\n";
}