#include "../headers/Traveller.h"
#include "../headers/Helpers.h"

// An old version of the TSP problem solver using greedy approach
void traveller(std::vector<std::vector<int>>& distanceMatrix, int& x, int& y, int& travelled, int startingLocation, int& travelled_distance)
{
    int maxCitiesVisited = 0;
    int optimalX = 0;
    int optimalY = 0;
    int final_distance = 0;

    // Iterate over different values of X and Y
    for (int X = 150; X <= 300; X += 1)
    {
        for (int Y = 15; Y <= 50; Y += 1)
        {
            int distance = 0;
            int citiesVisited = 0;
            int current_city = startingLocation;
            std::vector<int> isVisited(81, 0);
            isVisited[current_city] = 1;
            citiesVisited++;

            std::vector<int> neighbors = findAvailableNeighbors(distanceMatrix, X, Y, current_city, isVisited);

            // while there are available neighbors
            while (neighbors.size() > 0)
            {
                int maxSecN = 0;
                int maxSecNIndex = 0;

                // iterate over the available neighbors
                for (int i = 0; i < neighbors.size(); ++i)
                {
                    std::vector<int> secNeighbors = findAvailableNeighbors(distanceMatrix, X, Y, neighbors[i], isVisited);

                    // consider the neighbors of neighbors
                    int totalSecNeighbors = secNeighbors.size();
                    int totalThNeighbors = 0;
                    int maxThNeighbors = 0;
                    for (int j = 0; j < secNeighbors.size(); ++j)
                    {
                        totalThNeighbors = findAvailableNeighbors(distanceMatrix, X, Y, secNeighbors[j], isVisited).size();

                        if (totalThNeighbors > maxThNeighbors)
                        {
                            maxThNeighbors = totalThNeighbors;
                        }
                    }

                    if (totalSecNeighbors + maxThNeighbors > maxSecN)
                    {
                        maxSecN = totalSecNeighbors + maxThNeighbors;
                        maxSecNIndex = i;
                    }
                }

                // move to the neighbor with the most neighbors            
                if (current_city == neighbors[maxSecNIndex]) break;
                distance += distanceMatrix[current_city][neighbors[maxSecNIndex]];
                current_city = neighbors[maxSecNIndex];
                isVisited[current_city] = 1;
                citiesVisited++;

                // find the available neighbors of the new current city
                neighbors = findAvailableNeighbors(distanceMatrix, X, Y, current_city, isVisited);
            }

            citiesVisited += neighbors.size();
            for (int i = 0; i < neighbors.size(); ++i)
            {
                distance += distanceMatrix[current_city][neighbors[i]];
            }
            // update optimal values if more cities can be visited
            if (citiesVisited > maxCitiesVisited)
            {
                maxCitiesVisited = citiesVisited;
                optimalX = X;
                optimalY = Y;
                final_distance = distance;
            }
        }
    }

    x = optimalX;
    y = optimalY;
    travelled = maxCitiesVisited;
    travelled_distance = final_distance;
}
