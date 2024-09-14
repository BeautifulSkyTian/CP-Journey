#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    map<char, int> card {{'A', 4},{'K', 3},{'Q', 2},{'J', 1}}; 
    string input; cin>>input; 
    string C, D, H, S; 
    int count=0, point=0, tPoint=0; 
    int pos1, pos2, pos3, pos4; 

    cout<<"Cards Dealt Points"<<endl; 

    pos1=input.find('C'); 
    pos2=input.find('D'); 
    pos3=input.find('H'); 
    pos4=input.find('S'); 
    C=input.substr(pos1, pos2-pos1); 
    D=input.substr(pos2, pos3-pos2); 
    H=input.substr(pos3, pos4-pos3); 
    S=input.substr(pos4, input.size()-pos4); 

    cout<<"Clubs "; 
    for(int a=1; a<C.size(); a++){
        cout<<C[a]<<" "; 
        point+=card[C[a]]; 
    } 
    if(C.size()==1) point+=3;
    else if (C.size()==2) point+=2;
    else if (C.size()==3) point+=1; 
    cout<<point<<endl; 
    tPoint+=point; 

    cout<<"Diamonds "; 
    point=0; 
    for(int a=1; a<D.size(); a++){
        cout<<D[a]<<" "; 
        point+=card[D[a]]; 
    }
    if(D.size()==1) point+=3;
    else if (D.size()==2) point+=2;
    else if (D.size()==3) point+=1; 
    cout<<point<<endl; 
    tPoint+=point; 

    cout<<"Hearts "; 
    point=0; 
    for(int a=1; a<H.size(); a++){
        cout<<H[a]<<" "; 
        point+=card[H[a]]; 
    }
    if(H.size()==1) point+=3;
    else if (H.size()==2) point+=2;
    else if (H.size()==3) point+=1; 
    cout<<point<<endl; 
    tPoint+=point; 

    cout<<"Spades "; 
    point=0; 
    for(int a=1; a<S.size(); a++){
        cout<<S[a]<<" "; 
        point+=card[S[a]]; 
    }
    if(S.size()==1) point+=3;
    else if (S.size()==2) point+=2;
    else if (S.size()==3) point+=1; 
    cout<<point<<endl; 
    tPoint+=point; 
    cout<<"Total "<<tPoint<<endl; 
}