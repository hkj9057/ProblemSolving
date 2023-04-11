//#include <iostream>
//#include <queue>
//#include <ctime>
//using namespace std;
//
//// Node ����ü ����
//struct Node {
//    int x, y;
//    Node* parent;
//};
//
//// �׸��� �� ũ��
//const int n = 12;
//
//// �׸��� ��
//int grid[n][n] = {
//    {0,0,0,0,0,0,0,0,0,0},
//    {0,0,1,1,1,0,0,0,0,0},
//    {0,0,0,0,1,0,0,0,0,0},
//    {0,0,0,0,1,0,0,0,0,0},
//    {0,0,0,0,1,0,0,0,0,0},
//    {0,0,0,0,1,0,0,0,0,0},
//    {0,0,0,0,1,0,0,0,0,0},
//    {0,0,0,0,1,0,0,0,0,0},
//    {0,0,0,0,1,0,0,0,0,0},
//    {0,0,0,0,0,0,0,0,0,0}
//};
//
//// �̵� ����
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//// �ִ� �Ÿ��� ���ϴ� �Լ�
//int shortestPath(Node* start, Node* end) {
//    queue<Node*> q;
//    bool visited[n][n] = { false };
//
//    q.push(start);
//    visited[start->x][start->y] = true;
//
//    while (!q.empty()) {
//        Node* current = q.front();
//        q.pop();
//
//        if (current->x == end->x && current->y == end->y) {
//            // �������� ���������� �Ÿ��� ��ȯ
//            int distance = 0;
//            vector<Node*> path;
//            while (current->parent != nullptr) {
//                path.push_back(current);
//                current = current->parent;
//                distance++;
//            }
//            path.push_back(start);
//
//            // ��� ���
//            for (int i = path.size() - 1; i >= 0; i--) {
//                cout << "---";
//            }
//            cout << endl;
//
//            for (int i = path.size() - 1; i >= 0; i--) {
//                cout << "(" << path[i]->x << ", " << path[i]->y << ")";
//                if (i > 0) {
//                    cout << " -> ";
//                }
//            }
//            cout << endl;
//
//            for (int i = path.size() - 1; i >= 0; i--) {
//                cout << "---";
//            }
//            cout << endl;
//
//            return distance;
//        }
//
//        // �̵� ������ ��� ���⿡ ���� Ž��
//        for (int i = 0; i < 4; i++) {
//            int nx = current->x + dx[i];
//            int ny = current->y + dy[i];
//
//            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
//                grid[nx][ny] == 0 && !visited[nx][ny]) {
//                Node* next = new Node();
//                next->x = nx;
//                next->y = ny;
//                next->parent = current;
//                q.push(next);
//                visited[nx][ny] = true;
//            }
//        }
//    }
//
//    // ������ �� ���� ���
//    return -1;
//}
//// �׸��� �ʰ� ��θ� ����ϴ� �Լ�
//void printPath(Node* start, Node* end) {
//    // ��θ� ������ �迭 ����
//    int path[n][n] = { 0 };
//
//    // ���������� �����Ͽ� ��θ� ������
//    Node* current = end;
//    while (current->parent != nullptr) {
//        path[current->x][current->y] = 1;
//        current = current->parent;
//    }
//    path[current->x][current->y] = 1;
//
//    // �� ���
//    for (int i = 0; i < n + 2; i++) {
//        for (int j = 0; j < n + 2; j++) {
//            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
//                cout << "# ";
//            }
//            else if (i == start->x + 1 && j == start->y + 1) {
//                cout << "S ";
//            }
//            else if (i == end->x + 1 && j == end->y + 1) {
//                cout << "E ";
//            }
//            else if (path[i - 1][j - 1] == 1) {
//                cout << "- ";
//            }
//            else {
//                cout << (grid[i - 1][j - 1] ? "# " : "  ");
//            }
//        }
//        cout << endl;
//    }
//}
//
//
//int main() {
//
//    int startX, startY, endX, endY;
//    // �������� ���� ����
//    Node* start = new Node();
//    Node* end = new Node();
//    cout << "�������� ��ǥ�� �Է����ּ���ex) 5 4 : ";
//    cin >> startX >> startY;
//    cout << "�������� ��ǥ�� �Է����ּ���ex) 7 7 : ";
//    cin >> endX >> endY;
//    start->x = startX;
//    start->y = startY;
//    start->parent = nullptr;
//    end->x = endX;
//    end->y = endY;
//    end->parent = nullptr;
//
//    printPath(start, end);
//    // �ִ� �Ÿ� ���ϱ�
//    int distance = shortestPath(start, end);
//
//    if (distance == -1) {
//        cout << "������ �� �����ϴ�." << endl;
//    }
//    else
//    {
//        cout << "�ִ� �Ÿ��� " << distance << "�Դϴ�." << endl;
//    }
//
//    // ���� �Ҵ�� ��� ����
//    delete start;
//    delete end;
//
//    return 0;
//}
