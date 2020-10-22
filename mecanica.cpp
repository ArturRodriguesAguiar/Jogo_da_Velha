#include "mecanica.h"

void desenhar_matriz (unsigned char V[3][3]){
	
	struct {
		unsigned Linha : 2;
		unsigned Coluna : 2;			
	}Matriz;
	
	printf("\n                      ");
	for (Matriz.Linha = 0; Matriz.Linha < 3; Matriz.Linha++) printf("%d   ", Matriz.Linha);
	printf("\n");
	
	for (Matriz.Linha = 0; Matriz.Linha < 3; Matriz.Linha++){
		
		printf("                   %d ", Matriz.Linha);
		for (Matriz.Coluna = 0; Matriz.Coluna < 3; Matriz.Coluna++){

			if (V[Matriz.Linha][Matriz.Coluna] == 0) printf("[ ] "); else
			if (V[Matriz.Linha][Matriz.Coluna] == 1) printf("[X] "); else
			if (V[Matriz.Linha][Matriz.Coluna] == 2) printf("[O] ");
		}
		printf("\n");
	}
}

bool verificar_vitoria (unsigned char V[3][3]){

	//Retorno false: ninguém ganhou ainda.
	//Retorno true: Algum dos jogadores ganhou.
	
	if((V[0][0] == 1 && V[0][1] == 1 && V[0][2] == 1) ||
	   (V[1][0] == 1 && V[1][1] == 1 && V[1][2] == 1) ||
	   (V[1][0] == 1 && V[1][1] == 1 && V[1][2] == 1) ||
	   (V[0][0] == 1 && V[1][0] == 1 && V[2][0] == 1) ||
	   (V[0][1] == 1 && V[1][1] == 1 && V[2][1] == 1) ||
	   (V[0][2] == 1 && V[1][2] == 1 && V[2][2] == 1) ||	   
	   (V[0][0] == 1 && V[1][1] == 1 && V[2][2] == 1) ||
	   (V[0][2] == 1 && V[1][1] == 1 && V[2][0] == 1)){		
		system("color 6E");
		printf("[O Jogador \"X\" venceu!]\n");
		return true;	
	}
	else
	if((V[0][0] == 2 && V[0][1] == 2 && V[0][2] == 2) ||
	   (V[1][0] == 2 && V[1][1] == 2 && V[1][2] == 2) ||
	   (V[1][0] == 2 && V[1][1] == 2 && V[1][2] == 2) ||
	   (V[0][0] == 2 && V[1][0] == 2 && V[2][0] == 2) ||
	   (V[0][1] == 2 && V[1][1] == 2 && V[2][1] == 2) ||
	   (V[0][2] == 2 && V[1][2] == 2 && V[2][2] == 2) ||	   
	   (V[0][0] == 2 && V[1][1] == 2 && V[2][2] == 2) ||
	   (V[0][2] == 2 && V[1][1] == 2 && V[2][0] == 2)){		
		system("color 6E");
		printf("[O Jogador \"O\" venceu!]\n");
		return true;	
	}	
	return false;
}

bool receber_posicao(bool Jogador, unsigned char V[3][3]){
	
	//V[li][ci] == 0: Celula Vazia
	//V[li][ci] == 1: Celula ocupada pelo Jogador 1
	//V[li][ci] == 2: Celula ocupada pelo Jogador 2	
	unsigned char l, li, c, ci;
	
	scanf("%c %c", &l, &c);
	li = l - 48; ci = c - 48;
	fflush(stdin);
	
	Mostrar_Cursor(false);
	if (l < 48 || c < 48 || l > 50 || c > 50 || l == '\0' || c == '\0'){

		system("color 4C");
		printf("\a[Você deve escolher um intervalo válido de 0 a 2]\n");
		system("pause");
		fflush(stdin);
		return false;
	}
	else if(V[li][ci]){

		system("color 4C");
		if(Jogador){
			if(V[li][ci] == 2) printf("\a[Você já ocupou a célula (%c, %c)!]\n", l, c);
			else printf("\a[O jogador \"X\" já ocupou a célula (%c, %c)!]\n", l, c);
		}
		else{					
			if(V[li][ci] == 1) printf("\a[Você já ocupou a célula (%c, %c)!]\n", l, c);
			else printf("\a[O jogador \"O\" já ocupou a célula (%c, %c)!]\n", l, c);
		}
		system("pause");
		fflush(stdin);
		return false;
	}
	else V[li][ci] = Jogador + 1;
	return true;
}

bool Jogar_Dois_Jogadores(unsigned char V[3][3]){
	
	unsigned char Rodada;
	bool Jogador;
	
	for(unsigned char Coluna = 0; Coluna < 3; Coluna++)
		for(unsigned char Linha = 0; Linha < 3; Linha++)
			V[Linha][Coluna] = 0;
	
	for(Jogador = false, Rodada = 0; Rodada < 9 ;Rodada++, Jogador = !Jogador){
		do{
			system("cls");
			if(Jogador) system("color 1B");
			else system("color 2A");
		
			printf("(Vez do Jogador \"%s\") Em qual célula você quer jogar?\n", Jogador? "O" : "X");
			desenhar_matriz(V);
			Mostrar_Cursor(true);		
		}
		while(!receber_posicao(Jogador, V));		

		system("cls");
		if (Rodada > 3 && verificar_vitoria(V)){

			desenhar_matriz(V);
			system("pause");
			return true;
		}	
	}		
	system("color 6E");
	printf("[Empate!]\n");
	desenhar_matriz(V);
	Mostrar_Cursor(false);
	system("pause");
	return false;
}
