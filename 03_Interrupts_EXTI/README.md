# Module 3 — External Interrupts and NVIC (STM32CubeMX)

**English | [Türkçe](README.tr.md)**

This module explains how to configure **EXTI interrupts and NVIC priorities in STM32CubeMX** and integrate handler logic in `stm32f4xx_it.c`.

## Working with Cube-generated code

- Add example logic only to the appropriate `/* USER CODE BEGIN ... */` / `/* USER CODE END ... */` regions of the generated `EXTIx_IRQHandler`, following the generated file's actual layout.
- Do **not** remove the generated `HAL_GPIO_EXTI_IRQHandler(...)` call. The HAL handler processes/clears the EXTI pending event and dispatches callbacks according to the HAL configuration.
- Verify the exact generated user-code markers and placement for your STM32Cube/HAL version before pasting a snippet.

## NVIC setup in CubeMX

1. Open **System Core → NVIC**.
2. Enable the relevant `EXTI Line0`, `EXTI Line1`, or other interrupt line for your GPIO configuration.
3. Set **Preemption Priority** (lower numeric priority values represent higher priority, within the configured priority grouping).

## Examples

| Source | Concept |
| --- | --- |
| [01_temel_kesme.c](01_temel_kesme.c) | Toggle an LED with a PB1 button; HAL handles the pending interrupt |
| [02_debounce_cozumu.c](02_debounce_cozumu.c) | Use `HAL_GetTick` to reject button bounce |
| [03_oncelik_savasi_preemption.c](03_oncelik_savasi_preemption.c) | Observe a higher-priority PB1 event preempting the PA0 handler |
| [04_esit_oncelik_subpriority.c](04_esit_oncelik_subpriority.c) | Explore equal-preemption-priority behavior and subpriority ordering |

**Important:** Preserve the generated HAL call and use the appropriate Cube-generated user-code section. This is educational integration guidance, not a guarantee that a snippet can be pasted into every STM32Cube version without adaptation.

[Learning roadmap](../LEARNING_PATH.md) · [Türkçe](README.tr.md)
