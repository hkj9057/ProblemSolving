#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main() {
    ifstream file("C:/Users/hkj90/Desktop/test.txt");
    string line;
    string content;

    // �޸��� ���� ���� �б�
    while (getline(file, line)) {
        content += line + "\n";
    }

    // int, char, string�� �ش��ϴ� ���� ����
    regex intRegex("\\b\\d+\\b");
    regex charRegex("\\b.\\b");
    regex stringRegex("\\bstring\\b");

    // �� ������ ã�� ���� ����
    int intCount = distance(sregex_iterator(content.begin(), content.end(), intRegex), sregex_iterator());
    int charCount = distance(sregex_iterator(content.begin(), content.end(), charRegex), sregex_iterator());
    int stringCount = distance(sregex_iterator(content.begin(), content.end(), stringRegex), sregex_iterator());

    cout << "int ����: " << intCount << endl;
    cout << "char ����: " << charCount << endl;
    cout << "string ����: " << stringCount << endl;

    file.close();
    return 0;
}
