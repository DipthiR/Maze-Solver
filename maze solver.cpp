#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string YELLOW = "\033[33m";
const string MAGENTA = "\033[35m";
const string WHITE_BG = "\033[47m";
const string BLACK_BG = "\033[40m";

struct Point {
    int x, y;
};

bool isValid(int x, int y, int rows, int cols, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && y >= 0 && x < rows && y < cols && maze[x][y] == 0 && !visited[x][y]);
}

void printMazeWithPath(const vector<vector<int>>& maze, const vector<Point>& path, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();

    // Create a 2D char array for printing
    vector<vector<char>> display(rows, vector<char>(cols, ' '));

    // Mark walls and paths
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            display[i][j] = (maze[i][j] == 1) ? '#' : ' ';
        }
    }

    // Mark the solution path (except start and end)
    for (const auto& p : path) {
        if (!((p.x == start.x && p.y == start.y) || (p.x == end.x && p.y == end.y)))
            display[p.x][p.y] = '*';
    }

    cout << endl << "Maze Solution:" << endl;
    cout << "Legend: " 
         << RED << "#" << RESET << " Wall  "
         << CYAN << "S" << RESET << " Start  "
         << MAGENTA << "E" << RESET << " End  "
         << GREEN << "*" << RESET << " Path\n\n";

    // Print top border
    cout << "  ";
    for (int c = 0; c < cols; c++) cout << YELLOW << "==";
    cout << RESET << endl;

    for (int i = 0; i < rows; i++) {
        cout << YELLOW << "||" << RESET;  // left border
        for (int j = 0; j < cols; j++) {
            if (i == start.x && j == start.y)
                cout << CYAN << "S " << RESET;
            else if (i == end.x && j == end.y)
                cout << MAGENTA << "E " << RESET;
            else if (display[i][j] == '#')
                cout << RED << "# " << RESET;
            else if (display[i][j] == '*')
                cout << GREEN << "* " << RESET;
            else
                cout << "  ";
        }
        cout << YELLOW << "||" << RESET << endl; // right border
    }

    // Print bottom border
    cout << "  ";
    for (int c = 0; c < cols; c++) cout << YELLOW << "==";
    cout << RESET << endl;
}

void bfsSolveMaze(vector<vector<int>>& maze, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Point>> parent(rows, vector<Point>(cols, {-1, -1}));

    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    bool found = false;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == end.x && current.y == end.y) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, rows, cols, maze, visited)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
                parent[newX][newY] = current;
            }
        }
    }

    if (!found) {
        cout << RED << "No path found from start to end!" << RESET << endl;
        return;
    }

    // Reconstruct path
    vector<Point> path;
    Point p = end;
    while (!(p.x == start.x && p.y == start.y)) {
        path.push_back(p);
        p = parent[p.x][p.y];
    }
    path.push_back(start);

    // Reverse path to start->end
    reverse(path.begin(), path.end());

    // Print maze with path
    printMazeWithPath(maze, path, start, end);
}

int main() {
    vector<vector<int>> maze = {
        {1,1,1,1,1,1,1},
        {1,0,0,0,1,0,1},
        {1,0,1,0,1,0,1},
        {1,0,1,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
    };

    Point start = {1,1};
    Point end = {5,5};

    bfsSolveMaze(maze, start, end);

    return 0;
}
