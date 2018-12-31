/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gillja45
 *
 * Created on November 22, 2018, 6:26 AM
 */

//TESTING DBENTRY

#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"


using namespace std;

//Overloaded operator for printing a DBentry type object
ostream& operator<<(ostream& out, const DBentry& rhs) {

    string ActiveStatus;

    if (rhs.active == false) {
        ActiveStatus = "inactive";
    } else ActiveStatus = "active";

    out << rhs.name << " : " << rhs.IPaddress << " : " << ActiveStatus << endl;

    return (out);
}

//Overloaded operator for printing TreeDB type object, uses a TreeDB class function called FullTreePrinter
ostream& operator<< (ostream& out, const TreeDB& rhs) {
    rhs.FullTreePrinter(rhs.root, out);
    return (out);
}


int main(int argc, char** argv) {
    
    
    string line;
    string command;
    
    //Ask user for input
    cout << "> ";        

    // Receiving a line from from input, and inserting into string called line
    getline(cin, line);   

    //Declare a Database of type TreeDB, which will be used for whole program
    
        TreeDB TreeDatabase;

    while (!cin.eof()) {

        // Parse the line using linestream function, used to extract each of the words in the string line
        
        stringstream lineStream (line);
        
        // Assuming all input is correct, insert first word of line into string command, and act accordingly based on 
        // the command

        lineStream >> command;
        
        //If the command is insert, do this:       
        if (command == "insert"){
            
            string Name;
            unsigned int IPaddress; 
            string status;
            bool StatusofActive;
 
            while (!lineStream.eof()){
  
                lineStream >> Name; 
                
                //Check if the name already exists, if it does, break the loop
                    if (TreeDatabase.find(Name) != NULL){
                        cout << "Error: entry already exists" << endl; 
                        break;
                    }
                        
                lineStream >> IPaddress;
                lineStream >> status;
                
                if (status == "active") StatusofActive= 1;
                else if (status == "inactive") StatusofActive=0;
                
                TreeDatabase.insert(new DBentry(Name, IPaddress, StatusofActive));
                
                //Check if the entry was successfully inserted 
                if (TreeDatabase.find(Name) != NULL){
                        cout << "Success" << endl; 
                        break;
                    }
                else {cout << "Problem in entry" << endl;}
            }
   
        }
        
        //If the command is to find an entry in the database
        if (command == "find"){
            
            string FindName;
            
            while (!lineStream.eof()){
                
                lineStream >> FindName;
                
                DBentry* found= TreeDatabase.find(FindName);
                
                if (TreeDatabase.find(FindName) != NULL) {
                    cout << *(TreeDatabase.find(FindName));
                }
                
                else {
                    cout << "Error: entry does not exist" << endl;
                }
                break;
  
             }
        }
        
        //If the command is to remove an entry 
        if (command == "remove"){
            
            string Name;
            
            while (!lineStream.eof()){
                
                lineStream >> Name;
                                
                if (TreeDatabase.find(Name) != NULL) {
                    TreeDatabase.remove(Name);
                }
                
                //Removed, check does it exist right now, if not remove was successful!
                if (TreeDatabase.find(Name) == NULL){
                 cout << "Success" << endl;
                }
                
                else {
                    cout << "Error: entry does not exist" << endl;
                }
                break;
            }
        }
        
        //Print the whole database 
        if (command == "printall"){
            cout << TreeDatabase;
        }
        
        //Printing the probes 
        if (command == "printprobes"){
            
            string Name;
            
            
            while (!lineStream.eof()){
                
                lineStream >> Name;
                
                //Check whether the entry even exists, if it does, then print its probes
                                
                if (TreeDatabase.find(Name) != NULL) {
                    TreeDatabase.printProbes();
                }
                
                else {
                    cout << "Error: entry does not exist" << endl;
                }
                
                break;
             }
        }
        
        //Delete the whole tree
        
        if (command == "removeall"){
            
            TreeDatabase.clear();
            cout << "Success" <<endl;
          
        }
        
        //Execute countactive, printing the number of "active" entries in database
        
        if (command == "countactive"){
            
            TreeDatabase.countActive();
        }
        
        //Updating the status of an entry to either active or inactive
        if (command == "updatestatus"){
            
            string Name;
            string Status;
            bool UpdateStatus;
            
            while (!lineStream.eof()){
                lineStream >> Name;
                lineStream >> Status;
                
                if (Status == "active") UpdateStatus= 1;
                else if (Status == "inactive") UpdateStatus=0;
                
                DBentry* finder= TreeDatabase.find(Name);
                
                if (finder == NULL) {
                    cout << "Error: entry does not exist";
                    break;     
                }
                
                else {
                    //change the active value of where finder, a DBEntry pointer points to
                    finder->setActive(UpdateStatus);
                    cout << "Success" << endl;
                }
                
                break;
                
             }
        }
        

        // Once the command has been processed, prompt for the next command

        // next command
        command = "";          //Clear the previous command to prevent the issue of recurring commands when pressed enter
        cout << "> ";          // Prompt for input

        getline(cin, line);   // Get the command line

    }  // End input loop until EOF.

   

    //clear the Database when no more commands are to be given
    TreeDatabase.clear();

    return 0;

}
    
    
   