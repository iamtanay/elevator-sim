#include "InputReader.hpp"
#include "utility.hpp"

namespace Elevator {

    InputReader* InputReader::mInstance = 0;

    InputReader* InputReader::getInstance(std::string inputFileName) {

        if(mInstance == 0) {

            mInstance = new InputReader(inputFileName);
        }
        return mInstance;
    }

    InputReader::InputReader(std::string inputFileName) {

        std::ifstream inputfile(inputFileName);
        if (inputfile.good()) {

            this->mInputFileName = inputFileName;
            std::string templateKeys;
            std::getline(inputfile, templateKeys);
            this->mTemplateKeyString = templateKeys;
            std::cout << templateKeys << std::endl;
            this->mTemplateKeys = split(templateKeys,',');

            this->readRecordsFromFile();
        } else {
            std::cerr<<"Input File Not Found"<<std::endl;
        }
    }

    std::vector<std::string> InputReader::getKeysInTemplate() {

        if(this->mInputFileName != "")
            return this->mTemplateKeys;
    }

    void InputReader::readRecordsFromFile() {
        std::ifstream inputfile(this->mInputFileName);
        if (inputfile.good()) {

            while(!inputfile.eof()) {

                std::string inputRecord;
                std::getline(inputfile, inputRecord);
                if(inputRecord != this->mTemplateKeyString) {
                    Record record(inputRecord);
                }
            }

        } else {
            std::cerr<<"Input File Not Found"<<std::endl;
        }

    }

}
