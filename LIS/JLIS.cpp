#include <iostream>
#include <vector>

using namespace std;


vector<int> seq1;
vector<int> seq2;
int cache[101][101];
int maxlen(int idx1,int idx2){
  //base case
  //they are the last two elements
  if(idx1 == seq1.size()-1 && idx2 == seq2.size()-1 && seq1.at(idx1) != seq2.at(idx2)) return 2;
  else if(idx1 == seq1.size()-1 && idx2 == seq2.size()-1)return 1;

  if(cache[idx1][idx2]!=-1) return cache[idx1][idx2];
  //choose a bigger element of two
  int max = (seq1.at(idx1) > seq2.at(idx2)) ? seq1.at(idx1) : seq2.at(idx2);
  int a = 0;
  int now = -2;
  // cout<<" before : "<<a;
  for(int i=idx1+1;i<seq1.size();++i){
    if(seq1.at(i) > max)
        now = maxlen(i,idx2);
    if(a<now) a = now;
  }
  for(int i=idx2+1;i<seq2.size();++i){
    if(seq2.at(i) > max)
        now = maxlen(idx1,i);
    if(a<now) a = now;
  }
  // cout<<idx1<<","<<idx2<<" after : "<<a<<endl;
  // return a+1;
  return cache[idx1][idx2] = a + 1;
}

void clear_cache(){
  for(int i=0;i<101;++i)
    for(int j=0;j<101;++j)cache[i][j]=-1;
}
int main(){
  int num_case;
  cin>>num_case;
  for(int i=0;i<num_case;++i){
    clear_cache();
    seq1.clear();
    seq2.clear();
    seq1.push_back(-1);
    seq2.push_back(-1);
    int strlen1,strlen2;
    cin>>strlen1>>strlen2;
    for(int i1=0;i1<strlen1;++i1){
      int tmp;
      cin>>tmp;
      seq1.push_back(tmp);
    }
    for(int i2=0;i2<strlen2;++i2){
      int tmp;
      cin>>tmp;
      seq2.push_back(tmp);
    }
    cout<<maxlen(0,0)-2;
  }
  return 0;

}
