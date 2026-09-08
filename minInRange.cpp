#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>st;

void BuiltTree(vector<int>&arr , int i , int low , int high){
    if(low == high) {
        st[i] = arr[low];
        return;
    }
    int mid = low+(high-low)/2;
    BuiltTree(arr,2*i+1,low,mid);
    BuiltTree(arr,2*i+2,mid+1,high);
    st[i] = min(st[2*i+1] , st[2*i+2]);
}
int returnMin(int i , int low ,int high , int r , int l){
    if(high<l || r<low) return INT_MAX;
    if(low>=l && high<=r) {
        return st[i];
    }
     int mid = low+(high-low)/2;
     int rightMin = returnMin(2*i+2 , mid+1 , high ,r ,l);
     int leftMin = returnMin(2*i+1, low ,mid ,r ,l);
     return min(rightMin,leftMin);
}
int main(){
    int n ;
    cout<<"Enter the size of an array ";
    cin>>n;
    vector<int>arr;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    st.resize(4*n);
    BuiltTree(arr , 0 ,0 ,n-1);

}