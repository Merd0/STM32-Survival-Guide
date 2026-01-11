# STM32 Timer Interrupt Based Stopwatch (7-Segment Display)

Bu proje, STM32 mikrodenetleyicisi kullanarak geliştirilmiş, **Timer Interrupt (Zamanlayıcı Kesmesi)** ve **Multiplexing (Tarama)** tekniklerini içeren hassas bir kronometre uygulamasıdır.

## 🎯 Projenin Amacı ve Özellikleri
Gömülü sistemlerde işlemciyi meşgul etmeden (Non-blocking) zaman takibi yapabilmek kritik bir yetkinliktir. Bu projede:
- **Timer Interrupts:** Süre takibi ana döngüde (while) değil, arka planda donanımsal Timer ile yapılır.
- **Multiplexing:** 4 haneli 7-segment display, insan gözünün algılayamayacağı hızda taranarak (Scanning) sürülür.
- **State Logic:** Dakika ve saniye geçişleri (60 sn -> 1 dk) zincirleme (cascade) bir algoritma ile kontrol edilir.

## 🛠️ Donanım ve Pin Bağlantıları
* **Mikrodenetleyici:** STM32F4 Serisi
* **Ekran:** 4-Digit 7-Segment Display (Ortak Katot/Anot)
* **Segment Pinleri:** GPIO (A, B, C, D, E, F, G, DP)
* **Kontrol Pinleri (Scan):**
    * Digit 1 (Dakika Onlar): PE4
    * Digit 2 (Dakika Birler): PE5
    * Digit 3 (Saniye Onlar): PE6
    * Digit 4 (Saniye Birler): PE7

## 📂 Yazılım Mimarisi
Proje 3 ana bileşenden oluşur:
1.  **`bizimKutuphane.h`:** Display sürme ve sayıları basamaklarına ayırma fonksiyonlarını barındıran özel kütüphane.
2.  **`stm32f4xx_it.c`:** Timer her 1 saniyede bir kesme (Interrupt) oluşturduğunda sayacı tetikleyen ISR (Interrupt Service Routine).
3.  **`main.c`:** Sürekli ekranı tarayan ve zaman limitlerini (60 saniye kontrolü gibi) denetleyen ana döngü.

---
**Geliştirici:** [Senin Adın/Kullanıcı Adın]
