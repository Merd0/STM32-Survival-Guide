/*
 * Dosya: 02_kara_simsek.c
 * Açıklama: Git-Gel (Ping-Pong) Efekti.
 * Mantık:
 * - Işık 12 -> 13 -> 14 -> 15 sırasıyla gider.
 * - 15'e gelince sönüp başa dönmez; geri vites yapar.
 * - 15 -> 14 -> 13 -> 12 şeklinde geri döner.
 */

// while(1) dışı:
int i = 0; 
int yon = 1; // 1: İleri (12'den 15'e), -1: Geri (15'ten 12'ye)

// while(1) içi:
HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_SET);
HAL_Delay(100);
HAL_GPIO_WritePin(GPIOD, pinler[i], GPIO_PIN_RESET);

i += yon; // İndeksi yöne göre değiştir

// Köşelere çarpma kontrolü
if (i == 3) yon = -1; // 15'e çarptı, geri dön
if (i == 0) yon = 1;  // 12'ye çarptı, ileri git
