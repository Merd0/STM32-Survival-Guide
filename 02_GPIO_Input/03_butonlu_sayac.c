/*
 * Dosya: 03_butonlu_sayac.c
 * Açıklama: Sayaç değeri parçalanır ve Look-Up tablosu kullanılarak taranır.
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
uint16_t hane_pinleri[] = {GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7};

void segmente_yaz(int sayi) {
    for (int i = 0; i < 8; i++) {
        if (rakam_tablosu[sayi][i] == 1) HAL_GPIO_WritePin(GPIOE, segment_pinleri[i], GPIO_PIN_SET);
        else HAL_GPIO_WritePin(GPIOE, segment_pinleri[i], GPIO_PIN_RESET);
    }
}

// Değişkenler
int sayac = 0;
int buton_daha_once_basili_miydi = 0; 
int basamaklar[4];

// --- ANA KOD (while döngüsü içi) ---
while(1) {
    // 1. BUTON OKUMA (Logic)
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == GPIO_PIN_SET) {
        if (buton_daha_once_basili_miydi == 0) {
            sayac++; 
            if(sayac > 9999) sayac = 0;
            buton_daha_once_basili_miydi = 1;
        }
    } else {
        buton_daha_once_basili_miydi = 0; 
    }

    // 2. SAYIYI PARÇALA
    basamaklar[0] = sayac / 1000;
    basamaklar[1] = (sayac % 1000) / 100;
    basamaklar[2] = (sayac % 100) / 10;
    basamaklar[3] = sayac % 10;

    // 3. EKRANI TARA (Multiplexing)
    for(int i=0; i<4; i++) {
        // a) Tüm haneleri kapat
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
        
        // b) Tablodan deseni al ve pinlere yaz
        segmente_yaz(basamaklar[i]); 

        // c) İlgili haneyi aç
        HAL_GPIO_WritePin(GPIOE, hane_pinleri[i], GPIO_PIN_SET);

        // d) Göz yanılması için bekle
        HAL_Delay(3); 
    }
}
