#include <iostream>

using namespace std;

double cache1[1001][1001];
double cache3[1001][1001];


double prob(int day,int height){
  // at day, at height
  if(cache1[day][height]!=-1)return cache1[day][height];
  if(day==0 && height == 0) return cache1[day][height] = 1;
  if(day <= 0 || height <= 0 ) return cache1[day][height] = 0;
  double x = prob(day-1,height-1);
  double y = prob(day-1,height-2);
  // cout << "day : " << day << " height : " << height <<" x : "<<x<<" y : "<<y <<endl;
  return cache1[day][height] = x*0.25+ y*0.75;
}

double func2(int day,int height){
  double ret=0;
  if(cache3[day][height]!=-1)return cache3[day][height];
  for(int i=height;i<=day*2;i++){
    double a=prob(day,i);
    // cout<<a<<endl;
    // cout<<a<<" "<<i<<" "<<day<<endl;
    ret+=a;
  }
  return ret;
}


void clear_caches(){
  for(int i=0;i<1001;i++)
    for(int j=0;j<1001;j++){
      // ret+=prob2(i,height);
      cache1[i][j]=-1;
      cache3[i][j]=-1;
    }
}


int main(){
  int test_case;
  cin>>test_case;
  for(int i=0;i<test_case;i++){
    clear_caches();
    int Day,Height;
    cin>>Height>>Day;
    cout<<func2(Day,Height)<<endl;
  }
}
