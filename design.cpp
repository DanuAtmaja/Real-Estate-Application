#include "header.h"

//--------------------------------------------------------------
//Visual
void gotoxy(int x,int y)	{
    
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);    
}

void hidecursor()	{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor()	{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void setcolor(char text, char background)	{
	
	unsigned short color=background*16+text;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, color);
}


void set_layar_console(int WIDTH,int HEIGHT)	{
	SMALL_RECT windowSize = {0, 0, WIDTH, HEIGHT};					  
   	COORD bufferSize = {WIDTH+1, HEIGHT+1};						  
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &windowSize);	
}	

void set_daftar_menuUtama() {
	int i;
		//MENU 1
		gotoxy(6,8); for(i=0;i<27;i++) printf("%c",205 ); //line atas 18
		gotoxy(5,8); printf("%c",201); //pojok kiri atas
		gotoxy(33,8); printf("%c",187); //pojok kanan atas 24
		gotoxy(5,9); printf("%c      Mengelola Sales      %c",186,186);
		gotoxy(6,10); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,10); printf("%c",200); //pojok kiri bawah
		gotoxy(33,10); printf("%c",188); //pojok kanan bawah

		//MENU 2
		gotoxy(6,12); for(i=0;i<27;i++) printf("%c",205 ); //line atas
		gotoxy(5,12); printf("%c",201); //pojok kiri atas
		gotoxy(33,12); printf("%c",187); //pojok kanan atas
		gotoxy(5,13); printf("%c     Mengelola Property    %c",186,186);
		gotoxy(6,14); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,14); printf("%c",200); //pojok kiri bawah
		gotoxy(33,14); printf("%c",188); //pojok kanan bawah

		//MENU 3
		gotoxy(6,16); for(i=0;i<27;i++) printf("%c",205 ); //line atas
		gotoxy(5,16); printf("%c",201); //pojok kiri atas
		gotoxy(33,16); printf("%c",187); //pojok kanan atas
		gotoxy(5,17); printf("%cPenetapan Property ke Sales%c",186,186);
		gotoxy(6,18); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,18); printf("%c",200); //pojok kiri bawah
		gotoxy(33,18); printf("%c",188); //pojok kanan bawah

		//MENU 4
		gotoxy(6,20); for(i=0;i<27;i++) printf("%c",205 ); //line atas
		gotoxy(5,20); printf("%c",201); //pojok kiri atas
		gotoxy(33,20); printf("%c",187); //pojok kanan atas
		gotoxy(5,21); printf("%c     Pembelian Property    %c",186,186);
		gotoxy(6,22); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,22); printf("%c",200); //pojok kiri bawah
		gotoxy(33,22); printf("%c",188); //pojok kanan bawah

		//MENU 5
		gotoxy(6,24); for(i=0;i<27;i++) printf("%c",205 ); //line atas
		gotoxy(5,24); printf("%c",201); //pojok kiri atas
		gotoxy(33,24); printf("%c",187); //pojok kanan atas
		gotoxy(5,25); printf("%c     Penyewaan Property    %c",186,186);
		gotoxy(6,26); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,26); printf("%c",200); //pojok kiri bawah
		gotoxy(33,26); printf("%c",188); //pojok kanan bawah


		//MENU 6
		gotoxy(6,28); for(i=0;i<27;i++) printf("%c",205 ); //line atas
		gotoxy(5,28); printf("%c",201); //pojok kiri atas
		gotoxy(33,28); printf("%c",187); //pojok kanan atas
		gotoxy(5,29); printf("%c          Laporan          %c",186,186);
		gotoxy(6,30); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,30); printf("%c",200); //pojok kiri bawah
		gotoxy(33,30); printf("%c",188); //pojok kanan bawah
}
void set_ket_menuUtama(int &ket)	{
	
	//ngeclear keterangan sebelumnya
	gotoxy(69,9); for (int i = 0; i < 40; i++)
	{
		setcolor(putih,putih); printf("%c",219 ); 
	}
	setcolor(biru,putih);
	//Border
	gotoxy(64,7); for( i=0;i<46;i++) printf("%c",220);//border up
	for(i=0;i<22;i++) 
	{
		gotoxy(64,8+i);  printf("%c",221); //border left
	}
	for(i=0;i<22;i++)
	{
		gotoxy(109,8+i);  printf("%c",222); //border right
	}
	gotoxy(64,29); for(i=0;i<46;i++) printf("%c",223);//border down
	
	gotoxy(80,8); printf("Keterangan : ");
	gotoxy(69,9);
	if(ket==9)
	{ 
		printf("Mengelola Sales, menginput");
	}else if(ket==13)
	{
		printf("Mengelola Property");
	}else if(ket==17)
	{
		printf("Penetapan Property ke Sales");
	}else if(ket==21)
	{
		printf("Pembelian Property");
	}else if(ket==25)
	{
		printf("Penyewaan Property");
	}else if(ket==29)
	{
		printf("Laporan");
	}

	//Navigation Help
	
}


//Menu Penglola sales
void set_daftar_menu1()	{
	int i;
		//MENU 1
		gotoxy(6,8); for(i=0;i<18;i++) printf("%c",205 ); //line atas
		gotoxy(5,8); printf("%c",201); //pojok kiri atas
		gotoxy(24,8); printf("%c",187); //pojok kanan atas
		gotoxy(5,9); printf("%c       Input      %c",186,186);
		gotoxy(6,10); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,10); printf("%c",200); //pojok kiri bawah
		gotoxy(24,10); printf("%c",188); //pojok kanan bawah

		//MENU 2
		gotoxy(6,12); for(i=0;i<18;i++) printf("%c",205 ); //line atas
		gotoxy(5,12); printf("%c",201); //pojok kiri atas
		gotoxy(24,12); printf("%c",187); //pojok kanan atas
		gotoxy(5,13); printf("%c       Edit       %c",186,186);
		gotoxy(6,14); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,14); printf("%c",200); //pojok kiri bawah
		gotoxy(24,14); printf("%c",188); //pojok kanan bawah

		//MENU 3
		gotoxy(6,16); for(i=0;i<18;i++) printf("%c",205 ); //line atas
		gotoxy(5,16); printf("%c",201); //pojok kiri atas
		gotoxy(24,16); printf("%c",187); //pojok kanan atas
		gotoxy(5,17); printf("%c       Tampil     %c",186,186);
		gotoxy(6,18); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,18); printf("%c",200); //pojok kiri bawah
		gotoxy(24,18); printf("%c",188); //pojok kanan bawah

		//MENU 4
		gotoxy(6,20); for(i=0;i<18;i++) printf("%c",205 ); //line atas
		gotoxy(5,20); printf("%c",201); //pojok kiri atas
		gotoxy(24,20); printf("%c",187); //pojok kanan atas
		gotoxy(5,21); printf("%c       Hapus      %c",186,186);
		gotoxy(6,22); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,22); printf("%c",200); //pojok kiri bawah
		gotoxy(24,22); printf("%c",188); //pojok kanan bawah
}
void set_ket_menu1(int &ket)	{
	//Border
	for (int i = 0; i < 36; i++)
	{
		gotoxy(77,9); setcolor(putih,putih); printf("%c",219 );
	}
	setcolor(biru,putih);
	gotoxy(64,7); for(i=0;i<46;i++) printf("%c",220);//border up
	for(i=0;i<22;i++) 
	{
		gotoxy(64,8+i);  printf("%c",221); //border left
	}
	for(i=0;i<22;i++)
	{
		gotoxy(109,8+i);  printf("%c",222); //border right
	}
	gotoxy(64,29); for(i=0;i<46;i++) printf("%c",223);//border down
	
	gotoxy(80,8); printf("Keterangan : ");
	gotoxy(77,9);
	if(ket==9)
	{  
		setcolor(biru,putih); 	printf(" Input Data Sales");
	}else if(ket==13)
	{
		setcolor(biru,putih);	printf("  Edit Data Sales");
	}else if(ket==17)
	{
		setcolor(biru,putih);	printf("Tampil Data Sales");
	}else if(ket==21)
	{
		setcolor(biru,putih);	printf(" Hapus Data Sales");
	}
}


//Menu Penglola property
void set_daftar_menu2()	{
	int i;
		//MENU 1
		gotoxy(6,8); for(i=0;i<18;i++) printf("%c",205 ); //line atas
		gotoxy(5,8); printf("%c",201); //pojok kiri atas
		gotoxy(24,8); printf("%c",187); //pojok kanan atas
		gotoxy(5,9); printf("%c       Input      %c",186,186);
		gotoxy(6,10); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,10); printf("%c",200); //pojok kiri bawah
		gotoxy(24,10); printf("%c",188); //pojok kanan bawah

		//MENU 2
		gotoxy(6,12); for(i=0;i<18;i++) printf("%c",205 ); //line atas
		gotoxy(5,12); printf("%c",201); //pojok kiri atas
		gotoxy(24,12); printf("%c",187); //pojok kanan atas
		gotoxy(5,13); printf("%c       Edit       %c",186,186);
		gotoxy(6,14); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,14); printf("%c",200); //pojok kiri bawah
		gotoxy(24,14); printf("%c",188); //pojok kanan bawah

		//MENU 3
		gotoxy(6,16); for(i=0;i<18;i++) printf("%c",205 ); //line atas
		gotoxy(5,16); printf("%c",201); //pojok kiri atas
		gotoxy(24,16); printf("%c",187); //pojok kanan atas
		gotoxy(5,17); printf("%c       Tampil     %c",186,186);
		gotoxy(6,18); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,18); printf("%c",200); //pojok kiri bawah
		gotoxy(24,18); printf("%c",188); //pojok kanan bawah

}
void set_ket_menu2(int &ket)	{
	//clear kolom keterangan sebelumnya
	for (int i = 0; i < 36; i++)
	{
		gotoxy(77,9); setcolor(putih,putih); printf("%c",219 );
	}
	setcolor(biru,putih);
	//Border
	gotoxy(64,7); for(i=0;i<46;i++) printf("%c",220);//border up
	for(i=0;i<22;i++) 
	{
		gotoxy(64,8+i);  printf("%c",221); //border left
	}
	for(i=0;i<22;i++)
	{
		gotoxy(109,8+i);  printf("%c",222); //border right
	}
	gotoxy(64,29); for(i=0;i<46;i++) printf("%c",223);//border down
	
	gotoxy(80,8); printf("Keterangan : ");
	gotoxy(80,9);
	if(ket==9)
	{ 
		printf("Input  Property");
	}else if(ket==13)
	{
		printf("Edit   Property");
	}else if(ket==17)
	{
		printf("Tampil Property");
	}
}


//Menu Penetapan property ke sales
void set_daftar_menu3()	{
	int i;
		//MENU 1
		gotoxy(6,8); for(i=0;i<27;i++) printf("%c",205 ); //line atas
		gotoxy(5,8); printf("%c",201); //pojok kiri atas
		gotoxy(33,8); printf("%c",187); //pojok kanan atas
		gotoxy(5,9); printf("%c     Penetapan Property    %c",186,186);
		gotoxy(6,10); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,10); printf("%c",200); //pojok kiri bawah
		gotoxy(33,10); printf("%c",188); //pojok kanan bawah

		//MENU 2
		gotoxy(6,12); for(i=0;i<27;i++) printf("%c",205 ); //line atas
		gotoxy(5,12); printf("%c",201); //pojok kiri atas
		gotoxy(33,12); printf("%c",187); //pojok kanan atas
		gotoxy(5,13); printf("%c       Pindah Property     %c",186,186);
		gotoxy(6,14); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,14); printf("%c",200); //pojok kiri bawah
		gotoxy(33,14); printf("%c",188); //pojok kanan bawah

}
void set_ket_menu3(int &ket)	{
	//Border
	gotoxy(64,7); for(int i=0;i<46;i++) printf("%c",220);//border up
	for(i=0;i<22;i++) 
	{
		gotoxy(64,8+i);  printf("%c",221); //border left
	}
	for(i=0;i<22;i++)
	{
		gotoxy(109,8+i);  printf("%c",222); //border right
	}
	gotoxy(64,29); for(i=0;i<46;i++) printf("%c",223);//border down
	
	gotoxy(80,8); printf("Keterangan : ");
	gotoxy(80,9);
	if(ket==9)
	{ 
		printf("Penetapan Property");
	}else if(ket==13)
	{
		printf("Pindah Property");
	}
}


//Menu Laporan ///6

//Pendapatan setiap sales
//Pendapatan dari pentewaan dan penjualan
//Daftar property yg sudah terjual atau status sewa
//Daftar porperty yang masih tersedia
//Daftar properti yang dipegang oleh sales
void set_daftar_laporan()	{
	int i;
		//MENU 1
		gotoxy(6,8); for(i=0;i<34;i++) printf("%c",205 ); //line atas
		gotoxy(5,8); printf("%c",201); //pojok kiri atas
		gotoxy(40,8); printf("%c",187); //pojok kanan atas
		gotoxy(5,9); printf("%c       Pendapatan Sales           %c",186,186);
		gotoxy(6,10); for(i=0;i<34;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,10); printf("%c",200); //pojok kiri bawah
		gotoxy(40,10); printf("%c",188); //pojok kanan bawah

		//MENU 2
		gotoxy(6,12); for(i=0;i<34;i++) printf("%c",205 ); //line atas
		gotoxy(5,12); printf("%c",201); //pojok kiri atas
		gotoxy(40,12); printf("%c",187); //pojok kanan atas
		gotoxy(5,13); printf("%cPendapatan Penyewaan dan Penjualan%c",186,186);
		gotoxy(6,14); for(i=0;i<34;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,14); printf("%c",200); //pojok kiri bawah
		gotoxy(40,14); printf("%c",188); //pojok kanan bawah

		//MENU 3
		gotoxy(6,16); for(i=0;i<34;i++) printf("%c",205 ); //line atas
		gotoxy(5,16); printf("%c",201); //pojok kiri atas
		gotoxy(40,16); printf("%c",187); //pojok kanan atas
		gotoxy(5,17); printf("%c Property Terjual atau Status Sewa%c",186,186);
		gotoxy(6,18); for(i=0;i<34;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,18); printf("%c",200); //pojok kiri bawah
		gotoxy(40,18); printf("%c",188); //pojok kanan bawah

		//MENU 4
		gotoxy(6,20); for(i=0;i<34;i++) printf("%c",205 ); //line atas
		gotoxy(5,20); printf("%c",201); //pojok kiri atas
		gotoxy(40,20); printf("%c",187); //pojok kanan atas
		gotoxy(5,21); printf("%c  Property yang Masih Tersedia    %c",186,186);
		gotoxy(6,22); for(i=0;i<34;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,22); printf("%c",200); //pojok kiri bawah
		gotoxy(40,22); printf("%c",188); //pojok kanan bawah

		//MENU 5
		gotoxy(6,24); for(i=0;i<34;i++) printf("%c",205 ); //line atas
		gotoxy(5,24); printf("%c",201); //pojok kiri atas
		gotoxy(40,24); printf("%c",187); //pojok kanan atas
		gotoxy(5,25); printf("%c   Property yang dipegang Sales   %c",186,186);
		gotoxy(6,26); for(i=0;i<34;i++)  printf("%c",205 ); //line bawah
		gotoxy(5,26); printf("%c",200); //pojok kiri bawah
		gotoxy(40,26); printf("%c",188); //pojok kanan bawah
}

void set_ket_laporan(int &ket,ListSales LS,ListTransaksi LT){

	string field1[max] = {"Nama Sales            ","          Jumlah Pendapatan        "};
	string field2[max] = {"Pendapatan Hasil Penjualan  ","Pendapatan Hasil Penyewaan "};
	string field3[max] = {"No","Jenis","Harga Awal","H.Kesepakatan","No","Jenis","Harga Awal","H.Kesepakatan"};
	string field4[max] = {"No"," Jenis "," Status "," Harga "};
	string field5[max] = {"No","Nama Sales","Jenis "," Status ","Harga Awal"};

	gotoxy(65,9);
	if(ket==9)
	{
		
		setTable(45,2,field1,2,19,biru,kuning,biru,kuning);
		
		PendapatanSales(LS,LT);
	}else if(ket==13)
	{
		setTable(45,2,field2,2,5,biru,kuning,biru,kuning);
		laporan_totalPendapatan(LT);
	}else if(ket==17)
	{
		setcolor(biru,kuning);
		gotoxy(45,1); for(int i=0;i<85;i++) printf("%c",220); //line atas
		gotoxy(45,2); printf("%c             Property Terjual            %c               Status Sewa               %c",221,219,222 ); //Judul Table
		gotoxy(45,3); for(i=0;i<85;i++) printf("%c",223); //line Bawah
		setTable(45,4,field3,8,19,biru,kuning,biru,kuning);
		printPropertyYangLaku(LT);
	}else if(ket==21)
	{
		setTable(45,2,field4,4,19,biru,kuning,biru,kuning);
		printPropetyBelumLaku(LT);
	}else if(ket==25)
	{
		printDataTransaksi(LT);
	}
}

void highligh_select_laporan(int &y1, int &y2, int &y3) {
	int i;
	setcolor(hitam,6);
	gotoxy(6,y1); for(i=0;i<34;i++) printf("%c",205 ); //line atas
	gotoxy(5,y1); printf("%c",201); //pojok kiri atas
	gotoxy(40,y1); printf("%c",187); //pojok kanan atas
	gotoxy(5,y2); printf("%c",186);
	gotoxy(40,y2); printf("%c",186);
	gotoxy(6,y3); for(i=0;i<34;i++)  printf("%c",205 ); //line bawah
	gotoxy(5,y3); printf("%c",200); //pojok kiri bawah
	gotoxy(40,y3); printf("%c",188); //pojok kanan bawah

}

void set_logo_gedung()	{
	int i,x,temp;
	setcolor(biru,putih);
	//gedung 1
	gotoxy(5,1); for(i=0;i<7;i++) { printf("%c",220); Sleep(12); } 
	for(i=0;i<5;i++){ gotoxy(5,2+i); printf("%c",221); gotoxy(11,2+i); printf("%c",222); Sleep(12); }
	for(i=0;i<4;i++){ gotoxy(6,2+i); printf("%c",220); Sleep(12); gotoxy(8,2+i); printf("%c",220); Sleep(12); gotoxy(10,2+i); printf("%c",220); Sleep(12); }
	//gedung 2
	setcolor(biruX,putih);
	gotoxy(13,1); for(i=0;i<7;i++) { printf("%c",220); Sleep(12); }
	for(i=0;i<5;i++){ gotoxy(13,2+i); printf("%c",221); gotoxy(19,2+i); printf("%c",222); Sleep(12); }
	for(i=0;i<4;i++){ gotoxy(14,2+i); printf("%c",220); Sleep(12); gotoxy(16,2+i); printf("%c",220); Sleep(12); gotoxy(18,2+i); printf("%c",220); Sleep(12);  }
	//gedung 3
	setcolor(kuningX,putih);
	gotoxy(21,1); for(i=0;i<7;i++) { printf("%c",220); Sleep(12); }
	for(i=0;i<5;i++){ gotoxy(21,2+i); printf("%c",221); gotoxy(27,2+i); printf("%c",222); Sleep(12); }
	for(i=0;i<4;i++){ gotoxy(22,2+i); printf("%c",220); Sleep(12); gotoxy(24,2+i); printf("%c",220); Sleep(12); gotoxy(26,2+i); printf("%c",220); Sleep(12); }

	for(i=0;i<25;i++)
	{
		x=temp;
		x=32+i;
		gotoxy(x,2);
		gotoxy(temp,2); setcolor(putih,putih); printf("%c",219);
		setcolor(biru,putih);	printf("Selamat datang di Real Estate, Silahkan pilih menu ");
		Sleep(12);
	}
	
		hidecursor();
}

void setTable(int xStart, int yStart,string field[max], int sumOfField, int sumOfRecord, char textField, char backgroundField, char textRecord, char backgroundRecord)	{
	/*Code Goes Here*/
		int i,j,p;
	int width=0,height=0;
	int index;

	for(i=0;i<sumOfField;i++)   //memberikan kolom dasar
		width += strlen(field[i]); //
	width += 3*sumOfField + 1;  //

	height = 4 + sumOfRecord; //memberikan jumlah kolom ke bawah

	for(j=xStart;j<xStart+width;j++)  //memberikan warna pada field text, background (field, record)
	{
		for(i=yStart;i<yStart+height;i++) 
		{

			if(i<yStart+3)	setcolor(textField,backgroundField); 
			else			setcolor(textRecord,backgroundRecord); 
			gotoxy(j,i); printf(" ");		

		}
	}

	for(j=xStart;j<xStart+width;j++) //bertujuan untuk menampilkan grid ke samping --- pada masing masing field
	{
		setcolor(textField,backgroundField); 
		gotoxy(j,yStart);			printf("%c",h);
		gotoxy(j,yStart+2);			printf("%c",h);
		setcolor(textRecord,backgroundRecord);
		gotoxy(j,yStart+height-1);	printf("%c",h);
	}

	index =0; p=0;
	for(j=xStart;j<xStart+width;j++)  // memberikan garis ke tengah ke bawah
	{
		if(j==p+xStart)
		{
			for(i=yStart;i<=yStart+height-1;i++)
			{
				if(i<yStart+3)	setcolor(textField,backgroundField);
				else			setcolor(textRecord,backgroundRecord);
				gotoxy(j,i); printf("%c",v);
			}
			p += strlen(field[index]) + 3;
			index++;
		}
	}

	setcolor(textField,backgroundField);
	index =0; p=0;
	for(j=xStart;j<xStart+width;j++)	//memberikan kode ASCII untuk masing2 sudut
	{
		if(j==p+xStart)
		{
			for(i=yStart;i<=yStart+height-1;i++)
			{
				gotoxy(j,i);
				if(i==yStart)
				{
					setcolor(textField,backgroundField);
					if(j==xStart)				printf("%c",tl);
					else if(j==xStart+width-1)	printf("%c",tr);
					else						printf("%c",Tu);
				}
				else if(i==yStart+2)
				{
					setcolor(textField,backgroundField);
					if(j==xStart)				printf("%c",Tl);
					else if(j==xStart+width-1)	printf("%c",Tr);
					else						printf("%c",C4);
				}
				else if(i==yStart+height-1)
				{
					setcolor(textRecord,backgroundRecord);
					if(j==xStart)				printf("%c",bl);
					else if(j==xStart+width-1)	printf("%c",br);
					else						printf("%c",Td);
				}
			}
			p += strlen(field[index]) + 3;
			index++;
		}
	}

	setcolor(textField,backgroundField); 
	index=0; p=0;
	for(j=xStart;j<xStart+width;j++) //mengSet text masing2 judul
	{
		if(j==p+xStart+2)
		{
			gotoxy(j,yStart+1); printf("%s",field[index]);
			p += strlen(field[index]) + 3;
			index++;
		}
	} 
}

void setInputBox(){

	int i;

	for(i=0; i<57; i++){

		gotoxy(5+i,2);printf("%c",220);
		gotoxy(5+i,10);printf("%c",223);
	}
	
	gotoxy(5,3);printf("%c",221);
	gotoxy(61,3);printf("%c",222);
	gotoxy(5,4);printf("%c",221);
	gotoxy(61,4);printf("%c",222);
	gotoxy(5,5);printf("%c",221);
	gotoxy(61,5);printf("%c",222);
	gotoxy(5,6);printf("%c",221);
	gotoxy(61,6);printf("%c",222);
	gotoxy(5,7);printf("%c",221);
	gotoxy(61,7);printf("%c",222);
	gotoxy(5,8);printf("%c",221);
	gotoxy(61,8);printf("%c",222);
	gotoxy(5,9);printf("%c",221);
	gotoxy(61,9);printf("%c",222);

}

void setInputBox_PembelianProperty(){

	int i;

	for(i=0; i<57; i++){

		gotoxy(5+i,2);printf("%c",220);
		gotoxy(5+i,16);printf("%c",223);
	}
	
	gotoxy(5,3);printf("%c",221);
	gotoxy(61,3);printf("%c",222);
	gotoxy(5,4);printf("%c",221);
	gotoxy(61,4);printf("%c",222);
	gotoxy(5,5);printf("%c",221);
	gotoxy(61,5);printf("%c",222);
	gotoxy(5,6);printf("%c",221);
	gotoxy(61,6);printf("%c",222);
	gotoxy(5,7);printf("%c",221);
	gotoxy(61,7);printf("%c",222);
	gotoxy(5,8);printf("%c",221);
	gotoxy(61,8);printf("%c",222);
	gotoxy(5,9);printf("%c",221);
	gotoxy(61,9);printf("%c",222);
	gotoxy(5,10);printf("%c",221);
	gotoxy(61,10);printf("%c",222);
	gotoxy(5,11);printf("%c",221);
	gotoxy(61,11);printf("%c",222);
	gotoxy(5,12);printf("%c",221);
	gotoxy(61,12);printf("%c",222);
	gotoxy(5,13);printf("%c",221);
	gotoxy(61,13);printf("%c",222);
	gotoxy(5,14);printf("%c",221);
	gotoxy(61,14);printf("%c",222);
	gotoxy(5,15);printf("%c",221);
	gotoxy(61,15);printf("%c",222);

}


void set_Judul() {
	int i;
	gotoxy(38,3); for(i=0;i<8;i++) printf("%c",220); 
	gotoxy(38,4); printf("%c MENU %c",221,222);
	gotoxy(38,5); for(i=0;i<8;i++) printf("%c",223); 
}

void highligh_select(int &y1, int &y2, int &y3) {
	int i;
	setcolor(hitam,6);
	gotoxy(6,y1); for(i=0;i<18;i++) printf("%c",205 ); //line atas
	gotoxy(5,y1); printf("%c",201); //pojok kiri atas
	gotoxy(24,y1); printf("%c",187); //pojok kanan atas
	gotoxy(5,y2); printf("%c",186);
	gotoxy(24,y2); printf("%c",186);
	gotoxy(6,y3); for(i=0;i<18;i++)  printf("%c",205 ); //line bawah
	gotoxy(5,y3); printf("%c",200); //pojok kiri bawah
	gotoxy(24,y3); printf("%c",188); //pojok kanan bawah

}

void highligh_select_menuUtama(int &y1, int &y2, int &y3) {
	int i;
	setcolor(hitam,6);
	gotoxy(6,y1); for(i=0;i<27;i++) printf("%c",205 ); //line atas
	gotoxy(5,y1); printf("%c",201); //pojok kiri atas
	gotoxy(33,y1); printf("%c",187); //pojok kanan atas
	gotoxy(5,y2); printf("%c",186);
	gotoxy(33,y2); printf("%c",186);
	gotoxy(6,y3); for(i=0;i<27;i++)  printf("%c",205 ); //line bawah
	gotoxy(5,y3); printf("%c",200); //pojok kiri bawah
	gotoxy(33,y3); printf("%c",188); //pojok kanan bawah

}