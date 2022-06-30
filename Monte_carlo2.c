#include<stdio.h>
#include<stdlib.h>
#define NUM 10000000
double rnd(void){
    return((double)rand()/RAND_MAX);
}
int main(void){
    double x,y,cir;
    int i,in=0;

    for(i=0;i<NUM;i++){
        x=rnd();
        y=rnd();
        if(x*x/4+y*y<=1) in++;
    }
    cir=(double)4*in/NUM;
    printf("area=%f\n",cir);
    return 0;
}