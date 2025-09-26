/*
Autor: Bruno Myguel
Data: 23/09/25

Objetivo: CRUD com lista duplamente encadeada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// func posicao cursor
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// tela inicial
void tela() {
    system("cls");
    system("color 0c");
    int i;
    for (i = 1; i < 25; i++) {
        gotoxy(1, i);
        printf("|");
        gotoxy(80, i);
        printf("|");
    }
    gotoxy(1, 1);
    printf("+------------------------------------------------------------------------------+");
    gotoxy(1, 4);
    printf("+------------------------------------------------------------------------------+");
    gotoxy(1, 22);
    printf("+------------------------------------------------------------------------------+");
    gotoxy(1, 24);
    printf("+------------------------------------------------------------------------------+");
    gotoxy(3, 2);
    printf("UNICV");
	gotoxy(3,3);
	printf("Nome: Bruno Myguel Marcal");
    gotoxy(60, 2);
    printf("Estrutura de Dados");
    gotoxy(66, 3);
    printf("Prof. Rodney");
    gotoxy(2, 23);
    printf("MSG.:");
}

// Funcao da Tela de Cliente
void tela_funcionarios() {
    gotoxy(10, 7);
    printf("1 - Codigo.........: ");
    gotoxy(10, 9);
    printf("2 - Nome...........: ");
    gotoxy(10, 11);
    printf("3 - Endereco.......: ");
    gotoxy(10, 13);
    printf("4 - Cargo..........: ");
    gotoxy(10, 15);
    printf("5 - Data Admissao..: ");
    gotoxy(10, 17);
    printf("6 - Telefone.......: ");
    gotoxy(10, 19);
    printf("7 - Salario........: ");
}

// tela inicial
void tela_menu(){
	gotoxy(27, 5);
	printf("GERENCIAMENTO FUNCIONARIOS");
	
	gotoxy(15, 7);
    printf("1 - Cadastrar Funcionario no Final da Lista");
    gotoxy(15, 8);
    printf("2 - Cadastrar Funcionario no Inicio da Lista");
    gotoxy(15, 9);
    printf("3 - Cadastrar Funcionario em uma Posicao da Lista");
    gotoxy(15, 10);
    printf("4 - Remover Funcionario no Final da Lista");
    gotoxy(15, 11);
    printf("5 - Remover Funcionario no Inicio da Lista");
    gotoxy(15, 12);
    printf("6 - Remover Funcionario em uma Posicao da Lista");
	gotoxy(15, 13);
    printf("7 - Alteracao do Cadastro de Funcionario");
	gotoxy(15, 14);
    printf("8 - Consultar Funcionarios");
	gotoxy(15, 15);
    printf("9 - Sair do programa");
}

// Funcao que limpa a Linha de Mensagem
void limpa_msg() {
    gotoxy(07, 23);
    printf("                                                                 ");
}

// definicao estruturas de dados
typedef struct {
	
	int codigo;
	char nome[50];
	char endereco[50];
	char cargo[50];
	char dt_admissao[11];
	char telefone[15];
	float salario;
} reg_funcionarios;

typedef struct Item *Apontador;

typedef struct Item {
	
	Apontador anterior;
	reg_funcionarios conteudo;
	Apontador proximo;
} Item;

typedef struct {
	
	Apontador primeiro;
	Apontador ultimo;
} Lista;

//funcoes (req NAO funcionais)
void inicializaLista(Lista *L){
	// cria item vazio
	L->primeiro = (Apontador) malloc (sizeof(Item));

	// sempre trabalhar com L-> Ultimo, pois o objeto ja esta sendo apontado por ele
	L->ultimo = L->primeiro;

	// aterra item
	L->primeiro->anterior = NULL;
	L->primeiro->proximo = NULL;
}


//funcoes (req funcionais)
void CadFuncFinList(Lista *L, reg_funcionarios register){
	printf("teste");
	
};

void CadFuncIniList(){
	
	printf("Cadastro ini!");
};

void CadFuncMidList(){
	
	printf("Cadastro Meio!");
};

void RemFuncFinList(){
	
	printf("Remover final!");
};

void RemFuncIniList(){
	
	printf("Remover ini!");
};

void RemFuncMidList(){
	
	printf("Remover meio!");
};

void AltFunc(){
	
	printf("Alteracao!");
};

void Consulta(){
	
	printf("Consulta!");
};



int main(){
	
	// variaveis
	int resp = -1;
	Lista L;
	

	// inicializacao lista
	inicializaL(&L);
	
	// chamadas iniciais de telas
	tela();		
	tela_menu();

	// loop do software
	do{
		gotoxy(7, 23);
		printf("Digite uma opcao: ");
		scanf("%d",&resp);
		
		limpa_msg();
		switch (resp){
			case 1:
				//CadFuncFinList(L);
				break;
			
			case 2:
				CadFuncIniList();
				break;
			
			case 3: 
				CadFuncMidList();
				break;
			
			case 4:
				RemFuncFinList();
				break;
			
			case 5:
				RemFuncIniList();
				break;
				
			case 6:
				RemFuncMidList();
				break;
			
			case 7: 
				AltFunc();
				break;
			
			case 8:
				Consulta();
				break;
			
			case 9:
				system("cls");
				return 0;
				break;
			
			default:
				gotoxy(7, 23);
				printf("Valor invalido, digite novamente!");
				
		}
	} while(resp != -1);
	
	return 0;
}