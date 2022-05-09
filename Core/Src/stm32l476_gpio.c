/*
 * stm32l476rg_gpio.c
 *
 *  Created on: May 7, 2022
 *      Author: lenovo-t15-g2
 */

#include <stm32l476_gpio.h>
#include "stm32l476xx.h"

#define MAX_PINS_PER_PORT (16u)

bool stm32_input_gpio_is_set(GPIO_TypeDef *gpio, uint32_t pin_num)
{
    bool set = false;
    if (pin_num < MAX_PINS_PER_PORT) {
            set = (gpio->IDR & (1u << pin_num));
        }
    return set;
}

void stm32_output_gpio_set(GPIO_TypeDef *gpio, uint32_t pin_num)
{
    if (pin_num < MAX_PINS_PER_PORT) {
        gpio->BSRR |= (1u << pin_num);
    }
}

void stm32_output_gpio_clear(GPIO_TypeDef *gpio, uint32_t pin_num)
{
    if (pin_num < MAX_PINS_PER_PORT) {
        gpio->BSRR |= (1u << (pin_num + MAX_PINS_PER_PORT));
    }
}

bool stm32_output_gpio_is_set(GPIO_TypeDef *gpio, uint32_t pin_num)
{
    bool set = false;
    if (pin_num < MAX_PINS_PER_PORT) {
        set = (gpio->ODR & (1u << pin_num));
    }
    return set;
}

void stm32_configure_gpio_as_output(GPIO_TypeDef *gpio, uint32_t pin_num)
{
    uint32_t tmp;
    tmp = gpio->MODER;
    tmp &= ~(3 << (2 * pin_num));
    tmp |= (1 << (2 * pin_num)); // (2 * pin_num) == (1 << pin_num)
    gpio->MODER = tmp;
    tmp = gpio->OTYPER;
    tmp &= ~(1 << pin_num);
    gpio->OTYPER = tmp;
}

void stm32_configure_gpio_as_input(GPIO_TypeDef *gpio, uint32_t pin_num, GpioPullDir pull)
{
    uint32_t tmp;
    tmp = gpio->MODER;
    tmp &= ~(3 << (2 * pin_num));
    gpio->MODER = tmp;
    tmp = gpio->PUPDR;
    tmp &= ~(3 << (2 * pin_num));
    tmp |= (pull << (2 * pin_num)); // (2 * pin_num) == (1 << pin_num)
    gpio->PUPDR = tmp;
}

void stm32_output_gpio_toggle(GPIO_TypeDef *gpio, uint32_t pin_num)
{
    if (pin_num < MAX_PINS_PER_PORT) {
        if (stm32_output_gpio_is_set(gpio, pin_num)) {
            stm32_output_gpio_clear(gpio, pin_num);
        } else {
            stm32_output_gpio_set(gpio, pin_num);
        }
    }
}

bool stm32_port_a_in_pin_set(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOA;
    return stm32_input_gpio_is_set(gpio, pin_num);
}

void stm32_configure_port_a_pin_as_input(uint32_t pin_num, GpioPullDir pull)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOA;
    stm32_configure_gpio_as_input(gpio, pin_num, pull);
}

void stm32_configure_port_b_pin_as_output(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOB;
    stm32_configure_gpio_as_output(gpio, pin_num);
}

void stm32_port_b_out_pin_set(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOB;
    return stm32_output_gpio_set(gpio, pin_num);
}

void stm32_port_b_out_pin_clear(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOB;
    return stm32_output_gpio_clear(gpio, pin_num);
}

void stm32_port_b_out_pin_toggle(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOB;
    stm32_output_gpio_toggle(gpio, pin_num);
}

void stm32_configure_port_e_pin_as_output(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOE;
    stm32_configure_gpio_as_output(gpio, pin_num);
}


void stm32_port_e_out_pin_set(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOE;
    return stm32_output_gpio_set(gpio, pin_num);
}

void stm32_port_e_out_pin_clear(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOE;
    return stm32_output_gpio_clear(gpio, pin_num);
}

void stm32_port_e_out_pin_toggle(uint32_t pin_num)
{
    GPIO_TypeDef *gpio;
    gpio = GPIOE;
    stm32_output_gpio_toggle(gpio, pin_num);
}
