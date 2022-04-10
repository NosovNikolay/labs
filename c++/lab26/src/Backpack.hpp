#ifndef BACKPACK_H
#define BACKPACK_H

#include "Brand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

class Backpack
{
protected:
    
    string color;

    string appointment;
    
    bool laptop_comparament;
    
    unsigned volume;
    
    struct Brand* brand;

public:
    
    Backpack();

    Backpack(const Backpack& current_backapck);

    Backpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    const struct Brand &brand_);

    string ToString() const;

    ~Backpack();

    string GetColor() const;    
    
    bool GetLaptopComparament() const;

    unsigned GetVolume() const;

    string GetAppointment() const;

    struct Brand& GetBrand() const; 
    
    void SetColor(string color_);

    void SetLaptopComparament(bool laptop_comparament_);

    void SetAppointment(string appointment_);

    void SetVolume(unsigned volume_);

    void SetBrand(Brand* brand_);

    static Backpack* ReadFromString (string str);

    static Backpack* FillFromString(string str);    

    Backpack& operator=(const Backpack &other);

    bool operator==(const Backpack &other);

    friend std::ostream& operator<<(std::ostream& out, Backpack& other);

    friend std::istream& operator>>(std::istream& in, Backpack& other);
};

#endif
