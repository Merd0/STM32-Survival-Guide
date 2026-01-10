/*
 * Dosya: 10_kasa_sifresi.c
 * Senaryo: PB1 (A) ve PA0 (B) kombinasyonu.
 * Hedef Şifre: A -> B -> A

Senaryo: Dijital Kasa. Şifre: "A - B - A".
Sırayla: Buton A -> Buton B -> Buton A basılırsa kilit açılır.
Yanlış bir tuşa basılırsa (Mesela A -> A basılırsa) şifre sıfırlanır.
Vizyon: Bu bir "Finite State Machine" (Sonlu Durum Makinesi) örneğidir.
 */

// Bu değişkeni static yapıyoruz ki değeri kaybolmasın (Hafıza)
static int sifre_adimi = 0; 

// --- BUTON A (PB1) ---
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    if(sifre_adimi == 0) {
        sifre_adimi = 1; // 1. Adım Doğru (A basıldı)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); // Yeşil (İpucu)
    }
    else if(sifre_adimi == 2) {
        // ŞİFRE ÇÖZÜLDÜ! (A -> B -> A tamamlandı)
        sifre_adimi = 0; // Başa dön
        // Mavi LED ile kutla
        for(int k=0; k<5; k++) {
            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
            for(volatile int i=0; i<1000000; i++);
        }
    }
    else {
        sifre_adimi = 0; // YANLIŞ! Sıfırla.
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET); // Işıkları söndür
    }
}

// --- BUTON B (PA0) ---
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
{
    if(sifre_adimi == 1) {
        sifre_adimi = 2; // 2. Adım Doğru (A -> B basıldı)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); // Turuncu (İpucu)
    }
    else {
        sifre_adimi = 0; // YANLIŞ! Sıfırla.
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);
    }
}
