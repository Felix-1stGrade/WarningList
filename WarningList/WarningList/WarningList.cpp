/**
* @file       WarningList.cpp
* @brief      告警列表
* @details    用队列实现告警列表
* @note       数组队列的长度不能在运行中确定大小,如果数组队列的元素数据的类型发生变化，数组队列类型需要修改
* @author     Felix Lu
* @date       2018.11.13
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#include "WarningList.h"

/**
* @brief   Init()
* @details 初始化告警列表
* @param   /
* @return  操作状态
*/
INT16 CWarningList::Init(void)
{
    for (INT16 i = 0; i<LIST_CAPACITY; i++)
    {
        Data[i] = 0;
    }
	   
    Front = -1;
    Rear = -1;
    Length = 0;
    Capacity = LIST_CAPACITY;

    return WL_SUCCESS;
}

/**
* @brief   Append()
* @details 新增告警条目到列表最后
* @param   x 要增加的告警条目
* @return  操作状态
*/
INT16 CWarningList::Append(TListElem x)
{
    if (Length >= Capacity)
    {
        return WL_FULL;
    }

    for (INT16 i = 0; i<Length; i++)
    {
        if (Data[(Front + 1 + i) % Capacity] == x)
        {
            return WL_FAIL;
        }
    }
	   
    Rear = (Rear + 1) % Capacity;
    Data[Rear] = x;
    Length++; 

    return WL_SUCCESS;
}

/**
* @brief   Delete()
* @details 读取并删除列表中的告警条目
* @param   *y 删除并取出的告警条目
* @return  操作状态
*/
INT16 CWarningList::Delete(TListElem *y)
{
    if (y == nullptr)
    {
        return WL_FAIL;
    }

    if (Length <= 0)
    {
        return WL_EMPTY;
    }

    Length--;
    Front = (Front + 1) % Capacity;
    *y = Data[Front];
	
    return WL_SUCCESS;
}
 
/**
* @brief   GetLength()
* @details 获取列表中的条目数量
* @param   /
* @return  列表中的告警条目数量
*/
INT16 CWarningList::GetLength(void)
{
    return Length;
}

/**
* @brief   GetHead()
* @details 读取列表中的第一个条目，不删除
* @param   *y 读取的条目
* @return  操作状态
*/
INT16 CWarningList::GetHead(TListElem *y)
{
    if (y == nullptr)
    {
        return WL_FAIL;
    }

    if (Length <= 0)
    {
        return WL_EMPTY;
    }

    *y = Data[(Front + 1) % Capacity];

    return WL_SUCCESS;
} 

/**
* @brief   Get()
* @details 读取列表中指定序号的条目，不删除，Index从1开始
* @param   *y 读取的告警条目
* @param   Index 告警条目序号
* @return  操作状态
*/
INT16 CWarningList::Get(TListElem *y, INT16 Index)
{
    if ((y == nullptr) || (Index <= 0) || (Index > Length))
    {
        return WL_FAIL;
    }
	
    if (Length <= 0)
    {
        return WL_EMPTY;
    }
	
    *y = Data[(Front + Index) % Capacity];

    return WL_SUCCESS;
}

/**
* @brief   IsEmpty()
* @details 判断列表是否为空
* @param   /
* @return  列表空返回TRUE，否则返回FALSE
*/
INT16 CWarningList::IsEmpty(void)
{
    if (Length > 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

/// End of File