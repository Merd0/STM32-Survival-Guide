# ⚡ Konu 3: Interrupts (Kesmeler) ve NVIC (CubeMX Yöntemi)

Bu modül, **STM32CubeMX** üzerinden aktif edilen kesmelerin (NVIC), `stm32f4xx_it.c` dosyası içerisindeki Handler fonksiyonları kullanılarak nasıl yönetileceğini açıklar.

**Yöntem:**
* Kodlar, CubeMX'in otomatik ürettiği `EXTIx_IRQHandler` fonksiyonlarının içindeki `/* USER CODE BEGIN 0 */` alanına yazılır.
* Otomatik üretilen `HAL_GPIO_EXTI_IRQHandler` fonksiyonu **silinmez**. Bu fonksiyon kesme bayrağını bizim yerimize temizler.

## 🛠️ CubeMX Ayarları (NVIC)
Kodların çalışması için CubeMX arayüzünde şunları yapmalısınız:
1.  **System Core -> NVIC** sekmesine gelin.
2.  `EXTI Line0`, `EXTI Line1` gibi ilgili satırların **Enabled** kutucuğunu işaretleyin.
3.  **Preemption Priority:** Öncelik sırasını buradan belirleyin (Düşük sayı = Yüksek Öncelik).

---

## 📂 Kod Örnekleri

Bu kod bloklarını `stm32f4xx_it.c` dosyasındaki ilgili yerlere yapıştırın.

| Dosya | Açıklama |
| :--- | :--- |
| [📂 01_temel_kesme.c](./01_temel_kesme.c) | PB1 butonu ile LED toggle. (Bayrak temizliği otomatik). |
| [📂 02_debounce_cozumu.c](./02_debounce_cozumu.c) | `HAL_GetTick` kullanarak buton titremesini engelleme. |
| [📂 03_oncelik_savasi_preemption.c](./03_oncelik_savasi_preemption.c) | **Preemption:** Yüksek öncelikli butonun (PB1), diğerini (PA0) yarıda kesmesi. |
| [📂 04_esit_oncelik_subpriority.c](./04_esit_oncelik_subpriority.c) | **Sub-Priority:** Eşit öncelik durumunda kesmelerin birbirini beklemesi. |

---

### ⚠️ Önemli Not
Attığınız kodları `USER CODE BEGIN 0` ile `USER CODE END 0` arasına yazdığınızdan emin olun. Alt satırdaki `HAL_GPIO_EXTI_IRQHandler(...)` fonksiyonunu **silmeyin**.
