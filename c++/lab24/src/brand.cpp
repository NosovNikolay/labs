#include "brand.hpp"
// Constructor with parameters
Brand::Brand(){    
}
Brand::Brand(string _country, 
            string _city, string 
            _name_brand)
            :country(_country),
            city(_city),
            name_brand(_name_brand){
}