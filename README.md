# STM32 Survival Guide — GPIO, Interrupts & Timers

**English | [Türkçe](README.tr.md)** · **[Learning Roadmap](LEARNING_PATH.md) | [Türkçe Öğrenme Yolu](LEARNING_PATH.tr.md)**

![Language](https://img.shields.io/badge/language-Embedded%20C-00599C)
![Platform](https://img.shields.io/badge/target-STM32F4-orange)
![Scope](https://img.shields.io/badge/scope-educational%20examples-blue)

A hands-on collection of **STM32F4 / HAL-style C examples**, moving from GPIO output and input to external interrupts, NVIC priorities, timer interrupts, state machines, and embedded application patterns.

The repository provides example snippets and explanations for learning. It is **not** a turnkey STM32CubeIDE project, a hardware-validated product, or a functional-safety-certified control system.

## Start learning

Choose your documentation language:

- [English learning roadmap](LEARNING_PATH.md) — recommended progression, prerequisites, and module links.
- [Türkçe öğrenme yolu](LEARNING_PATH.tr.md) — aynı konuların Türkçe çalışma sırası.

Use the corresponding module README for CubeMX configuration and contextual explanations. Code filenames and HAL identifiers remain unchanged.

## Example target hardware

The documented examples use an **STM32F4-series target** and a four-digit seven-segment display with these assumed connections. Verify against your actual board and CubeMX configuration.

| Component | Pins | Purpose |
| --- | --- | --- |
| Onboard LEDs | `GPIOD` pins 12–15 | Four LED outputs |
| Buttons / triggers | `GPIOA` pin 0; `GPIOE` inputs | Digital input |
| Seven-segment digit select | `GPIOE` pins 4–7 | Multiplexed digit enable |
| Seven-segment segment data | `GPIOE` pins 8–15 | A–G and decimal point |

## Example catalog

### Module 1 — GPIO Output

| Example | What it teaches |
| --- | --- |
| [Sequential LED pattern](01_GPIO_Output/01_sirali_akis.c) | Loops, GPIO sequencing, and HAL delays |
| [Bidirectional scan](01_GPIO_Output/02_kara_simsek.c) | Left/right LED scanning using bit shifts |
| [Binary counter](01_GPIO_Output/03_binary_counter.c) | Display values 0–15 with four LEDs |
| [Alternating flasher](01_GPIO_Output/04_polis_cakari.c) | Alternating groups of LEDs |
| [Circular LED pattern](01_GPIO_Output/05_yilan_efekti.c) | Modulo arithmetic and wraparound |
| [Custom LED pattern](01_GPIO_Output/06_ozel_desen.c) | Array-driven output sequences |
| [Progress bar](01_GPIO_Output/07_yukleme_cubugu.c) | Accumulative LED activation |
| [Inverted binary](01_GPIO_Output/08_ters_binary.c) | Bitwise NOT and active-low logic |
| [Fading LED trail](01_GPIO_Output/09_hayalet_iz.c) | Software PWM and decay concepts |

### Module 2 — GPIO Input

| Example | What it teaches |
| --- | --- |
| [Basic input](02_GPIO_Input/01_basit_kontrol.c) | Reading a button to control an LED |
| [Selective display](02_GPIO_Input/02_hedefli_yazdirma.c) | Drive a specific seven-segment digit |
| [Button counter](02_GPIO_Input/03_butonlu_sayac.c) | Button-triggered increment with display multiplexing |
| [Doorbell](02_GPIO_Input/04_kapi_zili_basitD%C3%BCzey.c) | Level-sensitive push-button logic |
| [Toggle lamp](02_GPIO_Input/05_akilli_lamba_basitD%C3%BCzey.c) | Remember on/off state between presses |
| [Gear selector](02_GPIO_Input/05_vites_kutusu_basitD%C3%BCzey.c) | Switch-case state transitions |
| [Two-button interlock](02_GPIO_Input/07_guvenlik_kilidi_basitD%C3%BCzey.c) | Boolean AND-based control example |
| [Reaction exercise](02_GPIO_Input/08_refleks_testi_basitD%C3%BCzey.c) | Basic response logic without HAL_GetTick |

### Module 3 — External Interrupts and NVIC

| Example | What it teaches |
| --- | --- |
| [Basic EXTI](03_Interrupts_EXTI/01_temel_kesme.c) | Handle external input using the HAL callback |
| [Debouncing](03_Interrupts_EXTI/02_debounce_cozumu.c) | Use HAL_GetTick to reject rapid button transitions |
| [Preemption priorities](03_Interrupts_EXTI/03_oncelik_savasi_preemption.c) | Compare interrupt priority behavior |
| [Subpriority](03_Interrupts_EXTI/04_esit_oncelik_subpriority.c) | Explore equal preemption priority and ordering |
| [Mode switch](03_Interrupts_EXTI/Interrupts_OrtaSeviye/01_mod_degistirici.c) | Update system state on an interrupt |
| [Flag handoff](03_Interrupts_EXTI/Interrupts_OrtaSeviye/02_bayrak_yarisi.c) | Defer work to the main loop |
| [Emergency-stop logic example](03_Interrupts_EXTI/Interrupts_OrtaSeviye/03_acil_durum_freni.c) | Latched application state (not a certified safety circuit) |
| [Virtual encoder](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/01_sanal_encoder.c) | Input interpretation and bounds |
| [Latched stop](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/02_endustriyel_stop.c) | Require an explicit re-arm step |
| [Sequence lock](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/03_kasa_sifresi.c) | State-machine input sequence |
| [Restart delay](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/04_motor_koruma.c) | Cooldown time after shutdown |
| [Batch counter](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/05_paketleme_bandi.c) | Count items until a threshold |
| [Double-click detector](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/06_double_click.c) | Classify button events by time interval |

### Module 4 — Timer and State-Machine Applications

| Example | What it teaches |
| --- | --- |
| [Minute/second stopwatch](04_Timer_Interrupt_Header_Stopwatch/01_dk_sn_kronometre) | Interrupt-based timekeeping and display multiplexing |
| [Reaction timer](04_Timer_Interrupt_Header_Stopwatch/02_Reaction_Timer) | Button response time exercise |
| [Traffic-light state machine](04_Timer_Interrupt_Header_Stopwatch/03_Ak%C4%B1ll%C4%B1_Trafik_I%C5%9F%C4%B1%C4%9F%C4%B1_%28FSM%29) | Pedestrian button and timed states |
| [Simon Says memory game](04_Timer_Interrupt_Header_Stopwatch/04_Simon_Says_%28Haf%C4%B1za%20Oyunu%29) | LED pattern memory |
| [Breathing LED](04_Timer_Interrupt_Header_Stopwatch/05_Nefes_Alan_I%C5%9F%C4%B1k_%28Breathing%20LED%29) | PWM-like duty-cycle variation |
| [Parking sensor simulation](04_Timer_Interrupt_Header_Stopwatch/06_Park_Sens%C3%B6r%C3%BC_Sim%C3%BClasyonu) | Distance to buzzer rate mapping |
| [Pomodoro timer](04_Timer_Interrupt_Header_Stopwatch/07_Pomodoro_Zamanlay%C4%B1c%C4%B1) | 25-minute countdown |
| [Morse encoder](04_Timer_Interrupt_Header_Stopwatch/08_Mors_Alfabesi_%C3%87evirici) | Text to light pulses |
| [Digital die](04_Timer_Interrupt_Header_Stopwatch/09_Dijital_Zar_%28Rastgele%20Say%C4%B1%29) | Button-triggered changing display |
| [One-button menu](04_Timer_Interrupt_Header_Stopwatch/10_Butonla_Men%C3%BC_Kontrol%C3%BC) | Cycle through UI states |
| [Up/down counter](04_Timer_Interrupt_Header_Stopwatch/11_%C3%87ift_Y%C3%B6nl%C3%BC_Say%C4%B1c%C4%B1_%28Up_Down_Counter%29) | Bounded arithmetic and edge cases |

## Interrupt-focused lesson notes

For the interrupt modules, follow the accompanying documentation:

- [EXTI and NVIC](03_Interrupts_EXTI/README.md) — setup and handlers.
- [Intermediate interrupt patterns](03_Interrupts_EXTI/Interrupts_OrtaSeviye/README.md) — state and flag handoff.
- [Advanced scenarios](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/README.md) — event-driven application logic.
- [Timer applications](04_Timer_Interrupt_Header_Stopwatch/README.md) — stopwatch and timer-based patterns.

Each module also provides a `README.tr.md` for Turkish readers.

## Shared helper files

The timer-oriented examples describe:

1. `bizimKutuphane.h` — seven-segment multiplexing and digit extraction.
2. `stm32f4xx_it.c` — example interrupt handler logic.
3. `main.c` — foreground display scanning and application logic.

These latter files may appear as sections/snippets rather than standalone repository files; integrate them into a correctly generated STM32Cube project.

## Critical timer setup reminder

Configuring timer parameters (prescaler and period) in STM32CubeMX does **not** start the timer interrupt automatically. The appropriate startup code must call, for example:

```c
HAL_TIM_Base_Start_IT(&htim1); // Adapt the timer handle to your actual configuration
```

Place the call in the appropriate Cube-generated user-code region. Check clock, NVIC, GPIO mappings, and HAL initialization before running on hardware.

## Scope and safety

The emergency-stop, motor-protection, and industrial scenarios are **educational software logic examples**. They do not replace physical interlocks, certified safety functions, or a verified industrial safety design. Hardware behavior, timing, and interrupt priorities depend on the actual MCU and CubeMX configuration.

**Maintainer:** Merd0

[Start the learning path](LEARNING_PATH.md) · [Türkçe README](README.tr.md)
