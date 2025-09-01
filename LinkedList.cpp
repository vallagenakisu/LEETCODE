#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void display(ListNode *head){
    while(head)
    {
        cout << head->val<<" ";
        head = head->next;
    }
}
void insertFront(ListNode **head, int val)
{
    ListNode *newnode = new ListNode();
    newnode->val = val;
    if(head==NULL){
        *head = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = *head;
        *head = newnode;
    }
}
ListNode* reverseList(ListNode *head){
    ListNode *prev= nullptr ;
    ListNode *curr=head;

    while(curr){
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr= temp;
        
    }
    return prev;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *ptr1 = list1;
    ListNode *ptr2 = list2;
    ListNode *newlist = nullptr;
    while(ptr1 != NULL and ptr2!= NULL){
        if(ptr1->val > ptr2->val){
            insertFront(&newlist,ptr2->val);
            ptr2 = ptr2->next;
        }
        else{
            insertFront(&newlist,ptr1->val);
            ptr1 = ptr1->next;
        }
    }    
    while(ptr1){
        insertFront(&newlist,ptr1->val);
        ptr1= ptr1->next;
    }    
    while(ptr2){
        insertFront(&newlist,ptr2->val);
        ptr2= ptr2->next;
    }    
    return reverseList(newlist);
}
bool hasCycle(ListNode* head) {
    int checked = -100001;
    while(head){
        if(head->val == checked) return true;
        head->val = checked ;
        head = head->next;
    }
    return false;
}
void reorderList(ListNode* head) {
    ListNode *actualHead = head;

    while(head->next != NULL){
        ListNode *ptr = head;
        ListNode *prevptr = NULL;
        while(ptr->next != NULL){
            prevptr = ptr;
            ptr = ptr->next;    
        }
        if(head == prevptr) break;
        ListNode *temp = head->next;
        head->next = ptr;
        ptr->next = temp;
        prevptr->next =NULL;
        head = head->next->next;   
    }  
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0 ;
    ListNode *temp = head;
    while(temp){
        temp = temp->next;
        size++;
    }        
    if(size == 1 ) return NULL;
    if(n == size){
        head = head->next;
        return head;
    }
    //cout << size <<" ";
    int target = size - n + 1 ;
    //cout << target <<" ";
    temp = head;
    ListNode *prev = nullptr;
    int i = 1;
    while(true){
        //cout << temp->val << endl;
        if(i == target){
           // cout << "start here "<<temp->val<<endl;
            prev->next = temp->next;
            break;
        } 
        prev = temp;
        temp = temp->next;      
        i++;
    }
    return head;
}
int makeDigit(ListNode *head){
    int mul = 1 ;
    int digit = 0 ;
    while(head){
        digit = digit + (head->val) * mul;
        mul = mul * 10;
        head = head->next;
    }
    return digit;
}
ListNode * makeList(int digit){
    ListNode *head = new ListNode(digit%10);
    digit = digit/10;
    ListNode *temp = head;
    while(digit){
        ListNode *newnode = new ListNode(digit%10);
        digit = digit / 10;
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int result = makeDigit(l1) + makeDigit(l2);
    return makeList(result);
}
int main()
{
    ListNode *linkedlist = nullptr;
    insertFront(&linkedlist,6);
    insertFront(&linkedlist,5);
    insertFront(&linkedlist,4);
    insertFront(&linkedlist,3);
    insertFront(&linkedlist,2);
    insertFront(&linkedlist,1);
    //insertFront(&linkedlist,0);
    //display(linkedlist);
    //cout << endl;
    // reorderList(linkedlist);
    ListNode *newlist = removeNthFromEnd(linkedlist,6);
    display(linkedlist);
    cout << makeDigit(linkedlist);
}