#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    char aluno[50];
    float nota;
}aluno;

typedef void (*calculo_func)(aluno *, int);

void lendoVetor(aluno *vet, int tamanho){
    
    while (getchar() != '\n');
    
    for(int i=0; i<tamanho; i++){
        printf("---------------------------\n");
        printf("Nome do %d° aluno: \n",i+1);
        fflush(stdin); 
        fgets((vet+i)->aluno, 50, stdin);
        
        (vet+i)->aluno[strcspn((vet+i)->aluno, "\n")] = '\0';
        
        printf("digite a nota do %d° aluno:\n",i+1);
        scanf("%f",&(vet+i)->nota);
        
        while (getchar() != '\n');
    }
}

void mediaTurma(aluno *vet, int tamanho){
    
    float media = 0.0;
    
    for(int i=0; i< tamanho; i++){
        
        media=media+(vet+i)->nota;
    }
    printf("Media da turma: %.2f\n",media/tamanho);
}

void maiorNota(aluno *vet, int tamanho){
    
    float maior = 0.0;
    
    for(int i=0; i<tamanho; i++){
        
        if((vet+i)->nota > maior){
            maior = (vet+i)->nota;
        }
    }
    
    printf("Maior nota da turma: %.2f\n",maior);
    
}

void processarDados(aluno *vetor, int tamanho, calculo_func funcao_calculo){
    funcao_calculo(vetor, tamanho);
}

int main () {
    
    aluno *vetor;
    int quantidade = 0;
    int num = 0;
    
    printf("Digite a quantidade de alunos:\n");
    scanf("%d",&quantidade);
    
    vetor = (aluno *) malloc(quantidade * sizeof(aluno));
    
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
     }
    
    lendoVetor(vetor, quantidade);
    
    printf("qual opcao a baixo vc quer executar?\n");
    printf("1 - Calcular media da turma\n");
    printf("2 - Maior nota da sala\n");
    scanf("%d", &num);
    while (getchar() != '\n');
    
    switch (num){
        case 1:
            processarDados(vetor, quantidade, mediaTurma);
            break;
        case 2:
            processarDados(vetor, quantidade, maiorNota);
            break;
    }
    
    free (vetor);
    vetor = NULL;
    
    return (0);
}