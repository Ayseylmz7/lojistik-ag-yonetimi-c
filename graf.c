//
//  graf.c
//  LojistikProje
//
//  Created by Ayşe Yılmaz on 5.05.2026.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "yapilar.h"

Graf* graf_olustur(int sehir_sayisi) {
    Graf* graf = (Graf*)malloc(sizeof(Graf));
    graf->toplam_sehir = sehir_sayisi;
    graf->komsuluk_listesi = (KomsuNode**)malloc(sehir_sayisi * sizeof(KomsuNode*));
    
    for (int i = 0; i < sehir_sayisi; i++) {
        graf->komsuluk_listesi[i] = NULL;
    }
    return graf;
}

void kenar_ekle(Graf* graf, int kaynak, int hedef) {
    // Kaynaktan hedefe
    KomsuNode* yeni_dugum = (KomsuNode*)malloc(sizeof(KomsuNode));
    yeni_dugum->sehir_index = hedef;
    yeni_dugum->next = graf->komsuluk_listesi[kaynak];
    graf->komsuluk_listesi[kaynak] = yeni_dugum;

    // Hedeften kaynağa (Yönsüz graf)
    yeni_dugum = (KomsuNode*)malloc(sizeof(KomsuNode));
    yeni_dugum->sehir_index = kaynak;
    yeni_dugum->next = graf->komsuluk_listesi[hedef];
    graf->komsuluk_listesi[hedef] = yeni_dugum;
}

void graf_yazdir_ve_bellek(Graf* graf) {
    printf("\n--- GRAF POINTER BAĞLANTILARI (RAM) ---\n");
    for (int i = 0; i < graf->toplam_sehir; i++) {
        KomsuNode* temp = graf->komsuluk_listesi[i];
        printf("Şehir %d (Liste Başı) -> ", i);
        while (temp) {
            printf("[Şehir %d | Adres: %p | Sonraki: %p] -> ",
                   temp->sehir_index, (void*)temp, (void*)temp->next);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// BFS (Breadth-First Search) Kuyruk Mantığı
void BFS_gezinme(Graf* graf, int baslangic) {
    int ziyaret_edildi[SEHIR_SAYISI] = {0};
    int kuyruk[SEHIR_SAYISI];
    int on = 0, arka = 0;

    ziyaret_edildi[baslangic] = 1;
    kuyruk[arka++] = baslangic;

    printf("\n--- BFS GEZİNME ROTASI ---\nRota: ");
    while (on < arka) {
        int guncel = kuyruk[on++];
        printf("%d ", guncel);

        KomsuNode* temp = graf->komsuluk_listesi[guncel];
        while (temp) {
            int komsu = temp->sehir_index;
            if (!ziyaret_edildi[komsu]) {
                ziyaret_edildi[komsu] = 1;
                kuyruk[arka++] = komsu;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
