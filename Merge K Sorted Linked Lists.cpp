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

ListNode* mergeTwo(ListNode *l1, ListNode *l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *head = nullptr;
    for(auto l1 : lists){
        head = mergeTwo(head,l1);
    }
    return head;
}