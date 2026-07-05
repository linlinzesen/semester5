#include <stdio.h>
//int main(){
//	char Str1[65]="09d7b11ce21f469ca7efa5deaa9a6321e7e796ce85bb3a2bb550e84700346ef0";
//	for (int i = 0; i < 64; ++i)
//{
//    if (Str1[i] == 102)
//        Str1[i] = 97;
//    else if (Str1[i] == 57)
//        Str1[i] = 48;
//    else
//        Str1[i]++;
//}
//    printf("%s",Str1);
//    return 0;
//}


//int main(){
//	char Str1[65]="1f2e28649c4g:25:8bb:24c3D3EGF6GFg22dff:1dbd916df13239513g21e4663";
//	for (int i = 0; i < 64; ++i){
//		Str1[i]--;
//	}
//	printf("%s",Str1);
//    return 0;
//} 



//int main(){
//	char Str[7]="WORKER";
//	for(int i=0;i<6;i++){
//		Str[i]+=2;
//	}
//	Str[6]='\0';
//	printf("%s",Str);
//	return 0;
//} 


int main(){
	char str1[8]={0x55,0x11,0x40,0x04,0x3E,0x55,0x2E,0x29};
	char str2[8]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x08};
	char target[9]={0};
	for(int i=0;i<8;i++){
		target[i]=str1[i]^str2[i];
	}
	target[8]='\0'; 
	printf("%s",target);
} 
