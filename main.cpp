#include "tubes.h"
using namespace std;

#include <iostream>


int main() {
    ListToko listToko;
    ListItem listItem;

    createLT(listToko);
    createLI(listItem);
    string jenisP, namaP,  warnaP,ukuranP,namaT;
    opening();

    int choice = -1;
    while (choice != 0) {
        menu();
        cin >> choice;

        if (choice == 1) {
            // Tambah Toko
            infotype_toko tokoInfo;
            cout<<endl;
            cout << "Masukkan nama toko: ";
            cin >> tokoInfo.nama_toko;
            cout << "Masukkan lokasi toko: ";
            cin >> tokoInfo.lokasi_toko;
            cout << "Masukkan rating toko: ";
            cin >> tokoInfo.rating_toko;

            adr_toko newToko = createNewElmToko(tokoInfo);
            insertLastToko(listToko, newToko);
            cout<<endl;
            cout << "Toko berhasil ditambahkan!" << endl;
            showToko(listToko);
        } else if (choice == 2) {
            // Tambah Produk
            infotype_item itemInfo;
            cout<<endl;
            cout << "Masukkan jenis produk: ";
            cin >> itemInfo.jenis;
            cout << "Masukkan nama produk: ";
            cin >> itemInfo.nama_item;
            cout << "Masukkan ukuran produk: ";
            cin >> itemInfo.ukuran_item;
            cout << "Masukkan warna produk: ";
            cin >> itemInfo.warna_item;

            adr_item P = findItem(listItem, itemInfo.jenis, itemInfo.nama_item, itemInfo.ukuran_item, itemInfo.warna_item);
            if (P!=NULL){
                cout<<"Produk sudah terdaftar, silahkan hubungkan ke toko"<<endl;
            }else{
                adr_item newItem = createNewElmItem(itemInfo);
                insertLastItem(listItem, newItem);
                 cout << "Produk berhasil ditambahkan!" << endl;
            }



        } else if (choice == 3) {
            // Hubungkan Toko dengan Produk
            string namaToko, jenisItem, namaItem, ukuranItem, warnaItem;
            cout<<endl;
            cout << "Masukkan nama toko: ";
            cin >> namaToko;
            cout << "Masukkan jenis produk: ";
            cin >> jenisItem;
            cout << "Masukkan nama produk: ";
            cin >> namaItem;
            cout << "Masukkan ukuran produk: ";
            cin >> ukuranItem;
            cout << "Masukkan warna produk: ";
            cin >> warnaItem;

            connectTokotoItem(listToko, listItem, namaToko, jenisItem, namaItem, ukuranItem, warnaItem);

            cout << "Hubungan toko dengan produk berhasil dibuat!" << endl;
            showTokoAndItem(listToko);

        }else if (choice ==4){
            //cari detail toko
            findToko(listToko);

        }else if (choice == 5){

            //find produk apakah ada atau tidak
            cout<<"Jenis produk: ";
            cin>> jenisP;
            cout<< "Nama produk: ";
            cin>> namaP;
            cout<< "Ukuran produk: ";
            cin>> ukuranP;
            cout<<"Warna produk: ";
            cin>> warnaP;
            if (findItem(listItem,jenisP,namaP,ukuranP, warnaP)== NULL){
                cout<< "Produk tidak ditemukan";
            }else{
                cout<< "Produk ditemukan ";
            }


        }else if (choice ==6){
            //Cari Detail Produk di suatu Toko
            cout<<endl;
            cout<< "Nama produk: ";
            cin>> namaP;
            cout<<"Dari toko: ";
            cin>> namaT;

            adr_item Q = findItemInToko(listToko,namaT,namaP);

            if (Q != NULL) {
            cout<<""<<endl;
            cout << "Detail produk"<< Q->info.nama_item<< "di toko " << namaT << ":" << endl;
            cout << "Jenis produk: " << Q->info.jenis << endl;
            cout << "Nama produk: " << Q->info.nama_item << endl;
            cout << "Ukuran produk: " << Q->info.ukuran_item << endl;
            cout << "Warna produk: " << Q->info.warna_item << endl;
            } else {
            cout << "Produk tidak ditemukan di toko " << namaT << endl;
            }

        }else if (choice==7){
            //hapus toko
            cout<<endl;
            cout<< "Nama toko yang akan dihapus: ";
            cin>>namaT;
            delTokowithRelation(listToko,namaT);

        }else if (choice==8){
            //hapus produk di suatu toko
            cout<<endl;
            cout<< "Nama produk: ";
            cin>>namaP;
            cout<< "Dari toko: ";
            cin>> namaT;

            delItemDiTokoTertentu(listToko,namaP,namaT);

        }else if (choice==9){
            //tampil list toko
            showToko(listToko);

        }else if (choice ==10){
            //tampil list produk
            showItem(listItem);

        }else if (choice==11){
            // Tampil List Toko & Produk
           showTokoAndItem(listToko);

        }else if (choice == 12){
           //jumlah produk di toko
            cout<<endl;
            cout<< "Nama toko: ";
            cin>> namaT;
            cout<< countItemInToko(listToko,namaT)<<endl;

        }else if (choice == 0) {
            cout << "Terima kasih telah menggunakan kiw kiw E-commerce!" << endl;

        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }


    return 0;
}
