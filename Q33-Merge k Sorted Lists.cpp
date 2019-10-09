/*
https://leetcode.com/problems/merge-k-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct compare{
bool operator()(ListNode * A,ListNode * B){
    if(A->val>B->val)return true;
    return false;
}
    
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue <ListNode *, vector<ListNode *> , compare>q;
    int i=0;
    for(i=0;i<A.size();i++){
        if(A[i]){
            q.push(A[i]);
        }
    }
    ListNode * res=NULL,*cur,*it;
    while(q.size()){
        cur=q.top();
        q.pop();
        if(res){
            it->next=cur;
            it=it->next;    
        }
        else{
            res=cur;
            it=res;
        }
        
        if(cur->next){q.push(cur->next);}
    }
    return res;
}

