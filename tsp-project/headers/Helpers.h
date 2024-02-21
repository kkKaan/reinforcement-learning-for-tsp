#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdint>

std::vector<int> findAvailableNeighbors(std::vector<std::vector<int>>& distanceMatrix, int x, int y, int currentLocation, std::vector<int> isVisited);

#endif // !HELPERS_H