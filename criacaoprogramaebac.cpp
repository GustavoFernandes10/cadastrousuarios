#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o - por ser Brasil por causa dos acentos
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() //fun��o respons�vel por cadastrar no sistema
{
	//inicio cria��o de vari�vel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim cria��o de vari�vel/string
	
	//coletar informa��o do usu�rio
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a string e esta salvando
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //w quer dizer escrever //cria o arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200 ,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}


int deleta()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
		
	FILE *file;
	file = fopen(cpf,"r");

	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("Pause");
	}	
}	



int main ()
	{
		int opcao=0; //definindo vari�vel de mem�ria
		int laco=1;
		
		for(laco=1;laco=1;)
		{
		
			system("cls");
		
			setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
		
			printf("______ Cart�rio da EBAC ______\n\n");
			printf("Escolha a op��o desejada do MENU:\n\n");
			printf("\t 1 - Cadastrar nomes\n");
			printf("\t 2 - Consultar nomes\n");
			printf("\t 3 - Deletar nomes\n");
			printf("\t 4 - sair do sistema\n\n");
			printf("Op��o: "); //mensagem para digitar qual a op��o
		
			scanf("%d", &opcao);  //scanf tem por objetivo scanea o que o usu�rio coloca e armazena o valor "%d" tem por objetivo armazenar a op��o
		
			system("cls");  //tem por fun��o limpar a tela, deletar as mensagens que tinha antes
			
			switch (opcao) //s� aceita quando a op��o for verdadeira caso seja falsa, usar default
			{
				case 1:
				registrar();
				break;
				
				case 2:
				consulta();	
				break;
				
				case 3:
				deleta();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;	
					
				default:				
				printf("Essa op��o n�o est� dispon�vel!");
				system("pause");
				break;
			}//fim da sele��o								
		}	
	}	
