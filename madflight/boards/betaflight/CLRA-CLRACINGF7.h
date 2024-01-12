/*==============================================================================
Generated on: 2024-01-12 17:04:02.926305
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: CLRACINGF7
Manufacturer ID: CLRA

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/CLRA-CLRACINGF7.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-CLRA-CLRACINGF7"
#define HW_MCU "STM32F7X2"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6500
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25N01G"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PB0;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 8;
const int HW_PIN_OUT[]    = {PB6,PB7,PB8,PB9,PA1,PC8,PC9,PB1};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

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
#include "src/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 6
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 8
#define HW_MOTOR_OUT {PB6,PB7,PB8,PB9,PA1,PC8,PC9,PB1}

//other pins
#define HW_PIN_BEEPER PB4
#define HW_PIN_LED_STRIP PB1
//#define HW_PIN_LED PB0
#define HW_PIN_RX_BIND PB2
#define HW_PIN_CAMERA_CONTROL PB3
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_RSSI PC3
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_SDCARD_CS PB12
#define HW_PIN_SDCARD_DETECT PC3
#define HW_PIN_PINIO PA14
#define HW_PIN_FLASH_CS PB12
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_EXTI_2 PC14
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_GYRO_CS_2 PC13
#define HW_PIN_USB_DETECT PC5

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_DSHOT_BURST ON
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 250
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_PID_PROCESS_DENOM 1
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 2
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_PINIO_BOX 40,255,255,255
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_2_SPIBUS 1
#define HW_SET_GYRO_2_SENSOR_ALIGN CW90
#define HW_SET_GYRO_2_ALIGN_YAW 900
#define HW_SET_GYRO_TO_USE BOTH
#define HW_SET_PINIO_CONFIG 1,1,1,1
#define HW_SET_MCO2_ON_PC9 ON


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F7X2 (S7X2) 4.1.0 Oct 16 2019 / 00:02:08 (714f27b2d) MSP API: 1.42

#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO_SPI_MPU6000
#define USE_ACC_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G
#define USE_MAX7456

board_name CLRACINGF7
manufacturer_id CLRA

# resources
resource BEEPER 1 B04
resource MOTOR 1 B06
resource MOTOR 2 B07
resource MOTOR 3 B08
resource MOTOR 4 B09
resource MOTOR 5 A01
resource MOTOR 6 C08
resource MOTOR 7 C09
resource MOTOR 8 B01
resource LED_STRIP 1 B01
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
resource LED 1 B00
resource RX_BIND 1 B02
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource CAMERA_CONTROL 1 B03
resource ADC_BATT 1 C02
resource ADC_RSSI 1 C03
resource ADC_CURR 1 C01
resource SDCARD_CS 1 B12
resource SDCARD_DETECT 1 C03
resource PINIO 1 A14
resource FLASH_CS 1 B12
resource OSD_CS 1 A15
resource GYRO_EXTI 1 C04
resource GYRO_EXTI 2 C14
resource GYRO_CS 1 A04
resource GYRO_CS 2 C13
resource USB_DETECT 1 C05

# timer
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer B00 AF1
# pin B00: TIM1 CH2N (AF1)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer C06 AF2
# pin C06: TIM3 CH1 (AF2)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B00 0
# pin B00: DMA2 Stream 6 Channel 0
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin C06 0
# pin C06: DMA1 Stream 4 Channel 5
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin B03 0
# pin B03: DMA1 Stream 6 Channel 3
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7

# feature
feature RX_SERIAL
feature OSD

# serial
serial 4 64 115200 57600 0 115200

# master
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_bustype = I2C
set baro_i2c_device = 1
set serialrx_provider = SBUS
set blackbox_device = SPIFLASH
set dshot_burst = ON
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 250
set beeper_inversion = ON
set beeper_od = OFF
set pid_process_denom = 1
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 2
set max7456_spi_bus = 3
set pinio_box = 39,255,255,255
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_2_spibus = 1
set gyro_2_sensor_align = CW90
set gyro_2_align_yaw = 900
set gyro_to_use = BOTH
set pinio_config = 1,1,1,1
set pinio_box = 40,255,255,255
set mco2_on_pc9 = ON

*/
