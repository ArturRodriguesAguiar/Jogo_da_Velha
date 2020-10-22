#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#include "funcoeswindows.cpp"
#include "mecanica.cpp"

int main(){

	unsigned char V[3][3];	
	setlocale(LC_ALL, "Portuguese");
	Redimensionar();	
	system("color 6E");
	printf("              Bem-vindo ao Jogo da Velha!\n\n");
	printf("Você deve especificar cada jogada da seguinte forma:\nx y (Sendo \"x\" a linha e \"y\" a coluna desejada.)\n\n");
	Mostrar_Cursor(false);
	system("pause");
	system("cls");
	while(true)Jogar_Dois_Jogadores(V);	
	return 0;
}
