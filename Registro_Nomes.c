#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de string/vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de string/vari�veis
	
	printf("Digite o CPF para cadastro: "); //coletando informa��o das string
	scanf("%s", cpf); //%s refere-se a strings
	
	
	strcpy(arquivo, cpf); 	// responsavel por copiar os valores das string
 	
	FILE *file; 	//cria o arquivo na pasta do sistema
	file = fopen(arquivo, "w"); 	// cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); 		// fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualizar informa��o dentro da pasta 
	fprintf(file,"\nNome: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza o conteudo
	fprintf(file,nome); // salva o calor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza informa��o dentro da pasta
	fprintf(file,"\nSobrenome: "); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta informa��o da string
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza conteudo
	fprintf(file,sobrenome); // salva o valor da vari�vel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza conteudo
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); //abre o arquivo e atualiza conteudo
	fprintf(file,cargo); // salva o valor da vari�vel
	fclose(file); // fecha arquivo
	
	system("pause");
	
}

int consulta() //fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40]; //inicio cria��o de string/vari�veis
	char conteudo[200]; //final da cria��o de string/vari�veis
	
	printf("\nDigite o CPF a ser consultado: "); //coleta informa��o da string
	scanf("%s", cpf);
	
	
	FILE *file; //cria o arquivo na pasta do sistema
	file = fopen(cpf, "r"); //r para ler o arquivo
	
	
	if(file == NULL)
	{
		printf("O arquivo n�o foi localizado! \n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	
	printf(" Informa��es do usu�rio:\n ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	fclose(file); // fecha arquivo
	system("pause");
}
int deletar() //fun��o responsavel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:\n");
	printf("CPF: ");
	scanf("%s",cpf);
	
	
	
	
	FILE *file;//cria o arquivo na pasta do sistema
	file = fopen(cpf,"r");//r para ler o arquivo
	fclose(file); // fecha arquivo
	remove(cpf);

	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi encontrado no sistema!\n");
		system("pause");
	}
	if(file != NULL)
	{
		printf("Usuario deletado com sucesso!\n");
	}
	
	system("pause");

 }

int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("------ REGISTRO DE NOMES EBAC ------\n\n"); // inicio do menu
		printf("Selecione uma Op��o:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); // fim do menu
	
		scanf("%d",&opcao);
		
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("A op��o selecionada n�o est� disponivel\n\n");
			system("pause");
			break;
			//fim da sele��o
		}

	}
}
