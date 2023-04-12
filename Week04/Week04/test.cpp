#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

// Node 구조체 정의
struct Node {
    int x, y;
    Node* parent;
};

// 이동 방향
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 최단 거리를 구하는 함수
int shortestPath(Node* start, Node* end, int** grid, int n) {
    queue<Node*> q;
    bool** visited = new bool* [n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[n]();
    }

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

            for (int i = 0; i < n; i++) {
                delete[] visited[i];
            }
            delete[] visited;

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
    for (int i = 0; i < n; i++) {
        delete[] visited[i];
    }
    delete[] visited;

    return -1;
}

// 그리드 맵과 경로를 출력하는 함수
void printPath(Node* start, Node* end, int** grid, int n) {
    // 경로 출력을 위해 경로를 저장하는 벡터 생성
    vector<Node*> path;

    // 도착지부터 시작점까지 이동하며 경로를 저장
    Node* current = end;
    while (current != nullptr) {
        path.push_back(current);
        current = current->parent;
    }

    //// 경로 출력
    //for (int i = n - 1; i >= 0; i--) {
    //    for (int j = 0; j < n; j++) {
    //        if (i == start->x && j == start->y) {
    //            cout << "S";
    //        }
    //        else if (i == end->x && j == end->y) {
    //            cout << "E";
    //        }
    //        else if (grid[i][j] == 1) {
    //            cout << "#";
    //        }
    //        else {
    //            bool onPath = false;
    //            for (Node* node : path) {
    //                if (node->x == i && node->y == j) {
    //                    cout << "*";
    //                    onPath = true;
    //                    break;
    //                }
    //            }
    //            if (!onPath) {
    //                cout << ".";
    //            }
    //        }
    //    }
    //    cout << endl;
    //}
    // 그리드 맵 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == start->x && j == start->y) {
                cout << "S";
            }
            else if (i == end->x && j == end->y) {
                cout << "E";
            }
            else if (grid[i][j] == 1) {
                cout << "#";
            }
            else {
                cout << ".";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    srand((unsigned int)time(NULL)); // 시드값 설정

    int startX, startY, endX, endY;
    cout << "시작점의 좌표를 입력하세요. ex) 1 1" << endl;
    cin >> startX >> startY;
    cout << "도착점의 좌표를 입력하세요. ex) 6 6" << endl;
    cin >> endX >> endY;
    const int n = 10;
    int** grid = new int* [n];
    for (int i = 0; i < n; i++) {
        grid[i] = new int[n]();
    }

    // 장애물 생성
    for (int i = 0; i < 5; i++) {
        int x = rand() % n;
        int y = rand() % n;
        if (grid[x][y] == 0) {
            grid[x][y] = 1;
        }
    }

    Node* start = new Node();
    start->x = startX;
    start->y = startY;

    Node* end = new Node();
    end->x = endX;
    end->y = endY;

    printPath(start, end, grid, n);

    cout << "Start: (" << start->x << ", " << start->y << ")" << endl;
    cout << "End: (" << end->x << ", " << end->y << ")" << endl;

    

    int distance = shortestPath(start, end, grid, n);
    if (distance == -1) {
        cout << "Cannot reach the destination." << endl;
    }
    else {
        cout << "Shortest distance: " << distance << endl;
    }

    // 동적할당한 메모리 해제
    for (int i = 0; i < n; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    delete start;
    delete end;

    return 0;
}

