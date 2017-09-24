#include <iostream>
#include <vector>

using namespace std;


vector<int> seq1;
vector<int> seq2;
int cache[101][101];
int maxlen(int idx1,int idx2){
  //base case
  if(idx1==seq1.size()-1 && idx2==seq2.size()-1) return 2;
  if(cache[idx1][idx2]!=-1)return cache[idx1][idx2];
  int max = (seq1.at(idx1) > seq2.at(idx2)) ? seq1.at(idx1):seq2.at(idx2);
  int a = -1;
  for(int i=idx1+1;i<seq1.size();++i){
    int now;
    if(seq1.at(i) > max)
        now = maxlen(i,idx2);
    if(a<now) a=now;
  }
  for(int i=idx2+1;i<seq2.size();++i){
    int now;
    if(seq2.at(i) > max)
        now = maxlen(idx1,i);
    if(a<now) a=now;
  }
  return cache[idx1][idx2] = a + 1;
}
