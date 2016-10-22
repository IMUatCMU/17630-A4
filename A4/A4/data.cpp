//
//  data.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#include "data.hpp"
#include <sstream>

Data::Data(string rawData)
{
    vector<string> v1 = this->split(rawData, ',');                  // split by comma
    
    // only parse when there are 3 tokens, if not 3 tokens, we don't do anything, the validation later on will
    // mark this item as invalid.
    if (v1.size() == 3)
    {
        this->birth = this->trim(v1.at(2));                         // birth is the last token
        this->age = this->trim(v1.at(1));                           // age is the second last
        this->nameTokens = this->split(this->trim(v1.at(0)), ' ');  // split first token by space to be name tokens
    }
}

/*
 * Trim any leading and trailing space
 */
string Data::trim(string &str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

/*
 * Split by a character into a vector of string
 */
vector<string> Data::split(string raw, char delim)
{
    vector<string> v;
    istringstream split(raw);
    for (string each; getline(split, each, delim); v.push_back(each));
    return v;
}

/*
 * Validate data and return necessary error codes
 */
bool Data::isValid(int *code)
{
    if (this->nameTokens.size() == 0)
    {
        *code = NO_LAST_NAME;
        return false;
    }
    
    if (this->nameTokens.size() == 1)
    {
        *code = NO_FIRST_NAME;
        return false;
    }
    
    if (this->age.length() == 0)
    {
        *code = NO_AGE;
        return false;
    }
    
    // make sure age is a non-negative number
    try {
        int a = stoi(this->age);
        if (a < 0)
        {
            *code = INVALID_AGE;
            return false;
        }
    }
    catch (invalid_argument) {
        *code = INVALID_AGE;
        return false;
    }
    
    if (this->birth.length() == 0)
    {
        *code = NO_BIRTH;
        return false;
    }
    
    // check birth format
    int mm, yy, dd;
    sscanf(this->birth.c_str(), "%2d-%2d-%4d", &mm, &dd, &yy);
    if ((mm < 1 || mm > 12) || (dd < 1 || dd > 31) || (yy < 0))
    {
        *code = BIRTH_FORMAT_ERROR;
        return false;
    }
    
    return true;
}

string Data::getFirstName()
{
    return this->nameTokens.at(this->nameTokens.size() - 2);
}

string Data::getLastName()
{
    return this->nameTokens.at(this->nameTokens.size() - 1);
}

int Data::getAge()
{
    return stoi(this->age); // Assuming isValid has been verified, otherwise may throw error
}

string Data::getBirth()
{
    return this->birth;
}

/*
 * Implementation to Comparable interface, here we compare by last name
 */
int Data::compare(Data *other)
{
    if (this->getLastName() == other->getLastName())
        return 0;
    return this->getLastName() < other->getLastName() ? -1 : 1;
}

/*
 * Return a string representation of the data it holds
 */
string Data::toString()
{
    stringstream ss;
    for (size_t i = 0; i < this->nameTokens.size(); i++)
    {
        if (i > 0)
            ss << " ";
        ss << this->nameTokens[i];
    }
    ss << ", ";
    ss << this->age;
    ss << ", ";
    ss << this->birth;
    return ss.str();
}
