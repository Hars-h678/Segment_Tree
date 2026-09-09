#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector< unordered_map<int,int> >st;
void unionMap(int i){
  for(auto x : st[2*i+1]) st[i].insert(x);
  for(auto x : st[2*i+2]) {
    int key = x.first, value = x.second;
    if(st[i].find(key)==st[i].end()) st[i].insert(x);
    else st[i][key] += value;
  }
}
void BuiltTree(vector<int>&arr , int i ,int low , int high){
    if(low==high){
        int key = arr[low];
        int value =1 ;
        st[i][key] = value;
        return;
    }
    int mid = low+(high-low)/2;
    BuiltTree(arr , 2*i+1 , low , mid);
    BuiltTree(arr, 2*i+2 , mid+1 , high );
    unionMap(i);

}
int getFreq(int i , int low , int high , int l , int r , int value){
    if( high<l || r<low) return 0;
    if(low>=l && high<=r) return st[i][value]; // see before returning check whether the key is present or not although not necessary but still
    // to avoid memory constraints
    int mid = low+(high-low)/2;
    int leftFreq = getFreq(2*i+1 , low , mid , l,r ,value);
    int rightFreq = getFreq(2*i+2 , mid+1, high , l,r ,value);
    return leftFreq+rightFreq;

}
int main(){
    int n ;
    cout<<"Enter the size of an array ";
    cin>>n;
    vector<int>arr;
    arr.resize(n);
    st.resize(4*n);
    BuiltTree(arr,0,0,n-1);
}