#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair
#include <set>
#include <map>    // for std::map
#include <algorithm> // for std::reverse

using namespace std;

// Define the maze as a grid
const vector<string> maze = {
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛😀⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🟧⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🟦⬛",
    "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
};

// Directions for moving in the maze (up, down, left, right)
const vector<pair<int, int>> directions = {
    {-1, 0}, // Up
    {1, 0},  // Down
    {0, -1}, // Left
    {0, 1}   // Right
};

// Function to perform BFS and find the path to the goal
vector<pair<int, int>> bfs(pair<int, int> start, pair<int, int> goal) {
    queue<pair<int, int>> q;
    set<pair<int , int>> visited;
    map<pair<int, int>, pair<int, int>> parent; // To reconstruct the path

    q.push(start);
    visited.insert(start);
    parent[start] = {-1, -1}; // Mark the start position's parent as invalid

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        // Check if we reached the goal
        if (current == goal) {
            vector<pair<int, int>> path;
            for (auto step = current; step != make_pair(-1, -1); step = parent[step]) {
                path.push_back(step);
            }
            reverse(path.begin(), path.end()); // Reverse the path to get it from start to goal
            return path;
        }

        // Explore neighbors
        for (const auto& dir : directions) {
            int newRow = current.first + dir.first;
            int newCol = current.second + dir.second;
            pair<int, int> neighbor = {newRow, newCol};

            // Check if the new position is valid
            if (newRow >= 0 && newRow < maze.size() && newCol >= 0 && newCol < maze[0].size() &&
                maze[newRow][newCol] != "⬛" && visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current; // Record the parent
            }
        }
    }

    return {}; // Return an empty path if the goal is not reachable
}

int main() {
    pair<int, int> start = {1, 1}; // Starting position (😀)
    pair<int, int> orangeGoal = {1, 17}; // Orange square (🟧)
    pair<int, int> blueGoal = {15, 17}; // Blue square (🟦)

    // Find path to orange square
    vector<pair<int, int>> pathToOrange = bfs(start, orangeGoal);
    cout << "Path to Orange Square: ";
    for (const auto& pos : pathToOrange) {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;

    // Find path to blue square
    vector<pair<int, int>> pathToBlue = bfs(start, blueGoal);
    cout << "Path to Blue Square: ";
    for (const auto& pos : pathToBlue) {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;

    return 0;
}