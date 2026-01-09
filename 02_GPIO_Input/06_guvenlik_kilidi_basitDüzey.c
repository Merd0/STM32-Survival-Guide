/*
 * Senaryo: Güvenlik sistemi. İki elinle de butona basman lazım.
 * Buton 1: PA0
 * Buton 2: PA1 (Veya başka bir pin)
 * LED: PD14 (Kırmızı - Tehlike)

 Mantık: Filmlerde olur ya, iki asker aynı anda anahtarı çevirmeden füze ateşlenmez. 
 Burada da iki butona (PA0 ve PA1) aynı anda basmadan Kırmızı LED yanmayacak. Öğrenilen: && (VE) operatörü.
 */

while (1) {
    // İkisini de oku
    int btn1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
    int btn2 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);

    // İkisi de 1 ise çalış
    if (btn1 == GPIO_PIN_SET && btn2 == GPIO_PIN_SET) {
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET); // Kırmızı YAN
    } else {
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); // Kırmızı SÖN
    }
}
