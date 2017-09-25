#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define STAR '*'
#define Q_MARK '?'
int cache[101][101];
string W,S;
/*
  w : pattern index
  s : word index
  mathc(w,s) : check whether it is possible if word[w] is mathced to pattern[s]
*/
int match(int w,int s){
  int& ret = cache[w][s];
  if(ret != -1) return ret;//Is already find?
  if(s<S.size() && w<W.size() && (W.at(w)==Q_MARK || W.at(w)==S.at(s)) ){
    //if pattern character is question mark or they are matched
    //then extend to next index
    return (ret = match(w+1,s+1));
  }
  if(w==W.size()){
    //pattern is finished
    //check there is remained pattern character
    return (ret=(s==S.size()));
  }
  if(W.at(w)==STAR){
    //if pattenr is star, then it can be matched any of word's characters or nothing.
    return (ret=(match(w+1,s)||(s<S.size() && match(w,s+1))));
  }
  return (ret=0);
}

void printing_order(vector<string> &can_string){
  sort(can_string.begin(),can_string.end());
  vector<string> ::iterator iter;
  for(iter = can_string.begin();iter!=can_string.end();iter++)
    cout<<*iter<<endl;
}

int main(){
  for(int i=0;i<101;i++) memset(cache[i],-1,sizeof(int)*101);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int num;
    cin>>W;
    cin>>num;
    vector<string> can_string;
    for(int j=0;j<num;j++){
      cin>>S;
      for(int i=0;i<101;i++) memset(cache[i],-1,sizeof(int)*101);
      if(match(0,0))can_string.push_back(S);
    }
    printing_order(can_string);

  }
  return 0;
}
