

#include <iostream>

#include <string>

using namespace std;

 

#include "shape.h"

 

 

 //

//  shape.h

//  lab3

//

//  Created by Tarek Abdelrahman on 2018-08-25.

//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.

//

 

// ***********  ECE244 Student: DO NOT MODIFY THIS FILE  ***********

 

#ifndef shape_h

#define shape_h

 

#include <iostream>

#include <string>

using namespace std;

 

#endif /* shape_h */

 

/* class shape {

private:

    string name;                   // The name of the shape

    string type;                   // The type of the shape (see globals.h)

    int x_location;                // The location of the shape on the x-axis

    int y_location;                // The location of the shape on the y-axis

    int x_size;                    // The size of the shape in the x-dimension

    int y_size;                    // The size of the shape in the y-dimension

    int rotation = 0;              // The rotations of the shape (integer degrees)

public:

    // Build a shape object with its properties, constructor, need to define, define at last

    shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz);

   

    // Accessors functions

    string getType();              // Returns the type

    string getName();              // Returns the name of the shape

    int getXlocation();            // Returns location of the shape on the x-axis

    int getYlocation();            // Returns location of the shape on the y-axis

    int getXsize();                // Returns the size of the shape in the x-dimension

    int getYsize();                // Returns the size of the shape in the y-dimension

   

    // Mutators functions

    void setType(string t);        // Sets the type (see globals.h)

                                   // No error checking done inside the method

                                   // The calling program must ensure the type

                                   // is correct

    void setName(string n);        // Sets the name of the shape

    void setXlocation(int x_loc);  // Sets location of the shape on the x-axis

    void setYlocation(int y_loc);  // Sets location of the shape on the y-axis

    void setXsize(int x_sz);       // Sets size of the shape in the x-dimension

    void setYsize(int y_sz);       // Sets size of the shape in the y-dimension

   

    void setRotate(int angle);     // sets the rotation of the shape

   

    // Utility methods

    void draw();                   // Draws a shape; for this assignment it

                                   // only prints the information of the shape

};
 */

 

//Defining implementing each function.

 

 

 

//Accessors functions

string shape::getType(){

    return(type);

}

 

string shape::getName(){

    return(name);

};

 

int shape::getXlocation(){

    return(x_location);

};

 

int shape::getYlocation(){

    return(y_location);

};

 

int shape::getXsize(){

    return(x_size);

}             

 

int shape::getYsize(){

    return(y_size);

}

 

 

 

// Mutators functions

void shape::setType(string t){

    //see if we need to check whether inputted string t is a valid global variable.

    type=t;

    return;

};       

                               // No error checking done inside the method

                               // The calling program must ensure the type

                               // is correct

void shape::setName(string n){

    name=n;

    return;

};        // Sets the name of the shape

 

void shape::setXlocation(int x_loc){

    x_location=x_loc;

    return;

};  // Sets location of the shape on the x-axis

 

void shape::setYlocation(int y_loc){

    y_location=y_loc;

    return;

} ; // Sets location of the shape on the y-axis

 

void shape::setXsize(int x_sz){

    x_size= x_sz;

    return;

};       // Sets size of the shape in the x-dimension

 

void shape::setYsize(int y_sz){

    y_size= y_sz;

    return;

};       // Sets size of the shape in the y-dimension

 

void shape::setRotate(int angle){

    rotation= angle;

    return;

};     // sets the rotation of the shape

 

 

 

//Utility methods

 

void shape::draw(){

    cout << name << ": " << type << " " << x_location << " " << y_location << " " << x_size << " " << y_size << endl;

    return;

};                   // Draws a shape; for this assignment it

 

 

//Constructor:

shape::shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz){

   name=n;

   type=t;//check or is it outside

   x_location= x_loc;

   y_location= y_loc;

   x_size= x_sz;

   y_size= y_sz;  

};

 

 

// ECE244 Student:

// Write the implementation (and only the implementation) of the shape

// class below

 

 