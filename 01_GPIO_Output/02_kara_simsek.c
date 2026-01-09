/*
 * Dosya: 02_kara_simsek.c
 * Açıklama: Knight Rider (Kara Şimşek) Ping-Pong algoritması.
 * Yazar: Mert
 */

// while(1) dışındaki değişkenler:
int i = 0; 
int yon = 1; // 1: İleri, -1: Geri

// while(1) içi:
HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
HAL_Delay(100);
HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET);

i += yon; // İndeksi yöne göre güncelle

// Sınır kontrolü (Duvara çarpma anı)
if (i == 3) yon = -1; 
if (i == 0) yon = 1;
