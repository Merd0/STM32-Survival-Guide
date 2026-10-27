# Intermediate Interrupt Patterns — State and Flags

**English | [Türkçe](README.tr.md)**

These examples move beyond simple LED toggling to application **state management** and **flag-based handoff**.

The essential principle: keep interrupt service routines short. Record an event or change a small state, then carry out longer operations in the foreground loop where appropriate.

## Example state variables

The original examples use the following declarations. Adapt ownership, placement, and concurrency semantics to your generated application rather than copying blindly.

```c
/* USER CODE BEGIN 0 */
// Bu değişkenleri stm32f4xx_it.c dosyasının EN TEPESİNE yapıştırın

int sistem_modu = 0;       // 0:Kapalı, 1:Yavaş, 2:Hızlı, 3:Sabit
int acil_durum = 0;        // 0:Her şey yolunda, 1:PANİK!
uint8_t islem_bayragi = 0; // Main döngüsüne haber uçurmak için (Flag)

/* USER CODE END 0 */
```

The identifiers mean, respectively, the current system mode, an emergency-state flag, and a flag used to notify the main loop.

> **Concurrency note:** If a variable is shared between an ISR and foreground code, select the appropriate visibility, atomicity, and synchronization strategy. The snippet alone does not guarantee race-free access; `volatile` is not a substitute for atomic operations.

## Examples

| Source | Learning goal |
| --- | --- |
| [01_mod_degistirici.c](01_mod_degistirici.c) | Update modes through an interrupt-driven state machine |
| [02_bayrak_yarisi.c](02_bayrak_yarisi.c) | Signal the main loop with a flag and defer longer work |
| [03_acil_durum_freni.c](03_acil_durum_freni.c) | Model an application-level latched-stop condition |

The emergency-stop example illustrates state logic. It is **not** a certified machine safety function or replacement for hardware safety mechanisms.

[EXTI overview](../README.md) · [Learning roadmap](../../LEARNING_PATH.md)
