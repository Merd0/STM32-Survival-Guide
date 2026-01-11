# STM32 GPIO & Algorithm Survival Guide

![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-STM32F4-orange?style=flat-square)
![Topic](https://img.shields.io/badge/Domain-Embedded_Systems-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Active-blueviolet?style=flat-square)

## 📖 Repo Özeti
Bu depo, **Fırat Üniversitesi Bilgisayar Mühendisliği** müfredatını desteklemek ve gömülü sistemler dünyasına adım atan mühendisler için oluşturulmuş kapsamlı bir algoritma kütüphanesidir.

Proje, STM32 mimarisi üzerinde **GPIO Yönetimi**, **Timer Interrupts**, **Multiplexing**, **Finite State Machine (FSM)** ve **Endüstriyel Kodlama Mantığı** gibi temelden ileri seviyeye uzanan optimize edilmiş C algoritmalarını barındırır. Amaç, teorik bilgiyi çalışan, güvenli ve modüler koda dönüştürmektir.

---

## 🛠️ Donanım Konfigürasyonu
Kodların hedeflenen donanım (Deney Kartı) üzerindeki pin haritalaması:

| Bileşen | Port & Pinler | Fonksiyon |
| :--- | :--- | :--- |
| **Dahili LED'ler** | `GPIOD` [12, 13, 14, 15] | Durum Göstergeleri (Yeşil, Turuncu, Kırmızı, Mavi) |
| **Giriş Birimleri** | `GPIOA` [0, 13, 14] | User Button ve Harici Tetikleyiciler |
| **7-Segment (MUX)** | `GPIOE` [4, 5, 6, 7] | Hane Seçimi (Digit Select - Transistör Tetikleme) |
| **7-Segment (Data)** | `GPIOE` [8 - 15] | Segment Veri Hattı (A-G, DP) |

---

## 📂 Algoritma Kütüphanesi

### 1. Modül: GPIO Output Algoritmaları
*Konum:* `01_GPIO_Output/`  
Çıkış birimlerinin matematiksel ve mantıksal operatörler ile kontrolüne odaklanan temel modül.

| Dosya Adı | Teknik Açıklama | Seviye |
| :--- | :--- | :--- |
| `01_sirali_akis.c` | Temel sıralı iterasyon ve pin manipülasyonu. | Başlangıç |
| `02_kara_simsek.c` | Çift yönlü tarama algoritması (Ping-Pong logic). | Orta |
| `03_binary_counter.c` | 4-Bit Binary sayıcı implementasyonu (Bitwise Shifting). | İleri |
| `04_polis_cakari.c` | Asenkron grup flaşör algoritması. | Orta |
| `05_yilan_efekti.c` | Modulo aritmetiği ile dairesel kuyruk yapısı. | Orta |
| `06_ozel_desen.c` | Array-based (Dizi tabanlı) özel animasyon motoru. | Orta |
| `07_yukleme_cubugu.c` | Kümülatif artış mantığı (Loading Bar simulation). | Başlangıç |
| `08_ters_binary.c` | Bitwise NOT (~) operatörü ile negatif lojik. | İleri |
| `09_hayalet_iz.c` | **Software PWM** ve Decay algoritması ile analog parlaklık kontrolü. | Uzman |

### 2. Modül: GPIO Input ve Multiplexing
*Konum:* `02_GPIO_Input/`  
Look-Up Table (Matris) yönetimi, 7-Segment Multiplexing ve giriş sinyali işleme teknikleri.

| Dosya Adı | Teknik Açıklama | Seviye |
| :--- | :--- | :--- |
| `01_basit_kontrol.c` | Look-Up Table ile temel buton-segment etkileşimi. | Başlangıç |
| `02_hedefli_yazdirma.c` | Input tabanlı hane (Digit) adresleme. | Orta |
| `03_butonlu_sayac.c` | **Non-Blocking** Multiplexing taraması sırasında giriş okuma. | Uzman |
| `04_kapi_zili.c` | Direct-Drive giriş kontrol mantığı. | Başlangıç |
| `05_akilli_lamba.c` | Durum makinesi (State Machine) ile Toggle Switch yapısı. | İleri |
| `06_vites_kutusu.c` | Switch-Case yapısı ile sıralı mod değişimi. | İleri |
| `07_guvenlik_kilidi.c` | Mantıksal AND kapısı (`&&`) ile çoklu giriş doğrulama. | Orta |

### 3. Modül: Timer Interrupt & Gömülü Algoritmalar 🚀
*Konum:* `04_Timer_Interrupt_Header_Stopwatch/`  
İşlemciyi meşgul etmeden (Non-blocking) zaman yönetimi ve gelişmiş algoritma senaryoları.

| Dosya Adı | Proje Başlığı | Kazanılan Yetkinlik (Vizyon) |
| :--- | :--- | :--- |
| `01_dk_sn_kronometre` | **Ana Proje: Kronometre** | Timer Interrupt, Multiplexing & Cascade Logic (Zincirleme Mantık). |
| `02_Reaction_Timer` | **Refleks Ölçer** | Randomness (Rastgelelik) & Input Capture ile tepki süresi ölçümü. |
| `03_Akıllı_Trafik_FSM` | **Akıllı Trafik Işığı** | **Finite State Machine (FSM)** mimarisi ve durum yönetimi. |
| `04_Simon_Says` | **Hafıza Oyunu** | Dizi (Array) yönetimi ve dinamik oyun algoritmaları. |
| `05_Breathing_LED` | **Nefes Alan Işık** | **PWM** simülasyonu ve Duty Cycle mantığı ile analog efekt. |
| `06_Park_Sensoru` | **Park Sensörü** | Data Mapping (Veri Haritalama) ve frekans modülasyonu. |
| `07_Pomodoro` | **Pomodoro Timer** | Geri sayım (Count-Down) algoritmaları ve Flag yönetimi. |
| `08_Mors_Cevirici` | **Mors Kodu** | String işleme (Text-to-Signal) ve iletişim protokolü temelleri. |
| `09_Dijital_Zar` | **Dijital Zar** | Kullanıcı deneyimi (UX) tasarımı ve Modulo aritmetiği. |
| `10_Menu_Kontrol` | **Menü Sistemi** | Tek butonla State Management ve Multitasking temeli. |
| `11_Up_Down_Counter` | **İleri/Geri Sayaç** | **Edge Case** (Sınır durumları) kontrolü ve Overflow koruması. |

---

## 🏛️ Yazılım Mimarisi (Modül 3 İçin)
Timer tabanlı projeler modüler bir yapıda tasarlanmıştır:

1.  **`bizimKutuphane.h`:** 7-Segment Display sürme, Multiplexing ve sayıları basamaklarına ayırma fonksiyonlarını barındıran özel kütüphane.
2.  **`stm32f4xx_it.c`:** Donanımsal Timer her 1 saniyede bir kesme (Interrupt) oluşturduğunda devreye giren ISR (Interrupt Service Routine).
3.  **`main.c`:** Sürekli ekranı tarayan ve zaman limitlerini (60sn / 60dk) denetleyen ana döngü mantığı.

---

**Maintainer:** Merd0 (Mert Aydın)  
*Computer Engineering Dept. @ Fırat University*
