#ifndef BACKPACK_H
#define BACKPACK_H

#include "brand.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Backpack
{
private:
    
    string color;

    string appointment;
    
    bool laptop_comparament;
    
    unsigned volume;
    
    Brand* brand;

public:
    
    Backpack();

    Backpack(const Backpack& current_backapck);

    Backpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    const struct Brand& brand_);

    ~Backpack();

    string GetColor() const;    
    
    bool GetLaptopComparament() const;

    unsigned GetVolume() const;

    string GetAppointment() const;

    Brand* GetBrand() const; 
    
    void SetColor(string color_);

    void SetLaptopComparament(bool laptop_comparament_);

    void SetAppointment(string appointment_);

    void SetVolume(unsigned volume_);

    void SetBrand(Brand* brand_);

};

#endif