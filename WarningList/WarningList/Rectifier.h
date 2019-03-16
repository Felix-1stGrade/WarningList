/**
* @file       Rectifier.h
* @brief      主程序头文件
* @details    /
* @author     Felix Lu
* @date       2018.11.27
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#ifndef RECTIFIER_H
#define RECTIFIER_H

#include "DataTypes.h"
#include "FaultManagement.h"
#include "MainApplication.h"

class CRectifier
{
public:
    INT16 FaultFlag;

public:
    void Init(void);
    void CheckFault(void);
};

#endif

/// End of File