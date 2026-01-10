/*
 * EXTI1 (Kıdemli) - USER CODE BEGIN 0

 Senaryo: İkisinin de Preemption Priority'si aynı (0). Birbirlerini KESEMEZLER. Sadece sıraya girerler.

Ayarlar (CubeMX NVIC Sekmesi):

Priority Group: 2 bit Preemption, 2 bit SubPriority seçilmeli!

EXTI1 (PB1): Preemption 0, Sub-Priority 0 (Daha Kıdemli)

EXTI0 (PA0): Preemption 0, Sub-Priority 1 (Daha Kıdemsiz)

 */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET); // Mavi Yak
    // Bekle
    for(volatile int i=0; i<20000000; i++); 
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

/*
 * EXTI0 (Kıdemsiz) - USER CODE BEGIN 0
 */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); // Turuncu Yak
    
    // TEST: Turuncu yanarken PB1'e bas.
    // SONUÇ: Mavi YANMAZ! Turuncunun bitmesini bekler.
    // Çünkü Preemption (Patronluk) seviyeleri eşittir.
    for(volatile int i=0; i<20000000; i++); 
    
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
}
