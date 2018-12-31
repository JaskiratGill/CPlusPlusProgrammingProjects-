#include "DBentry.h"

	// the default constructor
	DBentry::DBentry(){
            name= "0";
            IPaddress= 0;
            active = 0;        
        }
        
        
        DBentry::DBentry(string _name, unsigned int _IPaddress, bool _active){
        
            name = _name;
            IPaddress = _IPaddress;
            active = _active;      
        
        }

	// the destructor
 	DBentry::~DBentry(){
            
          //Nothing to be done
        
        }
	

	// sets the domain name, which we will use as a key.
	void DBentry::setName(string _name){
            name = _name;
        }

	// sets the IPaddress data.
	void DBentry::setIPaddress(unsigned int _IPaddress){
            IPaddress = _IPaddress;
        }
    
        // sets whether or not this entry is active.
        void DBentry::setActive (bool _active){
            active = _active;
        }

        // returns the name.
	string DBentry::getName() const{
            return (name);
        }

	// returns the IPaddress data.
	unsigned int DBentry::getIPaddress() const{
            return (IPaddress);
        }

        // returns whether or not this entry is active.
        bool DBentry::getActive() const{
            return (active);
        }



