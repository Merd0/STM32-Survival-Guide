/*
 * Senaryo: Mod değiştirici. Her basışta sonraki LED.
 Mantık: Arabadaki vites gibi. Butona her bastığında bir sonraki LED yansın.
 Yeşil -> Turuncu -> Kırmızı -> Mavi -> Başa dön. Öğrenilen: Sayaç arttırma ve Switch-Case yapısı.
 */

int vites = 1;
int buton_eski = 0;

while (1) {
    int buton_yeni = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

    // Sadece basma anını yakala (Rising Edge)
    if (buton_yeni == GPIO_PIN_SET && buton_eski == GPIO_PIN_RESET) {
        vites++;
        if (vites > 4) vites = 1; // 4'ten sonra 1'e sar
    }
    buton_eski = buton_yeni;

    // Tüm LED'leri söndür (Temizlik)
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

    // Vitese göre LED yak
    switch (vites) {
        case 1: HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); break; // Yeşil
        case 2: HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); break; // Turuncu
        case 3: HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); break; // Kırmızı
        case 4: HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET); break; // Mavi
    }
    
    HAL_Delay(10);
}
