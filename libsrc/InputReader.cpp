#include "InputReader.hpp"

namespace Elevator {

    InputReader* InputReader::mInstance = 0;

    InputReader* InputReader::getInstance(std::string inputFileName,int numberOfFloors) {

        if(mInstance == 0) {

            mInstance = new InputReader(inputFileName,numberOfFloors);
        }
        return mInstance;
    }

    InputReader::InputReader(std::string inputFileName, int numberOfFloors) {

        std::ifstream inputfile(inputFileName);
        if (inputfile.good()) {

            this->mInputFileName = inputFileName;
            this->mNumberOfFloors = numberOfFloors;
            std::string templateKeys;
            std::getline(inputfile, templateKeys);
            this->mTemplateKeyString = templateKeys;
            spdlog::info("{} ______ Template Keys : {}", __PRETTY_FUNCTION__,this->mTemplateKeyString);
            this->mTemplateKeys = split(templateKeys,',');

            this->readRecordsFromFile();
            this->inputValidation();
            this->mValidInput = true;
        } else {
            spdlog::error("Input File Not Found");
            throw "Input File Not Found";
        }
    }

    void InputReader::readRecordsFromFile() {
        std::ifstream inputfile(this->mInputFileName);
        if (inputfile.good()) {

            spdlog::info("Reading records from input file");
            while(!inputfile.eof()) {

                std::string inputRecord;
                std::getline(inputfile, inputRecord);
                if(inputRecord != this->mTemplateKeyString && inputRecord.find(",") != std::string::npos){
                    Record record(inputRecord,this->mTemplateKeys);
                    this->mInputRecords.push_back(record);
                }
            }

        } else {
            spdlog::error("Input File Not Found");
            throw "Input File Not Found";
        }

    }

    std::vector<Record> InputReader::getInputRecords() {
        if(this->mValidInput)
            return this->mInputRecords;
    }

    bool InputReader::compareCallTimes(Record record1, Record record2) {

        int timeOfCall1 = stoi(record1.recordMap.find("TimeOfCall")->second);
        int timeOfCall2 = stoi(record2.recordMap.find("TimeOfCall")->second);
        return (timeOfCall1 < timeOfCall2);
    }

    bool InputReader::checkFloorNumbers() {
        for(int iter = 0; iter < this->mInputRecords.size(); iter++) {
            int sourceFloor = stoi(this->mInputRecords[iter].recordMap.find("SourceFloor")->second);
            int destinationFloor = stoi(this->mInputRecords[iter].recordMap.find("DestinationFloor")->second);

            if( sourceFloor      > this->mNumberOfFloors - 1 || 
                destinationFloor > this->mNumberOfFloors - 1 ||
                sourceFloor      < 0                         ||
                destinationFloor < 0) {

                spdlog::error("Invalid Floor combination: {},{}",sourceFloor,destinationFloor);
                return false;
            }
        }
        return true;
    }

    bool InputReader::inputValidation() {
        //Sorting records on the basis of Time of Call
        spdlog::info("Sorting the records on the basis of time of call");
        std::sort(this->mInputRecords.begin(), this->mInputRecords.end(), this->compareCallTimes);
        //Checking if Floor Numbers are valid
        if(!checkFloorNumbers()) {
            spdlog::error("Floor Number input is not correct");
            spdlog::error("Input Validation Failed");
            throw "Input Validation Failed";
        }
        return true;
    }

}
