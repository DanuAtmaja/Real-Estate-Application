#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define max 20

const char putih=15, kuning=14,  merah=12, sky=11, hijau=10, biru=9, abu=8;
const char abuX=7, kuningX=6, unguX=5, merahX=4, skyX=3, hijauX=2, biruX=1, hitam=0;

const int	tl=201,		tr=187,		bl=200,		 br=188,	h=205,	v=186,		o=219;																															  /**/
const int	C4=206,		Tu=203,		Td=202,		 Tl=204,	Tr=185;																																				  /**/
const int	u=24,		d=25,		r=26,		 l=27;																																							  /**/


const int Up=72, Down=80, Left=75, Right=77;
const int esc=27, enter=13, backspace=8, tab=9;

typedef char string[200];

//--------------------------------------------------------------------
///DATA STRUCT PROPERTY
typedef struct{

	int no;
	string jenis;
	string status;
	double harga;
	int ketersediaan;

}Property;

typedef struct nodeProperty *addressProperty;
typedef struct nodeProperty{
    
    Property data;
    addressProperty next;
    
}nodeProperty;

typedef struct{
    
    addressProperty first;
     
}ListProperty;


//DATA STRUCT SALES
typedef struct{

	string nama;
	string ID;

}Sales;

typedef struct nodeSales *addressSales;
typedef struct nodeSales{
    
    Sales data;
    addressSales next;
    
}nodeSales;

typedef struct{
    
    addressSales first;
     
}ListSales;


//DATA STRUCT TRANSAKSI
typedef struct 
{
	string ID;
	Property unit;
	double hargaK;
	string lamaSewa;
	string nama;
	string alamat;
	string noTlp;
}Transaksi;

typedef struct nodeTransaksi *addressTransaksi;
typedef struct nodeTransaksi{
    
    Transaksi data;
    addressTransaksi next;
    
}nodeTransaksi;

typedef struct{
    
    addressTransaksi first;
     
}ListTransaksi;


//----------------------------------------------------------------------------------------
//PROSEDUR PROPERTY
void createEmptyProperty(ListProperty &LP);
void insertFirstProperty(ListProperty &LP, addressProperty newNode);
void insertAfterProperty(addressProperty before, addressProperty newNode);
void insertLastProperty(ListProperty &LP, addressProperty newNode);
void deleteFirstProperty(ListProperty &LP);
void deleteAtProperty(ListProperty &LP, addressProperty del);
void deleteLastProperty(ListProperty &LP);

void printDataProperty(ListProperty LP);
void printDataPropertyTersedia(ListProperty LP);
addressProperty findNodeProperty(ListProperty LP, int no);

bool isEmptyProperty(ListProperty LP);

bool isOneElementProperty(ListProperty LP);

addressProperty alokasiProperty(Property X);

int isKetersediaanHabis(ListProperty LP);



//PROSEDUR SALES
void createEmptySales(ListSales &LS);
void insertFirstSales(ListSales &LS, addressSales newNode);
void insertAfterSales(addressSales before, addressSales newNode);
void insertLastSales(ListSales &LS, addressSales newNode);
void deleteFirstSales(ListSales &LS);
void deleteAtSales(ListSales &LS, addressSales del);
void deleteLastSales(ListSales &LS);

void printDataSales(ListSales LS);
addressSales findNodeSales(ListSales LS, string ID);

bool isEmptySales(ListSales LS);

bool isOneElementSales(ListSales LS);

addressSales alokasiSales(Sales X);

int isFoundSales(ListSales LS, string ID);

int isFoundInTrans(ListTransaksi LT, string ID);



//PROSEDUR TRANSAKSI
void createEmptyTransaksi(ListTransaksi &LT);
void insertFirstTransaksi(ListTransaksi &LT, addressTransaksi newNode);
void insertAfterTransaksi(addressTransaksi before, addressTransaksi newNode);
void insertLastTransaksi(ListTransaksi &LT, addressTransaksi newNode);
void deleteFirstTransaksi(ListTransaksi &LT);
void deleteAtTransaksi(ListTransaksi &LT, addressTransaksi del);
void deleteLastTransaksi(ListTransaksi &LT);

void printDataDijual(ListTransaksi LT);
void printDataDisewakan(ListTransaksi LT);
void printDataTransaksi(ListTransaksi LT);
addressTransaksi findNodeTransaksi(ListTransaksi LT, int no);
addressTransaksi findNodeTransaksiID(ListTransaksi LT, string ID);

bool isEmptyTransaksi(ListTransaksi LT);

bool isOneElementTransaksi(ListTransaksi LT);

addressTransaksi alokasiTransaksi(Transaksi X);

int hitungbeli(ListTransaksi LT);
int hitungsewa(ListTransaksi LT);


//---------------------------------------------------------------------------------
//SORTING PROPERTY //blm fix//
void swapProperty(addressProperty &a, addressProperty &b);
void bubbleSortProperty(ListProperty &LP);


//CREATE EMPTY
void createEmptystructTransaksi(Transaksi &T);
void createEmptystructSales(Sales &S);
void createEmptystructProperty(Property &P);


//REPORTS FUNCTIONS
void PendapatanSales(ListSales LS, ListTransaksi LT);
double hitungPedapatanSales(ListTransaksi LT, string ID);
void totalPendapatan(ListTransaksi LT);
void printPropertyYangLaku(ListTransaksi LT);
void printPropertyTiapSales(ListSales LS, ListTransaksi LT);
void printPropetyBelumLaku(ListTransaksi LT);
void hitunglama(ListTransaksi(LT));



//VISUAL CONSOLE
void gotoxy(int x, int y);
void hidecursor();
void showcursor();

//void set
void setcolor(char text, char background);
void set_layar_console(int WIDTH,int HEIGHT);
void tabel(int x, int y);
void set_logo_gedung();
void set_daftar_menuUtama();
void set_ket_menuUtama(int &ket);
void set_daftar_menu1();	
void set_ket_menu1(int &ket);
void set_daftar_menu2();	
void set_ket_menu2(int &ket);
void set_daftar_menu3();	
void set_ket_menu3(int &ket);

void setTable(int xStart, int yStart,string field[max], int sumOfField, int sumOfRecord, char textField, char backgroundField, char textRecord, char backgroundRecord);
void set_daftar_laporan();
void set_ket_laporan(int &ket,ListSales LS,ListTransaksi LT);

void setInputBox();
void set_Judul();
void highligh_select_menuUtama(int &y1, int &y2, int &y3);
void highligh_select(int &y1, int &y2, int &y3);
void setInputBox_PembelianProperty();
void laporan_totalPendapatan(ListTransaksi LT);
void highligh_select_laporan(int &y1, int &y2, int &y3);
void laporan_PendapatanSales(ListSales LS, ListTransaksi LT);
//FILE HANDLING
