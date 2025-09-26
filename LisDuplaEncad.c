/*
Autor: Bruno Myguel
Data: 23/09/25

Objetivo: CRUD cadastro clientes com lista duplamente encadeada.

OBSERVACAO: Esse codigo foi feito em Macos, porem, com funcoes e verificacoes de sistema operacional para rodar em sistemas distintos.
usando #ifdef para verificar o sistema operacional onde esta sendo compilado
*/

#include <stdio.h>
#include <stdlib.h>

// Cor de terminal e verificacao de SO para gotoxy, incluindo o windows.h caso seja win
#ifdef _WIN32
#include <windows.h>

void corTerminal(void){
    system("color 02"); // cor do terminal (VERDE)
}

void gotoxy(int x, int y) {
    COORD pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("ESTAMOS NO WINDOWS MEUS CAROS");
}
#else

void corTerminal(void){
    printf("\033[40;32m"); // cor do terminal (VERDE)
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x); // gotoxy adaptado para linux e Macos
	printf("ESTAMOS EM ALGO MEUS CAROS");

}
#endif

// funcao que substitui o sys(cls), verificando o sistema operacional antes de executar
void limpa_Tela(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
    
    
// tela inicial
void tela() {
	limpa_Tela();
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
void CadFuncFinList(Lista *L, reg_funcionarios Reg){
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
	gotoxy(1,1);
	
	return 0;
}