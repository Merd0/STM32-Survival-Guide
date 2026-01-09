/*
 * Dosya: 01_basit_kontrol.c
 * Açıklama: Butona basınca Look-Up tablosundan '1' desenini çeker ve basar.
 */

// --- LOOK-UP TABLE (KOPYA KAĞIDI) ---
// Satır: Sayı (0-9), Sütun: Segment (A-DP)
// 1 = Yan, 0 = Sön
int rakam_tablosu[10][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1, 0}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 0, 1, 1, 0, 1, 1, 0}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};

// Segment Pinlerinin Dizilimi (Donanımına göre A,B,C...DP)
uint16_t segment_pinleri[] = {
    GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, 
    GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15
};

// TABLOYU OKUYUP PİNLERE BASAN FONKSİYON
void segmente_yaz(int sayi) {
    for (int i = 0; i < 8; i++) {
        // Tabloda o hücre 1 ise pini SET yap, 0 ise RESET yap
        if (rakam_tablosu[sayi][i] == 1)
            HAL_GPIO_WritePin(GPIOE, segment_pinleri[i], GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(GPIOE, segment_pinleri[i], GPIO_PIN_RESET);
    }
}

// --- ANA KOD (while döngüsü içi) ---
// Sadece 1. Haneyi (PE4) aktif et
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

while(1) {
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == GPIO_PIN_SET) {
        segmente_yaz(1); // Tablonun 1. satırını uygula
    } else {
        segmente_yaz(0); // Tablonun 0. satırını uygula
    }
    HAL_Delay(50);
}
