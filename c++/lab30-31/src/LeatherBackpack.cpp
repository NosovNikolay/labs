#include "LeatherBackpack.hpp"

LeatherBackpack::LeatherBackpack(string color_,
                   AppointmentType appointment_,
                   bool laptop_comparament_,
                   unsigned volume_,
                   bool have_lining,
                   leatherType backpack_leather,
                   const Brand &brand_)
    {
        this->color = color_;
        this->appointment = appointment_;
        this->laptop_comparament = laptop_comparament_;
        this->volume = volume_;
        this->have_lining = have_lining;
        this->backpack_leather = backpack_leather; 
        //brand = new struct Brand(brand_.city, brand_.country, brand_.name_brand);
    }

LeatherBackpack::~LeatherBackpack()

{
}