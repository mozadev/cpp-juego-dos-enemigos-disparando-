// ConsoleApplication4.cpp : main project file.

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

int vida = 3;

void dibujarjugadorr(int &x, int &y)
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << char(12);
}
void eliminarjugador(int &x, int &y)
{
	Console::SetCursorPosition(x, y);
	cout << " ";

}
void dibujarenemigo(int &x, int &y)
{
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::White;
	cout << char(2);
}
void eliminarenemigo(int &x, int &y)
{
	Console::SetCursorPosition(x, y);
	cout << " ";

}
void moverenemigo(int &ex, int &dx) {
	ex = ex + dx;
	if (ex == 6 || ex == 79)
		dx *= -1;
}

void dibujarbala(int xbala, int ybala)
{
	Console::SetCursorPosition(xbala, ybala);
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << "*";

}

void eliminarbala(int xbala, int ybala)
{
	Console::SetCursorPosition(xbala, ybala);
	cout << " ";

}





void  hacerjugador(int &x, int &y, int &eex, int &ey, int&dx,int ex2, int ey2, int &dx2)
{
	char tecla = -1;
	int xbala = 6, ybala = 5, dybala = 1;//bala
	int xbala2 = 7, ybala2 = 5, dybala2 = 1;//bala
	Random r;
	dibujarjugadorr(x, y);
	dibujarenemigo(eex, ey);
	dibujarenemigo(ex2, ey2);
	int disparar;

	while (true)
	{
		Console::SetCursorPosition(50, 1);
		Console::ForegroundColor = ConsoleColor::Cyan;
		cout << "vidas" << vida;

		if (ybala == 27)
			disparar = r.Next(19, 66);
		_sleep(50);

		eliminarenemigo(eex, ey);
		eliminarenemigo(ex2, ey2);
		eliminarbala(xbala, ybala);
		eliminarbala(xbala2, ybala2);
		if (kbhit())
		{
			tecla = _getch();
			tecla = toupper(tecla);//a=A//A=a;21,13....22,13
			eliminarjugador(x, y);
			switch (tecla)//WASD
			{
			case 'W': y--; break;
			case 'A': x--; break;
			case 'S': y++; break;
			case 'D': x++; break;
			}
			dibujarjugadorr(x, y);
		}
		//MOVER BALA
		if (ybala < 27)
			ybala = ybala + dybala;
		if (ybala2 < 27)
			ybala2 = ybala2 + dybala2;
		if (eex == disparar)
		{
			xbala = eex;
			ybala = ey + 1;
			Console::SetCursorPosition(xbala, ybala);
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "*";

		}
		if (ex2 == disparar)
		{
			xbala2 = ex2;
			ybala2 = ey2 + 1;
			Console::SetCursorPosition(xbala2, ybala2);
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "*";

		}
		dibujarbala(xbala2, ybala2);
		dibujarbala(xbala, ybala);
		moverenemigo(eex, dx);
		moverenemigo(ex2, dx2);
		dibujarenemigo(eex, ey);
		dibujarenemigo(ex2, ey2);
		if (xbala == x && ybala == y)
			vida--;
		dibujarjugadorr(x, y);
		if (eex == x&& ey == y)
			vida--;
		dibujarjugadorr(x, y);
		if (xbala2 == x && ybala2 == y)
			vida--;
		dibujarjugadorr(x, y);
		if (ex2== x&& ey2 == y)
			vida--;
		dibujarjugadorr(x, y);



		if (vida == 0)
			exit(0);
	}
}


int main()
{
	int x = 41, y = 15;//jugador
	int ex = 6, ey = 5, dx = 1;//enemigo
	int ex2= 50, ey2 = 7, dx2 = 1;//enemigo2
	Console::CursorVisible = false;
	hacerjugador(x, y, ex, ey, dx,ex2,ey2,dx2);
	_getch();

}
