/*
 * Dosya: 06_ozel_desen.c
 * Açıklama: Look-Up Table (Dizi) kullanarak karmaşık desen oynatma.
 * Yazar: Mert
 */

// Desen Dizisi (0:Pin12, 1:Pin13, 2:Pin14, 3:Pin15)
int desen[] = {0, 3, 0, 2, 1, 3, 1, 0}; 
int uzunluk = 8;

for (int k = 0; k < uzunluk; k++) {
    int hedef = desen[k];
    HAL_GPIO_WritePin(GPIOD, pinler[hedef], GPIO_PIN_SET);
    HAL_Delay(200);
    HAL_GPIO_WritePin(GPIOD, pinler[hedef], GPIO_PIN_RESET);
}
