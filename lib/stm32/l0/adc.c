/*** @defgroup adc_file I2C
 *
 * @ingroup STM32L0xx
 *
 * @brief <b>libopencm3 STM32L0xx ADC</b>
 *
 * @version 1.0.0
 *
 * @date 15 September 2022
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/adc.h>
/**@{*/

/** @brief ADC Set Clock Source
 *
 * The ADC clock taken from the many sources.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] source Unsigned int32. Source (@ref adc_api_clksource)
 */

void adc_set_clk_source(uint32_t adc, uint32_t source)
{
    ADC_CFGR2(adc) = ((ADC_CFGR2(adc) & ~ADC_CFGR2_CKMODE) | source);
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for All Channels
 *
 * The sampling time can be selected in ADC clock cycles from 1.5 to 239.5,
 * same for all channels.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] time Unsigned int8. Sampling time selection (@ref adc_api_smptime)
 */

void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time)
{
    ADC_SMPR1(adc) = time & ADC_SMPR_SMP;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC select channel
 *
 * Select the channel to sample
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] time Unsigned int32. Channel to sample
 */
void adc_select_channel(uint32_t adc, uint32_t channel) {
    ADC_CHSELR(adc) = ADC_CHSELR_CHSEL(channel);
}