#include <bits/stdc++.h>
using namespace std; 

vector<vector<int>> cow(20, vector<int>(3)), airCondition(10, vector<int>(4)); 
vector<int> stall(100); 

int check(vector<int> combination){
    int cost=0; 
    bool valid=true; 
    vector<int> tempStall=stall; 
    for(int a: combination){
        for(int b=airCondition[a][0]; b<=airCondition[a][1]; b++) tempStall[b-1]+=airCondition[a][2]; 
        cost+=airCondition[a][3]; 
    }
    for(int a: tempStall) if(a<0) valid=false; 
    return(valid?cost:INT_MAX); 
}

int recurse(vector<int> combination, int m){
    combination.push_back(m); 
    int minCost=INT_MAX; 
    for(int a=0; a<m; a++) minCost=min(minCost, recurse(combination, a)); 

    return min(check(combination), minCost); 
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    // freopen("blocks.in", "r", stdin);
	// // the following line creates/overwrites the output file
	// freopen("blocks.out", "w", stdout);

    int m, n; cin>>m>>n; 
    for(int a=0; a<m; a++){
        cin>>cow[a][0]>>cow[a][1]>>cow[a][2]; 
        for(int b=cow[a][0]; b<=cow[a][1]; b++) stall[b-1]-=cow[a][2]; 
    }
    for(int a=0; a<n; a++) cin>>airCondition[a][0]>>airCondition[a][1]>>airCondition[a][2]>>airCondition[a][3]; 
    
    int ans=INT_MAX; 
    for(int a=0; a<n; a++) ans=min(ans, recurse({}, a)); 
    cout<<ans<<endl; 
}