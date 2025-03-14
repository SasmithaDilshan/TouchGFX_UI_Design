/*
 * dds.h
 *
 *  Created on: Apr 6, 2024
 *      Author: FYP project
 */

#ifndef INC_DDS_H_
#define INC_DDS_H_

// mandatory includes
#include "stm32f7xx_hal.h"


// defining OPCODES
#define OPCODE_NOP                0x00
#define OPCODE_WRITE_CARRIER_REG  0x02
#define OPCODE_WRITE_MODCONST_REG 0x03
#define OPCODE_WRITE_OFFSET_REG0  0x10
#define OPCODE_WRITE_OFFSET_REG1  0x11
#define OPCODE_WRITE_OFFSET_REG2  0x12
#define OPCODE_WRITE_OFFSET_REG3  0x13
#define OPCODE_WRITE_OFFSET_REG4  0x14
#define OPCODE_WRITE_DDR3         0x04
#define OPCODE_WRITE_BRAM         0x05
#define OPCODE_WRITE_DRAM         0x06

// define some popular frequencies
#define FREQ_100Hz  0x8637bd0ULL
#define FREQ_1KHZ   0x53e2d624ULL
#define FREQ_10KHZ  0x346dc5d64ULL
#define FREQ_100KHZ 0x20c49ba5e3ULL
#define FREQ_200KHZ 0x4189374bc7ULL
#define FREQ_500KHz 0xa3d70a3d71ULL
#define FREQ_1MHZ   0x147ae147ae1ULL
#define FREQ_2MHZ   0x28f5c28f5c3ULL
#define FREQ_5MHZ   0x66666666666ULL
#define FREQ_10MHZ  0xccccccccccdULL
#define FREQ_20MHZ  0x19999999999aULL
#define FREQ_50MHZ  0x400000000000ULL
#define FREQ_100MHZ 0x800000000000ULL
#define FREQ_200MHZ 0x1000000000000ULL
#define FREQ_500MHZ 0x2800000000000ULL

// defining Memory names
#define DDR3 0
#define BRAM 1
#define DRAM 2

// defining global constants
#define f_RUN 156.25E6 // the clock frequency of the FPGA
#define N_SAMPLES 0x1000000000000ULL // 2 ** 48

// this data type will hold the result we get from the configuration. The the result will be compared and select the best
typedef struct {
    uint64_t tune_word; // the tune word that should be send to DDS
    uint64_t offset_0;
    uint64_t offset_1;
    uint64_t offset_2;
    uint64_t offset_3;
    uint32_t samples; // How many samples will be in a single period
    uint8_t mem; // the memory type for the configurations DDR3, BRAM, DRAM
    double freq_act;
} Result;


// function prototypes
HAL_StatusTypeDef write_DDS_register(uint8_t opcode, UART_HandleTypeDef *huart, uint64_t data);
double min_freq(double f_sample);
Result f_to_n(double f_out, double f_sample, uint8_t mem_type);
Result generate_configuration(double f_out);

#endif /* INC_DDS_H_ */
