# STM32 Survival Guide: GPIO, Interrupts & Timers

![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-STM32F4-orange?style=flat-square)
![Topic](https://img.shields.io/badge/Domain-Embedded_Systems-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Active-blueviolet?style=flat-square)

## 📖 Repo Özeti
Bu depo, **Fırat Üniversitesi Bilgisayar Mühendisliği** müfredatını desteklemek ve gömülü sistemler dünyasına adım atan mühendisler için oluşturulmuş kapsamlı bir algoritma kütüphanesidir.

Proje, STM32 mimarisi üzerinde **GPIO**, **External Interrupts (EXTI)**, **Timer Interrupts** ve **Endüstriyel Algoritmalar** konularını kapsar. Basit pin kontrolünden başlayıp, öncelik yönetimi (NVIC), debouncing ve zamanlayıcı tabanlı multitasking yapılarına kadar uzanan optimize edilmiş C kodlarını barındırır.

---

## 🛠️ Donanım Konfigürasyonu
Kodların hedeflenen donanım (Deney Kartı) üzerindeki pin haritalaması:

| Bileşen | Port & Pinler | Fonksiyon |
| :--- | :--- | :--- |
| **Dahili LED'ler** | `GPIOD` [12, 13, 14, 15] | Durum Göstergeleri (Yeşil, Turuncu, Kırmızı, Mavi) |
| **Giriş Birimleri** | `GPIOA` [0], `GPIOE` [0..] | User Button ve Harici Tetikleyiciler |
| **7-Segment (MUX)** | `GPIOE` [4, 5, 6, 7] | Hane Seçimi (Digit Select) |
| **7-Segment (Data)** | `GPIOE` [8 - 15] | Segment Veri Hattı (A-G, DP) |

---

## 📂 Algoritma Kütüphanesi

### 1. Modül: GPIO Output (Dijital Çıkış)
*Konum:* [`01_GPIO_Output/`](./01_GPIO_Output/)  
LED animasyonları ve bit manipülasyonu temelleri.

| Dosya | Açıklama |
| :--- | :--- |
| [📂 01_sirali_akis.c](./01_GPIO_Output/01_sirali_akis.c) | Temel for döngüsü ve pin kontrolü. |
| [📂 02_kara_simsek.c](./01_GPIO_Output/02_kara_simsek.c) | Çift yönlü tarama algoritması (Ping-Pong). |
| [📂 03_binary_counter.c](./01_GPIO_Output/03_binary_counter.c) | 4-Bit Binary sayıcı (Bitwise Shifting). |
| [📂 04_polis_cakari.c](./01_GPIO_Output/04_polis_cakari.c) | Asenkron grup flaşör mantığı. |
| [📂 05_yilan_efekti.c](./01_GPIO_Output/05_yilan_efekti.c) | Dairesel kuyruk yapısı (Circular Buffer logic). |
| [📂 06_ozel_desen.c](./01_GPIO_Output/06_ozel_desen.c) | Dizi (Array) tabanlı animasyon motoru. |
| [📂 07_yukleme_cubugu.c](./01_GPIO_Output/07_yukleme_cubugu.c) | Kümülatif artış (Loading Bar). |
| [📂 08_ters_binary.c](./01_GPIO_Output/08_ters_binary.c) | Bitwise NOT (~) operatörü ile negatif lojik. |
| [📂 09_hayalet_iz.c](./01_GPIO_Output/09_hayalet_iz.c) | Software PWM ve Decay algoritması. |

### 2. Modül: GPIO Input (Dijital Giriş)
*Konum:* [`02_GPIO_Input/`](./02_GPIO_Input/)  
Buton okuma, koşullu yapılar ve giriş sinyali işleme.

| Dosya | Açıklama |
| :--- | :--- |
| [📂 01_basit_kontrol.c](./02_GPIO_Input/01_basit_kontrol.c) | Butona basınca LED yakma (Basic I/O). |
| [📂 02_hedefli_yazdirma.c](./02_GPIO_Input/02_hedefli_yazdirma.c) | Girişe göre belirli 7-segment hanesini yakma. |
| [📂 03_butonlu_sayac.c](./02_GPIO_Input/03_butonlu_sayac.c) | Buton ile sayı artırma (Basit Sayaç). |
| [📂 04_kapi_zili...](./02_GPIO_Input/04_kapi_zili_basitDüzey.c) | Bas-Çek mantığı (Push-Button Logic). |
| [📂 05_akilli_lamba...](./02_GPIO_Input/05_akilli_lamba_basitDüzey.c) | Toggle (Anahtar) mantığı oluşturma. |
| [📂 05_vites_kutusu...](./02_GPIO_Input/05_vites_kutusu_basitDüzey.c) | Switch-Case ile sıralı mod değişimi. |
| [📂 07_guvenlik_kilidi...](./02_GPIO_Input/07_guvenlik_kilidi_basitDüzey.c) | Mantıksal VE (`&&`) ile çoklu giriş doğrulama. |
| [📂 08_refleks_testi...](./02_GPIO_Input/08_refleks_testi_basitDüzey.c) | Basit tepki ölçüm mantığı. |

### 3. Modül: Interrupts & EXTI (Dış Kesmeler)
*Konum:* [`03_Interrupts_EXTI/`](./03_Interrupts_EXTI/)  
Donanımsal kesmeler, öncelik yönetimi ve buton kararsızlığı (debounce) çözümleri.

#### 🔹 Temel Kavramlar (Root)
| Dosya | Açıklama |
| :--- | :--- |
| [📂 01_temel_kesme.c](./03_Interrupts_EXTI/01_temel_kesme.c) | `HAL_GPIO_EXTI_Callback` kullanımı. |
| [📂 02_debounce_cozumu.c](./03_Interrupts_EXTI/02_debounce_cozumu.c) | Millis() tabanlı buton arkı engelleme. |
| [📂 03_oncelik_savasi...](./03_Interrupts_EXTI/03_oncelik_savasi_preemption.c) | Preemption Priority (Kesme Önceliği) testi. |
| [📂 04_esit_oncelik...](./03_Interrupts_EXTI/04_esit_oncelik_subpriority.c) | Sub-Priority (Alt Öncelik) davranışı. |

#### 🔸 Orta Seviye Senaryolar
| Dosya | Açıklama |
| :--- | :--- |
| [📂 01_mod_degistirici.c](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/01_mod_degistirici.c) | Kesme ile çalışma modu değiştirme. |
| [📂 02_bayrak_yarisi.c](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/02_bayrak_yarisi.c) | Volatile flag kullanımı ve ana döngü senkronizasyonu. |
| [📂 03_acil_durum_freni.c](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/03_acil_durum_freni.c) | Sistemsel kilitleme (Emergency Stop). |

#### 🚀 İleri Seviye (Endüstriyel)
| Dosya | Açıklama |
| :--- | :--- |
| [📂 01_sanal_encoder.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/01_sanal_encoder.c) | İki butonla Rotary Encoder simülasyonu. |
| [📂 02_endustriyel_stop.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/02_endustriyel_stop.c) | Safety Logic ve yeniden kurma (Reset) mantığı. |
| [📂 03_kasa_sifresi.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/03_kasa_sifresi.c) | Sıralı giriş doğrulama algoritması. |
| [📂 04_motor_koruma.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/04_motor_koruma.c) | Cool-down (Soğuma süresi) koruması. |
| [📂 05_paketleme_bandi.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/05_paketleme_bandi.c) | Sensör sayacı ve Batch (Parti) kontrolü. |
| [📂 06_double_click.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/06_double_click.c) | Tek/Çift tıklama algılama algoritması. |

### 4. Modül: Timer Interrupts & Algorithms
*Konum:* [`04_Timer_Interrupt_Header_Stopwatch/`](./04_Timer_Interrupt_Header_Stopwatch/)  
Non-blocking zamanlayıcılar, Multiplexing ve ileri düzey algoritmalar.

| Dosya | Proje & Vizyon |
| :--- | :--- |
| [📂 01_dk_sn_kronometre](./04_Timer_Interrupt_Header_Stopwatch/01_dk_sn_kronometre.c) | **Ana Proje:** Timer Interrupt & Multiplexing. |
| [📂 02_Reaction_Timer](./04_Timer_Interrupt_Header_Stopwatch/02_Reaction_Timer.c) | **Refleks Ölçer:** Randomness & Input Capture. |
| [📂 03_Akıllı_Trafik...](./04_Timer_Interrupt_Header_Stopwatch/03_Akıllı_Trafik_Işığı_(FSM).c) | **Trafik FSM:** Finite State Machine mimarisi. |
| [📂 04_Simon_Says...](./04_Timer_Interrupt_Header_Stopwatch/04_Simon_Says_(Hafıza_Oyunu).c) | **Hafıza Oyunu:** Dizi yönetimi ve oyun mantığı. |
| [📂 05_Nefes_Alan...](./04_Timer_Interrupt_Header_Stopwatch/05_Nefes_Alan_Işık_(Breathing_LED).c) | **Breathing LED:** PWM simülasyonu. |
| [📂 06_Park_Sensoru...](./04_Timer_Interrupt_Header_Stopwatch/06_Park_Sensörü_Simülasyonu.c) | **Park Sensörü:** Data Mapping. |
| [📂 07_Pomodoro...](./04_Timer_Interrupt_Header_Stopwatch/07_Pomodoro_Zamanlayıcı.c) | **Pomodoro:** Geri sayım (Count-Down). |
| [📂 08_Mors...](./04_Timer_Interrupt_Header_Stopwatch/08_Mors_Alfabesi_Çevirici.c) | **Mors:** Text-to-Signal işleme. |
| [📂 09_Dijital_Zar...](./04_Timer_Interrupt_Header_Stopwatch/09_Dijital_Zar_(Rastgele_Sayı).c) | **Zar:** UX ve Modulo aritmetiği. |
| [📂 10_Menu_Kontrol...](./04_Timer_Interrupt_Header_Stopwatch/10_Butonla_Menü_Kontrolü.c) | **Menü:** State Management. |
| [📂 11_Up_Down...](./04_Timer_Interrupt_Header_Stopwatch/11_Çift_Yönlü_Sayıcı_(Up_Down_Counter).c) | **Sayaç:** Edge Case & Overflow koruması. |

---

## 🏛️ Kütüphane Yapısı
Timer projeleri için geliştirilen yardımcı yapı:
1.  **`bizimKutuphane.h`:** 7-Segment Multiplexing ve basamak ayırma motoru.
2.  **`stm32f4xx_it.c`:** Zamanlayıcı kesmesi (1Hz) ile arka plan sayıcı tetikleme.
3.  **`main.c`:** Ön plan (Foreground) tarama ve mantıksal kontrol döngüsü.

---

**Maintainer:** Merd0 (Mert Aydın)  
*Computer Engineering Dept. @ Fırat University*
