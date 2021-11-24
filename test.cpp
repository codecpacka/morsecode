#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

class node
{
public:
  char key;
  node *left;
  node *right;
  node *insert(node *root, char key);
};

node *node::insert(node *root, char key){

};
int main()
{
  string str,encoded,temp;
  char msg[100];
  int n = 0;
  string data[40];

  // cout << "hello world \n";
  node *root = NULL;
  ifstream in;
  in.open("sample.txt");

  // in>>str;
  // cout<<str;
  while (in.eof() == 0)
  {

    getline(in, str);
    // in>>str;
    // if (str.empty())
    // {
      
    //   data[n] = "ram";
    // }
    data[n] = str;
    // cout << str << endl;
    n++;
  }

  cout << "no of lines are " << n;
  cout << endl;
  // for (int i = 0; i < n; i++)
  // {
  //   // cout << data[i] << endl;
  //   if (data[i] == "")
  //     cout << "empty";
  // }
  cout << "enter a code msg" << endl;
  cin.getline(msg, 100);
  

  for (int c = 0; c < strlen(msg); c++)
  {
    for (int i = 0; i < n; i++)
    {
      if (msg[c] == data[i].at(0))
      {
        // cout<< data[i];
        // data[i].copy(temp,3,1); 
        temp=data[i].substr(1,4);
        cout<<temp;
        encoded.append(temp);
        encoded.append(",");
        break;
      }
    }
  }
cout<<endl;
cout<<encoded;
  return 0;
}