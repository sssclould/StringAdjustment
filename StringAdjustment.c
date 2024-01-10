#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�������Ͷ���
#define BYTE	unsigned char
#define WORD    unsigned short
#define DWORD	unsigned long
#define BOOL	unsigned char
#define DDWORD	unsigned long long
#define	QWORD   unsigned long long
#define SQWORD	long long

#define MAX_ELEMENTS 120

void Convert_To_Tex(BYTE* Input_String)
{
    BYTE i = 0;
    BYTE* token = NULL;
    BYTE* Tem_Elements[MAX_ELEMENTS] = { 0 };//�洢�и���Ԫ��
    BYTE Elements[MAX_ELEMENTS] = { 0 };

    BYTE Len = 0;//Ԫ�ظ���

    // ���տո��и�Ԫ��
    token = strtok(Input_String, " ");
    while ((token != NULL) && (Len < MAX_ELEMENTS))
    {
        Tem_Elements[Len++] = token;
        token = strtok(NULL, " ");
    }

    //��ÿһ���ַ���Ԫ�ؽ��д�������Ĵ����Ƕ�ÿһ���ַ���Ԫ�ؽ���ʮ������ת��������ȥ0x33
    for (i = 0; i < Len; i++)
    {
        Elements[i] = strtol(Tem_Elements[i], NULL, 16) - 0x33;
    }

    // ��ӡ
    printf("Hex array: ");
    for (i = 0; i < Len; i++)
    {
        printf("0x%02x", Elements[i]);
        if (i < (Len - 1))
        {
            printf(",");
        }
    }
    printf("(0x%02x)\n",Len);

}

int main()
{
    //BYTE Input_String[] = "33 33 34 34 57";
#define lines 3
#define rows 120

    BYTE i = 0;
    BYTE Input_String[lines][rows] =
    {
        "33 33 34 34 57",
        "34 33 34 34 57 34",
        "35 33 34 34 57 36 38",
    };
    for (i = 0;i < lines;i++)
    {
        Convert_To_Tex(Input_String[i]);

    }
        
    return 0;
}