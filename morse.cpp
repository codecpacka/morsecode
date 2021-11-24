
#include <string>
#include "morse.h"

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

  // cout << "viewing in order " << endl;   /// for testing purpose
  // root->viewinorder();                   ///
  // cout << endl;                         ////
  // cout << "viewing pre order" << endl;  ////
  // root->viewpreorder();                  //
  // cout << endl;                          //
  // cout << "viewing post order" << endl;
  // root->viewpostorder();
  cout << "\ndecoded text is" << endl;
  stringtoarr(count, text, root);
  return 0;
}