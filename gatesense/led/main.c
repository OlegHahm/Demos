/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Posix UDP Server/Client example
 *
 * @author      Christian Mehlis <mehlis@inf.fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>

#include "posix_io.h"
#include "shell.h"
#include "board_uart0.h"
#include "kernel.h"
#include "thread.h"

#include "config.h"
#include "netsetup.h"
#include "net.h"
#include "led.h"

static char led_stack[KERNEL_CONF_STACKSIZE_MAIN];

int led_pid;

const shell_command_t shell_commands[] = {
    {NULL, NULL, NULL}
};

int main(void)
{
    puts("led Token Up");

    /* we assume the transceiver is started! */
    netsetup_set_channel(CONFIG_CHANNEL);
    netsetup_set_address(CONFIG_OWN_ADDRESS);
    netsetup_register_ondata(net_receive);
    printf("CHANNEL: %d\tADDRESS: %d\n", CONFIG_CHANNEL, CONFIG_OWN_ADDRESS);
    netsetup_start();

    /* start acc and game threads */
    led_pid = thread_create(led_stack, KERNEL_CONF_STACKSIZE_MAIN, PRIORITY_MAIN - 2, CREATE_STACKTEST,
                            led_thread, "led_reader");

    /* start shell */
    posix_open(uart0_handler_pid, 0);
    shell_t shell;
    shell_init(&shell, shell_commands, UART0_BUFSIZE, uart0_readc, uart0_putc);
    shell_run(&shell);
}
