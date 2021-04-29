//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//-----------------------------------------------------------
#include "tree.h"
#include <stdlib.h>
#include <fstream>
//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
   
}

//-----------------------------------------------------------
// Copy constructor helper function.
//-----------------------------------------------------------
void BinaryTree::CopyHelper(Node * Tree1, Node * &Tree2)
{
   // Check terminating condition
   if (Tree1 == NULL)
      Tree2 = NULL;

   // Copy node and it's children
   else
   {
      Tree2 = new Node;
      Tree2->Value = Tree1->Value;
      Tree2->Key = Tree1->Key;
      CopyHelper(Tree1->Left, Tree2->Left);
      CopyHelper(Tree1->Right, Tree2->Right);
   }
}

//-----------------------------------------------------------
// Copy constructor.
//-----------------------------------------------------------
BinaryTree::BinaryTree(const BinaryTree & B)
{
   // Call tree copy function
   CopyHelper(B.Root, Root);
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Reading the file
//-----------------------------------------------------------

void BinaryTree::read(string filename)
{
   // Open files
   ifstream din;
   din.open(filename);
   // Local variables
   string number;
   string street;
   string city;
   string state;
   string zip;

   // Loop reading input file
   while (!din.eof())
   {
    
        string line;
        
        // Read house number
        getline(din, line);
        number = line;
        if (din.eof()) return;
        
        // Read the street name
        getline(din, line);
        street = line;
        if (din.eof()) return;
        
        // Read the city name
        getline(din, line);
        city = line;
        if (din.eof()) return;
        
        // Read the state name
        getline(din, line);
        state = line;
        if (din.eof()) return;
        
        // Read zip code
        getline(din, line);
        zip = line;
        if (din.eof()) return;
       
        // Read empty line
        getline(din, line);
       
        int numb = atoi( number.c_str() );
        int zipcode = atoi( zip.c_str() );
        
        fulladdr f(numb, street, city, state, zipcode);
        Insert(f.getsearchkey(), f);
    
   }
   
   din.close();

}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string key, fulladdr value, Node * &Tree)
{
   // Insert key and value into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Key = key;
      Tree->Value = value;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Update value if key found
   else if (Tree->Key == key)
   {
      Tree->Value = value;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Key > key)
      return (InsertHelper(key, value, Tree->Left));
   else if (Tree->Key <= key)
      return (InsertHelper(key, value, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string key, fulladdr value)
{
   // Call tree insertion function
   return (InsertHelper(key, value, Root));
}


//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
string BinaryTree::Search(string key)
{
   // Call tree searching function
   if(SearchHelper(key, Root))
   {
       return "\n";
   }
   else
   {
     return "\n Key Not found in the Tree\n";   
   }
}
//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string key, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->Key == key)
   {
      cout<<"\n Key found in the Tree\n";
      cout<<endl;
      cout<<Tree->Value.print();
      return true;
   }

   // Recursively search for data value
   else if (Tree->Key > key)
      return (SearchHelper(key, Tree->Left));
   else if (Tree->Key < key)
      return (SearchHelper(key, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Height Helper function
//-----------------------------------------------------------

int BinaryTree::HeightHelper(Node * Tree)
{
    if(Tree!=NULL)
    {
        int leftheight = HeightHelper(Tree->Left);
        int rightheight = HeightHelper(Tree->Right);
        
        if(leftheight>rightheight)
        {
            return leftheight+1;
        }
        else
        {
            return rightheight+1;
        }
    }
    else
    {
        return 0;
    }
}

//-----------------------------------------------------------
// Calculate the height of the binary tree.
//-----------------------------------------------------------
int BinaryTree::Height()
{
    return HeightHelper(Root);
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      dout<<Tree->Value.print()<<endl;

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print(string filename)
{
   dout.open(filename);
   PrintHelper(Root);
   cout << endl;
   dout.close();
}






