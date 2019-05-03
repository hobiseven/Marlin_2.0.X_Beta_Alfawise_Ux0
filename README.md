# Marlin_2.0.X_Beta_Alfawise_Ux0

This is the initial commit of the Marlin 2.0.X code port to Alfawise Ux0 boards. ONLY COMPILES with STM32 5.3.0 Libs or above

This is based on a Marlin2.0.x_bugfix pull 14th April 2019 + custom code modified from JMZ52 + Hobi code specific for Alfawise. Marlin code has then be synched to 03rd May 2019, and they have already merged a part of our common changes.

To build the code, you need to install Vscode + Platformio. Detailled tutorial in French available at that URL :

https://www.lesimprimantes3d.fr/forum/topic/18260-alfawise-u20x-u30-marlin-2x-firmware-alternatif/


## Development
For developpers, or debugging if the screen does not work :

- ILI9341 support / init code
- Improved detection for ILI9341 screens that do not have the proper identifier in register 0x04 of the driver chip,*
but in alternate ID register 0xD3. This is selectable in the `Config.h` Alfawise section
- Removed SPI hardware driver for touch screen management, and replaced it by a pure software SPI as the Longer3D board
designer mixed pins MOSI and MISO while routing the board
- Changed CPU from STM32F1203ZE to STM32F103VE
- Changed the Marlin pins file for Alphawise Ux0 boards
- Disabled JTAG debug, but kept ST Link debug capability/SWD
- Use the original Alfawise bootloader to update from SD Card.
  For STLink flash, please comment the py script in platformio.ini and rebuild.
- Integrated touchscreen calibration in Configuration/Touchscreen menu (to get your values)
- Fixed the runout sensor

## To be done

- Store the calibration results directly in settings
- Include some Z Probes configuration samples
- Fix the Powerloss recovery resume (seems a Marlin bug for now)

## Configuration

- 1 extruder with 1 temperature probe
- 1 heater bed with 1 temperature probe. U20 or U30 flag to be set at the beginning of config.h
- 4 drivers type A4998 for the 3 axis + extruder
- Homing on X,Y,Z on (-) direction. No Xmax,Ymax and Zmax declared.
- Filament detection has been assigned to Xmax pin, like the alfawise fw. Users can modify and use this.
- SD-Card support for the code.
- 2 serial ports running at 250,000 baud (on the alfawise USB port, which is directly connected to STM32 CPU)
- Support in theory only 2 types of LCD screen : ILI9341, ST7798V. However Alfawise Ux0 printers may have 6 different types of screens.

In case you need to add your specific 320x240 screen if the LCD is not one of the 2 above:
All the screen detection is in file `u8g_dev_tft_320x240_upscale_from_128x64.cpp`, at line 275.
Place a breakpoint here to check the value. `0` is bad, and means an alternate ID method is needed.
ILI9341 can have its ID in register 0x04 sometimes or in alternate ID4 register 0xD3. Returned value for 0xD3 is 0x9341.
The LCD register to be checked for ID is configurable in `Config.h`.

In the same file additional screen initialization sequences canbe added if you have a screen different from the 3 listed above.
Initialization sequences are at lines 132-177.

<h3>:warning: Warning</h3>
We have tested the code on U30 and U20 as good as we could but bugs may remain. YOU ARE WARNED.
I will NOT do ANY customer support.
