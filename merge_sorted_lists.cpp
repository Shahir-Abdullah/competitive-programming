#include <bits/stdc++.h>
using namespace std;
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* a = list1;
        ListNode* b = list2;
        
    if(!a && !b)return nullptr;
	if(!a)return b;
	if(!b)return a;
	
	ListNode* dummy = new ListNode();
	ListNode* curr = dummy;
	
	while(a && b){
		if(a->val <= b->val){
			curr->next = a;
			a = a->next;
		}else if(a->val > b->val){
			curr->next = b;
			b = b->next;
		}
        //cout<<curr->val<<endl;
		curr = curr->next;
	}
	
	while(a){
		curr->next = a;
		curr = curr->next;
		a = a->next;
	}
	
	while(b){
		curr->next = b;
		curr = curr->next;
		b = b->next;
	}
	
	return dummy->next;
    }
