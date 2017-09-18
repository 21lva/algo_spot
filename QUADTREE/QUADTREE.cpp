#include <iostream>
#include <vector>

using namespace std;

#define BLACK true
#define WHITE false
#define LEAF true
#define NOT_LEAF false

int ORDER[4] = {2,3,0,1};
int CHAR_IDX=0;

class node{
private:
  bool leaf;
  bool black;
  vector<node> child;
public:
  node(){
    leaf=false;
  }
  void set_leaf(const bool is_leaf){
    this->leaf = is_leaf;
  }
  void set_child(node &new_node ,int i){
    if(child.size()==0){
      for(int i=0;i<4;i++) child.push_back(node());
    }
    if(i>=4){
      cout<<"Error : no empty children space"<<endl;
      return;
    }
    this->child.at(i) = new_node;
  }
  node &ith_child(int i){return this->child.at(i);  }
  bool is_leaf(){return this->leaf;}
  void set_color(bool is_black){this->black=is_black;}
  bool is_black(){return this->black;}
};


class Reader{
private:
  node root;
  string now_str;
public:
  void Read_data(){
    int num_case;
    cin >> num_case;
    for(int case_index=0; case_index<num_case; case_index++) cin >> now_str;
  }
  void make_tree(){
    CHAR_IDX=-1;
    make_node(root);
  }
  void make_node(node &now_node){
    CHAR_IDX++;
    if(CHAR_IDX<this->now_str.size()){
      char now_char = this->now_str.at(CHAR_IDX);
      if(now_char == 'x'){
        node child_node[4];
        for(int k=0;k<4;k++) now_node.set_child(child_node[k],k);
        for(int k=0;k<4;k++) make_node(now_node.ith_child(k));
      }
      else{
        now_node.set_leaf(LEAF);
        now_node.set_color(((now_char == 'w')? WHITE : BLACK));
      }
    }
  }
  void print_reversed(){
    print_node(root);
    cout<<endl;
  }
  void print_node(node &now_node){
    if(!(now_node.is_leaf())){
      cout<<'x';
      for(int i=0;i<4;i++)print_node(now_node.ith_child(ORDER[i]));
    }
    else{
      cout<<((now_node.is_black())? 'b':'w');
    }
  }
};


int main(){
  Reader player;
  //Read data
  player.Read_data();
  //make 4 children tree
  player.make_tree();
  //print reversed picture's quadtree
  player.print_reversed();

  return 0;
}
