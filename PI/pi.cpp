#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

#define ALL_SAME 1
#define MONO_ONE 2
#define ONE_TWO 4
#define SAME_DIF 5
#define ELSE 10
#define INF 999999


string line;
int cache[10001];

int check3(int idx){
  if(line.at(idx)==line.at(idx+1) && line.at(idx)==line.at(idx+2))return ALL_SAME;
  if(line.at(idx)-line.at(idx+1)==1&&line.at(idx+1)-line.at(idx+2)==1)return MONO_ONE;
  if(line.at(idx)-line.at(idx+1)==-1&&line.at(idx+1)-line.at(idx+2)==-1)return MONO_ONE;
  if(line.at(idx)==line.at(idx+2))return ONE_TWO;
  if(line.at(idx)-line.at(idx+1)==line.at(idx+1)-line.at(idx+2))return SAME_DIF;
  return ELSE;
}
int check4(int idx){
  if(line.at(idx)==line.at(idx+1) && line.at(idx)==line.at(idx+2)&&line.at(idx+1)==line.at(idx+3))return ALL_SAME;
  if(line.at(idx)-line.at(idx+1)==1&&line.at(idx+1)-line.at(idx+2)==1&&line.at(idx+2)-line.at(idx+3)==1)return MONO_ONE;
  if(line.at(idx)-line.at(idx+1)==-1&&line.at(idx+1)-line.at(idx+2)==-1&&line.at(idx+2)-line.at(idx+3)==-1)return MONO_ONE;
  if(line.at(idx)==line.at(idx+2)&&line.at(idx+1)==line.at(idx+3))return ONE_TWO;
  if(line.at(idx)-line.at(idx+1)==line.at(idx+1)-line.at(idx+2)&&line.at(idx+1)-line.at(idx+2)==line.at(idx+2)-line.at(idx+3))return SAME_DIF;
  return ELSE;
}
int check5(int idx){
  if(line.at(idx)==line.at(idx+1) && line.at(idx)==line.at(idx+2) && line.at(idx+1)==line.at(idx+3) && line.at(idx+1)==line.at(idx+4))return ALL_SAME;
  if(line.at(idx)-line.at(idx+1)==1&&line.at(idx+1)-line.at(idx+2)==1&&line.at(idx+2)-line.at(idx+3)==1&&line.at(idx+3)-line.at(idx+4)==1)return MONO_ONE;
  if(line.at(idx)-line.at(idx+1)==-1&&line.at(idx+1)-line.at(idx+2)==-1&&line.at(idx+2)-line.at(idx+3)==-1&&line.at(idx+3)-line.at(idx+4)==-1)return MONO_ONE;
  if(line.at(idx)==line.at(idx+2)&&line.at(idx+1)==line.at(idx+3)&&line.at(idx)==line.at(idx+4))return ONE_TWO;
  if(line.at(idx)-line.at(idx+1)==line.at(idx+1)-line.at(idx+2)&&line.at(idx+1)-line.at(idx+2)==line.at(idx+2)-line.at(idx+3))
    if(line.at(idx+2)-line.at(idx+3)==line.at(idx+3)-line.at(idx+4))return SAME_DIF;
  return ELSE;
}
int min1(int a,int b,int c){
  int ret = (a<b)? a : b;
  ret = (ret < c) ? ret : c;
  return ret;
}

int f(int idx){
  if(cache[idx]!=-1)return cache[idx];
  if(idx > line.size()-1)return 0;
  //three
  int three,four,five;

  if(idx>=line.size()-2)three=INF;
  else three = check3(idx);
  if(idx>=line.size()-3)four=INF;
  else four = check4(idx);
  if(idx>=line.size()-4)five=INF;
  else five = check5(idx);

  return cache[idx] = min1(three+f(idx+3),four+f(idx+4),five+f(idx+5));
}
void invert(int n){
  stack<int> tmp_stack;
  while(n!=0){
    tmp_stack.push(n%10);
    n=n/10;
  }
  while(!tmp_stack.empty()){
    cout<<tmp_stack.top();
    line.push_back(tmp_stack.top());
    tmp_stack.pop();
  }
  cout<<endl;
}
void cache_clear(){
  for(int i=0;i<10001;++i)cache[i]=-1;
}
int main(){
  int num_case;
  cin>>num_case;
  ofstream oufFILE("res.txt");
  for(int i=0;i<num_case;i++){
    // line.clear();
    cache_clear();
    // int N;
    cin>>line;
    // invert(N);
    int ll=f(0);
    // oufFILE<<ll<<endl;
    cout<<ll<<endl;
    // cout<<line<<endl;
  }
  return 0;
}
