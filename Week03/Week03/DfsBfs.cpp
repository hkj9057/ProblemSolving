#include <iostream>
#include <queue> // 큐(Queue)를 사용하기 위한 헤더 파일

// 이진 트리의 노드 클래스
class Node {
public:
    int data; // 데이터
    Node* left; // 왼쪽 자식 노드 포인터
    Node* right; // 오른쪽 자식 노드 포인터

    // 생성자 함수
    Node(int value) {
        data = value; // 데이터 초기화
        left = nullptr; // 왼쪽 자식 노드 초기화
        right = nullptr; // 오른쪽 자식 노드 초기화
    }
};

// 이진 트리 클래스
class BinaryTree {
public:
    Node* root; // 루트 노드 포인터

    // 생성자 함수
    BinaryTree() {
        root = nullptr; // 루트 노드 초기화
    }

    // 이진 트리에 노드를 삽입하는 함수
    void insert(int value) {
        Node* newNode = new Node(value); // 새 노드 생성

        // 트리가 비어있는 경우
        if (root == nullptr) {
            root = newNode; // 루트 노드에 새 노드 삽입
            return;
        }

        Node* currentNode = root; // 현재 노드를 루트 노드로 설정

        while (true) {
            // 삽입할 값이 현재 노드보다 작은 경우
            if (value < currentNode->data) {
                // 현재 노드의 왼쪽 자식 노드가 비어있는 경우
                if (currentNode->left == nullptr) {
                    currentNode->left = newNode; // 왼쪽 자식 노드에 새 노드 삽입
                    break;
                }
                currentNode = currentNode->left; // 현재 노드를 왼쪽 자식 노드로 변경
            }
            // 삽입할 값이 현재 노드보다 큰 경우
            else {
                // 현재 노드의 오른쪽 자식 노드가 비어있는 경우
                if (currentNode->right == nullptr) {
                    currentNode->right = newNode; // 오른쪽 자식 노드에 새 노드 삽입
                    break;
                }
                currentNode = currentNode->right; // 현재 노드를 오른쪽 자식 노드로 변경
            }
        }
    }
    // BFS(Breadth-First Search) 알고리즘을 구현한 함수
    void traverseBFS() {
        if (root == nullptr) {
            return; // 트리가 비어있는 경우 함수 종료
        }

        std::queue<Node*> q; // 큐 생성 및 루트 노드 삽입
        q.push(root);

        while (!q.empty()) { // 큐가 비어있을 때까지 반복
            Node* currentNode = q.front(); // 큐의 맨 앞에 있는 노드를 현재 노드로 설정
            q.pop(); // 큐에서 현재 노드를 제거
            std::cout << currentNode->data << " "; // 현재 노드의 데이터를 출력

            if (currentNode->left != nullptr) { // 현재 노드의 왼쪽 자식 노드가 있는 경우
                q.push(currentNode->left); // 왼쪽 자식 노드를 큐에 삽입
            }

            if (currentNode->right != nullptr) { // 현재 노드의 오른쪽 자식 노드가 있는 경우
                q.push(currentNode->right); // 오른쪽 자식 노드를 큐에 삽입
            }
        }
    }
    // DFS(Depth-First Search) 알고리즘을 구현한 함수
    void traverseDFS(Node* currentNode) {
        if (currentNode == nullptr) {
            return; // 현재 노드가 nullptr인 경우 함수 종료
        }

        std::cout << currentNode->data << " "; // 현재 노드의 데이터를 출력

        traverseDFS(currentNode->left); // 현재 노드의 왼쪽 자식 노드를 방문
        traverseDFS(currentNode->right); // 현재 노드의 오른쪽 자식 노드를 방문
    }

};

int main() {
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(9);
    tree.insert(6);

    std::cout << "BFS: ";
    tree.traverseBFS(); // prints "5 3 7 1 6 9"

    std::cout << "\nDFS: ";
    tree.traverseDFS(tree.root); // prints "5 3 1 7 6 9"

    return 0;
}