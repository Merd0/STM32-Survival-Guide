/*
 * Dosya: 03_binary_counter.c
 * Açıklama: 4-Bit Binary Sayıcı (0-15 arası).
 * Mantık:
 * - Sayı 0: Hepsi sönük (0000)
 * - Sayı 1: Sadece 12 yanar (0001)
 * - Sayı 3: 12 ve 13 yanar (0011)
 * - Sayı 15: Hepsi yanar (1111)
 */

int sayac = 0;

// Döngü her döndüğünde sayacı 1 arttırır
for (int i = 0; i < 4; i++) {
    // Sayacın o anki bitine bak: 1 ise YAK, 0 ise SÖNDÜR
    if ((sayac >> i) & 1) 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
    else 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET);
}
HAL_Delay(500);
sayac++;
if (sayac > 15) sayac = 0; // 15'ten sonra sıfırla
