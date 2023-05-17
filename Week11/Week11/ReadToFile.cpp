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
    //regex stringRegex("\\bstring\\b");
    //regex stringRegex("string");
    regex stringRegex("\\b\\w+\\b");

    // �� ������ ã�� ���� ����
    int intCount = distance(sregex_iterator(content.begin(), content.end(), intRegex), sregex_iterator());
    int charCount = distance(sregex_iterator(content.begin(), content.end(), charRegex), sregex_iterator());
    int stringCount = distance(sregex_iterator(content.begin(), content.end(), stringRegex), sregex_iterator());

    /*int stringCount = 0;
    sregex_iterator iter(content.begin(), content.end(), stringRegex);
    sregex_iterator end;
    while (iter != end) {
        string currentMatch = iter->str();
        if (currentMatch == "string") {
            stringCount++;
        }
        ++iter;
    }*/

    printf("int ����: %d \n", intCount);
    printf("char ����: %d \n", charCount);
    printf("string ����: %d \n", stringCount);

    file.close();
    return 0;
}
