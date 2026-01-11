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
| **7-Segment (MUX)** | `GPIOE` [4, 5, 6, 7] | Hane Seçimi (Digit Select - Transistör Tetikleme) |
| **7-Segment (Data)** | `GPIOE` [8 - 15] | Segment Veri Hattı (A-G, DP) |

---

## 📂 Algoritma Kütüphanesi

### 1. Modül: GPIO Output (Dijital Çıkış)
*Konum:* [`01_GPIO_Output/`](./01_GPIO_Output/)  
LED animasyonları, bit manipülasyonu ve port kontrol teknikleri.

| Dosya | Detaylı Açıklama | Seviye |
| :--- | :--- | :--- |
| [📂 01_sirali_akis.c](./01_GPIO_Output/01_sirali_akis.c) | `For` döngüsü kullanarak LED'leri sırayla yakıp söndüren temel akış kontrolü. | Başlangıç |
| [📂 02_kara_simsek.c](./01_GPIO_Output/02_kara_simsek.c) | LED'lerin sağa ve sola kayarak akmasını sağlayan klasik "Knight Rider" algoritması. | Orta |
| [📂 03_binary_counter.c](./01_GPIO_Output/03_binary_counter.c) | 4 LED ile 0-15 arası sayıları ikilik tabanda (Binary) saydıran bit kaydırma örneği. | İleri |
| [📂 04_polis_cakari.c](./01_GPIO_Output/04_polis_cakari.c) | Kırmızı ve Mavi LED gruplarının asenkron olarak yanıp söndüğü flaşör efekti. | Orta |
| [📂 05_yilan_efekti.c](./01_GPIO_Output/05_yilan_efekti.c) | Kuyruk mantığıyla birbirini takip eden LED grubu (Dairesel Buffer mantığı). | Orta |
| [📂 06_ozel_desen.c](./01_GPIO_Output/06_ozel_desen.c) | Önceden tanımlanmış bir diziyi (Array) okuyarak özel ışık animasyonları oynatır. | Orta |
| [📂 07_yukleme_cubugu.c](./01_GPIO_Output/07_yukleme_cubugu.c) | LED'lerin sönmeden üst üste eklenerek yandığı "Loading Bar" simülasyonu. | Başlangıç |
| [📂 08_ters_binary.c](./01_GPIO_Output/08_ters_binary.c) | Bitwise NOT (`~`) operatörü kullanarak negatif lojik (0 ise Yan, 1 ise Sön) kontrolü. | İleri |
| [📂 09_hayalet_iz.c](./01_GPIO_Output/09_hayalet_iz.c) | LED'in aniden sönmesi yerine yavaşça kararmasını sağlayan **Software PWM** efekti. | Uzman |

### 2. Modül: GPIO Input (Dijital Giriş)
*Konum:* [`02_GPIO_Input/`](./02_GPIO_Input/)  
Buton okuma, karar yapıları ve 7-Segment Display etkileşimi.

| Dosya | Detaylı Açıklama | Seviye |
| :--- | :--- | :--- |
| [📂 01_basit_kontrol.c](./02_GPIO_Input/01_basit_kontrol.c) | Butona basıldığı sürece LED yakan, bırakınca söndüren temel giriş-çıkış kontrolü. | Başlangıç |
| [📂 02_hedefli_yazdirma.c](./02_GPIO_Input/02_hedefli_yazdirma.c) | Hangi butona basılırsa Display'in o hanesini (Digit) aktif eden seçici kontrol. | Orta |
| [📂 03_butonlu_sayac.c](./02_GPIO_Input/03_butonlu_sayac.c) | Ekran taraması (Multiplexing) devam ederken butona basarak sayıyı artıran sayaç. | Orta |
| [📂 04_kapi_zili...](./02_GPIO_Input/04_kapi_zili_basitDüzey.c) | Butona basınca çalan, bırakınca susan "Bas-Çek" (Push-Button) mantığı. | Başlangıç |
| [📂 05_akilli_lamba...](./02_GPIO_Input/05_akilli_lamba_basitDüzey.c) | Butona bir kez basınca açılan, tekrar basınca kapanan (Toggle/Anahtar) hafıza yapısı. | İleri |
| [📂 05_vites_kutusu...](./02_GPIO_Input/05_vites_kutusu_basitDüzey.c) | Butona her basışta modu değiştiren (P -> R -> N -> D) `Switch-Case` yapısı. | İleri |
| [📂 07_guvenlik_kilidi...](./02_GPIO_Input/07_guvenlik_kilidi_basitDüzey.c) | İki butona aynı anda basılmadıkça çalışmayan (`&&` operatörü) güvenlik kontrolü. | Orta |
| [📂 08_refleks_testi...](./02_GPIO_Input/08_refleks_testi_basitDüzey.c) | LED yandığı anda butona basmayı bekleyen basit tepki ölçüm mantığı. | Başlangıç |

### 3. Modül: Interrupts & EXTI (Dış Kesmeler)
*Konum:* [`03_Interrupts_EXTI/`](./03_Interrupts_EXTI/)  
İşlemciyi durdurmadan olay yakalama, öncelik yönetimi ve buton parazit çözümleri.

#### 🔹 Temel Kavramlar (Root)
| Dosya | Detaylı Açıklama | Seviye |
| :--- | :--- | :--- |
| [📂 01_temel_kesme.c](./03_Interrupts_EXTI/01_temel_kesme.c) | Butona basıldığı an ana döngüyü bölüp LED yakan `HAL_GPIO_EXTI_Callback` yapısı. | Başlangıç |
| [📂 02_debounce_cozumu.c](./03_Interrupts_EXTI/02_debounce_cozumu.c) | Mekanik butonlardaki paraziti (ark) yazılımsal olarak süzen "Debounce" algoritması. | Orta |
| [📂 03_oncelik_savasi...](./03_Interrupts_EXTI/03_oncelik_savasi_preemption.c) | İki kesme aynı anda gelirse hangisinin çalışacağını belirleyen (Preemption) test kodu. | İleri |
| [📂 04_esit_oncelik...](./03_Interrupts_EXTI/04_esit_oncelik_subpriority.c) | Aynı önceliğe sahip kesmelerin çakışma durumunda (Sub-Priority) nasıl davrandığı. | İleri |

#### 🔸 Orta Seviye Senaryolar
| Dosya | Detaylı Açıklama | Seviye |
| :--- | :--- | :--- |
| [📂 01_mod_degistirici.c](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/01_mod_degistirici.c) | Kesme kullanarak sistemin çalışma modunu (Örn: Eco, Sport) değiştiren yapı. | Orta |
| [📂 02_bayrak_yarisi.c](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/02_bayrak_yarisi.c) | Kesme içinde sadece `volatile` bayrak kaldırıp, işi ana döngüye yaptıran güvenli kod. | Orta |
| [📂 03_acil_durum_freni.c](./03_Interrupts_EXTI/Interrupts_OrtaSeviye/03_acil_durum_freni.c) | Butona basıldığında tüm sistemi kilitleyen ve resetlenene kadar açılmayan "Emergency Stop". | Orta |

#### 🚀 İleri Seviye (Endüstriyel)
| Dosya | Detaylı Açıklama | Seviye |
| :--- | :--- | :--- |
| [📂 01_sanal_encoder.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/01_sanal_encoder.c) | İki buton kullanarak Rotary Encoder (Sağa/Sola dönüş) mantığını simüle eden kod. | İleri |
| [📂 02_endustriyel_stop.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/02_endustriyel_stop.c) | Makine durdurulduktan sonra tekrar çalışması için "Kurma" (Arming) gerektiren güvenlik kodu. | Uzman |
| [📂 03_kasa_sifresi.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/03_kasa_sifresi.c) | Butonlara doğru sırada (Örn: 1-2-1) basıldığında kilidi açan sıralı doğrulama. | İleri |
| [📂 04_motor_koruma.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/04_motor_koruma.c) | Motor kapatıldıktan sonra hemen açılmasını engelleyen "Cool-down" (Soğuma süresi) koruması. | İleri |
| [📂 05_paketleme_bandi.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/05_paketleme_bandi.c) | Sensörden gelen ürünleri sayan ve belirli sayıda (Batch) olunca sistemi durduran otomasyon. | Uzman |
| [📂 06_double_click.c](./03_Interrupts_EXTI/Interrupts_İleriSeviye/06_double_click.c) | Mouse mantığı: Tek tıklama ile Çift tıklamayı zaman farkına göre ayırt eden algoritma. | Uzman |

### 4. Modül: Timer Interrupts & Algorithms
*Konum:* [`04_Timer_Interrupt_Header_Stopwatch/`](./04_Timer_Interrupt_Header_Stopwatch/)  
İşlemciyi meşgul etmeden (Non-blocking) zaman yönetimi ve gelişmiş algoritma senaryoları.

| Dosya | Proje & Vizyon | Seviye |
| :--- | :--- | :--- |
| [📂 01_dk_sn_kronometre](./04_Timer_Interrupt_Header_Stopwatch/01_dk_sn_kronometre.c) | **Ana Proje:** Arka planda zamanı sayarken ön planda ekranı süren Dakika:Saniye kronometresi. | Orta |
| [📂 02_Reaction_Timer](./04_Timer_Interrupt_Header_Stopwatch/02_Reaction_Timer.c) | **Refleks Ölçer:** Rastgele bir zamanda yanan ışığa ne kadar hızlı tepki verdiğinizi milisaniye cinsinden ölçer. | Başlangıç |
| [📂 03_Akıllı_Trafik...](./04_Timer_Interrupt_Header_Stopwatch/03_Akıllı_Trafik_Işığı_(FSM).c) | **Trafik FSM:** Yaya butonu ile güvenli geçiş sağlayan, "State Machine" mimarili akıllı trafik ışığı. | İleri |
| [📂 04_Simon_Says...](./04_Timer_Interrupt_Header_Stopwatch/04_Simon_Says_(Hafıza_Oyunu).c) | **Hafıza Oyunu:** Rastgele yanan LED dizisini aklınızda tutup tekrar etmenizi isteyen oyun algoritması. | Orta |
| [📂 05_Breathing_LED...](./04_Timer_Interrupt_Header_Stopwatch/05_Nefes_Alan_Işık_(Breathing_LED).c) | **Breathing LED:** PWM simülasyonu ile LED'in "nefes alıyormuş gibi" yavaşça yanıp sönmesi. | Orta |
| [📂 06_Park_Sensoru...](./04_Timer_Interrupt_Header_Stopwatch/06_Park_Sensörü_Simülasyonu.c) | **Park Sensörü:** Mesafe azaldıkça buzzer'ın ötme sıklığını artıran veri haritalama (Mapping) örneği. | Orta |
| [📂 07_Pomodoro...](./04_Timer_Interrupt_Header_Stopwatch/07_Pomodoro_Zamanlayıcı.c) | **Pomodoro:** 25 dakikadan geriye sayan, 0 olunca alarm veren çalışma zamanlayıcısı. | Orta |
| [📂 08_Mors_Cevirici...](./04_Timer_Interrupt_Header_Stopwatch/08_Mors_Alfabesi_Çevirici.c) | **Mors:** Girilen metni (String) otomatik olarak ışık sinyallerine (Nokta-Çizgi) dönüştüren çevirici. | İleri |
| [📂 09_Dijital_Zar...](./04_Timer_Interrupt_Header_Stopwatch/09_Dijital_Zar_(Rastgele_Sayı).c) | **Zar:** Butona basılınca sayıları hızla döndüren, bırakınca rastgele bir sayıda duran şans oyunu. | Başlangıç |
| [📂 10_Menu_Kontrol...](./04_Timer_Interrupt_Header_Stopwatch/10_Butonla_Menü_Kontrolü.c) | **Menü:** Tek butonla farklı ekranlar (Saat -> Sıcaklık -> Nem) arasında gezmeyi sağlayan yapı. | İleri |
| [📂 11_Up_Down...](./04_Timer_Interrupt_Header_Stopwatch/11_Çift_Yönlü_Sayıcı_(Up_Down_Counter).c) | **Sayaç:** Sayının 0'ın altına düşmesini veya sınırı aşmasını engelleyen (Edge Case) korumalı sayaç. | Başlangıç |

---

## 🏛️ Kütüphane Yapısı
Timer projeleri için geliştirilen yardımcı yapı:
1.  **`bizimKutuphane.h`:** 7-Segment Multiplexing ve basamak ayırma motoru.
2.  **`stm32f4xx_it.c`:** Zamanlayıcı kesmesi (1Hz) ile arka plan sayıcı tetikleme.
3.  **`main.c`:** Ön plan (Foreground) tarama ve mantıksal kontrol döngüsü.

---

**Maintainer:** Merd0 (Mert Aydın)  
*Computer Engineering Dept. @ Fırat University*
