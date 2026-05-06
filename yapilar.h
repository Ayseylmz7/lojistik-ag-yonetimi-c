//
//  yapilar.h
//  LojistikProje
//
//  Created by Ayşe Yılmaz on 5.05.2026.
//

#ifndef yapilar_h
#define yapilar_h

#endif /* yapilar_h */
#ifndef YAPILAR_H
#define YAPILAR_H

#define TABLO_BOYUTU 10
#define SEHIR_SAYISI 5

// --- HASH TABLOSU (Paketler) ---
typedef struct {
    int id;
    char icerik[50];
    int dolu_mu; // Açık adresleme (Lineer Yoklama) için slot kontrolü
} Paket;

// --- GRAF (Şehir Bağlantıları) ---
typedef struct KomsuNode {
    int sehir_index;
    struct KomsuNode* next;
} KomsuNode;

typedef struct {
    int toplam_sehir;
    KomsuNode** komsuluk_listesi;
} Graf;

// --- FONKSİYON PROTOTİPLERİ ---
void paket_ekle(Paket tablo[], int id, const char* icerik);
void hash_yazdir_ve_bellek(Paket tablo[]);

Graf* graf_olustur(int sehir_sayisi);
void kenar_ekle(Graf* graf, int kaynak, int hedef);
void graf_yazdir_ve_bellek(Graf* graf);
void BFS_gezinme(Graf* graf, int baslangic);

#endif
