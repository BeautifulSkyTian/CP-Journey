#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("notlast.in", "r", stdin);
    // the following line creates/overwrites the output file
    freopen("notlast.out", "w", stdout);

    vector<string> cow1{"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"}; 
    map<string, int> cow2; 
    for(int a=0; a<cow1.size(); a++) cow2[cow1[a]]=a; 

    int n; cin>>n; 
    vector<vector<int>> milk(cow1.size(), vector<int>(2)); 
    for(int a=0; a<cow1.size(); a++) milk[a][1]=a; 
    for(int a=0; a<n; a++){
        string x; int y; cin>>x>>y; 
        milk[cow2[x]][0]+=y; 
    }
    sort(milk.begin(), milk.end()); 
    // for(int a=0; a<cow1.size(); a++) cout<<cow1[milk[a][1]]<<" "<<milk[a][0]<<endl; 

    int find=0; 
    for(int a=0; a<milk.size(); a++) if(milk[a][0]!=milk[0][0]) {find=a; break; }
    int count=0; 
    for(int a=find; a<milk.size(); a++) if(milk[a][0]==milk[find][0]) count++; 
    if(count>1) cout<<"Tie"<<endl; 
    else cout<<cow1[milk[find][1]]<<endl; 

}