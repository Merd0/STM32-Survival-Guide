/*
 * PATRON (PB1) - stm32f4xx_it.c -> EXTI1_IRQHandler
 * Kısım: USER CODE BEGIN 0

 Senaryo: Araya döngü veya HAL_Delay koyarak diğer kesmeyi bekletmek.

Ayarlar (CubeMX NVIC Sekmesi):

EXTI1 (PB1 - Patron): Preemption 0

EXTI0 (PA0 - Çırak): Preemption 1
 */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    // Patron geldi! Çırak çalışıyorsa onu susturur, araya girer.
    for(int i=0; i<10; i++) {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12); // Yeşil Yak/Söndür
        // Hızlıca işimi hallediyorum
        for(volatile int k=0; k<2000000; k++); 
    }
}

/*
 * ÇIRAK (PA0) - stm32f4xx_it.c -> EXTI0_IRQHandler
 * Kısım: USER CODE BEGIN 0
 */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
{
    // Çırak çalışmaya başladı...
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); // Kırmızı Yan
    
    // Eğer bu döngü dönerken PB1'e basarsan, işlemci burayı dondurur, 
    // yukarıdaki PB1 kodunu yapar, sonra buraya geri döner.
    for(volatile int i=0; i<50000000; i++); 
    
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); // Kırmızı Sön
}
