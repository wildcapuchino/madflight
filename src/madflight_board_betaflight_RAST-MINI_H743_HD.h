/*==============================================================================
Generated on: 2024-03-11 20:33:44.571652
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: MINI_H743_HD
Manufacturer ID: RAST

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_RAST-MINI_H743_HD.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-RAST-MINI_H743_HD"
#define HW_MCU "STM32H743"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BARO_USE  BARO_USE_BMP280
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PE2;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PB2;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PD12,PD13,PB0,PB1,PC8,PC9,PB4,PB5};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
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
#define HW_SERIAL_COUNT 7
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {6,-1,PC7,-1}, {7,PE8,PE7,-1}, {8,PE1,PE0,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 4
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12}, {4,PE12,PE13,PE14} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 2
#define HW_PIN_I2C { {1,PB8,PB9}, {2,PB10,PB11} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PD12,PD13,PB0,PB1,PC8,PC9,PB4,PB5}

//other pins
#define HW_PIN_BEEPER PB3
#define HW_PIN_PPM PA3
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PE2
#define HW_PIN_LED_2 PE3
#define HW_PIN_CAMERA_CONTROL PD9
#define HW_PIN_ADC_BATT PC3
#define HW_PIN_ADC_RSSI PC5
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_ADC_EXT PC1
#define HW_PIN_PINIO PD9
#define HW_PIN_PINIO_2 PD11
#define HW_PIN_FLASH_CS PB12
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_EXTI PB2
#define HW_PIN_GYRO_EXTI_2 PE15
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_GYRO_CS_2 PE11

//set statements
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 250
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_PINIO_BOX 40,41,255,255
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_1_ALIGN_YAW 1800
#define HW_SET_GYRO_2_SPIBUS 4
#define HW_SET_GYRO_2_SENSOR_ALIGN CW0FLIP
#define HW_SET_GYRO_2_ALIGN_PITCH 1800


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32H743 (SH74) 4.3.0 Apr 15 2022 / 10:19:04 (9360ab1) MSP API: 1.44

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name MINI_H743_HD
manufacturer_id RAST

# resources
resource BEEPER 1 B03
resource MOTOR 1 D12
resource MOTOR 2 D13
resource MOTOR 3 B00
resource MOTOR 4 B01
resource MOTOR 5 C08
resource MOTOR 6 C09
resource MOTOR 7 B04
resource MOTOR 8 B05
resource PPM 1 A03
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 7 E08
resource SERIAL_TX 8 E01
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 E07
resource SERIAL_RX 8 E00
resource I2C_SCL 1 B08
resource I2C_SCL 2 B10
resource I2C_SDA 1 B09
resource I2C_SDA 2 B11
resource LED 1 E02
resource LED 2 E03
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
resource SPI_MOSI 3 C12
resource SPI_MOSI 4 E14
resource CAMERA_CONTROL 1 D09
resource ADC_BATT 1 C03
resource ADC_RSSI 1 C05
resource ADC_CURR 1 C02
resource ADC_EXT 1 C01
resource PINIO 1 D09
resource PINIO 2 D11
resource FLASH_CS 1 B12
resource OSD_CS 1 A15
resource GYRO_EXTI 1 B02
resource GYRO_EXTI 2 E15
resource GYRO_CS 1 A04
resource GYRO_CS 2 E11

# timer
timer D12 AF2
# pin D12: TIM4 CH1 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer E09 AF1
# pin E09: TIM1 CH1 (AF1)
timer E11 AF1
# pin E11: TIM1 CH2 (AF1)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer E13 AF1
# pin E13: TIM1 CH3 (AF1)
timer E14 AF1
# pin E14: TIM1 CH4 (AF1)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer D13 AF2
# pin D13: TIM4 CH2 (AF2)
timer D14 AF2
# pin D14: TIM4 CH3 (AF2)
timer D15 AF2
# pin D15: TIM4 CH4 (AF2)
timer E05 AF4
# pin E05: TIM15 CH1 (AF4)
timer E06 AF4
# pin E06: TIM15 CH2 (AF4)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)

# dma
dma ADC 1 8
# ADC 1: DMA2 Stream 0 Request 9
dma ADC 2 9
# ADC 2: DMA2 Stream 1 Request 10
dma ADC 3 10
# ADC 3: DMA2 Stream 2 Request 115
dma TIMUP 1 0
# TIMUP 1: DMA1 Stream 0 Request 15
dma TIMUP 2 0
# TIMUP 2: DMA1 Stream 0 Request 22
dma TIMUP 3 0
# TIMUP 3: DMA1 Stream 0 Request 27
dma TIMUP 5 0
# TIMUP 5: DMA1 Stream 0 Request 59
dma TIMUP 8 4
# TIMUP 8: DMA1 Stream 4 Request 51
dma pin D12 6
# pin D12: DMA1 Stream 6 Request 29
dma pin A03 1
# pin A03: DMA1 Stream 1 Request 58
dma pin C08 0
# pin C08: DMA1 Stream 0 Request 49
dma pin B00 0
# pin B00: DMA1 Stream 0 Request 25
dma pin B01 1
# pin B01: DMA1 Stream 1 Request 26
dma pin E09 0
# pin E09: DMA1 Stream 0 Request 11
dma pin E11 0
# pin E11: DMA1 Stream 0 Request 12
dma pin B04 4
# pin B04: DMA1 Stream 4 Request 23
dma pin B05 5
# pin B05: DMA1 Stream 5 Request 24
dma pin E13 6
# pin E13: DMA1 Stream 6 Request 13
dma pin E14 7
# pin E14: DMA1 Stream 7 Request 14
dma pin A00 2
# pin A00: DMA1 Stream 2 Request 55
dma pin A01 4
# pin A01: DMA1 Stream 4 Request 56
dma pin A02 0
# pin A02: DMA1 Stream 0 Request 57
dma pin D13 7
# pin D13: DMA1 Stream 7 Request 30
dma pin D14 12
# pin D14: DMA2 Stream 4 Request 31
dma pin E05 0
# pin E05: DMA1 Stream 0 Request 105
dma pin A08 14
# pin A08: DMA2 Stream 6 Request 11
dma pin A15 0
# pin A15: DMA1 Stream 0 Request 18

# feature
feature RX_SERIAL
feature TELEMETRY
feature OSD

# master
set mag_i2c_device = 2
set baro_bustype = I2C
set baro_i2c_device = 1
set serialrx_provider = SBUS
set blackbox_device = SPIFLASH
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 250
set max7456_spi_bus = 3
set pinio_box = 40,41,255,255
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180
set gyro_1_align_yaw = 1800
set gyro_2_spibus = 4
set gyro_2_sensor_align = CW0FLIP
set gyro_2_align_pitch = 1800

*/
