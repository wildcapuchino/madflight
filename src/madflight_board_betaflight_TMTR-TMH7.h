/*==============================================================================
Generated on: 2024-03-11 20:33:44.903153
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: TMH7
Manufacturer ID: TMTR

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_TMTR-TMH7.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-TMTR-TMH7"
#define HW_MCU "STM32H743"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_ICM42688P
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "M25P16"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW270
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = -1;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB6;
const int HW_PIN_I2C_SCL  = PB7;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PA0,PA1,PA2,PA3,PB0,PB1,PC8,PC9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PD6;
const int HW_PIN_GPS_TX   = PD5;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC1;
const int HW_PIN_BAT_I    = PC3;

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
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PD5,PD6,-1}, {3,PD8,PD9,-1}, {4,PD1,PD0,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1}, {7,PE8,PE7,-1}, {8,PE1,PE0,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 4
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PB2}, {4,PE12,PE13,PE14} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB6,PB7} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PA0,PA1,PA2,PA3,PB0,PB1,PC8,PC9}

//other pins
#define HW_PIN_BEEPER PE3
#define HW_PIN_PPM PB9
#define HW_PIN_LED_STRIP PA8
#define HW_PIN_LED_2 PE5
#define HW_PIN_LED_3 PE4
#define HW_PIN_CAMERA_CONTROL PB8
#define HW_PIN_ADC_BATT PC1
#define HW_PIN_ADC_RSSI PC2
#define HW_PIN_ADC_CURR PC3
#define HW_PIN_ADC_EXT PC0
#define HW_PIN_FLASH_CS PA15
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_EXTI_2 PE15
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_GYRO_CS_2 PE11

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 200
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_DASHBOARD_I2C_BUS 1
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270
#define HW_SET_GYRO_1_ALIGN_YAW 1800
#define HW_SET_GYRO_2_SPIBUS 4
#define HW_SET_GYRO_2_SENSOR_ALIGN CW270
#define HW_SET_GYRO_2_ALIGN_YAW 2700


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32H743 (SH74) 4.3.1 Jul 13 2022 / 03:37:48 (8d4f005) MSP API: 1.44

#define USE_ACCGYRO_BMI270
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

board_name TMH7
manufacturer_id TMTR

# resources
resource BEEPER 1 E03
resource MOTOR 1 A00
resource MOTOR 2 A01
resource MOTOR 3 A02
resource MOTOR 4 A03
resource MOTOR 5 B00
resource MOTOR 6 B01
resource MOTOR 7 C08
resource MOTOR 8 C09
resource PPM 1 B09
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 D05
resource SERIAL_TX 3 D08
resource SERIAL_TX 4 D01
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_TX 7 E08
resource SERIAL_TX 8 E01
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 D06
resource SERIAL_RX 3 D09
resource SERIAL_RX 4 D00
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 E07
resource SERIAL_RX 8 E00
resource I2C_SCL 1 B06
resource I2C_SDA 1 B07
resource LED 2 E05
resource LED 3 E04
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_SCK 4 E12
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MISO 4 E13
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B02
resource SPI_MOSI 4 E14
resource CAMERA_CONTROL 1 B08
resource ADC_BATT 1 C01
resource ADC_RSSI 1 C02
resource ADC_CURR 1 C03
resource ADC_EXT 1 C00
resource FLASH_CS 1 A15
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_EXTI 2 E15
resource GYRO_CS 1 A04
resource GYRO_CS 2 E11

# timer
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B08 AF1
# pin B08: TIM16 CH1 (AF1)
timer B09 AF1
# pin B09: TIM17 CH1 (AF1)
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
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)

# dma
dma ADC 1 8
# ADC 1: DMA2 Stream 0 Request 9
dma ADC 3 9
# ADC 3: DMA2 Stream 1 Request 115
dma TIMUP 1 0
# TIMUP 1: DMA1 Stream 0 Request 15
dma TIMUP 3 0
# TIMUP 3: DMA1 Stream 0 Request 27
dma TIMUP 5 0
# TIMUP 5: DMA1 Stream 0 Request 59
dma TIMUP 8 0
# TIMUP 8: DMA1 Stream 0 Request 51
dma pin A08 0
# pin A08: DMA1 Stream 0 Request 11
dma pin B08 0
# pin B08: DMA1 Stream 0 Request 109
dma pin B09 0
# pin B09: DMA1 Stream 0 Request 111
dma pin A00 0
# pin A00: DMA1 Stream 0 Request 55
dma pin A01 0
# pin A01: DMA1 Stream 0 Request 56
dma pin A02 0
# pin A02: DMA1 Stream 0 Request 57
dma pin A03 0
# pin A03: DMA1 Stream 0 Request 58
dma pin B00 0
# pin B00: DMA1 Stream 0 Request 25
dma pin B01 0
# pin B01: DMA1 Stream 0 Request 26
dma pin C08 0
# pin C08: DMA1 Stream 0 Request 49
dma pin C09 0
# pin C09: DMA1 Stream 0 Request 50

# feature
feature TELEMETRY
feature LED_STRIP
feature OSD

# serial
serial 0 1024 115200 57600 0 115200

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 200
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set dashboard_i2c_bus = 1
set flash_spi_bus = 3
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_1_align_yaw = 1800
set gyro_2_spibus = 4
set gyro_2_sensor_align = CW270
set gyro_2_align_yaw = 2700

*/
