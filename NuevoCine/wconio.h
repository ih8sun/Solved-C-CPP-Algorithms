#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HANDLE hStdout, hin;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

void sizeWindow(int *x, int *y);

void gotoxy(int x, int y)
{
   HANDLE hCon;
   COORD dwPos;

   dwPos.X = x;
   dwPos.Y = y;
   hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hCon, dwPos);
}

int getch(void)
{
   int car;
   DWORD leidos, modo;

   GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &modo);
   SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo & !ENABLE_ECHO_INPUT & !ENABLE_PROCESSED_INPUT);
   ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &car, 1, &leidos, NULL);
   SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo);
   return car;
}

void clrscr()
{
   HANDLE hConsole;
   COORD coordScreen = {0, 0};
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;

   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
   {
      return;
   }
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
                                   (TCHAR)' ',      // Character to write to the buffer
                                   dwConSize,       // Number of cells to write
                                   coordScreen,     // Coordinates of first cell
                                   &cCharsWritten)) // Receive number of characters written
   {
      return;
   }
   if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
   {
      return;
   }
   if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
                                   csbi.wAttributes, // Character attributes to use
                                   dwConSize,        // Number of cells to set attribute
                                   coordScreen,      // Coordinates of first cell
                                   &cCharsWritten))  // Receive number of characters written
   {
      return;
   }
   SetConsoleCursorPosition(hConsole, coordScreen);
}

void textcolor(int ForgC)
{
   WORD wColor;
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
   }
   return;
}

void textbackground(int ForgC)
{
   WORD wColor;
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
      wColor = ((ForgC & 0x0F) << 4) | (csbi.wAttributes & 0x0f);
      SetConsoleTextAttribute(hStdOut, wColor);
   }
   return;
}
//limpia un numero de linea especifica con color
void clrline(int numlinea, int tbk, int tbc)
{
   int x, y;
   sizeWindow(&x, &y);
   textbackground(tbk);
   textcolor(tbc);
   for (int i = 0; i < x; i++)
   { //ajustar el tama�o de la linea segun pantalla
      gotoxy(i, numlinea);
      printf(" ");
   }
}
void clrCol(int columna, int tbk, int tbc)
{
   int x, y;
   sizeWindow(&x, &y);
   textbackground(tbk);
   textcolor(tbc);
   for (int i = 0; i < 29; i++)
   { //ajustar el tama�o de la linea segun pantalla
      gotoxy(columna, i);
      printf(" ");
   }
}
void espera(int segs)
{
   gotoxy(24, 1);
   gotoxy((csbiInfo.srWindow.Right - csbiInfo.srWindow.Left) / 2 - (segs / 2), 24);
   for (int i = 0; i < segs; i++)
   {
      printf(".");
      ;
      Sleep(1000);
   }
}

void pausa(char txt[])
{
   int x;

   gotoxy(24, 1);
   x = (csbiInfo.srWindow.Right - csbiInfo.srWindow.Left) / 2 - (strlen(txt) / 2) + 1;
   gotoxy(x, 24);
   printf("%s", txt);
   getch();
}
void mipausa(int x, int y, char txt[])
{
   //     int x;

   gotoxy(x, y);
   x = (csbiInfo.srWindow.Right - csbiInfo.srWindow.Left) / 2 - (strlen(txt) / 2) + 1;
   gotoxy(x, y);
   printf("%s", txt);
   getch();
}
void leeTecla(INPUT_RECORD *InputRecord)
{
   DWORD Events;

   FlushConsoleInputBuffer(hin);
   ReadConsoleInput(hin, InputRecord, 1, &Events);

   return;
}
void sizeWindow(int *x, int *y)
{
   HANDLE hConsole;
   COORD coordScreen = {0, 0};
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
   {
      return;
   }
   *x = csbi.dwSize.X;
   *y = csbi.dwSize.Y;
   return;
}
