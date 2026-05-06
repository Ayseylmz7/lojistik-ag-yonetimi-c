# lojistik-ag-yonetimi-c
C dili ile geliştirilmiş; Hash (Açık Adresleme) ve Graf (BFS) veri yapıları kullanan lojistik ağ optimizasyonu ve kargo takip simülasyonu.
# Lojistik Ağ Yönetimi ve Hibrit Veri Yapıları 🚚

Bu proje, Veri Yapıları ve Algoritmalar dersi kapsamında C dili ile geliştirilmiş bir lojistik simülasyonudur. Sistem, kargo paketlerinin takibi ve şehirler arası rotaların optimizasyonu için hibrit veri yapıları kullanmaktadır.

## 🛠️ Kullanılan Teknolojiler ve Algoritmalar

* **Programlama Dili:** C
* **Paket Yönetimi (Hash Tablosu):** * Tip A Hash Fonksiyonu (Modulo)
    * Çakışma Çözümü: Açık Adresleme (Lineer Yoklama / Linear Probing)
* **Ağ Yönetimi (Graf):**
    * Komşuluk Listesi (Adjacency List)
    * Rota Gezinme Algoritması: BFS (Genişlik Öncelikli Arama / Breadth-First Search)

## 📁 Proje Yapısı

Proje, mantıksal katmanlara ayrılmış çoklu dosya yapısı ile kurgulanmıştır:
* `yapilar.h` : Tüm struct (Paket, Graf, KomsuNode) tanımları ve prototipler.
* `hash.c` : O(1) karmaşıklığında paket ekleme ve lineer yoklama işlemleri.
* `graf.c` : Dinamik bellek (malloc) ile graf oluşturma ve BFS rota taraması.
* `main.c` : Sistemin başlatılması ve simülasyonun yürütülmesi.

## 🚀 Nasıl Çalıştırılır?

Projeyi derlemek ve çalıştırmak için terminal (veya komut satırı) üzerinden aşağıdaki komutları kullanabilirsiniz:

```bash
gcc main.c hash.c graf.c -o lojistik_sistemi
./lojistik_sistemi
