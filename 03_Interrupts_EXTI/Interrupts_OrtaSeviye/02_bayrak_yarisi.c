/*
 * Dosya: 06_bayrak_yarisi.c
 * Yer: stm32f4xx_it.c -> EXTI0_IRQHandler (PA0 Butonu)
 * Kısım: USER CODE BEGIN 0

 Senaryo: Butona basınca çok uzun süren bir işlem (mesela 5 saniyelik bir animasyon) yapılması gerekiyor. 
 Sorun: Bunu Kesme (Handler) içine yazarsan, 5 saniye boyunca işlemci kilitlenir. Başka hiçbir şeye bakamaz. 
 Çözüm: Kesme sadece "Yapılacak iş var" diye bayrak kaldırır (islem_bayragi = 1). Asıl işi ana döngü yapar.
 */

if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
{
    // Sadece bayrağı kaldır ve çık.
    // "Patron, bir sipariş geldi, müsait olunca hallet" diyoruz.
    islem_bayragi = 1; 
}

/*
 * NOT: Bu kodu test etmek için main.c dosyasındaki while(1) içine şunu yazmalısın:
 * * extern uint8_t islem_bayragi; // Değişkeni tanı
 * if(islem_bayragi == 1) {
 * // Uzun animasyon burada yapılır
 * HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
 * HAL_Delay(1000); 
 * islem_bayragi = 0; // İşi bitirince bayrağı indir
 * }
 */
