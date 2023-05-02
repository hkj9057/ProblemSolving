//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int vr_scanf(const char* format, void* a, void* b, void* c, void* d) {
//    char input_str[1024];
//    char* token;
//    int dex = 0;
//
//    // 입력 받기
//    if (!fgets(input_str, 1024, stdin)) {
//        return -1;
//    }
//
//    // 문자열 파싱
//    token = strtok(input_str, " \n");
//    while (token) {
//        if (format[dex] == '%') {
//            dex++;
//            switch (format[dex]) {
//            case 'd':
//                *(int*)a = atoi(token);
//                break;
//            case 'c':
//                *(char*)b = token[0];
//                break;
//            case 'f':
//                *(float*)c = atof(token);
//                break;
//            case 's':
//                *(char**)d = _strdup(token);
//                break;
//            default:
//                return -1;
//            }
//        }
//        dex++;
//        token = strtok(NULL, " \n");
//    }
//
//    return 0;
//}
//
//int main()
//{
//    int a;
//    char b;
//    float c;
//    char d[1024];
//
//    printf("Enter values: ");
//
//    int result = vr_scanf("%d|%c %f,%s", &a, &b, &c, d);
//
//
//
//    if (result == 0)
//
//        printf("Values entered: %d %c %f %s\n", a, b, c, d);
//
//    else
//
//        printf("Error\n");
//
//    return 0;
//}