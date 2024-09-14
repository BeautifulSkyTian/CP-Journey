#include <bits/stdc++.h>
using namespace std; 

//Solution: https://codeforces.com/blog/entry/124757
int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int h, w, xA, xB, yA, yB; cin>>h>>w>>xA>>yA>>xB>>yB; 
        
        string winner; 
        bool win; 
        int turn; 
        if((xA-xB)%2==0){ //If you know that the x-difference between the two players is an even number, then Bob will be the last person to move. Therefore, he has a higher chance to win. 
            winner="Bob"; 
            if(xA>=xB) win=false; //If the two playres have already passed each other in terms of x, then they will draw. 
            else if(yA==yB) win=true; //If their column number is the same, then Bob can always follow wherever Alice moves. 
            else{
                if(yA<yB) turn=yB-1; //If Alice is on the left of Bob, then Bob has to chase Alice. So we calculate the distance between column 1 and Bob. 
                else turn=w-yB; //Otherwise, Bob is chasing Alice to the left, so we calculate the distance between Bob and the last column. 
                win=xB-2*turn>=xA; //This inequality can be viewed as xB-turn>=xA-turn. We have to make sure the two players do not pass by each other in terms of x after all the moves end. Else it would be a draw. 
            }
        }
        else{
            winner="Alice"; //Since the distance between the two players is odd, Alice has a higher chance to win. 
            
            xA+=1; //This chunk basically executes Alice's first move since Alice moves first. 
            if(yB>yA) yA+=1; 
            else if(yB<yA) yA-=1; 

            if(xA>xB) win=false; //We need to execute Alice's first move so the moves are even, so this can be viewed similarly as the condition on top. 
            else if(yA==yB) win=true; //This is because we are doing the math under the condition that two players have equal moves. 
            else{
                if(yA<yB) turn=w-yA; //Now this is very similar to the prior condition. If Alice is on the left of Bob, she has to chase Bob. So the number of turns would be the distance between Alice and the last column. 
                else turn=yA-1; //Otherwise, Alice chases Bob to the left. 
                win=xB-2*turn>=xA; //Same condition. 
            }
        }
        cout<<(win?winner:"Draw")<<endl; 

    }
}