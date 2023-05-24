#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

using namespace std;

int main() {
    ifstream file("C:/Users/hkj90/Desktop/test2.txt");
    if (!file.is_open()) {
        cout << "������ �� �� �����ϴ�." << endl;
        return 1;
    }

    string line1, line2;
    string content1, content2;

    // ù ��° �� �б�
    if (getline(file, line1))
        content1 = line1;

    // �� ��° �� �б�
    if (getline(file, line2))
        content2 = line2;

    // '%' �ڿ� �ִ� Ÿ�԰� �ش� ���ڿ� ã��
    regex pattern("%(\\w)");
    smatch match1, match2;

    // Ÿ�Ժ� ������ ���� �� �ʱ�ȭ
    map<string, int> typeCount;

    // ù ��° �ٰ� �� ��° ���� ���Ͽ� Ÿ�� ã��
    while (regex_search(content1, match1, pattern)) {
        if (regex_search(content2, match2, pattern)) {
            string currentMatch1 = match1[1].str();
            string currentMatch2 = match2[1].str();
            typeCount[currentMatch1]++;

            cout << "����: %" << currentMatch1 << " - ";
            if (currentMatch1 == "s") {
                // ���ٿ��� %s �κи� ���
                size_t startPos = line2.find(match2.str());
                size_t endPos = startPos + match2.length();
                cout << line2.substr(startPos, endPos - startPos) << endl;
            }
            else if (currentMatch1 == "d") {
                cout << stoi(match2.prefix().str()) << endl;
            }
            else if (currentMatch1 == "c") {
                cout << match2.prefix().str().back() << endl;
            }

            content2 = match2.suffix().str();
        }

        content1 = match1.suffix().str();
        regex_search(content1, match1, pattern);  // ���� Ÿ�� �˻��� ���� �߰�
    }

    // Ÿ�Ժ� ���� ���
    for (const auto& pair : typeCount) {
        string type = pair.first;
        int count = pair.second;
        cout << type << " ����: " << count << endl;
    }

    file.close();
    return 0;
}
