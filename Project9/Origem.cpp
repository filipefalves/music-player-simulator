/*
Faça um algoritmo em linguagem C que emule as características de um player de músicas sendo executado em modo texto, via prompt de comando.
1. Deve - se criar uma playlist das músicas utilizando uma lista encadeada.A lista encadeada poderá ser simples ou dupla, circular ou não circular.Fica a critério do aluno decidir. 
2. Deve - se armazenar o nome de cada música, do artista / banda e a duração da faixa.Para o armazenamento utilize uma estrutura heterogênea de dados.  
3. Para inserção dos dados, você pode criar uma leitura dos dados através de um menu na tela ou já deixá - los armazenados em um arquivo texto no seu computador e só carregar este arquivo ao executar o programa.Ou ambas soluções.Decida também como você irá implementar a inserção(no início, no fim ou no meio da lista encadeada); 
4. Deve existir um menu na tela.Este menu deve permitir a inserção de novas músicas(caso optado pela inserção manual de dados), deve ter a opção de listar todas as músicas da playlist(listagem de uma lista encadeada) na tela e encerrar o programa
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Estrutura usada para armazenar os dados das musicas em lista simples
struct PLAYLIST {
	char nome[30];
	char artista[30];
	char duracao[5];
	PLAYLIST* prox;//Apenas ponteiro para próxima posição
} *head;
//Declaração das funções
int menu();
void insert(char*n, char* a, char* d);
void show();

int main() {
	int op;
	char nome[30], artista[30], duracao[5];
	//Laço de repetição com switch para cada opção do menu
	while (1) {
		op = menu();
		switch (op) {
		case 1://Obtém os dados e os coloca em variáveis auxiliares
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
//Função de menu
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
	return op;//Retorna a operação escolhida
}
//Função de inserção
void insert(char* n, char* a, char* d) {
	//Alocação na memória
	PLAYLIST* novo;
	novo = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	//Atribuição dos valores passados na chamada
	strcpy_s(novo->nome, n);
	strcpy_s(novo->artista, a);
	strcpy_s(novo->duracao, d);
	//Se head é NULL, o novo torna-se o head
	if (head == NULL) {
		head = novo;
		head->prox = NULL;
	}
	else {//Senão, head passa para a próxima posição
		novo->prox = head;
		head = novo;
	}
}
//Função para mostrar a lista
void show() {
	//Alocação na memória
	PLAYLIST* scan;
	scan = (PLAYLIST*)malloc(sizeof(PLAYLIST));
	//scan é uma cópia de head
	scan = head;
	if (scan == NULL) {//Se head é nulo, a lista não tem nenhum item
		printf("\n\tPlaylist vazia!\n\n");
		system("pause");
		return;
	}
	//Laço para obter os dados de cada struct inserida em cada iteração
	while (scan != NULL) {
		printf("**************************************************\n");
		printf("\n\tNome da musica: %s", scan->nome);
		printf("\n\tArtista: %s", scan->artista);
		printf("\n\tDuracao: %s\n", scan->duracao);
		printf("\n**************************************************\n");

		scan = scan->prox;//Faz a iteração com ponteiro para o proximo
	}

	system("pause");
	return;
}