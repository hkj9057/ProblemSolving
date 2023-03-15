//#include <iostream>
//#include <string>
//#include <conio.h>
//
//using namespace std;
//
//string toRoman(int num) {
//    string roman;
//    int nums[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
//    string romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//
//    for (int i = 0; i < 13; i++) {
//        while (num >= nums[i]) {
//            roman += romans[i];
//            num -= nums[i];
//        }
//    }
//
//    return roman;
//}
//
//int main() {
//    int num;
//    cout << "Enter a number(0입력시 종료) : ";
//    while (true)
//    {
//        if (_kbhit() && _getch() == 27)
//        {
//            cout << "종료";
//            break;
//        }
//        cin >> num;
//        if (num >= 4000)
//        {
//            cout << "3999를 넘는 수는 로마자 변환이 안되용";
//        }
//        else
//        {
//            cout << "Roman Numeral: " << toRoman(num) << endl;
//        }
//    }
//    
//    return 0;
//}