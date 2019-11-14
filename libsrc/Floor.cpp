#include "Floor.hpp"

namespace Elevator {

    Floor::Floor(int floorNumber) {        
        this->mFloorNumber = floorNumber;
        spdlog::info("Floor creation for floor Number : {}",this->mFloorNumber);
    }
}
