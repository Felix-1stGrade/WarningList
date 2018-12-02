/*===========================================================================
* File        : Rectifier.cpp
* Description : ...
* Author      : Felix Lu
* Date        : 2018.12.1
===========================================================================*/
#include "Rectifier.h"

void CRectifier::Init(void)
{
	FaultFlag = 0;
}

void CRectifier::CheckFault(void)
{
    FaultFlag = SET_FAULT(FaultFlag, MAINS_ABNORMAL);
    FaultManager.CurrentWarningList.Append(NUM_MAINS_ABNORMAL);

    FaultFlag = SET_FAULT(FaultFlag, REC_ABNORMAL);
    FaultManager.CurrentWarningList.Append(NUM_REC_ABNORMAL);

    FaultFlag = SET_FAULT(FaultFlag, CHG_ABNORMAL);
    FaultManager.CurrentWarningList.Append(NUM_CHG_ABNORMAL);

    FaultFlag = SET_FAULT(FaultFlag, PLL_ABNORMAL);
    FaultManager.CurrentWarningList.Append(NUM_PLL_ABNORMAL);

    FaultFlag = SET_FAULT(FaultFlag, CURR_LIMIT);
    FaultManager.CurrentWarningList.Append(NUM_CURR_LIMIT);

    FaultFlag = SET_FAULT(FaultFlag, WORKMODE_ABNORMAL);
    FaultManager.CurrentWarningList.Append(NUM_WORKMODE_ABNORMAL);

    //FaultFlag = 0;
    //FaultManager.CurrentWarningList.Init();
}

//===========================================================================
// End of File
//===========================================================================