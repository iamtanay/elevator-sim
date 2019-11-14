#include "Record.hpp"

namespace Elevator {

    Record::Record(std::string recordString,std::vector<std::string> templateKeys) {

        std::vector<std::string> recordValues = split(recordString,',');

        for(int iter = 0; iter < templateKeys.size(); iter++) {
            this->recordMap.insert({templateKeys[iter],recordValues[iter]});
        }
        spdlog::info("Record object created : {}", recordString);
    }

} 
