#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NUM 10000000
double rnd(void){
    return((double)rand()/RAND_MAX);
}
int main(void){
    double x,y,carve;
    int i,in=0;

    for(i=0;i<NUM;i++){
        x=2*rnd();
        y=2*rnd();
        if(sqrt(4-x*x)>=y) in++;
    }
    carve=(double)4*in/NUM;
    printf("area=%f\n",carve);
    return 0;
}