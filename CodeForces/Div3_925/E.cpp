#include <bits/stdc++.h>
using namespace std;
//Solution: https://codeforces.com/blog/entry/125878
int main() {
    cin.sync_with_stdio(0); 
    cin.tie(0); 
    
    int T; cin>>T; 
    while(T--){
        int n, m; cin>>n>>m; 
        vector<string> ar(n);
        vector<int> digit(n), zero(n); //These record the number of digits and the number of zeroes. 
        for(int a=0; a<n; a++) cin>>ar[a]; 
        for(int a=0; a<n; a++){
            digit[a]=ar[a].size(); 
            for(int b=ar[a].size()-1; b>=0 && ar[a][b]=='0'; b--)
                zero[a]++; //The reason why we keep track of the number of zeroes is because the whole point of this program is that the number of digits of the final 
                // answer is larger than m+1. 
        }

        int ans=0; //Ans keeps track of the number of digits. 
        for(int a=0; a<n; a++) ans+=digit[a]-zero[a]; //Iterates through the array and gets the number of digits that are non zero. 
        sort(zero.rbegin(), zero.rend()); //For Anna to play optimally, she will, of course, reverse the numbers that have the most amount of zeroes. 
        for(int a=0; a<n; a++){
            if(a%2) ans+=zero[a]; //Since Sasha will always go second, we just have to add the number of zeroes on his turn. 
        }
        
        cout<<(ans-1>=m?"Sasha":"Anna")<<endl; 
    }
}

/*  Conclusion: 
    Quote from the solution: If the decimal representation of a number x has exactly c digits, then x≥10^c−1. From this, it can be concluded that 
    Sasha is not required to maximize the final number; it is sufficient for him to maximize the number of digits in it.

    This is very clever since 10^m is actually just represents the number of required digits. Sasha is not required to maximize the final number. 
*/