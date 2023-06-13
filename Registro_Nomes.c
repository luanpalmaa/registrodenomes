#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de string/variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de string/variáveis
	
	printf("Digite o CPF para cadastro: "); //coletando informação das string
	scanf("%s", cpf); //%s refere-se a strings
	
	
	strcpy(arquivo, cpf); 	// responsavel por copiar os valores das string
 	
	FILE *file; 	//cria o arquivo na pasta do sistema
	file = fopen(arquivo, "w"); 	// cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); 		// fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualizar informação dentro da pasta 
	fprintf(file,"\nNome: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza o conteudo
	fprintf(file,nome); // salva o calor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza informação dentro da pasta
	fprintf(file,"\nSobrenome: "); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta informação da string
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza conteudo
	fprintf(file,sobrenome); // salva o valor da variável
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza conteudo
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); //abre o arquivo e atualiza conteudo
	fprintf(file,cargo); // salva o valor da variável
	fclose(file); // fecha arquivo
	
	system("pause");
	
}

int consulta() //função responsavel por consultar os usuários no sistema
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40]; //inicio criação de string/variáveis
	char conteudo[200]; //final da criação de string/variáveis
	
	printf("\nDigite o CPF a ser consultado: "); //coleta informação da string
	scanf("%s", cpf);
	
	
	FILE *file; //cria o arquivo na pasta do sistema
	file = fopen(cpf, "r"); //r para ler o arquivo
	
	
	if(file == NULL)
	{
		printf("O arquivo não foi localizado! \n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	
	printf(" Informações do usuário:\n ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	fclose(file); // fecha arquivo
	system("pause");
}
int deletar() //função responsavel por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n");
	printf("CPF: ");
	scanf("%s",cpf);
	
	
	
	
	FILE *file;//cria o arquivo na pasta do sistema
	file = fopen(cpf,"r");//r para ler o arquivo
	fclose(file); // fecha arquivo
	remove(cpf);

	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado no sistema!\n");
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
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("------ REGISTRO DE NOMES EBAC ------\n\n"); // inicio do menu
		printf("Selecione uma Opção:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); // fim do menu
	
		scanf("%d",&opcao);
		
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("A opção selecionada não está disponivel\n\n");
			system("pause");
			break;
			//fim da seleção
		}

	}
}
