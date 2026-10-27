**[English](README.md) | Türkçe**

# ⏱️ STM32 Timer Interrupt Stopwatch & Embedded Algorithms

Bu depo (repository), STM32 mikrodenetleyicisi kullanılarak geliştirilmiş **Timer Interrupt (Zamanlayıcı Kesmesi)** tabanlı hassas bir kronometre uygulamasını ve gömülü sistemler için kritik algoritma örneklerini içerir.

## 🎯 Ana Proje: Dakika/Saniye Kronometre
Gömülü sistemlerde işlemciyi `delay` komutlarıyla meşgul etmeden (Non-blocking) zaman takibi yapabilmek kritik bir mühendislik yetkinliğidir.

* **İlgili Dosya:** `01_dk_sn_kronometre`

### 🚀 Özellikler
* **Timer Interrupts:** Süre takibi ana döngüde (while) değil, arka planda donanımsal Timer (TIM1) kesmesi ile milimetrik hassasiyette yapılır.
* **Multiplexing (Tarama):** 4 haneli 7-segment display, insan gözünün algılayamayacağı hızda taranarak sürülür.
* **Cascade Logic:** Dakika ve saniye geçişleri (60 sn -> 1 dk) zincirleme bir algoritma ile kontrol edilir.

### 🛠️ Donanım ve Pin Bağlantıları
* **Mikrodenetleyici:** STM32F4 Serisi
* **Ekran:** 4-Digit 7-Segment Display
* **Segment Pinleri:** GPIO (A, B, C, D, E, F, G, DP) -> PE8-PE15
* **Kontrol Pinleri (Scan):**
    * Digit 1 (Dakika Onlar): PE4
    * Digit 2 (Dakika Birler): PE5
    * Digit 3 (Saniye Onlar): PE6
    * Digit 4 (Saniye Birler): PE7

---

## 📚 Gömülü Sistem Algoritma Örnekleri (Snippets)
Bu proje kapsamında, sadece donanım sürmek değil, **algoritma kurma yeteneğini** geliştirmek amacıyla aşağıdaki 10 farklı senaryo kodlanmıştır.

| Dosya Adı | Proje Açıklaması | Kazanılan Yetkinlik (Vizyon) |
| :--- | :--- | :--- |
| `01_dk_sn_kronometre` | **Ana Proje (Kronometre):** Dakika ve saniye sayan, kesme (interrupt) tabanlı hassas zamanlayıcı. | **Timer Interrupt** & **Multiplexing** & **Cascade Logic** |
| `02_Reaction_Timer` | **Refleks Ölçer:** Rastgele yanan ışığa tepki süresini ölçer. | Randomness (Rastgelelik) & Input Capture |
| `03_Akıllı_Trafik_Işığı_(FSM)` | **Trafik Işığı:** Yaya butonlu, durum kontrollü trafik sistemi. | Finite State Machine (FSM) Mimarisi |
| `04_Simon_Says_(Hafıza Oyunu)` | **Hafıza Oyunu:** Rastgele yanan LED dizisini tekrar etme oyunu. | Dizi (Array) Yönetimi & Oyun Algoritması |
| `05_Nefes_Alan_Işık_(Breathing LED)` | **Breathing LED:** Işığın yumuşakça yanıp sönmesi. | PWM Simülasyonu & Duty Cycle Mantığı |
| `06_Park_Sensörü_Simülasyonu` | **Park Sensörü:** Mesafeye göre artan sesli uyarı sistemi. | Data Mapping (Veri Haritalama) |
| `07_Pomodoro_Zamanlayıcı` | **Pomodoro:** 25 dakikadan geriye sayan çalışma saati. | Geri Sayım (Count-Down) & Flag Yönetimi |
| `08_Mors_Alfabesi_Çevirici` | **Mors Kodu:** Yazıyı (String) ışık sinyaline çevirir. | String İşleme & İletişim Protokolü Temeli |
| `09_Dijital_Zar_(Rastgele Sayı)` | **Dijital Zar:** Butona basılınca dönen, bırakınca duran zar. | UX Tasarımı & Modulo Aritmetiği |
| `10_Butonla_Menü_Kontrolü` | **Menü Sistemi:** Tek butonla ekranlar arası geçiş. | State Management & Multitasking |
| `11_Çift_Yönlü_Sayıcı_(Up_Down_Counter)` | **İleri/Geri Sayaç:** İki butonla sınır kontrollü sayma. | Edge Case (Sınır Durumu) & Overflow Koruması |

---

## 📂 Yazılım Mimarisi
Proje modüler bir yapıda tasarlanmıştır:

1.  **`bizimKutuphane.h`:** 7-Segment Display sürme, Multiplexing ve sayıları basamaklarına ayırma fonksiyonlarını barındıran özel kütüphane.
2.  **`stm32f4xx_it.c` (Snippet içinde):** Timer her 1 saniyede bir kesme (Interrupt) oluşturduğunda devreye giren ISR kodu.
3.  **`main.c` (Snippet içinde):** Sürekli ekranı tarayan ve zaman limitlerini denetleyen ana döngü mantığı.

---
**Geliştirici:** Merd0 (Mert Aydın)
