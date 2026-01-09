/*
 * Dosya: 07_yukleme_cubugu.c
 * Açıklama: LED'ler sönmeden sırayla yanar (Loading Bar).
 * Yazar: Mert
 */

// Doldurma Fazı
for (int i = 0; i < 4; i++) {
    HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
    HAL_Delay(250);
}

// Boşaltma Fazı
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
HAL_Delay(500);
