/*
 * Dosya: 07_yukleme_cubugu.c
 * Açıklama: Loading Bar (Yükleme Çubuğu).
 * Mantık:
 * 1. Adım: 12 yanar.
 * 2. Adım: 12 sönmeden 13 de yanar (12+13 yanık).
 * 3. Adım: 14 de eklenir (12+13+14 yanık).
 * 4. Adım: Hepsi yanar (Full dolu).
 * Sonuç: Hepsi birden söner ve başa döner.
 */

// Doldurma Fazı (Sırayla yak ama söndürme)
for (int i = 0; i < 4; i++) {
    HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
    HAL_Delay(250);
}

// Boşaltma Fazı (Hepsini tek seferde söndür)
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
HAL_Delay(500);
