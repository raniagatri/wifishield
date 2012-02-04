/*
 * ard_spi.h
 *
 *  Created on: May 27, 2010
 *      Author: mlf by Metodo2 srl
 */

#ifndef ARD_SPI_H_
#define ARD_SPI_H_

#include "lwip/netif.h"
#include "console.h"
#include "wl_definitions.h"


typedef enum {
		SPI_CMD_IDLE,
		SPI_CMD_INPUT,
        SPI_CMD_DONE,
        SPI_CMD_INPROGRESS,
        SPI_CMD_REPLING,
        SPI_CMD_FAIL,
} cmd_spi_state_t;

typedef enum {
		REPLY_ERR_GET,
		REPLY_ERR_SET,
		REPLY_ERR_CMD,
		REPLY_ERR_MSG,
        REPLY_NO_ERR,
} reply_err_t;


typedef enum {
	CMD_GET_FLAG = 0x01,
	CMD_SET_FLAG = 0x02,
	CMD_IMM_SET_FLAG = 0x04,
}cmd_flags;

#define TIMEOUT_SPI  	200
//#define TIMEOUT_SENT_REPLY 1000
#define MAX_CMD_PIPE_SIZE	5
#define DUMMY_DATA	0xFF

typedef int (*cmd_spi_cb_t)(int numParam, char* buf, void* ctx);
typedef cmd_spi_state_t (*cmd_spi_rcb_t)(char* recv, char* reply, void* ctx, uint16_t* _count);

#ifdef _APP_DEBUG_
#define PRINT_STATS_SPI() do { printStatSpi(); }while(0);
#else
#define PRINT_STATS_SPI() do { }while(0);
#endif

void set_result_cmd(int err) ;

void set_result(wl_status_t _status);

int initSpi(void);

void initExtInt();

void spi_poll(struct netif* netif);

int spi_slaveReceive(volatile avr32_spi_t *spi);

cmd_state_t cmd_statSpi(int argc, char* argv[], void* ctx);

cmd_state_t cmd_resetStatSpi(int argc, char* argv[], void* ctx);

#endif /* ARD_SPI_H_ */