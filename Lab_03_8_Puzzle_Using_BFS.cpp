#include <bits/stdc++.h>  
using namespace std;  

using Board = vector<vector<int>>;  

const Board GOAL = {  
    {1, 2, 3},  
    {4, 5, 6},  
    {7, 8, 0}  
};  

pair<int, int> findBlank(const Board &b) {  
    for (int i = 0; i < 3; i++)  
        for (int j = 0; j < 3; j++)  
            if (b[i][j] == 0)  
                return {i, j};  
    return {-1, -1};  
}  

void solve8PuzzleBFS(Board start) {  
    queue<Board> q;  
    map<Board, int> dist;  

    q.push(start);  
    dist[start] = 0;  

    int dx[] = {1, -1, 0, 0};  
    int dy[] = {0, 0, 1, -1};  

    while (!q.empty()) {  
        Board current = q.front();  
        q.pop();  

        int currentDist = dist[current];  

        if (current == GOAL) {  
            cout << "Goal reached in " << currentDist << " moves" << endl;  
            return;  
        }  

        auto [x, y] = findBlank(current);  

        for (int i = 0; i < 4; i++) {  
            int nx = x + dx[i];  
            int ny = y + dy[i];  

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {  
                Board next = current;  
                swap(next[x][y], next[nx][ny]);  

                if (dist.find(next) == dist.end()) {  
                    dist[next] = currentDist + 1;  
                    q.push(next);  
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

    cout << "Starting 8-Puzzle Solver using BFS..." << endl;  
    solve8PuzzleBFS(start);  

    return 0;  
}
