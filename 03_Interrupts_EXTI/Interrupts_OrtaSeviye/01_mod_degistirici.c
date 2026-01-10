/*
 * Dosya: 05_mod_degistirici.c
 * Yer: stm32f4xx_it.c -> EXTI1_IRQHandler (PB1 Butonu)
 * Kısım: USER CODE BEGIN 0

 Senaryo: Butona her bastığında sistemin modu değişsin.

Bas -> Mod 1 (Yavaş Yan Sön)

Bas -> Mod 2 (Hızlı Yan Sön)

Bas -> Mod 3 (Sürekli Yan)

Bas -> Mod 0 (Kapat) Öğretilen: State Machine (Durum Makinesi) mantığının kesme ile kontrolü.
 */

if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    // 1. Modu Arttır
    sistem_modu++;
    
    // 2. Eğer 3'ü geçerse başa sar (0-1-2-3 -> 0-1-2-3...)
    if(sistem_modu > 3) sistem_modu = 0;

    // 3. Görsel Geri Bildirim (Kullanıcı bastığını anlasın diye minik bir flash)
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    for(volatile int i=0; i<500000; i++); // Çok kısa bekleme
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    
    // NOT: Asıl yanıp sönme işini main.c içindeki while(1) yapacak.
    // Kesme sadece "sistem_modu" değişkenini değiştirdi ve kaçtı.
}
