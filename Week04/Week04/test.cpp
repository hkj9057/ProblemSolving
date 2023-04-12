#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

// Node ����ü ����
struct Node {
    int x, y;
    Node* parent;
};

// �̵� ����
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// �ִ� �Ÿ��� ���ϴ� �Լ�
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
            // �������� ���������� �Ÿ��� ��ȯ
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

        // �̵� ������ ��� ���⿡ ���� Ž��
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

    // ������ �� ���� ���
    for (int i = 0; i < n; i++) {
        delete[] visited[i];
    }
    delete[] visited;

    return -1;
}

// �׸��� �ʰ� ��θ� ����ϴ� �Լ�
void printPath(Node* start, Node* end, int** grid, int n) {
    // ��� ����� ���� ��θ� �����ϴ� ���� ����
    vector<Node*> path;

    // ���������� ���������� �̵��ϸ� ��θ� ����
    Node* current = end;
    while (current != nullptr) {
        path.push_back(current);
        current = current->parent;
    }

    //// ��� ���
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
    // �׸��� �� ���
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
    srand((unsigned int)time(NULL)); // �õ尪 ����

    int startX, startY, endX, endY;
    cout << "�������� ��ǥ�� �Է��ϼ���. ex) 1 1" << endl;
    cin >> startX >> startY;
    cout << "�������� ��ǥ�� �Է��ϼ���. ex) 6 6" << endl;
    cin >> endX >> endY;
    const int n = 10;
    int** grid = new int* [n];
    for (int i = 0; i < n; i++) {
        grid[i] = new int[n]();
    }

    // ��ֹ� ����
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

    // �����Ҵ��� �޸� ����
    for (int i = 0; i < n; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    delete start;
    delete end;

    return 0;
}

