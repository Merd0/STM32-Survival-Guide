/*
 * Dosya: 12_paketleme_bandi.c
 * Senaryo: PA0 (Sensör her ürünü algıladığında tetiklenir)
 * Hedef: Her 6 üründe bir "Mavi Işık" yak (Koli doldu sinyali)

 Vizyon: Bir üretim bandı düşün. Şişeler geçiyor. 
 Sensör her şişeyi sayar. 6 şişe (1 koli) olunca sistem otomatik olarak "Koli Doldu" sinyali vermeli ve sayacı sıfırlayıp yeni koliye geçmelidir.
 Mantık: Modulo (Kalanlı bölme) mantığı değil, Threshold (Eşik) ve Reset mantığı.
 */

static int urun_sayaci = 0;
#define KOLI_KAPASITESI 6

if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
{
    urun_sayaci++; // Ürün geçti

    // Her ürün geçişinde Turuncu LED anlık yansın (Sensör aktif)
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    for(volatile int i=0; i<100000; i++);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);

    // Koli Doldu mu?
    if(urun_sayaci >= KOLI_KAPASITESI) {
        
        // Operatöre veya Robot Kola haber ver: "Koli Hazır!"
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET); // Mavi Yak
        
        // Robot kol koliyi alana kadar bekle (Simülasyon)
        for(volatile int k=0; k<5000000; k++); 
        
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET); // Mavi Sön
        
        urun_sayaci = 0; // Yeni koli için sayacı sıfırla
    }
}
