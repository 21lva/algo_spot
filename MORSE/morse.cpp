#include <iostream>

#define O 'o'
#define dash '-'
#define MAXVAL 1000000100

using namespace std;

unsigned long long int cache[201][201];

unsigned long long int fac(int n){
  if(n<=1)return 1;
  return n*fac(n-1);
}

unsigned long long int comb(){
  for(int i=0;i<=201;i++){
    for(int j=0;j<201;j++)
      cache[i][j]=0;
  }
  for(int i=0;i<=201;i++){
    cache[i][0]=cache[i][i]=1;
    for(int j=1;j<i;j++)
      cache[i][j]=(MAXVAL<cache[i-1][j-1]+cache[i-1][j])? MAXVAL : cache[i-1][j-1]+cache[i-1][j];
  }
}

void func(int n,int m,int k){
  // cout<<endl<<" "<<n<<" "<<m<<" "<<k<<" "<<comb(n-1,m)<<endl;
  if(n==0){
    for(int i=0;i<m;i++)cout<<O;
  }
  else if(m==0){
    for(int i=0;i<n;i++)cout<<dash;
  }
  else if(cache[n+m-1][m] >= k){
    cout<<dash;
    func(n-1,m,k);
  }
  else{
    cout<<O;
    func(n,m-1,k-cache[n+m-1][m]);
  }
}

void clear_cache(){
  for(int i=0;i<101;i++)for(int j=0;j<101;j++)cache[i][j]=-1;
}

int main(){
  int test_case;
  cin>>test_case;
  for(int i=0;i<test_case;i++){
    int N,M,K;
    cin>>N>>M>>K;
    clear_cache();
    comb();
    func(N,M,K);
    cout<<endl;
  }
  return 0;
}
