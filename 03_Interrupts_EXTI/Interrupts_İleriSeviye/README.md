# 🚀 Mühendislik Vizyonu: Gerçek Hayat Senaryoları (Real-World Logic)

![Level](https://img.shields.io/badge/Level-Professional-red?style=flat-square)
![Focus](https://img.shields.io/badge/Focus-System_Safety_%26_UX-blue?style=flat-square)
![Concept](https://img.shields.io/badge/Concept-Event_Driven-green?style=flat-square)

## 👁️ Vizyon ve Amaç
Bir gömülü yazılım mühendisini, hobi devreleri kuran birinden ayıran temel fark **kodun karmaşıklığı değil, senaryonun gerçekçiliğidir.**

Bu modül, basit bir "LED Yak/Söndür" uygulamasının ötesine geçerek; **endüstriyel güvenlik standartlarını**, **donanım koruma protokollerini** ve **kullanıcı deneyimi (UX)** algoritmalarını simüle eder.

Buradaki amaç, yazılıma şu soruları sordurabilmektir:
* *"Kullanıcı butona basılı tutarsa sistem bozulur mu?"*
* *"Acil durumda sistem kendini kilitleyebiliyor mu?"*
* *"Operatör hata yaparsa donanım yanar mı?"*

---

## 🏭 Endüstriyel Senaryolar ve Çözümler

Bu klasördeki her kod parçası, fabrikalarda veya tüketici elektroniğinde karşılaşılan somut bir probleme çözüm üretir.

| Dosya | Problem (Gerçek Hayat) | Mühendislik Çözümü | Vizyon |
| :--- | :--- | :--- | :--- |
| [📂 01_sanal_encoder.c](./08_sanal_encoder.c) | **Sınır İhlali:** Ses sisteminde sesi 100'den yukarı açmaya çalışmak veya robot kolu fiziksel sınırın ötesine zorlamak. | **Clamping (Sınırlandırma):** Değerleri min/max aralığına hapseder. Kullanıcı zorlasa bile yazılım donanımı korur. | 🛡️ Sınır Yönetimi |
| [📂 02_endustriyel_stop.c](./09_endustriyel_stop.c) | **Güvenlik Riski:** Pres makinesinde elini kaptıran işçi butona basar, elini çekince makine tekrar çalışmamalıdır. | **Latching (Mühürleme):** Sistem "Hata Moduna" geçer. Yetkili personel "Reset" atana kadar sistem kilitli kalır. | 🚨 İş Güvenliği (Safety) |
| [📂 03_kasa_sifresi.c](./10_kasa_sifresi.c) | **Sıralı İşlem:** Bir kasanın veya nükleer ateşleme sisteminin belirli bir sıra (A->B->A) ile çalışması gerekir. | **Finite State Machine (FSM):** Her basış sistemi bir sonraki duruma taşır. Hata yapılırsa sistem başa döner. | 🔐 Algoritma Mantığı |
| [📂 04_motor_koruma.c](./11_motor_koruma.c) | **Donanım Hasarı:** Dev motorlar veya ısıtıcılar aniden kapatılıp hemen geri açılamaz (Deşarj süresi). | **Cool-Down (Soğuma):** Yazılım, son kapanma süresini hafızada tutar ve güvenli süre geçmeden yeniden başlatmayı reddeder. | ❄️ Donanım Ömrü |
| [📂 05_paketleme_bandi.c](./12_paketleme_bandi.c) | **Otomasyon:** Üretim bandında ürünleri tek tek sayıp kolilemek gerekir. | **Process Automation:** Belirli bir eşik değere (Threshold) ulaşınca tetiklenir ve sistemi otomatik sıfırlar. | 📦 Üretim Takibi |
| [📂 06_double_click.c](./13_double_click.c) | **Kullanıcı Deneyimi:** Tek bir butonla birden fazla komut (Seç/Aç) vermek. | **Time-Domain Analysis:** İki sinyal arasındaki süreyi (dt) ölçerek kullanıcın niyetini (Tek tık vs Çift tık) anlar. | 🖱️ HMI / UX |

---

## 🧠 Bu Modül Size Ne Katar?

Bu kodları inceleyip uyguladığınızda şunları fark edeceksiniz:
1.  **Hafıza Kullanımı:** `static` değişkenler kullanarak sistemin geçmişini (örn: motor ne zaman kapandı?) hatırlamayı.
2.  **Zaman Yönetimi:** Kesme içinde `Delay` kullanmadan, zaman farklarını (`HAL_GetTick`) ölçerek karar vermeyi.
3.  **Hata Toleransı:** Kullanıcının rastgele veya hatalı basışlarına karşı sistemin kararlı (stable) kalmasını sağlamayı.

---

## ⚠️ Teknik Kurulum Notu

Bu kodlar **Interrupt Handler** yapısı üzerine kuruludur. Çalışmaları için `stm32f4xx_it.c` dosyasının en tepesinde (Global Alan) şu değişkenlerin tanımlı olması gerekir:

```c
/* USER CODE BEGIN 0 */
int sistem_modu = 0;       // Genel durum değişkeni
int acil_durum = 0;        // Güvenlik kilidi
/* USER CODE END 0 */
