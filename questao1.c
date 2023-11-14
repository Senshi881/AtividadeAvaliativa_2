/*
1.	Em uma fábrica de peças, o salário base dos operários é de R$ 600,00. Além do salário base, cada operário recebe um adicional de produtividade baseado na quantidade de 
peças fabricadas por mês. Este adicional é pago de acordo com o seguinte critério:
•	Se o número de peças for inferior ou igual a 50, não existe adicional de produtividade;
•	Se o número de peças for superior a 50 e inferior ou igual a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50;
•	Se o número de peças for superior a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50 até 80 e de R$ 0,75 por peça fabricada acima 
das 80.

Elabore um algoritmo para solicitar de cada funcionário a quantidade de peças fabricadas naquele mês e apresentar o seu salário. Isto deve se repetir para todos os 
funcionários da empresa, onde o usuário não sabe, inicialmente, quantos funcionários existem nesta empresa, ou seja, o número de funcionários não será fornecido. 
Sua solução proposta deverá possuir as lógicas bem definidas que sejam necessárias a implementação separada em sub-algoritmos específicos, devendo pelo menos os seguintes 
sub-algoritmos:
a)	validaQuantidade que validará o número de peças fabricadas por cada funcionário;
b)	calculaSalario que efetuará o cálculo do salário total para cada funcionário.
O resultado final será mostrado ao usuário por meio de um procedimento (mostraFinal).
*/
#include <stdio.h>
#include <string.h>

int calculaSalario(int x){
    float novoSalario;
    if(x <= 50){
        return printf("\nO operario informado nao recebeu comissao. Seu salario e de R$600,00;");
    }else if(x > 50 && x <= 80){
        float pct;
        pct = (x - 50) * 0.50;
        novoSalario = 600 + pct;
        return printf("\nO novo salario do operario junto da comissao das pecas a partir das 50 e de R$%.2f;", novoSalario);
    } else{
        float pct1, pct2; 
        pct1 = 0.50 * 30;
        pct2 = (x - 80 ) * 0.75;
        novoSalario = 600 + pct1 + pct2;
        return printf("\nO novo salario do operario junto das comissoes a partir de 50 ate 80 e de 80 pra cima e de R$%.2f;", novoSalario);
    }
}

void validaQuantidade(int x){
    int pecas, reset = -1;

    do{
        printf("\nQuantas pecas o funcionario %d vendeu esse mes?\n", x);
        scanf("%d", &pecas);
        while(getchar() != '\n');

        printf("\nAs pecas informadas estao corretas? \n(PECAS: %d);\nSIM - 0; \nNAO - 1;\n", pecas);
        scanf("%d", &reset);
        while(getchar() != '\n');

        if(reset != 1){
            calculaSalario(pecas);
        } else{
            printf("\n*INSIRA CORRETAMENTE*\n");
        }
    } while(reset != 0);
}

int main(){
    int repeticao, i = 0;

    printf("Sobre o salario de funcionarios: ");
    do{
        i++;

        validaQuantidade(i);
        
        printf("\nDeseja inserir sobre um novo funcionario? \n SIM - 0; \n NAO - 1; \n", i);
        scanf("%d", &repeticao);
        while(getchar() != '\n');
    }while(repeticao != 1);

    return 0;
}