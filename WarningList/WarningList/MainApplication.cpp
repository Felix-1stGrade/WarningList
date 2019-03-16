/**
* @file       MainApplication.cpp
* @brief      ������
* @details    /
* @author     Felix Lu
* @date       2018.11.27
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#include "MainApplication.h"

CRectifier Rec;
CFaultManagement FaultManager;

/**
* @brief   main()
* @details App������
* @param   /
* @return  /
*/
void main(void)
{
    FaultManager.Init();
    Rec.Init();
    Rec.CheckFault();

}

/// End of File