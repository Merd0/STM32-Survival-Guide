/*
 * Dosya: 04_polis_cakari.c
 * Açıklama: Sağlı Sollu Çakar Lamba.
 * Mantık:
 * 1. Faz: Sol taraf (12 ve 13) 3 kere hızlıca yanıp söner.
 * 2. Faz: Sağ taraf (14 ve 15) 3 kere hızlıca yanıp söner.
 * Bu işlem sürekli tekrar eder.
 */

// Grup 1: Sol Taraf (12 ve 13)
for(int k=0; k<3; k++) {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13, GPIO_PIN_SET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_Delay(50);
}
// Grup 2: Sağ Taraf (14 ve 15)
for(int k=0; k<3; k++) {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
    HAL_Delay(50);
}
