#include <iostream>

using namespace std;
int N;

unsigned long long int cache[101];
unsigned long long int how_many(int x){
  if(x == 1 || x==0)return 1;
  if(x<0)return 0;
  if(cache[x]!=-1)return cache[x];

  return cache[x]=(how_many(x-1)+how_many(x-2))%1000000007;
}

void clear_cache(){
  for(int i=0;i<=100;i++)cache[i]=-1;
}

int main(){
  int test_case;
  cin >> test_case;
  for(int i=0;i<test_case;i++){
    cin>>N;
    clear_cache();
    cout<<how_many(N)<<endl;
  }
  return 0;
}
