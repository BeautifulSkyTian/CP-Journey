#include <bits/stdc++.h>
using namespace std;

int main(){
  string city; 
  string prevCity;
  int temp=0;
  int prevTemp=0;

  cin>>city; cin>>temp;
  prevCity=city; prevTemp=temp;
  do{
    cin>> city; cin>> temp;
    prevTemp=min(temp, prevTemp);
    if(prevTemp==temp){
      prevCity=city;
    }
  }while(city!="Waterloo");
  cout<<prevCity;
}