#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("billboard.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("billboard.out", "w", stdout);

    int x1, x2, y1, y2; 
    cin>>x1>>y1>>x2>>y2; 
    int n1, n2, m1, m2; 
    cin>>n1>>m1>>n2>>m2; 

    if(m1<=y1 && m2>=y2){
        if(n1>=x1 && n1<=x2 && n2>=x2) cout<<(n1-x1)*(y2-y1); 
        else if(n2>=x1 && n2<=x2 && n1<=x1) cout<<(x2-n2)*(y2-y1); 
        else cout<<(x2-x1)*(y2-y1); 
    }   
    else if(n1<=x1 && n2>=x2){
        if(m1>=y1 && m1<=y2 && m2>=y2) cout<<(m1-y1)*(x2-x1); 
        else if(m2>=y1 && m2<=y2 && m1<=y1) cout<<(y2-m2)*(x2-x1); 
        else cout<<(x2-x1)*(y2-y1); 
    }
    else cout<<(x2-x1)*(y2-y1); 
}