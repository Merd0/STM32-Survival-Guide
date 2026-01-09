/*
 * Senaryo: Bas-Çek yapınca durum değiştiren lamba.
 * Sorun: İşlemci çok hızlı. Sen butona "bip" diye basana kadar o 1000 kere okur.
 * Çözüm: "Elimi butondan çektim mi?" kontrolü yapmak.

 Mantık: Bu çok kritiktir. Kapı zili gibi değil, evdeki lamba anahtarı gibi olsun istiyoruz. Bir kere basıp çekeceğim, lamba yanık kalacak. Bir daha basıp çekeceğim, sönecek. Öğrenilen: "Eski Durum" (Previous State) kontrolü ve Flag (Bayrak) mantığı.
 */

int lamba_durumu = 0; // 0: Kapalı, 1: Açık
int buton_eski_durum = 0; // Butonun bir önceki hali

while (1) {
    int buton_yeni_durum = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

    // MANTIK: Butona ŞİMDİ basıldı (1) VE eskiden basılı değildi (0)
    // Yani "Yükselen Kenar" (Rising Edge) yakalıyoruz.
    if (buton_yeni_durum == GPIO_PIN_SET && buton_eski_durum == GPIO_PIN_RESET) {
        
        // Lambanın durumunu tersine çevir (Toggle)
        if (lamba_durumu == 0) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
            lamba_durumu = 1;
        } else {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
            lamba_durumu = 0;
        }
    }

    // Döngü bitmeden şimdiki durumu hafızaya at
    buton_eski_durum = buton_yeni_durum;
    
    HAL_Delay(10); // Ark (bounce) engellemek için minik bekleme
}
