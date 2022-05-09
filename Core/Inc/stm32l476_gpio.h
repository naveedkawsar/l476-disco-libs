/*
 * stm32l476rg_gpio.h
 *
 *  Created on: May 9, 2022
 *      Author: lenovo-t15-g2
 */

#ifndef INC_STM32L476_GPIO_H_
#define INC_STM32L476_GPIO_H_

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    NO_PULL = 0u,
    PULL_UP,
    PULL_DOWN,
} GpioPullDir;

void stm32_configure_port_a_pin_as_input(uint32_t pin_num, GpioPullDir pull);
bool stm32_port_a_in_pin_set(uint32_t pin_num);
void stm32_configure_port_b_pin_as_output(uint32_t pin_num);
void stm32_port_b_out_pin_set(uint32_t pin_num);
void stm32_port_b_out_pin_clear(uint32_t pin_num);
void stm32_port_b_out_pin_toggle(uint32_t pin_num);
void stm32_configure_port_e_pin_as_output(uint32_t pin_num);
void stm32_port_e_out_pin_set(uint32_t pin_num);
void stm32_port_e_out_pin_clear(uint32_t pin_num);
void stm32_port_e_out_pin_toggle(uint32_t pin_num);

#endif /* INC_STM32L476_GPIO_H_ */
