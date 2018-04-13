/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

static void sd_mmc_ready() ;

int main (void)
{
	system_init();
	
	//delay_ms(100);
	printf("System initialised successfully\n");
	
	
	FRESULT res;
	FATFS fs;
	
		//while(1)
		//{
			//printf("tick %d \n", readButton());
			//delay_ms(1000);
			//printf("tock %d \n", readButton());
			//delay_ms(1000);
		//}
	
	/* Wait card present and ready */
	sd_mmc_ready();
	memset(&fs, 0, sizeof(FATFS));
	res = f_mount(LUN_ID_SD_MMC_0_MEM, &fs);
	if (FR_INVALID_DRIVE == res)
	{	
		printf("[FAIL] Mounting SD card failed result= %d\r\n", res);
	
	}
	
	
	while(1)
	{
		printf("tick %d \n", readButton());
		delay_ms(1000);
		printf("tock %d \n", readButton());
		delay_ms(1000);
	}
}


/**
 * \brief waits till sd card is ready
 *
 * This function will wait, indefinitely till SD card is ready for access.
 *  
 */
static void sd_mmc_ready() 
{
	
	printf("Waiting for SD card to be present...\n");
	delay_ms(100);
	
	Ctrl_status status = CTRL_FAIL;
	do {
		status = sd_mmc_test_unit_ready(0);
		
		printf("Status: %d\n", (int)status);
		
		if (CTRL_FAIL == status)
		{
			printf("[SD Card install FAILED]\n\r");
			printf("Please unplug and re-plug the card!!!\n\r");
			while (CTRL_NO_PRESENT != sd_mmc_check(0)) {}
		}
		else if (CTRL_NO_PRESENT == status)
		{
			
			printf("No SD card detected\n");
		}
	} while (CTRL_GOOD != status);
	printf("SD Card Detection successful...\r\n");
}