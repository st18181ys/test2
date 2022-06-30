#include<stdio.h>
#include<stdlib.h>
#define NUM 10000000
double rnd(void){
    return((double)rand()/RAND_MAX);
}
int main(void){
    double x,y,carve;
    int i,in=0;

    for(i=0;i<NUM;i++){
        x=rnd();
        y=3*rnd();
        if(x*x+x+1>=y) in++;
    }
    carve=(double)3*in/NUM;
    printf("area=%f\n",carve);
    return 0;
}