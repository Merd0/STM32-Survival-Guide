# STM32 Timer Interrupts — Stopwatch and Embedded Algorithms

**English | [Türkçe](README.tr.md)**

This module brings together a **timer-interrupt-driven minute/second stopwatch** and additional embedded algorithm exercises focused on non-blocking timing, multiplexing, and state machines.

## Main project — minute/second stopwatch

Relevant example: `01_dk_sn_kronometre`.

The goal is to keep time without blocking the foreground loop with software delays.

- **Timer interrupts:** a configured hardware timer such as TIM1 periodically updates the timekeeping state.
- **Display multiplexing:** scan four seven-segment digits rapidly enough for a continuous display.
- **Cascade logic:** carry from seconds to minutes as the count advances.

The actual timing resolution and precision depend on clock configuration, prescaler, timer period, interrupt latency, and hardware measurement; no independent timing-accuracy guarantee is implied.

### Hardware mapping assumed by the examples

- **MCU:** STM32F4 family.
- **Display:** four-digit seven-segment display.
- **Segments A–G and DP:** `PE8–PE15`.
- **Digit select:** minute tens `PE4`, minute ones `PE5`, second tens `PE6`, second ones `PE7`.

## Additional exercises

| Example | Application | Concept |
| --- | --- | --- |
| `01_dk_sn_kronometre` | Minute/second stopwatch | Timer IRQs, multiplexing, carry logic |
| `02_Reaction_Timer` | Reaction timer | Event timing |
| `03_Akıllı_Trafik_Işığı_(FSM)` | Traffic light and pedestrian button | Finite-state machines |
| `04_Simon_Says_(Hafıza Oyunu)` | Simon Says memory sequence | Arrays and state |
| `05_Nefes_Alan_Işık_(Breathing LED)` | Gradually varying LED brightness | PWM-style duty-cycle logic |
| `06_Park_Sensörü_Simülasyonu` | Parking proximity alert | Mapping distance to alert rate |
| `07_Pomodoro_Zamanlayıcı` | Twenty-five-minute countdown | Flags and countdown logic |
| `08_Mors_Alfabesi_Çevirici` | Morse-code light signals | String processing and signaling |
| `09_Dijital_Zar_(Rastgele Sayı)` | Button-controlled digital die | Display state and modulo logic |
| `10_Butonla_Menü_Kontrolü` | One-button menu | State changes |
| `11_Çift_Yönlü_Sayıcı_(Up_Down_Counter)` | Bounded up/down counter | Edge cases and overflow avoidance |

## Software structure

The examples describe three cooperating components:

1. `bizimKutuphane.h`: seven-segment multiplexing and digit extraction helpers.
2. `stm32f4xx_it.c`: an interrupt handler updating shared timing state.
3. `main.c`: foreground display scanning and application logic.

The latter two may be shown as snippets within the repository. Adapt them to the generated STM32 HAL project layout.

**Timing reminder:** Configure the timer and NVIC in CubeMX **and** start the timer in the user-code startup path, for example with `HAL_TIM_Base_Start_IT(&htim1)` using the timer handle relevant to your project.

[Learning roadmap](../LEARNING_PATH.md) · [Türkçe](README.tr.md)
