
//-----------------------------------------------------------
//  Purpose:    Implementation of fulladdr class.
//-----------------------------------------------------------

#include "fulladdr.h"
#include<string>

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
fulladdr::fulladdr()
{
    house=0;
    street= "";
    city = "";
    state = "";
    zipcode = 0;
    searchkey = city+" "+street;
}

//-----------------------------------------------------------
// Constructor function with paramters
//-----------------------------------------------------------

fulladdr::fulladdr(int House, string Street, string City, string State, int Zipcode)
{
    house = House;
    street = Street;
    city = City;
    state = State;
    zipcode = Zipcode;
    searchkey = city+" "+street;
}

//-----------------------------------------------------------
// Copy Constructor.
//-----------------------------------------------------------

fulladdr::fulladdr(const fulladdr & param)
{
    house = param.house;
    street = param.street;
    city = param.city;
    state = param.state;
    zipcode = param.zipcode;
    searchkey = param.city+" "+param.street;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------

fulladdr::~fulladdr()
{
    
}

//-----------------------------------------------------------
// Setter function for the field house.
//-----------------------------------------------------------

void fulladdr::sethouse(int House)
{
    house = House;
}

//-----------------------------------------------------------
// Setter function for the field street.
//-----------------------------------------------------------

void fulladdr::setstreet(string Street)
{
    street = Street;
}

//-----------------------------------------------------------
// Setter function for the field city.
//-----------------------------------------------------------
void fulladdr::setcity(string City)
{
    city = City;
}

//-----------------------------------------------------------
// Setter function for the field state.
//-----------------------------------------------------------
void fulladdr::setstate(string State)
{
    state = State;
}

//-----------------------------------------------------------
// Setter function for the field Zipcode.
//-----------------------------------------------------------
void fulladdr::setzipcode(int Zipcode)
{
    zipcode = Zipcode;
}

//-----------------------------------------------------------
// Getter function for the field house.
//-----------------------------------------------------------
int fulladdr::gethouse()
{
    return house;
}

//-----------------------------------------------------------
// Getter function for the field street.
//-----------------------------------------------------------
string fulladdr::getstreet()
{
    return street;
}

//-----------------------------------------------------------
// Getter function for the field city.
//-----------------------------------------------------------
string fulladdr::getcity()
{
    return city;
}
//-----------------------------------------------------------
// Getter function for the field state.
//-----------------------------------------------------------
string  fulladdr::getstate()
{
    return state;
}

//-----------------------------------------------------------
// Getter function for the field Zipcode.
//-----------------------------------------------------------
int fulladdr::getzipcode()
{
    return zipcode;
}

//-----------------------------------------------------------
// Getter function for the field Search Key.
//-----------------------------------------------------------
string fulladdr::getsearchkey()
{
    return searchkey;
}

//-----------------------------------------------------------
// Function to print all the fields in the class.
//-----------------------------------------------------------

string fulladdr::print()
{
    
    auto newhouse = std::to_string(house);
    auto newzipcode = std::to_string(zipcode);
    
    return newhouse+"\n"+street+"\n"+city+"\n"+state+"\n"+newzipcode+"\n";
    
}










