#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* fan meeting problme
  it is easy
  1. get number of case
  2. for each case, get two strings; members and fans
  3. change two strings to bit if M is in ith seat, then put 1 on the bit.
  ex) MMMFFF -> 111000
  4. by shift fans 1 bit to right. do bit-and operator. if it is not 0, then there is 1 & 1.
    it means that there is a pair with two men.


    *******
    M : number of fans
    N : nuber of members
    time to make bits : O(N)+O(M)
    time to compare two bits : O(M)
    time of all comparing : O(M *N -M^2)
    its time-order is O(M*N) (all case M<=N)


    it is square, but it is suficiently fast, because for all comparings I use bit operation which is very very fast operation.
    *******
*/

int string_to_bits(string &str){
  int bits=0;
  int len=str.size();
  for(int i=0 ; i<len ; i++){
    bits+=pow(2,i)*((str.at(i)=='M')? 1:0);
  }
  return bits;
}
//
// void print_bit(int x){
//   for(int i=0;i<32;i++){
//     cout<<x%2;
//     x=x>>1;
//   }
//   cout<<endl;
// }

int main(){
  int num_case;
  cin>>num_case;
  for(int i=0;i<num_case;i++){
    string member;
    string fan;
    cin >> member >> fan;
    int res=0;
    int len = fan.size()-member.size();
    int mem_bits=string_to_bits(member);
    int fan_bits=string_to_bits(fan);
    for(int j=0; j<len+1;j++){
      if((mem_bits & fan_bits)==0)res++;//there is a case from man to man;
      fan_bits = fan_bits >> 1;
    }
    cout<<res<<endl;
  }
  return 0;
}
