/*==============================================================================
Generated on: 2024-03-11 20:33:43.599624
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: DRONIUSF7
Manufacturer ID: FOSS

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_FOSS-DRONIUSF7.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-FOSS-DRONIUSF7"
#define HW_MCU "STM32F7X2"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0FLIP
#define BARO_I2C_ADR  119
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PC14;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PB0;
const int HW_PIN_IMU_EXTI = PB10;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PA9,PA8,PC8,PC9};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PB7;
const int HW_PIN_RCIN_TX  = PB6;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC1;
const int HW_PIN_BAT_I    = PC0;

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
#define HW_PIN_SERIAL { {1,PB6,PB7,-1}, {2,PA2,PA3,-1}, {3,PC10,PC11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PA9,PA8,PC8,PC9}

//other pins
#define HW_PIN_BEEPER PC13
#define HW_PIN_PPM PB7
#define HW_PIN_LED_STRIP PA15
//#define HW_PIN_LED PC14
#define HW_PIN_ADC_BATT PC1
#define HW_PIN_ADC_CURR PC0
#define HW_PIN_PINIO PC2
#define HW_PIN_FLASH_CS PB2
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PB10
#define HW_PIN_GYRO_CS PB0
#define HW_PIN_USB_DETECT PA10

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_MAG_HARDWARE NONE
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BARO_I2C_ADDRESS 119
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_DSHOT_BURST ON
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 119
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_OSD_DISPLAYPORT_DEVICE MAX7456
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW0FLIP
#define HW_SET_GYRO_1_ALIGN_PITCH 1800
#define HW_SET_PINIO_CONFIG 1,1,1,1
#define HW_SET_PINIO_BOX 40,255,255,255


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F7X2 (S7X2) 4.1.5 Mar 16 2020 / 05:21:46 (d4e74e39c) MSP API: 1.42

board_name DRONIUSF7
manufacturer_id FOSS

# resources
resource BEEPER 1 C13
resource MOTOR 1 A09
resource MOTOR 2 A08
resource MOTOR 3 C08
resource MOTOR 4 C09
resource PPM 1 B07
resource LED_STRIP 1 A15
resource SERIAL_TX 1 B06
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 C10
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 B07
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 C11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 C14
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource ADC_BATT 1 C01
resource ADC_CURR 1 C00
resource PINIO 1 C02
resource FLASH_CS 1 B02
resource OSD_CS 1 B12
resource GYRO_EXTI 1 B10
resource GYRO_CS 1 B00
resource USB_DETECT 1 A10

# timer
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin A09 0
# pin A09: DMA2 Stream 6 Channel 0
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3

# feature
feature RX_SERIAL
feature TELEMETRY
feature LED_STRIP
feature OSD

# serial
serial 0 64 115200 57600 0 115200
serial 2 2048 115200 57600 0 115200

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set mag_hardware = NONE
set baro_bustype = I2C
set baro_i2c_device = 1
set baro_i2c_address = 119
set serialrx_provider = SBUS
set blackbox_device = SPIFLASH
set dshot_burst = ON
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 119
set beeper_inversion = ON
set beeper_od = OFF
set osd_displayport_device = MAX7456
set max7456_spi_bus = 2
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW0FLIP
set gyro_1_align_pitch = 1800
set pinio_config = 1,1,1,1
set pinio_box = 40,255,255,255

*/
