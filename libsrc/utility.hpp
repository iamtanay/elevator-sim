#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> split(const std::string& inputString, char delimiter)
{
    std::vector<std::string> outputVectorOfStrings;
    std::string token;
    std::istringstream tokenStream(inputString);
    while (std::getline(tokenStream, token, delimiter))
    {
        outputVectorOfStrings.push_back(token);
    }
    return outputVectorOfStrings;
}