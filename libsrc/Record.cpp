#include "Record.hpp"
#include "utility.hpp"

namespace Elevator {

    Record::Record(std::string recordString) {

        std::cout<<"Record  :"<<recordString<<std::endl;
        std::vector<std::string> recordValues = split(recordString,',');
    }

}
