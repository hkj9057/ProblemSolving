#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int vr_scanf(const char* str, void* a, void* b, void* c, void* d) {
    char input_str[1024]; // �Է� ���ڿ��� ������ �ӽ� �迭
    char* token; // ���ڿ� �Ľ��� ���� ������
    int dex = 0; // ������ �ڷ����� �����ϱ� ���� �ε��� ����

    // �Է� ���ڿ� �ޱ�
    gets_s(input_str, sizeof(input_str));

    // ���ڿ� �Ľ��� ���� ������ �ڷ����� ������ ���� �Ҵ��ϱ�
    token = strtok(input_str, " "); // ���� ���ڷ� ���ڿ��� �и�
    while (token != NULL && dex < 4) {
        switch (dex) {
        case 0:
            *((int*)a) = atoi(token);
            break;
        case 1:
            *((char*)b) = *token;
            break;
        case 2:
            *((float*)c) = atof(token);
            break;
        case 3:
            strcpy((char*)d, token);
            break;
        }
        dex++;
        token = strtok(NULL, " "); // ���� ��ū ���
    }

    // �� �Ҵ翡 ������ ��� -1 ��ȯ
    if (dex < 4) {
        return -1;
    }

    // �� �Ҵ翡 ������ ��� 0 ��ȯ
    return 0;
}

int main() {
    int a;
    char b;
    float c;
    char d[1024];

    // ����� �Է� �ޱ�
    printf("Enter values -  ex) 1 a 1.1 abc : ");
    if (vr_scanf("%d %c %f %s", &a, &b, &c, &d) == -1) {
        printf("Error\n");
        return -1;
    }

    // �Է� ���� ���� ����ϱ�
    printf("Values entered: %d %c %f %s\n", a, b, c, d);

    return 0;
}

