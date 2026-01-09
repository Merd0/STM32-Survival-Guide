/*
 * Dosya: 08_ters_binary.c
 * Açıklama: Binary sayıcının negatifi (Bitwise NOT ~ işlemi).
 * Yazar: Mert
 */

// while(1) dışındaki değişkenler:
int sayac = 0;

// while(1) içi:
int ters_sayac = ~sayac; // Tüm bitleri tersle (0->1, 1->0)

for (int i = 0; i < 4; i++) {
    if ((ters_sayac >> i) & 1) 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
    else 
        HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET);
}
HAL_Delay(500);
sayac++;
