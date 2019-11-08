#include "TripManager.hpp"

namespace Elevator {


    TripManager::TripManager(int fromFloor, int toFloor) {

        this->mFromFloor = fromFloor;
        this->mToFloor = toFloor;
    }

    TripManager::~TripManager() {
        this->totalTimeOfTrip();
    }

    void TripManager::totalTimeOfTrip() {

        std::cout<<"Total Time of Trip : : "<< this->mTotalTimeOfTrip <<std::endl;

    }

    Elevator TripManager::assignElevator() {

    }


}
