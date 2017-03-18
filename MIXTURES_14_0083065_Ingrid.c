# include <stdio.h>
# define max 999999
# define tam 105

int mixtures (int n){
	int color[tam][tam],smoke[tam][tam];
	int i,j,k,aux, aux2, seci, secj, min;
	for(i=0;i<n;i++) {
		scanf("%d",&color[i][i]);
		if (color[i][i]<0 || color[i][i]>99){
			color[i][i] = 0;
		}
	}
	for(aux=2;aux<=n;aux++){
		for(i=0;i<n-aux+1;i++){
			j=i+aux-1;
			min = max;
			for(k=i;k<=j-1;k++) {
				if(k+1<tam && j<tam){
					seci = k+1;
					secj = j;
					aux2 = (smoke[i][k] + smoke[seci][secj]) + (color[i][k]*color[seci][secj]); 
					if(aux2<min) {
						color[i][j]= (color[i][k] + color[seci][secj])%100;
						smoke[i][j] = aux2 ;
						min = aux2;
					}
				}
			}
		}
	}
return smoke[0][n-1];
}


int main(){
	int n, resposta=0;
	while(scanf("%d",&n)!=EOF){
		if(n>=1 && n<= 100){
			resposta = mixtures (n);
			printf("%d\n", resposta);
		}
	};
return 0;
}
