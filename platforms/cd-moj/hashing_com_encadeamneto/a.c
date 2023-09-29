#include <stdio.h>

int main()
{
    int numero;
    scanf("%d", &numero);
    
    int primo;
    int teste;
    int teste2;
    int contador=0;
    int verificador =0;
    
     for (int i = 0; i < numero; i++) {
        scanf("%d", &primo);
		puts("AWDAWD");
        do{
            teste = primo / 10;
            contador++;
			puts("LOL");
        } while (teste >= 10);
        for(int j=0; j<contador; j++){
			puts("HAH");
            teste2 = primo / 10;
            if((teste2==1 || teste2==3 || teste2 == 5 || teste2==7 || teste2==9)){
                verificador++;
            if((teste2 / 2 != 0) && (teste2 / 3 != 0) && (teste2 / 5 != 0) && (teste2 / 7 != 0) && (teste2 / 9 != 0) )
                verificador++;
            }
        }
    }
    
    if(verificador == contador){
        printf("S");
    } else{
        printf("N");
    }
    
    return 0;
}
