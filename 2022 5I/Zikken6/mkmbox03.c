#include "aes128.h"
#include <stdio.h>

unsigned char Multiply(unsigned char x,unsigned char y);

void mkmbox03(void){
    unsigned char b;
    unsigned char res;
    printf("unsigned char mbox03[256] = [ ");
    for(int i=0;i<=255;i++){
        b=i;
        res=Multiply(b,(unsigned char)3);
        if(i!=255){
            printf("0x%02x, ",res);
        }else{
            printf("0x%02x ",res);
        }
    }
    printf("] ;\n");
    return;
}