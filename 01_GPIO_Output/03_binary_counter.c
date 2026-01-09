/*
 * Dosya: 03_binary_counter.c
 * Açıklama: 4-Bit Binary (İkili) Sayıcı. Bitwise Shift kullanır.
 * Yazar: Mert
 */

// while(1) dışındaki değişkenler:
int sayac = 0;

// while(1) içi:
for (int i = 0; i < 4; i++) {
    // Sayacın i. bitini kontrol et (Maskeleme)
    if ((sayac >> i) & 1) 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
    else 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET);
}
HAL_Delay(500);
sayac++;
if (sayac > 15) sayac = 0; // 4 bitlik sınır
