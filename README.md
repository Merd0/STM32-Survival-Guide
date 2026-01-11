# STM32 Embedded Algorithms & Drivers

<div align="center">

![Platform](https://img.shields.io/badge/Platform-STM32F4_Discovery-orange?style=flat-square&logo=stmicroelectronics&logoColor=white)
![Language](https://img.shields.io/badge/Language-C99-00599C?style=flat-square&logo=c&logoColor=white)
![Architecture](https://img.shields.io/badge/Architecture-ARM_Cortex_M4-red?style=flat-square&logo=arm&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)

**Fırat Üniversitesi Bilgisayar Mühendisliği Müfredatına Uygun Gömülü Sistemler Referans Deposu**

[Documentation (Dokümantasyon)](#-module-breakdown-modül-detayları) • [Installation (Kurulum)](#-getting-started-kurulum-ve-kullanım) • [Contribute (Katkı)](https://github.com/SeninKullaniciAdin)

</div>

---

## 📖 Overview (Genel Bakış)

Bu proje, **STM32F4** mikrodenetleyicileri için donanım soyutlama katmanı (**HAL - Hardware Abstraction Layer**) kullanılarak geliştirilmiş, optimize edilmiş C algoritmalarını içerir. Depo, temel GPIO manipülasyonundan karmaşık zamanlayıcı (Timer) tabanlı otomasyon sistemlerine kadar geniş bir yelpazeyi kapsar.

Kod tabanı, endüstriyel yazılım prensipleri olan **Modularity (Modülerlik)**, **Scalability (Ölçeklenebilirlik)** ve **Clean Code (Temiz Kod)** standartlarına uygun olarak tasarlanmıştır.

### 🎯 Key Features (Temel Özellikler)
* **Low-Level Driver Implementation:** Kayıt defteri (Register) ve HAL seviyesinde donanım kontrolü.
* **Interrupt Management (Kesme Yönetimi):** NVIC önceliklendirmesi (Priority Grouping) ve asenkron olay işleme.
* **Real-Time Algorithms (Gerçek Zamanlı Algoritmalar):** Zaman kritik görevler için Timer ve FSM (Finite State Machine - Sonlu Durum Makinesi) yapıları.
* **Debouncing Techniques:** Mekanik buton arklarını önlemek için yazılımsal filtreleme.

---

## 📂 Repository Structure (Proje Yapısı)

    STM32-Algorithms/
    ├── 01_GPIO_Output/              # Digital Signal Synthesis (Dijital Sinyal Sentezi)
    ├── 02_GPIO_Input/               # Signal Acquisition & Processing (Sinyal Okuma ve İşleme)
    ├── 03_Interrupts_EXTI/          # Asynchronous Event Handling (Asenkron Olay Yönetimi)
    │   ├── Interrupts_OrtaSeviye/   # Intermediate Logic (Orta Seviye Mantık)
    │   └── Interrupts_İleriSeviye/  # Advanced Safety Systems (İleri Güvenlik Sistemleri)
    ├── 04_Timer_Interrupt/          # Timing & Automation (Zamanlama ve Otomasyon)
    └── README.md                    # Documentation (Dokümantasyon)

---

## 📊 Module Breakdown (Modül Detayları)

### 1. GPIO Output Control
**Focus:** `ODR (Output Data Register)` Manipulation & Bitwise Operations (Bit Düzeyinde İşlemler).
> **Path:** [`01_GPIO_Output/`](./01_GPIO_Output/)

| File (Dosya) | Algorithm / Logic (Algoritma / Mantık) | Description (Açıklama) |
| :--- | :--- | :--- |
| [`01_sirali_akis.c`](./01_GPIO_Output/01_sirali_akis.c) | **Sequential Logic (Sıralı Mantık)** | Temel port tarama döngüsü. |
| [`02_kara_simsek.c`](./01_GPIO_Output/02_kara_simsek.c) | **Bidirectional Shift (Çift Yönlü Kaydırma)** | Ping-Pong algoritması ile veri manipülasyonu. |
| [`03_binary_counter.c`](./01_GPIO_Output/03_binary_counter.c) | **Binary Arithmetic (İkili Aritmetik)** | 4-Bit sayaç ve maskeleme (Masking) işlemleri. |
| [`04_polis_cakari.c`](./01_GPIO_Output/04_polis_cakari.c) | **Asynchronous Toggle (Asenkron Anahtarlama)** | Farklı frekanslarda sinyal üretimi. |
| [`05_yilan_efekti.c`](./01_GPIO_Output/05_yilan_efekti.c) | **Circular Buffer Logic (Dairesel Tampon Mantığı)** | Kuyruk yapısı (Queue) simülasyonu. |
| [`06_ozel_desen.c`](./01_GPIO_Output/06_ozel_desen.c) | **Look-Up Table (LUT) (Başvuru Çizelgesi)** | Dizi (Array) tabanlı desen motoru. |
| [`07_yukleme_cubugu.c`](./01_GPIO_Output/07_yukleme_cubugu.c) | **Cumulative State (Kümülatif Durum)** | Aşamalı artış gösterimi. |
| [`08_ters_binary.c`](./01_GPIO_Output/08_ters_binary.c) | **Bitwise NOT / Inversion (Tümleyen İşlemi)** | Negatif lojik (Active-Low) uygulaması. |
| [`09_hayalet_iz.c`](./01_GPIO_Output/09_hayalet_iz.c) | **Software PWM (Yazılımsal PWM)** | Sönümleme (Decay) algoritması ile parlaklık kontrolü. |

### 2. GPIO Input & Signal Processing
**Focus:** `IDR (Input Data Register)`, Pull-Up/Down Configurations & Logic Gates (Mantık Kapıları).
> **Path:** [`02_GPIO_Input/`](./02_GPIO_Input/)

| File (Dosya) | Concept (Kavram) | Level (Seviye) |
| :--- | :--- | :--- |
| [`01_basit_kontrol.c`](./02_GPIO_Input/01_basit_kontrol.c) | **Polling Mechanism (Sorgulama Mekanizması)** | 🟢 Basic |
| [`02_hedefli_yazdirma.c`](./02_GPIO_Input/02_hedefli_yazdirma.c) | **Conditional Mapping (Koşullu Eşleme)** | 🟡 Intermediate |
| [`03_butonlu_sayac.c`](./02_GPIO_Input/03_butonlu_sayac.c) | **Edge Detection (Kenar Algılama)** | 🟡 Intermediate |
| [`04_kapi_zili_basitDüzey.c`](./02_GPIO_Input/04_kapi_zili_basitDüzey.c) | **Momentary Logic (Anlık Anahtarlama)** | 🟢 Basic |
| [`05_akilli_lamba_basitDüzey.c`](./02_GPIO_Input/05_akilli_lamba_basitDüzey.c) | **Toggle / Latch Logic (Mühürleme Mantığı)** | 🔴 Advanced |
| [`05_vites_kutusu_basitDüzey.c`](./02_GPIO_Input/05_vites_kutusu_basitDüzey.c) | **Sequential State Machine (Sıralı Durum Makinesi)** | 🔴 Advanced |
| [`07_guvenlik_kilidi_basitDüzey.c`](./02_GPIO_Input/07_guvenlik_kilidi_basitDüzey.c) | **AND Logic Gate (VE Mantık Kapısı)** | 🟡 Intermediate |
| [`08_refleks_testi_basitDüzey.c`](./02_GPIO_Input/08_refleks_testi_basitDüzey.c) | **Reaction Measurement (Tepki Ölçümü)** | 🟢 Basic |

### 3. Interrupts & EXTI (NVIC)
**Focus:** Hardware Interrupts (Donanım Kesmeleri), Preemption & Sub-Priority Management.
> **Path:** [`03_Interrupts_EXTI/`](./03_Interrupts_EXTI/)

| File (Dosya) | Technical Implementation (Teknik Uygulama) |
| :--- | :--- |
| [`01_temel_kesme.c`](./03_Interrupts_EXTI/01_temel_kesme.c) | **Callback Architecture (Geri Çağırma Mimarisi)** |
| [`02_debounce_cozumu.c`](./03_Interrupts_EXTI/02_debounce_cozumu.c) | **Non-Blocking Delay (Bloklamayan Gecikme)** |
| [`03_oncelik_savasi_preemption.c`](./03_Interrupts_EXTI/03_oncelik_savasi_preemption.c) | **Nested Interrupts (İç İçe Kesmeler)** |
| `Interrupts_İleriSeviye/01_sanal_encoder.c` | **Quadrature Signal Simulation (Dönel Kodlayıcı Simülasyonu)** |
| `Interrupts_İleriSeviye/02_endustriyel_stop.c` | **Fail-Safe Logic (Hata Güvenli Mantık)** |
| `Interrupts_İleriSeviye/05_paketleme_bandi.c` | **Batch Processing (Parti İşleme)** |

### 4. Timers & Automation Projects
**Focus:** Timer Interrupts, FSM (Finite State Machines) & Multiplexing.
> **Path:** [`04_Timer_Interrupt_Header_Stopwatch/`](./04_Timer_Interrupt_Header_Stopwatch/)

| Project Name (Proje Adı) | Algorithm / Method (Algoritma / Yöntem) | Link |
| :--- | :--- | :--- |
| **Stopwatch (Kronometre)** | **Time-Division Multiplexing (Zaman Bölmeli Çoğullama)** | [View](./04_Timer_Interrupt_Header_Stopwatch/01_dk_sn_kronometre) |
| **Reaction Timer** | **Input Capture & Randomization (Giriş Yakalama & Rastgelelik)** | [View](./04_Timer_Interrupt_Header_Stopwatch/02_Reaction_Timer) |
| **Smart Traffic Light** | **Finite State Machine - FSM (Sonlu Durum Makinesi)** | [View](./04_Timer_Interrupt_Header_Stopwatch/03_Akıllı_Trafik_Işığı_(FSM)) |
| **Simon Says** | **Memory Array Management (Hafıza Dizisi Yönetimi)** | [View](./04_Timer_Interrupt_Header_Stopwatch/04_Simon_Says_(Hafıza%20Oyunu)) |
| **Breathing LED** | **PWM Signal Simulation (Darbe Genişlik Modülasyonu)** | [View](./04_Timer_Interrupt_Header_Stopwatch/05_Nefes_Alan_Işık_(Breathing%20LED)) |
| **Parking Sensor** | **Frequency Mapping (Frekans Eşleme)** | [View](./04_Timer_Interrupt_Header_Stopwatch/06_Park_Sensörü_Simülasyonu) |
| **Pomodoro Timer** | **Countdown Logic (Geri Sayım Mantığı)** | [View](./04_Timer_Interrupt_Header_Stopwatch/07_Pomodoro_Zamanlayıcı) |
| **Morse Translator** | **Text-to-Signal Encoding (Metinden Sinyale Kodlama)** | [View](./04_Timer_Interrupt_Header_Stopwatch/08_Mors_Alfabesi_Çevirici) |
| **Digital Dice** | **Pseudo-Random Generator (Yalancı Rastgele Sayı Üreteci)** | [View](./04_Timer_Interrupt_Header_Stopwatch/09_Dijital_Zar_(Rastgele%20Sayı)) |
| **Menu System** | **UI/UX State Management (Kullanıcı Arayüzü Yönetimi)** | [View](./04_Timer_Interrupt_Header_Stopwatch/10_Butonla_Menü_Kontrolü) |

---

## 🛠️ Getting Started (Kurulum ve Kullanım)

Bu kodları kendi STM32 kartında çalıştırmak için:

1.  **Clone the Repo (Depoyu Klonla):**
    
        git clone https://github.com/SeninKullaniciAdin/RepoIsmi.git

2.  **Import to IDE (IDE'ye Aktar):**
    * STM32CubeIDE veya Keil uVision açın.
    * İlgili `.c` dosyasındaki kodları `main.c` içerisindeki `USER CODE BEGIN` bloklarına entegre edin.
3.  **Pin Configuration (Pin Ayarları):**
    * Kod içerisindeki `define` direktiflerine bakarak ilgili pinleri (örn: `PA0`, `PD12`) CubeMX arayüzünde tanımlayın.

---

<div align="center">

**Maintainer (Bakım Sorumlusu)**
<br>
Mert Aydın (Merd0)
<br>
*Computer Engineering Student @ Fırat University*
<br>
<a href="https://github.com/SeninGitHubKullaniciAdin">GitHub Profile</a>

</div>
