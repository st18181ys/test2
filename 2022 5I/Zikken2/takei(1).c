int p_0(int ID,int n,int SC[2],int *h) /*関数0*/
{
    //武井記述部分
    if(n>=2 && n%5 != 0){
        if(*(h+2*(n-2)+OID)==1||*(h+2*(n-1)+ID)){
            return 1;
        }
    }
    return 0;
}