#include <iostream>
#include <vector>

using namespace std;

vector<int> sequence;

int cache[501];// the maximum lenght after we choose idx element.
int maxlen(int idx){
  if(idx==sequence.size()-1)return 1;
  if(cache[idx]!=-1)return cache[idx];
  int ret=0;
  for(int i=idx+1;i<sequence.size();i++){
    if(sequence.at(idx)<sequence.at(i)){
      int a = maxlen(i);
      ret = (ret >= a)? ret:a;
    }
  }
  return cache[idx]=ret+1;
}

int start(){
  int max=0;
  for(int j=0;j<501;++j)cache[j]=-1;
  for(int i=0;i<sequence.size();++i){
    int now=maxlen(i);
    max = (max >= now) ? max : now;
  }
  return max;
}

int main(){
  int num_case;
  cin>>num_case;
  for(int i=0;i<num_case;++i){
    int num_ele;
    cin>>num_ele;
    for(int j=0;j<num_ele;j++){
      int a;
      cin>>a;
      sequence.push_back(a);
    }
    cout<<start()<<endl;
    sequence.clear();
  }
  return 0;
}
