// Define a shape class. Derive Triangle, Square and Rectangle classes. Demonstrate the
// use of virtual function by including display_area ( ) as a virtual function

#include<iostream> 
using namespace std; 
  
class Shape // base class
{ 
public: 
    virtual void display_area ()  //virtual function : in base class always
    { 
    	cout<< "shape class : Area : " <<endl; 
    } 
}; 
  
class Triangle:public Shape 
{ 
public: 
    void display_area () 
    { 
    	cout<< "Triangle class: Area: " <<endl; 
    } 
}; 
  
class Rectangle:public Shape 
{ 
public: 
    void display_area () 
    { 
    	cout<< "Rectangle class : Area : " <<endl; 
    } 
};

class Square:public Shape 
{ 
public: 
    void display_area () 
    { 
    	cout<< "Square class : Area : " <<endl; 
    } 
};

int main() 
{ 
	
    Shape *bptr;  // Base pointer to base class Shape

    Triangle T;  //derived class 
    bptr = &T;   //  pointing base class pointer to derived class object
    bptr->display_area();  // fuction overriding 

    Square S;  //derived class 
    bptr = &S;    //  pointing base class pointer to derived class object
    bptr->display_area();   // fuction overriding 


    Rectangle R;  //derived class 
    bptr = &R;   //  pointing base class pointer to derived class object
    bptr->display_area();   // fuction overriding 
    return 0;
} 