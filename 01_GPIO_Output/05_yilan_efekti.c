/*
 * Dosya: 05_yilan_efekti.c
 * Açıklama: Birbirini takip eden 2 LED (Kuyruk mantığı). Modulo aritmetiği içerir.
 * Yazar: Mert
 */

// while(1) dışındaki değişkenler:
int i = 0;

// while(1) içi:
// 1. Sahneyi Temizle
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

// 2. Mevcut ve bir sonrakini yak (Dairesel geçiş için %4)
HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOD, pinler[(i+1)%4], GPIO_PIN_SET);

HAL_Delay(250);
i = (i + 1) % 4;
