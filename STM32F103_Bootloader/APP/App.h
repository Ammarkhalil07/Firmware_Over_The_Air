/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Ammar Khalil
 *  File:  Application.h
 *  Module:  Application
 *  Description:  Application Interface File
*******************************************************************/
#ifndef _APP_H_
#define _APP_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Bootloader.h"
#include "GPIO.h"
#include "Macros.h"
#include "FLASH.h"
#include "CRC.h"
/*****************************************
---  Application Programming Interface  --
*****************************************/
/*****************************************************************************************
* Function Name   : System_Initialization
* Description     : Initializes the system components including LED pins and the bootloader.
* Parameters (in) : None
* Parameters (out): None
* Return value    : None
*****************************************************************************************/
void System_Initialization(void);
/*****************************************************************************************
* Function Name   : Test
* Description     : Tests the application by indicating that the bootloader is running.
* Parameters (in) : None
* Parameters (out): None
* Return value    : None
*****************************************************************************************/
void Test(void);
/********************************************************************
 *  END OF FILE:  Application.h
********************************************************************/
#endif
