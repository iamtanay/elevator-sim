#include <Elevator/utility.hpp>
#include <Elevator/Elevator.hpp>
#include <Elevator/TripManager.hpp>
#include <Elevator/Floor.hpp>
#include <Elevator/Record.hpp>
#include <Elevator/InputReader.hpp>
#include "spdlog/sinks/basic_file_sink.h"

using namespace Elevator;

int main() {

    try {
        auto logger = spdlog::basic_logger_mt("Elevator", "Logs/Simulation_"+dateTime()+".log");
        spdlog::set_default_logger(logger);
        spdlog::info("Logger Object Initialised");
        spdlog::info("Starting Simulation");
        
        int numberOfFloors;
        std::cout<<"Enter number of floors in the building: ";
        std::cin>>numberOfFloors;
        spdlog::info("Number of floors entered : {}",numberOfFloors);

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
