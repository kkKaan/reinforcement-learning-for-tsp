#include "../headers/ReadFile.h"
#include "../headers/Traveller.h"
#include "../headers/Helpers.h"

using namespace std;

int main()
{
    vector<vector<int>> data;
    myReadFile(data);
    RL(data);

    return 0;
}
