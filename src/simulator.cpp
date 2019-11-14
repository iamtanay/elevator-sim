#include <Elevator/Elevator.hpp>
#include <Elevator/TripManager.hpp>
#include <Elevator/Floor.hpp>
#include <Elevator/Record.hpp>
#include <Elevator/InputReader.hpp>


using namespace Elevator;

int main() {

    try {
        int numberOfFloors;
        std::cout<<"Enter number of floors in the building: ";
        std::cin>>numberOfFloors;

        std::vector<Floor> floors;
        for(int i = 0; i < numberOfFloors; i++) {

            Floor newFloor(i);
            floors.push_back(newFloor);
        }

        InputReader* inputRead = InputReader::getInstance("input/sampleInput.csv",numberOfFloors);

        std::vector<Record> records = inputRead->getInputRecords();
    } catch(const char* err) {
        std::cerr<<"Caught exception : " << err << std::endl;
    }

    return 0;
}
