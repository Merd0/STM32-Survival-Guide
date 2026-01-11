# STM32 Survival Guide: GPIO, Interrupts & Timers

![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-STM32F4-orange?style=flat-square)
![Topic](https://img.shields.io/badge/Domain-Embedded_Systems-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Active-blueviolet?style=flat-square)

## 📖 Repo Özeti
Bu depo, **Fırat Üniversitesi Bilgisayar Mühendisliği** müfredatını desteklemek ve gömülü sistemler dünyasına adım atan mühendisler için oluşturulmuş kapsamlı bir algoritma kütüphanesidir.

---

## 📂 Algoritma Kütüphanesi

### 1. Modül: GPIO Output (Dijital Çıkış)
*Konum:* [`01_GPIO_Output/`](./01_GPIO_Output/)

| Dosya Adı | Açıklama | Seviye |
| :--- | :--- | :--- |
| [`01_sirali_akis.c`](./01_GPIO_Output/01_sirali_akis.c) | Temel for döngüsü ve pin kontrolü. | Başlangıç |
| [`02_kara_simsek.c`](./01_GPIO_Output/02_kara_simsek.c) | Çift yönlü tarama (Ping-Pong) algoritması. | Orta |
| [`03_binary_counter.c`](./01_GPIO_Output/03_binary_counter.c) | 4-Bit Binary sayıcı (Bitwise Shifting). | İleri |
| [`04_polis_cakari.c`](./01_GPIO_Output/04_polis_cakari.c) | Asenkron grup flaşör mantığı. | Orta |
| [`05_yilan_efekti.c`](./01_GPIO_Output/05_yilan_efekti.c) | Dairesel kuyruk yapısı (Circular Buffer logic). | Orta |
| [`06_ozel_desen.c`](./01_GPIO_Output/06_ozel_desen.c) | Dizi (Array) tabanlı animasyon motoru. | Orta |
| [`07_yukleme_cubugu.c`](./01_GPIO_Output/07_yukleme_cubugu.c) | Kümülatif artış (Loading Bar) simülasyonu. | Başlangıç |
| [`08_ters_binary.c`](./01_GPIO_Output/08_ters_binary.c) | Bitwise NOT (~) operatörü ile negatif lojik. | İleri |
| [`09_hayalet_iz.c`](./01_GPIO_Output/09_hayalet_iz.c) | Software PWM ve Decay algoritması. | Uzman |

### 2. Modül: GPIO Input (Dijital Giriş)
*Konum:* [`02_GPIO_Input/`](./02_GPIO_Input/)

| Dosya Adı | Açıklama | Seviye |
| :--- | :--- | :--- |
| [`01_basit_kontrol.c`](./02_GPIO_Input/01_basit_kontrol.c) | Butona basınca LED yakma. | Başlangıç |
| [`02_hedefli_yazdirma.c`](./02_GPIO_Input/02_hedefli_yazdirma.c) | Girişe göre belirli 7-segment hanesini yakma. | Orta |
| [`03_butonlu_sayac.c`](./02_GPIO_Input/03_butonlu_sayac.c) | Buton ile sayı artırma (Basit Sayaç). | Orta |
| [`04_kapi_zili_basitDüzey.c`](./02_GPIO_Input/04_kapi_zili_basitDüzey.c) | Bas-Çek mantığı (Push-Button Logic). | Başlangıç |
| [`05_akilli_lamba_basitDüzey.c`](./02_GPIO_Input/05_akilli_lamba_basitDüzey.c) | Toggle (Anahtar) mantığı oluşturma. | İleri |
| [`05_vites_kutusu_basitDüzey.c`](./02_GPIO_Input/05_vites_kutusu_basitDüzey.c) | Switch-Case ile sıralı mod değişimi. | İleri |
| [`07_guvenlik_kilidi_basitDüzey.c`](./02_GPIO_Input/07_guvenlik_kilidi_basitDüzey.c) | Mantıksal VE (`&&`) ile çoklu giriş doğrulama. | Orta |
| [`08_refleks_testi_basitDüzey.c`](./02_GPIO_Input/08_refleks_testi_basitDüzey.c) | Basit tepki ölçüm mantığı. | Başlangıç |

### 3. Modül: Interrupts & EXTI (Dış Kesmeler)
*Konum:* [`03_Interrupts_EXTI/`](./03_Interrupts_EXTI/)

**Temel Dosyalar (Root):**
| Dosya Adı | Açıklama |
| :--- | :--- |
| [`01_temel_kesme.c`](./03_Interrupts_EXTI/01_temel_kesme.c) | `HAL_GPIO_EXTI_Callback` kullanımı. |
| [`02_debounce_cozumu.c`](./03_Interrupts_EXTI/02_debounce_cozumu.c) | Millis() tabanlı buton arkı engelleme. |
| [`03_oncelik_savasi_preemption.c`](./03_Interrupts_EXTI/03_oncelik_savasi_preemption.c) | Preemption Priority testi. |
| [`04_esit_oncelik_subpriority.c`](./03_Interrupts_EXTI/04_esit_oncelik_subpriority.c) | Sub-Priority davranışı. |

**Orta Seviye (Subfolder):**
| Dosya Adı | Açıklama |
| :--- | :--- |
| [`01_mod_degistirici.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/01_mod_degistirici.c) | Kesme ile çalışma modu değiştirme. |
| [`02_bayrak_yarisi.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/02_bayrak_yarisi.c) | Volatile flag kullanımı. |
| [`03_acil_durum_freni.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/03_acil_durum_freni.c) | Sistemsel kilitleme mekanizması. |

**İleri Seviye (Subfolder):**
| Dosya Adı | Açıklama |
| :--- | :--- |
| [`01_sanal_encoder.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/01_sanal_encoder.c) | İki butonla Rotary Encoder simülasyonu. |
| [`02_endustriyel_stop.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/02_endustriyel_stop.c) | Safety Logic ve Reset mantığı. |
| [`03_kasa_sifresi.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/03_kasa_sifresi.c) | Sıralı giriş doğrulama algoritması. |
| [`04_motor_koruma.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/04_motor_koruma.c) | Cool-down (Soğuma süresi) koruması. |
| [`05_paketleme_bandi.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/05_paketleme_bandi.c) | Sensör sayacı ve Batch kontrolü. |
| [`06_double_click.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/06_double_click.c) | Çift tıklama algılama. |

### 4. Modül: Timer Interrupts & Algorithms
*Konum:* [`04_Timer_Interrupt_Header_Stopwatch/`](./04_Timer_Interrupt_Header_Stopwatch/)

| Dosya Adı | Proje & Açıklama | Seviye |
| :--- | :--- | :--- |
| [`01_dk_sn_kronometre`](./04_Timer_Interrupt_Header_Stopwatch/01_dk_sn_kronometre) | **Ana Proje:** Timer Interrupt & Multiplexing. | Orta |
| [`02_Reaction_Timer`](./04_Timer_Interrupt_Header_Stopwatch/02_Reaction_Timer) | **Refleks Ölçer:** Randomness & Input Capture. | Başlangıç |
| [`03_Akıllı_Trafik_Işığı_(FSM)`](./04_Timer_Interrupt_Header_Stopwatch/03_Akıllı_Trafik_Işığı_(FSM)) | **Trafik Işığı:** Finite State Machine (FSM). | İleri |
| [`04_Simon_Says_(Hafıza Oyunu)`](./04_Timer_Interrupt_Header_Stopwatch/04_Simon_Says_(Hafıza%20Oyunu)) | **Hafıza Oyunu:** Dizi yönetimi. | Orta |
| [`05_Nefes_Alan_Işık_(Breathing LED)`](./04_Timer_Interrupt_Header_Stopwatch/05_Nefes_Alan_Işık_(Breathing%20LED)) | **Breathing LED:** PWM simülasyonu. | Orta |
| [`06_Park_Sensörü_Simülasyonu`](./04_Timer_Interrupt_Header_Stopwatch/06_Park_Sensörü_Simülasyonu) | **Park Sensörü:** Data Mapping. | Orta |
| [`07_Pomodoro_Zamanlayıcı`](./04_Timer_Interrupt_Header_Stopwatch/07_Pomodoro_Zamanlayıcı) | **Pomodoro:** Geri sayım (Count-Down). | Orta |
| [`08_Mors_Alfabesi_Çevirici`](./04_Timer_Interrupt_Header_Stopwatch/08_Mors_Alfabesi_Çevirici) | **Mors Kodu:** Text-to-Signal işleme. | İleri |
| [`09_Dijital_Zar_(Rastgele Sayı)`](./04_Timer_Interrupt_Header_Stopwatch/09_Dijital_Zar_(Rastgele%20Sayı)) | **Dijital Zar:** UX ve Modulo aritmetiği. | Başlangıç |
| [`10_Butonla_Menü_Kontrolü`](./04_Timer_Interrupt_Header_Stopwatch/10_Butonla_Menü_Kontrolü) | **Menü Sistemi:** State Management. | İleri |
| [`11_Çift_Yönlü_Sayıcı_(Up_Down_Counter)`](./04_Timer_Interrupt_Header_Stopwatch/11_Çift_Yönlü_Sayıcı_(Up_Down_Counter)) | **Sayaç:** Edge Case & Overflow koruması. | Başlangıç |

---

## 🏛️ Kütüphane Yapısı
Timer projeleri için geliştirilen yardımcı yapı:
1.  **`bizimKutuphane.h`:** 7-Segment Multiplexing ve basamak ayırma motoru.
2.  **`stm32f4xx_it.c`:** Zamanlayıcı kesmesi ile arka plan sayıcı tetikleme.
3.  **`main.c`:** Ön plan (Foreground) tarama ve mantıksal kontrol döngüsü.

---

**Maintainer:** Merd0 (Mert Aydın)  
*Computer Engineering Dept. @ Fırat University*
