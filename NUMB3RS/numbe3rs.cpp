#include <iostream>
#include <vector>

using namespace std;

int M;
int list[51][51];
int adj_num[51];
int city_num;
int day;
double cache[101][51];

double prob(int day, int city){
  double ret = 0;
  if(day == 0 && M == city) return 1;
  if(day == 0) return 0;
  if(cache[day][city]>-0.5)return cache[day][city];

  for(int i=0 ; i<city_num ; i++){
    if(list[city][i] == 0)continue;
    ret += prob(day-1,i)/adj_num[i];
  }
  return cache[day][city]=ret;
}

void clearing(){
  for(int i=0;i<101;i++)
    for(int j=0;j<51;j++)
      {
        cache[i][j]=-1;
      }
    for(int j=0;j<51;j++)
      adj_num[j] = 0;
    for(int j = 0;j<51;j++)
      for(int k = 0;k<51;k++)
        list[j][k]=0;
}

int main(){
  int test_case;
  cin>>test_case;
  for(int i=0;i<test_case;i++){
    cin >> city_num >> day >> M;
    clearing();

    for(int j = 0;j<city_num;j++){
      for(int k = 0;k<city_num;k++){
          cin>>list[j][k];
          if(list[j][k] == 1)adj_num[j]++;
      }
    }

    int test_city;
    cin>>test_city;
    for(int f=0;f<test_city;f++){
      int nnn;
      cin>>nnn;
      cout<<prob(day,nnn)<<" ";
    }
    cout<<endl;
  }
  return 0;
}
