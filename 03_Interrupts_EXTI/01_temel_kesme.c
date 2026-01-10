/*
 * Dosya: 01_temel_kesme.c
 * Yer: stm32f4xx_it.c -> void EXTI1_IRQHandler(void)
 * Kısım: USER CODE BEGIN EXTI1_IRQn 0
 */

// KONTROL: Eğer PB1'den geldiyse (Güvenlik kontrolü)
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    // LED'i Tersle (Toggle)
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12); // Yeşil LED
    
    // NOT: __HAL_GPIO_EXTI_CLEAR_IT yapmana gerek yok!
    // Fonksiyon bitince alttaki HAL_GPIO_EXTI_IRQHandler otomatik temizleyecek.
}
