
#include <string>
#include "morse.h"
/**
*brief the main function() its ask like an entry points
*author codecpacka
*date 25 nov 2021
*details the main function works as an entry point of any programme
*param none this function takes no parameters
*return  int of value 0;
*/

int main()
{
  char msg[100];
  // string test[7];
  cout << "enter a code msg" << endl;
  cin.getline(msg, 100);
  string text;
  cout << "encoded text is" << endl;
  text = encoded(msg);

  node *root = NULL;
  root = root->insert(data, root, n, 0);

  // cout << "viewing in order " << endl;   /// for testing purpose to check whether tree is being 
  // root->viewinorder();                   /// creating right or not
  // cout << endl;                         ////
  // cout << "viewing pre order" << endl;  ////
  // root->viewpreorder();                  //
  // cout << endl;                          //
  // cout << "viewing post order" << endl;
  // root->viewpostorder();
  cout << "\ndecoded text is" << endl;
  stringtoarr(text,root);
  return 0;
}