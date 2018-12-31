#include <iostream>

#include <sstream>

#include <string>

 

using namespace std;

 

#include "globals.h"

#include "shape.h"

 

// This is the shape array, to be dynamically allocated

shape** shapesArray;

// The number of shapes in the database, to be incremented
// everytime a shape is successfully created

int shapeCount = 0;
 
// The value of the argument to the maxShapes command
int max_shapes;


// ECE244 Student: you may want to add the prototype of
// helper functions you write here



//Checks if the inputName does or does not match the restrictions. If it does match, false is returned. If it doesn't match, true is returned
bool nameValid (string inputName){

    if ("all"==(inputName) || "maxShapes"==(inputName) || "create"==(inputName), "move"==(inputName) || "rotate"==(inputName) || "draw"==(inputName) || "delete"==(inputName) || "ellipse"==(inputName) || "rectangle"==(inputName)|| "triangle"==(inputName)){
        return(false);
    }
    else return(true);

}

//Checks through the array for shapes named same as "inputName". If a match is found, it returns true. Otherwise, it returns false.
bool nameMatch (shape* Array[], string inputName){
    bool matchingName= false;
    for(int i=0; i<max_shapes; i++) {
        
        if (Array[i] != NULL){

            if ( ((Array[i])->getName())==(inputName)){ 
                matchingName= true;
                break;

            }
        }
    }
    if (matchingName==true){
        return (true);

    }
    
    else if (matchingName==false){
        return (false);
    }

}

//Function creates a shape! Takes all required parameters as aruuments, and develops an object pointed to by an element of ShapesArray. 
void CreateNewShape(shape* Array[], string inputName, string inputType, int xPosInput, int yPosInput, int xSizeInput, int ySizeInput){ 

    //Checking if the array is full                                                                   

    if (shapeCount == max_shapes){
        cout<< "Error: shape array is full" << endl;
        return;
    }

    //A new object can be created at the element of array represented by shapeCount, so invoke constructor!
       
    Array[shapeCount]= new shape(inputName, inputType, xPosInput, yPosInput, xSizeInput, ySizeInput);
    
    cout << "Created " << inputName << ": " << inputType << " " << xPosInput << " " << yPosInput << " " << xSizeInput << " " << ySizeInput <<endl;
    
    //increment the shapeCount
    shapeCount++;
}


//Function that moves a shape to a particular location (x and y)
void moveShape(shape* Array[], string shapeName, int Xpos, int Ypos){
    
    int targetObject;
    bool nameFound= false;
    
        for(int i=0; i<max_shapes; i++) {
            if (Array[i] != NULL){
                if((Array[i]->getName())== shapeName){
                    nameFound= true; 
                    targetObject= i;
                    break;
                }
            }
        }
    
    if (nameFound==false){
        cout << "Error: shape " << shapeName << " not found" << endl;
        return;
    }
    
    //Double-check if invalid Xpos and YPos values are inputted
    
    if ((Xpos < 0) || (Ypos < 0)){
        cout<< "Error: invalid value" << endl;
        return;
    }
    
    else {
    
        Array[targetObject]-> setXlocation(Xpos);
        Array[targetObject]-> setYlocation(Ypos);
        
        cout << "Moved " << shapeName << " to " << Xpos << " " << Ypos << endl; 
        
    }
    
    return;    
}

//Function for setting the rotation value of a shape
void setRotate(shape* Array[], string shapeName, int rotationValue){
    
    int targetObject;
    bool nameFound= false;
    
        for(int i=0; i<max_shapes; i++) {
            
            if (Array[i] != NULL){
                
                if((Array[i]->getName())== shapeName){
                    nameFound= true; 
                    targetObject= i;
                    break;
                }
            }
        }
    
    if (nameFound==false){
        cout << "Error: shape " << shapeName << " not found";
        return;
    }
    
    //Check if invalid Xpos and YPos values are inputted
    
    if ((rotationValue < 0) || (rotationValue > 360)){
        cout<< "Error: invalid value" << endl;
        return;
    }
    
    else {
    
        Array[targetObject]->setRotate(rotationValue);
        
        cout << "Rotated " << shapeName << " by " << rotationValue <<" degrees" << endl; 
        
    }
    
    return;    
}


//Draw all shapes

void drawAll(shape* Array[]){
    
    cout << "Drew all shapes" << endl;
    
    for(int i=0; i<max_shapes; i++) {
        
            if(Array[i] != NULL){

                Array[i]->draw();
            }
         
        }
    
    return;
    
}

//Draw a specific Shape of the name "ShapeName"

void drawSpecificShape(shape* Array[], string shapeName){
    
    int targetObject;
    bool nameFound= false;
    
        for(int i=0; i<max_shapes; i++) {
            
            if (Array[i] != NULL){
                
                if((Array[i]->getName())== shapeName){
                    nameFound= true; 
                    targetObject= i;
                    break;
                }
            }
        }
    
    if (nameFound==false){
        cout << "Error: shape " << shapeName << " not found";
        return;
    } 
    
    else {
        cout << "Drew " << shapeName << endl;
        Array[targetObject]->draw();
    }
 
    return;
}



//Delete all objects in the array

void deleteAll(shape* Array[]){
    
    for(int i=0; i<max_shapes; i++) {
        
            if(Array[i] != NULL){
                delete Array[i];
                Array[i]= NULL;
                }
         
        }
    
    cout << "Deleted: all shapes" << endl;
    
    return;
}

//Function to delete all shapes in shapesArray, includes error messages as well, as a double check

void deleteSpecificShape (shape* Array[], string shapeName){
    
    int targetObject;
    bool nameFound= false;
    
        for(int i=0; i<max_shapes; i++) {
            
            if (Array[i] != NULL){
                
                if((Array[i]->getName())== shapeName){
                    nameFound= true; 
                    targetObject= i;
                    break;
                }
            }
        }
    
    if (nameFound==false){
        cout << "Error: shape " << shapeName << " not found" << endl;
        return;
    } 
    
    else{
        delete Array[targetObject];
        Array[targetObject]=NULL;
        cout << "Deleted shape " << shapeName << endl;;
    }
    
    return;
}


// Used to trim/cut the free spaces behind a string
void cutString(string& sentence)
{
    if (sentence.empty() == true) return;


    size_t len = sentence.size();
    while (sentence.rfind(" ") == --len)
    {
        sentence.erase(len, len + 1);
    }
}
 
 
//main function execution begins here!
 

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input

    getline(cin, line);   // Get a line from standard input

    //Trim the string to take out any blank spaces from the end. So that EOF immediately proceeds after the end of a string
    cutString(line);
    

    while (!cin.eof()) {

        // Put the line in a linestream for parsing

        // Making a new sstream for each line so the flags are cleared
        
        stringstream lineStream (line);

        // Read from string stream into the command
        
        // The only way this can fail is if the eof is encountered

        lineStream >> command;
        
        // Check for the command and act accordingly

        // ECE244 Student: Insert your code here
        
        //If command is not one of the valid types, error message will be printed. 
        
        if ((command != "maxShapes") && (command != "create") && (command != "move") && (command != "rotate") && (command != "draw") && (command  != "delete")){
 
            cout << "Error: invalid command" << endl;            
            
        }
        
        //If the command is "maxShapes", dynamically allocate a shapesArray containing pointers to objects of class shape
                
        if (command == "maxShapes"){
            
            lineStream >> max_shapes;
            
            shapesArray = new shape* [max_shapes];
            cout<< "New database: max shapes is " << max_shapes << endl;
        }
            
        //If the command is "create", check sequentially for errors, and finally if no errors are found, provoke Create function
       
        if (command == "create"){
            
            string Name;
            string FinalName;
            string Type; 
            string FinalType;
            int x_pos;
            int y_pos;
            int x_size;
            int y_size;
            int Finalx_pos;
            int Finaly_pos;
            int Finalx_size;
            int Finaly_size;
            bool argumentError=false;
            
            int createArg_count= 0;

            
            while (!lineStream.eof()){
                                                
                if (createArg_count == 0){
                
                    lineStream >> Name; 
                    
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        argumentError= true;
                        break;
                    }
                    else {
                        if (nameValid(Name)==true){
                            if ((nameMatch(shapesArray, Name))==false){
                            
                                FinalName=Name;
                                
                            }
                            else {cout << "Error: shape "<< Name << " exists" << endl; argumentError= true; break;};
                        }
                        else{cout << "Error: invalid shape name" << endl; argumentError= true; break;}
                    }
                
                }
                
                
                if (createArg_count == 1){

                
                    lineStream >> Type; 
                    if (lineStream.fail()){

                        cout<< "Error: invalid argument" << endl;
                        argumentError= true;
                        break;
                    }
                    
                    
                    
                    else {
                        if ("ellipse"==(Type) || "rectangle"==(Type)|| "triangle"==(Type)){      
                                FinalType=Type;
                        }
                        else {cout << "Error: invalid shape type" << endl; argumentError=true; break;};
                        }
                   
                }
                
                if (createArg_count == 2){
                
                    lineStream >> x_pos; 
                    if (lineStream.fail()){
                        cout<< "Error: invalid argument" << endl;
                        argumentError=true;
                        break;
                    }
                    else {
                        if (x_pos >= 0){      
                                Finalx_pos=x_pos;
                        }
                        else {cout << "Error: invalid value" << endl; argumentError=true; break;};
                        }
                
                }
                
                if (createArg_count == 3){
                
                    lineStream >> y_pos; 
                    if (lineStream.fail()){
                        cout<< "Error: invalid argument" << endl;
                        argumentError=true;
                        break;
                    }
                    else {
                        if (y_pos >= 0){      
                                Finaly_pos=y_pos;
                        }
                        else {cout << "Error: invalid value" << endl; argumentError=true; break;};
                        }
                
                }
                
                if (createArg_count == 4){
                
                    lineStream >> x_size; 
                    if (lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        argumentError=true;
                        break;
                    }
                    else {
                        if (x_size >= 0){      
                                Finalx_size=x_size;
                        }
                        else {cout << "Error: invalid value" << endl; argumentError=true; break;};
                        }
                
                }
                
                if (createArg_count == 5){
                
                    lineStream >> y_size; 
                    if (lineStream.fail()){
                        cout<< "Error: invalid argument" << endl;
                        argumentError=true;
                        break;
                    }
                    else {
                        if (x_pos >= 0){      
                                Finaly_size=y_size;
                        }
                        else {cout << "Error: invalid value" << endl; argumentError=true; break;};
                        }
                
                }
                
                if (createArg_count == 6 && (!lineStream.peek() == true)){
                    break;
                }
                
                if (createArg_count == 7){
                    break;
                }
                
               
                createArg_count++;
                
            }
                        
            if (createArg_count >= 7 && (argumentError==false)){
                cout << "Error: too many arguments" << endl;
            }
            
            if (createArg_count < 6 && (argumentError==false)){
                cout << "Error: too few arguments" << endl;
            }
            
            else if (createArg_count == 6 && (argumentError==false)) {
                CreateNewShape(shapesArray, FinalName, FinalType, Finalx_pos, Finaly_pos, Finalx_size, Finaly_size);
            }
            
            createArg_count=0;
            
   
        }
        
        
        //If the command is "move", check sequentially for errors, and finally if no errors are found in move function

        if (command == "move"){
            
            string moveName;
            string finalmoveName;
            int move_x;
            int move_y;
            int finalMove_x;
            int finalMove_y;
            bool moveArgumentError=false;
            
            int moveArg_count= 0;
            bool tooManyMoveArg= false;

            
            while (!lineStream.eof()){
                
                if (moveArg_count == 4){
                    tooManyMoveArg = true; 
                    break;
                    }
                                                
                if (moveArg_count == 0){
                
                    lineStream >> moveName; 
                    
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        moveArgumentError= true;
                        break;
                    }
                    
                    else{
                        
                        if ((nameMatch(shapesArray, moveName)) == false){
                         cout << "Error: shape "<< moveName << " not found" << endl;
                         moveArgumentError= true;
                         break;
                        }
                        
                        else {
                         finalmoveName = moveName;
                        }  
                    }
        
                }
                
                if (moveArg_count == 1){
                    
                    lineStream >> move_x;
                 
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        moveArgumentError= true;
                        break;
                    }
                    
                    else{
                        
                        if (move_x < 0){
                         cout << "Error: invalid value" << endl;
                         moveArgumentError= true;
                         break;
                        }
                        
                        else {
                         finalMove_x = move_x;
                        }  
                    }
                    
                    
                }
                
                
                if (moveArg_count == 2){
                    
                    lineStream >> move_y;
                 
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        moveArgumentError= true;
                        break;
                    }
                    
                    else{
                        
                            if (move_y < 0){
                             cout << "Error: invalid value" << endl;
                             moveArgumentError= true;
                             break;
                            }

                            else {
                             finalMove_y = move_y;
                            }  
                        }
                    }
                    
                    
                    if (moveArg_count == 2 && (!lineStream.peek() == true)){
                    break;
                    }

                    moveArg_count++;

                }

            if (moveArg_count >= 4 && (moveArgumentError==false) && (tooManyMoveArg == 1)){
                cout << "Error: too many arguments" << endl;
            }
            
            if (moveArg_count < 3 && (moveArgumentError==false)){
                cout << "Error: too few arguments" << endl;
            }
            
            else if (moveArg_count == 3 && (moveArgumentError==false)) {
               moveShape(shapesArray, finalmoveName, finalMove_x, finalMove_y);
            }
            
            moveArg_count=0;
                
                    
                
        }
        
        
        //If the command is "rotate", check sequentially for errors, and finally if no errors are found, provoke rotate functions

        if (command == "rotate"){
            
            string rotateName;
            string finalrotateName;
            int rotate;
            int finalRotate;
            bool rotateArgumentError=false;
            
            int rotateArg_count= 0;
            bool tooManyArguments= false;

            
            while (!lineStream.eof()){
                
                if (rotateArg_count== 3){
                    tooManyArguments= true; 
                    break;
                    }
                                                
                if (rotateArg_count == 0){
                
                    lineStream >> rotateName; 
                    
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        rotateArgumentError= true;
                        break;
                    }
                    
                    else{
                        
                        if ((nameMatch(shapesArray, rotateName)) == false){
                         cout << "Error: shape " << rotateName << " not found" << endl;
                         rotateArgumentError= true;
                         break;
                        }
                        
                        else {
                         finalrotateName = rotateName;
                        }  
                    }
        
                }
                
                if (rotateArg_count == 1){

                    lineStream >> rotate;
                 
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        rotateArgumentError= true;
                        break;
                    }
                    
                    else{
                        
                        if (rotate < 0 || rotate > 360){
                         cout << "Error: invalid value" << endl;
                         rotateArgumentError= true;
                         break;
                        }
                        
                        else {
                         finalRotate = rotate;
                        }  
                    }
                    
                    
                }
                
             
                if (rotateArg_count == 1 && (!lineStream.peek() == true)){
                break;
                }
                    
                rotateArg_count++;

            }

            if (rotateArg_count >= 3 && (rotateArgumentError==false) && (tooManyArguments == true)){
                cout << "Error: too many arguments" << endl;
            }
            
            if (rotateArg_count < 2 && (rotateArgumentError==false)){
                cout << "Error: too few arguments" << endl;
            }
            
            else if (rotateArg_count == 2 && (rotateArgumentError==false)) {
                setRotate(shapesArray, finalrotateName, finalRotate);
            }
            
            rotateArg_count=0;      
                
        }
        
        //If the command is "draw", check sequentially for errors, then check whether the subsequent command is "all" 
        //or the name of a shape. In accordance to the command, provoke the drawAll function or drawSpecificShape function

        if (command == "draw"){
            
            string DrawShape;
            string FinalDrawShape;
            int draw_counter=0;
            bool drawArgError=false;
            bool tooManyArg= false;
            
            while (!lineStream.eof()){
                
                    if (draw_counter == 1){
                        tooManyArg=true;
                        break;
                    }
                                                                    
                
                    lineStream >> DrawShape; 
                                        
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        drawArgError=true;
                        break;
                    }
                    
                    else{
                        
                        if (DrawShape == "all"){
                            
                            FinalDrawShape = DrawShape;
                            
                            }
                                                    
                        
                        
                        else if (DrawShape != "all"){
                            
                            if (nameMatch(shapesArray, DrawShape) == false){
                                cout << "Error: shape " << DrawShape << " not found" << endl;
                                drawArgError=true;
                                break;
                                
                            }
                            else{
                                
                                FinalDrawShape = DrawShape;
              
                            }
                        
                        }
                    
                       } 
                    
                    
             
                    draw_counter++;   

                   
                }
            
            
            if (draw_counter == 1 && (drawArgError==false) && (tooManyArg == true)){
                cout << "Error: too many arguments" << endl;
            }
            
            if (draw_counter < 1 && (drawArgError==false)){
                cout << "Error: too few arguments" << endl;
            }
            
            else if (draw_counter == 1 && (drawArgError==false) && (tooManyArg == false)) {
                
                if(FinalDrawShape == "all")
                drawAll(shapesArray);
                
                
                else if (FinalDrawShape != "all"){
                    drawSpecificShape(shapesArray, FinalDrawShape);
                }
            }            
            
            
        }
        
        //If the command is "delete", check sequentially for errors, then check whether the subsequent command is "all" 
        //or the name of a shape. In accordance to the command, provoke the deleteAll function or deleteSpecificShape function

        
        if (command == "delete"){
            
            string deleteShape;
            string FinalDeleteShape;
            int delete_counter=0;
            bool deleteArgError=false;
            bool OverArg= false;
            
            while (!lineStream.eof()){
                
                    if (delete_counter == 1){
                        OverArg=true;
                        break;
                    }
                                                                    
                
                    lineStream >> deleteShape; 
                                        
                    if (lineStream.fail()){
                        
                        cout<< "Error: invalid argument" << endl;
                        deleteArgError=true;
                        break;
                    }
                    
                    else{
                        
                        if (deleteShape == "all"){
                            
                            FinalDeleteShape = deleteShape;
                            
                            }
                                                    
                        
                        
                        else if (deleteShape != "all"){
                            
                            if (nameMatch(shapesArray, deleteShape) == false){
                                cout << "Error: shape " << deleteShape << " not found" << endl;
                                deleteArgError=true;
                                break;
                                
                            }
                            else{
                                
                                FinalDeleteShape = deleteShape;
                              
                            
                            }
                        
                        }
                    
                    } 
                    
                    
             
                    delete_counter++;   

                   
            }
            
            
            if (delete_counter == 1 && (deleteArgError==false) && (OverArg == true)){
                cout << "Error: too many arguments" << endl;
            }
            
            if (delete_counter < 1 && (deleteArgError==false)){
                cout << "Error: too few arguments" << endl;
            }
            
            else if (delete_counter == 1 && (deleteArgError==false) && (OverArg == false)) {
                
                if(FinalDeleteShape == "all")
                deleteAll(shapesArray);
                
                
                else if (FinalDeleteShape != "all"){
                    deleteSpecificShape(shapesArray, FinalDeleteShape);
                }
            }            
            
            
        }
        
  
 

        // Once the command has been processed, prompt for the

        // next command

        cout << "> ";          // Prompt for input

        getline(cin, line);   // Get the command line
        cutString(line);      // Remove spaces from the right side of the inputted line. 


       

    }  // End input loop until EOF.

   

    return 0;

}
