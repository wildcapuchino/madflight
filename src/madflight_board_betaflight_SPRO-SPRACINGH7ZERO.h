/*==============================================================================
Generated on: 2024-03-11 20:33:44.837730
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: SPRACINGH7ZERO
Manufacturer ID: SPRO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_SPRO-SPRACINGH7ZERO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-SPRO-SPRACINGH7ZERO"
#define HW_MCU "STM32H750"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define TARGET_BOARD_IDENTIFIER  "SP7Z"
#define USBD_PRODUCT_STRING  "SPRacingH7ZERO"
#define FC_VMA_ADDRESS  0x97CE0000
#define EEPROM_SIZE  8192
#define USE_SPRACING_PERSISTENT_RTC_WORKAROUND
#define USE_BUTTONS
#define BUTTON_A_PIN  PE4
#define BUTTON_A_PIN_INVERTED
#define BUTTON_B_PIN  PE4
#define BUTTON_B_PIN_INVERTED
#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define QUADSPI1_SCK_PIN  PB2
#define QUADSPI1_BK1_IO0_PIN  PD11
#define QUADSPI1_BK1_IO1_PIN  PD12
#define QUADSPI1_BK1_IO2_PIN  PE2
#define QUADSPI1_BK1_IO3_PIN  PD13
#define QUADSPI1_BK1_CS_PIN  PB10
#define QUADSPI1_BK2_IO0_PIN  PE7
#define QUADSPI1_BK2_IO1_PIN  PE8
#define QUADSPI1_BK2_IO2_PIN  PE9
#define QUADSPI1_BK2_IO3_PIN  PE10
#define QUADSPI1_BK2_CS_PIN  NONE
#define QUADSPI1_MODE  QUADSPI_MODE_BK1_ONLY
#define QUADSPI1_CS_FLAGS  (QUADSPI_BK1_CS_HARDWARE
#define FLASH_QUADSPI_INSTANCE  QUADSPI
#define CONFIG_IN_EXTERNAL_FLASH
#define USE_FIRMWARE_PARTITION
#define BB_USE  BB_USE_SDCARD
#define USE_SDCARD_SDIO
#define SDCARD_DETECT_PIN  PD10
#define SDCARD_DETECT_INVERTED
#define SDIO_DEVICE  SDIODEV_1
#define SDIO_USE_4BIT  true
#define SDIO_CK_PIN  PC12
#define SDIO_CMD_PIN  PD2
#define SDIO_D0_PIN  PC8
#define SDIO_D1_PIN  PC9
#define SDIO_D2_PIN  PC10
#define SDIO_D3_PIN  PC11
#define DEFAULT_BLACKBOX_DEVICE  BLACKBOX_DEVICE_SDCARD
#define DEFAULT_BLACKBOX_DEVICE  BLACKBOX_DEVICE_FLASH
#define USE_SPI
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN  PD3
#define SPI2_MISO_PIN  PC2
#define SPI2_MOSI_PIN  PC3
#define SPI2_NSS_PIN  PB12
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN  PB3
#define SPI3_MISO_PIN  PB4
#define SPI3_MOSI_PIN  PD6
#define SPI3_NSS_PIN  PA15
#define USE_SPI_DEVICE_4
#define SPI4_SCK_PIN  PE12
#define SPI4_MISO_PIN  PE13
#define SPI4_MOSI_PIN  PE14
#define SPI4_NSS_PIN  PE11
#define USE_USB_ID
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN  PB8
#define I2C1_SDA_PIN  PB9
#define I2C_DEVICE  (I2CDEV_1)
#define I2C2_SCL_PIN  NONE
#define I2C2_SDA_PIN  NONE
#define I2C3_SCL_PIN  NONE
#define I2C3_SDA_PIN  NONE
#define I2C4_SCL_PIN  NONE
#define I2C4_SDA_PIN  NONE
#define ENSURE_MPU_DATA_READY_IS_LOW
#define ADC1_DMA_OPT  8
#define ADC3_DMA_OPT  9
#define IMU_USE  IMU_USE_SPI_MPU6500
#define BARO_USE  BARO_USE_BMP388
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25N01G"
#define USE_CAMERA_CONTROL
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PE3;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI3)
const int HW_PIN_SPI_MISO = -1;
const int HW_PIN_SPI_MOSI = -1;
const int HW_PIN_SPI_SCLK = -1;
const int HW_PIN_IMU_CS   = PA15;
const int HW_PIN_IMU_EXTI = PD4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PA0,PA1,PA2,PA3,PB6,PB7,PC6,PC7};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PB15;
const int HW_PIN_RCIN_TX  = PB14;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PNONE;
const int HW_PIN_GPS_TX   = PD5;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC4;
const int HW_PIN_BAT_I    = PC1;

//Include Libraries
#include <Wire.h>                      //I2C communication
#include <SPI.h>                       //SPI communication
#include "madflight/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 8
#define HW_PIN_SERIAL { {1,PB14,PB15,-1}, {2,PD5,PNONE,-1}, {3,PD8,PD9,-1}, {4,PD1,PD0,-1}, {5,PB13,PB5,-1}, {6,PC6,PC7,-1}, {7,PNONE,PNONE,-1}, {8,PE1,PE0,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 0
#define HW_PIN_SPI {  } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 4
#define HW_PIN_I2C { {1,PB8,PB9}, {2,PNONE,PNONE}, {3,PNONE,PNONE}, {4,PNONE,PNONE} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PA0,PA1,PA2,PA3,PB6,PB7,PC6,PC7}

//other pins
#define HW_PIN_BEEPER PD7
#define HW_PIN_PPM PB15
#define HW_PIN_PWM PB15
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PE3
#define HW_PIN_TRANSPONDER PB11
#define HW_PIN_CAMERA_CONTROL PE5
#define HW_PIN_ADC_BATT PC4
#define HW_PIN_ADC_RSSI PC0
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_ADC_EXT PC5
#define HW_PIN_SDIO_CK PC12
#define HW_PIN_SDIO_CMD PD2
#define HW_PIN_SDIO_D0 PC8
#define HW_PIN_SDIO_D1 PC9
#define HW_PIN_SDIO_D2 PC10
#define HW_PIN_SDIO_D3 PC11
#define HW_PIN_OSD_CS PE11
#define HW_PIN_GYRO_EXTI PD4
#define HW_PIN_GYRO_EXTI_2 PE15
#define HW_PIN_GYRO_CS PA15
#define HW_PIN_GYRO_CS_2 PB12

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 0
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_GYRO_TO_USE FIRST
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 3
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_2_BUSTYPE SPI
#define HW_SET_GYRO_2_SPIBUS 2
#define HW_SET_GYRO_2_SENSOR_ALIGN CW90
#define HW_SET_MAX7456_SPI_BUS 4


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32H750 (SP7N) 4.4.0 Dec 26 2022 / 12:28:11 (7671c7eb01) MSP API: 1.45

#define TARGET_BOARD_IDENTIFIER "SP7Z"
#define USBD_PRODUCT_STRING "SPRacingH7ZERO"

#
# Settings required to boot
#
# Note: hardware for all possible config storage subsystems needs to be known and initialised BEFORE loading
# a config from it can work. (SPI/QSPI/SDCARD).
#

#define FC_VMA_ADDRESS    0x97CE0000

#define EEPROM_SIZE 8192

#define USE_SPRACING_PERSISTENT_RTC_WORKAROUND

#define USE_BUTTONS
#define BUTTON_A_PIN            PE4
#define BUTTON_A_PIN_INVERTED
#define BUTTON_B_PIN            PE4
#define BUTTON_B_PIN_INVERTED

#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define QUADSPI1_SCK_PIN PB2
#define QUADSPI1_BK1_IO0_PIN PD11
#define QUADSPI1_BK1_IO1_PIN PD12
#define QUADSPI1_BK1_IO2_PIN PE2
#define QUADSPI1_BK1_IO3_PIN PD13
#define QUADSPI1_BK1_CS_PIN PB10
#define QUADSPI1_BK2_IO0_PIN PE7
#define QUADSPI1_BK2_IO1_PIN PE8
#define QUADSPI1_BK2_IO2_PIN PE9
#define QUADSPI1_BK2_IO3_PIN PE10
#define QUADSPI1_BK2_CS_PIN NONE
#define QUADSPI1_MODE QUADSPI_MODE_BK1_ONLY
#define QUADSPI1_CS_FLAGS (QUADSPI_BK1_CS_HARDWARE | QUADSPI_BK2_CS_NONE | QUADSPI_CS_MODE_LINKED)

#define FLASH_QUADSPI_INSTANCE    QUADSPI

#define CONFIG_IN_EXTERNAL_FLASH
#define USE_FIRMWARE_PARTITION

#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDCARD_DETECT_PIN PD10
#define SDCARD_DETECT_INVERTED
#define SDIO_DEVICE             SDIODEV_1
#define SDIO_USE_4BIT           true
#define SDIO_CK_PIN             PC12
#define SDIO_CMD_PIN            PD2
#define SDIO_D0_PIN             PC8
#define SDIO_D1_PIN             PC9
#define SDIO_D2_PIN             PC10
#define SDIO_D3_PIN             PC11

#ifdef USE_SDCARD
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD
#else
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#endif

#define USE_SPI

#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PD3
#define SPI2_MISO_PIN           PC2
#define SPI2_MOSI_PIN           PC3
#define SPI2_NSS_PIN            PB12

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            PB3
#define SPI3_MISO_PIN           PB4
#define SPI3_MOSI_PIN           PD6
#define SPI3_NSS_PIN            PA15

#define USE_SPI_DEVICE_4
#define SPI4_SCK_PIN            PE12
#define SPI4_MISO_PIN           PE13
#define SPI4_MOSI_PIN           PE14
#define SPI4_NSS_PIN            PE11

#
# Settings to enable/configure remaining hardware
#

#define USE_USB_ID

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN            PB8
#define I2C1_SDA_PIN            PB9
#define I2C_DEVICE (I2CDEV_1)

#define I2C2_SCL_PIN            NONE
#define I2C2_SDA_PIN            NONE
#define I2C3_SCL_PIN            NONE
#define I2C3_SDA_PIN            NONE
#define I2C4_SCL_PIN            NONE
#define I2C4_SDA_PIN            NONE

#define ENSURE_MPU_DATA_READY_IS_LOW

#define ADC1_DMA_OPT 8
#define ADC3_DMA_OPT 9


#
# Settings that are currently defined in target/common_pre.h for non-cloud builds that probably shouldn't be.
# There are here to illustrate that they SHOULD be included in THIS target when they are removed by default.
#

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_BARO
#define USE_BARO_BMP388
#define USE_MAG
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define USE_FLASH
#define USE_FLASH_W25N01G
#define USE_CAMERA_CONTROL
#define USE_MAX7456

#
# Settings usually defined in common_pre.h for non-cloud-builds
# 

board_name SPRACINGH7ZERO
manufacturer_id SPRO

resource BEEPER 1 D07
resource MOTOR 1 A00
resource MOTOR 2 A01
resource MOTOR 3 A02
resource MOTOR 4 A03
resource MOTOR 5 B06
resource MOTOR 6 B07
resource MOTOR 7 C06
resource MOTOR 8 C07
resource PPM 1 B15
resource PWM 1 B15
resource LED_STRIP 1 A08

resource SERIAL_TX 1 B14
resource SERIAL_TX 2 D05
resource SERIAL_TX 3 D08
resource SERIAL_TX 4 D01
resource SERIAL_TX 5 B13
resource SERIAL_TX 6 C06
resource SERIAL_TX 7 NONE
resource SERIAL_TX 8 E01
resource SERIAL_RX 1 B15
resource SERIAL_RX 2 NONE
resource SERIAL_RX 3 D09
resource SERIAL_RX 4 D00
resource SERIAL_RX 5 B05
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 NONE
resource SERIAL_RX 8 E00

resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource I2C_SCL 2 NONE
resource I2C_SDA 2 NONE
resource I2C_SCL 3 NONE
resource I2C_SDA 3 NONE
resource I2C_SCL 4 NONE
resource I2C_SDA 4 NONE

resource LED 1 E03
resource TRANSPONDER 1 B11

resource CAMERA_CONTROL 1 E05

resource ADC_BATT 1 C04
resource ADC_RSSI 1 C00
resource ADC_CURR 1 C01
resource ADC_EXT 1 C05

resource SDIO_CK 1 C12
resource SDIO_CMD 1 D02
resource SDIO_D0 1 C08
resource SDIO_D1 1 C09
resource SDIO_D2 1 C10
resource SDIO_D3 1 C11
resource OSD_CS 1 E11

resource GYRO_EXTI 1 D04
resource GYRO_EXTI 2 E15
resource GYRO_CS 1 A15
resource GYRO_CS 2 B12

#timer
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B11 AF1
# pin B11: TIM2 CH4 (AF1)
timer B15 AF2
# pin B15: TIM12 CH2 (AF2)
timer E05 AF4
# pin E05: TIM15 CH1 (AF4)
timer E06 AF4
# pin E06: TIM15 CH2 (AF4)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer D14 AF2
# pin D14: TIM4 CH3 (AF2)
timer D15 AF2
# pin D15: TIM4 CH4 (AF2)
timer A06 AF2
# pin A06: TIM3 CH1 (AF2)
timer A07 AF2
# pin A07: TIM3 CH2 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)

# dma
dma ADC 1 8
# ADC 1: DMA2 Stream 0 Request 9
dma ADC 3 9
# ADC 3: DMA2 Stream 1 Request 115
dma TIMUP 1 0
# TIMUP 1: DMA1 Stream 0 Request 15
dma TIMUP 2 0
# TIMUP 2: DMA1 Stream 0 Request 22
dma TIMUP 3 0
# TIMUP 3: DMA1 Stream 0 Request 27
dma TIMUP 4 0
# TIMUP 4: DMA1 Stream 0 Request 32
dma TIMUP 5 0
# TIMUP 5: DMA1 Stream 0 Request 59
dma TIMUP 8 2
# TIMUP 8: DMA1 Stream 2 Request 51
dma TIMUP 0 0
# TIMUP 0: DMA1 Stream 0 Request 106
dma pin A08 10
# pin A08: DMA2 Stream 2 Request 11
dma pin B11 11
# pin B11: DMA2 Stream 3 Request 21
dma pin E05 0
# pin E05: DMA1 Stream 0 Request 105
dma pin A00 0
# pin A00: DMA1 Stream 0 Request 55
dma pin A01 1
# pin A01: DMA1 Stream 1 Request 56
dma pin A02 2
# pin A02: DMA1 Stream 2 Request 57
dma pin A03 3
# pin A03: DMA1 Stream 3 Request 58
dma pin B06 4
# pin B06: DMA1 Stream 4 Request 29
dma pin B07 5
# pin B07: DMA1 Stream 5 Request 30
dma pin C06 6
# pin C06: DMA1 Stream 6 Request 47
dma pin C07 7
# pin C07: DMA1 Stream 7 Request 48
dma pin D14 12
# pin D14: DMA2 Stream 4 Request 31
dma pin A06 0
# pin A06: DMA1 Stream 0 Request 23
dma pin A07 0
# pin A07: DMA1 Stream 0 Request 24
dma pin B00 0
# pin B00: DMA1 Stream 0 Request 25
dma pin B01 0
# pin B01: DMA1 Stream 0 Request 26

# feature
feature RX_SERIAL
feature TELEMETRY
feature RSSI_ADC
feature LED_STRIP
feature OSD
feature TRANSPONDER

# master
set mag_bustype = I2C
set mag_i2c_device = 0

set baro_bustype = I2C
set baro_i2c_device = 1

set blackbox_device = SPIFLASH

set gyro_to_use = FIRST
set gyro_1_bustype = SPI
set gyro_1_spibus = 3
set gyro_1_sensor_align = CW180
set gyro_2_bustype = SPI
set gyro_2_spibus = 2
set gyro_2_sensor_align = CW90
set max7456_spi_bus = 4

serial 0 1 115200 57600 0 115200

*/
