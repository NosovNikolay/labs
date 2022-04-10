#ifndef BRAND_H
#define BRAND_H
#include <string>
using std::string;

// Struct for brand 
struct Brand{

    Brand(string _country, 
        string _city, 
        string _name_brand);

    string country;
    string city;
    string name_brand;
};

#endif