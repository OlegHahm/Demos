/*
 * Copyright (C) 2015 Hauke Petersen <mail@haukepetersen.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/**
 * @ingroup     lndw15_sensor
 * @{
 *
 * @file
 * @brief       Interfaces of the sensing module
 *
 * @author      Hauke Petersen <mail@haukepetersen.de>
 */

#ifndef SENSE_H_
#define SENSE_H_

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @brief   Initialize the network interface
 */
void sense_init(kernel_pid_t radio);

/**
 * @brief   Turn sensing on or off
 */
void sense_set_state(int s);

/**
 * @brief   Set the sampling rate
 *
 * @param[in] int       new rate, wait value in ms between to samples
 */
void sense_set_rate(unsigned int new_rate);

void sense_send_data(uint8_t *pkt);

#ifdef __cplusplus
}
#endif

#endif /* SENSE_H_*/
/** @} */
