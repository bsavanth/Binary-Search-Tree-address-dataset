
//-----------------------------------------------------------
//  Purpose:    Main Program.
//-----------------------------------------------------------

#include <fstream>
#include <iostream>
#include "tree.h"
#include <vector>
using namespace std;

int main()
{
    
   // Welcome text to the program
   cout<<"\n\n Welcome to Binary Search Tree Demonstration";
  
   
   // Get the name of the input file
   string filename;
   cout<<"\n\n Enter the name of the file to read: ";
   std::getline(std::cin >> std::ws, filename);
   
   //Initialize a Binary Tree
   BinaryTree btree;
   btree.read(filename);
    
   bool infiniteloop = true;

   // Infinite while loop to maintain program state until we wish to exit
   while(infiniteloop)
   {
        int choice=0;
        
        // Displaying the menu
        cout<<"\n Available options are:\n 1) Insert a new address into the BST\n 2) Search BST using a city and state\n 3) Calculate height of the tree\n 4) Print tree into a file\n 5) Exit\n\n";
        
        //Get users choice of operation
        cout<<" Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            
            //-----------------------------------------------------------
            // Adds new address in the BST
            //-----------------------------------------------------------
            case 1: { 
                
                int number;
                string street;
                string city;
                string state;
                int zip;
                cout<<"\n Enter house/apt number: ";
                cin>>number;
                cout<<"\n Enter the name of the street: ";
                std::getline(std::cin >> std::ws, street);
                cout<<"\n Enter the name of the city: ";
                std::getline(std::cin >> std::ws, city);
                cout<<"\n Enter the name of the state: ";
                std::getline(std::cin >> std::ws, state);
                cout<<"\n Enter zip code: ";
                cin >>zip;
                
                // Initialize fulladdr class using parameters
                fulladdr f(number, street, city, state, zip);
                // call Insert to insert the fulladdr object and searchkey
                btree.Insert(f.getsearchkey(), f);
            } break;
        
        
            //-----------------------------------------------------------
            // Search for address in the BST using a key (city+street)
            //-----------------------------------------------------------
            case 2: { 
        
                string street;
                string city;
                cout<<"\n Enter the name of the street: ";
                std::getline(std::cin >> std::ws, street);
                cout<<"\n Enter the name of the city: ";
                std::getline(std::cin >> std::ws, city);
                string key = city+" "+street;
                cout<<"\n\n";
                btree.Search(key);
                cout<<"\n\n";
            } break;
            
           
           
            //-----------------------------------------------------------
            // Calculate the Height of the tree
            //-----------------------------------------------------------
            case 3: {
                
                cout<<"\n\n Height of the tree: "<<btree.Height()<<endl;
            } break;
            
           
           
            //-----------------------------------------------------------
            // Print the tree into a file
            //-----------------------------------------------------------
            case 4: {
                
                string filename;
                cout<<"\n Enter the name of the file to print: ";
                std::getline(std::cin >> std::ws, filename);
                btree.Print(filename);
            } break;
            
           
            //-----------------------------------------------------------
            // Exit the program
            //-----------------------------------------------------------
            case 5: infiniteloop = false; break;
           
            
            //-----------------------------------------------------------
            // Default Choice
            //-----------------------------------------------------------
            default: cout<<"\n Enter correct choice\n";
        } 
        
   }
  
 
   return 0;
}