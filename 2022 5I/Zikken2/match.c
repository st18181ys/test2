#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define N 50 /* 試行回数 */
#define OID (id^1) /* 相手のid */
#define CLIENT_0 "ID0" /* 名前 */
#define CLIENT_1 "ID1"

/*
 int sct[2][2]:点数表
 			自分		相手
 	[0][0]：	協調		協調
 	[0][1]：	協調		裏切り
 	[1][0]：	裏切り		協調
 	[1][1]：	裏切り		裏切り
 int *h:過去の手
        *(h+2*i+ID):i回目のIDの手
 int sc[2]:点数
 	sc[ID]:IDの点
*/

/*
   次の手を計算する関数のプロトタイプ宣言
   名前は何でもよい。引数も必要に応じて変えること
   この例では
   自分のID、今何回目か、現在までの点数、過去の手の配列
   を渡している。
*/
int play_0(int ID, int n,int SC[2] , int *H);/*ID0の関数*/
int play_1(int ID, int n,int SC[2] , int *H);/*ID1の関数*/

//(1)の点数表
const int SCT[2][2]={{5,0},{10,2}};


//(2)の点数表
//const int SCT[2][2]={{5,0},{20,2}};

int main(void){
  int i,j,k,t,n = N,rh[2] ;
  char c_name[2][255];
 
  int *h; //int h[2][N];
  int sc[2]={0,0};
  FILE *LOG;

  LOG=fopen("log_tai","w");

  setbuf(stderr,NULL);
  
  // 乱数を使いたい時に備えて初期化  
  //  srand((unsigned int)time(NULL));
  srand((unsigned int)19720117L);

  //calloc
  h=(int *)calloc(2*n,sizeof(int));

/////////////////////////////////////////
  for(j=0;j<n;j++){
		rh[0]=play_0(0, j, sc, h);
		rh[1]=play_1(1, j, sc, h);
    	
		for(k=0;k<2;k++){
			*(h+(2*j)+k)=rh[k];
			sc[k] += SCT[rh[k]][rh[k^1]];
		}
		fprintf(LOG,"Turn %3d,h: %d %d, sc:%3d %3d,total: %3d %3d\n",j+1,
			*(h+(2*j)),*(h+(2*j)+1),
			SCT[*(h+(2*j))][*(h+(2*j)+1)],SCT[*(h+(2*j)+1)][*(h+(2*j))],sc[0],sc[1]);
  }  
    
  fprintf(LOG,"      %s : %s .\n",CLIENT_0,CLIENT_1);
  fprintf(LOG,"score  %d : %d . %d\n",sc[0],sc[1],sc[0]+sc[1]);
  printf("      %s : %s .\n",CLIENT_0,CLIENT_1);
  printf("score  %d : %d . %d\n",sc[0],sc[1],sc[0]+sc[1]);
  fprintf(stderr,"\n THE END\n");

  fclose(LOG);
  free(h);
  return 0;  
}
/////////////////////////////////////////
/////////////////////////////////////////

int play_0(int ID,int n,int SC[2] , int *H)/*ID0の関数*/
{
  int  t,i,j;

  //武井1
  /*
  if(n>=2 && n%5 != 0){
    if(*(H+2*(n-2)+(ID^1))==1||*(H+2*(n-1)+ID)){
      return 1;
    }
  }
  t=0;
  */

  //佐々木1
  /*
  //点数が相手より高い時のみ協力
  if(n == 0){
    t = 0;
  }else if(SC[ID] <= SC[ID^1]){
    t = 1;
  }else{
    t = 0;
  }
  */

  //佐々木2
  /*
  //初回は協力し、以降前の手が相手と同じなら協力、でなければ裏切り
  if(n == 0){
    t = 0;
  }else if(H[2*n-1] == H[2*n-2]){
    t = 0;
  }else{
    t = 1;
  }
  */

  //薗部2
  //デービス戦略
  /*
  if(n<=9){
    return 0;
  }
  for(i=1;i<=19;i+=2){
    if(H[i]==1){
      t=1;
      break;
    }else{
      t=0;
    }
  }
  */

  //南2
  //テュロック戦略
  /*
  if(n<=9){
    return 0;
  }
  j=0;
  for(i=1;i<=19;i+=2){
    if(H[i]==0){
      j++;
    }
  }
  j=(j-1)*10;
  i=rand()%100+1;
  if(j<=i){
    t=0;
  }else{
    t=1;
  }
  */

  //南1
  //ヨッス戦略
  /*
  if(n==0){
    return 0;
  }
  if(H[2*n-1]==1){
    t=1;
  }else{
    i=rand()%100+1;
    if(i>=90){
      t=1;
    }else{
      t=0;
    }
  }
  */

  //薗部1
  //フリードマン戦略
  /*
  if(n==0){
    return 0;
  }
  for(i=1;i<=2*n-1;i+=2){
    if(H[i]==1){
      t=1;
      break;
    }else{
      t=0;
    }
  }
  */

  //堪忍袋戦略
  /*
  if(n==0&&n==1){
    return 0;
  }
  if(H[2*n-3]==1&&H[2*n-1]==1){
    t=1;
  }else{
    t=0;
  }
  */

  //（逆）しっぺ返し
  /*
  if(n==0){
    return 0;
  }
  t=H[2*n-1];
  */

  //デフォルト
  /*
  if(ID == 0){
    t = rand() & 1;
  }
  
  if(ID == 1){
    t = (rand()>>1) & 1;
  }
  */

  return t;
}

int play_1(int ID,int n,int SC[2] , int *H)/*ID1の関数*/
{
  int  t,i,j;

  //佐々木1
  /*
  //点数が相手より高い時のみ協力
  if(n == 0){
    t = 0;
  }else if(SC[ID] <= SC[ID^2]){
    t = 1;
  }else{
    t = 0;
  }
  */

  //佐々木2
  /*
  //初回は協力し、以降前の手が相手と同じなら協力、でなければ裏切り
  if(n == 0){
    t = 0;
  }else if(H[2*n-1] == H[2*n-2]){
    t = 0;
  }else{
    t = 1;
  }
  */

  //薗部2
  //デービス戦略
  /*
  if(n<=9){
    return 0;
  }
  for(i=0;i<=18;i+=2){
    if(H[i]==1){
      t=1;
      break;
    }else{
      t=0;
    }
  }
  */

  //南2
  //テュロック戦略
  /*
  if(n<=9){
    return 0;
  }
  j=0;
  for(i=0;i<=18;i+=2){
    if(H[i]==0){
      j++;
    }
  }
  j=(j-1)*10;
  i=rand()%100+1;
  if(j<=i){
    t=0;
  }else{
    t=1;
  }
  */

  //南1
  //ヨッス戦略
  /*
  if(n==0){
    return 0;
  }
  if(H[2*n-2]==1){
    t=1;
  }else{
    i=rand()%100+1;
    if(i>=90){
      t=1;
    }else{
      t=0;
    }
  }
  */

  //薗部1
  //フリードマン戦略
  /*
  if(n==0){
    return 0;
  }
  for(i=0;i<=2*n-2;i+=2){
    if(H[i]==1){
      t=1;
      break;
    }else{
      t=0;
    }
  }
  */

  //堪忍袋戦略
  /*
  if(n==0&&n==1){
    return 0;
  }
  if(H[2*n-4]==1&&H[2*n-2]==1){
    t=1;
  }else{
    t=0;
  }
  */

  //（逆）しっぺ返し
  /*
  if(n==0){
    return 0;
  }
  t=H[2*n-2];
  */

  //　デフォルト
  /*
  if(ID == 0){
    t = rand() & 1;
  }
  
  if(ID == 1){
    t = (rand()>>1) & 1;
  }
  */

  return t;
}