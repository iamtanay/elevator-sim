#ifndef RECORD_HPP
#define RECORD_HPP

#include <iostream>
#include <string>
#include <map>
#include "spdlog/spdlog.h"
#include "utility.hpp"


namespace Elevator {

    class InputReader;
    /**
     * @brief Class for managing particular record of CSV file.
     *
     * @details
     *  This class will create a data structure for a particular
     *  record.
     **/
    class Record {

        public:

            Record(std::string recordString,std::vector<std::string> templateKeys);

        private:

            std::map<std::string,std::string> recordMap;
            
            friend class InputReader;

    };
}
#endif
