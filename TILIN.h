/*********************************************************/
/*			UNIVERSIDAD NACIONAL DE INGENIERIA			 */
/*	Lenguajes de Programacion   						 */
/*       Grupo: Jose Luis Lovo Rodriguez     2021-0103U  */
/*		        Cristian Ariel Mora Aburto   2021-0185U  */
/*              Eduard Jose Garcia Jarquin   2021-0159U  */
/*********************************************************/
/****************************/
/*        Librerias         */
/****************************/
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
/****************************/
/* Definición de Constantes */
/****************************/
#define MAXTRABAJADORES 10			/*Maximo de trabajadores*/
#define MAXCARACTERES 15			/*Maximo de caracteres*/
#define User "admin"				/*Usuario de CREDENCIALES*/
#define Pass "12345"				/*Clave de CREDENCIALES*/
#define ENTER 13					/*Definicion de tecla ENTER para distintos campos*/
#define ESPACIO 32					/*Definicion de tecla ESPACIO para distintos campos*/
#define Longitud 10					/*Maximo de longitud de cadenas de CREDENCIALES*/
#define Limite1  100000L			/*Constante para tabla de IR*/
#define Limite2  200000L			/*Constante para tabla de IR*/
#define Limite3  330000L			/*Constante para tabla de IR*/
#define Limite4  500000L			/*Constante para tabla de IR*/
/****************************/
/* Prototipado de Funciones */
/****************************/
void Inicializador(void);			/*Inicialiaza los tres trabajadores de la Struct*/
void Logouni(void);					/*Logo de la Universidad*/
void Carga(void);					/*Pantalla de Carga*/
void Presentacion(void);			/*Presentación del grupo*/
void Interfaz(void);				/*Marco principal*/
void Interfaz2(void);				/*Cuadro de CREDENCIALES*/
void Interfaz3(void);				/*Marcos de campos en AGREGAR*/
void Interfaz4(void);				/*Marco amarillo de mensajes*/
void Interfaz5(void);				/*Marco de BUSCAR y RESULTADOS*/
void Interfaz6(void);				/*Marcos de campos CREDENCIALES*/
void Planilla1(void);				/*Interfaz de mostrar planilla*/
void Planilla2(void);				/*Interfaz de Mostrar Planilla2*/
void Planilla3(void);				/*Interfaz de Mostrar Planilla3*/
void Credenciales(void);			/*Credenciales con 3 intentos y user establecido en #define*/
void Recaptcha(void);				/*Recaptcha Estetico*/
void BuscarT(void);					/*Funcion CRUD BUSCAR*/
void Resultados(void);				/*Funcion RESULTADOS de BUSCAR*/
void IngresarT(void);				/*Funcion CRUD INGRESAR*/
void ActualizarT(void);				/*Funcion CRUD ACTUALIZAR*/
void EliminarT(void);				/*Funcion CRUD ELIMINAR*/
void Planilla(void);				/*Funcion Mostrar planilla*/
void Pantallasalida(void);			/*Pantalla de salida Estetica*/
void CalculoPlanilla(int);			/*Funcion para calcular la planilla*/
int validar_cadena(char cadena[]);	/*Funcion para validar campos de cadena*/
int validar_numero(char numero[]);	/*Funcion para validar campos de numero*/
/****************************/
/*    Variables Globales    */
/****************************/
bool Buscar;
int Cantidad = 3, ContadorCarnet = 3, errores = 3, intento = 3, Posicion = 0, i, j, Busqueda[MAXTRABAJADORES];
char Nombre[MAXTRABAJADORES][MAXCARACTERES] = {"Lovo", "Roberto", "Leonel"};
char Auxiliar[MAXTRABAJADORES][MAXCARACTERES], *Actualizar, *ResultadoN;
int CarnetAux[MAXTRABAJADORES];
/****************************/
/*   Estructura de Datos    */
/****************************/
typedef struct{
	float Salario;
	int Horas_extra;
	int Comisiones;
	int PagoHoraExtra;
	float TotalIngreso;
	float IR;
	float TotalDeducciones;
	float Neto;
	float INSS;
	float INSSPatrol;
	float INATEC;
	int Carnet;
} agregar;
agregar Empleado[10];
/****************************/
/*        FUNCIONES         */
/****************************/
void Inicializador(){
	int i;

	for(i=0; i<3; i++){
		/*Lovo*/
		Empleado[i].Salario = 10000;
		Empleado[i].Horas_extra = 15;
		Empleado[i].Comisiones = 3000;
		Empleado[i].Carnet = i+1;
		CalculoPlanilla(0);
	}	
	/*Roberto*/
	Empleado[1].Salario = 12000;
	Empleado[1].Horas_extra = 10;
	Empleado[1].Comisiones = 5000;
	CalculoPlanilla(1);
	/*Leonel*/
	Empleado[2].Salario = 20000;
	Empleado[2].Horas_extra = 8;
	Empleado[2].Comisiones = 9000;
	CalculoPlanilla(2);
}
void Logouni(){
	int x, y;
		system("cls");
		for(y=5; y<=15; y++){
			delay(5);gotoxy(15,y);textcolor (BLUE);cprintf("%c",219);
		}
		for(y=5; y<=15; y++){
			delay(5);gotoxy(16,y);textcolor (BLUE);cprintf("%c",219);
		}
		for(y=5; y<=15; y++){
			delay(5);gotoxy(17,y);textcolor (BLUE);cprintf("%c",219);
		}
		for(y=5; y<=15; y++){
			delay(5);gotoxy(18,y);textcolor (BLUE);cprintf("%c",219);
		}
		for(y=5; y<=15; y++){
			delay(5);gotoxy(19,y);textcolor (BLUE);cprintf("%c",219);
		}
		for(y=5; y<=15; y++){
			delay(5);gotoxy(20,y);textcolor (BLUE);cprintf("%c",219);
		}
		for(y=5; y<=15; y++){
			delay(5);gotoxy(21,y);textcolor (BLUE);cprintf("%c",219);
		}
		for(x=15;x<=33;x++){
			delay(5);gotoxy(x,15);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=15;x<=33;x++){
			delay(5);gotoxy(x,16);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=15;x<=33;x++){
			delay(5);gotoxy(x,17);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=15;x<=33;x++){
			delay(5);gotoxy(x,18);textcolor(BLUE);cprintf("%c",219);
		}
		for(y=18; y>=10; y--){
			delay(5);gotoxy(34, y);textcolor(BLUE);cprintf("%c", 219);
		}
		for(y=18; y>=10; y--){
			delay(5);gotoxy(35, y);textcolor(BLUE);cprintf("%c", 219);
		}
		for(y=18; y>=10; y--){
			delay(5);gotoxy(36, y);textcolor(BLUE);cprintf("%c", 219);
		}
		for(y=18; y>=10; y--){
			delay(5);gotoxy(37, y);textcolor(BLUE);cprintf("%c", 219);
		}
		for(y=18; y>=10; y--){
			delay(5);gotoxy(38, y);textcolor(BLUE);cprintf("%c", 219);
		}
		for(y=18; y>=10; y--){
			delay(5);gotoxy(39, y);textcolor(BLUE);cprintf("%c", 219);
		}
		for(y=18; y>=10; y--){
			delay(5);gotoxy(40 ,y);textcolor(BLUE);cprintf("%c", 219);
		}
		for(y=5;y<=13;y++){
			delay(5);gotoxy(24,y);textcolor(BLUE);cprintf("%c",219);
		}
		for(y=5;y<=13;y++){
			delay(5);gotoxy(25,y);textcolor(BLUE);cprintf("%c",219);
	    }
		for(y=5;y<=13;y++){
			delay(5);gotoxy(26,y);textcolor(BLUE);cprintf("%c",219);
	    }
		for(y=5;y<=13;y++){
			delay(5);gotoxy(27,y);textcolor(BLUE);cprintf("%c",219);
	    }
		for(y=5;y<=13;y++){
			delay(5);gotoxy(28,y);textcolor(BLUE);cprintf("%c",219);
	    }
		for(y=5;y<=13;y++){
			delay(5);gotoxy(29,y);textcolor(BLUE);cprintf("%c",219);
	    }
		for(y=5;y<=13;y++){
			delay(5);gotoxy(30,y);textcolor(BLUE);cprintf("%c",219);
	    }
		for(y=5;y<=13;y++){
			delay(5);gotoxy(31,y);textcolor(BLUE);cprintf("%c",219);
	    }
		for(x=32;x<=50;x++){
			delay(5);gotoxy(x,5);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=32;x<=50;x++){
			delay(5);gotoxy(x,6);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=32;x<=50;x++){
			delay(5);gotoxy(x,7);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=32;x<=50;x++){
			delay(5);gotoxy(x,8 );textcolor(BLUE);cprintf("%c",219);
		}
		for(y=9;y<=18;y++){
			delay(5);gotoxy(43,y);textcolor(BLUE);cprintf("%c",219);
        }
		for(y=9;y<=18;y++){
			delay(5);gotoxy(44,y);textcolor(BLUE);cprintf("%c",219);
        }
		for(y=9;y<=18;y++){
			delay(5);gotoxy(45,y);textcolor(BLUE);cprintf("%c",219);
        }
		for(y=9;y<=18;y++){
			delay(5);gotoxy(46,y);textcolor(BLUE);cprintf("%c",219);
        }
		for(y=9;y<=18;y++){
			delay(5);gotoxy(47,y);textcolor(BLUE);cprintf("%c",219);
        }
		for(y=9;y<=18;y++){
			delay(5);gotoxy(48,y);textcolor(BLUE);cprintf("%c",219);
        }
		for(y=9;y<=18;y++){
			delay(5);gotoxy(49,y);textcolor(BLUE);cprintf("%c",219);
        }
		for(y=9;y<=18;y++){
			delay(5);gotoxy(50,y);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=51;x<=60;x++){
			delay(5);gotoxy(x,18);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=51;x<=60;x++){
			delay(5);gotoxy(x,17);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=51;x<=60;x++){
			delay(5);gotoxy(x,16);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=51;x<=60;x++){
			delay(5);gotoxy(x,15);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,14);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,13);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,12);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,11);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,10);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,8);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,7);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,6);textcolor(BLUE);cprintf("%c",219);
		}
		for(x=53;x<=60;x++){
			delay(5);gotoxy(x,5);textcolor(BLUE);cprintf("%c",219);
		}
	gotoxy(21,20);textcolor(BLUE);cprintf("UNIVERSIDAD NACIONAL DE INGENIERIA");
delay(3000);
system("cls");
}
void Carga(){
	int x, y;

	system("cls");

	for(y=0; y<52; y++){
		/*Marcos*/
		gotoxy(13,11);cprintf("%c", 201);
		gotoxy(13,13);cprintf("%c", 200);
		gotoxy(66,11);cprintf("%c", 187);
		gotoxy(66,13);cprintf("%c", 188);
		gotoxy(14+y,11);textcolor(WHITE);cprintf("%c", 205);
		gotoxy(14+y,13);textcolor(WHITE);cprintf("%c", 205);
	}
	for(x=0; x<=49; x++){
		/*Barra de carga*/
		gotoxy(36, 9);textcolor(WHITE);cprintf("CARGANDO");
		gotoxy(38, 14);cprintf("%i%",  x*2+2);
		gotoxy(15+x, 12);textcolor(GREEN);cprintf("%c", 219);
		delay(50);
	}
delay(1000);
system("cls");
}
void Presentacion(){
	time_t t;
	struct tm * tm;
	char *meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

	t=time(NULL);
	tm=localtime(&t);

	system("cls");
	gotoxy(65,1);
	textcolor(WHITE);
	cprintf("0%d/%s/%d\n",tm->tm_mday, meses[tm->tm_mon], 1900 + tm->tm_year);
	delay(15);
	gotoxy(23,2);
	cprintf("Universidad Nacional De Ingenieria");
	gotoxy(20,4);
	delay(15);
	textcolor(LIGHTBLUE);
    cprintf("&&&&&&  &&&&&&&&&&&&&&&&&&&&&&&  &&&&&&");
	gotoxy(20,5);
	delay(15);
    cprintf("&&&&&&  &&&&&&&&&&&&&&&&&&&&&&&  &&&&&&");
	gotoxy(20,6);
	delay(15);
    cprintf("&&&&&&  &&&&&&#         #&&&&&&        ");
	gotoxy(20,7);
	delay(15);
    cprintf("&&&&&&  &&&&&&# &&&&&&& #&&&&&&  &&&&&&");
	gotoxy(20,8);
	delay(15);
    cprintf("&&&&&&  &&&&&&# &&&&&&& #&&&&&&  &&&&&&");
	gotoxy(20,9);
	delay(15);
    cprintf("&&&&&&  &&&&&&# &&&&&&& #&&&&&&  &&&&&&");
	gotoxy(20,10);
	delay(15);
    cprintf("&&&&&&          &&&&&&& #&&&&&&  &&&&&&");
	gotoxy(20,11);
	delay(15);
    cprintf("&&&&&&&&&&&&&&&&&&&&&&& #&&&&&&&&&&&&&&");
	gotoxy(20,12);
	delay(15);
	cprintf("&&&&&&&&&&&&&&&&&&&&&&& #&&&&&&&&&&&&&&");
	gotoxy(24,14);
	delay(15);
	textcolor(YELLOW);
	delay(15);
	cprintf("P L A N I L L A   D E   P A G O");
	gotoxy(21,16);
	delay(15);
	textcolor(WHITE);
	cprintf("Proyecto de Lenguaje de Programaci%cn", 162);
	gotoxy(25,18);
	delay(15);
	cprintf("Docente: Ing. Nelson Barrios");
	gotoxy(14,20);
	delay(15);
	cprintf("Presentado por: Jose Luis Lovo Rodriguez 2021-0103U");
	gotoxy(30,21);
	delay(15);
	cprintf("Eduar Jose Garcia Jarquin 2021-0159U");
	gotoxy(30,22);
	delay(15);
	cprintf("Cristian Ariel Mora Aburto 2021-0185U");
	gotoxy(32,24);
	delay(15);
	cprintf("Grupo: 1M1 - CO.");
getch();
}
void Interfaz(){
	int x, y;
	/*Linea de Arriba*/
	for(x=0; x<=74; x++){
		gotoxy(3,2); textcolor(WHITE);cprintf("%c", 201);gotoxy(4+x,2);
		cprintf("%c", 205);gotoxy(78,2);cprintf("%c", 187);gotoxy(4+x,24);
		cprintf("%c", 205);
	}
	/*Lineas laterales*/
	for(y=0; y<21; y++){
		gotoxy(3,3+y);cprintf("%c", 186);gotoxy(3,24);cprintf("%c", 200);
		gotoxy(78,3+y);cprintf("%c", 186);gotoxy(78,24);cprintf("%c", 188);
	}
}
void Interfaz2(){
	int x, y;

	for(x=0;x<51;x++){
		gotoxy(14,3); textcolor(WHITE); cprintf("%c",201);gotoxy(15+x,3);
		cprintf("%c", 205); gotoxy(66,3); cprintf("%c", 187);gotoxy(15+x,22);
		cprintf("%c",205);
	}
	for(y=0;y<18;y++){
		gotoxy(14,4+y);cprintf("%c",186);gotoxy(14,22);cprintf("%c",200);
		gotoxy(66,4+y);cprintf("%c",186);gotoxy(66,22);cprintf("%c",188);
	}
}
void Interfaz3(){
	int x;
	textcolor(WHITE);
	for(x=0;x<29;x++){
        gotoxy(30,6);
        cprintf("%c",201);
        gotoxy(31+x,6);
        cprintf("%c", 205);
        gotoxy(31+x,8);
		cprintf("%c",205);
        gotoxy(59,6);
        cprintf("%c", 187);
        gotoxy(59,8);cprintf("%c",188);
        gotoxy(30,8);cprintf("%c",200);
        gotoxy(30,7);cprintf("%c",186);
        gotoxy(59,7);cprintf("%c",186);
    }

    gotoxy(22,7);
    cprintf("Nombre:"); /*32,7*/
	textcolor(WHITE);
    for(x=0;x<20;x++){
        gotoxy(34,10);
        cprintf("%c",201);
        gotoxy(35+x,10);
        printf("%c", 205);
        gotoxy(35+x,12);
        printf("%c", 205);
        gotoxy(55,10);
        cprintf("%c", 187);
        gotoxy(55,12);cprintf("%c",188);
        gotoxy(34,12);cprintf("%c",200);
        gotoxy(34,11);cprintf("%c",186);
        gotoxy(55,11);cprintf("%c",186);
    }
    gotoxy(25,11);
    cprintf("Salario:");
	textcolor(GREEN);
    gotoxy(36,11);
    cprintf("C%c",36); /*39,11*/
	textcolor(WHITE);
    for(x=0;x<20;x++){
        gotoxy(34,14);
        cprintf("%c",201);
        gotoxy(35+x,14);
        printf("%c", 205);
        gotoxy(35+x,16);
        printf("%c", 205);
        gotoxy(55,14);
        cprintf("%c", 187);
        gotoxy(55,16);cprintf("%c",188);
        gotoxy(34,16);cprintf("%c",200);
        gotoxy(34,15);cprintf("%c",186);
        gotoxy(55,15);cprintf("%c",186);
    }
    gotoxy(22,15);
    cprintf("Comisiones:");
	textcolor(GREEN);
    gotoxy(36,15);
    cprintf("C%c",36); /*39,11*/
	textcolor(WHITE);
    for(x=0;x<10;x++){
        gotoxy(39,18);
        cprintf("%c",201);
        gotoxy(40+x,18);
        printf("%c", 205);
        gotoxy(40+x,20);
        printf("%c", 205);
        gotoxy(49,18);
        cprintf("%c", 187);
        gotoxy(49,20);cprintf("%c",188);
        gotoxy(39,20);cprintf("%c",200);
        gotoxy(39,19);cprintf("%c",186);
        gotoxy(49,19);cprintf("%c",186);
    }
    gotoxy(25,19);
    cprintf("Horas Extras:");
}
void Interfaz4(){
	int x;
	for(x = 0 ; x < 40; x++){
		textcolor(YELLOW);
		gotoxy(19,8);
		cprintf("%c", 201);
		gotoxy(20+x,8);
		cprintf("%c", 205);
		gotoxy(60,8);
		cprintf("%c", 187);
		gotoxy(19,12);
		cprintf("%c", 200);
		gotoxy(20+x,12);
		cprintf("%c", 205);
		gotoxy(60,12);
		cprintf("%c", 188);
	}
}
void Interfaz5(){
	int x, y;

	for(x=0;x<50;x++){
		gotoxy(15,5); textcolor(WHITE); cprintf("%c",201);gotoxy(16+x,5);
		cprintf("%c", 205); gotoxy(65,5); cprintf("%c", 187);gotoxy(16+x,9);
		cprintf("%c",205);gotoxy(16+x,21); cprintf("%c",205);

	}
	for(y=0;y<15;y++){
		gotoxy(15,9); cprintf("%c",204); gotoxy(65,9); cprintf("%c",185);
		gotoxy(15,6+y);cprintf("%c",186);
		gotoxy(65,6+y);cprintf("%c",186);
		gotoxy(15,21);cprintf("%c",200);
		gotoxy(65,21);cprintf("%c",188);
	}
	for(x=0;x<29;x++){
        gotoxy(32,6);
        cprintf("%c",201);
        gotoxy(33+x,6);
        cprintf("%c", 205);
        gotoxy(33+x,8);
		cprintf("%c",205);
        gotoxy(61,6);
        cprintf("%c", 187);
        gotoxy(61,8);cprintf("%c",188);
        gotoxy(32,8);cprintf("%c",200);
        gotoxy(32,7);cprintf("%c",186);
        gotoxy(61,7);cprintf("%c",186);
    }
    gotoxy(17,7);
    cprintf("Nombre/Carnet:"); /*32,7*/
}
void Interfaz6(){
	int x;
	for(x=0;x<29;x++){
        gotoxy(29,8);
        cprintf("%c",201);
        gotoxy(30+x,8);
        cprintf("%c", 205);
        gotoxy(30+x,10);
		cprintf("%c",205);
        gotoxy(58,8);
        cprintf("%c", 187);
        gotoxy(58,10);cprintf("%c",188);
        gotoxy(29,10);cprintf("%c",200);
        gotoxy(29,9);cprintf("%c",186);
        gotoxy(58,9);cprintf("%c",186);
    }

	for(x=0;x<29;x++){
        gotoxy(29,11);
        cprintf("%c",201);
        gotoxy(30+x,11);
        cprintf("%c", 205);
        gotoxy(30+x,13);
		cprintf("%c",205);
        gotoxy(58,11);
        cprintf("%c", 187);
        gotoxy(58,13);cprintf("%c",188);
        gotoxy(29,13);cprintf("%c",200);
        gotoxy(29,12);cprintf("%c",186);
        gotoxy(58,12);cprintf("%c",186);
    }
}
void Planilla1(){
	 int x;

    system("cls");
    /*Fondo Pantalla*/
    for(x = 0; x < 78; x++){
        textcolor(BLUE);
        gotoxy(2+x,2);
        cprintf("%c",219);
        gotoxy(2+x,3);
        cprintf("%c",219);
        gotoxy(2+x,4);
        cprintf("%c",219);
        gotoxy(2+x,5);
        cprintf("%c",219);
        gotoxy(2+x,6);
        cprintf("%c",219);
        gotoxy(2+x,7);
        cprintf("%c",219);
        gotoxy(2+x,8);
        cprintf("%c",219);
        gotoxy(2+x,9);
        cprintf("%c",219);
        gotoxy(2+x,10);
        cprintf("%c",219);
        gotoxy(2+x,11);
        cprintf("%c",219);
        gotoxy(2+x,12);
        cprintf("%c",219);
        gotoxy(2+x,13);
        cprintf("%c",219);
        gotoxy(2+x,14);
        cprintf("%c",219);
        gotoxy(2+x,15);
        cprintf("%c",219);
        gotoxy(2+x,16);
        cprintf("%c",219);
        gotoxy(2+x,17);
        cprintf("%c",219);
        gotoxy(2+x,18);
        cprintf("%c",219);
        gotoxy(2+x,19);
        cprintf("%c",219);
        gotoxy(2+x,20);
        cprintf("%c",219);
        gotoxy(2+x,21);
        cprintf("%c",219);
        gotoxy(2+x,22);
        cprintf("%c",219);
        gotoxy(2+x,23);
        cprintf("%c",219);
        gotoxy(2+x,24);
        cprintf("%c",219);
    }
    for(x = 0; x < 74; x++){
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,2);
        cprintf("%c", 201);
        gotoxy(4+x,2);
        cprintf("%c", 205);
        gotoxy(78,2);
		cprintf("%c", 187);

        gotoxy(3,24);
        cprintf("%c", 200);
        gotoxy(4+x,24);
        cprintf("%c", 205);
        gotoxy(78,24);
		cprintf("%c", 188);
    }
    for(x = 0; x < 21; x++){ /*Marco cyan*/
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,3+x);
        cprintf("%c",186);
        gotoxy(78,3+x);
        cprintf("%c", 186);
    }
    for(x = 0; x < 21; x++){ /*Lineas intermedias*/
        gotoxy(12,3+x);
        cprintf("%c", 179);
        gotoxy(28,3+x);
		cprintf("%c", 179);
        gotoxy(40,3+x);
		cprintf("%c", 179);
        gotoxy(48,3+x);
		cprintf("%c", 179);
        gotoxy(61,3+x);
        cprintf("%c", 179);
    }
    for(x = 0; x <73; x++){
        gotoxy(4+x,5);
        cprintf("%c", 196);
    }
    textcolor(YELLOW);
    gotoxy(5,4);
    cprintf("Carnet");
    gotoxy(17,4);
    cprintf("Nombre");
    gotoxy(31,4);
    cprintf("Salario");
    gotoxy(43,3);
    cprintf("HRS");gotoxy(42,4);cprintf("Extra");
    gotoxy(52,3);
    cprintf("Pago D.");gotoxy(53,4);cprintf("HRS");
    gotoxy(65,4);
    cprintf("Comisiones");
}
void Planilla2(){
	int x;
    /*Fondo Pantalla*/
    for(x = 0; x < 78; x++){
        textcolor(BLUE);
        gotoxy(2+x,2);
        cprintf("%c",219);
        gotoxy(2+x,3);
        cprintf("%c",219);
        gotoxy(2+x,4);
        cprintf("%c",219);
        gotoxy(2+x,5);
        cprintf("%c",219);
        gotoxy(2+x,6);
        cprintf("%c",219);
        gotoxy(2+x,7);
        cprintf("%c",219);
        gotoxy(2+x,8);
        cprintf("%c",219);
        gotoxy(2+x,9);
        cprintf("%c",219);
        gotoxy(2+x,10);
        cprintf("%c",219);
        gotoxy(2+x,11);
        cprintf("%c",219);
        gotoxy(2+x,12);
        cprintf("%c",219);
        gotoxy(2+x,13);
        cprintf("%c",219);
        gotoxy(2+x,14);
        cprintf("%c",219);
        gotoxy(2+x,15);
        cprintf("%c",219);
        gotoxy(2+x,16);
        cprintf("%c",219);
        gotoxy(2+x,17);
        cprintf("%c",219);
        gotoxy(2+x,18);
        cprintf("%c",219);
        gotoxy(2+x,19);
        cprintf("%c",219);
        gotoxy(2+x,20);
        cprintf("%c",219);
        gotoxy(2+x,21);
        cprintf("%c",219);
        gotoxy(2+x,22);
        cprintf("%c",219);
        gotoxy(2+x,23);
        cprintf("%c",219);
        gotoxy(2+x,24);
        cprintf("%c",219);
    }
    for(x = 0; x < 74; x++){
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,2);
        cprintf("%c", 201);
        gotoxy(4+x,2);
        cprintf("%c", 205);
        gotoxy(78,2);
		cprintf("%c", 187);

        gotoxy(3,24);
        cprintf("%c", 200);
        gotoxy(4+x,24);
        cprintf("%c", 205);
        gotoxy(78,24);
		cprintf("%c", 188);
    }
    for(x = 0; x < 21; x++){ /*Marco cyan*/
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,3+x);
        cprintf("%c",186);
        gotoxy(78,3+x);
        cprintf("%c", 186);
    }
    for(x = 0; x < 21; x++){ /*Lineas intermedias*/
        gotoxy(12,3+x);
        cprintf("%c", 179);
        gotoxy(28,3+x);
		cprintf("%c", 179);
        gotoxy(40,3+x);
		cprintf("%c", 179);
        gotoxy(52,3+x);
		cprintf("%c", 179);
        gotoxy(64,3+x);
        cprintf("%c", 179);
    }
    for(x = 0; x <73; x++){ /*Linea horizontal*/
        gotoxy(4+x,5);
        cprintf("%c", 196);
    }
    textcolor(YELLOW);
    gotoxy(5,4);
    cprintf("Carnet");
    gotoxy(17,4);
    cprintf("Nombre");
    gotoxy(32,3);
    cprintf("Total");
    gotoxy(31,4);cprintf("Ingresos");
    gotoxy(44,4);
    cprintf("INSS");
    gotoxy(57,4);
    cprintf("IR");
    gotoxy(69,3);
    cprintf("Total");     
    gotoxy(66,4);cprintf("Deducciones");
}
void Planilla3(){
	int x;
    /*Fondo Pantalla*/
    for(x = 0; x < 78; x++){
        textcolor(BLUE);
        gotoxy(2+x,2);
        cprintf("%c",219);
        gotoxy(2+x,3);
        cprintf("%c",219);
        gotoxy(2+x,4);
        cprintf("%c",219);
        gotoxy(2+x,5);
        cprintf("%c",219);
        gotoxy(2+x,6);
        cprintf("%c",219);
        gotoxy(2+x,7);
        cprintf("%c",219);
        gotoxy(2+x,8);
        cprintf("%c",219);
        gotoxy(2+x,9);
        cprintf("%c",219);
        gotoxy(2+x,10);
        cprintf("%c",219);
        gotoxy(2+x,11);
        cprintf("%c",219);
        gotoxy(2+x,12);
        cprintf("%c",219);
        gotoxy(2+x,13);
        cprintf("%c",219);
        gotoxy(2+x,14);
        cprintf("%c",219);
        gotoxy(2+x,15);
        cprintf("%c",219);
        gotoxy(2+x,16);
        cprintf("%c",219);
        gotoxy(2+x,17);
        cprintf("%c",219);
        gotoxy(2+x,18);
        cprintf("%c",219);
        gotoxy(2+x,19);
        cprintf("%c",219);
        gotoxy(2+x,20);
        cprintf("%c",219);
        gotoxy(2+x,21);
        cprintf("%c",219);
        gotoxy(2+x,22);
        cprintf("%c",219);
        gotoxy(2+x,23);
        cprintf("%c",219);
        gotoxy(2+x,24);
        cprintf("%c",219);
    }
    for(x = 0; x < 74; x++){
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,2);
        cprintf("%c", 201);
        gotoxy(4+x,2);
        cprintf("%c", 205);
        gotoxy(78,2);
		cprintf("%c", 187);

        gotoxy(3,24);
        cprintf("%c", 200);
        gotoxy(4+x,24);
        cprintf("%c", 205);
        gotoxy(78,24);
		cprintf("%c", 188);
    }
    for(x = 0; x < 21; x++){ /*Marco cyan*/
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,3+x);
        cprintf("%c",186);
        gotoxy(78,3+x);
        cprintf("%c", 186);
    }
    for(x = 0; x < 21; x++){ /*Lineas intermedias*/
        gotoxy(12,3+x);
        cprintf("%c", 179);
        gotoxy(28,3+x);
		cprintf("%c", 179);
        gotoxy(45,3+x);
		cprintf("%c", 179);
        gotoxy(60,3+x);
		cprintf("%c", 179);
        gotoxy(75,3+x);
        cprintf("%c", 179);
    }
    for(x = 0; x <73; x++){ /*Linea horizontal*/
        gotoxy(4+x,5);
        cprintf("%c", 196);
    }
    textcolor(YELLOW);
    gotoxy(5,4);
    cprintf("Carnet");
    gotoxy(17,4);
    cprintf("Nombre");
    gotoxy(33,3);
    cprintf("Salario");
    gotoxy(35,4);cprintf("Neto");
    gotoxy(51,3);
    cprintf("INSS");
    gotoxy(49,4);cprintf("Patronal");
    gotoxy(65,4);
    cprintf("INATEC");
}
void Credenciales(){
    char Username[Longitud+1];
    char Password[Longitud+1];
    char caracter;
    int i = 0, p;
    int long1;
	bool ingreso;

    do{
		ingreso = false;
        i = 0;
        system("cls");
        fflush(stdin);

		Interfaz2();
		Interfaz6();

        gotoxy(34,4);textcolor(YELLOW);
        cprintf("CREDENCIALES");
		gotoxy(28,5);textcolor(WHITE);
        cprintf("Ingrese sus credenciales");
		gotoxy(29,6);
		cprintf("Intentos permitidos: %i", intento);
		gotoxy(20,9);
        cprintf("Usuario:");
		gotoxy(17,12);
        cprintf("Contrase%ca:",164);
		gotoxy(31,9);

        switch (getch()){
            case ENTER:
                goto intento;
            case ESPACIO:
                goto intento;
            default:
                gets(Username);
            break;
        }

        long1 = strlen(Username);
        if (long1 > 10){
            textcolor(RED);gotoxy(25,15);
            cprintf("(!) El usuario es incorrecto.\n");
			gotoxy(28,16);
			cprintf("(!) Exceso de caracteres.");
            getch();
            goto intento;
        }
		gotoxy(31,12);
        switch (getch()){
             case ENTER:
                 goto intento;
             case ESPACIO:
                 goto intento;
			 default:
				while(caracter = getch())
                 if(caracter == 13){
					 Password[i] = '\0';
                     break;
                 }else if(caracter == 8){
                    if(i > 0){
                         i--;
                         printf("\b \b");
                    }
                 }else{
                    if(i < Longitud){
                     printf("*");
                     Password[i] = caracter;
                     i++;
                    }
                }
             break;
            }

		for (p = 0; p < 3 ; p++){
			textcolor(YELLOW);
			gotoxy(34,15);
			cprintf("Verificando");
			gotoxy(45+p,15);
			cprintf(".");
			delay(800);
		}

        if (strcmp(Username,User) == 0 && strcmp(Password,Pass) == 0){
            ingreso = true;
        }else{

            if(strcmp(Username,User) != 0){
                textcolor(RED);
				gotoxy(27,17);
                cprintf("(!) El usuario es incorrecto.");
                getch();
            }
            if(strcmp(Password,Pass) != 0){
                textcolor(RED);
				gotoxy(28,18);
				cprintf("(!) La clave es incorrecta.");
				getch();
            }

            intento:
            intento--;

            if (intento == 0){
				textcolor(RED+BLINK);gotoxy(22,19);
                cprintf("(!) Fallaste: Credenciales incorrectas.");
				gotoxy(31,20);
                cprintf("(!) Bloqueando acceso.");
				getch();
				Pantallasalida();
            }
        }

    } while (intento > 0 && ingreso != true);

	textcolor(GREEN+BLINK);
	gotoxy(32,17);
	cprintf("ACCESO PERMITIDO");
	delay(2000);
}
void Recaptcha(){
	int recap = 0, numero;
	bool validado;
	int x;

	srand(time(NULL));

	do{
		validado = false;
		system("cls");
		fflush(stdin);

		Interfaz();

		for(x = 0 ; x < 40; x++){
			textcolor(YELLOW);
			gotoxy(19,8);
			cprintf("%c", 201);
			gotoxy(20+x,8);
			cprintf("%c", 205);
			gotoxy(60,8);
			cprintf("%c", 187);
			gotoxy(19,15);
			cprintf("%c", 200);
			gotoxy(20+x,15);
			cprintf("%c", 205);
			gotoxy(60,15);
			cprintf("%c", 188);
		}

		recap = (rand() % 9000 + 1000);

		textcolor(YELLOW);
		gotoxy(35,9);
		cprintf("reCAPTCHA");
		textcolor(WHITE);
		gotoxy(25,11);
		cprintf("Verifica que no eres un robot.\n");
		gotoxy(37,12);
		cprintf("%i", recap);
		gotoxy(26,13);
		cprintf("Codigo en pantalla: ");

		switch (getch()){
             case ENTER:
                 goto intento1;
             case ESPACIO:
                 goto intento1;
             default:
				 scanf("%i", &numero);
             break;
            }

			if (strcmp(recap,numero)==0){
				validado = true;
			}else{
				textcolor(RED);
				gotoxy(28,17);
            	cprintf("(!) reCAPTCHA incorrecto.");
            	getch();

				intento1:
				errores--;

				if(errores == 0){
					textcolor(RED+BLINK);
					gotoxy(25,17);
        	    	cprintf("(!) Fallaste: Muchos intentos.");
					gotoxy(29,18);
        	    	cprintf("(!) Bloqueando acceso.");
       	     		getch();
        	    	Pantallasalida();
				}
			}
	}while(validado != true);

	textcolor(GREEN+BLINK);
	gotoxy(32,17);
	cprintf("ACCESO PERMITIDO");
	delay(2000);
}
void BuscarT(){
	int C = 0;
	system("cls");

	Interfaz();
	Interfaz5();
	fflush(stdin);
	textcolor(WHITE);

	gotoxy(34,3); textcolor(YELLOW);
	cprintf("B U S C A R");
	gotoxy(34,7);
	gets(ResultadoN);
	C = atoi(ResultadoN);

	for (i = 0; i < Cantidad; i++){
		if((strcmp(Nombre[i], ResultadoN) == 0) || C==Empleado[i].Carnet){
			Buscar = true;
			Busqueda[Posicion] = i;
			strcpy(Auxiliar[Posicion],Nombre[i]);
			CarnetAux[Posicion] = Empleado[i].Carnet;
			Posicion++;
		}
	}
}
void Resultados(){
	Interfaz5();
	gotoxy(30,10); textcolor(YELLOW);
	cprintf("R e s u l t a d o s");
	if(Buscar == true){
		textcolor(WHITE);
		gotoxy(18,11);cprintf("No.");
		gotoxy(25,11);cprintf("Nombre");
		gotoxy(50,11);cprintf("Carnet");
		for (j = 0; j < Posicion; j++){
			gotoxy(18,13+j);
			cprintf("%i.", j+1);

			gotoxy(25,13+j);
			cprintf("%s", Auxiliar[j]);

			gotoxy(52,13+j);
			cprintf("%iU", CarnetAux[j]);
		}
	}else{
		gotoxy(28,10);
		cprintf("No se encontraron datos :(");
	}
	Buscar = false;
	Posicion = 0;
	ResultadoN = '\0';
getch();
}
void IngresarT(){
	int p, lon = 0, sw = 0, i = 0 , n;
	char opc, numero[20];
	int CantidadFull = 0;
	float AuxSalario = 0;

	system("cls");
	fflush(stdin);
	do{
		system("cls");
		Interfaz();
		fflush(stdin);
		if(Cantidad < MAXTRABAJADORES){
			gotoxy(33,3); textcolor(YELLOW);
			cprintf("A G R E G A R");
			Interfaz3();
	
		do{
			gotoxy(32,7);
			gets(Nombre[Cantidad]);
			sw = validar_cadena(Nombre[Cantidad]);
			lon = strlen(Nombre[Cantidad]);
			if (lon > 10 || sw != 0){
				for (i = 0; i < lon; i++)
				{
					gotoxy(33 + i, 7);
					printf("\b \b");
				}
			}
		}while (sw != 0);

			gotoxy(39, 11);
			scanf("%f", &AuxSalario);

		Empleado[Cantidad].Salario = AuxSalario;

		do{
			do{
				gotoxy(39, 15);
				scanf("%s", numero);
				n = validar_numero(numero);
				Empleado[Cantidad].Comisiones = atoi(numero);
				lon = strlen(numero);
				if (lon > 10 || n == 0){
					for (i = 0; i < lon; i++){
						gotoxy(40 + i, 15);
						printf("\b \b");
					}
				}
			} while (n == 0);
		} while (Empleado[Cantidad].Comisiones < 0);

		do{
			do{
				gotoxy(41, 19);
				scanf("%s", numero);
				n = validar_numero(numero);
				Empleado[Cantidad].Horas_extra = atoi(numero);
				lon = strlen(numero);
				if (lon > 10 || n == 0){
					for (i = 0; i < lon; i++){
						gotoxy(42 + i, 19);
						printf("\b \b");
					}
				}
			} while (n == 0);
		} while (Empleado[Cantidad].Horas_extra < 0);

			for (p = 0; p < 3 ; p++){
			textcolor(YELLOW);
			gotoxy(33,21);
			cprintf("Creando Perfil");
			gotoxy(47+p,21);
			cprintf(".");
			delay(800);
			}
			textcolor(YELLOW);
			gotoxy(28,22);
			cprintf("Registrado correctamente!");
			sleep(1);

			CalculoPlanilla(Cantidad);

			ContadorCarnet++;
			Empleado[Cantidad].Carnet = ContadorCarnet;
			Cantidad++;
		}else{
			Interfaz4();
			gotoxy(21,10);
			cprintf("El numero de registros esta completo.");
			CantidadFull = 1;
			getch();
		}

		if(CantidadFull == 0){
			system("cls");
			Interfaz();
			Interfaz4();
			gotoxy(25,9);
			cprintf("Desea ingresar otro trabajador?");
			textcolor(WHITE);
			gotoxy(35,11);
			cprintf("%cSi o No?",168);
			do{
				opc = getch();
			} while (tolower(opc) != 'n' && tolower(opc) != 's');
		}else{
			opc = 'n';
		}
	} while (tolower(opc) != 'n');
}
void ActualizarT(){
	int opc, x, p, i = 0, n = 0, lon = 0;
	char numero[20];
	float AuxSalario;

	BuscarT();
	Interfaz();
	gotoxy(31,3); textcolor(YELLOW);
	cprintf("A C T U A L I Z A R");
	if(Buscar == true){
		gotoxy(30,10); textcolor(YELLOW);
		cprintf("R e s u l t a d o s");
		textcolor(WHITE);
		gotoxy(18,11);cprintf("No.");
		gotoxy(25,11);cprintf("Nombre");
		gotoxy(50,11);cprintf("Carnet");

		for (j = 0; j < Posicion; j++){
			gotoxy(18,13+j);
			cprintf("%i.", j+1);

			gotoxy(25,13+j);
			cprintf("%s", Auxiliar[j]);

			gotoxy(52,13+j);
			cprintf("%iU", CarnetAux[j]);
		}
		textcolor(YELLOW);
		gotoxy(16,22);
		cprintf("Presione el numero del trabajador a actualizar: ");scanf("%d", &opc);

		opc = opc - 1;
		x = Busqueda[opc];
		system("cls");
		fflush(stdin);
		Interfaz();

		gotoxy(31,3); textcolor(YELLOW);
		cprintf("A C T U A L I Z A R");
		Interfaz3();

		gotoxy(32,7);
		gets(Actualizar);

		gotoxy(39, 11);
		scanf("%f", &AuxSalario);

		Empleado[x].Salario = AuxSalario;

		do{
			do{
				gotoxy(39, 15);
				scanf("%s", numero);
				n = validar_numero(numero);
				Empleado[x].Comisiones = atoi(numero);
				lon = strlen(numero);
				if (lon > 10 || n == 0){
					for (i = 0; i < lon; i++){
						gotoxy(40 + i, 15);
						printf("\b \b");
					}
				}
			} while (n == 0);
		} while (Empleado[x].Comisiones < 0);

		do{
			do{
				gotoxy(41, 19);
				scanf("%s", numero);
				n = validar_numero(numero);
				Empleado[x].Horas_extra = atoi(numero);
				lon = strlen(numero);
				if (lon > 10 || n == 0){
					for (i = 0; i < lon; i++){
						gotoxy(42 + i, 19);
						printf("\b \b");
					}
				}
			} while (n == 0);
		} while (Empleado[x].Horas_extra < 0);

		for (p = 0; p < 3 ; p++){
			textcolor(YELLOW);
			gotoxy(30,21);
			cprintf("Actualizando Perfil");
			gotoxy(49+p,21);
			cprintf(".");
			delay(800);
		}
		gotoxy(27,22);
		cprintf("Actualizado correctamente!");
		delay(1000);

		CalculoPlanilla(x);

		strcpy(Nombre[x], Actualizar);
	}else{
		gotoxy(28,10);
		cprintf("No se encontraron datos :(");
		getch();
	}
	Buscar = false;
	Posicion = 0;
	ResultadoN = '\0';
}
void EliminarT(){
	int opc, i, x;

	BuscarT();
	Interfaz();
	gotoxy(33,3); textcolor(YELLOW);
	cprintf("E L I M I N A R");
	if(Buscar == true){
		gotoxy(30,10); textcolor(YELLOW);
		cprintf("R e s u l t a d o s");
		textcolor(WHITE);
		gotoxy(18,11);cprintf("No.");
		gotoxy(25,11);cprintf("Nombre");
		gotoxy(50,11);cprintf("Carnet");

		for (j = 0; j < Posicion; j++){
			gotoxy(18,13+j);
			cprintf("%i.", j+1);

			gotoxy(25,13+j);
			cprintf("%s", Auxiliar[j]);

			gotoxy(52,13+j);
			cprintf("%iU", CarnetAux[j]);
		}

		textcolor(YELLOW);
		gotoxy(16,22);
		cprintf("Presione el numero del trabajador a");
		textcolor(RED);
		gotoxy(52,22);
		cprintf("eliminar: ");scanf("%d", &opc);

		opc -= 1;
		x = Busqueda[opc];
		
		for(i = x; i < Cantidad; i++){
			strcpy(Nombre[i],Nombre[i+1]);
			Empleado[i].Salario = Empleado[i+1].Salario;
			Empleado[i].Comisiones = Empleado[i+1].Comisiones;
			Empleado[i].Horas_extra = Empleado[i+1].Horas_extra;
			Empleado[i].Carnet = Empleado[i+1].Carnet;                  
			Empleado[i].PagoHoraExtra = Empleado[i+1].PagoHoraExtra;
			Empleado[i].TotalIngreso = Empleado[i+1].TotalIngreso;
			Empleado[i].TotalDeducciones = Empleado[i+1].TotalDeducciones;
			Empleado[i].IR = Empleado[i+1].IR;                        
			Empleado[i].Neto = Empleado[i+1].Neto;
			Empleado[i].INSS = Empleado[i+1].INSS;
			Empleado[i].INSSPatrol = Empleado[i+1].INSSPatrol;
			Empleado[i].INATEC = Empleado[i+1].INATEC;
		}
		Cantidad--;
	}else{
		gotoxy(28,10);
		cprintf("No se encontraron datos :(");
		getch();
	}
	Buscar = false;
	Posicion = 0;
	ResultadoN = '\0';
}
void Planilla(){
	system("cls");
	Planilla1();
	  	for(i = 0; i < Cantidad; i++){
			textcolor(WHITE);

			gotoxy(7,7+i);
			cprintf("%iU", Empleado[i].Carnet);

			gotoxy(14,7+i);
        	cprintf("%s", Nombre[i]);

			gotoxy(29,7+i);
			cprintf("C%c%.2f",36, Empleado[i].Salario);

			gotoxy(43,7+i);
			cprintf("%i", Empleado[i].Horas_extra);

			gotoxy(51,7+i);
			cprintf("C%c%i",36,Empleado[i].PagoHoraExtra);

			gotoxy(66,7+i);
			cprintf("C%c%i",36, Empleado[i].Comisiones);
    	}
	getch();
	system("cls");
	Planilla2();
		for(i = 0; i < Cantidad; i++){
			textcolor(WHITE);

			gotoxy(7,7+i);
			cprintf("%iU", Empleado[i].Carnet);

			gotoxy(14,7+i);
        	cprintf("%s", Nombre[i]);

			gotoxy(29,7+i);
			cprintf("C%c%.2f",36, Empleado[i].TotalIngreso);

			gotoxy(42,7+i);
			cprintf("C%c%.2f",36,Empleado[i].INSS);

			gotoxy(54,7+i);
			cprintf("C%c%.2f",36,Empleado[i].IR);

			gotoxy(66,7+i);
			cprintf("C%c%.2f",36,Empleado[i].TotalDeducciones);
		}
	getch();
	system("cls");
	Planilla3();
		for(i = 0; i < Cantidad; i++){
			textcolor(WHITE);
			gotoxy(14,7+i);
        	cprintf("%s", Nombre[i]);

			gotoxy(7,7+i);
			cprintf("%iU", Empleado[i].Carnet);

			gotoxy(31,7+i);
			cprintf("C%c%.2f",36,Empleado[i].Neto);

			gotoxy(48,7+i);
			cprintf("C%c%.2f",36,Empleado[i].INSSPatrol);

			gotoxy(63,7+i);
			cprintf("C%c%.2f",36,Empleado[i].INATEC);
		}
getch();
system("cls");
}
void Pantallasalida(){
	int x, a, y, z;
	for(y = 0; y < 33 ; y++){
		textcolor(WHITE);
		gotoxy(23,9);
		cprintf("%c", 201);
		gotoxy(24+y,9);
		cprintf("%c", 205);
		gotoxy(57,9);
		cprintf("%c", 187);
		gotoxy(23,16);
		cprintf("%c", 200);
		gotoxy(24+y,16);
		cprintf("%c", 205);
		gotoxy(57,16);
		cprintf("%c", 188);
	}
	for(z = 0; z < 6; z++){
		textcolor(WHITE);
		gotoxy(23,10+z);
		cprintf("%c", 186);
		gotoxy(57,10+z);
		cprintf("%c", 186);
	}
	for(a = 0; a < 6; a++){
		textcolor(BLACK);
		gotoxy(24,10+a);
		cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
	}
	for(x = 0; x < 3 ; x++){
		textcolor(RED);
		gotoxy(29,12);
		cprintf("Terminando Ejecuci%cn", 162);
		gotoxy(50+x,12);
		cprintf(".");
		delay(1000);
	}
exit(EXIT_SUCCESS);
}
void CalculoPlanilla(int i){
	float temporal = 0, Aplicable = 0, Exceso = 0, ImpuestoB = 0;

	/*Hora Extra*/
	Empleado[i].PagoHoraExtra = (Empleado[i].Salario)/120 * (Empleado[i].Horas_extra);
	/*Total Ingreso*/
	Empleado[i].TotalIngreso = (Empleado[i].Salario + Empleado[i].PagoHoraExtra + Empleado[i].Comisiones);
	/*INSS LABORAL*/
	Empleado[i].INSS = (Empleado[i].TotalIngreso * 0.07);
	/*Tabla IR*/
	temporal = (Empleado[i].TotalIngreso - Empleado[i].INSS);
	temporal = temporal * 12;

	if(temporal <= Limite1){
		ImpuestoB = 0;
		Aplicable = 0;
		Exceso = 0;
	}else{
		if(temporal <= Limite2){
			ImpuestoB = 0;
			Aplicable = 0.15;
			Exceso = 100000L;
		}else{
			if(temporal <= Limite3){
				ImpuestoB = 15000L;
				Aplicable = 0.20;
				Exceso = 200000L;
			}else{
				if(temporal <= Limite4){
					ImpuestoB = 45000L;
					Aplicable = 0.25;
					Exceso = 350000L;
				}else{
					if(temporal > Limite4){
						ImpuestoB = 82500L;
						Aplicable = 0.30;
						Exceso = 500000L;
					}
				}
			}
		}
	}
	/*IR*/
	Empleado[i].IR = ((((temporal - Exceso) * Aplicable) + ImpuestoB) / 12);
	/*Total deducciones*/
	Empleado[i].TotalDeducciones = (Empleado[i].IR + Empleado[i].INSS);
	/*Neto a recibir*/
	Empleado[i].Neto = (Empleado[i].TotalIngreso - Empleado[i].TotalDeducciones);
	/*Inss Patronal*/
	Empleado[i].INSSPatrol = (Empleado[i].TotalIngreso * 0.225);
	/*INACTEC*/
	Empleado[i].INATEC = (Empleado[i].Salario * 0.02);
}
int validar_numero(char numero[]){
	int i;
	for (i = 0; i < strlen(numero); i++){
		if (!(isdigit(numero[i]))){
			return 0;
		}
	}
return 1;
}
int validar_cadena(char cadena[]){
	int i = 0, sw = 0, j;
	j = strlen(cadena);
	while (i < j && sw == 0){
		if (isalpha(cadena[i]) != 0){
			i++;
		}
		else{
			sw = 1;
		}
	}
return sw;
}