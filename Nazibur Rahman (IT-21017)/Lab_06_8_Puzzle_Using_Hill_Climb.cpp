#include <bits/stdc++.h>
using namespace std;

using Board = vector<vector<int>>;

const Board GOAL = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

map<int, pair<int, int>> goalPos;

void goalMap() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            goalPos[GOAL[i][j]] = {i, j};
}

int calculateManhattan(const Board &b) {
    int dist = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = b[i][j];
            if (val != 0)
                dist += abs(i - goalPos[val].first) + abs(j - goalPos[val].second);
        }
    }
    return dist;
}

pair<int, int> findBlank(const Board &b) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] == 0)
                return {i, j};
    return {-1, -1};
}

void solve8PuzzleHillClimbing(Board start) {
    Board current = start;
    int currentH = calculateManhattan(current);
    int cost = 0; // number of moves taken

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (true) {
        if (current == GOAL) {
            cout << "Goal reached using Hill Climbing. Cost = "
                 << cost << " moves." << endl;
            return;
        }

        auto [x, y] = findBlank(current);

        Board bestNeighbor = current;
        int bestH = currentH;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                Board next = current;
                swap(next[x][y], next[nx][ny]);

                int h = calculateManhattan(next);
                if (h < bestH) {
                    bestH = h;
                    bestNeighbor = next;
                }
            }
        }

        if (bestH >= currentH) {
            cout << "Stopped at local minimum. Goal not reached. Cost = "
                 << cost << " moves." << endl;
            return;
        }

        current = bestNeighbor;
        currentH = bestH;
        cost++; // one move taken
    }
}

int main() {
    Board start = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    goalMap();

    cout << "Starting 8-Puzzle Solver using Hill Climbing..." << endl;
    solve8PuzzleHillClimbing(start);

    return 0;
}
