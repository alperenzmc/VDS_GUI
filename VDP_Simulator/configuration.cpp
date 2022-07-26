#include "configuration.h"
#include <iostream>




void Configuration::display() {
    std::cout<<"Latitude is: "<<latitude_m<<std::endl;
    std::cout<<"Longitude is: "<<longitude_m<<std::endl;
    std::cout<<"Velocity is: "<<velocity_m<<std::endl;
    std::cout<<"Acceleration is: "<<acceleration_m<<std::endl;
}

void Configuration::set_longitude(double longitude_val) {
    longitude_m=longitude_val;
}

void Configuration::set_latitude(double latitude_val) {
    latitude_m=latitude_val;
}

void Configuration::set_velocity(double velocity_val) {
    velocity_m=velocity_val;
}

void Configuration::set_acceleration(double acceleration_val) {
    acceleration_m=acceleration_val;
}
