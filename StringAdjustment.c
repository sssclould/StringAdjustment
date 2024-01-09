#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数据类型定义
#define BYTE	unsigned char
#define WORD    unsigned short
#define DWORD	unsigned long
#define BOOL	unsigned char
#define DDWORD	unsigned long long
#define	QWORD   unsigned long long
#define SQWORD	long long

#define MAX_ELEMENTS 120

void Convert_To_Tex(char* Input_String)
{
    BYTE i = 0;
    BYTE* token;
    BYTE* Tem_Elements[MAX_ELEMENTS] = { 0 };//存储切割后的元素
    BYTE Elements[MAX_ELEMENTS] = { 0 };

    BYTE Len = 0;//元素个数

    // 按照空格切割元素
    token = strtok(Input_String, " ");
    while (token != NULL && Len < MAX_ELEMENTS)
    {
        Tem_Elements[Len++] = token;
        token = strtok(NULL, " ");
    }

    //对每一个字符串元素进行处理：这里的处理是对每一个字符串元素进行十六进制转换，并减去0x33
    for (i = 0; i < Len; i++)
    {
        Elements[i] = strtol(Tem_Elements[i], NULL, 16) - 0x33;
    }

    // 打印
    printf("Hex array: ");
    for (i = 0; i < Len; i++)
    {
        printf("0x%02x", Elements[i]);
        if (i < (Len - 1))
        {
            printf(",");
        }
    }
    printf("\n");



}

int main()
{
    BYTE Input_String[] = "36 33 33 37 33 34 36 33 3a 35 33 3b 36 33 43 37 33 45 36 33 47 35 33 49 34 33 4a 35 33 4c 36 33 55";
    Convert_To_Tex(Input_String);
    return 0;
}