#include <bits/stdc++.h>
using namespace std; 
//Solution: https://codeforces.com/blog/entry/125878

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    long long T; cin>>T; 
    while(T--){
        long long n, x, y; cin>>n>>x>>y; 
        vector<long long> ar(n); 
        for(long long a=0; a<n; a++) cin>>ar[a]; 

        map<pair<long long, long long>, long long> count; 
        /*  The key value of the map represesnts the modular value of ar[i[] by x and y. This allows us to track an element that fullfills the requirements: 
            a[i]modx=(x−a[j]modx)modx
            a[i]mody=a[j]mody

        */
        long long ans=0; 
        for(long long a=0; a<n; a++){
            long long xx=ar[a]%x, yy=ar[a]%y; 
            ans+=count[{(x-xx)%x, yy}]; 
            /*  You don't have to worry about repeats because we are iterating from the first element. There wouldn't be an ar[j] that matches ar[i] since we start
                at the front. The map value count[{(x-xx)%x, yy}] has not yet been made for ar[j], so when the forloop gets to ar[j], the program just needs to 
                use the map to get the number of elements that match ar[j]. 
            */
            count[{xx, yy}]++; //This updates the modular value of every element. 
        }

        cout<<ans<<endl; 
    }

    /*  Conclusion: for this kind of combinatorics questions, you need to turn the alogrithm from O(n^2) to O(n). The way you do it would be creating the description
        of each element inside a map. Then you would only need to iterate through the array and the value from the map that match the element's condition. 
    */
}

