#include <stdio.h>
#include <math.h>
# define tam 1001

long long int AchaMax(long long int a, long long int b){
		if(a > b){
			return a;
		}
		else{
			return b;
		}
}

long long int farida (){
	int n, i;
	long long int monsters[tam], gold[tam];

	scanf("%d", &n);
	if(n>=0 && n<=pow(10,4)){
		for(i = 0; i < n; i++){
			scanf("%lld", &monsters[i]);
			if(monsters[i]>pow(10,9))
				monsters[i]==0;
		}
	}

	gold[0] = monsters[0];
	gold[1] = AchaMax(gold[0], monsters[1]);

	for(i = 2; i < n; i++){
		gold[i] = AchaMax(gold[i-1], (monsters[i] + gold[i-2]));
	}
return gold[n-1];
}

int main(){
	int casos, i;
	long long resposta;
	scanf("%d", &casos);
	for(i = 0; i < casos; i++){
		resposta = farida();
		printf("Case %d: %lld\n", i+1, resposta);
	}

return 0;
}
