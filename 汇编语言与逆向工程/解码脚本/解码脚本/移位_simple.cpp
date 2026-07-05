#include <stdio.h>
//int main(){
//	char target[16]={0xD5,0x96,0xC4,0xF6,0x07,0x45,0x57,0x77,0x76,0xE5,0xF6,0x48,0x47,0xF7,0x48,0x17};
//	char Str[17]={0};
//	for(int i=0;i<16;i++){
//		Str[i]=target[i];
//		Str[i] = ( (Str[i] & 0x0F)<<4) | ((Str[i] & 0x30) >> 2) | ((Str[i] & 0xC0)>>6);
//		Str[i]=Str[i]-i;
//	}
//	Str[16]='\0';
//	printf("%s",Str);
//	return 0;
//} 

int main(){
	char target[19]="FDG\\OXXVFDGMUFCQV";
	char Str[19]={0};
	for(int i=0;i<18;i++){
		Str[i]=target[i];
		Str[i] = (4 * (Str[i] & 3)) | ((Str[i] & 0xC) >> 2) | Str[i] & 0xF0;
	}
	Str[18]='\0';
	printf("%s",Str);
    return 0;
} 	
//int main(){
//	char Str[8]={26,10,14,7,17,7,13};
//	char target[8]="realpwd";
//	char v10[8]={0}; 
//	for(int i=0;i<7;i++){
//		v10[i]=target[i];
//		v10[i]=v10[i]^Str[i]; 
//	}
//	printf("%s",v10);
//	return 0;
//} 
