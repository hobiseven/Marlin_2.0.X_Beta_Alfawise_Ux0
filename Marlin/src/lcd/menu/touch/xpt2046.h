#include <stdint.h>

#define XPT2046_DFR_MODE        0x00
#define XPT2046_SER_MODE        0x04
#define XPT2046_CONTROL         0x80

#define XPT2046_X               0x10
#define XPT2046_Y               0x50

#define XPT2046_X_CALIBRATION   12430
#define XPT2046_X_OFFSET        -35
#define XPT2046_Y_CALIBRATION   -8838
#define XPT2046_Y_OFFSET        255

#define TP_CS2  PB12
#define TP_INT  PC6

// the 3 defines below are needed for the sw_SPI function

#define TP_SCK  PB13
#define TP_MISO PB15
#define TP_MOSI PB14

void initTouch(void); // Not used as HW spi is incompatible with alfawise board routing
void initTouch_sw_SPI(void);

uint16_t getTouchCoordinate(uint8_t coordinate); // Not used as HW spi is incompatible with alfawise board routing
uint16_t getTouchCoordinate_sw_SPI(uint8_t coordinate);

bool getTouchPoint(uint16_t *x, uint16_t *y);

//inline bool isTouched() { return getTouchCoordinate(XPT2046_Z1) >= XPT2046_Z1_TRESHHOLD; }
inline bool isTouched() { return !digitalRead (TP_INT); }
inline void waitForRelease(void) { while (isTouched()) {}; }
inline void waitForTouch(uint16_t *x, uint16_t *y) { while(!getTouchPoint(x, y)) {}; }
