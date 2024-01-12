/*==============================================================================
Generated on: 2024-01-12 17:04:02.921306
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: NERO
Manufacturer ID: BKMN

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/BKMN-NERO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-BKMN-NERO"
#define HW_MCU "STM32F7X2"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6500

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PB6;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = -1;
const int HW_PIN_IMU_EXTI = PB15;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PA0,PA1,PA2,PA3};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC3;
const int HW_PIN_BAT_I    = -1;

//Include Libraries
#include <Wire.h>                      //I2C communication
#include <SPI.h>                       //SPI communication
#include "src/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 3
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {3,PB10,PB11,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PA0,PA1,PA2,PA3}

//other pins
//#define HW_PIN_LED PB6
#define HW_PIN_LED_2 PB5
#define HW_PIN_LED_3 PB4
#define HW_PIN_beeper_0 P
#define HW_PIN_gyro_cs PC4
#define HW_PIN_GYRO_EXTI PB15
#define HW_PIN_SDCARD_CS PA15
#define HW_PIN_SDCARD_DETECT PD2
#define HW_PIN_LED_STRIP_0 P
#define HW_PIN_PPM_0 P
#define HW_PIN_ADC_BATT PC3
#define HW_PIN_ESCSERIAL PC7

//set statements
#define HW_SET_DSHOT_BURST ON
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW0
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 3
#define HW_SET_BATTERY_METER ADC


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F7X2 (S7X2) 4.0.0

# this will trigger the cloud build system to include these target defines.
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500

board_name NERO
manufacturer_id BKMN

# Basic I/O
resource LED 1 B06
resource LED 2 B05
resource LED 3 B04
resource beeper C1
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource SPI_SCK 1 A05
resource SPI_MISO 1 A06
resource SPI_MOSI 1 A07
resource SPI_SCK 2 B13
resource SPI_MISO 2 B14
resource SPI_MOSI 2 B15
resource SPI_SCK 3 C10
resource SPI_MISO 3 C11
resource SPI_MOSI 3 C12
resource gyro_cs 1 C4
resource GYRO_EXTI 1 B15
resource SDCARD_CS 1 A15
resource SDCARD_DETECT 1 D02
resource MOTOR 1 A0
resource MOTOR 2 A1
resource MOTOR 3 A2
resource MOTOR 4 A3
resource LED_STRIP B0
resource PPM C7
resource SERIAL_TX 1 A9
resource SERIAL_RX 1 A10
resource SERIAL_TX 3 B10
resource SERIAL_RX 3 B11
resource SERIAL_TX 6 C6
resource SERIAL_RX 6 C7
resource ADC_BATT 1 C03
resource ESCSERIAL 1 C07
resource SDCARD_CS 1 A15
resource SDCARD_DETECT 1 D02

# Timers
# First four timers
# timer is zero origin
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin A08 2
# pin A08: DMA2 Stream 3 Channel 6
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6

feature RX_SERIAL

set dshot_burst = ON
set beeper_inversion = ON
set beeper_od = OFF
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW0
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 3
serial 5 64 115200 57600 0 115200
set battery_meter = ADC

*/
