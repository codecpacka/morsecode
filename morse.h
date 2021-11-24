#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

string data[40];
int n = 0, count = 0;

/**
  *@brief  class with name node has been created to implement morse code tree
  *@author codecpacka
  *@date 25 nov 2021
  *@details this class is created to use the properties and functionality/concepts of oops it isused   to generate tree node instead of using structures
 *@param constructure char data type for leaf node generation
*/

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
  node *insert(string arr[], node *root, int n, int i); ///declaration of the insert function
  void viewinorder();                                   ///declaration of inorder traversal function for testing purpose only
  void viewpreorder();                                  ///declaration of preorder traversal function for testing purpose only
  void viewpostorder();                                 ///declaration of postorder traversal function for testing purpose only
  void decoder(string letter, int i);                   ///declaration of decoder function for decodig the morse code
};

/**
 * @brief *this function creates a morse tree for an array in where elemets are store in level fashion  
 * @author codecpacka
 * @date 25 NOV 2021
 * @param arr and array of string from which the morse tree in generated
 * @param root a object of class node used to keep the initial starting point of the tree
 * @param n int type used to tell how many elements are present in the array;
 * @param i int datatype used to traverse the array in the function;
 * @return node* returns updated valued to the position of root/first element of tree;
 * @details this function takes an arr as input which is generated while reading the file morse.txt then the elements first character is used to create a morse tree in inorder fashion here the variable n is caculated by reading the number of lines present in the file and int i is used to traverse the elements stored in array arr
 */
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


///these below functions were only created for testing purpose only///////

void node::viewinorder() //for viewing tree in in order fashion
{                        //i.e (left,root,right)
  if (this->left != NULL)
    this->left->viewinorder();
  cout << this->symbol << " ";
  if (this->right != NULL)
    this->right->viewinorder();
}
void node::viewpreorder() //for viewing tree in in order fashion
{                         //i.e (root,left,right)
  cout << this->symbol << " ";
  if (this->left != NULL)
    this->left->viewpreorder();
  if (this->right != NULL)
    this->right->viewpreorder();
}
void node::viewpostorder() //for viewing tree in  postorder fashion
{                          //i.e (left,right,root)

  if (this->left != NULL)
    this->left->viewpostorder();
  if (this->right != NULL)
    this->right->viewpostorder();
  cout << this->symbol << " ";
}


/**
 * @brief function name search() used to decode the morse code from a given string
 * @author codecpacka
 * @date 25 nov 2021
 * @param letter the morse code of a particular alphabet
 * @param i use to increment character count until delimeter is encountered
 * @return  void
 * @details this function is called from with another function which passes a set of filtered out string which this function takes as input and then according to each character the tree is traversed and when the delimeter is met the value to that particular node is printed and thus the loop continuos in a recursive manner until the delimeter i.e "," is met 
 */

void node::decoder(string letter, int i)
{
  if (letter[i] == '.')
  {
    this->left->decoder(letter, i + 1);
  }
  else if (letter[i] == '-')
  {
    this->right->decoder(letter, i + 1);
  }
  else
  {
    cout << this->symbol;
  }
}

/**
 * @brief function name encoded it takes the user message in plain txt format   
 * @author codecpacka
 * @date 25 nov 2021
 * @param msg message provided by user
 * @return encoded an encoded string in morse code format
 * @details this function takes an user input then it read a txt file containg the alphabhar along with its appropriate morse code then it concatinates the input strings/lines from the file into an data array for future purpose then it return an concatinated string by adding delimeter i.e "," to it
 */
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
        cout << temp << " ";
        encoded.append(temp);
        encoded.append(",");
        count++;
        break;
      }
    }
  }
  cout << endl;

  return encoded;
}

/**
 * @brief function name stringtoarr this function converts a large string and pass it to another function     for   decoding
 * @author codecpacka
 * @date 24 nov 2021 
 * @param text the string which contain the encoded morse code which is to be decoded 
 * @param root the initial pointer to the tree 
 * @details this function takes an string along with pointer to the top node of the tree then it appends delimeter to the end of each morse code alphabet completion then the set of code is passed to decoder function for decoding the morse code 
 */
void stringtoarr(string text, node *root)
{
  string letter;
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] == ' ')              //coutering spaces in string 
    {
      cout << " ";
      continue;
    }
    if (text[i] != ',')
    {
      letter.append(1, text[i]);
    }
    else
    {
      letter.append(1, ',');
      root->decoder(letter, 0);                   //calling decoder 
      letter = "";                                //clearing letter string 
    }
  }
}
