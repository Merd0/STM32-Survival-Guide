# ⚡ STM32 GPIO & Algorithm Survival Guide

![Language](https://img.shields.io/badge/language-C-00599C)
![Platform](https://img.shields.io/badge/platform-STM32F4-orange)
![Topic](https://img.shields.io/badge/topic-Embedded_Systems-green)
![Status](https://img.shields.io/badge/Status-Educational-blueviolet)

## 📖 Hakkında
Bu depo (repository), **Fırat Üniversitesi Bilgisayar Mühendisliği** Mikroişlemciler dersi müfredatına uygun olarak geliştirilmiş, STM32 mikrodenetleyicileri için **Gelişmiş GPIO Algoritmaları** kütüphanesidir.

Sadece LED yakıp söndürmeyi değil; **Bitwise Operasyonlar**, **Multiplexing (Tarama)**, **Look-Up Table (Matris)** ve **Input De-bouncing** gibi gömülü yazılımın temel taşlarını içeren pratik senaryolar sunar.

---

## 🛠️ Donanım Yapılandırması (Pinout)
Kodların doğru çalışması için geliştirme kartınızda aşağıdaki pinlerin kullanıldığı varsayılmıştır:

| Bileşen | Port & Pinler | Açıklama |
| :--- | :--- | :--- |
| **Dahili LED'ler** | `GPIOD` (12, 13, 14, 15) | Yeşil, Turuncu, Kırmızı, Mavi |
| **Butonlar** | `GPIOA` (0, 13, 14) | User Button ve Harici Butonlar |
| **7-Segment (Kontrol)** | `GPIOE` (4, 5, 6, 7) | Hane Seçimi (Digit Select) |
| **7-Segment (Veri)** | `GPIOE` (8, 9 ... 15) | Segment A-G ve DP |

---

## 📂 Kütüphane İçeriği

### 1. Modül: GPIO Output (LED Algoritmaları)
*Klasör:* `01_GPIO_Output`  
Bit kaydırma ve matematiksel algoritmalarla LED kontrolü.

| Dosya | Açıklama | Zorluk |
| :--- | :--- | :--- |
| `01_sirali_akis.c` | LED'lerin sırayla yanıp söndüğü temel akış. | ⭐ |
| `02_kara_simsek.c` | Işığın bir uçtan diğer uca gidip geldiği (Ping-Pong) efekt. | ⭐⭐ |
| `03_binary_counter.c` | 4-Bitlik ikili sayma işlemi (0000 - 1111). | ⭐⭐⭐ |
| `04_polis_cakari.c` | Sağ ve sol grupların sırayla çaktığı efekt. | ⭐⭐ |
| `05_yilan_efekti.c` | Kuyruklu takip efekti (Modulo aritmetiği içerir). | ⭐⭐ |
| `06_ozel_desen.c` | Dizi tabanlı özel animasyon oynatıcı. | ⭐⭐ |
| `07_yukleme_cubugu.c` | LED'lerin sönmeden sırayla dolduğu "Loading" barı. | ⭐ |
| `08_ters_binary.c` | Bitwise NOT (~) kullanılarak yapılan negatif sayıcı. | ⭐⭐⭐ |
| `09_hayalet_iz.c` | **Software PWM** ile LED'lerde sönümleme (Ghost Trail) efekti. | ⭐⭐⭐⭐⭐ |

### 2. Modül: GPIO Input (Matris & Display & Temel Buton)
*Klasör:* `02_GPIO_Input`  
Look-Up Table (Matris) yöntemiyle 7-Segment kontrolü, Multiplexing ve temel buton okuma mantıkları.

| Dosya | Açıklama | Zorluk |
| :--- | :--- | :--- |
| `01_basit_kontrol.c` | Butona basınca tablodan veri çekip ekrana basar. | ⭐ |
| `02_hedefli_yazdirma.c` | PA13 -> 1. Haneye, PA14 -> 2. Haneye veri yazar. | ⭐⭐ |
| `03_butonlu_sayac.c` | **Multiplexing + Input:** Ekran taranırken sayı arttırma. | ⭐⭐⭐⭐⭐ |
| `04_kapi_zili_basitDuzey.c` | Basınca yanar, çekince söner (Direct Drive). | ⭐ |
| `05_akilli_lamba_basitDuzey.c` | Bas-Çek yapınca durum değiştiren (Toggle) lamba. | ⭐⭐⭐ |
| `05_vites_kutusu_basitDuzey.c` | Her basışta modu (vitesi) değiştiren yapı. | ⭐⭐⭐ |
| `07_guvenlik_kilidi_basitDuzey.c` | İki butona aynı anda basma kontrolü (`&&` logic). | ⭐⭐ |
| `08_refleks_testi_basitDuzey.c` | LED yandığı anda butona basma oyunu. | ⭐⭐⭐ |

---

## 🚀 Kurulum ve Kullanım

1.  Bu repoyu indirin (`Clone` veya `Download ZIP`).
2.  İlgili klasördeki `.c` dosyasını açın.
3.  Kodun tamamını kopyalayıp, `main.c` dosyanızdaki `while(1)` döngüsünün içine yapıştırın.
4.  **Dikkat:** Input/Display örnekleri için `main.c` dosyasının en tepesine **Global Değişkenleri** (Look-Up tablosu vb.) eklemeyi unutmayın.

---

## 👨‍💻 Yazar
**Mert** Fırat Üniversitesi - Bilgisayar Mühendisliği  
*Embedded Systems & Computer Architecture Enthusiast*
