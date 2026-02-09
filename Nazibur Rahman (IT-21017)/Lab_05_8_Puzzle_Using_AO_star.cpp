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

// state: (f, g, board)
struct State {
    int f, g;
    Board board;
    bool operator>(const State &other) const {
        return f > other.f;
    }
};

void solve8PuzzleAO(Board start) {
    priority_queue<State, vector<State>, greater<State>> pq;
    set<Board> visited;

    int h0 = calculateManhattan(start);
    pq.push({h0, 0, start}); 
    // f = g + h = 0 + h0

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        Board board = current.board;

        if (visited.count(board))
            continue;
        visited.insert(board);

        if (board == GOAL) {
            cout << "Goal reached using AO* Search. Cost = "
                 << current.g << " moves." << endl;
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
                    int gNext = current.g + 1;            
                    int hNext = calculateManhattan(next); 
                    int fNext = gNext + hNext;
                    pq.push({fNext, gNext, next});
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

    cout << "Starting 8-Puzzle Solver using AO* Search..." << endl;
    solve8PuzzleAO(start);

    return 0;
}
