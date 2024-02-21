#include "../headers/ReadFile.h"

void myReadFile(std::vector<std::vector<int>>& data)
{
    // File pointer
    std::fstream myfile("tsp-project/DistancesBetweenCities.csv"); // Change this path to the absolute path of the CSV file
    if (myfile.fail())
    {
        std::cerr << "Error opening CSV file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(myfile, line))
    {
        std::vector<int> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ';'))
        {
            row.push_back(stoi(cell));
        }

        data.push_back(row);
    }
}
