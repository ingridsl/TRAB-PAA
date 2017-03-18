#include <stdio.h>
#include <string.h>
#define tam 2001

int AchaMin(int a,int b,int c) {
	if(a<=b){
		if(c<=a)
			return c;
		else return a;
	}
	else{
		if(c<=b){
			return c;
		}
		else{
			return b;
		}
	}
}

int edist (int tam1,int tam2){
	int i,j,a,b,c, mtr[tam][tam];
	char palavra1[tam],palavra2[tam];

	scanf("%s",palavra1);
	tam1=strlen(palavra1);
	if(tam1>tam){
		return 0;
	}

	scanf("%s",palavra2);
	tam2=strlen(palavra2);
	if(tam2>tam){
		return 0;
	}
	
	for(i=0;i<=tam1;i++){
		mtr[i][0]=i;
	}
	for(i=0;i<=tam2;i++){
		mtr[0][i]=i;
	}
	
	for(j=1;j<tam2+1;j++){
		for(i=1;i<tam1+1;i++){
			if(palavra1[i-1]==palavra2[j-1]){
				mtr[j][i]=mtr[j-1][i-1];
			}
			else{
				a=mtr[j-1][i-1];
				b=mtr[j-1][i];
				c=mtr[j][i-1];
				mtr[j][i]=AchaMin(a,b,c)+1;
			}
		}
	}

return mtr[tam1][tam2];
}

int main(void) {
	int t, tam1, tam2, resposta;

	scanf("%d",&t);

	for(; t!=0 ; t--){
   		resposta = edist(tam1, tam2);
	printf("%d\n",resposta);
	}	
	return 0;
}

