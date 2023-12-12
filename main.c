#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool keyPressed(int vKey) {
    return GetAsyncKeyState(vKey) & 0x8000;
}

void drawRectangle(int x, int y) {
    gotoxy(x, y);     printf("   _______________________________");
    gotoxy(x, y + 1); printf("  |    _____  _    ___   _        |                           _");
    gotoxy(x, y + 2); printf("  |   |  ___|| |  / _ \\ | |       |                          | |");
    gotoxy(x, y + 3); printf("  |   | |__  | | / /_\\ \\| |__    _|_   _ __   ___   __ _   __| |  ___");
    gotoxy(x, y + 4); printf("  |   |  __| | | |  _  || '_ \\  /   \\ | '__| / __| / _` | / _` | / _ \\");
    gotoxy(x, y + 5); printf("  |   | |___ | | | | | || | | || X X || |   | (__ | (_| || (_| || (_) |");
    gotoxy(x, y + 6); printf("  |   \\____/ |_| \\_| |_/|_| |_| \\_-_/ |_|    \\___| \\__,_| \\__,_| \\___/");
    gotoxy(x, y + 7); printf("  |                               |");
    gotoxy(x, y + 8); printf(" _|_________                     /|\\");
    gotoxy(x, y + 9); printf("                                / | \\");
    gotoxy(x, y + 10); printf("			          / \\");
    gotoxy(x, y + 11); printf("				 /   \\");
}

void drawOptions(int x, int y, int selected) {
    gotoxy(x + 6, y + 4); printf(selected == 1 ? "> JUGAR   " : "  JUGAR   ");
    gotoxy(x + 5, y + 6); printf(selected == 2 ? "> PUNTAJES" : "  PUNTAJES");
    gotoxy(x + 4, y + 8); printf(selected == 3 ? "> INSTRUCCIONES" : "  INSTRUCCIONES");
    gotoxy(x + 6, y + 10); printf(selected == 4 ? "> SALIR   " : "  SALIR   ");
}

int main() {
    system("cls");

    int opcion = 1;

    do {
        if (keyPressed(VK_UP)) {
            if (opcion > 1) opcion--;
        } else if (keyPressed(VK_DOWN)) {
            if (opcion < 4) opcion++;
        }

        system("cls");

        drawRectangle(10, 5);
        drawOptions(30, 15, opcion);

        Sleep(100);

    } while (!keyPressed(VK_RETURN));

    printf("Presiona cualquier tecla para salir...");
    getch();

    return 0;
}
