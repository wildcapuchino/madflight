/*==============================================================================
Generated on: 2024-01-12 17:04:03.041671
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: GEPRCF722
Manufacturer ID: GEPR

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/betaflight/GEPR-GEPRCF722.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-GEPR-GEPRCF722"
#define HW_MCU "STM32F7X2"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define IMU_USE  IMU_USE_SPI_ICM42688P
#define BARO_USE  BARO_USE_BMP280
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PA13;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI3)
const int HW_PIN_SPI_MISO = PC11;
const int HW_PIN_SPI_MOSI = PC12;
const int HW_PIN_SPI_SCLK = PC10;
const int HW_PIN_IMU_CS   = PA15;
const int HW_PIN_IMU_EXTI = PC3;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 6;
const int HW_PIN_OUT[]    = {PB4,PB5,PB0,PB1,PB6,PB7};

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
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 2
#define HW_PIN_I2C { {1,PB8,PB9}, {2,PB10,PB11} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 6
#define HW_MOTOR_OUT {PB4,PB5,PB0,PB1,PB6,PB7}

//other pins
#define HW_PIN_BEEPER PC13
#define HW_PIN_PPM PA3
#define HW_PIN_PWM PA2
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PA13
#define HW_PIN_LED_2 PA14
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_RSSI PC2
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_ADC_EXT PA4
#define HW_PIN_PINIO PC8
#define HW_PIN_PINIO_2 PC9
#define HW_PIN_FLASH_CS PB12
#define HW_PIN_OSD_CS PB2
#define HW_PIN_GYRO_EXTI PC3
#define HW_PIN_GYRO_EXTI_2 PC4
#define HW_PIN_GYRO_CS PA15
#define HW_PIN_GYRO_CS_2 PD2
#define HW_PIN_USB_DETECT PC14

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_DSHOT_BURST ON
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 179
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_GPS_PROVIDER UBLOX
#define HW_SET_MAX7456_SPI_BUS 1
#define HW_SET_PINIO_BOX 40,41,255,255
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 3
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_1_ALIGN_YAW 1800
#define HW_SET_GYRO_2_SPIBUS 3


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F7X2 (S7X2) 4.1.7 May 28 2020 / 15:06:20 (9ba02a587) MSP API: 1.42

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name GEPRCF722
manufacturer_id GEPR

# resources
resource BEEPER 1 C13
resource MOTOR 1 B04
resource MOTOR 2 B05
resource MOTOR 3 B00
resource MOTOR 4 B01
resource MOTOR 5 B06
resource MOTOR 6 B07
resource PPM 1 A03
resource PWM 1 A02
resource LED_STRIP 1 A08
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
resource I2C_SCL 1 B08
resource I2C_SCL 2 B10
resource I2C_SDA 1 B09
resource I2C_SDA 2 B11
resource LED 1 A13
resource LED 2 A14
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C02
resource ADC_CURR 1 C01
resource ADC_EXT 1 A04
resource PINIO 1 C08
resource PINIO 2 C09
resource FLASH_CS 1 B12
resource OSD_CS 1 B02
resource GYRO_EXTI 1 C03
resource GYRO_EXTI 2 C04
resource GYRO_CS 1 A15
resource GYRO_CS 2 D02
resource USB_DETECT 1 C14

# timer
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer A02 AF3
# pin A02: TIM9 CH1 (AF3)

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
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin A08 2
# pin A08: DMA2 Stream 3 Channel 6

# feature
feature RX_SERIAL
feature OSD

# serial
serial 0 1 115200 57600 0 115200
serial 1 64 115200 57600 0 115200
serial 5 2 115200 57600 0 115200

# aux
aux 0 0 0 1700 2100 0 0
aux 1 41 3 1800 2100 0 0

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set serialrx_provider = SBUS
set blackbox_device = SPIFLASH
set dshot_burst = ON
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 179
set beeper_inversion = ON
set beeper_od = OFF
set gps_provider = UBLOX
set max7456_spi_bus = 1
set pinio_box = 40,41,255,255
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 3
set gyro_1_sensor_align = CW180
set gyro_1_align_yaw = 1800
set gyro_2_spibus = 3

*/
