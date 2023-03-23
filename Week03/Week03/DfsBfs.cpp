#include <iostream>
#include <queue> // ť(Queue)�� ����ϱ� ���� ��� ����

// ���� Ʈ���� ��� Ŭ����
class Node {
public:
    int data; // ������
    Node* left; // ���� �ڽ� ��� ������
    Node* right; // ������ �ڽ� ��� ������

    // ������ �Լ�
    Node(int value) {
        data = value; // ������ �ʱ�ȭ
        left = nullptr; // ���� �ڽ� ��� �ʱ�ȭ
        right = nullptr; // ������ �ڽ� ��� �ʱ�ȭ
    }
};

// ���� Ʈ�� Ŭ����
class BinaryTree {
public:
    Node* root; // ��Ʈ ��� ������

    // ������ �Լ�
    BinaryTree() {
        root = nullptr; // ��Ʈ ��� �ʱ�ȭ
    }

    // ���� Ʈ���� ��带 �����ϴ� �Լ�
    void insert(int value) {
        Node* newNode = new Node(value); // �� ��� ����

        // Ʈ���� ����ִ� ���
        if (root == nullptr) {
            root = newNode; // ��Ʈ ��忡 �� ��� ����
            return;
        }

        Node* currentNode = root; // ���� ��带 ��Ʈ ���� ����

        while (true) {
            // ������ ���� ���� ��庸�� ���� ���
            if (value < currentNode->data) {
                // ���� ����� ���� �ڽ� ��尡 ����ִ� ���
                if (currentNode->left == nullptr) {
                    currentNode->left = newNode; // ���� �ڽ� ��忡 �� ��� ����
                    break;
                }
                currentNode = currentNode->left; // ���� ��带 ���� �ڽ� ���� ����
            }
            // ������ ���� ���� ��庸�� ū ���
            else {
                // ���� ����� ������ �ڽ� ��尡 ����ִ� ���
                if (currentNode->right == nullptr) {
                    currentNode->right = newNode; // ������ �ڽ� ��忡 �� ��� ����
                    break;
                }
                currentNode = currentNode->right; // ���� ��带 ������ �ڽ� ���� ����
            }
        }
    }
    // BFS(Breadth-First Search) �˰����� ������ �Լ�
    void traverseBFS() {
        if (root == nullptr) {
            return; // Ʈ���� ����ִ� ��� �Լ� ����
        }

        std::queue<Node*> q; // ť ���� �� ��Ʈ ��� ����
        q.push(root);

        while (!q.empty()) { // ť�� ������� ������ �ݺ�
            Node* currentNode = q.front(); // ť�� �� �տ� �ִ� ��带 ���� ���� ����
            q.pop(); // ť���� ���� ��带 ����
            std::cout << currentNode->data << " "; // ���� ����� �����͸� ���

            if (currentNode->left != nullptr) { // ���� ����� ���� �ڽ� ��尡 �ִ� ���
                q.push(currentNode->left); // ���� �ڽ� ��带 ť�� ����
            }

            if (currentNode->right != nullptr) { // ���� ����� ������ �ڽ� ��尡 �ִ� ���
                q.push(currentNode->right); // ������ �ڽ� ��带 ť�� ����
            }
        }
    }
    // DFS(Depth-First Search) �˰����� ������ �Լ�
    void traverseDFS(Node* currentNode) {
        if (currentNode == nullptr) {
            return; // ���� ��尡 nullptr�� ��� �Լ� ����
        }

        std::cout << currentNode->data << " "; // ���� ����� �����͸� ���

        traverseDFS(currentNode->left); // ���� ����� ���� �ڽ� ��带 �湮
        traverseDFS(currentNode->right); // ���� ����� ������ �ڽ� ��带 �湮
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