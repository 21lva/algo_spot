#include <iostream>

using namespace std;

int N;

int count(int extra,int begin,int last){
  if(extra==0)return 1;
  int ret;
  for(int i=begin;i<=last;++i){
    for(int j=1;j <= last-begin+1;++j){
      ret+=count(extra-j,i,i+j-1);
    }
  }
}
