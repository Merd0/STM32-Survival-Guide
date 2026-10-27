**[English](README.md) | Türkçe** · [Öğrenme yolu](LEARNING_PATH.tr.md)

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

### 1. Modül: GPIO Output (Dijital Çıkış) 💡
*Konum:* [`01_GPIO_Output/`](./01_GPIO_Output/)

| Dosya Adı | Teknik Detay & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_sirali_akis.c`](./01_GPIO_Output/01_sirali_akis.c) | **Sıralı Akış**<br>`for` döngüsü ve `HAL_Delay` kullanarak pinleri sırayla kontrol eden temel akış. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`02_kara_simsek.c`](./01_GPIO_Output/02_kara_simsek.c) | **Kara Şimşek**<br>Bit kaydırma operatörleri (`<<`, `>>`) ile çift yönlü tarama (Ping-Pong) algoritması. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`03_binary_counter.c`](./01_GPIO_Output/03_binary_counter.c) | **Binary Counter**<br>4 LED ile 0-15 arası sayıları ikilik tabanda (Binary) saydıran bitwise algoritma. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`04_polis_cakari.c`](./01_GPIO_Output/04_polis_cakari.c) | **Polis Çakar**<br>İki farklı LED grubunun asenkron zamanlamalarla yanıp söndüğü flaşör mantığı. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`05_yilan_efekti.c`](./01_GPIO_Output/05_yilan_efekti.c) | **Yılan Efekti**<br>Modulo (`%`) aritmetiği kullanarak oluşturulan dairesel kuyruk (Circular Buffer) yapısı. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`06_ozel_desen.c`](./01_GPIO_Output/06_ozel_desen.c) | **Özel Desen**<br>Önceden tanımlanmış bir diziyi (`Array`) okuyarak özel ışık animasyonları oynatan motor. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`07_yukleme_cubugu.c`](./01_GPIO_Output/07_yukleme_cubugu.c) | **Loading Bar**<br>LED'lerin sönmeden üst üste eklenerek yandığı kümülatif artış simülasyonu. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`08_ters_binary.c`](./01_GPIO_Output/08_ters_binary.c) | **Ters Binary**<br>Bitwise NOT (`~`) operatörü ile negatif lojik (0 ise Yan, 1 ise Sön) kontrolü. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`09_hayalet_iz.c`](./01_GPIO_Output/09_hayalet_iz.c) | **Hayalet İz**<br>LED'in aniden sönmesi yerine yavaşça kararmasını sağlayan **Software PWM** ve Decay algoritması. | ![](https://img.shields.io/badge/-Uzman-blueviolet?style=flat-square) |

### 2. Modül: GPIO Input (Dijital Giriş) 🔘
*Konum:* [`02_GPIO_Input/`](./02_GPIO_Input/)

| Dosya Adı | Teknik Detay & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_basit_kontrol.c`](./02_GPIO_Input/01_basit_kontrol.c) | **Basit I/O**<br>`HAL_GPIO_ReadPin` ile buton durumunu okuyup LED yakan temel şart yapısı. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`02_hedefli_yazdirma.c`](./02_GPIO_Input/02_hedefli_yazdirma.c) | **Hedefli Kontrol**<br>Giriş sinyaline göre belirli bir 7-Segment hanesini (Digit) aktif eden seçici kontrol. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`03_butonlu_sayac.c`](./02_GPIO_Input/03_butonlu_sayac.c) | **Butonlu Sayaç**<br>Ekran taraması (Multiplexing) devam ederken butona basarak sayıyı artıran sayaç. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`04_kapi_zili_basitDüzey.c`](./02_GPIO_Input/04_kapi_zili_basitDüzey.c) | **Kapı Zili**<br>Butona basıldığı sürece aktif olan, bırakınca pasifleşen "Bas-Çek" (Push-Button) mantığı. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`05_akilli_lamba_basitDüzey.c`](./02_GPIO_Input/05_akilli_lamba_basitDüzey.c) | **Akıllı Lamba**<br>Butona bir kez basınca açılan, tekrar basınca kapanan (Toggle) hafızalı anahtar yapısı. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`05_vites_kutusu_basitDüzey.c`](./02_GPIO_Input/05_vites_kutusu_basitDüzey.c) | **Vites Kutusu**<br>Her basışta modu değiştiren (P -> R -> N -> D) `Switch-Case` tabanlı durum makinesi. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`07_guvenlik_kilidi_basitDüzey.c`](./02_GPIO_Input/07_guvenlik_kilidi_basitDüzey.c) | **Güvenlik Kilidi**<br>İki butona aynı anda basılmadıkça çalışmayan (`&&` operatörü) güvenlik kontrolü. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`08_refleks_testi_basitDüzey.c`](./02_GPIO_Input/08_refleks_testi_basitDüzey.c) | **Refleks Testi**<br>LED yandığı anda butona basmayı bekleyen, `HAL_GetTick()` kullanmayan basit ölçüm. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |

### 3. Modül: Interrupts & EXTI (Dış Kesmeler) ⚡
*Konum:* [`03_Interrupts_EXTI/`](./03_Interrupts_EXTI/README.tr.md)

**Temel Dosyalar (Root):**
| Dosya Adı | Teknik Detay & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_temel_kesme.c`](./03_Interrupts_EXTI/01_temel_kesme.c) | **Temel Kesme**<br>Polling yerine `HAL_GPIO_EXTI_Callback` kullanarak asenkron olay yakalama. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`02_debounce_cozumu.c`](./03_Interrupts_EXTI/02_debounce_cozumu.c) | **Debounce Çözümü**<br>Mekanik butonlardaki paraziti (ark) yazılımsal olarak süzen `millis()` tabanlı algoritma. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`03_oncelik_savasi_preemption.c`](./03_Interrupts_EXTI/03_oncelik_savasi_preemption.c) | **Preemption Priority**<br>İki kesme aynı anda gelirse hangisinin çalışacağını belirleyen öncelik testi. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`04_esit_oncelik_subpriority.c`](./03_Interrupts_EXTI/04_esit_oncelik_subpriority.c) | **Sub-Priority**<br>Aynı önceliğe sahip kesmelerin çakışma durumunda nasıl davrandığını gösteren yapı. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |

**Orta Seviye (Subfolder):**
| Dosya Adı | Teknik Detay & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_mod_degistirici.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/01_mod_degistirici.c) | **Mod Değiştirici**<br>Kesme kullanarak sistemin çalışma modunu (Örn: Eco, Sport) değiştiren state yapısı. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`02_bayrak_yarisi.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/02_bayrak_yarisi.c) | **Bayrak Yarışı**<br>Kesme içinde sadece `volatile` bayrak kaldırıp, ağır işi ana döngüye yaptıran güvenli kod. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`03_acil_durum_freni.c`](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/03_acil_durum_freni.c) | **Emergency Stop**<br>Butona basıldığında sistemi kilitleyen ve resetlenene kadar açılmayan güvenlik kodu. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |

**İleri Seviye (Subfolder):**
| Dosya Adı | Teknik Detay & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_sanal_encoder.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/01_sanal_encoder.c) | **Sanal Encoder**<br>İki buton kullanarak Rotary Encoder (Sağa/Sola dönüş) mantığını simüle eden yapı. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`02_endustriyel_stop.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/02_endustriyel_stop.c) | **Safety Logic**<br>Makine durdurulduktan sonra tekrar çalışması için "Kurma" (Arming) gerektiren kod. | ![](https://img.shields.io/badge/-Uzman-blueviolet?style=flat-square) |
| [`03_kasa_sifresi.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/03_kasa_sifresi.c) | **Kasa Şifresi**<br>Butonlara doğru sırada (Örn: 1-2-1) basıldığında kilidi açan sıralı doğrulama. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`04_motor_koruma.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/04_motor_koruma.c) | **Motor Koruma**<br>Motor kapatıldıktan sonra hemen açılmasını engelleyen "Cool-down" zamanlayıcısı. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`05_paketleme_bandi.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/05_paketleme_bandi.c) | **Paketleme Bandı**<br>Sensörden gelen ürünleri sayan ve belirli sayıda (Batch) olunca sistemi durduran otomasyon. | ![](https://img.shields.io/badge/-Uzman-blueviolet?style=flat-square) |
| [`06_double_click.c`](./03_Interrupts_EXTI/Interrupts_İleriSeviye/06_double_click.c) | **Double Click**<br>Mouse mantığı: Tek tıklama ile Çift tıklamayı zaman farkına göre ayırt eden algoritma. | ![](https://img.shields.io/badge/-Uzman-blueviolet?style=flat-square) |

### 4. Modül: Timer Interrupts & Algorithms ⏱️
*Konum:* [`04_Timer_Interrupt_Header_Stopwatch/`](./04_Timer_Interrupt_Header_Stopwatch/README.tr.md)

| Dosya Adı | Teknik Detay & Açıklama | Zorluk |
| :--- | :--- | :---: |
| [`01_dk_sn_kronometre`](./04_Timer_Interrupt_Header_Stopwatch/01_dk_sn_kronometre) | **Kronometre (Ana Proje)**<br>Arka planda zamanı sayarken ön planda ekranı süren Dakika:Saniye kronometresi. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`02_Reaction_Timer`](./04_Timer_Interrupt_Header_Stopwatch/02_Reaction_Timer) | **Refleks Ölçer**<br>Rastgele bir zamanda yanan ışığa tepki süresini milisaniye cinsinden ölçer. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`03_Akıllı_Trafik_Işığı_(FSM)`](./04_Timer_Interrupt_Header_Stopwatch/03_Ak%C4%B1ll%C4%B1_Trafik_I%C5%9F%C4%B1%C4%9F%C4%B1_%28FSM%29) | **Trafik FSM**<br>Yaya butonu ile güvenli geçiş sağlayan, "State Machine" mimarili akıllı trafik ışığı. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`04_Simon_Says_(Hafıza Oyunu)`](./04_Timer_Interrupt_Header_Stopwatch/04_Simon_Says_%28Haf%C4%B1za%20Oyunu%29) | **Hafıza Oyunu**<br>Rastgele yanan LED dizisini aklınızda tutup tekrar etmenizi isteyen oyun algoritması. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`05_Nefes_Alan_Işık_(Breathing LED)`](./04_Timer_Interrupt_Header_Stopwatch/05_Nefes_Alan_I%C5%9F%C4%B1k_%28Breathing%20LED%29) | **Breathing LED**<br>PWM simülasyonu ile LED'in "nefes alıyormuş gibi" yavaşça yanıp sönmesi. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`06_Park_Sensörü_Simülasyonu`](./04_Timer_Interrupt_Header_Stopwatch/06_Park_Sensörü_Simülasyonu) | **Park Sensörü**<br>Mesafe azaldıkça buzzer'ın ötme sıklığını artıran veri haritalama (Mapping) örneği. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`07_Pomodoro_Zamanlayıcı`](./04_Timer_Interrupt_Header_Stopwatch/07_Pomodoro_Zamanlayıcı) | **Pomodoro**<br>25 dakikadan geriye sayan, 0 olunca alarm veren çalışma/ders zamanlayıcısı. | ![](https://img.shields.io/badge/-Orta-warning?style=flat-square) |
| [`08_Mors_Alfabesi_Çevirici`](./04_Timer_Interrupt_Header_Stopwatch/08_Mors_Alfabesi_Çevirici) | **Mors Çevirici**<br>Girilen metni (String) otomatik olarak ışık sinyallerine (Nokta-Çizgi) dönüştüren motor. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`09_Dijital_Zar_(Rastgele Sayı)`](./04_Timer_Interrupt_Header_Stopwatch/09_Dijital_Zar_%28Rastgele%20Say%C4%B1%29) | **Dijital Zar**<br>Butona basılınca sayıları hızla döndüren, bırakınca rastgele bir sayıda duran şans oyunu. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |
| [`10_Butonla_Menü_Kontrolü`](./04_Timer_Interrupt_Header_Stopwatch/10_Butonla_Menü_Kontrolü) | **Menü Sistemi**<br>Tek butonla farklı ekranlar (Saat -> Sıcaklık -> Nem) arasında gezmeyi sağlayan yapı. | ![](https://img.shields.io/badge/-İleri-critical?style=flat-square) |
| [`11_Çift_Yönlü_Sayıcı_(Up_Down_Counter)`](./04_Timer_Interrupt_Header_Stopwatch/11_%C3%87ift_Y%C3%B6nl%C3%BC_Say%C4%B1c%C4%B1_%28Up_Down_Counter%29) | **Sayaç**<br>Sayının 0'ın altına düşmesini veya sınırı aşmasını engelleyen (Edge Case) korumalı sayaç. | ![](https://img.shields.io/badge/-Başlangıç-success?style=flat-square) |

---

## 🏛️ Kütüphane Yapısı
Timer projeleri için geliştirilen yardımcı yapı:
1.  **`bizimKutuphane.h`:** 7-Segment Multiplexing ve basamak ayırma motoru.
2.  **`stm32f4xx_it.c`:** Zamanlayıcı kesmesi ile arka plan sayıcı tetikleme.
3.  **`main.c`:** Ön plan (Foreground) tarama ve mantıksal kontrol döngüsü.

---

> [!IMPORTANT]  
> **⚠️ Kritik Uyarı: Timer Başlatma** > CubeMX üzerinden Timer ayarlarını (Prescaler, Period) yapsanız bile, kodun `main.c` dosyasında Timer'ı yazılımsal olarak başlatmazsanız kesmeler çalışmaz.
>
> `USER CODE BEGIN 2` bloğuna şu kodu eklemeyi unutmayın:
> ```c
> HAL_TIM_Base_Start_IT(&htim1); // Kullandığınız Timer kanalına göre (htim1, htim10 vs.) değişir.
> ```

**Maintainer:** Merd0 (Mert Aydın)  
*Computer Engineering Dept. @ Fırat University*
