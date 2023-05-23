#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o do espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //respons�vel por cuidar dos strings

int main() //fun��o principal
{
	int opcao=0; //definindo as vari�veis
    int x=1; //definindo o valor para o comando for
    
    for(x=1;x=1;) //definindo o espa�o de repeti��o
    {
    	system("cls");
	    setlocale(LC_ALL, "portuguese"); //defini��o da linguagem
	
	    printf("### Consult�rio da EBAC ###\n\n"); //in�cio do menu
        printf("Escolha a op��o que deseja executar:\n\n");
     	printf("\t1 - Registrar nomes\n");
  	    printf("\t2 - Consultar nomes\n");
 	    printf("\t3 - Deletar nomes\n");
 	    printf("\t4 - Sair do sistema\n\n");
 	    printf("Op��o: ");                         //final do menu
	
 	    scanf("%d", &opcao); //armazenando a escolha 
	          system("cls"); //respons�vel por limpar a tela
	
	    switch(opcao)
	    { 
		    case 1:                    //in�cio das op��es
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
	    	printf("Essa op��o � inexistente!\n\n");
	    	system("pause");
	    	break;                      //final das op��es
	     } 
    }
}

int registro() //fun��o respons�vel por registrar os uau�rios
{
	char arquivo[40]; //definindo o limite de caracteres dispon�vel por registro
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o cpf a ser cadastrado: "); //in�cio do registro do CPF
	scanf("%s",cpf); //"%s" � o comando respons�vel pelas vari�veis/strings
	
	strcpy(arquivo,cpf);
	
	FILE *file;                  //criando o arquivo
	file = fopen(arquivo, "w");  //criando o arquivo
	fprintf(file, "\nCPF: "); 
	fprintf(file,cpf);           //salvando as vari�veis
	fclose(file);                //fechando o arquivo criado e fim do registro do CPF
	
	printf("Digite o nome a ser cadastrado: "); //inicio do regsitro do nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome: ");   
	fprintf(file,nome);     
	fclose(file);                               //fim do registro do nome

	printf("Digite o sobrenome a ser cadastrado: "); //in�cio do registro do sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);                                    //fim do registro do sobrenome
	
	printf("Digite o cargo a ser cadastrado: "); //in�cio do registro do cargo
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

int consulta() //fun��o respon�vel por consultar os dados registrados dos usu�rios
{
	setlocale(LC_ALL, "portuguese"); //defini��o da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //obtendo os dados do usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //preven��o e aviso para um suposto erro de digita��o
	{
		printf("\n o CPF digitado n�o foi localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: "); 
		printf("%s", conteudo);	
	}
	
	system("pause");	
}

int deletar() //fun��o respons�vel por deletar os usu�rios
{
	char cpf[40];
	
	printf("Digite o usu�rio a ser deletado: "); //obtendo informa��o do usu�rio a ser deletado
	scanf("%s",cpf);
	
	remove(cpf); //remo��o do usu�rio
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" � o c�digo para o sistema ler o arquivo
	
	if(file == NULL) //preven��o e aviso para um suposto erro de digita��o
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}


 
	

	
	

