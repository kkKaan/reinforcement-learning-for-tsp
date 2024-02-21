#include "../headers/Helpers.h"

std::vector<int> findAvailableNeighbors(std::vector<std::vector<int>>& distanceMatrix, int x, int y, int currentLocation, std::vector<int> isVisited)
{
    std::vector<int> availableNeighbors;

    for (int i = 0; i < distanceMatrix.size(); ++i)
    {
        if ((distanceMatrix[currentLocation][i] < x + y) && (distanceMatrix[currentLocation][i] > x - y) && (i != currentLocation) && (isVisited[i] == 0))
        {
            availableNeighbors.push_back(i);
        }
    }
    return availableNeighbors;
}