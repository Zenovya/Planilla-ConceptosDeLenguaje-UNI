/*********************************************************/
/*          UNIVERSIDAD NACIONAL DE INGENIERIA		 */
/*	        Lenguajes de Programacion   		 */
/*							 */
/*    Grupo: Jose Luis Lovo Rodriguez     2021-0103U     */
/*	     Cristian Ariel Mora Aburto   2021-0185U     */
/*           Eduard Jose Garcia Jarquin   2021-0159U     */
/*********************************************************/
/****************************/
/*        Librerias         */
/****************************/
#include <stdlib.h>
#include <string.h>
#include <TILIN.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
/****************************/
/* Definicion de Constantes */
/****************************/
#define ARRIBA 72
#define ABAJO 80
/****************************/
/* Prototipado de Funciones */
/****************************/
void Logouni(void);
void Carga(void);
void Presentacion(void);
void Interfaz(void);
void Credenciales(void);
void Recaptcha(void);
void BuscarT(void);
void Resultados(void);
void IngresarT(void);
void ActualizarT(void);
void EliminarT(void);
void Planilla(void);
void Pantallasalida(void);
void Navegacion(int);
void SeleccionPantalla(int);
/****************************/
/*    Variables Globales    */
/****************************/
char tecla;
/****************************/
/*          MAIN            */
/****************************/
int main(){
	int seleccion = 1;
	time_t t;
	struct tm * tm;
	char *meses[12]={"Enero","Febrero","Marzo","Abril",
					"Mayo","Junio","Julio","Agosto",
					"Septiembre","Octubre","Noviembre","Diciembre"};
	t=time(NULL);
	tm=localtime(&t);
	Inicializador();
	system("cls");

	Logouni();
	Credenciales();
	Recaptcha();
	Carga();

		reset:
		system("cls");
		textbackground(BLACK);
		fflush(stdin);

	do{
		Interfaz();

		gotoxy(63,1);
		textcolor(WHITE);
		cprintf("0%d/%s/%d\n",tm->tm_mday, meses[tm->tm_mon], 1900 + tm->tm_year);
		gotoxy(24,3);
		textcolor(YELLOW);
		cprintf("P L A N I L L A   D E   P A G O");
		gotoxy(28,4);
		textcolor(WHITE);
		cprintf("Elige una opci%cn con:", 162);
		gotoxy(25,5);
		cprintf("Direccionales:");
		gotoxy(31,6);
		cprintf("Elecci%cn:",162);
		gotoxy(40,5);textcolor(BLUE);cprintf("ARRIBA y ABAJO");
		gotoxy(41,6);cprintf("ENTER");
		textcolor(WHITE);
		Navegacion(seleccion);

		tecla = getch();
		if ((tecla == 80)| (tecla == 72) | (tecla == 13)){
        	switch (tecla){
        	case ABAJO:
				seleccion++;
				if(seleccion > 7){
					seleccion = 1;
				}
            	break;
        	case ARRIBA:
				seleccion--;
				if(seleccion < 1){
					seleccion = 7;
				}
            	break;
			case 13:
				SeleccionPantalla(seleccion);
				goto reset;
        	default:
            	break;
        	}
    	}

	} while (true);
}
void Navegacion(int seleccion){
		switch (seleccion){
		case 1:
			textcolor(LIGHTBLUE);
			gotoxy(33,9);cprintf("Presentaci%cn",162);
			textcolor(WHITE);
			gotoxy(36,11);cprintf("Buscar");
			gotoxy(31,13);cprintf("Agregar empleado");
			gotoxy(30,15);cprintf("Actualizar empleado");
			gotoxy(31,17);cprintf("Eliminar empleado");
			gotoxy(32,19);cprintf("Mostrar planilla");
			gotoxy(37,21);cprintf("Salir");
			break;
		case 2:
			gotoxy(33,9);cprintf("Presentaci%cn",162);
			textcolor(YELLOW);
			gotoxy(36,11);cprintf("Buscar");
			textcolor(WHITE);
			gotoxy(31,13);cprintf("Agregar empleado");
			gotoxy(30,15);cprintf("Actualizar empleado");
			gotoxy(31,17);cprintf("Eliminar empleado");
			gotoxy(32,19);cprintf("Mostrar planilla");
			gotoxy(37,21);cprintf("Salir");
			break;
		case 3:
			gotoxy(33,9);cprintf("Presentaci%cn",162);
			gotoxy(36,11);cprintf("Buscar");
			textcolor(GREEN);
			gotoxy(31,13);cprintf("Agregar empleado");
			textcolor(WHITE);
			gotoxy(30,15);cprintf("Actualizar empleado");
			gotoxy(31,17);cprintf("Eliminar empleado");
			gotoxy(32,19);cprintf("Mostrar planilla");
			gotoxy(37,21);cprintf("Salir");
			break;
		case 4:
			gotoxy(33,9);cprintf("Presentaci%cn",162);
			gotoxy(36,11);cprintf("Buscar");
			gotoxy(31,13);cprintf("Agregar empleado");
			textcolor(GREEN);
			gotoxy(30,15);cprintf("Actualizar empleado");
			textcolor(WHITE);
			gotoxy(31,17);cprintf("Eliminar empleado");
			gotoxy(32,19);cprintf("Mostrar planilla");
			gotoxy(37,21);cprintf("Salir");
			break;
		case 5:
			gotoxy(33,9);cprintf("Presentaci%cn",162);
			gotoxy(36,11);cprintf("Buscar");
			gotoxy(31,13);cprintf("Agregar empleado");
			gotoxy(30,15);cprintf("Actualizar empleado");
			textcolor(RED);
			gotoxy(31,17);cprintf("Eliminar empleado");
			textcolor(WHITE);
			gotoxy(32,19);cprintf("Mostrar planilla");
			gotoxy(37,21);cprintf("Salir");
			break;
		case 6:
			gotoxy(33,9);cprintf("Presentaci%cn",162);
			gotoxy(36,11);cprintf("Buscar");
			gotoxy(31,13);cprintf("Agregar empleado");
			gotoxy(30,15);cprintf("Actualizar empleado");
			gotoxy(31,17);cprintf("Eliminar empleado");
			textcolor(YELLOW);
			gotoxy(32,19);cprintf("Mostrar planilla");
			textcolor(WHITE);
			gotoxy(37,21);cprintf("Salir");
			break;
		case 7:
			gotoxy(33,9);cprintf("Presentaci%cn",162);
			gotoxy(36,11);cprintf("Buscar");
			gotoxy(31,13);cprintf("Agregar empleado");
			gotoxy(30,15);cprintf("Actualizar empleado");
			gotoxy(31,17);cprintf("Eliminar empleado");
			gotoxy(32,19);cprintf("Mostrar planilla");
			textcolor(RED);
			gotoxy(37,21);cprintf("Salir");
			break;
		default:
			break;
		}
}
void SeleccionPantalla(int seleccion){
	switch (seleccion){
	case 1:
		Presentacion();
		break;
	case 2:
		BuscarT();
		Resultados();
		break;
	case 3:
		IngresarT();
		break;
	case 4:
		ActualizarT();
		break;
	case 5:
		EliminarT();
		break;
	case 6:
		Planilla();
		system("cls");
		break;
	case 7:
		Pantallasalida();
		break;
	default:
		break;
	}
}
