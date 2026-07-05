#include <stdio.h>
int main(){
    // ¸Ä³É unsigned char
    unsigned char target[22]={0x8E,0x9A,0x80,0x8C,0xB4,0xA4,0x9C,0xFC,0xAE,0x88,0xA6,0xB0,0xFC,0x88,0x80,0xA4,0xB0,0xFC,0xB2,0x9C,0xA6,0xB8};
    //unsigned char a[12]={1,2,3,4,5,6,6,5,4,3,2,1};
    unsigned char Str[23]={0};
    
    for(int i=0;i<22;i++){
    	Str[i]=target[i];
    	Str[i]=(Str[i]^0x21)>>1;
    	//Str[i]=Str[i]^
    	//Str[i] = (8 * (Str[i] & 7)) | ((Str[i] & 0x38) >> 3) | Str[i] & 0xC0;
    }
    Str[22]='\0';
    printf("%s\n",Str);
    return 0;
}
