#include "aes128.h"
#include "Multiply.h"	//Inverse.cの確認で必要。統合テストでは不要
#include <stdio.h>

unsigned char Multiply(unsigned char x,unsigned char y);

unsigned char Inverse(unsigned char b){
	if (b==0){
		return 0;
	}
	unsigned char temp=b;
	for(int i=1;i<=253;i++){
		temp=Multiply(temp,b);
	}
	return temp;
}

