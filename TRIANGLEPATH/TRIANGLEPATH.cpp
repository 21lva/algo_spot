#include <iostream>

using namespace std;



int arr[100][100];
int cache[100][100];
int path(int n,int x,int y){
  if(x==n-1)return cache[x][y]=arr[x][y];
  if(cache[x][y] !=-1)return cache[x][y];
  int down=path(n,x+1,y);
  int down_left=path(n,x+1,y+1);
  return cache[x][y]=arr[x][y]+((down > down_left)? down : down_left);
}

int main(){
  int case_num;
  cin>>case_num;
  for(int i=0;i<case_num;++i){
    int row_num;
    cin>>row_num;
    for(int j=0;j<row_num;++j){
      for(int k=0;k<=j;++k){
        cin>>arr[j][k];
        cache[j][k]=-1;
      }
    }
    cout<<path(row_num,0,0)<<endl;
  }
  return 0;
}
