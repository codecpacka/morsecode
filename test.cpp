#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;
string data[40];
int n = 0,count=0;
class node
{
public:
  char symbol;
  node *left;
  node *right;
  node(char symbol)
  {
    this->symbol = symbol;
    this->left = NULL;
    this->right = NULL;
  }
  node *insert(string arr[], node *root, int n, int i);
  void viewinorder();
  void viewpreorder();
  void viewpostorder();
  void lsearch(string letter,int i);
  node *search(node *root, string letter,int i);
};

node *node::insert(string arr[], node *root, int n, int i)
{

  if (i < n)
  {
    node *temp = new node(arr[i][0]);
    root = temp;
    // cout << root->symbol << endl;
    //inserting in left
    root->left = insert(arr, root->left, n, (2 * i) + 1);
    //inseting in right
    root->right = insert(arr, root->right, n, (2 * i) + 2);
  }
  return root;
};
void node::viewinorder()
{
  if (this->left != NULL)
    this->left->viewinorder();
  cout << this->symbol << " ";
  if (this->right != NULL)
    this->right->viewinorder();
}
void node::viewpreorder()
{
  cout << this->symbol << " ";
  if (this->left != NULL)
    this->left->viewpreorder();
  if (this->right != NULL)
    this->right->viewpreorder();
}
void node::viewpostorder()
{
  if (this->left != NULL)
    this->left->viewpostorder();
  if (this->right != NULL)
    this->right->viewpostorder();
  cout << this->symbol << " ";
}
void node::lsearch(string letter,int i){
// cout<<"inside recursion"<<endl;
// cout<<letter[i];
if (letter[i]== '.'){

    // cout<<this->symbol;r
    // cout<<"going left";
    this->left->lsearch(letter,i+1);
}
  else if (letter[i]== '-'){
//  cout<<this->symbol;
    // cout<<"going right";
    this->right->lsearch(letter,i+1);
  }
  else{
  cout << this->symbol;
  }
}


//encoding and returning the encoded test
string encoded(char msg[])
{
  string str, encoded, temp;

  // int n = 0;
  // string data[40];

  ifstream in;
  // in.open("sample.txt");
  in.open("sample.txt");

  while (in.eof() == 0)
  {
    getline(in, str);

    data[n] = str;

    n++;
  }

  // cout << "no of lines are " << n;
  // cout << endl;ra

  for (int c = 0; c < strlen(msg); c++)
  {
    if (msg[c] == ' ')
    {
      encoded.append(" ");
      continue;
    }
    for (int i = 0; i < n - 2; i++)
    {
      if (data[i] == "")
        continue;
      if (msg[c] == data[i].at(0))
      {

        temp = data[i].substr(1, 4);
        cout << temp<<" ";
        encoded.append(temp);
        encoded.append(",");
        count++;
        break;
      }
    }
  }
  cout << endl;
  // cout << encoded;
  return encoded;
}
void stringtoarr(int count,string text,node *root){
  string letter;
  for (int i = 0; i < text.length(); i++)
  {
    if(text[i]== ' '){
      cout<<" ";
    continue;
    }
    if(text[i]!=',')
    {
      letter.append(1,text[i]);
    }
    else{
      letter.append(1,',');
      // cout<<"letter is"<<letter;
      // node* temp=temp->search(root,letter,0);
      root->lsearch(letter,0);

  // cout<<"search completed";r

      
      letter="";
      
    }
  }
  
}

int main()
{
  char msg[100];
  // string test[7];
  cout << "enter a code msg" << endl;
  cin.getline(msg, 100);
  string text;
  cout<<"encoded text is"<<endl;
  text = encoded(msg);
  // cout << text << endl; // node *root=NULL;
  // cout<<"number of letter are "<<count<<endl;
  node *root = NULL;
  root = root->insert(data, root, n, 0);

  // cout << "viewing in order " << endl;   /// for testing purpose
  // root->viewinorder();                   ///
  // cout << endl;                         ////
  // cout << "viewing pre order" << endl;  ////
  // root->viewpreorder();                  //
  // cout << endl;
  // cout << "viewing post order" << endl;
  // root->viewpostorder();
  cout<<"\ndecoded text is"<<endl;
  stringtoarr(count,text,root);
  return 0;
}