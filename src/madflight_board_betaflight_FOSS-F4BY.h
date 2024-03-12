/*==============================================================================
Generated on: 2024-03-11 20:33:43.603645
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: F4BY
Manufacturer ID: FOSS

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_FOSS-F4BY.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FOSS-F4BY"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BARO_USE  BARO_USE_MS5611
#define BB_USE  BB_USE_SDCARD

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW90
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PE3;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PB0;

//BARO/MAG I2C: (I2C2)
const int HW_PIN_I2C_SDA  = PB10;
const int HW_PIN_I2C_SCL  = PB11;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PA0,PA1,PA2,PA3,PE9,PE11,PE13,PE14};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PB7;
const int HW_PIN_RCIN_TX  = PB6;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PD6;
const int HW_PIN_GPS_TX   = PD5;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC3;
const int HW_PIN_BAT_I    = PC2;

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
#define HW_PIN_SERIAL { {1,PB6,PB7,-1}, {2,PD5,PD6,-1}, {3,PD8,PD9,-1}, {4,PC10,PC11,-1}, {6,PC6,PC7,PD3} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {2,PB10,PB11} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PA0,PA1,PA2,PA3,PE9,PE11,PE13,PE14}

//other pins
#define HW_PIN_BEEPER PE5
#define HW_PIN_PWM PC9
#define HW_PIN_PWM_2 PC8
#define HW_PIN_PWM_3 PC6
#define HW_PIN_PWM_4 PC7
#define HW_PIN_PWM_5 PD15
#define HW_PIN_PWM_6 PD14
#define HW_PIN_PWM_7 PD13
#define HW_PIN_PWM_8 PD12
//#define HW_PIN_LED PE3
#define HW_PIN_LED_2 PE2
#define HW_PIN_LED_3 PE1
#define HW_PIN_ESCSERIAL PA0
#define HW_PIN_ADC_BATT PC3
#define HW_PIN_ADC_RSSI PC1
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_SDCARD_CS PE15
#define HW_PIN_GYRO_EXTI PB0
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_USB_DETECT PA9

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 2
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_BATTERY_METER ADC
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 2
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_DASHBOARD_I2C_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW90
#define HW_SET_GYRO_1_ALIGN_YAW 900


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.2.0 Feb  2 2020 / 16:57:58 (norevision) MSP API: 1.43

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_BARO
#define USE_BARO_MS5611
#define USE_SDCARD

board_name F4BY
manufacturer_id FOSS

# resources
resource BEEPER 1 E05
resource MOTOR 1 A00
resource MOTOR 2 A01
resource MOTOR 3 A02
resource MOTOR 4 A03
resource MOTOR 5 E09
resource MOTOR 6 E11
resource MOTOR 7 E13
resource MOTOR 8 E14
resource PWM 1 C09
resource PWM 2 C08
resource PWM 3 C06
resource PWM 4 C07
resource PWM 5 D15
resource PWM 6 D14
resource PWM 7 D13
resource PWM 8 D12
resource SERIAL_TX 1 B06
resource SERIAL_TX 2 D05
resource SERIAL_TX 3 D08
resource SERIAL_TX 4 C10
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 B07
resource SERIAL_RX 2 D06
resource SERIAL_RX 3 D09
resource SERIAL_RX 4 C11
resource SERIAL_RX 6 C07
resource INVERTER 6 D03
resource I2C_SCL 2 B10
resource I2C_SDA 2 B11
resource LED 1 E03
resource LED 2 E02
resource LED 3 E01
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource ESCSERIAL 1 A00
resource ADC_BATT 1 C03
resource ADC_RSSI 1 C01
resource ADC_CURR 1 C02
resource SDCARD_CS 1 E15
resource GYRO_EXTI 1 B00
resource GYRO_CS 1 A04
resource USB_DETECT 1 A09

# timer
timer C09 AF2
# pin C09: TIM3 CH4 (AF2)
timer C08 AF2
# pin C08: TIM3 CH3 (AF2)
timer C06 AF2
# pin C06: TIM3 CH1 (AF2)
timer C07 AF2
# pin C07: TIM3 CH2 (AF2)
timer D15 AF2
# pin D15: TIM4 CH4 (AF2)
timer D14 AF2
# pin D14: TIM4 CH3 (AF2)
timer D13 AF2
# pin D13: TIM4 CH2 (AF2)
timer D12 AF2
# pin D12: TIM4 CH1 (AF2)
timer A00 AF1
# pin A00: TIM2 CH1 (AF1)
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer E09 AF1
# pin E09: TIM1 CH1 (AF1)
timer E11 AF1
# pin E11: TIM1 CH2 (AF1)
timer E13 AF1
# pin E13: TIM1 CH3 (AF1)
timer E14 AF1
# pin E14: TIM1 CH4 (AF1)
timer E06 AF3
# pin E06: TIM9 CH2 (AF3)

# dma
dma SPI_TX 2 0
# SPI_TX 2: DMA1 Stream 4 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin C09 0
# pin C09: DMA1 Stream 2 Channel 5
dma pin C08 0
# pin C08: DMA1 Stream 7 Channel 5
dma pin C06 0
# pin C06: DMA1 Stream 4 Channel 5
dma pin C07 0
# pin C07: DMA1 Stream 5 Channel 5
dma pin D14 0
# pin D14: DMA1 Stream 7 Channel 2
dma pin D13 0
# pin D13: DMA1 Stream 3 Channel 2
dma pin D12 0
# pin D12: DMA1 Stream 0 Channel 2
dma pin A00 0
# pin A00: DMA1 Stream 5 Channel 3
dma pin A01 0
# pin A01: DMA1 Stream 6 Channel 3
dma pin A02 0
# pin A02: DMA1 Stream 0 Channel 6
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
dma pin E09 0
# pin E09: DMA2 Stream 6 Channel 0
dma pin E11 0
# pin E11: DMA2 Stream 6 Channel 0
dma pin E13 0
# pin E13: DMA2 Stream 6 Channel 0
dma pin E14 0
# pin E14: DMA2 Stream 4 Channel 6

# master
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_bustype = I2C
set baro_i2c_device = 2
set blackbox_device = SDCARD
set battery_meter = ADC
set sdcard_mode = SPI
set sdcard_spi_bus = 2
set system_hse_mhz = 8
set dashboard_i2c_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90
set gyro_1_align_yaw = 900

*/
