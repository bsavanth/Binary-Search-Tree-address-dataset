//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include "fulladdr.h"
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public:
   string Key;
   fulladdr Value;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
   BinaryTree(const BinaryTree & tree);
    ~BinaryTree();

  
   void read(string filename);
   bool Insert(string key, fulladdr value);
   string Search(string key);
   int Height();
   void Print(string filename);
   

 private:
   // Helper functions
   void CopyHelper(Node * Tree1, Node * &Tree2);
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string key, Node * Tree);
   bool InsertHelper(string key, fulladdr value, Node * &Tree);
   void PrintHelper(Node * Tree);
   int HeightHelper(Node * Tree);
  
   // Tree pointer
   Node *Root;
   ofstream dout;
};