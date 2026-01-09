/*
 * Dosya: 01_sirali_akis.c
 * Açıklama: Tekli Yürüyen Işık.
 * Mantık:
 * 1. Adım: Sadece 12 yanar, diğerleri söner.
 * 2. Adım: Sadece 13 yanar, 12 söner.
 * 3. Adım: Sadece 14 yanar, 13 söner.
 * 4. Adım: Sadece 15 yanar, 14 söner.
 * ...Sonra başa döner.
 */

// uint16_t pinler[] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};

for (int i = 0; i < 4; i++) {
    HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);   // Sıradaki LED'i YAK
    HAL_Delay(200);
    HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET); // Bir sonrakine geçmeden SÖNDÜR
}
