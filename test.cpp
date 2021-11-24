#include <iostream>
#include<fstream>
using namespace std;

class node
{
public:
  char key;
  node *left;
  node *right;
  node *insert(node* root,char key);

};

node* node::insert(node* root,char key){

};
int main()
{
  string str;
  // cout << "hello world \n";
  node *root = NULL;
  ifstream in;
  in.open("sample.txt");

  // in>>str;
  // cout<<str;
  while(in.eof()==0){
  getline(in,str);
  // if(str=="-1")
  // cout<<"error"<<endl;
  // cout<<str;
  if(str.empty()){
    cout<<"null";
  }
  cout<<str<<endl;


  // in>>str;
  // if(str=="")
  // cout<<"null";
  // cout<<str<<endl;
  

  }
 


  
  return 0;
}