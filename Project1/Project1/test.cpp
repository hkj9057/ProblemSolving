#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main() {
    ifstream file("C:/Users/hkj90/Desktop/test.txt");
    string line;
    string content;

    // 메모장 파일 내용 읽기
    while (getline(file, line)) {
        content += line + "\n";
    }

    // int, char, string에 해당하는 패턴 정의
    regex intRegex("\\b\\d+\\b");
    regex charRegex("\\b.\\b");
    regex stringRegex("\\bstring\\b");

    // 각 패턴을 찾아 개수 세기
    int intCount = distance(sregex_iterator(content.begin(), content.end(), intRegex), sregex_iterator());
    int charCount = distance(sregex_iterator(content.begin(), content.end(), charRegex), sregex_iterator());
    int stringCount = distance(sregex_iterator(content.begin(), content.end(), stringRegex), sregex_iterator());

    cout << "int 개수: " << intCount << endl;
    cout << "char 개수: " << charCount << endl;
    cout << "string 개수: " << stringCount << endl;

    file.close();
    return 0;
}
