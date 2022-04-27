struct Node{
    int count;
    Node* next[26];
    Node (){
        count = 0;
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};

Node* root = new Node();

void add(string name){
    int len = name.length();
    Node* current = root;
    for(int i = 0; i < len; i++){
        char letter = name[i];
        if(current->next[(int)letter-'a'] == NULL){
            current->next[(int)letter - 'a'] = new Node();
        }
        current = current->next[(int)letter - 'a'];
        current->count++;
    }
}
int find(string name){
    int len = name.length();
    Node* current = root;
    for(int i = 0; i < len; i++){
        char letter = name[i];
        if(current->next[(int)letter - 'a'] == NULL){
            return 0;
        }
        current = current->next[(int)letter - 'a'];
    }
    return current->count;
}
