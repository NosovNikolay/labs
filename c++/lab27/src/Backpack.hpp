#ifndef BACKPACK_H
#define BACKPACK_H

#include "Brand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

enum BackpackId
{
    LeatherBackpack_,
    Clothbackpack_
};

class Backpack
{
protected:
    string color;

    string appointment;

    bool laptop_comparament;

    unsigned volume;

    struct Brand *brand;

public:
    Backpack();

    Backpack(const Backpack &current_backapck);

    Backpack(string color_,
             string appointment_,
             bool laptop_comparament_,
             unsigned volume_,
             const struct Brand &brand_);

    virtual ~Backpack() = 0;

    virtual string ToString() const;

    virtual bool FillFromString(string str);

    virtual Backpack *Copy() const = 0;

    string GetColor() const;

    bool GetLaptopComparament() const;

    unsigned GetVolume() const;

    string GetAppointment() const;

    struct Brand &GetBrand() const;

    void SetColor(string color_);

    void SetLaptopComparament(bool laptop_comparament_);

    void SetAppointment(string appointment_);

    void SetVolume(unsigned volume_);

    void SetBrand(Brand *brand_);

    Backpack &operator=(const Backpack &other);

    bool operator==(const Backpack &other);

    friend std::ostream &operator<<(std::ostream &out, Backpack &other);

    friend std::istream &operator>>(std::istream &in, Backpack &other);

    static Backpack *GetBackpackOfType(BackpackId id);
};

#endif