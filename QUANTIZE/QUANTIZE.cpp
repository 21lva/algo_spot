#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ROUND(x) ( floor((x) * pow(float(10),0) + 0.5f) / pow(float(10),0) )
#define INF 987654321;
using namespace std;

vector<int> &preprocess(vector<int> v){
  sort(v.begin(),v.end());
  int n=0;
  vector<int> sum;
  for(int i=0;i<v.size();v++){
    n+=v.at(i);
    sum.push_back(n);
  }
  return sum;
}

int minerror(vector<int> seq,vector<int> &sum,int begin,int end){
  int ret=0;
  if(begin-1>=0)
    int mean = ROUND((sum.at(end)-sum.at(begin-1))/(end-begin+1))
  else
    int mean = ROUND((sum.at(end))/(end-begin+1))
  for(int i=begin,i<=end;i++){
    ret+=(seq.at(i)-mean)*(seq.at(i)-mean);
  }
  return ret;
}

int cache[101][11];
int quant(vector<int> &seq,vector<int> &sum,int begin,int num_part){
  if(begin==seq.size())return 0;
  if(num_part==0)return return INF;
  if(cache[begin][part]==-1)return cache[begin][part];
  int n=-1;
  for(int i=1;i<seq.size()-begin;i++){
    int a = minerror(seq,sum,begin,begin+a-1) + quant(seq,sum,begin+a,num_part-1);
    n = (n>a) ? n:a;
  }
  return cache[begin][part]=n;
}
