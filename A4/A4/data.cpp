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
    vector<string> v1 = this->split(rawData, ',');
    if (v1.size() == 3)
    {
        this->birth = this->trim(v1.at(2));
        this->age = this->trim(v1.at(1));
        this->nameTokens = this->split(this->trim(v1.at(0)), ' ');
    }
}

string Data::trim(string &str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<string> Data::split(string raw, char delim)
{
    vector<string> v;
    istringstream split(raw);
    for (string each; getline(split, each, delim); v.push_back(each));
    return v;
}

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
    
    try {
        int a = stoi(this->age);
        if (a < 0)
        {
            *code = INVALID_AGE;
            return false;
        }
    } catch (invalid_argument) {
        *code = INVALID_AGE;
        return false;
    }
    
    if (this->birth.length() == 0)
    {
        *code = NO_BIRTH;
        return false;
    }
    
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

// Assuming isValid has been verified, otherwise may throw error
int Data::getAge()
{
    return stoi(this->age);
}

string Data::getBirth()
{
    return this->birth;
}

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
