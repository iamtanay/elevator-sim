#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <iostream>
#include "spdlog/spdlog.h"

namespace Elevator {

    /**
     * @brief Class for properties of a Floor in building.
     *
     * @details
     *  This class will handle all functions and
     *  activities happening on the floor in the simulation.
     **/
    class Floor {

        public:

            Floor(int floorNumber);

            bool elevatorAtFloor();

            void pressDown();

            void pressUp();

            void waitOnFloor(int time);


        private:

            int mFloorNumber;

    };
}
#endif
