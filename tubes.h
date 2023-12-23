#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

struct infotype_toko{
    string nama_toko;
    string lokasi_toko;
    float rating_toko;
};

typedef struct elm_toko *adr_toko;
typedef struct elm_item *adr_item;

typedef struct elm_relation *adr_relation;
struct elm_relation{
    adr_item next_item;
    adr_relation next_relation;
};
struct list_relation{
    adr_relation firstRelation;
};

struct elm_toko{
    infotype_toko info;
    adr_toko next_toko;
    list_relation items;
};

struct infotype_item{
    string jenis; //atasan, celana,rok, topi,sepatu,jacket
    string nama_item;
    string ukuran_item;
    string warna_item;

};


struct elm_item{
    infotype_item info;
    adr_item next;
};

struct ListToko{
    adr_toko firstToko;
};
struct ListItem{
    adr_item firstItem;
};
void opening();
void menu();
void createLT(ListToko &L);
void createLI(ListItem &L);
bool isEmptyToko(ListToko L);
bool isEmptyRelation(list_relation L);
bool isEmptyItem(ListItem L);
adr_toko createNewElmToko( infotype_toko x);
adr_relation createNewElmRelation(adr_item x);
adr_item createNewElmItem(infotype_item x);
void insertLastToko(ListToko &L, adr_toko P );
void insertLastRel(list_relation &L, adr_relation P);
void connectTokotoItem(ListToko &L, ListItem P, string namaToko, string jenisItem, string namaItem, string ukuranItem, string warnaItem );
void insertLastItem(ListItem &L, adr_item P);
adr_toko delFirstToko(ListToko &L);
adr_relation delFirstRel(list_relation &L);
adr_item delFirstItem(ListItem &L);
adr_toko delAfterToko(ListToko &L, adr_toko Prev);
adr_relation delAfterRel(list_relation &L);
adr_item delAfterItem(ListItem &L, adr_item prec);
adr_toko delLastToko(ListToko &L);
adr_relation delLastRel(list_relation &L);
adr_item delLasItem(ListItem &L);
void delTokowithRelation(ListToko &L, string nama);
void delItemDiTokoTertentu(ListToko &L, string namaItem, string namaToko);
void findToko(ListToko L);
adr_toko findTokobyNama(ListToko L, string nama);
adr_item findItem(ListItem L,string jenis, string nama, string ukuran, string warna  );
adr_item findItemInToko(ListToko L, string namaToko, string namaItem);
void showToko(ListToko L); //all toko
void show1Toko(ListToko L, adr_toko P);
void showTokoAndItem(ListToko L);
void showItem(ListItem L);
int countItemInToko(ListToko L, string nama);


#endif // TUBES_H_INCLUDED
