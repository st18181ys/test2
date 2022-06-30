#include <stdio.h>
#include <math.h>
#define f(x) 4/(1+x*x)
int main(void){
    float a=0.0;
    float b=1.0;
    float n=20000;

    float dx=0.0;
    dx=(b-a)/n;

    float ans=0.0;
    float x=0.0;
    float f;

    for(int c=0;c<=n;c++){
        if(c==0||c==n){
            x=c*dx;
            f=f(x);
            ans+=f;
        }else if(c%3==1){
            x=c*dx;
            f=f(x);
            f*=3;
            ans+=f;
        }else if(c%3==2){
            x=c*dx;
            f=f(x);
            f*=3;
            ans+=f;
        }else if(c%3==0){
            x=c*dx;
            f=f(x);
            f*=2;
            ans+=f;
        }
    }

    float answer=0.0;
    answer=(ans*dx*3.0)/8.0;

    printf("%.8f\n",answer);

    return 0;
}