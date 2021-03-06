/*
* Configuration of module: Can (Can_PBcfg.c)
*
* Created by:              
* Copyright:               
*
* Configured for (MCU):    MPC5567
*
* Module vendor:           ArcCore
* Generator version:       2.0.4
*
* Generated by Arctic Studio (http://arccore.com) 
*/

	

#include <stdlib.h>
#include "Can.h"
#include "CanIf_Cbk.h"

Can_FilterMaskType Can_FilterMaskConfigData_Controller_1_Mask_1 = 0x0;
Can_FilterMaskType Can_FilterMaskConfigData_FULLMask = 0x1FFFFFFF;



const Can_HardwareObjectType CanHardwareObjectConfig_Controller_1[] = {
	{
		.CanObjectId =				HWObj_1,
		.CanIdType =				CAN_ID_TYPE_STANDARD,
		.CanIdValue = 				0x0,
		.CanObjectType =			CAN_OBJECT_TYPE_RECEIVE,
		.CanFilterMaskRef =			&Can_FilterMaskConfigData_Controller_1_Mask_1,
		
		.Can_Arc_Flags =			(0),
		
		
		/* Mailbox(es): 8 */
		.ArcMailboxMask = 0x100ULL ,
	},
	{
		.CanObjectId =				HWObj_2,
		.CanIdType =				CAN_ID_TYPE_STANDARD,
		.CanIdValue = 				0x0,
		.CanObjectType =			CAN_OBJECT_TYPE_TRANSMIT,
		.CanFilterMaskRef =			0,
		
		.Can_Arc_Flags =			(0),
		
		
		/* Mailbox(es): 9 */
		.ArcMailboxMask = 0x200ULL ,
	},
};

PduIdType  Can_swPduHandles_Controller_1[1];

// NEW
const uint8 Can_MailBoxToHrh_Controller_1[]= {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0, 
	HWObj_1,
};



const Can_ControllerConfigType CanControllerConfigData[] =
{  
  {
    .CanControllerActivation =	TRUE,
    .CanControllerBaudRate =	125,
    .CanControllerId =			FLEXCAN_A,
    .CanControllerPropSeg =		4,
    .CanControllerSeg1 =		4,
    .CanControllerSeg2 =		4,
    .Can_Arc_Flags =			(CAN_CTRL_BUSOFF_PROCESSING_INTERRUPT | CAN_CTRL_RX_PROCESSING_INTERRUPT | CAN_CTRL_TX_PROCESSING_INTERRUPT | CAN_CTRL_WAKEUP_PROCESSING_INTERRUPT | CAN_CTRL_ERROR_PROCESSING_INTERRUPT | CAN_CTRL_ACTIVATION),
    .CanCpuClockRef =			PERIPHERAL_CLOCK_FLEXCAN_A,
    .Can_Arc_Hoh =				&CanHardwareObjectConfig_Controller_1[0],
    .Can_Arc_HohCnt =			2,
    .Can_Arc_HohFifoCnt = 		0,
    .Can_Arc_RxMailBoxMask =    0x100ULL,
    .Can_Arc_TxMailBoxMask =    0x200ULL,
    .Can_Arc_TxMailboxStart =   9,
    .Can_Arc_MailBoxToHrh =     Can_MailBoxToHrh_Controller_1,
    .Can_Arc_TxPduHandles =     Can_swPduHandles_Controller_1,
    .Can_Arc_MailboxMax  =      10,
  },
};

const uint8 Can_HthToUnit[] = {
     [HWObj_2] = 0,
};

const uint8 Can_HthToHohMap[] = {
     [HWObj_2] = 1,
};

const uint8 Can_CtrlToUnit[] = {
     [FLEXCAN_A] = 0,
};

const Can_CallbackType CanCallbackConfigData = {
    NULL, //CanIf_CancelTxConfirmation,
    CanIf_RxIndication,
    CanIf_ControllerBusOff,
    CanIf_TxConfirmation,
    NULL, //CanIf_ControllerWakeup,
    CanIf_Arc_Error,
};

const Can_ConfigSetType CanConfigSetData =
{
  .CanController =	CanControllerConfigData,
  .CanCallbacks =	&CanCallbackConfigData,
  .ArcHthToUnit =   Can_HthToUnit,
  .ArcHthToHoh =    Can_HthToHohMap,
  .ArcCtrlToUnit =  Can_CtrlToUnit,
};

const Can_ConfigType CanConfigData = {
  .CanConfigSet =	&CanConfigSetData,
};

