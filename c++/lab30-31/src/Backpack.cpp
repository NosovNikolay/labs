#include "Backpack.hpp"

// Constructor with parameters
Backpack::Backpack()
{
    brand = new struct Brand("", "", "");
}

Backpack::Backpack(string color_,
                   AppointmentType appointment_,
                   bool laptop_comparament_,
                   unsigned volume_,
                   const struct Brand &brand_)
    : color(color_),
      appointment(appointment_),
      laptop_comparament(laptop_comparament_),
      volume(volume_)
{
    brand = new struct Brand(brand_.city, brand_.country, brand_.name_brand);
}
// Copy constructor
Backpack::Backpack(const Backpack &current_backpack)
    : color(current_backpack.color),
      appointment(current_backpack.appointment),
      laptop_comparament(current_backpack.laptop_comparament),
      volume(current_backpack.volume)
{
    brand = new struct Brand(current_backpack.brand->city,
                             current_backpack.brand->country,
                              current_backpack.brand->name_brand);
}
// Destructor
// Проверка не нужна, так как память выделяется в любом случае
Backpack::~Backpack()
{
    delete brand;
}

unsigned int Backpack::GetVolume() const
{
    return volume;
}

string Backpack::GetColor() const
{
    return color;
}

AppointmentType Backpack::GetAppointment() const
{
    return appointment;
}

struct Brand &Backpack::GetBrand() const
{
    return *brand;
}

bool Backpack::GetLaptopComparament() const
{
    return laptop_comparament;
}

void Backpack::SetAppointment(AppointmentType appointment_)
{
    appointment = appointment_;
}

void Backpack::SetBrand(Brand *brand_)
{
    if (brand != nullptr)
    {
        delete brand;
    }
    brand = brand_;
}

void Backpack::SetLaptopComparament(bool laptop_comparament_)
{
    laptop_comparament = laptop_comparament_;
}

void Backpack::SetVolume(unsigned volume_)
{
    volume = volume_;
}

void Backpack::SetColor(string color_)
{
    color = color_;
}

string Backpack::ToString() const
{

    stringstream string_s;

    string_s << color <<" "<< appointment <<" "<< laptop_comparament <<" "<< volume <<" "<< brand->country <<" "<< brand->city <<" "<< brand->name_brand;

    return string_s.str();
}
Backpack &Backpack::operator=(const Backpack &other)
{

    if (this != &other)
    {

        // Память выделена в любом случае, надо почистить
        delete this->brand;
        this->brand = new struct Brand(other.brand->country, other.brand->city, other.brand->name_brand);

        this->color = other.color;
        this->laptop_comparament = other.laptop_comparament;
        this->volume = other.volume;
        this->appointment = other.appointment;
    }
    return *this;
}
bool Backpack::operator==(const Backpack &other)
{

    return color == other.color &&
           appointment == other.appointment &&
           brand->city == other.brand->city &&
           brand->country == other.brand->country &&
           brand->name_brand == other.brand->name_brand &&
           laptop_comparament == other.laptop_comparament &&
           volume == other.volume;
}
std::ostream &operator<<(std::ostream &out, Backpack &other)
{
    out << other.ToString();
    return out;
}

