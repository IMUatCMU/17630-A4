//
//  data.hpp
//  A4
//
//  Data is the class for holding the entry data. This class handles data parsing,
//  validation and comparison
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef data_hpp
#define data_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "comparable.hpp"

using namespace std;

class Data : public Comparable<Data>
{
private:
    string rawData;
    // intentionally store the name as a vector
    // judging from the sample input file, name tokens can be 2, 3, and 4 in length.
    // hence assuming if last token is the last name, the second last is the first name.
    vector<string> nameTokens;
    // intentionally store the age as string, so we don't run into any trouble in initialization
    string age;
    string birth;
    
    // helper function to parse raw input data
    vector<string> split(string raw, char delim);
    string trim(string &str);
    
public:
    // validation error codes
    const int NO_FIRST_NAME = -1;
    const int NO_LAST_NAME = -2;
    const int NO_AGE = -3;
    const int INVALID_AGE = -4;
    const int NO_BIRTH = -5;
    const int BIRTH_FORMAT_ERROR = -6;
    
    Data(string rawData);                   // constructor accepting an input string
    bool isValid(int *code);                // validates the data, provide the code to see details
    string getFirstName();                  // return the first name
    string getLastName();                   // return the last name
    int getAge();                           // return the age
    string getBirth();                      // return the birth
    string toString();                      // return a string representation of this object
    int compare(Data *other);               // implement comparable
    ~Data() {};                             // default destructor
};

#endif /* data_hpp */
