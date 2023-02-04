#include "aes128.h"
#include <stdio.h>

unsigned char Affine(unsigned char b);
unsigned char Inverse(unsigned char b);

void SubBytes(void){
	//事前計算プログラム
	unsigned char temp;
	unsigned char sbox[256];
	unsigned char res;
	unsigned char b;
	printf("unsigned char sbox[256] = [ ");
	for(int i=0;i<=255;i++){
		b=i;
		temp=Inverse(b);
		res=Affine(temp);
		if(i!=255){
			printf("0x%02x, ",res);
		}else{
			printf("0x%02x ",res);
		}
		sbox[b]=res;
	}
	printf("] ;\n");

	//本体
	//for(int i=0;i<=4*Nb-1;i++){
	//	state[i]=sbox[state[i]];
	//}
	return;
}

int main(void){
	SubBytes();
	return 0;
}