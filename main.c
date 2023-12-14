#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


#define MAX_JUGADORES 8

char nombres[MAX_JUGADORES][50] = {
    "Juan",
    "Ana",
    "Carlos",
    "Maria",
    "Luis",
    "Laura",
    "Pedro",
    "Sofia"
};

int puntajes[MAX_JUGADORES] = { 150, 120, 100, 90, 80, 70, 60, 50 };

//====================================================================================================
// FUNCIONES PARA EL MANEJO DE TECLAS Y CURSOR
//====================================================================================================

// Mueve el cursor a la posición (x, y) en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Verifica si la tecla especificada (vKey) está actualmente presionada
bool keyPressed(int vKey) {
    return GetAsyncKeyState(vKey) & 0x8000;
}

// Oculta el cursor en la consola
void ocultarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100; 
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Muestra el cursor en la consola
void mostrarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//====================================================================================================
// FUNCION PARA EL SONIDO
//====================================================================================================

void reproducirSonido() {
    Beep(500, 300); // Frecuencia, Duración del sonido (en milisegundos)
}


//====================================================================================================
// FUNCIONES PARA EL MENU
//====================================================================================================

// Función para dibujar el título del juego al inicio
void dibujoInicial(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Cambiar el color a  rosado para el dibujo inicial
    SetConsoleTextAttribute(hConsole, 13);

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
    gotoxy(x, y + 10); printf("			           / \\");
    gotoxy(x, y + 11); printf("				  /   \\");

    // Restaurar el color original de la consola
    SetConsoleTextAttribute(hConsole, 7);
}


// Función para mostrar las opciones del menú
void opciones(int x, int y, int selected) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Cambiar el color a cian para las opciones
    SetConsoleTextAttribute(hConsole, 11);

    gotoxy(x + 6, y + 4); printf(selected == 1 ? "> JUGAR   " : "  JUGAR   ");
    gotoxy(x + 6, y + 6); printf(selected == 2 ? "> PUNTAJES" : "  PUNTAJES");
    gotoxy(x + 6, y + 8); printf(selected == 3 ? "> INSTRUCCIONES" : "  INSTRUCCIONES");
    gotoxy(x + 6, y + 10); printf(selected == 4 ? "> SALIR   " : "  SALIR   ");

    // Restaurar el color original de la consola
    SetConsoleTextAttribute(hConsole, 7);
}

// Función para manejar el menú y la interacción con las teclas
int manejarMenu() {
    ocultarCursor();

    int opcion = 1;

    do {
        if (keyPressed(VK_UP)) {
            if (opcion > 1) {
                opcion--;
                //Incluir sonido
                reproducirSonido();
            }
        } else if (keyPressed(VK_DOWN)) {
            if (opcion < 4) {
                opcion++;
                //Incluir sonido
                reproducirSonido();
            }
        }

        system("cls");

        dibujoInicial(10, 5);
        opciones(30, 15, opcion);

        Sleep(100);

    } while (!keyPressed(VK_RETURN));

    return opcion;
}

// Función para mostrar la información del jugador en pantalla
void informacionJugador(int x, int y) {
    gotoxy(x, y); printf("        ___________________________");
    gotoxy(x, y + 1); printf("       | ** INFORMACION JUGADOR ** |");
    gotoxy(x, y + 2); printf("       |                           |");
    gotoxy(x, y + 3); printf("       |    Jugador: Jugador1      |");
    gotoxy(x, y + 4); printf("       |    =================      |");
    gotoxy(x, y + 5); printf("       |    Nivel Actual: 1        |");
    gotoxy(x, y + 6); printf("       |    =================      |");
    gotoxy(x, y + 7); printf("       |    Puntos: 0              |");
    gotoxy(x, y + 8); printf("       |    =================      |");
    gotoxy(x, y + 9); printf("       |___________________________|");
    gotoxy(x, y + 10); printf("       |                           |");
    gotoxy(x, y + 11); printf("       | ** INFORMACION NIVEL **   |");
    gotoxy(x, y + 12); printf("       |                           |");
    gotoxy(x, y + 13); printf("       |    Nivel: 1               |");
    gotoxy(x, y + 14); printf("       |    ===============        |");
    gotoxy(x, y + 15); printf("       |    Intentos: 6            |");
    gotoxy(x, y + 16); printf("       |    ===============        |");
    gotoxy(x, y + 17); printf("       |    Puntos:   600          |");
    gotoxy(x, y + 18); printf("       |    ===============        |");
    gotoxy(x, y + 19); printf("       |___________________________|");
}

// Función para dibujar el ahorcado en pantalla
void dibujarAhorcado(int x, int y) {
    gotoxy(x, y); printf("  ___________ ");
    gotoxy(x, y + 1); printf("  |         |");
    gotoxy(x, y + 2); printf("  |         |");
    gotoxy(x, y + 3); printf("  |         O");
    gotoxy(x, y + 4); printf("  |        /|\\");
    gotoxy(x, y + 5); printf("  |        / \\");
    gotoxy(x, y + 6); printf("  |");
    gotoxy(x, y + 7); printf("  |");
    gotoxy(x, y + 8); printf("  |");
    gotoxy(x, y + 9); printf("__|__");
}

// Función para mostrar las letras usadas durante el juego
void letrasUsadas(int x, int y) {
    gotoxy(x, y); printf("  ___Letras usadas___        ");
    gotoxy(x, y + 1); printf(" |                   |       ");
    gotoxy(x, y + 2); printf(" |                   |       ");
    gotoxy(x, y + 3); printf(" |___________________|       ");
}

// Función para mostrar la interfaz de adivinanza de palabras
void adivinar(int x, int y) {
    gotoxy(x, y); printf("Palabra a adivinar:     _ _ _                                        ");
    gotoxy(x, y + 2); printf("Ingrese una letra:                                    ");
    gotoxy(x, y + 4); printf("Pista: Ave acuatica ");
}


// Función principal para la pantalla de juego
void jugar() {
    system("cls");
    // Lógica para la ventana de Jugar
    informacionJugador(2,3);
    dibujarAhorcado(45, 5);
    letrasUsadas(75, 5);
    adivinar(50,20);
    system("pause");
}


// Función para mostrar los puntajes de los jugadores
void mostrarPuntajes(int x, int y) {
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Cambiar el color a  rosado para el dibujo inicial
    SetConsoleTextAttribute(hConsole, 13);

    
    gotoxy(x+15, y); printf(".______    __    __  .__   __. .___________.     ___             __   _______      _______.");
    gotoxy(x+15, y + 1); printf("|   _  \\  |  |  |  | |  \\ |  | |           |    /   \\           |  | |   ____|    /       |");
    gotoxy(x+15, y + 2); printf("|  |_)  | |  |  |  | |   \\|  | `---|  |----`   /  ^  \\          |  | |  |__      |   (----`");
    gotoxy(x+15, y + 3); printf("|   ___/  |  |  |  | |  . `  |     |  |       /  /_\\  \\   .--.  |  | |   __|      \\   \\");
    gotoxy(x+15, y + 4); printf("|  |      |  `--'  | |  |\\   |     |  |      /  _____  \\  |  `--'  | |  |____ .----)   |");
    gotoxy(x+15, y + 5); printf("| _|       \\______/  |__| \\__|     |__|     /__/     \\__\\  \\______/  |_______||_______/");

    // Restaurar el color original de la consola
    SetConsoleTextAttribute(hConsole, 7);

    for (int i = 0; i < MAX_JUGADORES; i++) {
        gotoxy(50, 15 + i); // Ubicación en la pantalla para imprimir el nombre
        printf("%s", nombres[i]);
        gotoxy(60, 15 + i); // Ubicación para imprimir el puntaje
        printf("%d", puntajes[i]);
    }

    system("pause");
}

// Función para mostrar las instrucciones del juego
void mostrarInstrucciones(int x, int y) {
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Cambiar el color a  rosado para el dibujo inicial
    SetConsoleTextAttribute(hConsole, 13);

    gotoxy(x+30, y); printf(" ___          __        __   ___  ___  __   __   __");
    gotoxy(x+30, y + 1); printf("|___ |       |__| |__| |  | |__/ |    |__| |  \\ |  |");
    gotoxy(x+30, y + 2); printf("|___ |___    |  | |  | |__| |  \\ |___ |  | |__/ |__|");

    // Restaurar el color original de la consola
    SetConsoleTextAttribute(hConsole, 7);
   
    gotoxy(x, y+5); printf("Instrucciones:");
    gotoxy(x, y+6); printf("1. Adivina la palabra oculta en el menor numero de intentos posible.");
    gotoxy(x, y+7); printf("2. Cada nivel tiene una palabra de longitud especifica, aumentando en un caracter por nivel.");
    gotoxy(x, y+8); printf("3. Para subir de nivel se necesita una cantidad de puntos especifica segun el nivel.");
    gotoxy(x, y+9); printf("4. Cada intento fallido disminuye tu puntaje base.");
    gotoxy(x, y+10); printf("5. Selecciona la opcion correspondiente para adivinar una letra de la palabra oculta.");
    gotoxy(x, y+11); printf("6. Si adivinas correctamente, se revelaran las apariciones de la letra en la palabra.");
    gotoxy(x, y+12); printf("7. Completa el nivel antes de agotar los intentos para obtener puntos adicionales; de lo contrario,");
    gotoxy(x, y+13); printf("   no ganas puntos y pierdes el nivel.");

    system("pause");

}


// Función para mostrar un mensaje de salida o despedida
void mensajeSalida(int x, int y) {
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Cambiar el color a  rosado para el dibujo inicial
    SetConsoleTextAttribute(hConsole, 13);

    gotoxy(x, y); printf(" ___                                          ___                   _____                            ");
    gotoxy(x, y + 1); printf("(  _`\\                     _                 (  _`\\                (___  )                           ");
    gotoxy(x, y + 2); printf("| ( (_) _ __   _ _    ___ (_)   _ _   ___    | |_) )  _    _ __        | | _   _    __     _ _  _ __ ");
    gotoxy(x, y + 3); printf("| |___ ( '__)/'_` ) /'___)| | /'_` )/',__)   | ,__/'/'_`\\ ( '__)    _  | |( ) ( ) /'_ `\\ /'_` )( '__)");
    gotoxy(x, y + 4); printf("| (_, )| |  ( (_| |( (___ | |( (_| |\\__, \\   | |   ( (_) )| |      ( )_| || (_) |( (_) |( (_| || |   ");
    gotoxy(x, y + 5); printf("(____/'(_)  `\\__,_)`\\____)(_)`\\__,_)(____/   (_)   `\\___/'(_)      `\\___/'`\\___/'`\\__  |`\\__,_)(_)   ");
    gotoxy(x, y + 6); printf("                                                                                 ( )_) |             ");
    gotoxy(x, y + 7); printf("                                                                                   \\___/              ");

    // Restaurar el color original de la consola
    SetConsoleTextAttribute(hConsole, 7);

    system("pause");
}


//====================================================================================================
// FUNCION PRINCIPAL
//====================================================================================================

int main() {
    system("cls"); // Limpia la pantalla al iniciar el programa

    int opcionElegida = manejarMenu(); // Llama a la función para manejar el menú y devuelve la opción elegida

    // Evalúa la opción elegida por el usuario
    switch (opcionElegida) {
        case 1: // Opción para jugar
            jugar(); 
            mensajeSalida(3,4); 
            break;
        case 2: // Opción para ver los puntajes
            mostrarPuntajes(3,4); 
            mensajeSalida(3,4); 
            break;
        case 3: // Opción para ver las instrucciones
            mostrarInstrucciones(3, 4); 
            mensajeSalida(3,4); 
            break;
        case 4: // Opción para salir
            mensajeSalida(3,4); // Muestra un mensaje de salida
            break;
        default: // Si se elige una opción no válida
            break;
    }

    return 0;
}
