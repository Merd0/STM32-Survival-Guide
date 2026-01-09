/*
 * Dosya: 05_yilan_efekti.c
 * Açıklama: Kuyruklu Takip (Yılan).
 * Mantık: Aynı anda 2 LED yanar ve kayar.
 * 1. Adım: 12 ve 13 yanık.
 * 2. Adım: 13 ve 14 yanık.
 * 3. Adım: 14 ve 15 yanık.
 * 4. Adım: 15 ve 12 yanık (Dairesel geçiş).
 */

int i = 0;
// Temizlik (Önce hepsini söndür)
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

// Şu anki (i) ve bir sonraki (i+1) LED'i yak
HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOD, pinler[(i+1)%4], GPIO_PIN_SET);

HAL_Delay(250);
i = (i + 1) % 4; // İndeksi arttır, 4 olunca 0 yap
