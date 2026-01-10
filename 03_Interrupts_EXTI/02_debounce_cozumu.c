/*
 * Dosya: 02_debounce_cozumu.c
 * Yer: USER CODE BEGIN 0
 
 */

// Global değişken (Dosyanın tepesine eklemeyi unutma)
// uint32_t last_time = 0;

//Senaryo: Ark önleme.

if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    uint32_t current_time = HAL_GetTick();

    // 200ms geçmediyse işlem yapma
    if((current_time - last_time) > 200) 
    {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12); 
        last_time = current_time; 
    }
}
// Kod buradan çıkınca otomatik temizlik yapılacak.
