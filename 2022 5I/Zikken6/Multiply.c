#include "aes128.h"
#include <stdio.h>

unsigned char Multiply(unsigned char x,unsigned char y){
	unsigned char z[8]={0,0,0,0,0,0,0,0};
	unsigned char a[8];
	unsigned char b=x;
	for(int i=0;i<8;i++){
		a[7-i]=b%2;
		b=b/2;
	}
	unsigned char c[8];
	unsigned char d=y;
	for(int i=0;i<8;i++){
		c[7-i]=d%2;
		d=d/2;
	}
	while(c[0]!=0||c[1]!=0||c[2]!=0||c[3]!=0||c[4]!=0||c[5]!=0||c[6]!=0||c[7]!=0){
		if (c[7]==1){
			for(int i=0;i<8;i++){
				z[i]=z[i]^a[i];
			}
		}
		for(int i=0;i<8;i++){
			if(i==7){
				c[7-i]=0;
			}else{
				c[7-i]=c[6-i];
			}
		}
		if (a[0]==1){
			for(int i=0;i<8;i++){
				if(i==7){
					a[i]=0;
				}else{
					a[i]=a[i+1];
				}
			}
			unsigned char BH[8]={0,0,0,1,1,0,1,1};
			for(int i=0;i<8;i++){
				a[i]=a[i]^BH[i];
			}
		}else{
			for(int i=0;i<8;i++){
				if(i==7){
					a[i]=0;
				}else{
					a[i]=a[i+1];
				}
			}
		}
	}
	unsigned char zd=0;
	for(int i=0;i<8;i++){
		unsigned char l=1;
		for(int j=0;j<7-i;j++){
			l=l*2;
		}
		zd=zd+(z[i]*l);
	}
	return zd;
}
