#include<iostream>
#include<vector>
using namespace std;

vector<int> st;

void buildTree(int arr[], int node, int start, int end){
    if(start == end){
        st [node] = arr[start];
        return ;
    }
    int mid = (start + end)/2;// l0+(hi-lo)/2;
    buildTree(arr,2*node+1,start ,mid);
    // now see it is like merge sort we will not these two recurrsion call
    // we set the largest value in the current node from a range
    buildTree(arr,2*node+2,mid+1 , end);
    st[node] =  max (st[2*node+1] , st[2*node+2]);
}
int main(){
   int arr[] = {1, 4 , 2 , 8 ,6 ,4 ,9 ,3};
   int n = sizeof(arr)/4;
   st.resize(4*n);
   buildTree(arr,0,0,n-1);;// 

}