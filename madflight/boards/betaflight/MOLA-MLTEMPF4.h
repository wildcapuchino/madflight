/*==============================================================================
Generated on: 2024-01-12 17:04:03.164159
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: MLTEMPF4
Manufacturer ID: MOLA

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/MOLA-MLTEMPF4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-MOLA-MLTEMPF4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define OSD_USE  OSD_USE_MAX7456
#define BB_USE  BB_USE_SDCARD

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PC3;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC5;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB5,PB0,PB3,PB1};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC0;
const int HW_PIN_BAT_I    = PC1;

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
#define HW_SERIAL_COUNT 5
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB5,PB0,PB3,PB1}

//other pins
#define HW_PIN_BEEPER PB4
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PC3
#define HW_PIN_ESCSERIAL PB8
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_SDCARD_CS PB12
#define HW_PIN_SDCARD_DETECT PC13
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_EXTI PC5
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 140
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 2
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_1_ALIGN_YAW 1800


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.1.0 Jul 27 2019 / 18:42:59 (f6870e418) MSP API: 1.42

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_MAX7456
#define USE_SDCARD

board_name MLTEMPF4
manufacturer_id MOLA

# resources
resource BEEPER 1 B04
resource MOTOR 1 B05
resource MOTOR 2 B00
resource MOTOR 3 B03
resource MOTOR 4 B01
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource LED 1 C03
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 B08
resource ADC_BATT 1 C00
resource ADC_CURR 1 C01
resource SDCARD_CS 1 B12
resource SDCARD_DETECT 1 C13
resource OSD_CS 1 A15
resource GYRO_EXTI 1 C05
resource GYRO_CS 1 A04

# timer
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)

# dma
dma SPI_TX 2 0
# SPI_TX 2: DMA1 Stream 4 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A02 0
# pin A02: DMA1 Stream 0 Channel 6
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2

# feature
feature OSD

# master
set blackbox_device = SDCARD
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 140
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 2
set system_hse_mhz = 8
set max7456_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180
set gyro_1_align_yaw = 1800

*/
