/*==============================================================================
Generated on: 2024-03-11 20:33:43.791614
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: TAKERG4AIO
Manufacturer ID: GEPR

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_GEPR-TAKERG4AIO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-GEPR-TAKERG4AIO"
#define HW_MCU "STM32G47X"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define IMU_USE  IMU_USE_SPI_ICM42688P
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW270
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PB7;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PB0;
const int HW_PIN_IMU_EXTI = PA4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PA13;
const int HW_PIN_I2C_SCL  = PA14;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PA0,PA1,PA2,PA3};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PB4;
const int HW_PIN_GPS_TX   = PB3;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PB2;
const int HW_PIN_BAT_I    = PB1;

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
#define HW_SERIAL_COUNT 5
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PB3,PB4,-1}, {3,PB9,-1,-1}, {4,PC10,PC11,-1}, {11,PB10,PB11,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PA13,PA14} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PA0,PA1,PA2,PA3}

//other pins
#define HW_PIN_BEEPER PA15
#define HW_PIN_LED_STRIP PB6
//#define HW_PIN_LED PB7
#define HW_PIN_ADC_BATT PB2
#define HW_PIN_ADC_CURR PB1
#define HW_PIN_FLASH_CS PC6
#define HW_PIN_OSD_CS PA8
#define HW_PIN_GYRO_EXTI PA4
#define HW_PIN_GYRO_CS PB0

//set statements
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 120
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_ALIGN_BOARD_YAW 45
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32G47X (SG47) 4.5.0 Feb 21 2023 / 01:24:44 (d98740b) MSP API: 1.45

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name TAKERG4AIO 
manufacturer_id GEPR

# resources1
resource BEEPER 1 A15
resource MOTOR 1 A00
resource MOTOR 2 A01
resource MOTOR 3 A02
resource MOTOR 4 A03
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 B03
resource SERIAL_TX 3 B09
resource SERIAL_TX 4 C10
resource SERIAL_TX 11 B10
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 B04
resource SERIAL_RX 4 C11
resource SERIAL_RX 11 B11
resource I2C_SCL 1 A13
resource I2C_SDA 1 A14
resource LED 1 B07
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource ADC_BATT 1 B02
resource ADC_CURR 1 B01
resource FLASH_CS 1 C06
resource OSD_CS 1 A08
resource GYRO_EXTI 1 A04
resource GYRO_CS 1 B00

# timer
timer A00 AF1
# pin A00: TIM2 CH1 (AF1)
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer B06 AF5
# pin B06: TIM8 CH1 (AF5)

# dma
dma ADC 1 1
# ADC 1: DMA1 Channel 2 Request 5
dma ADC 2 8
# ADC 2: DMA2 Channel 1 Request 36
dma TIMUP 2 0
# TIMUP 2: DMA1 Channel 1 Request 60
dma TIMUP 8 0
# TIMUP 8: DMA1 Channel 1 Request 53
dma pin A00 1
# pin A00: DMA1 Channel 2 Request 56
dma pin A01 2
# pin A01: DMA1 Channel 3 Request 57
dma pin A02 3
# pin A02: DMA1 Channel 4 Request 58
dma pin A03 4
# pin A03: DMA1 Channel 5 Request 59
dma pin B06 9
# pin B06: DMA2 Channel 2 Request 49

# feature
feature RX_SERIAL
feature TELEMETRY
feature OSD
feature AIRMODE


# master
set blackbox_device = SPIFLASH
set max7456_spi_bus = 2
set beeper_inversion = ON
set beeper_od = OFF
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 120
set flash_spi_bus = 2 
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set align_board_yaw = 45
set gyro_1_sensor_align = CW270

*/
