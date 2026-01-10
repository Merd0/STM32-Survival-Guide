/*
 * Dosya: 11_motor_koruma.c
 * Senaryo: PB1 (Motor Start)
 * Vizyon: Donanım dostu yazılım (Cool-Down Logic)

 Vizyon: Gerçek hayatta devasa motorları veya ısıtıcıları "Aç-Kapa-Aç-Kapa" yapamazsın. Motor yanar veya şebekeyi çökertir. 
 Yazılım, operatör butona bassa bile donanımı korumalı ve "Henüz hazır değilim" demelidir.
 Mantık: Sistem kapandıktan sonra tekrar açılmak için en az 3 saniye (veya 3000 ms) beklemelidir.
 */

// Bu değişken son kapanma zamanını tutar (Static = Hafıza)
static uint32_t son_kapanma_zamani = 0;
// Motorun çalışıp çalışmadığını takip et
static uint8_t motor_aktif = 0;

if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET)
{
    uint32_t su_an = HAL_GetTick();

    // 1. Durum: Motor zaten çalışıyorsa -> DURDUR
    if(motor_aktif == 1) {
        motor_aktif = 0;
        son_kapanma_zamani = su_an; // Ne zaman durduğunu not et!
        
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); // Motoru (Yeşil) Kes
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);   // Kırmızı (Durdu)
    }
    // 2. Durum: Motor duruyorsa -> ÇALIŞTIRMAYI DENE
    else {
        // KORUMA MANTIĞI: Son kapanmadan bu yana 3 saniye geçti mi?
        if((su_an - son_kapanma_zamani) > 3000) 
        {
            motor_aktif = 1;
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); // Motoru Başlat
        }
        else 
        {
            // HATA: Operator sabırsız! Ona beklemesini söyle (Turuncu flaş yap)
            for(int i=0; i<3; i++){
                HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
                for(volatile int k=0; k<200000; k++);
            }
        }
    }
}
