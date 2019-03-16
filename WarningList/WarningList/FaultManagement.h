/**
* @file       FaultManagement.h
* @brief      π‹¿Ìπ ’œ
* @details    /
* @author     Felix Lu
* @date       2018.11.27
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#ifndef FAULTMANAGEMENT_H
#define FAULTMANAGEMENT_H

#include "DataTypes.h"
#include "WarningList.h"

#define MAINS_ABNORMAL    0x0001
#define DIRECTION_ERROR   0x0002
#define REC_ABNORMAL      0x0004
#define CHG_ABNORMAL      0x0008
#define PLL_ABNORMAL      0x0010
#define CURR_LIMIT        0x0020
#define WORKMODE_ABNORMAL 0x0040 

#define NUM_UNKNOWN_FAULT     0
#define NUM_MAINS_ABNORMAL    1
#define NUM_DIRECTION_ERROR   2
#define NUM_REC_ABNORMAL      3
#define NUM_CHG_ABNORMAL      4
#define NUM_PLL_ABNORMAL      5
#define NUM_CURR_LIMIT        6
#define NUM_WORKMODE_ABNORMAL 7 

#define SET_FAULT(Flag, Mask) ((Flag)|(Mask))
#define CLR_FAULT(Flag, Mask) ((Flag)&(~(Mask))) 

class CFaultManagement
{
public:
    CWarningList CurrentWarningList;
    CWarningList HistoryWarningList;

public:
    void Init(void);
}; 

#endif

/// End of File