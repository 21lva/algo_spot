#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


bool no_man_man(char* mem,char* fan,int first,int last,int fan_start){
  if(first==last)return (mem[first] !='M'|| fan[first+fan_start]!='M');
  int mid = (last+first)/2;
  return no_man_man(mem,fan,first,mid,fan_start)&&no_man_man(mem,fan,mid+1,last,fan_start);
}

int main(){
  int numCase;
  scanf("%d",&numCase);
  for(int i=0;i<numCase;i++){
    char mem[200001];
    char fan[200001];
    scanf("%s",mem);
    scanf("%s",fan);
    int res=0;
    int len=strlen(fan)-strlen(mem);
    for(int i=0;i<=len;i++){
      if(no_man_man(mem,fan,0,strlen(mem)-1,i))res++;
    }
    cout<<res<<endl;
  }
  return 0;
}
