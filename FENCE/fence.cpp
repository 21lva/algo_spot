#include <iostream>
#include <vector>
using namespace std;

#define INF 999999
#define MINF -999999

int max_area(vector<int> &board,int left,int right){
  if(left==right)return board.at(left);//base case
  // cout<<" left : "<<left<<" right : "<<right<<endl;
  int mid = (right+left)/2;
  int left_side = max_area(board,left,mid);
  int right_side = max_area(board,mid+1,right);

  int ret = (left_side > right_side)? left_side:right_side;

  int maxarea = board.at(mid), minidx=mid, len=1;
  int new_right=mid, new_left=mid;

  while(new_right != right || new_left != left){
    if(new_right == right){
      --new_left;
      minidx = (board.at(new_left) < board.at(minidx)? new_left : minidx);
    }

    else if(new_left==left){
      ++new_right;
      minidx = (board.at(new_right) < board.at(minidx)? new_right : minidx);
    }
    else{
      if(board.at(new_right+1) < board.at(new_left-1)){
        --new_left;
        minidx = (board.at(new_left) < board.at(minidx)? new_left : minidx);
      }
      else{
        ++new_right;
        minidx = (board.at(new_right) < board.at(minidx)? new_right : minidx);
      }
    }
    len++;
    maxarea = (maxarea > board.at(minidx)*(len))? maxarea : board.at(minidx)*(len);
  }
  ret = (ret > maxarea)? ret:maxarea;
  // cout<<"ret : "<<ret<<" left : "<<left<<" right : "<<right<<endl;
  return ret;
}

int main(){
  int num_case;
  cin>>num_case;
  for(int i=0;i<num_case;i++){
    int num_board;
    cin>>num_board;

    vector<int> boards;
    for(int j=0;j<num_board;j++){
      int tmp;
      cin>>tmp;
      boards.push_back(tmp);
    }
    int res= max_area(boards,0,num_board-1);
    cout<<res<<endl;
  }
  return 0;
}
