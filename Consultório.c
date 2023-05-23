#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação do espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //responsável por cuidar dos strings

int main() //função principal
{
	int opcao=0; //definindo as variáveis
    int x=1; //definindo o valor para o comando for
    
    for(x=1;x=1;) //definindo o espaço de repetição
    {
    	system("cls");
	    setlocale(LC_ALL, "portuguese"); //definição da linguagem
	
	    printf("### Consultório da EBAC ###\n\n"); //início do menu
        printf("Escolha a opção que deseja executar:\n\n");
     	printf("\t1 - Registrar nomes\n");
  	    printf("\t2 - Consultar nomes\n");
 	    printf("\t3 - Deletar nomes\n");
 	    printf("\t4 - Sair do sistema\n\n");
 	    printf("Opção: ");                         //final do menu
	
 	    scanf("%d", &opcao); //armazenando a escolha 
	          system("cls"); //responsável por limpar a tela
	
	    switch(opcao)
	    { 
		    case 1:                    //início das opções
	    	registro();
			break;
	    	
	    	case 2:
	    	consulta();
	    	break;
	    		
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por usar o nosso programa!\n");
	    	return 0;
	    	break;
	    	
	    			
	    	default:
	    	printf("Essa opção é inexistente!\n\n");
	    	system("pause");
	    	break;                      //final das opções
	     } 
    }
}

int registro() //função responsável por registrar os uauários
{
	char arquivo[40]; //definindo o limite de caracteres disponível por registro
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o cpf a ser cadastrado: "); //início do registro do CPF
	scanf("%s",cpf); //"%s" é o comando responsável pelas variáveis/strings
	
	strcpy(arquivo,cpf);
	
	FILE *file;                  //criando o arquivo
	file = fopen(arquivo, "w");  //criando o arquivo
	fprintf(file, "\nCPF: "); 
	fprintf(file,cpf);           //salvando as variáveis
	fclose(file);                //fechando o arquivo criado e fim do registro do CPF
	
	printf("Digite o nome a ser cadastrado: "); //inicio do regsitro do nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome: ");   
	fprintf(file,nome);     
	fclose(file);                               //fim do registro do nome

	printf("Digite o sobrenome a ser cadastrado: "); //início do registro do sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);                                    //fim do registro do sobrenome
	
	printf("Digite o cargo a ser cadastrado: "); //início do registro do cargo
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: ");
	fprintf(file,cargo);
	fclose(file);                                
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);                                //fim do registro do cargo
	
	system("pause");
}

int consulta() //função responável por consultar os dados registrados dos usuários
{
	setlocale(LC_ALL, "portuguese"); //definição da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //obtendo os dados do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //prevenção e aviso para um suposto erro de digitação
	{
		printf("\n o CPF digitado não foi localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: "); 
		printf("%s", conteudo);	
	}
	
	system("pause");	
}

int deletar() //função responsável por deletar os usuários
{
	char cpf[40];
	
	printf("Digite o usuário a ser deletado: "); //obtendo informação do usuário a ser deletado
	scanf("%s",cpf);
	
	remove(cpf); //remoção do usuário
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" é o código para o sistema ler o arquivo
	
	if(file == NULL) //prevenção e aviso para um suposto erro de digitação
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}


 
	

	
	

