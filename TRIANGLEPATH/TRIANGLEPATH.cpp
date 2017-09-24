#include <iostream>

using namespace std;



int arr[100][100];
int cache[100][100];
int path(int n,int x,int y){
  if(x==n-1)return cache[x][y]=arr[x][y];
  if(cache !=-1)return cache[x][y];
  int down=path(x+1,y);
  int down_left=path(x+1,y+1);
  return cache[x][y]=arr[x][y]+((down>down_left)? down:down_left);
}

int main(){
  
}
