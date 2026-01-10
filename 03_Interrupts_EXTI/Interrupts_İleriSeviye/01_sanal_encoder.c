/*
 * Dosya: 08_sanal_encoder.c
 * Senaryo: PB1 Sesi Arttırır, PA0 Sesi Azaltır. (0 ile 10 arası sınırlandırılmıştır)
 * Değişken: 'sistem_modu' değişkenini ses seviyesi olarak kullanacağız.

 Senaryo: Arabadaki hız sabitleyici (Cruise Control) veya ses düğmesi. 
 Vizyon: "Sınırsız arttırma" diye bir şey yoktur. 
 Yazılım, donanımın sınırlarını korumalıdır (Clamping). 
 Ayrıca kullanıcı butona basılı tutsa bile sistem sapıtmamalıdır.
 */

// --- ARTTIRMA BUTONU (PB1) ---
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    // Sınır Kontrolü (Clamping): Ses 10'dan büyükse arttırma!
    if(sistem_modu < 10) {
        sistem_modu++;
    } else {
        // Kullanıcıya "Sınırdayız" uyarısı (Hızlı çift flash)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        for(volatile int i=0; i<200000; i++);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
        for(volatile int i=0; i<200000; i++);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        for(volatile int i=0; i<200000; i++);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    }
}

// --- AZALTMA BUTONU (PA0) ---
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
{
    // Sınır Kontrolü: Ses 0'dan küçükse azaltma!
    if(sistem_modu > 0) {
        sistem_modu--;
    }
    // Azalınca sadece tek flash yap
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14); 
}
