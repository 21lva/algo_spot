#include <iostream>
#include <vector>

using namespace std;
#define INF 99999
vector<vector<int> > connection(10);

int lless(vector<int> cclock,int button,int times){
  vector<int> :: iterator clk_iter;
  for(clk_iter=connection.at(button).begin();clk_iter!=connection.at(button).end();clk_iter++){
    cclock.at(*clk_iter) += times;
    cclock.at(*clk_iter) %= 4;
  }
  if(button==9){
    for(int i=0;i<16;i++){
      if(cclock.at(i)!=0) return INF;
    }
    return times;
  }
  int ret=INF;
  for(int i=0;i<4;i++){
    int a = lless(cclock,button+1,i);
    ret = (ret < a) ? ret : a;
  }
  return ret+times;
}


int trans(int x){
  switch (x) {
    case 12:return 0;
    case 3 :return 1;
    case 6 :return 2;
    default :return 3;
  }
}
void connect(){
int a0[3]={0,1,2};
connection.at(0).assign(a0,a0+3);
int a1[4]={3,7,9,11};
connection.at(1).assign(a1,a1+4);
int a2[4]={4,10,14,15};
connection.at(2).assign(a2,a2+4);
int a3[5]={0,4,5,6,7};
connection.at(3).assign(a3,a3+5);
int a4[5]={6,7,8,10,12};
connection.at(4).assign(a4,a4+5);
int a5[4]={0,2,14,15};
connection.at(5).assign(a5,a5+4);
int a6[3]={3,14,15};
connection.at(6).assign(a6,a6+3);
int a7[5]={4,5,7,14,15};
connection.at(7).assign(a7,a7+5);
int a8[5]={1,2,3,4,5};
connection.at(8).assign(a8,a8+5);
int a9[5]={3,4,5,9,13};
connection.at(9).assign(a9,a9+5);
}

int most_less(vector<int>& val){
  int ret=INF;
  for(int i=0;i<4;i++){
    int a = lless(val,0,i);
    ret = (ret<a) ? ret : a;
  }
  if(ret==INF )return -1;
  return ret;
}

int main(){
  int num_case;
  cin>>num_case;
  connect();
  for(int i=0;i<num_case;i++){
    vector<int> val;
    int x;
    for(int j=0;j<16;j++){
      cin>>x;
      val.push_back(trans(x));
    }
    cout<<most_less(val)<<endl;
  }
}
