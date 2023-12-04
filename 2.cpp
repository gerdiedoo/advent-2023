#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to check if a game is possible based on cube configurations
bool isGamePossible(const std::string& gameRecord, int redCubes, int greenCubes, int blueCubes) {
    std::istringstream ss(gameRecord);
    std::string subset;

    int redCount = 0, greenCount = 0, blueCount = 0;

    while (getline(ss, subset, ';')) {
        std::istringstream subsetStream(subset);
        char cubeColor;
        int cubeCount;

        while (subsetStream >> cubeCount >> cubeColor) {
            cout << cubeCount << endl;
            cout << cubeColor << endl;
            switch (cubeColor) {
                case 'r':
                    redCount += cubeCount;
                    break;
                case 'g':
                    greenCount += cubeCount;
                    break;
                case 'b':
                    blueCount += cubeCount;
                    break;
                default:
                    // Handle invalid input
                    break;
            }
        }
    }

    return redCount <= redCubes && greenCount <= greenCubes && blueCount <= blueCubes;
}

// Function to find possible games based on cube configurations
std::vector<int> findPossibleGames(const std::vector<std::string>& gameRecords, int redCubes, int greenCubes, int blueCubes) {
    std::vector<int> possibleGames;

    for (int i = 0; i < gameRecords.size(); ++i) {
        if (isGamePossible(gameRecords[i], redCubes, greenCubes, blueCubes)) {
            possibleGames.push_back(i + 1); // Add 1 to convert from zero-based index to game ID
        }
    }

    return possibleGames;
}

int main() {
    // Example game records
    std::vector<std::string> gameRecords = {
        "3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
        // "1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
        // "8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
        // "1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
        // "6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"
    };

    // Cube configurations
    int redCubes = 12;
    int greenCubes = 13;
    int blueCubes = 14;

    // Find possible games
    std::vector<int> possibleGames = findPossibleGames(gameRecords, redCubes, greenCubes, blueCubes);

    // Print results
    std::cout << "Possible games: ";
    for (int gameId : possibleGames) {
        std::cout << "Game " << gameId << " ";
    }
    std::cout << std::endl;

    return 0;
}
