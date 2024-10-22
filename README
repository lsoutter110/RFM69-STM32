# RFM69-STM32

Port of the RFM69W library provided in the ELEC3221 labs.
Library ported and adapted from previous adaptation by Willow Herring (can be found at https://github.com/ReFil/RFM69-ilmatto).

The library has been stripped back to its core as a RFM69 driver - the user is expected to setup the SPI, CS, and EXTI pins using CubeMX or other methods.
The driver expects this hardware to be set up:
- A SPI handle (set by changing the macro definition `RF_SPI` in `src/rfm69_int.h`)
- A CS pin (GPIO Output) called `RF_CS` (if not using CubeMX then the macros `RF_CS_Pin` and `RF_CS_GPIO_Port` should be defined as the GPIO pin and port in `src/rfm69_int.h`)
- An EXTI channel called `RF_INT` (if not using CubeMX them the macro `RF_INT_EXTI_IRQn`, `RF_INT_Pin`, and `RF_INT_Port` should be defined as the IRQ number of the EXTI channel and GPIO pin and port in `src/rfm69_int.h`)

The driver implements `HAL_GPIO_EXTI_Callback()` - if you need to use this, replace the callback implementation with a function and call it from your own `HAL_GPIO_EXTI_Callback` implementation.
