
//-----------------------------------------------------------
//  Purpose:    Header file for the fulladdr class.
//-----------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//-----------------------------------------------------------
// Define the fulladdr class interface 
//-----------------------------------------------------------

class fulladdr
{
public:
    // Constructors functions
    fulladdr();
    fulladdr(int House, string Street, string City, string State, int Zipcode);
    fulladdr(const fulladdr & param);
    ~fulladdr();
   
    // Setters functions
    void sethouse(int House);
    void setstreet(string Street);
    void setcity(string City);
    void setstate(string State);
    void setzipcode(int Zipcode);

    // Getters functions
    int    gethouse();
    string getstreet();
    string getcity();
    string  getstate();
    int getzipcode();
    string getsearchkey();

    // Other helper functions
    string print();
    

private:

   // private Fields
    int house;
    string street;
    string city;
    string state;
    int zipcode;
    string searchkey;
};
