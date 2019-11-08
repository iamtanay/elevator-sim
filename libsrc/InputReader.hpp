#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <iostream>
#include <string>
#include "Record.hpp"


namespace Elevator {

    /**
     * @brief Class for reading input file for simulation.
     *
     * @details
     *  This class will create a data structure for handling,
     *  and managing the input to the simulation.
     **/
    class InputRecords {

        public:

            InputRecords(std::string inputFileName);

            static std::vector<std::string> getKeysInTemplate();

        private:

            void readRecordsFromFile();

            std::string mInputFileName;

            std::vector<Record> mInputRecords;

            std::vector<std::string> mTemplateKeys;

    };
}
#endif
