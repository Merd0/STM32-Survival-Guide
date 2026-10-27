# STM32 Survival Guide — Türkçe Öğrenme Yolu

**[English](LEARNING_PATH.md) | Türkçe**

Bu yol haritası, depodaki C örneklerini temel düzeyden ileri seviyeye doğru takip etmek içindir. C kodları iki dilde ortaktır; öğrenme açıklamaları ayrı EN/TR README dosyalarındadır.

| Aşama | Konular | Hedef |
| --- | --- | --- |
| **0 — Hazırlık** | STM32CubeMX, CubeIDE, STM32F4 HAL, GPIO yapılandırması | Pinleri ve kullanıcı kodu bloklarını tanımak |
| **1 — GPIO Output** | LED sırası, bit işlemleri, diziler, yazılımsal PWM | Çıkış desenlerini açıklamak ve değiştirmek |
| **2 — GPIO Input** | Buton okuma, toggle, durum geçişi, multiplexing | Girişe bağlı kararlı davranış oluşturmak |
| **3 — EXTI Temelleri** | Harici kesme, NVIC, öncelikler, debounce | EXTI'yi yapılandırmak ve kesmeyi gözlemlemek |
| **4 — Kesme Tasarımı** | ISR bayrakları, durum makineleri, kilitlenen durumlar | ISR içindeki işi azaltıp ana döngüye devretmek |
| **5 — Olay Senaryoları** | Encoder mantığı, cooldown, parti sayımı, double-click | Zaman ve durum yönetimini denemek |
| **6 — Timer** | Timer kesmesi, multiplexing, kronometre, trafik FSM | Bloklamayan zamanlayıcı tabanlı davranış kurmak |

## Modül sırası

1. [GPIO Output](README.tr.md) — LED desenleri ve binary sayaçlar.
2. [GPIO Input](README.tr.md) — buton ve durum yönetimi.
3. [EXTI / NVIC](03_Interrupts_EXTI/README.tr.md) — temel kesme ve öncelikler.
4. [Orta seviye kesmeler](03_Interrupts_EXTI/Interrupts_OrtaSeviye/README.tr.md) — bayraklar ve iş devri.
5. [İleri seviye kesmeler](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/README.tr.md) — olay odaklı senaryolar.
6. [Timer uygulamaları](04_Timer_Interrupt_Header_Stopwatch/README.tr.md) — kronometre, FSM ve zaman yönetimi.

## Nasıl çalışmalı?

Her örnekte önce CubeMX ayarlarını ve beklenen davranışı incele, kodu uygun STM32 projesine yerleştir, mümkünse gerçek kartta gözlemle ve sonucu kendi notlarınla karşılaştır. Her seferinde tek bir değişkeni değiştir.

**Sınır:** Bu örnekler doğrulanmış endüstriyel güvenlik işlevleri veya tümü donanım üzerinde otomatik test edilmiş ürünler olarak sunulmaz.

[Türkçe ana sayfa](README.tr.md) · [English learning path](LEARNING_PATH.md)
