#include <iostream>

using namespace std;
int MAX_ROW;
int tri[101][101];
int cache[101][101];

int count=0;

int max_val(int row,int col){
  if(MAX_ROW == row)return tri[row][col];
  if(cache[row][col]!=-1)return cache[row][col];
  int bottom=max_val(row+1,col);
  int right=max_val(row+1,col+1);
  return cache[row][col] = tri[row][col]+((bottom>right)?bottom:right);
}


void max_num(int row,int col,int num){
  if(MAX_ROW==row){
    if(tri[row][col]==num)count++;
    return;
  }
  else if(cache[row][col]<num)return;
  else{
    max_num(row+1,col,num-tri[row][col]);
    max_num(row+1,col+1,num-tri[row][col]);
  }
}

void clear_cache(){
  for(int i=0;i<101;i++)
    for(int j=0;j<101;j++)
      cache[i][j]=-1;
}

void get_tri(){
  for(int i=0;i<101;i++)
    for(int j=0;j<101;j++)
      tri[i][j]=-1;
  for(int i=0;i<=MAX_ROW;i++)
    for(int j=0;j<=i;j++)
      cin>>tri[i][j];
}
int main(){
  int test_case;
  cin>>test_case;
  for(int i=0;i<test_case;i++){
    count=0;
    cin >> MAX_ROW;
    MAX_ROW--;
    clear_cache();
    get_tri();
    int max_Val=max_val(0,0);
    max_num(0,0,max_Val);
    cout<<count<<endl;

  }
  return 0;
}
