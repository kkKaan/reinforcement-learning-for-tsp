#ifndef TRAVELLER_H
#define TRAVELLER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdint>

void traveller(std::vector<std::vector<int>>& distanceMatrix, int& x, int& y, int& travelled, int startingLocation, int& travelled_distance);

int selectAction(int state, std::vector<int> possibleStates);
void updateQTable(int state, int action, double reward, int nextState);
int calculateTotalDistance(std::vector<int> path, std::vector<std::vector<int>> distanceMatrix);
void RL(std::vector<std::vector<int>> distanceMatrix);

#endif // !TRAVELLER_H
