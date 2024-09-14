#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        vector<int> ar(n); 
        int sum=0; 
        for(int a=0; a<n; a++) {cin>>ar[a]; sum+=ar[a];}

        for(int a=0; a<=sum; a++){
            if(a!=0 && sum%a!=0) continue; //If you think about it, the sum must be divisible by a. 

            int curr=0; 
            bool valid=true; 
            for(int b: ar){
                curr+=b; 
                if(curr>a){ //The current hour_number cannot be greater than a. 
                    valid=false; 
                    break;
                }
                else if(curr==a) curr=0;  //If it is equal to a, then just set it back to zero so it can keep adding the next few numbers in the array. 
            }

            if(valid){
                if(a==0){
                    cout<<0<<endl; //This is an edge case since you cannot use the same math as below. You cannot divide by zero. 
                }
                else cout<<n-sum/a<<endl; //This is really smart. Since a will be the hour_number resulted from the operations, you know that sum/a is the 
                //final length of the array. So you know that n-sum/a will be the number of operations you did. 
                break;
            }
        }
    }

}