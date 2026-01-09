/*
 * Dosya: 02_hedefli_yazdirma.c
 * Açıklama: Butona göre hem sayıyı (Tablodan) hem de Haneyi seçer.
 */

// --- LOOK-UP TABLE ---
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

uint16_t segment_pinleri[] = {GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};

void segmente_yaz(int sayi) {
    for (int i = 0; i < 8; i++) {
        if (rakam_tablosu[sayi][i] == 1) HAL_GPIO_WritePin(GPIOE, segment_pinleri[i], GPIO_PIN_SET);
        else HAL_GPIO_WritePin(GPIOE, segment_pinleri[i], GPIO_PIN_RESET);
    }
}

// --- ANA KOD (while döngüsü içi) ---
while(1) {
    // Önce temizlik: Tüm haneleri kapat, segmentleri temizle
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOE, 0xFF00, GPIO_PIN_RESET); 

    // PA13'e basılınca -> Hane 1'de '5' gör
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == GPIO_PIN_SET) {
        segmente_yaz(5); // Tablodan 5'in desenini al
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET); // Sadece 1. Hane pinini aç
    }
    
    // PA14'e basılınca -> Hane 2'de '8' gör
    else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_14) == GPIO_PIN_SET) {
        segmente_yaz(8); // Tablodan 8'in desenini al
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET); // Sadece 2. Hane pinini aç
    }

    HAL_Delay(5); // Tarama hızı
}
