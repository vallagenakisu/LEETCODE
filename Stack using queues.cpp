#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int top_element = q1.front();
        q1.pop();
        swap(q1, q2);
        return top_element;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int top_element = q1.front();
        q2.push(top_element);
        q1.pop();
        swap(q1, q2);
        return top_element;
    }

    bool empty()
    {
        if(q1.empty()) return true;
        else return false;
    }
};

int main()
{
}