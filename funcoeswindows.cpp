#include "funcoeswindows.h"

void textcolor(enum DOS_COLORS iColor){
	
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void Mostrar_Cursor(bool Mostrar){
	
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
    CONSOLE_CURSOR_INFO Info_Cursor;
    GetConsoleCursorInfo(out, &Info_Cursor);
    Info_Cursor.bVisible = Mostrar;
    SetConsoleCursorInfo(out, &Info_Cursor);
}

void Redimensionar(){
	
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	system("mode con: cols=55 lines=10");
}
