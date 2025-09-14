#include <stdio.h>
#include <stdlib.h>

void menu(){

    printf("O que gostaria de faze:\n");
    printf("1- Somar:\n");
    printf("2- Subtracao:\n");
    printf("3- Multiplicacao:\n");
    printf("4- divisao:\n");
    printf("5- Sair:\n");
    printf("Escolha 1 das opcoes:\n");
}

void soma(int *a, int *b, int *resultado){
    printf("Resultado: %d\n",*resultado = *a + *b);
}

void subtracao(int *a, int *b, int *resultado){
    printf("Resultado: %d\n",*resultado = *a - *b);
}

void multiplicacao(int *a, int *b, int *resultado){
    printf("Resultado: %d\n",*resultado = *a * *b);
}

void divisao(int *a, int *b, int *resultado){

    if (*b==0)
    {
        printf("Divisao por 0 nao pode ser feita!\n");
    }
    else{
        printf("Resultado: %d\n",*resultado = *a / *b);       
    }
    
}

int main (){

    int num, num2, resultado, codigo;

        printf("Digite o primeiro numero\n");
        scanf("%d",&num);

        printf("Digite o segundo numero\n");
        scanf("%d",&num2);
    
    
    do {

        menu();
        scanf("%d",&codigo);

        switch (codigo)
        {
            case 1:
                soma(&num, &num2, &resultado);
                break;

            case 2:
                subtracao(&num, &num2, &resultado);
                break;

            case 3:
                multiplicacao(&num, &num2, &resultado);
                break;
            
            case 4:
                divisao(&num, &num2, &resultado);
                break;

                case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }
    
    }while(codigo != 5);

return (0);
}