#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Record.hpp"


namespace Elevator {

    /**
     * @brief Class for reading input file for simulation.
     *
     * @details
     *  This class will create a data structure for handling,
     *  and managing the input to the simulation.
     **/
    class InputReader {

        public:

            std::vector<std::string> getKeysInTemplate();
            
            static InputReader* getInstance(std::string inputFileName="");

        private:

            InputReader(std::string inputFileName);
            
            void readRecordsFromFile();

            static InputReader* mInstance;

            std::string mInputFileName;

            std::string mTemplateKeyString;

            std::vector<Record> mInputRecords;

            std::vector<std::string> mTemplateKeys;

    };
}
#endif
