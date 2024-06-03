//euclidean theirem or gcd
#include<stdio.h>
int gcd(int a ,int b){
	if(b==0){
		return a;
	}
	else
	return gcd(b,a%b);
}
int main(){
  int x,y;
  printf("enter the number that you want to calculate");
  scanf("%d,%d",&x,&y);
  int result=gcd(x,y);
  printf("gcd is %d",result);
  return 0;
}
