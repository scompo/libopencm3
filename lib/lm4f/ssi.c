/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Mauro Scomparin <scompo@gmail.com>
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

#include <libopencm3/lm4f/ssi.h>
#include <libopencm3/lm4f/systemcontrol.h>

/**
 * \brief Enable the SSI
 *
 * @param[in] ssi SSI block register address base @ref ssi_reg_base
 */
void ssi_enable(u32 ssi){
	SSI_CR1(ssi) |= SPI_CR1_SEE;
}

/**
 * \brief Enable the SSI
 *
 * @param[in] ssi SSI block register address base @ref ssi_reg_base
 */
void ssi_disable(u32 ssi){
	SSI_CR1(ssi) &= ~SPI_CR1_SEE;
}

/**
 * \brief Set Mode for SSI
 *
 * @param[in] ssi SSI block register address base @ref ssi_reg_base
 * @param[in] mode SSI mode to set
 */
void ssi_set_mode(u32 ssi, ssi_mode mode){
	switch(mode){
		case SSI_MODE_MASTER:
			return;
		case SSI_MODE_SLAVE_TX_ENABLED:
			SSI_CR1(ssi) |= SPI_CR1_MS;
			return;
		case SSI_MODE_SLAVE_TX_DISABLED:
			SSI_CR1(ssi) |= (SPI_CR1_MS | SPI_CR1_SOD;
			return;
		default:
			/* I should not end here! */
			return;
	}
}

/**
 * \brief Set SSI frame format
 *
 * @param[in] ssi SSI block register address base @ref ssi_reg_base
 * @param[in] format format of frame.
 */
void ssi_set_frame_format(u32 ssi, ssi_frm_frmt_t format){
	u32 reg32,tmpFRF;
	switch(format){
		case SSI_FRAME_FORMAT_TI:
			tmpFRF |= SPI_CR0_FRF_1;
			break;
		case SSI_FRAME_FORMAT_MICROWIRE:
			tmpFRF |= SPI_CR0_FRF_2;
			break;
		case SSI_FRAME_FORMAT_SPI_0:
			tmpFRF |= SPI_CR0_FRF_0;
		case SSI_FRAME_FORMAT_SPI_1:
			tmpFRF |= SPI_CR0_FRF_0;
			return;
		case SSI_FRAME_FORMAT_SPI_2:
			tmpFRF |= SPI_CR0_FRF_0;
			return;
		case SSI_FRAME_FORMAT_SPI_3:
			tmpFRF |= SPI_CR0_FRF_0;
			return;
		default:
			/* I should not end here! */
			return;
	}
	reg32 = SSI_CR0(ssi);
	reg32 &= ~SSI_CR0_FRF_MASK;
	reg32 |= tmpFRF;
	SSI_CR0(ssi) = reg32;
	return;
}

/* TODO: implement the other stuff */