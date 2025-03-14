/*
 * dds.c
 *
 *  Created on: Apr 6, 2024
 *      Author: FYP project
 */

#include "dds.h"
#include <math.h>

const double tune_dict_freq[3] = {50e6, 400e6, 1000e6};
const uint8_t  tune_dict_samp[3] = {20, 12, 6};

HAL_StatusTypeDef write_DDS_register(uint8_t opcode, UART_HandleTypeDef *huart, uint64_t data){
	/*
	 * This function will be used to update the registers in the DDS chains
	 * opcode : give the opcode as a uint8_t integer
	 * *huart : give the uart port
	 * data   : give the 48 bit integer as a 64 bit integer
	 * */

	uint8_t data_buffer[17]; // the full data buffer to be sent
	uint8_t temp_data; // cannot send 48 bit. This will hold the splitted 8 bit value
	HAL_StatusTypeDef transmit_status;

	data_buffer[16] = opcode; // send the opcode first

	for (size_t i = 0; i < 6; ++i){
		temp_data = (uint8_t)(data >> (i * 8)); // get the 8 LSb s
		data_buffer[10 + i] = temp_data; // adding the data to the array
	} // end of the for loop

	// transmit the signal
	transmit_status = HAL_UART_Transmit(huart, data_buffer, sizeof(data_buffer),150);

	return transmit_status;
} // end of the write DDS register

double min_freq(double f_sample){
    // this function will return the minimum frequency can be achived with this samples
    return f_sample / N_SAMPLES;
} // end of the minimum frequency calculation

Result f_to_n(double f_out, double f_sample, uint8_t mem_type){
    double n = (f_out/f_sample) * N_SAMPLES;
    double samples = N_SAMPLES / n;
    double tune_float = n * tune_dict_freq[mem_type] / f_RUN;

    Result res;
    res.tune_word = (uint64_t)round(tune_float);
//    res.offset_0 = (uint64_t)round(tune_float/4);
    res.offset_1 = (uint64_t)round(tune_float/2);
    res.offset_2 = (uint64_t)round(2*tune_float/4);
    res.offset_3 = (uint64_t)round(3*tune_float/4);
    res.samples = (uint32_t)round(fmin(samples, pow(2,tune_dict_samp[mem_type])));
    res.freq_act = res.tune_word * f_RUN / N_SAMPLES;

    return res; // returning the result
} // end of freq to n

Result generate_configuration(double f_out){
    Result results[3]; // the results will be stored here
    Result result;
    uint32_t max_samples = 0;
    uint8_t max_sample_index = 0;
    double min_fr_comp;
    double max_fr_comp;

    for(uint8_t mem_type = 0; mem_type < 3; mem_type ++){

        min_fr_comp = min_freq(tune_dict_freq[mem_type]);
        max_fr_comp = (2 * tune_dict_freq[mem_type]);

        if (min_fr_comp < f_out && f_out < max_fr_comp){
            result = f_to_n(f_out, tune_dict_freq[mem_type], mem_type);

            if (result.samples > 2){
                // now this is a valid result
                result.mem = mem_type;
                results[mem_type] = result; // adding the result to the array

                if(result.samples > max_samples){
                    max_samples = result.samples;
                    max_sample_index = mem_type;
                }

            } // end of if
        } // end of if statement

    } // end of the for loop

    return results[max_sample_index]; // returning the result

} // end of generate configuration
