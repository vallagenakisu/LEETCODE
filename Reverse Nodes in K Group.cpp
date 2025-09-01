#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0) , next(nullptr){}
    ListNode(int x) : val(x) , next(nullptr){}
    ListNode(int x , ListNode *next) : val(x) , next(next){}
};
ListNode *reverse(ListNode* head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while(curr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    int size = 0;
    ListNode *temp = head;
    while(temp){
        temp = temp->next;
        size++;
    }
    int flag = 0 ;
    if(size-k >= k) flag = 1;
    temp = head;
    int i = 1;
    while(true)
    {
        if(i==k) break;
        temp = temp->next;

    }
    ListNode* temp2 = temp->next;
    temp->next =NULL;
    temp = reverse(temp);
    if(flag == 0 ){
        head = temp;
        while(temp){
            temp = temp->next;
        }
        temp->next = temp2;
    }
    else{
        head = temp;
        while(temp){
            temp = temp->next;
        }
        temp2 = reverse(temp2);
        temp->next = temp2;
    }
    return head;   
}