#include <stdio.h>
#include <stdlib.h>

void lerVetor(double *vet, int tamanho){
    
    double media=0;
    
    for(int i=0; i<tamanho; i++){
        printf("digite %d° do vetor:\n",i+1);
        scanf("%lf",(vet+i));
        //*(vetor+i)
        media=media+vet[i];
    }
    media = media/tamanho;
    
    printf("Media: %.2lf\n", media);
}

void maiorPreco(double *vet, int tamanho){
    
    double maior = 0;
    
    for(int i=0; i<tamanho; i++){
        
        if(vet[i] > maior){
            maior = vet[i];
        }
    }
    printf("Maior valor:%.2lf\n",maior);
}

int main()
{
    int mes;
    
    printf("Digite a quantidade de meses:\n");
    scanf("%d",&mes);
    
    double *vetor = (double *) malloc(mes * sizeof(double));
    
    lerVetor(vetor, mes);
    maiorPreco(vetor, mes);
    
    
    free(vetor);
    vetor=NULL;
    
    return 0;
}