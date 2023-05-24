#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

using namespace std;

int main() {
    ifstream file("C:/Users/hkj90/Desktop/test2.txt");
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    string line1, line2;
    string content1, content2;

    // 첫 번째 줄 읽기
    if (getline(file, line1))
        content1 = line1;

    // 두 번째 줄 읽기
    if (getline(file, line2))
        content2 = line2;

    // '%' 뒤에 있는 타입과 해당 문자열 찾기
    regex pattern("%(\\w)");
    smatch match1, match2;

    // 타입별 개수를 위한 맵 초기화
    map<string, int> typeCount;

    // 첫 번째 줄과 두 번째 줄을 비교하여 타입 찾기
    while (regex_search(content1, match1, pattern)) {
        if (regex_search(content2, match2, pattern)) {
            string currentMatch1 = match1[1].str();
            string currentMatch2 = match2[1].str();
            typeCount[currentMatch1]++;

            cout << "윗줄: %" << currentMatch1 << " - ";
            if (currentMatch1 == "s") {
                // 윗줄에서 %s 부분만 출력
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
        regex_search(content1, match1, pattern);  // 다음 타입 검색을 위해 추가
    }

    // 타입별 개수 출력
    for (const auto& pair : typeCount) {
        string type = pair.first;
        int count = pair.second;
        cout << type << " 개수: " << count << endl;
    }

    file.close();
    return 0;
}
