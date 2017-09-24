#include <iostream>

using namespace std;

int N;
int MOD=1000000007;

int cache[101];
int whole(int n){
  //base case
  if(n <= 1)return 1;
  if(cache[n] != -1)return cache[n];
  return cache[n] = (whole(n-1)+whole(n-2))%MOD;
}
int asym(int n){
  if(n%2==0){
    int ret=(MOD+whole(n)-whole(n/2-1))%MOD;
    return (MOD+ret-whole(n/2))%MOD;
  }
  return (MOD+whole(n)-whole((n-1)/2))%MOD;
}

int main(){
  int num_case;
  cin>>num_case;
  for(int j=0;j<num_case;j++){
    for(int i=0;i<101;i++)cache[i]=-1;
    cin>>N;
    cout<<asym(N)<<endl;
  }
  return 0;
}
