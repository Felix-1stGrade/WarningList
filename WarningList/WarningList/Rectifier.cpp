/**
* @file       Rectifier.cpp
* @brief      整流器
* @details    /
* @author     Felix Lu
* @date       2018.11.13
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#include "Rectifier.h"

/**
* @brief   Init()
* @details 整流器相关变量初始化
* @param   /
* @return  /
*/
void CRectifier::Init(void)
{
	FaultFlag = 0;
}

/**
* @brief   CheckFault()
* @details 故障检测
* @param   /
* @return  /
*/
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

/// End of File