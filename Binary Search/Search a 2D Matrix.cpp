#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> first;
    for(auto vectors : matrix){
        first.push_back(vectors[0]);
    }
    int l = 0 ;
    int r = first.size() - 1;
    int fans = - 1;
    while(l<=r){
        int mid = l + (r - l ) /2;
        if(first[mid] > target ){
            r = mid - 1;
        }
        else if (first[mid] <= target ){
            fans = mid;
            l = mid + 1 ;
        }
    }
    if(fans == -1) return false;
    vector<int> target_vector = matrix[fans];
    l = 0 ;
    r = target_vector.size() - 1 ;
    while( l <= r){
        int mid = l + (r - l) /2 ;
        if(target_vector[mid] < target ){
            l = mid + 1 ;
        }
        else if ( target_vector[mid] > target) {
            r = mid - 1 ;
        }
        else {
            return true;
        }
    }
    return false;

}
int main(){
    vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20},{23,30,34,60}};
    int target  = 3 ;
    searchMatrix(matrix , 20 );
}