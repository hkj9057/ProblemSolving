#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

// Node 구조체 정의
struct Node {
    int x, y;
    Node* parent;
};

// 그리드 맵 크기
const int n = 12;

// 그리드 맵
int grid[n][n] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

// 이동 방향
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 최단 거리를 구하는 함수
int shortestPath(Node* start, Node* end) {
    queue<Node*> q;
    bool visited[n][n] = { false };

    q.push(start);
    visited[start->x][start->y] = true;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->x == end->x && current->y == end->y) {
            // 목적지에 도달했으면 거리를 반환
            int distance = 0;
            vector<Node*> path;
            while (current->parent != nullptr) {
                path.push_back(current);
                current = current->parent;
                distance++;
            }
            path.push_back(start);

            // 경로 출력
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << "---";
            }
            cout << endl;

            for (int i = path.size() - 1; i >= 0; i--) {
                cout << "(" << path[i]->x << ", " << path[i]->y << ")";
                if (i > 0) {
                    cout << " -> ";
                }
            }
            cout << endl;

            for (int i = path.size() - 1; i >= 0; i--) {
                cout << "---";
            }
            cout << endl;

            return distance;
        }

        // 이동 가능한 모든 방향에 대해 탐색
        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                Node* next = new Node();
                next->x = nx;
                next->y = ny;
                next->parent = current;
                q.push(next);
                visited[nx][ny] = true;
            }
        }
    }
    // 도달할 수 없는 경우
    return -1;
}
// 그리드 맵과 경로를 출력하는 함수
void printPath(Node* start, Node* end) {
    // 경로를 저장할 배열 생성
    int path[n][n] = { 0 };

    // 맵 출력
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
                cout << "# ";
            }
            else if (i == start->x + 1 && j == start->y + 1) {
                cout << "S ";
            }
            else if (i == end->x + 1 && j == end->y + 1) {
                cout << "E ";
            }
            else if (path[i - 1][j - 1] == 1) {
                cout << "- ";
            }
            else {
                cout << (grid[i - 1][j - 1] ? "# " : "  ");
            }
        }
        cout << endl;
    }
}
// 맵 생성
void generate_map(int gridX, int gridY, char**& grid)
{
    grid = new char* [gridY];
    for (int i = 0; i < gridY; i++) {
        grid[i] = new char[gridX];
    }
    // 맵 초기화
    for (int i = 0; i < gridY; i++) {
        for (int j = 0; j < gridX; j++) {
            grid[i][j] = '.';
        }
    }
}
// 랜덤 위치에 벽 추가
void add_wall(int gridX, int gridY, char** grid) 
{
    int wall_x = rand() % gridX;
    int wall_y = rand() % gridY;
    grid[wall_y][wall_x] = '#';
}



int main() {

    int startX, startY, endX, endY, gridX, gridY;
    // 시작점과 끝점 생성
    Node* start = new Node();
    Node* end = new Node();
    char** grid;
    cout << "맵의 크기를 정해주세요ex) (10 10) : ";
    cin >> gridX >> gridY;

    generate_map(gridX, gridY, grid);

    cout << "시작점의 좌표를 입력해주세요ex) 5 4 : ";
    cin >> startX >> startY;
    cout << "도착점의 좌표를 입력해주세요ex) 7 7 : ";
    cin >> endX >> endY;
    start->x = startX;
    start->y = startY;
    start->parent = nullptr;
    end->x = endX;
    end->y = endY;
    end->parent = nullptr;

    printPath(start, end);
    // 최단 거리 구하기
    int distance = shortestPath(start, end);

    if (distance == -1) {
        cout << "도달할 수 없습니다." << endl;
    }
    else
    {
        cout << "최단 거리는 " << distance << "입니다." << endl;
    }

    // 동적 할당된 노드 해제
    delete start;
    delete end;

    return 0;
}
