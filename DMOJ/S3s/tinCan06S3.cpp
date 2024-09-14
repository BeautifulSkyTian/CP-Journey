#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    pair<long double, long double> p1, p2; 
    cin>>p1.first>>p1.second>>p2.first>>p2.second; 

   long double N; cin>>N; 
    vector<vector<pair<long double, long double>>> building(N); 
    for(int a=0; a<N; a++){
       long double M; cin>>M; 
        for(int b=0; b<M; b++){
            pair<long double, long double> x; cin>>x.first>>x.second; 
            building[a].push_back({x.first, x.second}); 
        }
    }

   long double m, b; 
    bool isFunction=true; 
    if(p1.first==p2.first) isFunction=false; 
    else{
        m=(p1.second-p2.second)/(p1.first-p2.first); 
        b=p1.second-m*p1.first; 
    }

   long double block=0; 
    for(int a=0; a<N; a++){
        for(int b=0; b<building[a].size(); b++){
            pair<long double, long double> c1{building[a][b].first, building[a][b].second}, 
            c2; 
            if(b==building[a].size()-1) c2={building[a][0].first, building[a][0].second}; 
            else c2={building[a][b+1].first, building[a][b+1].second}; 
            
            if(!isFunction){
                if(c1.first==c2.first && c1.first==p1.first){
                    if((c1.second>=min(p1.second, p2.second) && c1.second<=max(p1.second, p2.second))
                    ||(c2.second>=min(p1.second, p2.second) && c2.second<=max(p1.second, p2.second))){
                        cout<<'a'<<b<<" "; 
                        block++; 
                        break;
                    }
                }
                else if(c1.first!=c2.first && c1.first!=p1.first){
                   long double m1=(c1.second-c2.second)/(c1.first-c2.first); 
                   long double b1=c1.second-m1*c1.first;
                   long double interY=m1*p1.first+b1; 
                    if((interY>=min(p1.second, p2.second)) && interY<=max(p1.second, p2.second)){
                        cout<<'b'<<b<<" "; 
                        block++; break;
                    }
                }
            }
            else if(c1.first==c2.first){
               long double interY=m*c1.first+b; 
                if((interY>=min(c1.second, c2.second)) && (interY<=max(c1.second, c2.second))){
                    cout<<'c'<<b<<" "; 
                    block++; 
                    break;
                }
            }
            else{
               long double m1=(c1.second-c2.second)/(c1.first-c2.first); //5
               long double b1=c1.second-m1*c1.first; //-201
                if(m1!=m){
                   long double interX=(b1-b)/(m-m1); 
                    if((interX>=min(c1.first, c2.first)) && (interX<=max(c1.first, c2.first))){
                        cout<<'d'<<b<<" "; 
                        block++; break; 
                    }
                }
                else if(m1==m && b1==b){
                    if((c1.first>=min(p1.first, p2.first) && c1.first<=max(p1.first, p2.first))
                    ||(c2.first>=min(p1.first, p2.first) && c2.first<=max(p1.first, p2.first))){
                        cout<<'e'<<b<<" "; 
                        block++; 
                        break;
                    }
                }
            }
        }
        cout<<"num: "<<block<<endl; 
    }
    cout<<block<<endl;
}