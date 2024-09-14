#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int N; cin>>N; 
        
        vector<int> ar(N+1);
        vector<int> pref(N+1); //This array holds the all of the prefix xor numbers. For instance, index 2 holds all xor values from index 0 to 2. And this continues for every single index. 
        for(int a=1; a<N+1; a++) cin>>ar[a];
        
        string str; cin>>str; 
        int Q; cin>>Q; 

        vector<int> ans(2); 
        str='0'+str; 
        for(int a=1; a<N+1; a++){
            ans[str[a]-48]^=ar[a]; 
            pref[a]=pref[a-1]^ar[a]; //This allows you to use the previous prefix xor to xor with the current ar[a] which allows you to get the prefix xor of index a. 
        }
        int massxor=0; 

        for(int i=0; i<Q; i++){
            int x; cin>>x; 

            if(x==1){
                int l, r; cin>>l>>r; 
                massxor^=pref[r]^pref[l-1]; //It is extremely important to store the xor values inside massxor because the change is permanent. pref[r]^pref[l-1] gets the xor value from l to r inclusive. 
            }
            else{
                int g; cin>>g; 
                int result=massxor^ans[g]; //At the end, all it takes is to massxor^ans[g] because taking xor values from the 0 and 1 arrays are the samething. Read editorial for more info. 
                cout<<result<<" "; //https://codeforces.com/blog/entry/120165
            }
        }
        cout<<"\n"; 
    }
}
/*
{0, 12, 12, 14, 14, 5, 5}
{0, 12, 0, 14, 0, 5, 0}
*/