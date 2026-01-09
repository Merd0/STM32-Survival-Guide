/*
 * ======================================================================================
 * PROJE: SOFTWARE PWM ILE HAYALET LED EFEKTİ (GHOST TRAIL)
 * SEVİYE: İLERİ DÜZEY (Advanced)
 * ======================================================================================
 * * SORU: Biz derste sadece LED'i YAK (1) veya SÖNDÜR (0) demeyi öğrendik. 
 * Ara tonları (mesela %50 parlaklık) nasıl yapıyoruz?
 * * CEVAP: "GÖZ YANILMASI" (PWM - Pulse Width Modulation) Tekniği ile.
 * * MANTIK NASIL ÇALIŞIYOR?
 * -----------------------
 * Dijital dünyada "yarım voltaj" diye bir şey yoktur. Pin ya 3.3V'tur ya 0V'tur.
 * Ama eğer bir LED'i saniyede 1000 kere yakıp söndürürseniz, gözünüz bu hıza
 * yetişemez ve LED'i sürekli yanıyormuş gibi görür.
 * * HİLE ŞURADA:
 * Bir periyot içinde (mesela 10 ms), LED'i ne kadar süre "AÇIK" tuttuğumuz önemlidir.
 * * ÖRNEK SENARYO (Bir Döngü İçinde):
 * Sayacımız 0'dan 100'e kadar sayıyor olsun.
 * * DURUM 1: %20 PARLAKLIK İSTİYORUZ
 * - Sayaç 0..20 arasındayken -> LED'i YAK.
 * - Sayaç 21..100 arasındayken -> LED'i SÖNDÜR.
 * - SONUÇ: LED zamanın %20'sinde yanık, %80'inde sönük. Göz bunu "kısık ışık" görür.
 * * DURUM 2: %80 PARLAKLIK İSTİYORUZ
 * - Sayaç 0..80 arasındayken -> LED'i YAK.
 * - Sayaç 81..100 arasındayken -> LED'i SÖNDÜR.
 * - SONUÇ: LED zamanın %80'inde yanık. Göz bunu "parlak ışık" görür.
 * * --------------------------------------------------------------------------------------
 * KODDAKİ "HAYALET İZ" (TRAIL) NASIL OLUŞUYOR?
 * * Biz ışığı "KÜT" diye söndürmüyoruz. Parlaklık değerini her turda çarpıyoruz:
 * * parlaklik = parlaklik * 0.75;
 * * 1. Tur: Parlaklık 100 (Tam yanıyor)
 * 2. Tur: 100 * 0.75 = 75 (Biraz söndü)
 * 3. Tur: 75 * 0.75 = 56 (Daha da söndü)
 * 4. Tur: 56 * 0.75 = 42 ...
 * * Bu matematiksel işlem sayesinde ışık arkasında bir "kuyruk" bırakarak yavaşça yok olur.
 * ======================================================================================
 */

// Global Değişkenler (while döngüsünden önce tanımla)
// Her LED'in o anki parlaklık değeri (0 ile 100 arası)
float parlakliklar[] = {0, 0, 0, 0}; 

// Işığın konumu ve yönü
int kafa_pozisyonu = 0;
int yon = 1;

// Zamanlama sayaçları
uint32_t pwm_sayaci = 0;
uint32_t animasyon_zamani = 0;

// --- AYARLAR ---
// Işığın ne kadar hızlı hareket edeceği (Düşük = Hızlı)
#define HIZ 100 
// Arkadaki izin ne kadar uzun kalacağı (0.5 = Hızlı söner, 0.9 = Uzun iz)
#define SOGUMA_CARPANI 0.75 

// --- ANA DÖNGÜ ---
while (1) 
{
    // ==========================================
    // BÖLÜM 1: GÖRÜNTÜ MOTORU (Software PWM)
    // ==========================================
    /* * Burası mikrosaniyeler içinde binlerce kez döner.
     * Gözün göremeyeceği hızda LED'leri açıp kapatarak
     * "kısık ışık" illüzyonu yaratır.
     */
    pwm_sayaci++;
    if (pwm_sayaci > 100) pwm_sayaci = 0; // 0-100 arası sayar

    for (int i = 0; i < 4; i++) {
        // Eğer o LED'in parlaklık değeri, sayaçtan büyükse YAK
        // Örnek: Parlaklık 20 ise, döngünün %20'sinde yanık kalır (Kısık ışık)
        if (pwm_sayaci < (int)parlakliklar[i]) {
            HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET);
        }
    }

    // ==========================================
    // BÖLÜM 2: FİZİK VE ANİMASYON MOTORU
    // ==========================================
    /*
     * Burası her 'HIZ' milisaniyede bir çalışır.
     * Işığın konumunu değiştirir ve arkadaki izleri soğutur.
     */
    if (HAL_GetTick() - animasyon_zamani > HIZ) 
    {
        animasyon_zamani = HAL_GetTick();

        // 1. Tüm LED'lerin parlaklığını biraz azalt (Sönümleme/Decay Efekti)
        // Her turda parlaklık %75'ine düşer. (100 -> 75 -> 56 -> 42...)
        for (int i = 0; i < 4; i++) {
            parlakliklar[i] = parlakliklar[i] * SOGUMA_CARPANI;
        }

        // 2. "Kafa" (Head) LED'ini tam parlaklığa çek
        parlakliklar[kafa_pozisyonu] = 100.0;

        // 3. Kafayı ilerlet
        kafa_pozisyonu += yon;

        // 4. Duvarlara çarpma kontrolü
        if (kafa_pozisyonu == 3) yon = -1;
        if (kafa_pozisyonu == 0) yon = 1;
    }
}
