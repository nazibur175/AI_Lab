#include <bits/stdc++.h>
using namespace std;

using Board = vector<vector<int>>;
using State = pair<int, Board>; // (heuristic, board)

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

void solve8PuzzleBestFS(Board start) {
    priority_queue<State, vector<State>, greater<State>> pq;
    set<Board> visited;

    pq.push({calculateManhattan(start), start});
    visited.insert(start);

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        Board board = current.second;

        if (board == GOAL) {
            cout << "Goal reached using Best First Search." << endl;
            return;
        }

        auto [x, y] = findBlank(board);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                Board next = board;
                swap(next[x][y], next[nx][ny]);

                if (!visited.count(next)) {
                    visited.insert(next);
                    int h = calculateManhattan(next);
                    pq.push({h, next});
                }
            }
        }
    }

    cout << "Unsolvable puzzle." << endl;
}

int main() {
    Board start = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    goalMap();

    cout << "Starting 8-Puzzle Solver using Best First Search..." << endl;
    solve8PuzzleBestFS(start);

    return 0;
}
