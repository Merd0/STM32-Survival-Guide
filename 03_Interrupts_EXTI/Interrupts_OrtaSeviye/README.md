# Orta Seviye Kesme Algoritmaları (Logic & Flags)

Bu modül, kesme (interrupt) kullanımını sadece "LED yak/söndür" basitliğinden çıkarıp, **Durum Yönetimi (State Machine)** ve **Bayrak (Flag)** mantığıyla profesyonel bir yapıya taşır.

Buradaki temel amaç: **"Kesme fonksiyonu içinde ağır iş yapılmaz, sadece emir verilir veya durum değiştirilir."** ilkesini kavramaktır.

---

## ⚠️ Kritik Ön Hazırlık (Değişken Tanımları)

Bu klasördeki kodların çalışabilmesi için, sistemin durumunu hafızada tutacak değişkenlere ihtiyacımız var. 

Aşağıdaki kod bloğunu kopyalayın ve projenizdeki **`Core/Src/stm32f4xx_it.c`** dosyasının **en tepesine** (include satırlarının altına, fonksiyonların dışına) yapıştırın.

```c
/* USER CODE BEGIN 0 */
// Bu değişkenleri stm32f4xx_it.c dosyasının EN TEPESİNE yapıştırın

int sistem_modu = 0;       // 0:Kapalı, 1:Yavaş, 2:Hızlı, 3:Sabit
int acil_durum = 0;        // 0:Her şey yolunda, 1:PANİK!
uint8_t islem_bayragi = 0; // Main döngüsüne haber uçurmak için (Flag)

/* USER CODE END 0 */
