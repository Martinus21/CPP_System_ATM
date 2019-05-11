/* 
Nama 	= Martinus Richard Ticoalu.
NIM 	= 20180801055.
Matkul	= Bahasa Pemprograman.
*/

#include <iostream>		// INPUT OUTPUT / BASIC STREAM
#include <iomanip> 		// MEMBANTU MENGONTROL INPUT OUTPUT
#include <fstream>		// FILE STREAM / INPUT OUTPUT FILE
//#include <stdlib.h>		// KONTROL PROSES / MEMANGGIL FUNSI SYSTEM("CLS");
#include <conio.h>		// GETCH / CONSOL INPUT OUTPUT
//#include <windows.h>	// PREPROSSESOR FILE

using namespace std;

/*============================================================================================================================================================*/
/*                                                                 DEKLARASI GLOBAL VARIABLE                                                                  */
/*============================================================================================================================================================*/
int saldo_awal = 200000;
int nominal_tarik_tunai, nominal_setor_tunai, nominal_transfer, nominal_pembayaran;
int pilihan_menu_utama, pilihan_menu_transfer, pilihan_menu_pembayaran;

int nomer_pembayaran_telepon_seluler, nomer_pembayaran_PLN, nomer_pembayaran_cicilan, nomer_pembayaran_tiket;
int nominal_pembayaran_telepon_seluler, nominal_pembayaran_PLN, nominal_pembayaran_cicilan, nominal_pembayaran_tiket;

char pilihan_cetak_struk, pilihan_transaksi_ulang;
int ulangi_pin = 0;

string nomer_rekening_transfer;
/*============================================================================================================================================================*/
/*                                                               DEKLARASI GLOBAL VARIABLE END                                                                */
/*============================================================================================================================================================*/


/*============================================================================================================================================================*/
/*                                                         DEKLARASI GLOBAL VARIABLE UNTUK CLASS                                                              */
/*============================================================================================================================================================*/
char pin_input;
string pin = "";
int max_input_pin = 0;
/*============================================================================================================================================================*/
/*                                                       DEKLARASI GLOBAL VARIABLE UNTUK CLASS END                                                            */
/*============================================================================================================================================================*/


/*============================================================================================================================================================*/
/*                                                             DEKLARASI FUNGSI TAMPILAN HEADER                                                               */
/*============================================================================================================================================================*/
void header();
void header_tarik_tunai();
void header_setor_tunai();
void header_cek_saldo();
void header_transfer_rekening();
void header_pembayaran();
void header_pembayaran_telepon_seluler();
void header_pembayaran_pln();
void header_pembayaran_cicilan();
void header_pembayaran_tiket();
void footer();
/*============================================================================================================================================================*/
/*                                                            DEKLARASI FUNGSI TAMPILAN HEADER END                                                            */
/*============================================================================================================================================================*/


/*============================================================================================================================================================*/
/*                                                                     CLASS PIN SISTEM                                                                       */
/*============================================================================================================================================================*/
class pin_sistem {
private :
    string pin_user(){
        return "111111";
    }
public :
    string config_pin(){
        return pin_user();
    }
    void form_pass(){
		pin = "";
		cout << endl;
		cout << setw(54) << "Silahkan masukkan pin anda : " << endl;
		pin_input=_getch(); // Fungsi untuk menunggu inputan dari keyboard
    	cout << setw(37);
		while(pin_input >= 6 && max_input_pin < 6){ // Membatasi Inputan Keyboard
    		pin.push_back(pin_input);
			cout << "*";
    		pin_input=_getch();
    		max_input_pin++;
		}
		max_input_pin = 0;
	}
    string username(){
        return "Calon S1 8 Tahun :v";
    }
};
/*============================================================================================================================================================*/
/*                                                                   END CLASS PIN SISTEM                                                                     */
/*============================================================================================================================================================*/


int main(){
	system("color 0B");

	// DEKLARASI NAMA NAMA CLASS
	pin_sistem call_pin;
    

	do{
		header();
		call_pin.form_pass();
    	menu :
    		
   		if ( pin == call_pin.config_pin() ){	
			system("CLS");
    		header();
    
        	cout << setw(39) << "Selamat Datang , " << call_pin.username() << endl << endl;
        	cout << setw(32) << "Pilihan Menu :" << endl << endl;
        	cout << setw(30) << "1. Tarik Tunai" << setw(34) << "4. Transfer" << endl << endl;
			cout << setw(30) << "2. Setor Tunai" << setw(36) << "5. Pembayaran" << endl << endl;
			cout << setw(28) << "3. Cek Saldo" << setw(34) << "6. Keluar" << endl << endl;
        	cout << setw(31) << "Pilih menu : ";
			cin >> pilihan_menu_utama;
		
			system("cls");
		
        	switch(pilihan_menu_utama){
/*============================================================================================================================================================*/
/*                                                             PROSES CASE 1 / PROSES TARIK TUNAI                                                             */
/*============================================================================================================================================================*/
        		case 1 :
            		tarik :
        			header();
            		header_tarik_tunai();
            		
					cout << "Silahkan masukkan uang yang ingin anda ambil : \n\n";
					cin >> nominal_tarik_tunai;
            	
					if (nominal_tarik_tunai % 50000 != 0 || nominal_tarik_tunai < 0){
                		cout << "Masukkan total uang dengan pecahan 50000." << endl;
                		system("pause");
               			system("cls");
                		goto tarik;
            		}else{
                		if (nominal_tarik_tunai > saldo_awal){
                    		cout << "SALDO LU GK CUKUP WOI." << endl;
                    		system("pause");
                    		goto menu;
                		}else{
                			saldo_awal -= nominal_tarik_tunai;
                			cout << endl;
							cout << "-------------------------------------------------------------------------------" << endl;
                			cout << "Penarikan Berhasil" << endl;
							cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
							cout << "-------------------------------------------------------------------------------" << endl;
       						cout << "Apakah ingin mencetak struk (Y/T) ? ";
       						cin >> pilihan_cetak_struk;
							cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
       						ofstream struk_atm_tarik;
							struk_atm_tarik.open ("atm_struk_tarik.txt");
							struk_atm_tarik << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
							struk_atm_tarik << "PENARIKAN DARI TABUNGAN" << endl << endl;
							struk_atm_tarik << "Jumlah 	= Rp. " << nominal_tarik_tunai << endl;
							struk_atm_tarik << "Saldo	= Rp. " << saldo_awal << endl << endl;
							struk_atm_tarik << "TARIK TUNAI BERHASIL" << endl;
							struk_atm_tarik << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
							struk_atm_tarik << "CONTACT BOONGAN : 3127/1214126" << endl;
							struk_atm_tarik.close();
       						
       						pilihan_ulang_transaksi_tarik:
							if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       							system("atm_struk_tarik.txt");
       							goto transaksi_tarik_ulang;
							}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
								transaksi_tarik_ulang:
	    						cout << "-------------------------------------------------------------------------------" << endl;
                				cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
								cin >> pilihan_transaksi_ulang;
	    						cout << "-------------------------------------------------------------------------------" << endl;
								
								if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
            						system("cls");
									goto menu;
								}else{
									system("cls");
									header();
		    						cout << "-------------------------------------------------------------------------------" << endl;
                					cout << "Terima Kasih" << endl;
		    						cout << "-------------------------------------------------------------------------------" << endl;
                					system("pause");
                					system("cls");
								}
							}else{
								goto pilihan_ulang_transaksi_tarik;
							}
                		}
        			}
        		break;
/*============================================================================================================================================================*/
/*                                                          PROSES CASE 1 / PROSES TARIK TUNAI END                                                            */
/*============================================================================================================================================================*/


/*============================================================================================================================================================*/
/*                                                             PROSES CASE 2 / PROSES SETOR TUNAI                                                             */
/*============================================================================================================================================================*/
				case 2 :
        	    	setor :
    	    		header();
    	        	header_setor_tunai();
    	        	
	            	cout << "Silahkan masukkan uang yang ingin anda tabung : " << endl << endl;
					cin >> nominal_setor_tunai;
					
					if (nominal_setor_tunai % 50000 != 0 || nominal_setor_tunai < 0){
 	        	    	cout << "masukkan total uang dengan pecahan 50000\n";
    	        		system("pause");
        	        	system("cls");
    	            	goto setor;
    		        }else {
        		        saldo_awal += nominal_setor_tunai;
            		    cout << endl;
						cout << "-------------------------------------------------------------------------------" << endl;
                		cout << "Setor Tunai Berhasil" << endl;
	   					cout << "-------------------------------------------------------------------------------" << endl << endl;
			
						cout << "-------------------------------------------------------------------------------" << endl;
       					cout << "Apakah ingin mencetak struk (Y/T) ? ";
       					cin >> pilihan_cetak_struk;
						cout << "-------------------------------------------------------------------------------" << endl << endl;
       					
       					ofstream struk_atm_setor;
						struk_atm_setor.open ("atm_struk_setor.txt");
						struk_atm_setor << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
						struk_atm_setor << "SETOR TUNAI KE TABUNGAN" << endl << endl;
						struk_atm_setor << "SALDO	= Rp. " << saldo_awal << endl << endl;
						struk_atm_setor << "SETOR TUNAI BERHASIL" << endl;
						struk_atm_setor << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
						struk_atm_setor << "CONTACT BOONGAN : 3127/1214126" << endl;
						struk_atm_setor.close();
       						
       					pilihan_ulang_transaksi_setor:
						if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       						system("atm_struk_setor.txt");
       						goto transaksi_setor_ulang;
						}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
							transaksi_setor_ulang:
							cout << "-------------------------------------------------------------------------------" << endl;
                			cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
							cin >> pilihan_transaksi_ulang;
							cout << "-------------------------------------------------------------------------------" << endl;
							
							if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
            					system("cls");
								goto menu;
							}else{
								system("cls");
								header();
	    						cout << "-------------------------------------------------------------------------------" << endl;
               					cout << "Terima Kasih" << endl;
								cout << "-------------------------------------------------------------------------------" << endl;
                				system("pause");
                				system("cls");
							}
						}else{
							goto pilihan_ulang_transaksi_setor;
						}
    	        	}
	        	break;
/*============================================================================================================================================================*/
/*                                                          PROSES CASE 2 / PROSES SETOR TUNAI END                                                            */
/*============================================================================================================================================================*/

			
/*============================================================================================================================================================*/
/*                                                              PROSES CASE 3 / PROSES CEK SALDO                                                              */
/*============================================================================================================================================================*/
				case 3 :
        			header();
        			header_cek_saldo();
        		
    		        cout << "Total saldo anda sekarang , " << saldo_awal << endl << endl;
					cout << "-------------------------------------------------------------------------------" << endl << endl;
    	        	
					cout << "-------------------------------------------------------------------------------" << endl;
                	cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
					cin >> pilihan_transaksi_ulang;
					cout << "-------------------------------------------------------------------------------" << endl;
							
					if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
            			system("cls");
						goto menu;
					}else{
						system("cls");
						header();
						cout << "-------------------------------------------------------------------------------" << endl;
       					cout << "Terima Kasih" << endl;
						cout << "-------------------------------------------------------------------------------" << endl;
        				system("pause");
        				system("cls");
					}
		        break;
/*============================================================================================================================================================*/
/*                                                            PROSES CASE 3 / PROSES CEK SALDO END                                                            */
/*============================================================================================================================================================*/

			
/*============================================================================================================================================================*/
/*                                                             PROSES CASE 4 / PROSES TRANSFER                                                                */
/*============================================================================================================================================================*/			
				case 4:
        	   		transfer:
	    	       	header();
    	    	   	header_transfer_rekening();
    	       		
    	       		ulangi_pilihan_menu_transfer:
					cout << "1. Transfer Bank Boongan" << endl;
	    			cout << "2. Transfer Bank Lain" << endl << endl;
   					cout << "Masukan Pilihan Menu Transfer : ";
	    			cin >> pilihan_menu_transfer;
    				cout << endl << endl;

// PROSES TRANSFER REKENING BOONGAN        	    
        	    	if (pilihan_menu_transfer == 1){
            			system("cls");
	            		header();
		            	header_transfer_rekening();
		            	
    		        	cin.ignore();
        		    	cout << "Masukan 8 Digit Nomer Rekening Penerima : ";
            			getline(cin, nomer_rekening_transfer);
            			cout << endl;
						cout << "Masukan Nominal Uang yang Ingin di Transfer : ";
						cin >> nominal_transfer;
						cout << endl;

	            		if (nomer_rekening_transfer.length() == 8){
    	        			if (nominal_transfer > saldo_awal){
        	            		cout << "SALDO LU GK CUKUP WOI.";
            	        		goto transfer;
                			}else {
                				saldo_awal -= nominal_transfer;
                				cout << endl;
	    						cout << "-------------------------------------------------------------------------------" << endl;
                				cout << "Transfer Rekening Berhasil" << endl;
	    						cout << "-------------------------------------------------------------------------------" << endl << endl;
			
	    						cout << "-------------------------------------------------------------------------------" << endl;
       							cout << "Apakah ingin mencetak struk  (Y/T) ?";
       							cin >> pilihan_cetak_struk;
	    						cout << "-------------------------------------------------------------------------------" << endl << endl;

       							ofstream struk_atm_transfer_bank_boongan;
								struk_atm_transfer_bank_boongan.open ("atm_struk_transfer_bank_boongan.txt");
								struk_atm_transfer_bank_boongan << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
								struk_atm_transfer_bank_boongan << "TRANSFER KE REKENING " << nomer_rekening_transfer << endl << endl;
								struk_atm_transfer_bank_boongan << "SALDO	= Rp. " << saldo_awal << endl;
								struk_atm_transfer_bank_boongan << "TRANSFER	= Rp. " << nominal_transfer << endl << endl;
								struk_atm_transfer_bank_boongan << "TRANSFER REKENING BERHASIL" << endl;
								struk_atm_transfer_bank_boongan << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
								struk_atm_transfer_bank_boongan << "CONTACT BOONGAN : 3127/1214126" << endl;
								struk_atm_transfer_bank_boongan.close();
       						
		       					pilihan_ulang_transaksi_transfer_bank_boongan:
								if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       								system("atm_struk_transfer_bank_boongan.txt");
       								goto transaksi_transfer_bank_boongan_ulang;
								}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
									transaksi_transfer_bank_boongan_ulang:
		    						cout << "-------------------------------------------------------------------------------" << endl;
                					cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
									cin >> pilihan_transaksi_ulang;
		    						cout << "-------------------------------------------------------------------------------" << endl;

									if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
        		    					system("cls");
										goto menu;
									}else{
										system("cls");
										header();
		    							cout << "-------------------------------------------------------------------------------" << endl;
               							cout << "Terima Kasih" << endl;
			    						cout << "-------------------------------------------------------------------------------" << endl;
                						system("pause");
        		        				system("cls");
									}
								}else{
									goto pilihan_ulang_transaksi_transfer_bank_boongan;
								}
        		    		}
    		        	}else {
							cout << "Nomer Rekening Salah";
							system("pause");
							system("cls");
            				goto transfer;
						}
// PROSES TRANSFER REKENING BOONGAN END

// PROSES TRANSFER REKENING BANK LAIN
					}else if (pilihan_menu_transfer == 2){
            			system("cls");
	            		header();
		            	header_transfer_rekening();
		            	
						cin.ignore();
        	    		cout << "Masukan 6 Digit Nomer Rekening Penerima : 030 - ";
	        	    	getline(cin, nomer_rekening_transfer);
    	        		cout << endl;
						cout << "Masukan Nominal Uang yang Ingin di Transfer : ";
						cin >> nominal_transfer;
						cout << endl;
					
	    	        	if (nomer_rekening_transfer.length() == 6){
    	    	    		if (nominal_transfer > saldo_awal){
        	    	        	cout << "SALDO LU GK CUKUP WOI.";
            	    	    	goto transfer;
                			}else {
                				saldo_awal -= nominal_transfer;
                				cout << endl;
		    					cout << "-------------------------------------------------------------------------------" << endl;
                				cout << "Transfer Rekening Bank Lain Berhasil" << endl;
	    						cout << "-------------------------------------------------------------------------------" << endl << endl;
			
	    						cout << "-------------------------------------------------------------------------------" << endl;
       							cout << "Apakah ingin mencetak struk ? (Y/T)";
       							cin >> pilihan_cetak_struk;
	    						cout << "-------------------------------------------------------------------------------" << endl << endl;
       					
       							ofstream struk_atm_transfer_bank_lain;
								struk_atm_transfer_bank_lain.open ("atm_struk_transfer_bank_lain.txt");
								struk_atm_transfer_bank_lain << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
								struk_atm_transfer_bank_lain << "TRANSFER KE REKENING 030 - " << nomer_rekening_transfer << endl << endl;
								struk_atm_transfer_bank_lain << "SALDO		= Rp. " << saldo_awal << endl;
								struk_atm_transfer_bank_lain << "TRANSFER	= Rp. " << nominal_transfer << endl << endl;
								struk_atm_transfer_bank_lain << "TRANSFER REKENING KE BANK LAIN BERHASIL" << endl;
								struk_atm_transfer_bank_lain << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
								struk_atm_transfer_bank_lain << "CONTACT BOONGAN : 3127/1214126" << endl;
								struk_atm_transfer_bank_lain.close();
       						
		       					pilihan_ulang_transaksi_transfer_bank_lain:
								if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       								system("atm_struk_transfer_bank_lain.txt");
       								goto transaksi_transfer_bank_lain_ulang;
								}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
									transaksi_transfer_bank_lain_ulang:
			    					cout << "-------------------------------------------------------------------------------" << endl;
                					cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
									cin >> pilihan_transaksi_ulang;
									cout << "-------------------------------------------------------------------------------" << endl;

									if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
        		    					system("cls");
										goto menu;
									}else{
										system("cls");
										header();
	    								cout << "-------------------------------------------------------------------------------" << endl;
               							cout << "Terima Kasih" << endl;
	    								cout << "-------------------------------------------------------------------------------" << endl;
                						system("pause");
        		        				system("cls");
									}
								}else{
									goto pilihan_ulang_transaksi_transfer_bank_lain;
								}	
            	    		}
    	        		}else {
							cout << "Nomer Rekening Salah";
							system("pause");
							system("cls");
        	    			goto transfer;
						}
// PROSES TRANSFER REKENING BANK LAIN END

					}else{
						cout << "Pilihan yang anda masukan salah";
						goto ulangi_pilihan_menu_transfer;
					}
        		break;
/*============================================================================================================================================================*/
/*                                                             PROSES CASE 4 / PROSES TRANSFER END                                                            */
/*============================================================================================================================================================*/


/*============================================================================================================================================================*/
/*                                                                PROSES CASE 5 / PROSES PEMBAYARAN                                                           */
/*============================================================================================================================================================*/
		        case 5:
    		    	header();
        			header_pembayaran();
        			
					cout << "1. Telepon Seluler			3. Cicilan" << endl;
					cout << "2. PLN					4. Tiket" << endl << endl;
        			cout << "Pilih menu Pembayaran : " ;
					cin >> pilihan_menu_pembayaran;
					
// PROSES PEMBAYARAN TELEPON SELULER
					if (pilihan_menu_pembayaran == 1){
						system("cls");
						header();
						header_pembayaran_telepon_seluler();
						
						cout << "Masukan Nomer Telepon Seluler anda = +62 ";
						cin >> nomer_pembayaran_telepon_seluler;
						cout << "Masukan Nominal topup anda = ";
						cin >> nominal_pembayaran_telepon_seluler;		
		
						if (nominal_pembayaran_telepon_seluler > saldo_awal){
                    		cout << "SALDO LU GK CUKUP WOI." << endl;
                    		system("pause");
                    		goto menu;
                		}else{
                			saldo_awal -= nominal_pembayaran_telepon_seluler;
                			cout << endl;
	    					cout << "-------------------------------------------------------------------------------" << endl;
                			cout << "Topup Telepon Seluler Berhasil" << endl;
	    					cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
	    					cout << "-------------------------------------------------------------------------------" << endl;
       						cout << "Apakah ingin mencetak struk (Y/T) ? ";
       						cin >> pilihan_cetak_struk;
	    					cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
       						ofstream struk_atm_pembayaran_telepon_seluler;
							struk_atm_pembayaran_telepon_seluler.open ("atm_struk_pembayaran_telepon_seluler.txt");
							struk_atm_pembayaran_telepon_seluler << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
							struk_atm_pembayaran_telepon_seluler << "TOPUP TELEPON SELULER" << endl << endl;
							struk_atm_pembayaran_telepon_seluler << "NO. TELEPON SELULER 	= +62 " << nomer_pembayaran_telepon_seluler << endl;
							struk_atm_pembayaran_telepon_seluler << "JUMLAH 			= Rp. " << nominal_pembayaran_telepon_seluler << endl;
							struk_atm_pembayaran_telepon_seluler << "SALDO			= Rp. " << saldo_awal << endl << endl;
							struk_atm_pembayaran_telepon_seluler << "TOPUP TELEPON SELULER BERHASIL" << endl;
							struk_atm_pembayaran_telepon_seluler << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
							struk_atm_pembayaran_telepon_seluler << "CONTACT BOONGAN : 3127/1214126" << endl;
							struk_atm_pembayaran_telepon_seluler.close();
       						
       						pilihan_ulang_transaksi_pembayaran_telepon_seluler:
							if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       							system("atm_struk_pembayaran_telepon_seluler.txt");
       							goto transaksi_pembayaran_telepon_seluler_ulang;
							}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
								transaksi_pembayaran_telepon_seluler_ulang:
            					cout << "-------------------------------------------------------------------------------" << endl;
                				cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
								cin >> pilihan_transaksi_ulang;
            					cout << "-------------------------------------------------------------------------------" << endl;
								
								if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
            						system("cls");
									goto menu;
								}else{
									system("cls");
									header();
    	        					cout << "-------------------------------------------------------------------------------" << endl;
                					cout << "Terima Kasih" << endl;
        	    					cout << "-------------------------------------------------------------------------------" << endl;
                					system("pause");
                					system("cls");
								}
							}else{
								goto pilihan_ulang_transaksi_pembayaran_telepon_seluler;
							}
                		}
// PROSES PEMBAYARAN TELEPON SELULER END

// PROSES PEMBAYARAN PLN
					}else if (pilihan_menu_pembayaran == 2){
						system("cls");
						header();
						header_pembayaran_pln();
						
						cout << "Masukan Nomer Tagihan PLN anda = TL-";
						cin >> nomer_pembayaran_PLN;
						cout << "Masukan Nominal tagihan anda = ";
						cin >> nominal_pembayaran_PLN;
						
						if (nominal_pembayaran_PLN > saldo_awal){
                    		cout << "SALDO LU GK CUKUP WOI." << endl;
                    		system("pause");
                    		goto menu;
                		}else{
                			saldo_awal -= nominal_pembayaran_PLN;
                			cout << endl;
        					cout << "-------------------------------------------------------------------------------" << endl;
                			cout << "Pembayaran Tagihan PLN Berhasil" << endl;
        					cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
            				cout << "-------------------------------------------------------------------------------" << endl;
       						cout << "Apakah ingin mencetak struk (Y/T) ? ";
       						cin >> pilihan_cetak_struk;
        					cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
       						ofstream struk_atm_pembayaran_PLN;
							struk_atm_pembayaran_PLN.open ("atm_struk_pembayaran_PLN.txt");
							struk_atm_pembayaran_PLN << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
							struk_atm_pembayaran_PLN << "PEMBAYARAN PLN" << endl << endl;
							struk_atm_pembayaran_PLN << "NO. PLN 	= TL-" << nomer_pembayaran_PLN << endl;
							struk_atm_pembayaran_PLN << "JUMLAH 		= Rp. " << nominal_pembayaran_PLN << endl;
							struk_atm_pembayaran_PLN << "SALDO		= Rp. " << saldo_awal << endl << endl;
							struk_atm_pembayaran_PLN << "PEMBAYARAN TAGIHAN PLN BERHASIL" << endl;
							struk_atm_pembayaran_PLN << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
							struk_atm_pembayaran_PLN << "CONTACT BOONGAN : 3127/1214126" << endl;
							struk_atm_pembayaran_PLN.close();
       						
       						pilihan_ulang_transaksi_pembayaran_PLN:
							if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       							system("atm_struk_pembayaran_PLN.txt");
       							goto transaksi_pembayaran_PLN_ulang;
							}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
								transaksi_pembayaran_PLN_ulang:
            					cout << "-------------------------------------------------------------------------------" << endl;
                				cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
								cin >> pilihan_transaksi_ulang;
            					cout << "-------------------------------------------------------------------------------" << endl;
								
								if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
            						system("cls");
									goto menu;
								}else{
									system("cls");
									header();
                					cout << "-------------------------------------------------------------------------------" << endl;
                					cout << "Terima Kasih" << endl;
                					cout << "-------------------------------------------------------------------------------" << endl;
                					system("pause");
                					system("cls");
								}
							}else{
								goto pilihan_ulang_transaksi_pembayaran_PLN;
							}
                		}
// PROSES PEMBAYARAN PLN END
                		
// PROSES PEMBAYARAN CICILAN
					}else if (pilihan_menu_pembayaran == 3){
						system("cls");
						header();
						header_pembayaran_cicilan();
						
						cout << "Masukan Nomer Tagihan Cicilan anda = CN-";
						cin >> nomer_pembayaran_cicilan;
						cout << "Masukan Nominal Pembayaran anda = ";
						cin >> nominal_pembayaran_cicilan;

						if (nominal_pembayaran_cicilan > saldo_awal){
                    		cout << "SALDO LU GK CUKUP WOI." << endl;
                    		system("pause");
                    		goto menu;
                		}else{
                			saldo_awal -= nominal_pembayaran_cicilan;
                			cout << endl;
        					cout << "-------------------------------------------------------------------------------" << endl;
                			cout << "Pembayaran Cicilan Berhasil" << endl;
        					cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
        					cout << "-------------------------------------------------------------------------------" << endl;
       						cout << "Apakah ingin mencetak struk (Y/T) ? ";
       						cin >> pilihan_cetak_struk;
        					cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
       						ofstream struk_atm_pembayaran_cicilan;
							struk_atm_pembayaran_cicilan.open ("atm_struk_pembayaran_cicilan.txt");
							struk_atm_pembayaran_cicilan << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
							struk_atm_pembayaran_cicilan << "PEMBAYARAN CICILAN" << endl << endl;
							struk_atm_pembayaran_cicilan << "NO. CICILAN 	= CN-" << nomer_pembayaran_cicilan << endl;
							struk_atm_pembayaran_cicilan << "JUMLAH 		= Rp. " << nominal_pembayaran_cicilan << endl;
							struk_atm_pembayaran_cicilan << "SALDO		= Rp. " << saldo_awal << endl << endl;
							struk_atm_pembayaran_cicilan << "PEMBAYARAN CICILAN BERHASIL" << endl;
							struk_atm_pembayaran_cicilan << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
							struk_atm_pembayaran_cicilan << "CONTACT BOONGAN : 3127/1214126" << endl;
							struk_atm_pembayaran_cicilan.close();
       						
       						pilihan_ulang_transaksi_pembayaran_cicilan:
							if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       							system("atm_struk_pembayaran_cicilan.txt");
       							goto transaksi_pembayaran_cicilan_ulang;
							}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
								transaksi_pembayaran_cicilan_ulang:
   	        					cout << "-------------------------------------------------------------------------------" << endl;
                				cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
								cin >> pilihan_transaksi_ulang;
            					cout << "-------------------------------------------------------------------------------" << endl;
								
								if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
            						system("cls");
									goto menu;
								}else{
									system("cls");
									header();
                					cout << "-------------------------------------------------------------------------------" << endl;
                					cout << "Terima Kasih" << endl;
                					cout << "-------------------------------------------------------------------------------" << endl;
                					system("pause");
                					system("cls");
								}
							}else{
								goto pilihan_ulang_transaksi_pembayaran_cicilan;
							}
                		}
// PROSES PEMBAYARAN CICILAN END

// PROSES PEMBAYARAN TIKET
					}else if (pilihan_menu_pembayaran == 4){
						system("cls");
						header();
						header_pembayaran_tiket();
						
						cout << "Masukan Kode Pembayaran Tiket anda = STN-";
						cin >> nomer_pembayaran_tiket;
						cout << "Masukan Nominal pembayaran anda = ";
						cin >> nominal_pembayaran_tiket;
				
						if (nominal_pembayaran_tiket > saldo_awal){
                    		cout << "SALDO LU GK CUKUP WOI." << endl;
                    		system("pause");
                    		goto menu;
                		}else{
                			saldo_awal -= nominal_pembayaran_tiket;
                			cout << endl;
                			cout << "-------------------------------------------------------------------------------" << endl;
                			cout << "Pembayaran Tiket Berhasil" << endl;
                			cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
                			cout << "-------------------------------------------------------------------------------" << endl;
       						cout << "Apakah ingin mencetak struk (Y/T) ? ";
       						cin >> pilihan_cetak_struk;
                			cout << "-------------------------------------------------------------------------------" << endl << endl;
       						
       						ofstream struk_atm_pembayaran_tiket;
							struk_atm_pembayaran_tiket.open ("atm_struk_pembayaran_tiket.txt");
							struk_atm_pembayaran_tiket << "BANK BOONGAN WAKANDA FOREVER" << endl << endl;
							struk_atm_pembayaran_tiket << "PEMBAYARAN TIKET" << endl << endl;
							struk_atm_pembayaran_tiket << "NO. TIKET 	= STN-" << nomer_pembayaran_tiket << endl;
							struk_atm_pembayaran_tiket << "JUMLAH 		= Rp. " << nominal_pembayaran_tiket << endl;
							struk_atm_pembayaran_tiket << "SALDO		= Rp. " << saldo_awal << endl << endl;
							struk_atm_pembayaran_tiket << "PEMBAYARAN TIKET BERHASIL" << endl;
							struk_atm_pembayaran_tiket << "TERIMAKASIH TELAH MENGGUNAKAN ATM BOONGAN" << endl;
							struk_atm_pembayaran_tiket << "CONTACT BOONGAN : 3127/1214126" << endl;
							struk_atm_pembayaran_tiket.close();
       						
       						pilihan_ulang_transaksi_pembayaran_tiket:
							if (pilihan_cetak_struk == 'Y' || pilihan_cetak_struk == 'y'){
       							system("atm_struk_pembayaran_tiket.txt");
       							goto transaksi_pembayaran_tiket_ulang;
							}else if (pilihan_cetak_struk == 'T' || pilihan_cetak_struk == 't'){
								transaksi_pembayaran_tiket_ulang:
               					cout << "-------------------------------------------------------------------------------" << endl;
                				cout << "Apakah ingin melakukan transaksi lain (Y/T) ? ";
								cin >> pilihan_transaksi_ulang;
               					cout << "-------------------------------------------------------------------------------" << endl;
								
								if (pilihan_transaksi_ulang == 'Y' || pilihan_transaksi_ulang == 'y'){
            						system("cls");
									goto menu;
								}else{
									system("cls");
									header();
                					cout << "-------------------------------------------------------------------------------" << endl;
                					cout << "Terima Kasih" << endl;
                					cout << "-------------------------------------------------------------------------------" << endl;
                					system("pause");
                					system("cls");
								}
							}else{
								goto pilihan_ulang_transaksi_pembayaran_tiket;
							}
                		}				
					}
// PROSES PEMBAYARAN TIKET END
        		break;
/*============================================================================================================================================================*/
/*                                                            PROSES CASE 5 / PROSES PEMBAYARAN END                                                           */
/*============================================================================================================================================================*/
        
				case 6:
        			footer();
        		break;
        
        		default :
            		cout << "\nKode yang anda pilih tidak ada , \npastikan kode yang anda masukkan benar\n";
            		system("pause");
            		system("cls");
            		header();
            		goto menu;
        		break;
						
			}
    	}else{
    		ulangi_pin++;
		}
	system("cls");
	
	}while (ulangi_pin < 3);
	
	header();
    cout << "===============================================================================" << endl << endl;
	cout << "      ANDA SALAH MEMASUKAN PIN SEBANYAK 3x, AKUN ANDA TERPAKSA DIBLOKIR." << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	cout << setw(46) << "PERINGATAN!!!" << endl << endl;
	cout << "      SUDAH 3x SALAH, INGAT JANGAN NGAMBIL MILIK ORANG LAIN, INGAT DOSA" << endl << endl;
    cout << "===============================================================================" << endl;
}




/* FUNCTION HEADER */
void header(){
    cout << "===============================================================================" << endl;
    cout << setw(60) << "ATM Boongan by WAKANDA FOREVER with C++" << endl;
    cout << setw(55) << "Pecahan 50.000 gk bisa Nego :v" << endl;
    cout << "===============================================================================" << endl << endl;
}
void header_tarik_tunai(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "Tarik Tunai" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_setor_tunai(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "Setor Tunai" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_cek_saldo(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "Cek Saldo" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_transfer_rekening(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "Transfer Rekening" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_pembayaran(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "Pembayaran" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_pembayaran_telepon_seluler(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "Topup Telepon Seluler" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_pembayaran_pln(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "Pembayaran Tagihan PLN" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_pembayaran_cicilan(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "Pembayaran Cicilan" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
void header_pembayaran_tiket(){
	cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "Pembayaran Tiket" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
}

void footer(){
    cout << "===============================================================================" << endl;
    cout << setw(50) << "Terima Kasih atas kunjungan anda" << endl;
    cout << setw(52) << "Silahkan cek kembali uang anda" << endl;
    cout << "\t dan pastikan tidak ada barang yang tertinggal" << endl;
    cout << "===============================================================================" << endl;
}
