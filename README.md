# STM32 Survival Guide: GPIO, Interrupts & Timers

![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-STM32F4-orange?style=flat-square)
![Topic](https://img.shields.io/badge/Domain-Embedded_Systems-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Active-blueviolet?style=flat-square)

## 📖 Repo Özeti
Bu depo, **Fırat Üniversitesi Bilgisayar Mühendisliği** müfredatını desteklemek ve gömülü sistemler dünyasına adım atan mühendisler için oluşturulmuş kapsamlı bir algoritma kütüphanesidir.

Proje, STM32 mimarisi üzerinde **GPIO**, **External Interrupts (EXTI)**, **Timer Interrupts** ve **Endüstriyel Algoritmalar** konularını kapsar. Basit pin kontrolünden başlayıp, öncelik yönetimi (NVIC), debouncing ve zamanlayıcı tabanlı multitasking yapılarına kadar uzanan optimize edilmiş C kodlarını barındırır.

---
## 📂 Algoritma Kütüphanesi

### 1. Modül: GPIO Output (Dijital Çıkış) 💡
*Konum:* [`01_GPIO_Output/`](./01_GPIO_Output/)

| Dosya Adı | Proje & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_sirali_akis.c`](./01_GPIO_Output/01_sirali_akis.c) | 🌊 **Sıralı Akış**<br>Temel `for` döngüsü ve pin kontrolü. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`02_kara_simsek.c`](./01_GPIO_Output/02_kara_simsek.c) | 🏎️ **Kara Şimşek**<br>Çift yönlü tarama (Ping-Pong) algoritması. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`03_binary_counter.c`](./01_GPIO_Output/03_binary_counter.c) | 🔢 **Binary Counter**<br>4-Bit Binary sayıcı (Bitwise Shifting). | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`04_polis_cakari.c`](./01_GPIO_Output/04_polis_cakari.c) | 🚓 **Polis Çakar**<br>Asenkron grup flaşör mantığı. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`05_yilan_efekti.c`](./01_GPIO_Output/05_yilan_efekti.c) | 🐍 **Yılan Efekti**<br>Dairesel kuyruk yapısı (Circular Buffer logic). | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`06_ozel_desen.c`](./01_GPIO_Output/06_ozel_desen.c) | 🎆 **Özel Desen**<br>Dizi (Array) tabanlı animasyon motoru. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`07_yukleme_cubugu.c`](./01_GPIO_Output/07_yukleme_cubugu.c) | 🔋 **Loading Bar**<br>Kümülatif artış simülasyonu. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`08_ters_binary.c`](./01_GPIO_Output/08_ters_binary.c) | 🔄 **Ters Binary**<br>Bitwise NOT (`~`) operatörü ile negatif lojik. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`09_hayalet_iz.c`](./01_GPIO_Output/09_hayalet_iz.c) | 👻 **Hayalet İz**<br>Software PWM ve Decay algoritması. | ![](https://img.shields.io/badge/-Uzman-blueviolet?style=flat-square) |

### 2. Modül: GPIO Input (Dijital Giriş) 🔘
*Konum:* [`02_GPIO_Input/`](./02_GPIO_Input/)

| Dosya Adı | Proje & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_basit_kontrol.c`](./02_GPIO_Input/01_basit_kontrol.c) | 🔌 **Basit I/O**<br>Butona basınca LED yakma. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`02_hedefli_yazdirma.c`](./02_GPIO_Input/02_hedefli_yazdirma.c) | 🎯 **Hedefli Kontrol**<br>Girişe göre belirli 7-segment hanesini yakma. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`03_butonlu_sayac.c`](./02_GPIO_Input/03_butonlu_sayac.c) | 🆙 **Butonlu Sayaç**<br>Buton ile sayı artırma (Basit Sayaç). | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`04_kapi_zili...`](./02_GPIO_Input/04_kapi_zili_basitDüzey.c) | 🔔 **Kapı Zili**<br>Bas-Çek mantığı (Push-Button Logic). | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`05_akilli_lamba...`](./02_GPIO_Input/05_akilli_lamba_basitDüzey.c) | 💡 **Akıllı Lamba**<br>Toggle (Anahtar) mantığı oluşturma. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`06_vites_kutusu...`](./02_GPIO_Input/06_vites_kutusu_basitDüzey.c) | 🕹️ **Vites Kutusu**<br>Switch-Case ile sıralı mod değişimi. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`07_guvenlik_kilidi...`](./02_GPIO_Input/07_guvenlik_kilidi_basitDüzey.c) | 🔐 **Güvenlik Kilidi**<br>Mantıksal VE (`&&`) ile çoklu giriş doğrulama. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`08_refleks_testi...`](./02_GPIO_Input/08_refleks_testi_basitDüzey.c) | ⚡ **Refleks Testi**<br>Basit tepki ölçüm mantığı. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |

### 3. Modül: Interrupts & EXTI (Dış Kesmeler) ⚡
*Konum:* [`03_Interrupts_EXTI/`](./03_Interrupts_EXTI/)

| Dosya Adı | Proje & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_temel_kesme.c`](./03_Interrupts_EXTI/01_temel_kesme.c) | 🚩 **Temel Kesme**<br>`HAL_GPIO_EXTI_Callback` kullanımı. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`02_debounce_cozumu.c`](./03_Interrupts_EXTI/02_debounce_cozumu.c) | 🛡️ **Debounce**<br>Millis() tabanlı buton arkı engelleme. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`01_mod_degistirici.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/01_mod_degistirici.c) | 🔄 **Mod Değiştirici**<br>Kesme ile çalışma modu değiştirme. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`03_acil_durum_freni.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/03_acil_durum_freni.c) | 🚨 **Emergency Stop**<br>Sistemsel kilitleme mekanizması. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`01_sanal_encoder.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/01_sanal_encoder.c) | 🎛️ **Sanal Encoder**<br>İki butonla Rotary Encoder simülasyonu. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`02_endustriyel_stop.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/02_endustriyel_stop.c) | 🛑 **Safety Logic**<br>Reset gerektiren endüstriyel durdurma. | ![](https://img.shields.io/badge/-Uzman-blueviolet?style=flat-square) |
| [`03_kasa_sifresi.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/03_kasa_sifresi.c) | 🔑 **Kasa Şifresi**<br>Sıralı giriş doğrulama algoritması. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`04_motor_koruma.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/04_motor_koruma.c) | ❄️ **Motor Koruma**<br>Cool-down (Soğuma süresi) koruması. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`05_paketleme_bandi.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/05_paketleme_bandi.c) | 📦 **Paketleme Bandı**<br>Sensör sayacı ve Batch kontrolü. | ![](https://img.shields.io/badge/-Uzman-blueviolet?style=flat-square) |

### 4. Modül: Timer Interrupts & Algorithms ⏱️
*Konum:* [`04_Timer_Interrupt_Header_Stopwatch/`](./04_Timer_Interrupt_Header_Stopwatch/)

| Dosya Adı | Proje & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_dk_sn_kronometre.c`](./04_Timer_Interrupt_Header_Stopwatch/01_dk_sn_kronometre.c) | ⏱️ **Kronometre**<br>Ana Proje: Timer Interrupt & Multiplexing. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`02_Reaction_Timer.c`](./04_Timer_Interrupt_Header_Stopwatch/02_Reaction_Timer.c) | ⚡ **Refleks Ölçer**<br>Randomness & Input Capture. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`03_Akıllı_Trafik...c`](./04_Timer_Interrupt_Header_Stopwatch/03_Akıllı_Trafik_Işığı_(FSM).c) | 🚦 **Trafik Işığı**<br>Finite State Machine (FSM) mimarisi. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`04_Simon_Says...c`](./04_Timer_Interrupt_Header_Stopwatch/04_Simon_Says_(Hafıza_Oyunu).c) | 🧠 **Hafıza Oyunu**<br>Dizi yönetimi ve oyun mantığı. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`05_Breathing_LED...c`](./04_Timer_Interrupt_Header_Stopwatch/05_Nefes_Alan_Işık_(Breathing_LED).c) | 🌬️ **Breathing LED**<br>PWM simülasyonu. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`06_Park_Sensoru...c`](./04_Timer_Interrupt_Header_Stopwatch/06_Park_Sensörü_Simülasyonu.c) | 🔊 **Park Sensörü**<br>Data Mapping ve sesli ikaz. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`07_Pomodoro...c`](./04_Timer_Interrupt_Header_Stopwatch/07_Pomodoro_Zamanlayıcı.c) | 🍅 **Pomodoro**<br>Geri sayım (Count-Down). | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`08_Mors_Cevirici...c`](./04_Timer_Interrupt_Header_Stopwatch/08_Mors_Alfabesi_Çevirici.c) | 📡 **Mors Kodu**<br>Text-to-Signal işleme. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`09_Dijital_Zar...c`](./04_Timer_Interrupt_Header_Stopwatch/09_Dijital_Zar_(Rastgele_Sayı).c) | 🎲 **Dijital Zar**<br>UX ve Modulo aritmetiği. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`10_Menu_Kontrol...c`](./04_Timer_Interrupt_Header_Stopwatch/10_Butonla_Menü_Kontrolü.c) | 📱 **Menü Sistemi**<br>State Management ve Multitasking. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`11_Up_Down...c`](./04_Timer_Interrupt_Header_Stopwatch/11_Çift_Yönlü_Sayıcı_(Up_Down_Counter).c) | 🔼 **İleri/Geri Sayaç**<br>Edge Case & Overflow koruması. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |

---

## 🏛️ Kütüphane Yapısı
Timer projeleri için geliştirilen yardımcı yapı:
1.  **`bizimKutuphane.h`:** 7-Segment Multiplexing ve basamak ayırma motoru.
2.  **`stm32f4xx_it.c`:** Zamanlayıcı kesmesi (1Hz) ile arka plan sayıcı tetikleme.
3.  **`main.c`:** Ön plan (Foreground) tarama ve mantıksal kontrol döngüsü.

---

**Maintainer:** Merd0 (Mert Aydın)  
*Computer Engineering Dept. @ Fırat University*
**Maintainer:** Merd0 (Mert Aydın)  
*Computer Engineering Dept. @ Fırat University*
