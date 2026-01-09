/*
 * Senaryo: Kırmızı LED yanınca butona bas!
 * Yeşil yanarsa kazandın, Mavi yanarsa (erken bastın) kaybettin.
 Mantık: Bu biraz eğlenceli. LED aniden yanacak, sen yanınca butona basmalısın. 
 Yanmadan basarsan veya geç basarsan kaybedersin. Öğrenilen: while döngüsü içinde bekletme (Blocking logic).
 */

while (1) {
    // 1. Oyun Başlıyor: Her şey sönük
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
    HAL_Delay(2000); // 2 saniye bekle (Gerilim müziği...)

    // 2. Kırmızı LED (PD14) yansın (HEDEF!)
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);

    // 3. Kullanıcının basmasını bekle (Sonsuz döngü)
    // Kırmızı yanar yanmaz süre saymaya başlarız aslında ama burada basit tutalım.
    while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) {
        // Butona basılana kadar burada takılı kalır.
    }

    // 4. Butona basıldı! Kırmızıyı söndür.
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);

    // Kazandın efekti (Yeşil yanıp sönsün)
    for(int i=0; i<3; i++) {
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        HAL_Delay(100);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_Delay(100);
    }
}
