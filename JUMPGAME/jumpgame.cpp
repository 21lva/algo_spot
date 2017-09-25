#include<iostream>

using namespace std;


int cache[100][100];
int N;
int board[100][100];
//pos(int row,int col) : there is a possible way to the end from (row,col)

int poss(int row,int col){
  if(row==N-1 && col==N-1) return 1;
  if(cache[row][col] != -1) return cache[row][col];
  int &ret = cache[row][col];
  ret=0;
  if(row+board[row][col]<N)if(poss(row+board[row][col],col)) return 1;
  if(col+board[row][col]<N)if(poss(row,col+board[row][col])) return 1;
  return 0;
}

void clear(){
  for(int i=0;i<100;i++)for(int j=0;j<100;j++){
    cache[i][j] = -1;
    board[i][j] = 0;
  }
}
void get_num(int row){
  for(int i=0;i<row;i++)
    for(int j=0;j<row;j++)
      cin>>board[i][j];
}

int main(){
  int num_case;
  cin>>num_case;
  for(int i=0;i<num_case;i++){
    cin>>N;
    clear();
    get_num(N);
    cout<<((poss(0,0))?"YES":"NO")<<endl;
  }
  return 0;
}
