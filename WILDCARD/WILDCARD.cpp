#include <iostream>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

#define STAR '*'
#define Q_MARK '?'
int cache[101][101]={{-1,},};
string W,S;

int match(int w,int s){
  int& ret = cache[w][s];
  if(ret != -1) return ret;
  if(s<S.size() && w<W.size() && (W.at(w)==Q_MARK || W.at(w)==S.at(s)) ){
    return (ret = match(w+1,s+1));
  }
  if(w==W.size()){
    //pattern is finished
    return (ret=(s==S.size()));
  }
  if(W.at(w)==STAR){
    return (ret=(match(w+1,s)||(s<S.size() && match(w,s+1))));
  }
  return (ret=0);
}

int main(){
  for(int i=0;i<101;i++) memset(cache[i],-1,sizeof(int)*101);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int num;
    cin>>W;
    cin>>num;
    for(int j=0;j<num;j++){
      cin>>S;
      for(int i=0;i<101;i++) memset(cache[i],-1,sizeof(int)*101);
      if(match(0,0))cout<<S<<endl;
    }
  }
  return 0;
}
