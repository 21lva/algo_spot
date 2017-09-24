#include <iostream>
#include <vector>

using namespace std;

vector<int> sequence;

int cache1[100];// the maximum lenght after we choose idx element.
int maxlen1(int last,int start_idx){
  //return max length of two the strictly increasing sub-sequences one is including sequence[start_idx] the other is not.
  if(start_idx==sequence.size()-1){
    //base case
    //two case : whether include start_idx or not.
    if(last<sequence.at(start_idx)) return cache[start_idx]=1;
    else return 0;
  }
  if(last < sequence.at(start_idx) && cache[start_idx]!=-1){
    //the sub-sequence include start_idx element and it is already in memory.
    return cache[start_idx];
  }
  if(last < sequence.at(start_idx)){
    //the sub-sequence include start_idx element but it is the first meeting.
    return cache[start_idx]=1+maxlen1(sequence.at(start_idx),start_idx+1);
  }
  //not choose start_idx element.
  return maxlen1(last,start_idx+1);
}

int start1(){
  int max=0;
  for(int j=0;j<100;++j)cache1[j]=-1;
  for(int i=0;i<sequence.size();++i){
    int now=maxlen(-1,i);
    max = (max >= now) ? max : now;
  }
  return max;
}

int main(){

}
