/*
 * Dosya: 07_acil_durum_freni.c
 * Yer: stm32f4xx_it.c -> EXTI15_10_IRQHandler (Eğer PA13 ise)
 * Kısım: USER CODE BEGIN 0

 Senaryo: Sistem çalışırken (hangi modda olursa olsun) PA13 butonuna basılırsa HER ŞEYİ DURDUR ve Kırmızı LED'i yak. 
 Tekrar resetlenene kadar sistem çalışmasın. Öğretilen: Override (Baskılama) mantığı.
 */

// PA13 Kesmesi (Genelde EXTI15_10 hattındadır)
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_13) != RESET)
{
    // Acil Durumu Aktif Et
    acil_durum = 1;
    
    // 1. Tüm yeşil/mavi işlerini söndür
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_RESET);
    
    // 2. Kırmızı Alarmı Yak
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
    
    // 3. Sistemi Kilitle (İsteğe bağlı sonsuz döngü)
    // while(1); // Burayı açarsan işlemci donar, reset atana kadar düzelmez.
}
