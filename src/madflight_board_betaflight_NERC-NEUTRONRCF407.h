/*==============================================================================
Generated on: 2024-03-11 20:33:44.479736
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: NEUTRONRCF407
Manufacturer ID: NERC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_NERC-NEUTRONRCF407.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-NERC-NEUTRONRCF407"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_ICM42688P

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW270
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PB5;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB0,PB1,PC9,PC8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = PC13;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC2;
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
#define HW_SERIAL_COUNT 5
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,PC13}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB0,PB1,PC9,PC8}

//other pins
#define HW_PIN_BEEPER PB4
#define HW_PIN_PPM PA3
#define HW_PIN_LED_STRIP PB6
//#define HW_PIN_LED PB5
#define HW_PIN_CAMERA_CONTROL PB7
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_PINIO_2 PB3
#define HW_PIN_FLASH_CS PA15
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_EXTI_2 PA8
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_GYRO_CS_2 PC3
#define HW_PIN_USB_DETECT PC5

//set statements
#define HW_SET_GYRO_TO_USE BOTH
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BARO_HARDWARE BMP280
#define HW_SET_DSHOT_BURST ON
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 100
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_DASHBOARD_I2C_BUS 1
#define HW_SET_PINIO_CONFIG 129,1,1,1
#define HW_SET_PINIO_BOX 0,40,41,42
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270
#define HW_SET_GYRO_2_BUSTYPE SPI
#define HW_SET_GYRO_2_SPIBUS 1


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.0.0 Mar 14 2019 / 11:45:26 (360afd96d) MSP API: 1.41

board_name NEUTRONRCF407
manufacturer_id NERC

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P

# resources
resource BEEPER 1 B04
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 C09
resource MOTOR 4 C08
resource PPM 1 A03
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 6 C07
resource INVERTER 2 C13
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 B05
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource CAMERA_CONTROL 1 B07
resource ADC_CURR 1 C01
resource ADC_BATT 1 C02
resource PINIO 2 B03
resource FLASH_CS 1 A15
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_EXTI 2 A08
resource GYRO_CS 1 A04
resource GYRO_CS 2 C03
resource USB_DETECT 1 C05

# timer
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF3
# pin A02: TIM9 CH1 (AF3)
timer C06 AF2
# pin C06: TIM3 CH1 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
dma pin C06 0
# pin C06: DMA1 Stream 4 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2

# feature
feature RX_SERIAL
feature TELEMETRY
feature LED_STRIP
feature OSD

# serial
serial 0 8192 115200 57600 0 115200
serial 1 64 115200 57600 0 115200

# master
set gyro_to_use = BOTH
set serialrx_provider = SBUS
set mag_bustype = I2C
set mag_i2c_device = 1
set blackbox_device = SPIFLASH
set baro_bustype = I2C
set baro_i2c_device = 1
set baro_hardware = BMP280
set dshot_burst = ON
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 100
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set dashboard_i2c_bus = 1
set pinio_config = 129,1,1,1
set pinio_box = 0,40,41,42
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_2_bustype = SPI
set gyro_2_spibus = 1

*/
