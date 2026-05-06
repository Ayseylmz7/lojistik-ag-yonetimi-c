//
//  hash.c
//  LojistikProje
//
//  Created by Ayşe Yılmaz on 5.05.2026.

#include <stdio.h>
#include <string.h>
#include "yapilar.h"

// Tip A: Modulo Hash Fonksiyonu
int hash_fonksiyonu(int key) {
    return key % TABLO_BOYUTU;
}

// Açık Adresleme (Lineer Yoklama) ile Ekleme
void paket_ekle(Paket tablo[], int id, const char* icerik) {
    int index = hash_fonksiyonu(id);
    int baslangic_index = index;

    // Slot doluysa (Çakışma varsa) bir sonrakine geç
    while (tablo[index].dolu_mu) {
        printf(" -> Çakışma! Paket %d için İndis %d dolu. Sonrakine bakılıyor...\n", id, index);
        index = (index + 1) % TABLO_BOYUTU;
        
        if (index == baslangic_index) {
            printf("Hata: Tablo tamamen dolu!\n");
            return;
        }
    }

    tablo[index].id = id;
    strcpy(tablo[index].icerik, icerik);
    tablo[index].dolu_mu = 1;
    printf("Paket %d, İndis %d'ye eklendi.\n", id, index);
}

// Rapor için Bellek Adreslerini Yazdırma
void hash_yazdir_ve_bellek(Paket tablo[]) {
    printf("\n--- HASH TABLOSU BELLEK DURUMU ---\n");
    for (int i = 0; i < TABLO_BOYUTU; i++) {
        if (tablo[i].dolu_mu) {
            // %p formatı RAM'deki gerçek adresi (0x...) verir
            printf("İndis %d | Paket: %d | İçerik: %-10s | RAM Adresi: %p\n",
                   i, tablo[i].id, tablo[i].icerik, (void*)&tablo[i]);
        }
    }
}
