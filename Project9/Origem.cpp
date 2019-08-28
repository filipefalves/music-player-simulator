/*
Fa�a um algoritmo em linguagem C que emule as caracter�sticas de um player de m�sicas sendo executado em modo texto, via prompt de comando.
1. Deve - se criar uma playlist das m�sicas utilizando uma lista encadeada.A lista encadeada poder� ser simples ou dupla, circular ou n�o circular.Fica a crit�rio do aluno decidir. 
2. Deve - se armazenar o nome de cada m�sica, do artista / banda e a dura��o da faixa.Para o armazenamento utilize uma estrutura heterog�nea de dados.  
3. Para inser��o dos dados, voc� pode criar uma leitura dos dados atrav�s de um menu na tela ou j� deix� - los armazenados em um arquivo texto no seu computador e s� carregar este arquivo ao executar o programa.Ou ambas solu��es.Decida tamb�m como voc� ir� implementar a inser��o(no in�cio, no fim ou no meio da lista encadeada); 
4. Deve existir um menu na tela.Este menu deve permitir a inser��o de novas m�sicas(caso optado pela inser��o manual de dados), deve ter a op��o de listar todas as m�sicas da playlist(listagem de uma lista encadeada) na tela e encerrar o programa
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Estrutura usada para armazenar os dados das musicas em lista simples
struct PLAYLIST {
	char nome[30];
	char artista[30];
	char duracao[5];
	PLAYLIST* prox;//Apenas ponteiro para pr�xima posi��o
} *head;
//Declara��o das fun��es
int menu();
void insert(char*n, char* a, char* d);
void show();

int main() {
	int op;
	char nome[30], artista[30], duracao[5];
	//La�o de repeti��o com switch para cada op��o do menu
	while (1) {
		op = menu();
		switch (op) {
		case 1://Obt�m os dados e os coloca em vari�veis auxiliares
			printf("\n\tDigite o nome da musica: ");
			fgets(nome, 30, stdin);
			printf("\n\tDigite o nome do artista: ");
			fgets(artista, 30, stdin);
			printf("\n\tDigite duracao da faixa (no formato mm:ss): ");
			fgets(duracao, 5, stdin);
			
			insert(nome, artista, duracao);//Insere os dados na struct
			break;

		case 2:
			show();//Mostra a lista
			break;

		case 3:
			return 0;//Sai do programa

		default:
			printf("\n\tOPCAO INVALIDA\n");//Fora do intervalo
			system("pause");
		}
	}
	return 0;

}
//Fun��o de menu
int menu() {
	int op, c;
	system("cls");
	printf("\t**************MUSIC PLAYER**************\n");
	//Menu principal
	printf("\n\t1. Inserir nova musica na playlist");
	printf("\n\t2. Listar todas as musicas da playlist");
	printf("\n\t3. Sair do player\n");
	
	printf("\n\tEscolha sua opcao: ");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF);//Limpeza de buffer

	system("cls");
	return op;//Retorna a opera��o escolhida
}
//Fun��o de inser��o
void insert(char* n, char* a, char* d) {
	//Aloca��o na mem�ria
	PLAYLIST* novo;
	novo = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	//Atribui��o dos valores passados na chamada
	strcpy_s(novo->nome, n);
	strcpy_s(novo->artista, a);
	strcpy_s(novo->duracao, d);
	//Se head � NULL, o novo torna-se o head
	if (head == NULL) {
		head = novo;
		head->prox = NULL;
	}
	else {//Sen�o, head passa para a pr�xima posi��o
		novo->prox = head;
		head = novo;
	}
}
//Fun��o para mostrar a lista
void show() {
	//Aloca��o na mem�ria
	PLAYLIST* scan;
	scan = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	//scan � uma c�pia de head
	scan = head;
	if (scan == NULL) {//Se head � nulo, a lista n�o tem nenhum item
		printf("\n\tPlaylist vazia!\n\n");
		system("pause");
		return;
	}
	//La�o para obter os dados de cada struct inserida em cada itera��o
	while (scan != NULL) {
		printf("**************************************************\n");
		printf("\n\tNome da musica: %s", scan->nome);
		printf("\n\tArtista: %s", scan->artista);
		printf("\n\tDuracao: %s\n", scan->duracao);
		printf("\n**************************************************\n");

		scan = scan->prox;//Faz a itera��o com ponteiro para o proximo
	}

	system("pause");
	return;
}