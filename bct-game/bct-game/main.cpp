#include <iostream>
#include <conio.h>
#include <string> 

using namespace std;
using namespace System;

void gotoXY(int x, int y) {
	Console::SetCursorPosition(x, y);
};

void imprimirLogo() {
	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "--              BIENVENIDOS AL JUEGO               --" << endl;
	cout << "--                                                 --" << endl;
	cout << "--                                                 --" << endl;
	cout << "--          *****     *******    ********          --" << endl;
	cout << "--          ******    *******    ********          --" << endl;
	cout << "--          **   **   **            **             --" << endl;
	cout << "--          **   **   **            **             --" << endl;
	cout << "--          ******    **            **             --" << endl;
	cout << "--          ******    **            **             --" << endl;
	cout << "--          **   **   **            **             --" << endl;
	cout << "--          **   **   **            **             --" << endl;
	cout << "--          ******    *******       **             --" << endl;
	cout << "--          *****     *******       **             --" << endl;
	cout << "--                                                 --" << endl;
	cout << "--                                                 --" << endl;
	cout << "--          Gana el jugador que saca Barco (6)     --" << endl;
	cout << "--             Capitan(5) y Tripulacion(4)         --" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;
};

void imprimirMensaje(string mensaje) {
	cout << "#####################################################" << endl;
	cout << "##";

	for (size_t i = 1; i < 25 - mensaje.length() / 2; i++)
	{
		cout << " ";
	}

	cout << mensaje;

	for (size_t i = 1; i < 25 - mensaje.length() / 2; i++)
	{
		cout << " ";
	}

	cout << "##" << endl;
	cout << "#####################################################" << endl;
};

void imprimirTurno(bool jugador, int turnoActual) {
	if (jugador) {
		imprimirMensaje("Turno | Jugador");
	}
	else {
		imprimirMensaje("Turno | Computadora");
	}
};

void imprimirDadoCara(int dado) {
	cout << "-----" << endl;

	for (int i = 1; i <= 3; ++i) {
		cout << "|"; // -
		for (int j = 1; j <= 3; ++j) {
			if (dado == 1 && i == 2 && j == 2) {
				cout << char(42);// *
			}
			else if (dado == 2 && ((i == 1 && j == 3) || (i == 3 && j == 1))) {
				cout << char(42);// *
			}
			else if (dado == 3 && ((i == 1 && j == 3) || (i == 3 && j == 1) || (i == 2 && j == 2))) {
				cout << char(42);// *
			}
			else if (dado == 4 && ((i == 1 && j == 3) || (i == 3 && j == 1) || (i == 1 && j == 1) || (
				i == 3 && j == 3))) {
				cout << char(42);// *
			}
			else if (dado == 5 && ((i == 1 && j == 3) || (i == 3 && j == 1) || (i == 1 && j == 1) || (
				i == 3 && j == 3) || (i == 2 && j == 2))) {
				cout << char(42);// *
			}
			else if (dado == 6 && ((i == 1 && j == 3) || (i == 3 && j == 1) || (i == 1 && j == 1) || (
				i == 3 && j == 3) || (i == 2 && j == 1) || (i == 2 && j == 3))) {
				cout << char(42); // *
			}
			else {
				cout << char(32);// espacio
			}
		}
		cout << "|"; // - char(45)
		cout << endl;

		//_sleep(200);
	}
	cout << "-----";
	cout << endl;
	cout << endl;
};

void main()
{
	Random r;

	int turnosPorJugador = 5;
	int cantidadDados = 5;
	int turnoActual = 1;

	bool barcoJugador = false;
	bool capitanJugador = false;
	bool tripulacionJugador = false;

	bool barcoComputadora = false;
	bool capitanComputadora = false;
	bool tripulacionComputador = false;

	imprimirLogo();
	cout << endl;
	imprimirMensaje("Presiona p para jugar");

	while (turnoActual <= turnosPorJugador * 2) {
		if (kbhit()) {
			if (barcoJugador && capitanJugador && tripulacionJugador)
			{
				break;
			}

			if (barcoComputadora && capitanComputadora && tripulacionComputador)
			{
				break;
			}

			char tecla = getch();

			if (tecla == 112) // 112 = p 
			{
				Console::Clear();

				if (turnoActual % 2 != 0)
				{
					imprimirTurno(true, turnoActual);

					for (size_t i = 0; i < cantidadDados; i++)
					{
						int numero = r.Next(6) + 1;

						imprimirDadoCara(numero);

						if (numero == 6)
						{
							if (!barcoJugador) {
								imprimirMensaje("Barco obtenido");
							}

							barcoJugador = true;
						}

						if (barcoJugador && numero == 5)
						{
							if (!capitanJugador) {
								imprimirMensaje("Capitan obtenido");
							}

							capitanJugador = true;
						}

						if (barcoJugador && capitanJugador && numero == 4)
						{
							if (!tripulacionJugador) {
								imprimirMensaje("Tripulacion obtenido");
							}

							tripulacionJugador = true;
						}
					}
				}
				else
				{
					imprimirTurno(false, turnoActual);

					for (size_t i = 0; i < cantidadDados; i++)
					{
						int numero = r.Next(6) + 1;

						imprimirDadoCara(numero);

						if (numero == 6)
						{
							if (!barcoComputadora) {
								imprimirMensaje("Barco obtenido");
							}

							barcoComputadora = true;
						}

						if (barcoComputadora && numero == 5)
						{
							if (!capitanComputadora) {
								imprimirMensaje("Capitan obtenido");
							}

							capitanComputadora = true;
						}

						if (barcoComputadora && capitanComputadora && numero == 4)
						{
							if (!tripulacionComputador) {
								imprimirMensaje("Tripulacion obtenido");
							}

							tripulacionComputador = true;
						}
					}
				}

				turnoActual++;
			}
			else {
				Console::Clear();

				imprimirMensaje("Presiona p para lanzar los dados");
			}
		}
	}

	if (barcoJugador && capitanJugador && tripulacionJugador && barcoComputadora && capitanComputadora && tripulacionComputador)
	{
		Console::Clear();

		imprimirMensaje("Empate");

		system("pause>null");
	}

	if (barcoJugador && capitanJugador && tripulacionJugador)
	{
		Console::Clear();

		if (turnoActual < 10) {
			imprimirMensaje("Jugador ha ganado en el turno: " + to_string(turnoActual));
		}
		else {
			imprimirMensaje("Jugador ha ganado");
		}
	}

	if (barcoComputadora && capitanComputadora && tripulacionComputador)
	{
		Console::Clear();

		if (turnoActual < 10) {
			imprimirMensaje("Computadora ha ganado en el turno: " + to_string(turnoActual));
		}
		else {
			imprimirMensaje("Computadora ha ganado");
		}
	}

	system("pause>null");
}
