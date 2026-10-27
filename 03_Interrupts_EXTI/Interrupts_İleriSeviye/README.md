# Advanced Interrupt Exercises — Event-Driven Scenarios

**English | [Türkçe](README.tr.md)**

![Focus](https://img.shields.io/badge/focus-event--driven%20logic-blue)
![Scope](https://img.shields.io/badge/scope-educational%20examples-lightgrey)

These exercises go beyond basic GPIO operations to model input sequences, timing, state transitions, and abnormal operating conditions.

Ask questions such as: What happens if a button is held down? Can an application remember that a stop was requested? How should it respond to unexpected input or a too-early restart?

## Scenarios and techniques

| Source | Scenario | Technique |
| --- | --- | --- |
| [01_sanal_encoder.c](01_sanal_encoder.c) | Restrict values such as a volume control or motion command to a permissible range | **Clamping:** limit values to min/max bounds |
| [02_endustriyel_stop.c](02_endustriyel_stop.c) | Avoid automatically resuming an application after a stop event | **Latching:** require an explicit re-arm action |
| [03_kasa_sifresi.c](03_kasa_sifresi.c) | Recognize a specific input sequence, such as A → B → A | **Finite-state machine:** advance on correct inputs, reset on invalid sequences |
| [04_motor_koruma.c](04_motor_koruma.c) | Prevent an immediate restart after shutdown | **Cooldown:** check elapsed time since the last stop |
| [05_paketleme_bandi.c](05_paketleme_bandi.c) | Count products and act after a batch threshold | **Event counting and process control** |
| [06_double_click.c](06_double_click.c) | Distinguish one click from a double-click | **Timing:** compare event intervals |

## What you should learn

1. **State retention:** track previous events using application state, including appropriate `static` variables.
2. **Timing decisions:** avoid blocking delays in ISRs; compare elapsed time using a suitable tick source such as `HAL_GetTick`.
3. **Error handling:** reason about repeated, out-of-order, or unexpected button events.

## Integration note

These snippets target an interrupt-handler-based HAL project. The original examples describe state variables such as:

```c
/* USER CODE BEGIN 0 */
int sistem_modu = 0;       // Genel durum değişkeni
int acil_durum = 0;        // Güvenlik kilidi
/* USER CODE END 0 */
```

Integrate only after checking the generated file layout and state ownership. Shared ISR/foreground state requires careful handling of visibility and atomicity.

> **Safety scope:** These examples **simulate** software control decisions. They are not industrial safety standards, certified emergency stops, verified motor protection, or substitutes for physical safety circuits.

[EXTI overview](../README.md) · [Learning roadmap](../../LEARNING_PATH.md)
