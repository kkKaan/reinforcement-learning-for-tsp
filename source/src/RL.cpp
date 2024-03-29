#include "../headers/Helpers.h"   
#include "../headers/Traveller.h"

#define NUM_CITIES 81 // Define the number of cities

// Define various parameters for the reinforcement learning algorithm
uint32_t num_episodes = 150000;
uint8_t max_steps_per_episode = 81;
uint16_t X = 240;
uint16_t Y = 70;

double learning_rate = 0.1;
double discount_factor = 0.2;
double exploration_rate = 1.0;
double max_exploration_rate = 1.0;
double min_exploration_rate = 0.01;
double exploration_decay_rate = 0.01;

// Initialize the Q-table with all zeros
std::vector<std::vector<double>> qTable(NUM_CITIES, std::vector<double>(NUM_CITIES, 0.0));

// Function to select an action (city) based on the current state and available options
int selectAction(int state, std::vector<int> possibleStates)
{
    if (possibleStates.empty()) return -1; // If no available actions, return -1

    // Exploration-exploitation trade-off
    if (rand() / static_cast<double>(RAND_MAX) < exploration_rate)
    {
        // Exploration: choose a random action (city)
        int randIndex = rand() % possibleStates.size();
        return possibleStates[randIndex];
    }
    else
    {
        // Exploitation: choose the action (city) with the highest Q-value
        int bestAction = -1;
        double bestQValue = -1.0;
        for (int action = 0; action < possibleStates.size(); ++action)
        {
            if (action != state && qTable[state][possibleStates[action]] > bestQValue)
            {
                bestAction = possibleStates[action];
                bestQValue = qTable[state][possibleStates[action]];
            }
        }
        return bestAction;
    }
}

// Function to update the Q-table based on the Q-learning algorithm
void updateQTable(int state, int action, double reward, int nextState)
{
    double maxNextQValue = 0.0;
    for (int a = 0; a < NUM_CITIES; ++a)
    {
        if (a != nextState && qTable[nextState][a] > maxNextQValue)
        {
            maxNextQValue = qTable[nextState][a];
        }
    }
    // Update the Q-value for the current state-action pair
    qTable[state][action] += learning_rate * (reward + discount_factor * maxNextQValue - qTable[state][action]);
}

// Function to calculate the total distance of a path through cities
int calculateTotalDistance(std::vector<int> path, std::vector<std::vector<int>> distanceMatrix)
{
    int dist = 0;
    for (int i = 0; i < path.size() - 1; ++i)
    {
        dist += distanceMatrix[path[i]][path[i + 1]]; // Sum up distances between consecutive cities
    }
    return dist;
}

// Function to implement the Q-learning-like algorithm
void RL(std::vector<std::vector<int>> distanceMatrix)
{
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    double maxReward = 0;
    int maxCityCount = 0;
    std::vector<int> maxPath;

    // Loop over episodes
    for (int episode = 0; episode < num_episodes; ++episode)
    {
        std::vector<int> isVisited(NUM_CITIES, 0); // Keep track of visited cities
        std::vector<int> path;

        int currentState = 5; // Start from Ankara
        int nextState = -1;
        int cityCount = 1;
        double reward = 1.0;

        double totalReward = 0.0;
        // Loop over steps within an episode
        for (int step = 0; step < NUM_CITIES; ++step)
        {
            isVisited[currentState] = 1;
            path.push_back(currentState);
            std::vector<int> available = findAvailableNeighbors(distanceMatrix, X, Y, currentState, isVisited);
            int action = selectAction(currentState, available);
            if (action == -1) break; // Cannot continue anymore

            // Simulate a reward (e.g., +1 for visiting a city)
            reward++;
            totalReward += reward;
            cityCount++;

            // Choose the next state (city)
            nextState = action;

            // Update the Q-table
            updateQTable(currentState, action, reward, nextState);

            currentState = nextState;
        }

        // Update exploration rate
        exploration_rate = min_exploration_rate + (max_exploration_rate - min_exploration_rate) * std::exp(-exploration_decay_rate * episode);

        // Track maximum reward and path
        maxReward = std::max(maxReward, totalReward);
        if (cityCount > maxCityCount)
        {
            maxCityCount = cityCount;
            maxPath = path;
            if (maxCityCount == NUM_CITIES)
            {
                break; // Terminate if all cities are visited
            }
        }
    }

    // Output results
    std::cout << std::endl;
    std::cout << "Maximum reward: " << maxReward << std::endl;
    std::cout << "Maximum # of visited cities: " << maxCityCount << std::endl;
    std::cout << "Total distance travelled: " << calculateTotalDistance(maxPath, distanceMatrix) << std::endl;

    for (int i = 0; i < maxPath.size(); ++i)
    {
        if (i % 8 == 0) std::cout << std::endl; // Print a new line after every 8 cities
        std::cout << maxPath[i] << " --> ";
    }

    // Print the Q-table (commented out)
    // std::cout << "Q-Table:" << std::endl;
    // for (int i = 0; i < NUM_CITIES; ++i)
    // {
    //    for (int j = 0; j < NUM_CITIES; ++j)
    //    {
    //        std::cout << qTable[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    // }
}
