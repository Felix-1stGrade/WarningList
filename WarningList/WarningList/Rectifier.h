/*===========================================================================
* File        : Rectifier.h
* Description : ...
* Author      : Felix Lu
* Date        : 2018.11.27
===========================================================================*/
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
//===========================================================================
// End of File
//===========================================================================