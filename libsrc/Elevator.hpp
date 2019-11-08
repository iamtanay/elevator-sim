#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <iostream>

namespace Elevator {

    /**
     * @brief Class for elevator simulation.
     *
     * @details
     *  This class will handle all functions and
     *  activities of the lift in our simulation.
     **/
    class Elevator {

        public:

            Elevator(int timeBetweenFloors = 2, int timeForOpening = 3, int timeForClosing = 3);

            int elevatorOpen();

            int elevatorClose();

            int elevatorWait(int time);

        private:

            int mTimeBetweenFloors;

            int mTimeForOpening;

            int mTimeForClosing;

    };
}
#endif
