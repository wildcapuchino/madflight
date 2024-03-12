/*==============================================================================
Generated on: 2024-03-11 20:33:44.552974
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: PYRODRONEF4PDB
Manufacturer ID: PYDR

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_PYDR-PYRODRONEF4PDB.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-PYDR-PYRODRONEF4PDB"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PB4;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C2)
const int HW_PIN_I2C_SDA  = PB10;
const int HW_PIN_I2C_SCL  = PB11;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB1,PB0,PC9,PA8};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = PC3;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

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
#define HW_SERIAL_COUNT 6
#define HW_PIN_SERIAL { {1,PA9,PA10,PC3}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {2,PB10,PB11} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB1,PB0,PC9,PA8}

//other pins
#define HW_PIN_BEEPER PB5
#define HW_PIN_LED_STRIP PB8
//#define HW_PIN_LED PB4
#define HW_PIN_ESCSERIAL PB9
#define HW_PIN_CAMERA_CONTROL PB9
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_PINIO PA15
#define HW_PIN_PINIO_2 PC15
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_BARO_CS PC14
#define HW_PIN_FLASH_CS PC13

//set statements
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_SPI_DEVICE 2
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_VBAT_SCALE 160
#define HW_SET_IBATA_SCALE 250
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_PID_PROCESS_DENOM 1
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_PINIO_BOX 40,41,255,255
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.1.1 Nov 15 2019 / 12:54:53 (1e5e3d369) MSP API: 1.42

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name PYRODRONEF4PDB
manufacturer_id PYDR

# resources
resource BEEPER 1 B05
resource MOTOR 1 B01
resource MOTOR 2 B00
resource MOTOR 3 C09
resource MOTOR 4 A08
resource LED_STRIP 1 B08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource INVERTER 1 C03
resource LED 1 B04
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource ESCSERIAL 1 B09
resource CAMERA_CONTROL 1 B09
resource ADC_BATT 1 C02
resource ADC_CURR 1 C01
resource PINIO 1 A15
resource PINIO 2 C15
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource BARO_CS 1 C14
resource FLASH_CS 1 C13
resource I2C_SCL 2 B10
resource I2C_SDA 2 B11

# timer
# pin B09: TIM11 CH1 (AF3)
timer B09 AF3           
# pin B01: TIM3 CH4 (AF2)
timer B01 AF2           
# pin B00: TIM8 CH2N (AF3)
timer B00 AF3          
# pin C09: TIM8 CH4 (AF3)
timer C09 AF3          
# pin A08: TIM1 CH1 (AF1)
timer A08 AF1           
# pin B08: TIM4 CH3 (AF2)
timer B08 AF2           

# dma
# ADC 1: DMA2 Stream 4 Channel 0
dma ADC 1 1             
# pin B01: DMA1 Stream 2 Channel 5
dma pin B01 0           
# pin B00: DMA2 Stream 2 Channel 0
dma pin B00 0           
# pin C09: DMA2 Stream 7 Channel 7
dma pin C09 0           
# pin A08: DMA2 Stream 1 Channel 6
dma pin A08 1           
# pin B08: DMA1 Stream 7 Channel 2
dma pin B08 0           

# feature
feature OSD

# aux
# turn on vtx PIT switch 
aux 0 40 255 900 2100 0 0           
# turn on BT module
aux 1 41 255 900 2100 0 0               

# serial
# set up for BT module
serial 3 1 19200 57600 0 115200       


# master
set mag_i2c_device = 2
set baro_spi_device = 2
set blackbox_device = SPIFLASH
set flash_spi_bus = 2
set max7456_spi_bus = 2
set current_meter = ADC
set battery_meter = ADC
set vbat_scale = 160
set ibata_scale = 250
set beeper_inversion = ON
set beeper_od = OFF
set pid_process_denom = 1
set system_hse_mhz = 8
set pinio_box = 40,41,255,255
set gyro_1_bustype = SPI
set gyro_1_spibus = 1

*/
