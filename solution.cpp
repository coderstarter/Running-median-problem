#include <bits/stdc++.h>
using namespace std;

vector<int> calculateMedians(vector<int>& arr){
     vector<int> C;
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int num: arr){
        if(maxheap.empty() || num<maxheap.top()){
            maxheap.push(num);
        } else{
            minheap.push(num);
        }
        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if(maxheap.size()>minheap.size()){
            C.push_back(maxheap.top());
        } else{
            C.push_back((maxheap.top() + minheap.top())/2);
        }
    }
    return C;
}

vector<int> findMedians(vector<int>& A) {
    return calculateMedians(A);
}
int main() {
    vector<int> A = {1, 2, 5, 4, 3};
    vector<int> C = findMedians(A);
    for (int median : C) {
        cout << median << " ";
    }
    cout << endl;
    return 0;
}
