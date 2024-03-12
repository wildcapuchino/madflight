/*==============================================================================
Generated on: 2024-03-11 20:33:43.244286
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: MAMBAF411
Manufacturer ID: DIAT

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_DIAT-MAMBAF411.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-DIAT-MAMBAF411"
#define HW_MCU "STM32F411"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PC13;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PB0;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB3,PB4,PB6,PB7};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = PB10;

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
#include "madflight/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 2
#define HW_PIN_SERIAL { {1,PA9,PA10,PB10}, {2,PA2,PA3,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB3,PB4,PB6,PB7}

//other pins
//#define HW_PIN_LED PC13
#define HW_PIN_LED_2 PC14
#define HW_PIN_BEEPER PB2
#define HW_PIN_GYRO_EXTI PB0
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_OSD_CS PB12
#define HW_PIN_ADC_BATT PA0
#define HW_PIN_ADC_RSSI PB1
#define HW_PIN_ADC_CURR PA1
#define HW_PIN_PPM PB9
#define HW_PIN_LED_STRIP PA8
#define HW_PIN_ESCSERIAL PB9

//set statements
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_ADC_DEVICE 1
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_DSHOT_BURST AUTO
#define HW_SET_DSHOT_BITBANG OFF
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411 (S411) 4.0.4 Jun 30 2019 / 14:58:36 (f3a95efa3) MSP API: 1.41

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_MAX7456

board_name MAMBAF411
manufacturer_id DIAT

# I/O
resource LED 1 C13
resource LED 2 C14
resource BEEPER 1 B02
set beeper_inversion = ON
set beeper_od = OFF

# ACC/GYRO
resource GYRO_EXTI 1 B00
resource GYRO_CS 1 A04
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180

# SPI
resource SPI_SCK 1 A05
resource SPI_MISO 1 A06
resource SPI_MOSI 1 A07

resource SPI_SCK 2 B13
resource SPI_MISO 2 B14
resource SPI_MOSI 2 B15

# OSD
resource OSD_CS 1 B12
set max7456_spi_bus = 2

# ADC
resource ADC_BATT 1 A00
resource ADC_RSSI 1 B01
resource ADC_CURR 1 A01
set adc_device = 1
set current_meter = ADC
set battery_meter = ADC

# SERIAL PORTS
resource SERIAL_TX 1 A09
resource SERIAL_RX 1 A10

resource SERIAL_TX 2 A02
resource SERIAL_RX 2 A03

# TIMERS
timer B09 AF3
# pin B09: TIM11 CH1 (AF3)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer B08 AF3
# pin B08: TIM10 CH1 (AF3)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)

# RESOURCES
resource MOTOR 1 B03
resource MOTOR 2 B04
resource MOTOR 3 B06
resource MOTOR 4 B07
resource PPM 1 B09
resource LED_STRIP 1 A08
resource INVERTER 1 B10
resource ESCSERIAL 1 B09

# DMA
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0

# FEATURE
feature RX_SERIAL
feature SOFTSERIAL
feature TELEMETRY
feature OSD

# SERIAL
serial 0 64 115200 57600 0 115200

# MASTER
set serialrx_provider = SBUS
set dshot_burst = AUTO
set dshot_bitbang = OFF
set motor_pwm_protocol = DSHOT600

*/
