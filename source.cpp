#include "header.h"



//----------------------------------------------------------------------------------------
//PROSEDUR PROPERTY
void createEmptyProperty(ListProperty &LP)
{
	LP.first=NULL;
}
void insertFirstProperty(ListProperty &LP, addressProperty newNode)
{
	newNode->next=LP.first;
	LP.first=newNode;
}
void insertAfterProperty(addressProperty before, addressProperty newNode)
{
	if(before!=NULL)
	{
		newNode->next=before->next;
		before->next=newNode;
	}
}
void insertLastProperty(ListProperty &LP, addressProperty newNode)
{
	if(isEmptyProperty(LP)) 
		insertFirstProperty(LP,newNode);
	else
	{
		for(addressProperty P=LP.first; P->next!=NULL; P=P->next);
		P->next=newNode;
	}
}
void deleteFirstProperty(ListProperty &LP)
{
	if(!isEmptyProperty(LP))
	{
		addressProperty del=LP.first;
		LP.first=LP.first->next;
		delete(del);
	}
}
void deleteAtProperty(ListProperty &LP, addressProperty del)
{
	if(!isEmptyProperty(LP))
	{
	if(LP.first==del)
		deleteFirstProperty(LP);
		else
		{
			for(addressProperty P=LP.first; P->next!=NULL && P->next!=del; P=P->next);

			if(P->next==del)
			{
				P->next=del->next;
				delete(del);
			}
		}
	}
}
void deleteLastProperty(ListProperty &LP)
{
	if(!isEmptyProperty(LP))
	{
		if(isOneElementProperty(LP)) 
			deleteFirstProperty(LP);
		else
		{
			for(addressProperty P=LP.first; P->next->next!=NULL; P=P->next);
			delete(P->next);

		}
	}
}

void printDataProperty(ListProperty LP)
{
	string fieldTableProperty[max] = {"No","   Jenis   ", "  Status  ", "  Harga Awal  "};
	setTable(70,2,fieldTableProperty,4,19,biru,kuning,biru,kuning);

	int i=0, y=5;
	for(addressProperty P=LP.first; P!=NULL; P=P->next)
	{
			
		gotoxy(72,y+i); cout<<P->data.no<<endl;
		gotoxy(80,y+i); cout<<P->data.jenis<<endl;
		gotoxy(91,y+i); cout<<P->data.status<<endl;
		gotoxy(105,y+i); cout<<P->data.harga<<endl;
		i++;
		
	}
	cout<<endl;
}

void printDataPropertyTersedia(ListProperty LP)
{
	string fieldTableProperty[max] = {"No","   Jenis   ", "  Status  ", "  Harga Awal  "};
	setTable(70,2,fieldTableProperty,4,19,biru,kuning,biru,kuning);

	int i=0, y=5;
	for(addressProperty P=LP.first; P!=NULL; P=P->next)
	{
		if(P->data.ketersediaan==1){
			
			gotoxy(72,y+i); cout<<P->data.no<<endl; 
			gotoxy(80,y+i); cout<<P->data.jenis<<endl;
			gotoxy(91,y+i); cout<<P->data.status<<endl;
			gotoxy(105,y+i); cout<<P->data.harga<<endl;
			i++;
		}
	}
	cout<<endl;
}
	
addressProperty findNodeProperty(ListProperty LP, int no)
{
	for(addressProperty P=LP.first; P!=NULL&&P->data.no!=no; P=P->next);
	return P;
}

bool isEmptyProperty(ListProperty LP)
{
	return LP.first==NULL;
}

bool isOneElementProperty(ListProperty LP)
{
	return !isEmptyProperty(LP) && LP.first->next==NULL;
}

addressProperty alokasiProperty(Property X)
{
	addressProperty P=new(nodeProperty);

	if(P!=NULL)
	{
		P->data=X;
		P->next=NULL;
	}
	return P;
}

int isKetersediaanHabis(ListProperty LP){

	for(addressProperty P=LP.first; P!=NULL; P=P->next)
	{
		if(P->data.ketersediaan==1){
			
			return 0;
		}
	}

	return 1;
}





//------------------------------------------------------------------------------------
//PROSEDUR SALES
void createEmptySales(ListSales &LS)
{
	LS.first=NULL;
}
void insertFirstSales(ListSales &LS,addressSales newNode)
{
	newNode->next=LS.first;
	LS.first=newNode;
}
void insertAfterSales(addressSales before, addressSales newNode)
{
	if(before!=NULL)
	{
		newNode->next=before->next;
		before->next=newNode;
	}
}
void insertLastSales(ListSales &LS, addressSales newNode)
{
	if(isEmptySales(LS)) 
		insertFirstSales(LS,newNode);
	else
	{
		for(addressSales P=LS.first; P->next!=NULL; P=P->next);
		P->next=newNode;
	}
}
void deleteFirstSales(ListSales &LS)
{
	if(!isEmptySales(LS))
	{
		addressSales del=LS.first;
		LS.first=LS.first->next;
		delete(del);
	}
}
void deleteAtSales(ListSales &LS, addressSales del)
{
	if(!isEmptySales(LS))
	{
	if(LS.first==del)
		deleteFirstSales(LS);
		else
		{
			for(addressSales P=LS.first; P->next!=NULL && P->next!=del; P=P->next);

			if(P->next==del)
			{
				P->next=del->next;
				delete(del);
			}
		}
	}
}
void deleteLastSales(ListSales &LS)
{
	if(!isEmptySales(LS))
	{
		if(isOneElementSales(LS)) 
			deleteFirstSales(LS);
		else
		{
			for(addressSales P=LS.first; P->next->next!=NULL; P=P->next);
			delete(P->next);

		}
	}
}

void printDataSales(ListSales LS)
{
	string fieldTableSales[max] = {"ID        ","          Nama        "};

	setTable(80,2,fieldTableSales,2,19,biru,kuning,biru,kuning);

	int i=0,y=5;

	for(addressSales P=LS.first; P!=NULL; P=P->next)
	{
		gotoxy(82,y+i);printf("%s",P->data.ID);
		gotoxy(94,y+i);printf("%s",P->data.nama);
		i++;
	}
	
	
	cout<<endl;
}

addressSales findNodeSales(ListSales LS, string ID)
{
	for(addressSales P=LS.first; P!=NULL&&strcmpi(P->data.ID,ID)!=0; P=P->next);
	return P;
}

bool isEmptySales(ListSales LS)
{
	return LS.first==NULL;
}

bool isOneElementSales(ListSales LS)
{
	return !isEmptySales(LS) && LS.first->next==NULL;
}

addressSales alokasiSales(Sales X)
{
	addressSales P=new(nodeSales);

	if(P!=NULL)
	{
		P->data=X;
		P->next=NULL;
	}
	return P;
}

int isFoundSales(ListSales LS, string ID){

	addressSales temp = LS.first;

	while(temp!=NULL){

		if(strcmpi(temp->data.ID,ID)==0)
			return 1;

		temp = temp->next;
	}

	return 0;
}

int isFoundInTrans(ListTransaksi LT, string ID){

	addressTransaksi temp = LT.first;

	while(temp!=NULL){

		if(strcmpi(temp->data.ID,ID)==0)
			return 1;

		temp = temp->next;
	}

	return 0;

}


//-------------------------------------------------------------------------------------------
//PROSEDUR TRANSAKSI
void createEmptyTransaksi(ListTransaksi &LT)
{
	LT.first=NULL;
}
void insertFirstTransaksi(ListTransaksi &LT, addressTransaksi newNode)
{
	newNode->next=LT.first;
	LT.first=newNode;
}
void insertAfterTransaksi(addressTransaksi before, addressTransaksi newNode)
{
	if(before!=NULL)
	{
		newNode->next=before->next;
		before->next=newNode;
	}
}
void insertLastTransaksi(ListTransaksi &LT, addressTransaksi newNode)
{
	if(isEmptyTransaksi(LT)) 
		insertFirstTransaksi(LT,newNode);
	else
	{
		for(addressTransaksi P=LT.first; P->next!=NULL; P=P->next);
		P->next=newNode;
	}
}

void deleteFirstTransaksi(ListTransaksi &LT)
{
	if(!isEmptyTransaksi(LT))
	{
		addressTransaksi del=LT.first;
		LT.first=LT.first->next;
		delete(del);
	}
}

void deleteAtTransaksi(ListTransaksi &LT, addressTransaksi del)
{
	if(!isEmptyTransaksi(LT))
	{
	if(LT.first==del)
		deleteFirstTransaksi(LT);
		else
		{
			for(addressTransaksi P=LT.first; P->next!=NULL && P->next!=del; P=P->next);

			if(P->next==del)
			{
				P->next=del->next;
				delete(del);
			}
		}
	}
}

void deleteLastTransaksi(ListTransaksi &LT)
{
	if(!isEmptyTransaksi(LT))
	{
		if(isOneElementTransaksi(LT)) 
			deleteFirstTransaksi(LT);
		else
		{
			for(addressTransaksi P=LT.first; P->next->next!=NULL; P=P->next);
			delete(P->next);

		}
	}
}


void printDataDijual(ListTransaksi LT){

	string fieldTableDijual[max] ={"ID Sales", "No", " Jenis", "Harga", "Status"};
	setTable(65,2,fieldTableDijual,5,19,biru,kuning,biru,kuning);
	int i=0, y=5;
	for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
	{
		if(strcmpi(P->data.unit.status,"dijual")==0 && P->data.hargaK==0){

			gotoxy(67,y+i); cout<<P->data.ID<<endl;
			gotoxy(78,y+i); cout<<P->data.unit.no<<endl;
			gotoxy(82,y+i); cout<<P->data.unit.jenis<<endl;
			gotoxy(92,y+i); cout<<P->data.unit.harga<<endl;
			gotoxy(99,y+i); cout<<P->data.unit.status<<endl;
		}
	}
	cout<<endl;
}

void printDataDisewakan(ListTransaksi LT){

	string fieldTableDisewakan[max] ={"ID Sales", "No", " Jenis", "Harga", "Status"};
	setTable(65,2,fieldTableDisewakan,5,19,biru,kuning,biru,kuning);
	int i=0, y=5;
	for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
	{
		if(strcmpi(P->data.unit.status,"disewakan")==0 && P->data.hargaK==0){

			gotoxy(67,y+i); cout<<P->data.ID<<endl;
			gotoxy(78,y+i); cout<<P->data.unit.no<<endl;
			gotoxy(82,y+i); cout<<P->data.unit.jenis<<endl;
			gotoxy(92,y+i); cout<<P->data.unit.harga<<endl;
			gotoxy(99,y+i); cout<<P->data.unit.status<<endl;
		}
	}
	cout<<endl;
}

void printDataTransaksi(ListTransaksi LT){

	string fieldTableDisewakan[max] ={"ID Sales", "No", " Jenis", "Harga", "Status   "};
	setTable(65,2,fieldTableDisewakan,5,19,biru,kuning,biru,kuning);
	int i=0, y=5;
	for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
	{
			gotoxy(67,y+i); cout<<P->data.ID<<endl;
			gotoxy(78,y+i); cout<<P->data.unit.no<<endl;
			gotoxy(82,y+i); cout<<P->data.unit.jenis<<endl;
			gotoxy(92,y+i); cout<<P->data.unit.harga<<endl;
			gotoxy(100,y+i); cout<<P->data.unit.status<<endl;

			i++;
	}
	cout<<endl;
}

int hitungbeli(ListTransaksi LT)
{
	int i=0;

	for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
	{
		if(strcmpi(P->data.unit.status,"dijual")==0 && P->data.hargaK==0)
		{
			i++;
		}
	}

	if(i==0)
	{
		return 0;
	}

	return 1;
}

int hitungsewa(ListTransaksi LT)
{
	int i=0;

	for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
	{
		if(strcmpi(P->data.unit.status,"disewakan")==0  && P->data.hargaK==0)
		{
			i++;
		}
	}

	if(i==0)
	{
		return 0;
	}

	return 1;
}
addressTransaksi findNodeTransaksi(ListTransaksi LT, int no){

	for(addressTransaksi P=LT.first; P!=NULL&&P->data.unit.no!=no; P=P->next);
	return P;
}

addressTransaksi findNodeTransaksiID(ListTransaksi LT, string ID){

	for(addressTransaksi P=LT.first; P!=NULL&& strcmpi(P->data.ID,ID)!=0; P=P->next);
	return P;
}

bool isEmptyTransaksi(ListTransaksi LT)
{
	return LT.first==NULL;
}
bool isOneElementTransaksi(ListTransaksi LT)
{
	return !isEmptyTransaksi(LT) && LT.first->next==NULL;
}

addressTransaksi alokasiTransaksi(Transaksi X)
{
	addressTransaksi P=new(nodeTransaksi);

	if(P!=NULL)
	{
		P->data=X;
		P->next=NULL;
	}
	return P;
}










//---------------------------------------------------------------------------------
//SORTING PROPERTY //blm fix//
void swapProperty(addressProperty &a, addressProperty &b)
{
    addressProperty temp=a;
    a=b;
    b=temp;
}

void bubbleSortProperty(ListProperty &LP)
{
   
	addressProperty temp = LP.first, banding = LP.first;

	banding = banding->next;

	while(temp!=NULL){

		while(banding!=NULL){

			if(temp->data.no > banding->data.no){

				swapProperty(temp,banding);

			}

			banding = banding->next;
		}

		temp = temp->next;
	}

	for(addressProperty P=LP.first; P!=NULL; P=P->next)
	{
		
		cout<<"No         : "<<P->data.no<<endl;
		cout<<"Jenis      : "<<P->data.jenis<<endl;
		cout<<"Status     : "<<P->data.status<<endl;
		cout<<"Harga Awal : "<<P->data.harga<<endl;
		cout<<endl;

	}
	cout<<endl;
}



//----------------------------------------------------------------
//Create Empty Struct
void createEmptystructTransaksi(Transaksi &T){

	strcpy(T.alamat,"-");
	strcpy(T.nama,"-");
	strcpy(T.ID,"-");
	T.hargaK=0;
	strcpy(T.noTlp,"-");
	strcpy(T.lamaSewa,"-");
}
void createEmptystructSales(Sales &S){
	strcpy(S.ID,"-");
	strcpy(S.nama,"-");
}
void createEmptystructProperty(Property &P){

	strcpy(P.status,"-");
	strcpy(P.jenis,"-");
	P.no=0;
	P.harga=0;
	P.ketersediaan=1;
}


//-------------------------------------------------------------------------------
//REPORTS FUNCTIONS
void PendapatanSales(ListSales LS, ListTransaksi LT)
{
	double hasil;
	int i=0;
	int y=5;

	if(isEmptyTransaksi(LT))
	{
		gotoxy(46,5);printf("Data Kosong");
	}
	else
	{
		for(addressSales P=LS.first; P!=NULL; P=P->next)
		{
			i++;
			hasil=hitungPedapatanSales(LT,P->data.ID);
			gotoxy(78,y+i);printf("Rp.%.2lf\n",hasil);
			gotoxy(46,y+i);printf("%s",P->data.nama);
		}
	}
}

double hitungPedapatanSales(ListTransaksi LT, string ID){

	double Hasil=0;

	for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
	{
		if(strcmpi(P->data.ID,ID)==0)
		{
			Hasil=Hasil+P->data.hargaK;
		}

	}
	return Hasil;
}


void laporan_totalPendapatan(ListTransaksi LT) {
	double totalJual=0, totalSewa=0;

	for(addressTransaksi P=LT.first; P!=NULL; P=P->next){

		if(strcmpi(P->data.unit.status,"dijual")==0 && P->data.hargaK!=0)
			totalJual = totalJual + P->data.hargaK;
		else if(strcmpi(P->data.unit.status,"disewakan")==0 && P->data.hargaK!=0)
			totalSewa = totalSewa + P->data.hargaK;
	}
	gotoxy(47,5); printf("Rp %.2lf", totalJual);
	gotoxy(78,5); printf("Rp %.2lf", totalSewa);

}

void printPropetyBelumLaku(ListTransaksi LT)
{
	int i=0;
	int y=5;
	if(isEmptyTransaksi(LT))
	{
		gotoxy(46,5);printf("Data Kosong");
	}
	else
	{
		for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
		{
			if(P->data.hargaK==0){
				
				gotoxy(48,y+i); cout<<P->data.unit.no<<endl;
				gotoxy(52,y+i); cout<<P->data.unit.jenis<<endl;
				gotoxy(62,y+i); cout<<P->data.unit.status<<endl;
				gotoxy(73,y+i); cout<<P->data.unit.harga<<endl;
				i++;
			}
		}
	}
}

void printPropertyYangLaku(ListTransaksi LT){

int i=0;
int y=7;
	if(isEmptyTransaksi(LT))
	{
	    gotoxy(46,7);printf("Data Kosong");		
	}
	else
	{
		for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
		{
			if(P->data.hargaK!=0 && strcmpi(P->data.unit.status,"dijual")==0){
				
				gotoxy(48,y+i); cout<<P->data.unit.no<<endl;
				gotoxy(52,y+i); cout<<P->data.unit.jenis<<endl;
				gotoxy(60,y+i); cout<<P->data.unit.harga<<endl;
				gotoxy(73,y+i); cout<<P->data.hargaK<<endl;
				i++;
			}
		}

		i=0;
		for(P=LT.first; P!=NULL; P=P->next)
		{
			if(P->data.hargaK!=0 && strcmpi(P->data.unit.status,"disewakan")==0){
				
				gotoxy(90,y+i); cout<<P->data.unit.no<<endl;
				gotoxy(93,y+i); cout<<P->data.unit.jenis<<endl;
				gotoxy(101,y+i); cout<<P->data.unit.harga<<endl;
				gotoxy(114,y+i); cout<<P->data.hargaK<<endl;
				i++;
			}
		}
	}
}

void printPropertyTiapSales(ListSales LS, ListTransaksi LT){

	int i=0;
	int y=8;
	int x=45;
	int tab=15;
	int counter=0;
	if(isEmptyTransaksi(LT))
	{
	   gotoxy(46,5);printf("Data Kosong");	
	}
	else
	{
		for(addressSales P=LS.first; P!=NULL; P=P->next)
		{
			gotoxy(x,30+counter);cout<<"ID Sales: "<<P->data.ID<<endl;
			gotoxy(x,30+counter);cout<<"Nama: "<<P->data.nama<<endl;
			gotoxy(x,30+counter);cout<<"MEMILIKI PROPERTY//---------------"<<endl;
			for(addressTransaksi Q=LT.first; Q!=NULL; Q=Q->next){

				if(strcmpi(Q->data.ID,P->data.ID)==0){

					gotoxy(46,y+i); cout<<Q->data.unit.no<<endl;
					gotoxy(49,y+i); cout<<Q->data.unit.jenis<<endl;
					gotoxy(57,y+i); cout<<Q->data.unit.status<<endl;
					gotoxy(68,y+i); cout<<Q->data.unit.harga<<endl;
					counter++;
				}
			}
		}
	}

}

