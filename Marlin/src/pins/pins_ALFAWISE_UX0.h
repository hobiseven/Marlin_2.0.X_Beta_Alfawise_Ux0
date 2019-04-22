/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * ALFAWISE U30 (STM32F130VET6) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif

#if HOTENDS > 1 || E_STEPPERS > 1
  #error "ALFAWISE U30 supports up to 1 hotends / E-steppers. Comment out this line to continue."
#endif

#ifdef U20
#define BOARD_NAME "Longer3D U20"
#elif defined(U30)
#define BOARD_NAME "Longer3D U30"
#elif defined(U20_PLUS)
#define BOARD_NAME "Longer3D U20+"
#else
#define BOARD_NAME "Longer3D Ux0"
#endif
                              // Release PB4 (STEP_X_PIN) from JTAG NRST role.  
// #define DISABLE_DEBUG      // > Hobi : We still want to debug with STLINK...
#define DISABLE_JTAG          //we free the jtag pins ( pa15) but keep STLINK

//
// Limit Switches
//
#define X_MIN_PIN         PC1
//#define X_MAX_PIN         PC0  // Used as filament sensor runout on Alfawise setup
#define Y_MIN_PIN         PC15
//#define Y_MAX_PIN         PC14 // Unused in stock Alfawise steup. May also be used for Z_Probe Servo function
#define Z_MIN_PIN         PE6  // Standard Endstop or Z_Probe endstop function
//#define Z_MAX_PIN         PE5  // Unused in stock Alfawise steup.
// or GCODE STOP COMMAND. / May also be used for Z_Probe Servo function

//Servo for Z_Probe
// #define SERVO0_PIN PE5 / Z_MAX / If you don't care about optional GCODE STOP COMMAND or 
//already used Y_Max Endstop.
// #define SERVO0_PIN PC14 / Y_MAX / If you want to keep GCODE STOP COMMAND or/and Y_MAX not used.

//
// Steppers
//
#define X_ENABLE_PIN      PB5 // PB5 or 91
#define X_STEP_PIN        PB4 // PB4 or 90
#define X_DIR_PIN         PB3 // PB3 or 89

#define Y_ENABLE_PIN      PB8 // PB8 or 95
#define Y_STEP_PIN        PB7 // PB7 or 93
#define Y_DIR_PIN         PB6 // PB6 or 92

#define Z_ENABLE_PIN      PE1 // PE1 or 98
#define Z_STEP_PIN        PE0 // PE0 or 97
#define Z_DIR_PIN         PB9 // PB9 or 96

#define E0_ENABLE_PIN     PE4  // PE4 or 3
#define E0_STEP_PIN       PE3  // PE3 or 2
#define E0_DIR_PIN        PE2  // PE2 or 1

//
// Temperature Sensors
//
#define TEMP_0_PIN         PA0 // PA0 or 23  // Head thermistor 1
#define TEMP_BED_PIN       PA1 //PA1 or 24   // Bed Thermistor 1

//
// Heaters / Fans
//
#define HEATER_0_PIN       PD3 // PD3 or 84   HEATER1
#define HEATER_BED_PIN     PA8 //PA8 or 67   // HOT BED

#define FAN_PIN            PA15 // PA15 or 77   // FAN
#define FAN_SOFT_PWM            // Required to avoid issues with heating or STLink
#define FAN_MIN_PWM        35   // Fan will not start in 1-30 range
#define FAN_MAX_PWM        255

#define BTN_ENC            PB0 // PB0 or 35 unnconnected pin on Alfawise. Real pin is needed to enable encoder's push button functionality used by touch screen
#define BTN_EN1            -1
#define BTN_EN2            -1

//#define POWER_LOSS_PIN     PA2   // PW_DET
//#define PS_ON_PIN          PA3   // PW_OFF

#define FIL_RUNOUT_PIN       PC0  // MT_DET >> X Max plug on PCB used as filament runout sensor on Alfawise boards

//#define BEEPER_PIN         PC13

#define LED_PIN            PC2 // PC2 or 17

/**
 * Note: Alfawise TFT screens may have 6 different TFT controllers
 * If the screen stays white, disable 'LCD_RESET_PIN' to rely on the bootloader to do screen initialization.
 * Supported screens based on ILI9342, ILI9328 and ST7798V. For other proper initialisation sequence needs to be definned in u8g_dev_tft_320x240_upscale_from_128x64.cpp
 * 
 * Enabling 'LCD_RESET_PIN' causes flickering when entering the LCD menu due to LCD controller reset.
 * Reset feature was designed to "revive the LCD if static electricity killed it."
 */

#define LCD_RESET_PIN      PC4 // PC4 or 33
#define LCD_BACKLIGHT_PIN  PD12 // PD12 or 59
#define FSMC_CS_PIN        PD7 // PD7 = FSMC_NE1 or 88
#define FSMC_RS_PIN        PD11 // A16 PD11 or 58 Register / data select. Only one address needed


/*
 * Note: Alfawise U20/U30 boards are NOT using SPI2 interface, as the hardware designer mixed up MOSI and MISO pins. SPI is managed in SW, and needs below pins declaration
 */

#define TOUCH_CS           PB12 // PB12 or 51 SPI2_NSS
#define TOUCH_SCK          PB13
#define TOUCH_MOSI         PB14
#define TOUCH_MISO         PB15

#define TOUCH_INT          PC6 // PenIRQ coming from ADS7843

/*
//
// SPI1 (EEPROM W25Q64 + DAC OUT)
//

//#define SPI_EEPROM          // If commented this will create a file on the SD card as a replacement 
#define SPI_CHAN_EEPROM1   1
#define SPI_EEPROM1_CS     PC5

//#define EEPROM_SCK         BOARD_SPI1_SCK_PIN  // PA5
//#define EEPROM_MISO        BOARD_SPI1_MISO_PIN // PA6
//#define EEPROM_MOSI        BOARD_SPI1_MOSI_PIN // PA7

#define SPI_CHAN_DAC       2
#define DAC0_SYNC          PA4
*/
