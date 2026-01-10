/*
 * Dosya: 13_double_click.c
 * Senaryo: PB1 Butonu.
 * Tek Tık: Yeşil Yanar.
 * Çift Tık (Hızlıca): Kırmızı Yanar (Özel Fonksiyon).

 Vizyon: Tek bir butonla iki farklı iş yapmak. 
 Tek tıklama "Seç", Çift tıklama "Aç". 
 Mantık: İki basış arasındaki süre 300ms'den kısaysa bu bir "Double Click"tir.
 Uzunsa iki tane ayrı "Single Click"tir. 
 Bu, modern arayüzlerin (UI/UX) temelidir.
 */

static uint32_t son_tiklama_zamani = 0;

if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    uint32_t su_an = HAL_GetTick();

    // İki tıklama arasındaki farka bak
    if((su_an - son_tiklama_zamani) < 300) 
    {
        // --- DOUBLE CLICK ALGILANDI! ---
        // (Süre 300ms'den az, demek ki hızlı basıldı)
        
        // Kırmızıyı Yak (Double Click Aksiyonu)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
        for(volatile int i=0; i<500000; i++);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
        
        // Yeşil yanmışsa onu söndür (Single click iptali gibi düşün)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    }
    else 
    {
        // --- SINGLE CLICK ---
        // Yeşil Yak (Normal Aksiyon)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        // Not: Gerçek bir sistemde Single Click'in onaylanması için 
        // 300ms beklenir ama burada basitleştirdik.
    }

    // Zamanı güncelle
    son_tiklama_zamani = su_an;
}
