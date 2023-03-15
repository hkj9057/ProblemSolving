#include <iostream>
#include <conio.h> // getch 함수를 사용하기 위해 추가한다
#include <Windows.h>
#include <unordered_map>

using namespace std;

// 로마자를 숫자로 변환하는 함수
int romanToNumber(string roman) {
    // 로마자에 해당하는 값을 저장하는 unordered_map
    unordered_map<char, int> romanNumerals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    for (int i = 0; i < roman.size(); i++) {
        // 로마자가 아닌 문자열이 입력되면 예외 처리한다
        if (romanNumerals.find(roman[i]) == romanNumerals.end()) {
            cout << "올바른 로마자를 입력하세요." << endl;
            return 0;
        }

        // 현재 문자에 해당하는 값을 가져온다
        int current = romanNumerals[roman[i]];

        // 다음 문자에 해당하는 값을 가져온다
        int next = 0;
        if (i + 1 < roman.size()) {
            next = romanNumerals[roman[i + 1]];
        }

        // 현재 문자가 다음 문자보다 작으면 뺀다
        if (current < next) {
            result -= current;
        }
        // 그 외에는 더한다
        else {
            result += current;
        }
    }

    return result;
}

int main() {
    // 로마자를 입력받는다
    string roman;
    char key;
    cout << "I = 1 / V = 5 / X = 10 / L = 50 / C = 100 / D = 500 / M = 1000" << endl;

    // ESC 키를 입력받을 때까지 반복한다
    while (true) {
        cout << "로마자를 입력하세요: ";
        cin >> roman;
        //key = cin.get();

        //if (key == 27) break;
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

        // 로마자를 숫자로 변환한다
        int result = romanToNumber(roman);

        if (result > 3999) { cout << "3999가 넘으면 안되용" << endl; }
        else { cout << "숫자 : " << result << endl; }

        // ESC 키를 입력받으면 프로그램을 종료한다
    }

    return 0;
}
