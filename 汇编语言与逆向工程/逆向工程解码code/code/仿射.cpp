#include <stdio.h>
#include <string.h>  // 用 strlen 自动算长度

//int main(){
//    char Str1[100];  // 开大点，随便装
//    char target[] = "kbcwsxxsz";  // 不写数字，自动长度
//    
//    // strlen(target) 
//    for(int i=0; i < strlen(target); i++){
//        // 正确解密公式
//        Str1[i] = ((21* ((target[i]) - 5-97) +260) % 26)+97; 
//    }
//    Str1[strlen(target)] = '\0';  // 自动加结束符
//    printf("%s", Str1);
//    return 0;
//}


int main()
{
    unsigned char target[] = {
        0x77,0x6F,0x68,0x7A,0x7B,0x4D,0x31,0x68,
        0x75,0x2D,0x37,0x31,0x2D,0x34,0x68,0x30,
        0x2D,0x39,0x74,0x2D,0x68,0x2D,0x21,0x7D
    };

    int len = sizeof(target) / sizeof(target[0]);
    char Str1[100] = {0};

    for (int i = 0; i < len; i++)
    {
        if (target[i] >= 'A' && target[i] <= 'Z')
        {
            Str1[i] = ((9 * (target[i] - 'A' - 7) + 260) % 26) + 'A';
        }
        else if (target[i] >= 'a' && target[i] <= 'z')
        {
            Str1[i] = ((9 * (target[i] - 'a' - 7) + 260) % 26) + 'a';
        }
        else
        {
            Str1[i] = target[i];
        }
    }

    Str1[len] = '\0';

    printf("%s\n", Str1);

    return 0;
}
