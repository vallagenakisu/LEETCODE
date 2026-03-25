#include <bits/stdc++.h>
using namespace std;
void print(stack<float> st)
{
    while(!st.empty())
    {
        cout << st.top()<<" ";
        st.pop();
    }
    cout << endl;
}
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    vector<float> ttr(n, 0);
    vector<tuple<int, float>> cars; // position ttr
    for (int i = 0; i < n; i++)
    {
        ttr[i] = (target - position[i] *1.0) / speed[i];
        cars.push_back({position[i], ttr[i]});
    }
    sort(cars.rbegin(), cars.rend());
    stack<float> stk;
    auto [pos,time] = cars[0];
    stk.push(time);

    int curr_max = time;
    for(int i = 1 ; i < n ; i++)
    {
        auto [pos1,time1] = cars[i];

        if(stk.top() >= time1)
        {
            continue;
        }
        else 
        {
            stk.push(time1);
        }
    }
    return stk.size();
}
int main()
{
    int target = 10;
    vector<int> position = {0,4,2};
    vector<int> speed = {2,1,3};
    cout << carFleet(target, position, speed);
}