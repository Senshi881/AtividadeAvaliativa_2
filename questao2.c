/*
2.	Com a proposta para ampliação da terceirização da mão de obra, o Ministério da Fazenda está empenhado em elaborar uma análise sobre o recebimento de salário regular 
através do registro em carteira profissional dos funcionários no país. 

Assim, elabore um algoritmo que obtenha, para cada assalariado, com carteira profissional assinada, o seu sexo M(masculino) e F(feminino) e o valor de seu salário, devendo 
este salário ser maior que um real (R$1,00). Seu algoritmo deverá analisar e classificar este assalariado em Acima, Igual ou Abaixo do salário mínimo. 
Sabe-se que o salário mínimo nacional é de R$ 1400,00. 

Após a leitura dos dados de cada assalariado cadastrado pelo ministério deverá ser apresentado o seu salário em reais,
a classificação por extenso em relação ao salário mínimo e o sexo por extenso (Masculino ou Feminino).

A classificação em relação ao salário mínimo nacional deverá ser feita pelo sub-algoritmo classificaSalario e os resultados solicitados para cada assalariado deverão ser 
apresentados pelo sub-algoritmo denominado mostraClassifica. 

Você deverá fazer a entrada de dados para todos os assalariados que foram pesquisados pelo ministério, lembrando de fazer sempre a validação de todos os dados informados 
em sub-algoritmos específicos.   
Na solução deste problema os resultados finais de cada assalariado que participou desta pesquisa deverão ser apresentados.
Após a leitura dos dados de todos os assalariados pesquisados o seu algoritmo deverá apresentar a quantidade de assalariados com salário abaixo do salário mínimo e a 
quantidade assalariados com salário acima do salário mínimo.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int classificaSalario(float salario[], int g, int *cM, int *cF, int *bM, int *bF, int r){
    int validaSalario;
        if(salario[r] < 1400){
            validaSalario = 1;
            printf("\nO assalariado %d nao possui o salario minimo;", r + 1);
            return mostraClassificacao(validaSalario, salario, g, cM, cF, bM, bF, r);
        }else if(salario[r] == 1400){
            validaSalario = 2;
            printf("\nO assalariado %d possui o salario minimo;", r + 1);
            return mostraClassificacao(validaSalario, salario, g, cM, cF, bM, bF, r);
        }else if(salario[r] > 1400){
            validaSalario = 3;
            printf("\nO assalariado %d possui mais que o salario minimo;", r + 1);
            return mostraClassificacao(validaSalario, salario, g, cM, cF, bM, bF, r);  
    }
}
int mostraClassificacao(int casoSalario, float s[], int g[], int *cM, int *cF, int *bM, int *bF, int r){
    switch(casoSalario){
        case 1:
        //0 PARA MASCULINO   1 PARA FEMININO;
        if(g == 0){
            printf("\n*STATUS*\nAsslariado %d:\nSexo: Masculino;\nSalario: R$%.2f < R$1400,00;", r + 1, s[r]);
            (*bM)++;
        }else{
            printf("\n*STATUS*\nAsslariado %d:\nSexo: Feminino;\nSalario: R$%.2f < R$1400,00;", r + 1, s[r]);
            (*bF)++;
        }
        break;
        case 2:
        //0 PARA MASCULINO   1 PARA FEMININO;
        if(g == 0){
            printf("\n*STATUS*\nAsslariado %d:\nSexo: Masculino;\nSalario: R$%.2f = R$1400,00;", r + 1, s[r]);
            (*cM)++;
        }else{
            printf("\n*STATUS*\nAsslariado %d:\nSexo: Feminino;\nSalario: R$%.2f = R$1400,00;", r + 1, s[r]);
            (*cF)++;
        }
        break;
        case 3:
        //0 PARA MASCULINO   1 PARA FEMININO;
        if(g == 0){
            printf("\n*STATUS*\nAsslariado %d:\nSexo: Masculino;\nSalario: R$%.2f > R$1400,00;", r + 1, s[r]);
            (*cM)++;
        }else{
            printf("\n*STATUS*\nAsslariado %d:\nSexo: Feminino;\nSalario: R$%.2f > R$1400,00;", r + 1, s[r]);
            (*cF)++;
        }
        break;
    }
}

void validaUsuario(char g,float s,int *i){
    int reset = -1;

    printf("\nConfirma inserir que o assalariado %d possui:\nGenero: %c;\nSalario: R$%.2f;\n? \nSIM - 0; \nNAO - 1;\n", *i + 1, g, s);
    scanf("%d", &reset);
    while (getchar() != '\n');

    if(reset == 1) {
        printf("\n*INSIRA CORRETAMENTE*\n");

        (*i)--;
    } else{

    }
}
void validaQuantidade(int qtd, int *resetqtd) {
    int reset = -1;

    printf("\nConfirma inserir dados sobre %d assalariados? \nSIM - 0; \nNAO - 1;\n", qtd);
    scanf("%d", &reset);
    while (getchar() != '\n');

    if(reset == 1) {
        printf("\n*INSIRA CORRETAMENTE*\n");

        *resetqtd = 0;
    } else{

        *resetqtd = 1;
    }
}

int main(){
    int quantidadeAssalariados, resetQA;
    float salario;

    do{
        printf("\nDeseja verificar quantos assalariados? ");
        scanf("%d", &quantidadeAssalariados);
        while (getchar() != '\n');
        validaQuantidade(quantidadeAssalariados, &resetQA);
    } while(resetQA != 1);
    int genero[quantidadeAssalariados];
    float salarios[quantidadeAssalariados]; 
    char sexo;

    for(int i = 0; i < quantidadeAssalariados; i++){
        printf("\nQual e o genero do assalariado %d?\nPara masculino use 'M';\nPara feminino use 'F';\n", i + 1);
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
        while(getchar() != '\n');
        printf("\nQual e o salario do assalariado %d? ", i + 1);
        scanf("%f", &salario);
        while(getchar() != '\n');
        if(sexo == 'M'){
            genero[i] = 0;
        }else if(sexo == 'F'){
            genero[i] = 1;
        }
        salarios[i] = salario;
        validaUsuario(sexo, salario, &i);
        if(salario < 1.00){
            printf("\nInsira um salario valido;");
            i--;
        }else if(sexo != 'M' && sexo != 'F'){
            printf("\n*Insira um genero valido;*\n");
            i--;
        }else{
            printf("\n*DADOS SALVOS*\n");
        }
    }


    int acimaM = 0, acimaF = 0, abaixoM = 0, abaixoF = 0;
    for(int i = 0; i < quantidadeAssalariados; i++){
        classificaSalario(salarios, genero[i], &acimaM, &acimaF, &abaixoM, &abaixoF, i);
    }

    int tM, tF;
    tM = acimaM + abaixoM;
    tF = acimaF + abaixoF;
    printf("\nFoi informado que ha no total %d HOMENS e %d MULHERES. Sendo assim recebem menos que o salario minimo:\nHomens = %d;\nMulheres = %d;\nRecebem igual ou mais que o salario minimo:\nHomens = %d;\nMulheres = %d;", tM, tF, abaixoM, abaixoF, acimaM, acimaF);
    
    return 0;
}