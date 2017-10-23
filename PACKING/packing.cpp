#include <iostream>
#include <queue>

#define MAXVAL 9999999
#define MINVAL -9999999
using namespace std;

typedef struct _item{
  string name;
  int volume;
  int value;
  bool is_already;
}item;

int many;
int capacity;
item items[100];
int cache[1001][101];


int max_val(int capa,int idx){
  if(capa < 0)return MINVAL;
  if(idx == many) return 0;
  if(cache[capa][idx] != -1) return cache[capa][idx];
  int yes = max_val(capa - items[idx].volume,idx+1)+ items[idx].value;
  int no =  max_val(capa,idx+1);
  return cache[capa][idx] = ((yes>no) ? yes : no);
}

void max_str(int capa,int idx,queue<string> &strlist){
  if(idx==many)return;
  if(max_val(capa,idx)==max_val(capa,idx+1))max_str(capa,idx+1,strlist);
  else{
    strlist.push(items[idx].name);
    max_str(capa-items[idx].volume,idx+1,strlist);
  }
}



void clear_items(){
  for(int i=0;i<100;i++){
    items[i].name = ' ';
    items[i].volume = 0;
    items[i].value = 0;
    items[i].is_already = false;
  }
}

void get_items(){
  for(int i=0;i<many;i++){
    cin >> items[i].name >> items[i].volume >> items[i].value;
  }
}

void clear_cache(){
  for(int i=0;i<1001;i++)
    for(int j=0; j<101;j++)
      cache[i][j]=-1;
}



int main(){
  int test_case;
  cin>> test_case;
  for(int i=0;i<test_case;i++){
    clear_items();
    clear_cache();

    cin >> many >> capacity;
    get_items();

    int tmp = max_val(capacity,0);
    queue<string> strlist;
    max_str(capacity,0,strlist);

    cout <<tmp <<" "<<strlist.size()<<endl;

    while(!strlist.empty()){
      cout<<strlist.front()<<endl;
      strlist.pop();
    }
  }
  return 0;
}
