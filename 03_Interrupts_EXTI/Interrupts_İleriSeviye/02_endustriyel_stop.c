/*
 * Dosya: 09_endustriyel_stop.c
 * Değişken: 'acil_durum' (0: Güvenli, 1: KİLİTLİ)

 Senaryo: Pres makinesi. İşçi elini kaptırınca acil stop'a (PB1) basar. Makine durur. İşçi elini butondan çekse bile makine ASLA çalışmamalıdır. 
 Usta başı gelip "Reset" butonuna (PA0) basana kadar sistem kilitli kalır. 
 Vizyon: Güvenlik yazılımlarında "State Retention" (Durumu Koruma) hayati önem taşır.
 */

// --- ACİL STOP (PB1) ---
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    acil_durum = 1; // KİLİTLE! (Mühürleme)
    
    // Tüm çıkışları (Motorları/LED'leri) anında kes
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_RESET);
    // Kırmızı Alarmı Yak
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
}

// --- SİSTEM RESET (PA0) ---
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
{
    // Sadece Acil Stop butonu basılı DEĞİLSE reset atılabilir.
    // (Donanımsal olarak butonun bırakıldığını kontrol ediyoruz)
    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET) 
    {
        acil_durum = 0; // Kilidi Aç
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET); // Kırmızıyı Söndür
        
        // Sistemin açıldığını belli et (Mavi yak)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
    }
}
