#include "Record.hpp"
#include "utility.hpp"

namespace Elevator {

    Record::Record(std::string recordString) {

        std::cout<<"Record  :"<<recordString<<std::endl;
        std::vector<std::string> recordValues = split(recordString,',');
        InputReader* inputReaderInstance = InputReader::getInstance();
        std::vector<std::string> recordKeys = inputReaderInstance->getTemplateKeys();
    }

}
