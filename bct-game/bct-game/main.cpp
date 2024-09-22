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

void imprimirDadoCara(int x, int y, int dado, int color) {
	if (color != 0) {
		Console::ForegroundColor = ConsoleColor(color);
	}
	else {
		Console::ForegroundColor = ConsoleColor::White;
	}

	gotoXY(x, y);
	cout << "-----";

	gotoXY(x, y + 1);
	cout << "|";
	if (dado == 2 || dado == 3) cout << "  *";
	else if (dado == 4 || dado == 5 || dado == 6) cout << "* *";
	else cout << "   ";
	cout << "|";

	gotoXY(x, y + 2);
	cout << "|";
	if (dado == 1 || dado == 3 || dado == 5) cout << " * ";
	else if (dado == 6) cout << "* *";
	else cout << "   ";
	cout << "|";

	gotoXY(x, y + 3);
	cout << "|";
	if (dado == 2 || dado == 3) cout << "*  ";
	else if (dado == 4 || dado == 5 || dado == 6) cout << "* *";
	else cout << "   ";
	cout << "|";

	gotoXY(x, y + 4);
	cout << "-----";
}

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
					Console::ForegroundColor = ConsoleColor::White;
					imprimirTurno(true, turnoActual);

					for (size_t i = 0; i < cantidadDados; i++)
					{
						int numero = r.Next(6) + 1;
						int color = r.Next(10);

						imprimirDadoCara(8 * (i + 1), 5, numero, color);						

						if (numero == 6)
						{
							if (!barcoJugador) {
								gotoXY(0, 12);
								Console::ForegroundColor = ConsoleColor::Green;
								imprimirMensaje("Barco obtenido!!");
								Console::ForegroundColor = ConsoleColor::White;
							}

							barcoJugador = true;
						}

						if (barcoJugador && numero == 5)
						{
							if (!capitanJugador) {
								gotoXY(0, 12);
								Console::ForegroundColor = ConsoleColor::Green;
								imprimirMensaje("Capitan obtenido!!");
								Console::ForegroundColor = ConsoleColor::White;
							}

							capitanJugador = true;
						}

						if (barcoJugador && capitanJugador && numero == 4)
						{
							if (!tripulacionJugador) {
								gotoXY(0, 12);
								Console::ForegroundColor = ConsoleColor::Green;
								imprimirMensaje("Tripulacion obtenido!!");
								Console::ForegroundColor = ConsoleColor::White;
							}

							tripulacionJugador = true;
						}
					}
				}
				else
				{
					Console::ForegroundColor = ConsoleColor::White;
					imprimirTurno(false, turnoActual);

					for (size_t i = 0; i < cantidadDados; i++)
					{
						int numero = r.Next(6) + 1;
						int color = r.Next(10);

						imprimirDadoCara(8 * (i + 1), 5, numero, color);						

						if (numero == 6)
						{
							if (!barcoComputadora) {
								gotoXY(0, 12);
								Console::ForegroundColor = ConsoleColor::Green;
								imprimirMensaje("Barco obtenido!!");
								Console::ForegroundColor = ConsoleColor::White;
							}

							barcoComputadora = true;
						}

						if (barcoComputadora && numero == 5)
						{
							if (!capitanComputadora) {
								gotoXY(0, 12);
								Console::ForegroundColor = ConsoleColor::Green;
								imprimirMensaje("Capitan obtenido!!");
								Console::ForegroundColor = ConsoleColor::White;
							}

							capitanComputadora = true;
						}

						if (barcoComputadora && capitanComputadora && numero == 4)
						{
							if (!tripulacionComputador) {
								gotoXY(0, 12);
								Console::ForegroundColor = ConsoleColor::Green;
								imprimirMensaje("Tripulacion obtenido!!");
								Console::ForegroundColor = ConsoleColor::White;
							}

							tripulacionComputador = true;
						}
					}
				}

				turnoActual++;
			}
			else {
				Console::Clear();
				Console::ForegroundColor = ConsoleColor::Red;

				imprimirMensaje("Presiona p para lanzar los dados");
			}
		}
	}

	if (barcoJugador && capitanJugador && tripulacionJugador && barcoComputadora && capitanComputadora && tripulacionComputador)
	{
		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Yellow;
		
		imprimirMensaje("Empate");

		system("pause>null");
	}

	if (barcoJugador && capitanJugador && tripulacionJugador)
	{
		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Yellow;

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
		Console::ForegroundColor = ConsoleColor::Yellow;

		if (turnoActual < 10) {
			imprimirMensaje("Computadora ha ganado en el turno: " + to_string(turnoActual));
		}
		else {
			imprimirMensaje("Computadora ha ganado");
		}
	}

	system("pause>null");
}
