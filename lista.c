#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define Tam 100
typedef struct{
    char nome[49];
    int idade;


}pessoa;

    // defino os valores globais

pessoa lista[Tam];  // Também posso criar este vetor como global
                    // obs : como nosso vetor é global, não é necessario passar nenhum parametro nas funçoes
int quant =0;

int cadastrarPessoa(){ // funçao para casatrar uma pessoa na lista

    if(quant< Tam){// verifica se tem espaço para cadastrar a pessoa na lista
    pessoa p; // criei uma pessoa

    scanf("%*c"); // para limpar o buffer do teclado , para impedir que leia um enter e coloque como nome

    printf("Nome:");
    fgets(p.nome,49,stdin);   // nome da variavel que é do tipo pessoa= p.nome, tamanho do nome, vem do teclado=stdin
                              // obs: usar fgets para texto, usuario pode colocar mais letras e teremos perca de memoria

    printf("Idade:");
    scanf("%d", &p.idade);


    lista[quant]= p; // nosso vetor lista recebe a pessoa "p" criada e joga na posição quant do vetor lista

    quant ++; // acrecento uma unidade em quant para ir para segunda posição da lista



    return 1;// conseguiu registrar a pessoa na lista

    }else{
     printf("lista está cheia");
     return 0; // retorna que não foi possivel cadastrar a pessoa
    }



 }

void salvarEmArquivo(){ // salvar na memoria

    FILE *arq= fopen("lista.txt","w") ;// estou craindo uma variavel tipo arquivo ,
                                       // este ponteiro vai armazenar o endereço de memoria
                                        //onde este arquivo vai estar

                        // parametros do fopen: primeiro o nome do arquivo, segundo parametro: vc quer abrir para ler o para
                        // escrever:w para white = escrever ou r para read= escrever.

     if(arq){ // ou arq!= NULL
              // aqui escrevemos as pessoas no arquivo

     fprintf(arq,"%d\n",quant); // obs:esta parte serve para representar a quantidade de elementos no vetor.
                                // Essencial para depois abrir o arquivo preenchendo a quantidade de informaçao que tem no arquivo


     for(int i=0; i<quant; i++){ // para escrever o nome e a idade no arquivo de cada pessoa

        fprintf(arq, "%s", lista[i].nome );    // fprintf serve para imprimir no arquivo
                       // parametros para o fprintf: primeiro: quem é o arquivo= ponteiro do arquivo= arq
                       // segundo: qual tipo= que é o do nome=%s
                       // terceiro: de onde o nome vira= lista[i].nome
                       // para escrever o nome no arquivo

        fprintf(arq,"%d\n", lista[i].idade); // para escrever a idade no arquivo
                    // \n utilizado na escrita das informaçoes nos arquios é para deixar em ordem

     }
     fclose(arq);


     }else{
     printf("não foi possivel abrir o arquivo \n \n");

     }


}

void LerDoArquivo(){ // para abrir o arquivo
    FILE *arq= fopen("lista.txt","r") ; // le do arquivo
     if(arq){
     fscanf(arq,"%d\n ", &quant );      // fscanf le do arquivo
                                        // parametros: leio do arquivo = arq, o tipo= %d,
                                        // em qual variavel eu quero salvar=&quaunt
                                        // obs: precisa deste paço para colocar na variavel quant
                                        // significa a quantidade de pessoas tem e vai indicar quantas vezes o for deve agir

     for(int i=0; i<quant; i++){
        pessoa p; // dizer quem é a pessoa que ira ser salva
        fgets(p.nome,49, arq);

        fscanf(arq,"%d\n", &p.idade);
        lista[i] = p; // salva no vetor a pessoa

     }
      fclose(arq);
     }else{
     printf("não foi possivel abrir o arquivo \n \n");

     }


}


void imprimirLista(){


    printf("                           --------------------Lista De Pessoas---------------\n");
    for(int i=0; i<quant; i++){
    printf("                              %d -     Nome: %s", i+1, lista[i].nome);
    printf("                                      Idade: %d\n", lista[i].idade);
    printf("                           ---------------------------------------------------\n");
    printf("\n");

    }
    printf("\n");

}
int main(){
    setlocale(LC_ALL, "Portuguese");

    FILE *arq= fopen("lista.txt", "r");
    if(!arq){  // verifica se o arquivo existe
        arq= fopen("lista.txt","w");
        fclose(arq);
    }else{
        fclose(arq);


    }

    LerDoArquivo();
    int op;

    do{



    printf("                   -------------------Cadastro de pessoas---------------------------");
    printf("\n                      1-Cadastrar           2-lista de pessoas           0-Sair \n");
    scanf("%d", &op);

    switch(op){
        case 0:

            printf("Sair");
            break;

        case 1:

            system("cls");
            cadastrarPessoa();
            salvarEmArquivo();
            printf("Pessoa cadastrada !!!\n");

            break;
        case 2:
            system("cls");
            imprimirLista();
            break;


        default:
            printf("Opção inválida");
            break;


    }

    }while(op !=0); // encerra o loop do menu

   return 0;

}
