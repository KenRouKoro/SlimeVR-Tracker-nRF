/*
 * Copyright (c) 2018 Nordic Semiconductor ASA.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/init.h>
#include <hal/nrf_gpio.h>
#include <zephyr/devicetree.h>

#define ZEPHYR_USER_NODE DT_PATH(zephyr_user)

#define VCC_GPIO_PIN DT_GPIO_PIN(ZEPHYR_USER_NODE, vcc_gpios)
#define VCC_GPIO_PORT_NUM DT_PROP(DT_GPIO_CTLR(ZEPHYR_USER_NODE, vcc_gpios), port)

static int board_foxsmolv1_init(void)
{
	/* pull up on P0.24 P0.22, to spi cs sdo up
	 */
	nrf_gpio_cfg(NRF_GPIO_PIN_MAP(0, 22), NRF_GPIO_PIN_DIR_INPUT, NRF_GPIO_PIN_INPUT_DISCONNECT, NRF_GPIO_PIN_PULLUP, NRF_GPIO_PIN_S0S1, NRF_GPIO_PIN_NOSENSE);
	nrf_gpio_cfg(NRF_GPIO_PIN_MAP(0, 24), NRF_GPIO_PIN_DIR_INPUT, NRF_GPIO_PIN_INPUT_DISCONNECT, NRF_GPIO_PIN_PULLUP, NRF_GPIO_PIN_S0S1, NRF_GPIO_PIN_NOSENSE);
	return 0;
}

SYS_INIT(board_foxsmolv1_init, PRE_KERNEL_1,
	CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);