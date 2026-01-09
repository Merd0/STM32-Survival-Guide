/*
 * Senaryo: Kapı zili gibi. Basınca çalar (yanar), çekince susar.
 * Buton: PA0 (User Button)
 * LED: PD12 (Yeşil)
 */

while (1) {
    // Butonu oku: 1 mi (Basılı) ?
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) {
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); // Yak
    } 
    else {
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); // Söndür
    }
}
