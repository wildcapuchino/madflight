/*==============================================================================
Generated on: 2024-01-12 17:04:03.197293
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: HYBRIDG4
Manufacturer ID: NERC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/NERC-HYBRIDG4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-NERC-HYBRIDG4"
#define HW_MCU "STM32G47X"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PC15;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PA15;
const int HW_PIN_I2C_SCL  = PB7;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB0,PB1,PB2,PB3};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PA0;
const int HW_PIN_BAT_I    = PA1;

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
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PA15,PB7} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB0,PB1,PB2,PB3}

//other pins
#define HW_PIN_BEEPER PC14
#define HW_PIN_PPM PA2
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PC15
#define HW_PIN_ESCSERIAL PC6
#define HW_PIN_CAMERA_CONTROL PB6
#define HW_PIN_ADC_BATT PA0
#define HW_PIN_ADC_CURR PA1
#define HW_PIN_FLASH_CS PB9
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_LED_INVERSION 1
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_PID_PROCESS_DENOM 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_ALIGN_YAW 2700


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32G47X (SG47) 4.3.0 Apr 27 2021 / 03:49:09 (e228d797c) MSP API: 1.44

board_name HYBRIDG4
manufacturer_id NERC

# resources
resource BEEPER 1 C14
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 B02
resource MOTOR 4 B03
resource PPM 1 A02
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource I2C_SCL 1 A15
resource I2C_SDA 1 B07
resource LED 1 C15
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource ESCSERIAL 1 C06
resource CAMERA_CONTROL 1 B06
resource ADC_BATT 1 A00
resource ADC_CURR 1 A01
resource FLASH_CS 1 B09
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B02 AF2
# pin B02: TIM5 CH1 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer A08 AF6
# pin A08: TIM1 CH1 (AF6)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer A02 AF9
# pin A02: TIM15 CH1 (AF9)

# dma
dma ADC 1 12
# ADC 1: DMA2 Channel 5 Request 5
dma ADC 4 0
# ADC 4: DMA1 Channel 1 Request 38
dma ADC 5 0
# ADC 5: DMA1 Channel 1 Request 39
dma TIMUP 3 0
# TIMUP 3: DMA1 Channel 1 Request 65
dma TIMUP 4 0
# TIMUP 4: DMA1 Channel 1 Request 71
dma TIMUP 5 0
# TIMUP 5: DMA1 Channel 1 Request 76
dma pin B00 0
# pin B00: DMA1 Channel 1 Request 63
dma pin B01 1
# pin B01: DMA1 Channel 2 Request 64
dma pin B02 2
# pin B02: DMA1 Channel 3 Request 72
dma pin B03 3
# pin B03: DMA1 Channel 4 Request 57
dma pin A08 8
# pin A08: DMA2 Channel 1 Request 42
dma pin B06 0
# pin B06: DMA1 Channel 1 Request 67
dma pin A02 0
# pin A02: DMA1 Channel 1 Request 78

# serial
serial 0 2048 115200 57600 0 115200
serial 1 64 115200 57600 0 115200
serial 2 1024 115200 57600 0 115200

# master
set baro_bustype = I2C
set baro_i2c_device = 1
set blackbox_device = SPIFLASH
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set led_inversion = 1
set flash_spi_bus = 3
set pid_process_denom = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_align_yaw = 2700

*/
