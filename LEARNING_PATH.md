# STM32 Survival Guide — Learning Roadmap

**English | [Türkçe](LEARNING_PATH.tr.md)**

This is a progressive learning path through the existing source examples. The C files are shared across languages; English/Turkish documentation provides the explanations.

| Stage | Topics | Suggested outcome |
| --- | --- | --- |
| **0 — Prepare** | STM32CubeMX, CubeIDE, STM32F4 HAL, GPIO setup | Configure pins and identify generated user-code regions |
| **1 — GPIO Output** | Sequencing, bitwise patterns, arrays, simple software PWM | Explain and modify LED output patterns |
| **2 — GPIO Input** | Button reads, toggles, state transitions, multiplexing | Build deterministic input-controlled behavior |
| **3 — EXTI Fundamentals** | External IRQs, NVIC, priority, debouncing | Configure EXTI and observe interrupt dispatch |
| **4 — Interrupt Design** | ISR flag handoff, state machines, latched conditions | Separate short ISR work from main-loop processing |
| **5 — Event Scenarios** | Encoder-like inputs, cool-down, batch counts, double-click | Reason about state, timing, and abnormal inputs |
| **6 — Timers** | Timer IRQs, multiplexing, stopwatch, traffic FSM, PWM-like effects | Build non-blocking, timer-driven logic |

## Module-by-module

1. [GPIO Output](README.md#module-1--gpio-output) — sequential LEDs, binary counters, patterns.
2. [GPIO Input](README.md#module-2--gpio-input) — buttons, stateful toggles, counters.
3. [EXTI / NVIC](03_Interrupts_EXTI/README.md) — basic setup and interrupt prioritization.
4. [Intermediate interrupts](03_Interrupts_EXTI/Interrupts_OrtaSeviye/README.md) — state flags, deferring work to the foreground.
5. [Advanced interrupts](03_Interrupts_EXTI/Interrupts_%C4%B0leriSeviye/README.md) — application-level event-driven exercises.
6. [Timer applications](04_Timer_Interrupt_Header_Stopwatch/README.md) — timed display, stopwatch, state-machine applications.

## Suggested practice routine

For each example, understand the GPIO/IRQ/timer configuration, predict the behavior, integrate the snippet into a Cube-generated project, run on a suitable board when available, and record the observation. Change one detail at a time and compare with the prediction.

**Limitations:** These examples are not documented as having passed a uniform automated hardware test suite. Do not treat safety-related application logic as certified safety protection.

[Repository overview](README.md) · [Türkçe öğrenme yolu](LEARNING_PATH.tr.md)
