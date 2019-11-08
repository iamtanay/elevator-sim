#ifndef RECORD_HPP
#define RECORD_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "InputReader.hpp"


namespace Elevator {

    /**
     * @brief Class for managing particular record of CSV file.
     *
     * @details
     *  This class will create a data structure for a particular
     *  record.
     **/
    class Record {

        public:

            Record(std::string recordString);

        private:

            std::vector<std::map<std::string,std::string>> recordMap;

            friend class InputReader;

    };
}
#endif
