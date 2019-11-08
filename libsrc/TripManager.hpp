#ifndef TRIP_MANAGER_HPP
#define TRIP_MANAGER_HPP

#include <iostream>
#include "Elevator.hpp"

namespace Elevator {

    /**
     * @brief Class for handling a trip by the user.
     *
     * @details
     *  This class will handle all functions.
     **/
    class TripManager {

        public:

            TripManager(int fromFloor, int toFloor);

            ~TripManager();

            Elevator assignElevator();


        private:

            void totalTimeOfTrip();
            
            int mFromFloor;

            int mToFloor;

            int mTotalTimeOfTrip;

    };
}
#endif
