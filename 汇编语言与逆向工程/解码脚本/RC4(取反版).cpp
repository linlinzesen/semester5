#include<stdio.h>
#include<windows.h>
#include<string.h>
#define MAX_KEY 256
#define MAX_STR 100

int pos_i=0;
int pos_j=0;
int sbox[256];
unsigned char key[MAX_KEY]=
"secrets";  // 密钥

void init_sbox();
unsigned char generate_key();
void decryption(unsigned char *ciphertext,int len,unsigned char *result);

int main()
{
 	SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8编码
    SetConsoleCP(65001); // 设置控制台输入为UTF-8编码
	char result[MAX_STR]={0};
	int len;
	unsigned char cipher[MAX_STR]= {
    0x10,0x2C,0x02,0xFC,0xFB,0x3B,0x0D,0x73,0x6E,0xBC,0xB9,0xA7,0x6F,0x2F
    };  // 密文
	decryption((unsigned char*)cipher,14,(unsigned char*)result);
	printf("%s\n",result);
	return 0;
}

void decryption(unsigned char* ciphertext,int len,unsigned char*result) {
	pos_i =0;
	pos_j =0;
	int i=0;
	init_sbox();
	for(i=0;i<len;++i)
		result[i]= ciphertext[i]^(~generate_key()&0xFF);
	result[i]='\0'; 
}



void init_sbox(){
    int i,j;
    int key_len = strlen((const char *)key);
    unsigned char temp;
    for(i=0;i<256;++i)
        sbox[i]=i;
    j=0;

    for(i=0;i<256;++i){
        j=(j+sbox[i]+key[i%key_len])%256;
        temp = sbox[i];
        sbox[i] = sbox[j];
        sbox[j] = temp;
    }
}

unsigned char generate_key(){
    unsigned char temp;
    int t;

    pos_i=(pos_i+1)%256;
    pos_j = (pos_j+sbox[pos_i])%256;
    temp = sbox[pos_i];
    sbox[pos_i] = sbox[pos_j];
    sbox[pos_j] = temp;
    t = (sbox[pos_i]+sbox[pos_j])%256;
    return sbox[t];
}
