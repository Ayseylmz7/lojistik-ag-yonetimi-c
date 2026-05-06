//
//  main.c
//  LojistikProje
//
//  Created by Ayşe Yılmaz on 5.05.2026.

#include <stdio.h>
#include "yapilar.h"

int main(int argc, const char * argv[]) {
    printf("=== LOJİSTİK SİSTEMİ BAŞLATILIYOR (No: 5250505062) ===\n\n");

    // 1. Hash Tablosu İşlemleri
    Paket hashTablosu[TABLO_BOYUTU];
    for (int i = 0; i < TABLO_BOYUTU; i++) hashTablosu[i].dolu_mu = 0;

    printf("[1] PAKETLER EKLENİYOR (Açık Adresleme Simülasyonu)\n");
    paket_ekle(hashTablosu, 102, "Elektronik");
    paket_ekle(hashTablosu, 202, "Kozmetik");  // Çakışma yaratacak (102 ve 202 modulo 10'da 2 verir)
    paket_ekle(hashTablosu, 305, "Gıda");
    paket_ekle(hashTablosu, 105, "Tekstil");   // Çakışma yaratacak
    paket_ekle(hashTablosu, 401, "Kitap");

    hash_yazdir_ve_bellek(hashTablosu);

    // 2. Graf İşlemleri
    printf("\n[2] ŞEHİR AĞI OLUŞTURULUYOR\n");
    Graf* lojistik_agi = graf_olustur(SEHIR_SAYISI);
    
    // Örnek yollar ekleniyor
    kenar_ekle(lojistik_agi, 0, 1);
    kenar_ekle(lojistik_agi, 0, 2);
    kenar_ekle(lojistik_agi, 1, 3);
    kenar_ekle(lojistik_agi, 2, 4);
    kenar_ekle(lojistik_agi, 3, 4);

    graf_yazdir_ve_bellek(lojistik_agi);

    // 3. Rota Sorgulama (BFS)
    BFS_gezinme(lojistik_agi, 0);

    return 0;
}
