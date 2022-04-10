#ifndef BACKPACK_H
#define BACKPACK_H

#include "Brand.hpp"
#include <string>
#include <iostream>
#include <sstream>


using std::string;
using std::cout;
using std::endl;
using std::stringstream;
enum AppointmentType{
    Urban,
    Sport,
    Tactical
};
class Backpack
{
protected:
    
    string color;

    AppointmentType appointment;
    
    bool laptop_comparament;
    
    unsigned volume;
    
    struct Brand* brand;

public:
    
    Backpack();

    Backpack(const Backpack& current_backapck);

    Backpack(string color_,
    AppointmentType appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    const struct Brand &brand_);

    string ToString() const;

    ~Backpack();

    string GetColor() const;    
    
    bool GetLaptopComparament() const;

    unsigned GetVolume() const;

    AppointmentType GetAppointment() const;

    struct Brand& GetBrand() const; 
    
    void SetColor(string color_);

    void SetLaptopComparament(bool laptop_comparament_);

    void SetAppointment(AppointmentType appointment_);

    void SetVolume(unsigned volume_);

    void SetBrand(Brand* brand_);

    static Backpack* ReadFromString (string str);

    static Backpack* FillFromString(string str);    

    Backpack& operator=(const Backpack &other);

    bool operator==(const Backpack &other);

    friend std::ostream& operator<<(std::ostream& out, Backpack& other);

    friend std::istream& operator>>(std::istream& in, Backpack& other);

    virtual std::string display() = 0;
    virtual bool isLeather() = 0;
    virtual bool isCloth() = 0;
};

#endif