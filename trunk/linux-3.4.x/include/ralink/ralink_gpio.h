/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright, Ralink Technology, Inc.
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 *  THIS  SOFTWARE  IS PROVIDED   ``AS  IS'' AND   ANY  EXPRESS OR IMPLIED
 *  WARRANTIES,   INCLUDING, BUT NOT  LIMITED  TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 *  NO  EVENT  SHALL   THE AUTHOR  BE    LIABLE FOR ANY   DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED   TO, PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS OF
 *  USE, DATA,  OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN  CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  You should have received a copy of the  GNU General Public License along
 *  with this program; if not, write  to the Free Software Foundation, Inc.,
 *  675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *
 ***************************************************************************
 */

#ifndef __RALINK_GPIO_H__
#define __RALINK_GPIO_H__

#ifdef __KERNEL__
#include <asm/rt2880/rt_mmap.h>
#endif

#define RALINK_GPIO_NAME		"ralink_gpio"
#define RALINK_GPIO_DEVNAME		"gpio"
#define RALINK_GPIO_DEVPATH		"/dev/gpio"	//userlevel devname

/*
 * ioctl commands
 */
#define IOCTL_GPIO_CMD_LENGTH_BITS	(8)

#define IOCTL_GPIO_DIR_OUT		0x01
#define IOCTL_GPIO_READ			0x02
#define IOCTL_GPIO_WRITE		0x03
#define IOCTL_GPIO_MODE_GET		0x04
#define IOCTL_GPIO_MODE_SET		0x05
#define IOCTL_GPIO_IRQ_SET		0x10
#define IOCTL_GPIO_LED_SET		0x20
#define IOCTL_GPIO_LED_ENABLED		0x21
#define IOCTL_GPIO_LED_BLINK		0x22

#if defined (CONFIG_RALINK_RT3052)
#define RALINK_GPIO_HAS_5124		1
#elif defined (CONFIG_RALINK_RT3883)
#define RALINK_GPIO_HAS_9524		1
#elif defined (CONFIG_RALINK_RT3352)
#define RALINK_GPIO_HAS_4524		1
#elif defined (CONFIG_RALINK_MT7620)
#define RALINK_GPIO_HAS_7224		1
#elif defined (CONFIG_RALINK_MT7621) || defined (CONFIG_RALINK_MT7628)
#define RALINK_GPIO_HAS_9532		1
#elif defined (CONFIG_RALINK_RT5350)
#define RALINK_GPIO_HAS_2722		1
#endif

#if defined (CONFIG_RALINK_RT5350)
#define RALINK_GPIO_LED_SHOW_VAL	1
#else
#define RALINK_GPIO_LED_SHOW_VAL	0
#endif

#define RALINK_GPIO_LED_INFINITY	255

/*
 * Address of RALINK_ Registers
 */
#define RALINK_SYSCTL_ADDR		RALINK_SYSCTL_BASE	// system control
#define RALINK_REG_GPIOMODE		(RALINK_SYSCTL_ADDR + 0x60)
#if defined (CONFIG_RALINK_MT7628)
#define RALINK_REG_GPIOMODE2		(RALINK_SYSCTL_ADDR + 0x64)
#endif

#define RALINK_IRQ_ADDR			RALINK_INTCL_BASE
#define RALINK_PRGIO_ADDR		RALINK_PIO_BASE // Programmable I/O

#if defined (CONFIG_RALINK_MT7621) || defined (CONFIG_RALINK_MT7628)
#define RALINK_REG_PIOINT		(RALINK_PRGIO_ADDR + 0x90)
#define RALINK_REG_PIOEDGE		(RALINK_PRGIO_ADDR + 0xA0)
#define RALINK_REG_PIORENA		(RALINK_PRGIO_ADDR + 0x50)
#define RALINK_REG_PIOFENA		(RALINK_PRGIO_ADDR + 0x60)
#define RALINK_REG_PIODATA		(RALINK_PRGIO_ADDR + 0x20)
#define RALINK_REG_PIODIR		(RALINK_PRGIO_ADDR + 0x00)
#define RALINK_REG_PIOSET		(RALINK_PRGIO_ADDR + 0x30)
#define RALINK_REG_PIORESET		(RALINK_PRGIO_ADDR + 0x40)
#else
#define RALINK_REG_PIOINT		(RALINK_PRGIO_ADDR + 0x00)
#define RALINK_REG_PIOEDGE		(RALINK_PRGIO_ADDR + 0x04)
#define RALINK_REG_PIORENA		(RALINK_PRGIO_ADDR + 0x08)
#define RALINK_REG_PIOFENA		(RALINK_PRGIO_ADDR + 0x0C)
#define RALINK_REG_PIODATA		(RALINK_PRGIO_ADDR + 0x20)
#define RALINK_REG_PIODIR		(RALINK_PRGIO_ADDR + 0x24)
#define RALINK_REG_PIOSET		(RALINK_PRGIO_ADDR + 0x2C)
#define RALINK_REG_PIORESET		(RALINK_PRGIO_ADDR + 0x30)
#define RALINK_REG_PIOTOGGLE		(RALINK_PRGIO_ADDR + 0x34)
#endif

#if defined (RALINK_GPIO_HAS_2722)

#define RALINK_REG_PIO2722INT		(RALINK_PRGIO_ADDR + 0x60)
#define RALINK_REG_PIO2722EDGE		(RALINK_PRGIO_ADDR + 0x64)
#define RALINK_REG_PIO2722RENA		(RALINK_PRGIO_ADDR + 0x68)
#define RALINK_REG_PIO2722FENA		(RALINK_PRGIO_ADDR + 0x6C)
#define RALINK_REG_PIO2722DATA		(RALINK_PRGIO_ADDR + 0x70)
#define RALINK_REG_PIO2722DIR		(RALINK_PRGIO_ADDR + 0x74)
#define RALINK_REG_PIO2722SET		(RALINK_PRGIO_ADDR + 0x7C)
#define RALINK_REG_PIO2722RESET		(RALINK_PRGIO_ADDR + 0x80)
#define RALINK_REG_PIO2722TOGGLE	(RALINK_PRGIO_ADDR + 0x84)

#elif defined (RALINK_GPIO_HAS_4524)

#define RALINK_REG_PIO3924INT		(RALINK_PRGIO_ADDR + 0x38)
#define RALINK_REG_PIO3924EDGE		(RALINK_PRGIO_ADDR + 0x3C)
#define RALINK_REG_PIO3924RENA		(RALINK_PRGIO_ADDR + 0x40)
#define RALINK_REG_PIO3924FENA		(RALINK_PRGIO_ADDR + 0x44)
#define RALINK_REG_PIO3924DATA		(RALINK_PRGIO_ADDR + 0x48)
#define RALINK_REG_PIO3924DIR		(RALINK_PRGIO_ADDR + 0x4C)
#define RALINK_REG_PIO3924SET		(RALINK_PRGIO_ADDR + 0x54)
#define RALINK_REG_PIO3924RESET		(RALINK_PRGIO_ADDR + 0x58)
#define RALINK_REG_PIO3924TOGGLE	(RALINK_PRGIO_ADDR + 0x5C)

#define RALINK_REG_PIO4540INT		(RALINK_PRGIO_ADDR + 0x60)
#define RALINK_REG_PIO4540EDGE		(RALINK_PRGIO_ADDR + 0x64)
#define RALINK_REG_PIO4540RENA		(RALINK_PRGIO_ADDR + 0x68)
#define RALINK_REG_PIO4540FENA		(RALINK_PRGIO_ADDR + 0x6C)
#define RALINK_REG_PIO4540DATA		(RALINK_PRGIO_ADDR + 0x70)
#define RALINK_REG_PIO4540DIR		(RALINK_PRGIO_ADDR + 0x74)
#define RALINK_REG_PIO4540SET		(RALINK_PRGIO_ADDR + 0x7C)
#define RALINK_REG_PIO4540RESET		(RALINK_PRGIO_ADDR + 0x80)
#define RALINK_REG_PIO4540TOGGLE	(RALINK_PRGIO_ADDR + 0x84)

#elif defined (RALINK_GPIO_HAS_5124)

#define RALINK_REG_PIO3924INT		(RALINK_PRGIO_ADDR + 0x38)
#define RALINK_REG_PIO3924EDGE		(RALINK_PRGIO_ADDR + 0x3C)
#define RALINK_REG_PIO3924RENA		(RALINK_PRGIO_ADDR + 0x40)
#define RALINK_REG_PIO3924FENA		(RALINK_PRGIO_ADDR + 0x44)
#define RALINK_REG_PIO3924DATA		(RALINK_PRGIO_ADDR + 0x48)
#define RALINK_REG_PIO3924DIR		(RALINK_PRGIO_ADDR + 0x4C)
#define RALINK_REG_PIO3924SET		(RALINK_PRGIO_ADDR + 0x54)
#define RALINK_REG_PIO3924RESET		(RALINK_PRGIO_ADDR + 0x58)
#define RALINK_REG_PIO3924TOGGLE	(RALINK_PRGIO_ADDR + 0x5C)

#define RALINK_REG_PIO5140INT		(RALINK_PRGIO_ADDR + 0x60)
#define RALINK_REG_PIO5140EDGE		(RALINK_PRGIO_ADDR + 0x64)
#define RALINK_REG_PIO5140RENA		(RALINK_PRGIO_ADDR + 0x68)
#define RALINK_REG_PIO5140FENA		(RALINK_PRGIO_ADDR + 0x6C)
#define RALINK_REG_PIO5140DATA		(RALINK_PRGIO_ADDR + 0x70)
#define RALINK_REG_PIO5140DIR		(RALINK_PRGIO_ADDR + 0x74)
#define RALINK_REG_PIO5140SET		(RALINK_PRGIO_ADDR + 0x7C)
#define RALINK_REG_PIO5140RESET		(RALINK_PRGIO_ADDR + 0x80)
#define RALINK_REG_PIO5140TOGGLE	(RALINK_PRGIO_ADDR + 0x84)

#elif defined (RALINK_GPIO_HAS_7224)

#define RALINK_REG_PIO3924INT		(RALINK_PRGIO_ADDR + 0x38)
#define RALINK_REG_PIO3924EDGE		(RALINK_PRGIO_ADDR + 0x3C)
#define RALINK_REG_PIO3924RENA		(RALINK_PRGIO_ADDR + 0x40)
#define RALINK_REG_PIO3924FENA		(RALINK_PRGIO_ADDR + 0x44)
#define RALINK_REG_PIO3924DATA		(RALINK_PRGIO_ADDR + 0x48)
#define RALINK_REG_PIO3924DIR		(RALINK_PRGIO_ADDR + 0x4C)
#define RALINK_REG_PIO3924POL		(RALINK_PRGIO_ADDR + 0x50)
#define RALINK_REG_PIO3924SET		(RALINK_PRGIO_ADDR + 0x54)
#define RALINK_REG_PIO3924RESET		(RALINK_PRGIO_ADDR + 0x58)
#define RALINK_REG_PIO3924TOGGLE	(RALINK_PRGIO_ADDR + 0x5C)

#define RALINK_REG_PIO7140INT		(RALINK_PRGIO_ADDR + 0x60)
#define RALINK_REG_PIO7140EDGE		(RALINK_PRGIO_ADDR + 0x64)
#define RALINK_REG_PIO7140RENA		(RALINK_PRGIO_ADDR + 0x68)
#define RALINK_REG_PIO7140FENA		(RALINK_PRGIO_ADDR + 0x6C)
#define RALINK_REG_PIO7140DATA		(RALINK_PRGIO_ADDR + 0x70)
#define RALINK_REG_PIO7140DIR		(RALINK_PRGIO_ADDR + 0x74)
#define RALINK_REG_PIO7140POL		(RALINK_PRGIO_ADDR + 0x78)
#define RALINK_REG_PIO7140SET		(RALINK_PRGIO_ADDR + 0x7C)
#define RALINK_REG_PIO7140RESET		(RALINK_PRGIO_ADDR + 0x80)
#define RALINK_REG_PIO7140TOGGLE	(RALINK_PRGIO_ADDR + 0x84)

#define RALINK_REG_PIO72INT		(RALINK_PRGIO_ADDR + 0x88)
#define RALINK_REG_PIO72EDGE		(RALINK_PRGIO_ADDR + 0x8C)
#define RALINK_REG_PIO72RENA		(RALINK_PRGIO_ADDR + 0x90)
#define RALINK_REG_PIO72FENA		(RALINK_PRGIO_ADDR + 0x94)
#define RALINK_REG_PIO72DATA		(RALINK_PRGIO_ADDR + 0x98)
#define RALINK_REG_PIO72DIR		(RALINK_PRGIO_ADDR + 0x9C)
#define RALINK_REG_PIO72POL		(RALINK_PRGIO_ADDR + 0xA0)
#define RALINK_REG_PIO72SET		(RALINK_PRGIO_ADDR + 0xA4)
#define RALINK_REG_PIO72RESET		(RALINK_PRGIO_ADDR + 0xA8)
#define RALINK_REG_PIO72TOGGLE		(RALINK_PRGIO_ADDR + 0xAC)

#elif defined (RALINK_GPIO_HAS_9524)

#define RALINK_REG_PIO3924INT		(RALINK_PRGIO_ADDR + 0x38)
#define RALINK_REG_PIO3924EDGE		(RALINK_PRGIO_ADDR + 0x3C)
#define RALINK_REG_PIO3924RENA		(RALINK_PRGIO_ADDR + 0x40)
#define RALINK_REG_PIO3924FENA		(RALINK_PRGIO_ADDR + 0x44)
#define RALINK_REG_PIO3924DATA		(RALINK_PRGIO_ADDR + 0x48)
#define RALINK_REG_PIO3924DIR		(RALINK_PRGIO_ADDR + 0x4C)
#define RALINK_REG_PIO3924SET		(RALINK_PRGIO_ADDR + 0x54)
#define RALINK_REG_PIO3924RESET		(RALINK_PRGIO_ADDR + 0x58)
#define RALINK_REG_PIO3924TOGGLE	(RALINK_PRGIO_ADDR + 0x5C)

#define RALINK_REG_PIO7140INT		(RALINK_PRGIO_ADDR + 0x60)
#define RALINK_REG_PIO7140EDGE		(RALINK_PRGIO_ADDR + 0x64)
#define RALINK_REG_PIO7140RENA		(RALINK_PRGIO_ADDR + 0x68)
#define RALINK_REG_PIO7140FENA		(RALINK_PRGIO_ADDR + 0x6C)
#define RALINK_REG_PIO7140DATA		(RALINK_PRGIO_ADDR + 0x70)
#define RALINK_REG_PIO7140DIR		(RALINK_PRGIO_ADDR + 0x74)
#define RALINK_REG_PIO7140SET		(RALINK_PRGIO_ADDR + 0x7C)
#define RALINK_REG_PIO7140RESET		(RALINK_PRGIO_ADDR + 0x80)
#define RALINK_REG_PIO7140TOGGLE	(RALINK_PRGIO_ADDR + 0x84)

#define RALINK_REG_PIO9572INT		(RALINK_PRGIO_ADDR + 0x88)
#define RALINK_REG_PIO9572EDGE		(RALINK_PRGIO_ADDR + 0x8C)
#define RALINK_REG_PIO9572RENA		(RALINK_PRGIO_ADDR + 0x90)
#define RALINK_REG_PIO9572FENA		(RALINK_PRGIO_ADDR + 0x94)
#define RALINK_REG_PIO9572DATA		(RALINK_PRGIO_ADDR + 0x98)
#define RALINK_REG_PIO9572DIR		(RALINK_PRGIO_ADDR + 0x9C)
#define RALINK_REG_PIO9572SET		(RALINK_PRGIO_ADDR + 0xA0)
#define RALINK_REG_PIO9572RESET		(RALINK_PRGIO_ADDR + 0xA4)
#define RALINK_REG_PIO9572TOGGLE	(RALINK_PRGIO_ADDR + 0xA8)

#elif defined (RALINK_GPIO_HAS_9532)

#define RALINK_REG_PIO6332INT		(RALINK_PRGIO_ADDR + 0x94)
#define RALINK_REG_PIO6332EDGE		(RALINK_PRGIO_ADDR + 0xA4)
#define RALINK_REG_PIO6332RENA		(RALINK_PRGIO_ADDR + 0x54)
#define RALINK_REG_PIO6332FENA		(RALINK_PRGIO_ADDR + 0x64)
#define RALINK_REG_PIO6332DATA		(RALINK_PRGIO_ADDR + 0x24)
#define RALINK_REG_PIO6332DIR		(RALINK_PRGIO_ADDR + 0x04)
#define RALINK_REG_PIO6332SET		(RALINK_PRGIO_ADDR + 0x34)
#define RALINK_REG_PIO6332RESET		(RALINK_PRGIO_ADDR + 0x44)

#define RALINK_REG_PIO9564INT		(RALINK_PRGIO_ADDR + 0x98)
#define RALINK_REG_PIO9564EDGE		(RALINK_PRGIO_ADDR + 0xA8)
#define RALINK_REG_PIO9564RENA		(RALINK_PRGIO_ADDR + 0x58)
#define RALINK_REG_PIO9564FENA		(RALINK_PRGIO_ADDR + 0x68)
#define RALINK_REG_PIO9564DATA		(RALINK_PRGIO_ADDR + 0x28)
#define RALINK_REG_PIO9564DIR		(RALINK_PRGIO_ADDR + 0x08)
#define RALINK_REG_PIO9564SET		(RALINK_PRGIO_ADDR + 0x38)
#define RALINK_REG_PIO9564RESET		(RALINK_PRGIO_ADDR + 0x48)

#endif

/*
 * Values for the GPIOMODE Register
 */
#if defined (CONFIG_RALINK_RT3052)

#define RALINK_GPIOMODE_I2C		0x01
#define RALINK_GPIOMODE_SPI		0x02
#define RALINK_GPIOMODE_UARTF		0x1C
#define RALINK_GPIOMODE_UARTL		0x20
#define RALINK_GPIOMODE_JTAG		0x40
#define RALINK_GPIOMODE_MDIO		0x80
#define RALINK_GPIOMODE_SDRAM		0x100
#define RALINK_GPIOMODE_RGMII		0x200

#elif defined (CONFIG_RALINK_RT3352)

#define RALINK_GPIOMODE_I2C		0x01
#define RALINK_GPIOMODE_SPI		0x02
#define RALINK_GPIOMODE_UARTF		0x1C
#define RALINK_GPIOMODE_UARTL		0x20
#define RALINK_GPIOMODE_JTAG		0x40
#define RALINK_GPIOMODE_MDIO		0x80
#define RALINK_GPIOMODE_GE1		0x200
#define RALINK_GPIOMODE_EPHY		0x4000
#define RALINK_GPIOMODE_LNA_G		0x40000
#define RALINK_GPIOMODE_PA_G		0x100000
#define RALINK_GPIOMODE_SPI_CS1		0x400000

#elif defined (CONFIG_RALINK_RT5350)

#define RALINK_GPIOMODE_I2C		0x01
#define RALINK_GPIOMODE_SPI		0x02
#define RALINK_GPIOMODE_UARTF		0x1C
#define RALINK_GPIOMODE_UARTL		0x20
#define RALINK_GPIOMODE_JTAG		0x40
#define RALINK_GPIOMODE_EPHY		0x4000
#define RALINK_GPIOMODE_SPI_CS1		0x400000

#elif defined (CONFIG_RALINK_RT3883)

#define RALINK_GPIOMODE_I2C		0x01
#define RALINK_GPIOMODE_SPI		0x02
#define RALINK_GPIOMODE_UARTF		0x1C
#define RALINK_GPIOMODE_UARTL		0x20
#define RALINK_GPIOMODE_JTAG		0x40
#define RALINK_GPIOMODE_MDIO		0x80
#define RALINK_GPIOMODE_GE1		0x200
#define RALINK_GPIOMODE_GE2		0x400
#define RALINK_GPIOMODE_PCI		0x1800
#define RALINK_GPIOMODE_LNA_A		0x30000
#define RALINK_GPIOMODE_LNA_G		0xC0000

#elif defined (CONFIG_RALINK_MT7620)

#define RALINK_GPIOMODE_I2C		0x01
#define RALINK_GPIOMODE_UARTF		0x1C
#define RALINK_GPIOMODE_UARTL		0x20
#define RALINK_GPIOMODE_MDIO		0x180
#define RALINK_GPIOMODE_GE1		0x200
#define RALINK_GPIOMODE_GE2		0x400
#define RALINK_GPIOMODE_SPI		0x800
#define RALINK_GPIOMODE_SPI_REFCLK	0x1000
#define RALINK_GPIOMODE_WLED		0x2000
#define RALINK_GPIOMODE_EPHY		0x8000
#define RALINK_GPIOMODE_PERST		0x20000
#define RALINK_GPIOMODE_ND_SD		0x80000
#define RALINK_GPIOMODE_PA_G		0x100000
#define RALINK_GPIOMODE_WDT		0x400000

#elif defined (CONFIG_RALINK_MT7621)

#define RALINK_GPIOMODE_UART1		0x02
#define RALINK_GPIOMODE_I2C		0x04
#define RALINK_GPIOMODE_UART3		0x08
#define RALINK_GPIOMODE_UART2		0x20
#define RALINK_GPIOMODE_JTAG		0x80
#define RALINK_GPIOMODE_WDT		0x100
#define RALINK_GPIOMODE_PERST		0x400
#define RALINK_GPIOMODE_MDIO		0x3000
#define RALINK_GPIOMODE_GE1		0x4000
#define RALINK_GPIOMODE_GE2		0x8000
#define RALINK_GPIOMODE_SPI		0x10000
#define RALINK_GPIOMODE_SDXC		0x40000
#define RALINK_GPIOMODE_ESWINT		0x100000

#elif defined (CONFIG_RALINK_MT7628)

#define RALINK_GPIOMODE_GPIO		0x1
#define RALINK_GPIOMODE_SPI_SLAVE	0x4
#define RALINK_GPIOMODE_SPI_CS1		0x10
#define RALINK_GPIOMODE_I2S		0x40
#define RALINK_GPIOMODE_UART1		0x100
#define RALINK_GPIOMODE_SDXC		0x400
#define RALINK_GPIOMODE_SPI		0x1000
#define RALINK_GPIOMODE_WDT		0x4000
#define RALINK_GPIOMODE_PERST		0x10000
#define RALINK_GPIOMODE_REFCLK		0x40000
#define RALINK_GPIOMODE_I2C		0x100000
#define RALINK_GPIOMODE_EPHY		0x40000
#define RALINK_GPIOMODE_P0LED		0x100000
#define RALINK_GPIOMODE_WLED		0x400000
#define RALINK_GPIOMODE_UART2		0x1000000
#define RALINK_GPIOMODE_UART3		0x4000000
#define RALINK_GPIOMODE_PWM0		0x10000000
#define RALINK_GPIOMODE_PWM1		0x40000000

#else
#error Please Choose System Type
#endif

// if you would like to enable GPIO mode for other pins, please modify this value
// !! Warning: changing this value may make other features(MDIO, PCI, etc) lose efficacy
#if defined (CONFIG_RALINK_MT7621)
#define RALINK_GPIOMODE_DFT		(RALINK_GPIOMODE_UART2 | RALINK_GPIOMODE_UART3 | RALINK_GPIOMODE_WDT)
#elif defined (CONFIG_RALINK_MT7628)
#define RALINK_GPIOMODE_DFT		(RALINK_GPIOMODE_UART2 | RALINK_GPIOMODE_UART3 | RALINK_GPIOMODE_SPI_CS1 | RALINK_GPIOMODE_WDT)
#else
#define RALINK_GPIOMODE_DFT		(RALINK_GPIOMODE_UARTF)
#endif

/*
 * bit is the unit of length
 */
#if defined (RALINK_GPIO_HAS_2722)
#define RALINK_GPIO_NUMBER		28
#elif defined (RALINK_GPIO_HAS_4524)
#define RALINK_GPIO_NUMBER		46
#elif defined (RALINK_GPIO_HAS_5124)
#define RALINK_GPIO_NUMBER		52
#elif defined (RALINK_GPIO_HAS_7224)
#define RALINK_GPIO_NUMBER		73
#elif defined (RALINK_GPIO_HAS_9524)
#define RALINK_GPIO_NUMBER		96
#elif defined (RALINK_GPIO_HAS_9532)
#define RALINK_GPIO_NUMBER		64	/* MT7621=62 pins, MT7628=47 pins (use 2 full units) */
#else
#define RALINK_GPIO_NUMBER		24
#endif

#define RALINK_GPIO_DIR_IN		0
#define RALINK_GPIO_DIR_OUT		1

#define RALINK_GPIO(x)			(1u << (x))

/*
 * structure used at regsitration
 */
typedef struct {
	pid_t pid;			// process id to notify
	unsigned char rise;		// notify rising edge
	unsigned char fall;		// notify falling edge
} ralink_gpio_irq_info;

typedef struct {
	unsigned char invert;		// invert led (blink=on->off->on)
	unsigned char on;		// interval of led on
	unsigned char off;		// interval of led off
	unsigned char blinks;		// number of blinking cycles
	unsigned char rests;		// number of break cycles
	unsigned char times;		// blinking times
} ralink_gpio_led_info;

#ifdef __KERNEL__
extern void ralink_gpio_lock(void);
extern void ralink_gpio_unlock(void);
extern void ralink_gpio_set_pin_direction(u32 pin, u32 is_output);
extern void ralink_gpio_set_pin_value(u32 pin, u32 value);
extern u32  ralink_gpio_get_pin_value(u32 pin);
extern void ralink_gpio_mode_set_bit(u32 idx, u32 value);
extern u32  ralink_gpio_mode_get_bit(u32 idx);
#ifdef CONFIG_RALINK_GPIO_LED
extern int  ralink_gpio_led_blink(u32 led_gpio);
#endif
#endif

#endif
