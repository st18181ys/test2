#include <stdio.h>
#define f(x) (x)*(x)+x+1
int main(void){
    float a=0.0;
    float b=1.0;
    float n=10;

    float dx=0.0;
    dx=(b-a)/(2*n);

    float ans=0.0;
    float x=0.0;
    float f;

    for(int c=0;c<=2*n;c++){
        if(c==0||c==2*n){
            x=c*dx;
            f=f(x);
            ans+=f;
        }else if(c%2==1){
            x=c*dx;
            f=f(x);
            f*=4;
            ans+=f;
        }else if(c%2==0){
            x=c*dx;
            f=f(x);
            f*=2;
            ans+=f;
        }
        printf("ans=%f\n",ans);
    }

    float answer=0.0;
    answer=(ans*dx)/3.0;

    printf("%f\n",answer);

    return 0;
}