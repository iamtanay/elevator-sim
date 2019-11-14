#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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

            std::vector<Record> getInputRecords();

            static bool compareCallTimes(Record record1, Record record2);
            
            static InputReader* getInstance(std::string inputFileName="",int numberOfFloors=0);

        private:

            InputReader(std::string inputFileName,int numberOfFloors);
            
            bool inputValidation();

            bool checkFloorNumbers(); 
            
            void readRecordsFromFile();

            static InputReader* mInstance;

            std::string mInputFileName;
            
            int mNumberOfFloors;

            std::string mTemplateKeyString;

            std::vector<Record> mInputRecords;

            std::vector<std::string> mTemplateKeys;

            bool mValidInput = false;

    };
}
#endif
