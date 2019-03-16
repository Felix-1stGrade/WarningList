/**
* @file       FaultManagement.cpp
* @brief      管理故障
* @details    /
* @author     Felix Lu
* @date       2018.11.27
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#include "FaultManagement.h"

/**
* @brief   Init()
* @details 故障管理相关初始化
* @param   /
* @return  /
*/
void CFaultManagement::Init(void)
{
    CurrentWarningList.Init();
    HistoryWarningList.Init();
}

/// End of File