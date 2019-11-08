#include <vector>

#include <Elevator/Elevator.hpp>
#include <Elevator/TripManager.hpp>
#include <Elevator/Floor.hpp>


using namespace Elevator;

int main() {

    int numberOfFloors;
    std::cout<<"Enter number of floors in the building: "<<std::endl;
    std::cin>>numberOfFloors;

    std::vector<Floor> floors;
    for(int i = 0; i < numberOfFloors; i++) {

        Floor newFloor(i);
        floors.push_back(newFloor);
    }

    return 0;
}
