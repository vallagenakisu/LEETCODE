#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node *next;
    Node *random;
    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> mymap;
    Node* temp = head;
    while(temp){
        mymap[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        mymap[temp]->next = mymap[temp->next];
        if(temp->random){
            mymap[temp]->random = mymap[temp->random];
        }
        else mymap[temp]->random = nullptr;
        temp = temp->next;
    }
    return mymap[head];
}

int main()
{

}