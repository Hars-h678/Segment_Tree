#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>st;
vector<int>lazy;

void BuiltTree(int arr[] , int i , int low , int high){
    if(low == high) {
        st[i] = arr[low];
        return;
    }
    int mid = low+(high-low)/2;
    BuiltTree(arr,2*i+1,low,mid);
    BuiltTree(arr,2*i+2,mid+1,high);
    st[i] = (st[2*i+1] + st[2*i+2]);
}
int getSum(int i , int low ,int high , int l , int r){
    // check for pending
    if(lazy[i] != 0){
        int rangeSize = high-low+1;
        st[i] += rangeSize*lazy[i];
        // now pass the lazy to its child if not in leaf node
        if(low!=high){
            // now send the same lazy 
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
            lazy[i] = 0;
        }
    }
    if(high<l || r<low) return 0;
    if(low>=l && high<=r) {
        return st[i];
    }
     int mid = low+(high-low)/2;
     int rightSum = getSum(2*i+2 , mid+1 , high ,l ,r);
     int leftSum = getSum(2*i+1, low ,mid ,l,r);
     return rightSum+leftSum;
}

void updateRange(int i , int lo , int hi , int l ,int r,int val){
    // check for pending
    if(lazy[i] != 0){
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*lazy[i];
        // now pass the lazy to its child if not in leaf node
        if(lo!=hi){
            // now send the same lazy 
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
            lazy[i] = 0;
        }
    }

    if(l>hi || r<lo) return;
    if(lo>=l && hi<=r){
        //update entire [lo,hi]
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*val;
    
     if(lo!=hi){
            // now send the pending but this pending is different from the lazy one it is pending of value
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return ;
    }
    int mid = lo+(hi-lo)/2; 
    updateRange(2*i+1,lo,mid,l,r,val);
    updateRange(2*i+2,mid+1,hi,l,r,val);
    st[i] = (st[2*i+1] + st[2*i+2]); // very important as we did update so re construct it

    
}
int main(){
     int arr[] = {1, 4 , 2 , 8 ,6 ,4 ,9 ,3};
   int n = sizeof(arr)/4;
   st.resize(4*n);
   lazy.resize(4*n);
   BuiltTree(arr,0,0,n-1);;// 
   cout<<getSum(0 ,0 ,n-1 , 1 , 3)<<endl;
   updateRange(0,0,n-1,2,5,10);
   cout<<getSum(0 ,0 ,n-1 , 1 , 3)<<endl;
}