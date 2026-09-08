#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> st;

int maxSeg(int i , int low, int high , int l , int r){
   if(r<low || l>high) return INT_MIN;// now see we will not use equals to bcz one element will get included and it will lie in other cases
   if(low>= l && high <= r) return st[i]; // this is the case where [low,high] is a subset of [l,r]
   // Now we are left with subset and overlap conditon
   // but it will come under else bcz in both the cases we have to call both the childs
   int mid = low+(high-low)/2;
   int leftmax = maxSeg(2*i+1 ,low ,mid,l,r);
   int rightmax = maxSeg(2*i+2 ,mid+1,high,l,r);
   return max(leftmax , rightmax);
}
void BuiltTree(int arr[] , int i , int lo ,int hi){
    if(lo==hi){
        st[i] = arr[lo];
        return ;
    }
    int mid = lo+(hi-lo)/2;
    BuiltTree(arr,2*i+1 ,lo ,mid);
    BuiltTree(arr,2*i+2 ,mid+1 ,hi);
    st[i] = max(st[2*i+1],st[2*i+2]); // backTracking

}
int main(){
    int arr [] = {1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    st.resize(4*n); // Resize segment tree
    BuiltTree(arr,0,0,n-1);
    int q;
    cout<<"Enter the number of queries";
    cin>>q;
    while(q--){
    int l , r;
    cout<<"enter the valid range";
    cin>>l>>r;
    cout<<maxSeg(0,0,n-1,l,r)<<endl;
    }
}
