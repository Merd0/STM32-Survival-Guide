/*
 * Dosya: 08_ters_binary.c
 * Açıklama: Negatif Binary Sayıcı.
 * Mantık: Normal sayıcının tam tersidir.
 * - Sayı 0: Hepsi YANAR (1111).
 * - Sayı 1: Sadece 12 SÖNER (1110).
 * - Sayı 15: Hepsi SÖNER (0000).
 */

int sayac = 0;
int ters_sayac = ~sayac; // Bitleri ters çevir (0->1, 1->0)

for (int i = 0; i < 4; i++) {
    if ((ters_sayac >> i) & 1) 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
    else 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET);
}
HAL_Delay(500);
sayac++;
