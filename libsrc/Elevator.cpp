#include "Elevator.hpp"

namespace Elevator {

    Elevator::Elevator(int timeBetweenFloors, int timeForOpening, int timeForClosing) {

        this->mTimeBetweenFloors = timeBetweenFloors;
        this->mTimeForOpening = timeForOpening;
        this->mTimeForClosing = timeForClosing;
    }

    int Elevator::elevatorOpen() {
        
        return mTimeForOpening;
    }

    int Elevator::elevatorClose() {

        return mTimeForClosing;
    }

    int Elevator::elevatorWait(int time) {

        return time;
    }

}
