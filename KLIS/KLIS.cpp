#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define MIN -9999999
#define MAX 2000000001

int seq[501];
int len;
unsigned long long int K;
unsigned long long int cache1[501];
unsigned long long int cache2[501];
void clear_cache(){
  for(int i=0;i<501;i++){
    cache1[i]=-1;
    cache2[i]=-1;
  }
}

unsigned long long int lis(int idx){
  if(idx==len)return 1;
  if(cache1[idx]!=-1)return cache1[idx];

  unsigned long long int ret=0;
  for(int i = idx+1;i<=len;++i){
    if(seq[idx] > seq[i] )continue;
    int tmp = lis(i);
    ret = (ret>tmp)? ret : tmp;
  }
  return cache1[idx] = ret + 1;
}

unsigned long long int count(int idx){
  if(lis(idx) == 1)return 1;
  if(cache2[idx] != -1)return cache2[idx];

  unsigned long long int ret=0;
  for(int i = idx+1;i<=len;i++){
    if(seq[idx] < seq[i] && lis(idx) == lis(i)+1){
      ret += count(i);
      ret = (ret > MAX)? MAX : ret;
    }
  }
  return cache2[idx] = ret;
}

void str(int idx,unsigned long long int k,vector<unsigned long long int>& strs){
  if(k > count(idx))str(idx+1,k,strs);
  else{
    strs.push_back(seq[idx]);
    vector<pair<int,int> > followers;
    for(int i = idx+1;i<=len;i++){
      if(seq[idx] < seq[i] && lis(idx) == lis(i)+1){
        followers.push_back(make_pair(seq[i],i));
      }
    }
    sort(followers.begin(),followers.end());
    for(int i=0;i<followers.size();i++){
      if(count(followers.at(i).second) <k)k-=count(followers.at(i).second);
      else{
        str(followers.at(i).second,k,strs);
        break;
      }
    }
  }
}

int main(){
  int test_case;
  cin >> test_case;
  for(int i= 0;i<test_case;i++){
    clear_cache();
    cin>>len>>K;
    seq[0]=MIN;
    for(int j = 0;j<len;j++)cin>>seq[j+1];

    cout<<lis(0)-1<<endl;
    vector<unsigned long long int> strs;
    str(0,K,strs);
    for(int i=1;i<strs.size();++i)cout<<strs.at(i)<<" ";
    strs.clear();
  }
  return 0;
}
