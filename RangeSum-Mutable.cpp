// Now this question will give the clear essence of segment tree
// now we will have queries of multiple behaviour means that now we are going to perform multiple queries
// the very first query is sum and second is update 
#include<iostream>
#include<vector>
using namespace std;

vector<int> st;
void BuiltTree(vector<int>&arr , int i , int low , int high){
    if(low == high) {
        st[i]=arr[low];
        return ;
    }
    int mid = low+(high-low)/2;
    BuiltTree(arr , 2*i+1,low,mid );// this i is basically for the segment tree
    BuiltTree(arr , 2*i+2 , mid+1 ,high);
    st[i] =st[2*i+1]+st[2*i+2];
}
int sumQuery(int i , int low , int high , int l , int r){
     if(high < l || r < low) return 0;
     if(low>= l && high <= r) return st[i];
     int mid = low + (high-low)/2;
     int rightSum = sumQuery(2*i+1 ,low , mid , l ,r);
     int leftSum =  sumQuery(2*i+2 , mid+1 ,high,l ,r);
     return leftSum+rightSum;
}
void update(vector<int>&arr,int index , int i ,int value , int high , int low){
    // now see we are dividing on the basis of mid so lets choose the subtree using mid
    if(low == high) {
        st[i]  = value;
        return ;
    }
    int mid = low+(high-low)/2;
    if(index <= mid) update(arr,index , 2*i+1 , value , mid , low);
    else update(arr,index, 2*i+2 ,value , high , mid+1);
    st[i] = st[2*i+2]+st[2*i+1];

}
int main(){
    vector<int>arr;
    int n ;
    cout<<"enter the size of an array ";
    cin>>n;
    arr.resize(n);
    st.resize(n);
    BuiltTree(arr,0,0,n-1);
}




