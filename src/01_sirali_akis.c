/*
 * Dosya: 01_sirali_akis.c
 * Açıklama: LED'leri sırayla yakıp söndürür.
 * Yazar: Mert
 */

// Gerekli Tanımlama (main.c içinde olmalı)
// uint16_t pinler[] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};

for (int i = 0; i < 4; i++) {
    HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);   // Yak
    HAL_Delay(200);
    HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET); // Söndür
}
