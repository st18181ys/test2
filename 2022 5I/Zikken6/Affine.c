#include "aes128.h"
#include <stdio.h>

unsigned char Affine(unsigned char b){
	unsigned char aff1[8][8]={{1,0,0,0,1,1,1,1},
				{1,1,0,0,0,1,1,1},
				{1,1,1,0,0,0,1,1},
				{1,1,1,1,0,0,0,1},
				{1,1,1,1,1,0,0,0},
				{0,1,1,1,1,1,0,0},
				{0,0,1,1,1,1,1,0},
				{0,0,0,1,1,1,1,1}};
	unsigned char aff2[8]={1,1,0,0,0,1,1,0};
	unsigned char bd[8]={0,0,0,0,0,0,0,0};
	unsigned char bb[8];
	unsigned char a=b;

	for(int i=0;i<8;i++){
		bb[7-i]=a%2;
		a=a/2;
	}
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			bd[7-i]=(aff1[i][j]&bb[7-j])^bd[7-i];
		}
		bd[7-i]=bd[7-i]^aff2[i];
	}
	
	unsigned char z=0;
	for(int i=0;i<8;i++){
		unsigned char l=1;
		for(int j=0;j<7-i;j++){
			l=l*2;
		}
		z=z+(bd[i]*l);
	}
	return z;
}
