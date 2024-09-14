#include <bits/stdc++.h>
using namespace std; 

bool volume(vector<int> a, vector<int> b){
    return a[0]*a[1]*a[2]<b[0]*b[1]*b[2]; 
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int n1, n2; 
    
    cin>>n1; 
    vector<vector<int>> box(n1, vector<int>(3)); 
    for(int a=0; a<n1; a++){
        for(int b=0; b<3; b++) cin>>box[a][b];
        sort(box[a].begin(), box[a].end()); 
    }
    sort(box.begin(), box.end(), volume); 
    
    //cout<<"Box: "<<endl; 
    //for(vector<int> i:box)cout<<i[0]<<i[1]<<i[2]<<endl; 

    cin>>n2; 
    vector<vector<int>> item(n2, vector<int>(3)); 
    for(int a=0; a<n2; a++){
        for(int b=0; b<3; b++) cin>>item[a][b];
        sort(item[a].begin(), item[a].end()); 
    }
    
    //cout<<"Item: "<<endl; 
    //for(vector<int> i:item)cout<<i[0]<<i[1]<<i[2]<<endl; 

    for(int a=0; a<n2; a++){
        vector<int> fit; 
        bool valid=false; 
        for(int b=0; b<n1; b++){
            if(item[a][0]*item[a][1]*item[a][2]<=box[b][0]*box[b][1]*box[b][2]){
                if(item[a][0]<=box[b][0] && item[a][1]<=box[b][1] && item[a][2]<=box[b][2]) {valid=true; fit=box[b]; break;}
            }
        }
        if(valid) cout<<fit[0]*fit[1]*fit[2]<<endl; 
        else cout<<"Item does not fit."<<endl; 
    }
}