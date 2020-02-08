////READ ME////
//printData di pindah property tam,pilan//




#include "header.h"

void main()
{
    int no=0,noKey;
    string ID,tanya;
	double harga;
    int NO;

    ListSales LS;
    ListProperty LP;
    ListTransaksi LT;

	addressSales AS;
	addressProperty AP;
	addressTransaksi AT;
    
    Sales S;
    Property P;
    Transaksi T;

	createEmptystructTransaksi(T);
	createEmptystructSales(S);
	createEmptystructProperty(P);
    
    createEmptySales(LS);
    createEmptyProperty(LP);
    createEmptyTransaksi(LT);

	int i,y1=8,y2=9,y3=10,key;
    SetConsoleTitle("Real Estate System");
	set_layar_console(140,50);
	system("color F0");

    do{
		system("CLS");
		system("color F0");
		set_logo_gedung();
		
		//------------------------------------------------------------------------
		//MENU UTAMA
        do{
			hidecursor();

			set_layar_console(140,50);
			setcolor(biru,putih);
			set_Judul();
			set_daftar_menuUtama();
			set_ket_menuUtama(y2);
			
			//Select
			highligh_select_menuUtama(y1,y2,y3);


			key=getch();
	            
	            if(key==Down){
	                y1+=4;
	                y2+=4;
	                y3+=4;
	            }
	            if(key==Up){
	                y1-=4;
	                y2-=4;
	                y3-=4;
	            }
	            if(y2==33){
	            	y1=8;
	                y2=9;
	                y3=10;
	            }
	            if(y2==5){
	            	y1=28;
	                y2=29;
	                y3=30;
				}
			
				Beep(523.25,2); //frekuensi do,interval ms
				Sleep(2); //interval ms delay
		}while(key!=enter);

		system("CLS");
		system("color F0");
        
        switch(y2){
			setcolor(biru,putih);

			case 9 :
				y1=8,y2=9,y3=10; //ngeset ke  select highligh 1
				//---------------------------------------------------------------------------
				//SUB MENU PENGELOLA SALES
				do{
					do{
						hidecursor();
						system("color F0");
						
						setcolor(biru,putih);
				 		set_daftar_menu1();
						set_ket_menu1(y2);
						
						//Select
						highligh_select(y1,y2,y3);


						key=getch();
							
							if(key==Down){
								y1+=4;
								y2+=4;
								y3+=4;
							}
							if(key==Up){
								y1-=4;
								y2-=4;
								y3-=4;
							}
							if(y2==25){
	            				y1=8;
								y2=9;
								y3=10;
							}
							if(y2==5){
	            				y1=20;
								y2=21;
								y3=22;
							}
						
							Beep(523.25,2); //frekuensi do,interval ms
							Sleep(2); //interval ms delay
					}while(key!=enter && key!=backspace);

					if(key==backspace)
						break;	
				
					system("CLS");
					system("color F0");
					showcursor();

					switch(y2){

						case 9:
							setInputBox();
							do{
								gotoxy(7,5);printf("Nama Sales : ");
								gotoxy(20,5);fflush(stdin);gets(S.nama);
							}while(strcmpi(S.nama,"")==0);

							gotoxy(7,7);printf("ID Sales   : ");
					
							do{

								gotoxy(20,7);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
								setcolor(hitam,putih);gotoxy(20,7);fflush(stdin);gets(S.ID);

								if(isFoundSales(LS,S.ID)){
									gotoxy(80,8);printf("ID SUDAH ADA");
								}
							
							}while(isFoundSales(LS,S.ID));
							

							hidecursor();
							gotoxy(80,8);printf("INPUT BERHASIL");
                    
							AS = alokasiSales(S);
							insertLastSales(LS,AS);
							break;

						case 13:

							setcolor(hitam,putih);

							if(isEmptySales(LS))
							{
								setInputBox();
								gotoxy(7,5);
								printf("Data Kosong");
							}
							else{
								printDataSales(LS);
								setInputBox();
								gotoxy(7,5);printf("ID Sales yang ingin diganti: ");
								do{

									gotoxy(37,5);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
									setcolor(hitam,putih);gotoxy(37,5);fflush(stdin);gets(ID);


									if(!isFoundSales(LS,ID)){
										gotoxy(20,14);printf("ID TIDAK ADA");
									}
								
								}while(!isFoundSales(LS,ID));

								AS = findNodeSales(LS,ID);
								gotoxy(7,6);printf("Nama Baru                    : ");
								gotoxy(37,6);fflush(stdin);gets(AS->data.nama);

								hidecursor();
							}
								
							break;

						case 17:
							hidecursor();
							if(isEmptySales(LS))
							{
								setInputBox();
								gotoxy(7,5);
								printf("Data Kosong");
							}
							else{
								setInputBox();
								gotoxy(7,5);
								printf("Daftar Sales ---->");
								printDataSales(LS);
							}
				
							break;


						case 21:
							printDataSales(LS);
							if(isEmptySales(LS))
							{
								gotoxy(7,6);
								printf("Data Kosong");
							}
							else
							{
								setcolor(biru,putih);
								setInputBox();
								gotoxy(7,4);printf("ID Sales yang ingin dihapus : ");
								do{

									gotoxy(37,4);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
									setcolor(hitam,putih);gotoxy(38,4);fflush(stdin);gets(ID);

									AS=findNodeSales(LS,ID);

									if(AS==NULL){
										gotoxy(10,16);printf("ID TIDAK KETEMU");
									}
								
								}while(AS==NULL);

								AT=findNodeTransaksiID(LT,ID);

								if(AT!=NULL){
								
									gotoxy(7,5);printf("Apakah anda ingin memindah properti [Y/N]: ");scanf("%s",&tanya);
									if(strcmpi(tanya,"Y")==0)
									{
										
										printf("\n Pindah Ke Sales: ");scanf("%s",&ID);
										
										for(addressTransaksi P=LT.first; P!=NULL; P=P->next)
										{
											if(strcmpi(P->data.ID,AS->data.ID)==0)
											{
												strcpy(P->data.ID,ID);
											}
										}
										deleteAtSales(LS,AS);

									}
									else if(strcmpi(tanya,"N")==0)
									{
										for(addressTransaksi Q=LT.first; Q!=NULL; Q=Q->next)
										{
											if(strcmpi(Q->data.ID,AS->data.ID)==0)
											{
												Q->data.unit.ketersediaan=1;
											}
										}
										deleteAtSales(LS,AS);
									}

								}
								else
								{
									deleteAtSales(LS,AS);
									gotoxy(10,16);printf("DATA SALES TERHAPUS");
								}

							}

							break;
					}
					getch();
					system("cls");
				}while(key!=backspace);
				break;

			case 13 :
				y1=8,y2=9,y3=10; //ngeset ke  select highligh 1
				//---------------------------------------------------------------------------
				//SUB MENU PENGELOLA PROPERTY
				do{
					do{
						hidecursor();
						system("color F0");
						
						setcolor(biru,putih);
				 		set_daftar_menu2();
						set_ket_menu2(y2);
						
						//Select
						setcolor(hitam,6);
						highligh_select(y1,y2,y3);


						key=getch();
							
							if(key==Down){
								y1+=4;
								y2+=4;
								y3+=4;
							}
							if(key==Up){
								y1-=4;
								y2-=4;
								y3-=4;
							}
							if(y2==21){
	            				y1=8;
								y2=9;
								y3=10;
							}
							if(y2==5){
	            				y1=16;
								y2=17;
								y3=18;
							}
						
							Beep(523.25,2); //frekuensi do,interval ms
							Sleep(2); //interval ms delay
					}while(key!=enter && key!=backspace);

					if(key==backspace)
						break;	
				
					system("CLS");
					system("color F0");
					showcursor();

					switch(y2){

						case 9: //Input Property
							no++;
							P.no=no;
							setInputBox();
							setcolor(biru,putih);
							gotoxy(65,3);printf("KETERANGAN:   ");
							setcolor(hitam,putih);
							gotoxy(65,4);printf("hanya TANAH atau BANGUNAN");
							gotoxy(65,6);printf("hanya DISEWAKAN atau DIJUAL");
							gotoxy(7,4);printf("Jenis Property: ");
							do{

								gotoxy(23,4);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
								setcolor(hitam,putih);gotoxy(23,4);fflush(stdin);gets(P.jenis);


								if(strcmpi(P.jenis,"Tanah")!=0 && strcmpi(P.jenis,"Bangunan")!=0){
									gotoxy(20,14);printf("hanya TANAH atau BANGUNAN");
								}
							
							}while(strcmpi(P.jenis,"Tanah")!=0 && strcmpi(P.jenis,"Bangunan")!=0);
							
                        
							gotoxy(7,6);printf("Status Property: ");
							do{

								gotoxy(24,6);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
								setcolor(hitam,putih);gotoxy(24,6);fflush(stdin);gets(P.status);

								if(strcmpi(P.status,"Disewakan")!=0 && strcmpi(P.status,"Dijual")!=0){
									gotoxy(20,14);printf("hanya DISEWAKAN atau DIJUAL");
								}
							
							}while(strcmpi(P.status,"Disewakan")!=0 && strcmpi(P.status,"Dijual")!=0);
							

							gotoxy(7,8);printf("Harga Awal: ");scanf("%lf", &P.harga);
                        
							AP = alokasiProperty(P);
							insertLastProperty(LP,AP);
							break;


						case 13: //Edit Property
							setInputBox();
							printDataPropertyTersedia(LP);		//ATUR LETAK DI SOURCE, BELUM ADA GOTOXY//

							gotoxy(7,5);printf("No Property yang ingin diganti: ");

							do{

								gotoxy(39,5);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
								setcolor(hitam,putih);gotoxy(39,5);scanf("%d", &noKey);

								AP = findNodeProperty(LP,noKey);

								if(AP==NULL || AP->data.ketersediaan==0){
									gotoxy(20,14);printf("PROPERTY TIDAK ADA atau SUDAH DIBELI");
								}
							
							}while(AP==NULL || AP->data.ketersediaan==0);

							gotoxy(7,7);printf("Harga Awal: ");scanf("%lf", &AP->data.harga);
							gotoxy(10,16);printf("HARGA PROPERTY TER-UPDATE");

							break;


						case 17:
							if(isEmptyProperty(LP))
							{
								setInputBox();
								gotoxy(7,5);
								printf("Data Kosong");
							}
							else{
								setInputBox();
								gotoxy(7,5);
								printf("Daftar Property ---->");
								printDataProperty(LP);		//ATUR LETAK DI SOURCE, BELUM ADA GOTOXY//
							}
							break;

					}
					getch();
					system("cls");
				}while(key!=backspace);
				break;

			case 17 :
				y1=8,y2=9,y3=10; //ngeset ke  select highligh 1
				//---------------------------------------------------------------------------
				//SUB MENU PENETAPAN PROPERTY KE SALES
				do{
					do{
						hidecursor();
						system("color F0");
						
						setcolor(biru,putih);
				 		set_daftar_menu3();
						set_ket_menu3(y2);
						
						//Select
						highligh_select_menuUtama(y1,y2,y3);


						key=getch();
							
							if(key==Down){
								y1+=4;
								y2+=4;
								y3+=4;
							}
							if(key==Up){
								y1-=4;
								y2-=4;
								y3-=4;
							}
							if(y2==17){
	            				y1=8;
								y2=9;
								y3=10;
							}
							if(y2==5){
	            				y1=12;
								y2=13;
								y3=14;
							}
						
							Beep(523.25,2); //frekuensi do,interval ms
							Sleep(2); //interval ms delay
					}while(key!=enter && key!=backspace);

					if(key==backspace)
						break;	
				
					system("CLS");
					system("color F0");
					showcursor();

					switch(y2){

						case 9:
							do{
								if(isEmptySales(LS) || isEmptyProperty(LP))
								{
									printDataSales(LS);
									setInputBox();
									gotoxy(7,5);printf("Data Property atau Sales Masih Kosong");
									break;
								}
								else
								{
									if(!isKetersediaanHabis(LP)){
										setInputBox();

										gotoxy(7,5);printf("Pilih Sales dengan ID: ");
										gotoxy(7,7);printf("Pilih no property: ");

										printDataSales(LS);
										do{

											gotoxy(30,5);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
											setcolor(hitam,putih);gotoxy(30,5);fflush(stdin);gets(ID);

											AS = findNodeSales(LS,ID);

											if(AS==NULL){
												gotoxy(20,14);printf("SALES TIDAK ADA");
											}
										
										}while(AS==NULL);

										printDataPropertyTersedia(LP);
										do{

											gotoxy(26,7);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
											setcolor(hitam,putih);gotoxy(26,7);scanf("%d", &noKey);

											AP = findNodeProperty(LP,noKey);

											if(AP==NULL || AP->data.ketersediaan==0){
												gotoxy(20,14);printf("PROPERTY TIDAK ADA atau TIDAK TERSEDIA");
											}
										
										}while(AP==NULL || AP->data.ketersediaan==0);

										AP->data.ketersediaan=0;
										strcpy(T.ID,AS->data.ID);
										T.unit = AP->data;

										AT = alokasiTransaksi(T);
										insertLastTransaksi(LT,AT);
										hidecursor();
										gotoxy(20,14);printf("Penetapan BERHASIL!                       ");
									}
									else{

										printDataSales(LS);
										setInputBox();
										gotoxy(7,5);printf("Data Property tidak ada yang TERSEDIA");
										break;

									}
									break;
								}
							}while(key!=backspace);
							break;


						case 13:
							//DATA TRANSAKSI
							do{
								if(isEmptyProperty(LP))
								{
									printDataProperty(LP);
									setInputBox();
									gotoxy(7,5);printf("Data Kosong");
									break;
								}
								else
								{
									
									setInputBox();

									gotoxy(7,5);printf("Masukan no property yang ingin di dipindahkan: ");
									gotoxy(7,7);printf("Masukan ID Sales yang di tuju: ");
									
									printDataProperty(LP);

									do{

										gotoxy(54,5);setcolor(putih,putih);printf("%c%c%c",219,219,219);
										setcolor(hitam,putih);gotoxy(54,5);scanf("%d",&NO);

										AT = findNodeTransaksi(LT,NO);

										if(AT==NULL){
											gotoxy(20,14);printf("PROPERTY TIDAK ADA di TRANSAKSI");
										}
									
									}while(AT==NULL);

									printDataSales(LS);
									do{

										gotoxy(37,7);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
										setcolor(hitam,putih);gotoxy(37,7);;scanf("%s",&ID);

										AS = findNodeSales(LS,ID);

										if(AS==NULL){
											gotoxy(20,14);printf("SALES TIDAK ADA");
										}
									
									}while(AS==NULL);
									
									strcpy(AT->data.ID,AS->data.ID);
									gotoxy(20,14);printf("Berhasil DIPINDAHKAN!");
								}
								break;
							}while(key!=backspace);
							break;
					}
					getch();
					system("cls");
				}while(key!=backspace);
				break;

			case 21 :
				//---------------------------------------------------------------------------
				//SUB MENU PEEMBELIAN PROPERTY
				do{
					if(isEmptyTransaksi(LT))
					{
						setInputBox_PembelianProperty();
						printDataDijual(LT);
						gotoxy(7,5);printf("data Kosong");
						break;
					}
					else
					{
						if(hitungbeli(LT)!=0)
						{
							showcursor();
							printDataDijual(LT);		//BELUM ADA GOTOXY//
							setInputBox_PembelianProperty();
							setcolor(hitam,putih);
							gotoxy(7,5);printf("Beli property no berapa: ");

							do{

								gotoxy(36,5);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
								setcolor(hitam,putih);gotoxy(36,5);scanf("%d",&NO);

								AT = findNodeTransaksi(LT,NO);

								if(AT==NULL || strcmpi(AT->data.unit.status,"dijual")!=0){
									gotoxy(20,14);printf("PROPERTY TIDAK ADA di TRANSAKSI");
								}
							
							}while(AT==NULL || strcmpi(AT->data.unit.status,"dijual")!=0);
							
							gotoxy(7,5);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
							setcolor(hitam,putih);

							//clear text beli property
							setcolor(putih,putih);gotoxy(19,5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219 );

							setcolor(hitam,putih);
							gotoxy(7,5);printf("                          ");
							gotoxy(7,5);printf("Nama anda : ");
							gotoxy(7,7);printf("Alamat    : ");
							gotoxy(7,9);printf("No Tlp    : ");

							gotoxy(19,5);fflush(stdin);gets(AT->data.nama);
							gotoxy(19,7);fflush(stdin);gets(AT->data.alamat);
							gotoxy(19,9);fflush(stdin);gets(AT->data.noTlp);

							do{

								gotoxy(7,11);printf("Harga Kesepakatan: ");scanf("%lf",&harga);
								if(harga<AT->data.unit.harga){
									gotoxy(20,14);printf("Harga kurang dari harga awal");
								}

							}while(harga<AT->data.unit.harga);

							AT->data.hargaK=harga;
							hidecursor();
							break;
						}
						else
						{
							setInputBox_PembelianProperty();
							printDataDijual(LT);
							gotoxy(7,5);printf("data Kosong");
							break;
						}
						
					}
					

				}while(key!=backspace);
					break;

			case 25 :
				//---------------------------------------------------------------------------
				//SUB MENU PENYEWAAN PROPERTY
				do{
					if(isEmptyTransaksi(LT))
					{
						printDataDisewakan(LT);
						setInputBox_PembelianProperty();
						gotoxy(7,5);printf("Data Kosong");
						break;
					}
					else
					{
						if(hitungsewa(LT)!=0)
						{
							showcursor();
							printDataDisewakan(LT);		//BELUM ADA GOTOXY//
							setInputBox_PembelianProperty();

							gotoxy(7,5);printf("Sewa property no berapa: ");

							do{

								gotoxy(37,5);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
								setcolor(hitam,putih);gotoxy(37,5);scanf("%d", &NO);

								AT = findNodeTransaksi(LT,NO);

								if(AT==NULL || strcmpi(AT->data.unit.status,"disewakan")!=0){
									gotoxy(20,14);printf("PROPERTY TIDAK ADA di TRANSAKSI");
								}
							
							}while(AT==NULL || strcmpi(AT->data.unit.status,"disewakan")!=0);

							gotoxy(7,5);setcolor(putih,putih);printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
							setcolor(hitam,putih);


							gotoxy(7,5);printf("                              ");
							gotoxy(7,5);printf("Nama anda : ");
							gotoxy(7,7);printf("alamat    : ");
							gotoxy(7,9);printf("No Tlp    : ");

							gotoxy(19,5);fflush(stdin);gets(AT->data.nama);
							gotoxy(19,7);fflush(stdin);gets(AT->data.alamat);
							gotoxy(19,9);fflush(stdin);gets(AT->data.noTlp);

							do{

								gotoxy(7,11);printf("Harga Kesepakatan: ");scanf("%lf", &harga);
								if(harga<AT->data.unit.harga){
									gotoxy(20,14);printf("Harga dibawah harga awal");
								}

							}while(harga<AT->data.unit.harga);
							AT->data.hargaK=harga;

							gotoxy(7,12);printf("Lama Sewa: ");fflush(stdin);gets(AT->data.lamaSewa);
							hidecursor();
						}
						else
						{
							printDataDisewakan(LT);
							setInputBox_PembelianProperty();
							gotoxy(7,5);printf("Data Kosong");
							break;
						}
					}
					break;
				}while(key!=backspace);
					break;

			case 29 :
				set_layar_console(170,50);
				y1=8,y2=9,y3=10; //ngeset ke  select highligh 1
				do{
					hidecursor();
					system("color F0");
					
					setcolor(biru,putih);
				 	set_daftar_laporan();
					set_ket_laporan(y2,LS,LT);
					
					//Select
					highligh_select_laporan(y1, y2,y3);
	

					key=getch();
						
						if(key==Down){
							y1+=4;
							y2+=4;
							y3+=4;
						}
						if(key==Up){
							y1-=4;
							y2-=4;
							y3-=4;
						}
						if(y2==29){
	            			y1=8;
							y2=9;
							y3=10;
						}
						if(y2==5){
	            			y1=24;
							y2=25;
							y3=26;
						}	
						Beep(523.25,2); //frekuensi do,interval ms
						Sleep(2); //interval ms delay
						system("cls");
				}while(key!=enter && key!=backspace);		
				break;
        }
        getch();
    }while(key!=esc);
}
