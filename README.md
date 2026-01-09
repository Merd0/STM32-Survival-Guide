# STM32 GPIO & Algorithm Survival Guide

![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-STM32F4-orange?style=flat-square)
![Topic](https://img.shields.io/badge/Domain-Embedded_Systems-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Active-blueviolet?style=flat-square)

## 📖 Proje Özeti
Bu depo, **Fırat Üniversitesi Bilgisayar Mühendisliği** Mikroişlemciler müfredatını desteklemek amacıyla oluşturulmuş kapsamlı bir gömülü sistemler kütüphanesidir. 

Proje, STM32 mimarisi üzerinde **GPIO Yönetimi**, **Bitwise Manipülasyon**, **Multiplexing (Zaman Paylaşımlı Tarama)** ve **Input De-bouncing** tekniklerini içeren optimize edilmiş C algoritmalarını barındırır. Amaç, teorik bilgiyi endüstriyel kodlama pratiklerine dönüştürmektir.

---

## 🛠️ Donanım Konfigürasyonu
Kodların hedeflenen donanım üzerindeki pin haritalaması aşağıdaki gibidir:

| Bileşen | Port & Pinler | Fonksiyon |
| :--- | :--- | :--- |
| **Dahili LED'ler** | `GPIOD` [12, 13, 14, 15] | Durum Göstergeleri (Yeşil, Turuncu, Kırmızı, Mavi) |
| **Giriş Birimleri** | `GPIOA` [0, 13, 14] | User Button ve Harici Tetikleyiciler |
| **7-Segment (MUX)** | `GPIOE` [4, 5, 6, 7] | Hane Seçimi (Digit Select / Common Pins) |
| **7-Segment (Data)** | `GPIOE` [8 - 15] | Segment Veri Hattı (A-G, DP) |

---

## 📂 Algoritma Kütüphanesi

### 1. Modül: GPIO Output Algoritmaları
*Konum:* `01_GPIO_Output/`  
Bu modül, çıkış birimlerinin matematiksel ve mantıksal operatörler ile kontrolüne odaklanır.

| Dosya Adı (Source Code) | Teknik Açıklama | Seviye |
| :--- | :--- | :--- |
| [📂 01_sirali_akis.c](./01_GPIO_Output/01_sirali_akis.c) | Temel sıralı iterasyon ve pin manipülasyonu. | Başlangıç |
| [📂 02_kara_simsek.c](./01_GPIO_Output/02_kara_simsek.c) | Çift yönlü tarama algoritması (Ping-Pong logic). | Orta |
| [📂 03_binary_counter.c](./01_GPIO_Output/03_binary_counter.c) | 4-Bit Binary sayıcı implementasyonu (Bitwise Shifting). | İleri |
| [📂 04_polis_cakari.c](./01_GPIO_Output/04_polis_cakari.c) | Asenkron grup flaşör algoritması. | Orta |
| [📂 05_yilan_efekti.c](./01_GPIO_Output/05_yilan_efekti.c) | Modulo aritmetiği ile dairesel kuyruk yapısı. | Orta |
| [📂 06_ozel_desen.c](./01_GPIO_Output/06_ozel_desen.c) | Array-based (Dizi tabanlı) özel animasyon motoru. | Orta |
| [📂 07_yukleme_cubugu.c](./01_GPIO_Output/07_yukleme_cubugu.c) | Kümülatif artış mantığı (Loading Bar simulation). | Başlangıç |
| [📂 08_ters_binary.c](./01_GPIO_Output/08_ters_binary.c) | Bitwise NOT (~) operatörü ile negatif lojik. | İleri |
| [📂 09_hayalet_iz.c](./01_GPIO_Output/09_hayalet_iz.c) | **Software PWM** ve Decay algoritması ile analog parlaklık kontrolü. | Uzman |

### 2. Modül: GPIO Input ve Multiplexing
*Konum:* `02_GPIO_Input/`  
Bu modül, Look-Up Table (Matris) yönetimi, 7-Segment Multiplexing ve giriş sinyali işleme tekniklerini kapsar.

| Dosya Adı (Source Code) | Teknik Açıklama | Seviye |
| :--- | :--- | :--- |
| [📂 01_basit_kontrol.c](./02_GPIO_Input/01_basit_kontrol.c) | Look-Up Table ile temel buton-segment etkileşimi. | Başlangıç |
| [📂 02_hedefli_yazdirma.c](./02_GPIO_Input/02_hedefli_yazdirma.c) | Input tabanlı hane (Digit) adresleme. | Orta |
| [📂 03_butonlu_sayac.c](./02_GPIO_Input/03_butonlu_sayac.c) | **Non-Blocking** Multiplexing taraması sırasında giriş okuma. | Uzman |
| [📂 04_kapi_zili_basitDuzey.c](./02_GPIO_Input/04_kapi_zili_basitDuzey.c) | Direct-Drive giriş kontrol mantığı. | Başlangıç |
| [📂 05_akilli_lamba_basitDuzey.c](./02_GPIO_Input/05_akilli_lamba_basitDuzey.c) | Durum makinesi (State Machine) ile Toggle Switch yapısı. | İleri |
| [📂 05_vites_kutusu_basitDuzey.c](./02_GPIO_Input/05_vites_kutusu_basitDuzey.c) | Switch-Case yapısı ile sıralı mod değişimi. | İleri |
| [📂 07_guvenlik_kilidi_basitDuzey.c](./02_GPIO_Input/07_guvenlik_kilidi_basitDuzey.c) | Mantıksal AND kapısı (`&&`) ile çoklu giriş doğrulama. | Orta |
| [📂 08_refleks_testi_basitDuzey.c](./02_GPIO_Input/08_refleks_testi_basitDuzey.c) | Tepki süresi ölçümü ve blocking-loop yönetimi. | İleri |

---

## 🚀 Entegrasyon

Bu algoritmalar **STM32CubeIDE** ve **HAL Kütüphanesi** ile tam uyumludur. Kullanmak istediğiniz algoritmanın kaynak kodunu (Raw Code) projenizdeki `main.c` dosyasının `while(1)` döngüsü içerisine entegre edebilirsiniz.

> **Not:** Input/Display modülleri için gerekli olan global dizi tanımlamaları (Look-Up Tables) ilgili dosyaların başlık kısmında (Header) belirtilmiştir.

---

**Maintainer:** Mert  
*Computer Engineering Dept. @ Fırat University*
