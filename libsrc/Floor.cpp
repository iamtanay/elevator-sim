#include "Floor.hpp"
#include <iostream>

namespace Elevator {

    Floor::Floor(int floorNumber) {
        
        std::cout<<"Initializing Floor "<<floorNumber<<std::endl;
        this->mFloorNumber = floorNumber;
    }
}
