#include <iostream>
#include <vector>

using namespace std;


double arr[101][101];

double reach(int day,int height,int obj_day,int obj_depth){
  //base case
  if(day == obj_day && height >= obj_depth)return 1;
  if(day == obj_day) return 0;
  if(arr[day][height] >= 0) return arr[day][height];
  return arr[day][height] = 0.25*reach(day+1,height+2,obj_day,obj_depth)+0.75*reach(day+1,height+1,obj_day,obj_depth);
}

int main(){
  int depth,day;
  cin>>depth>>day;
  for(int i=0;i<101;i++)
    for(int j=0;j<101;j++)
      arr[i][j] = -1;
  cout<< reach(0,0,day,depth) <<endl;
  cout<<0.25*0.25*0.25+0.25*0.25*0.75*3;
  return 0;
}
