/*===========================================================================
* File        : WarningList.cpp
* Description : 数组队列的长度不能在运行中确定大小,如果数组队列的元素数据的类型发生变化，数组队列类型需要修改
* Author      : Felix
* Date        : 2018.11.13
===========================================================================*/
#include "WarningList.h"

/*---------------------------------------------------------------------------
函数名称: Init()
功能描述: 初始化告警列表
---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------
函数名称: Append()
功能描述: 新增告警条目到列表最后
---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------
函数名称: Delete()
功能描述: 读取并删除列表中的告警条目
---------------------------------------------------------------------------*/
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
 
/*---------------------------------------------------------------------------
函数名称: GetLength()
功能描述: 获取列表中的条目数量
---------------------------------------------------------------------------*/
// 得到队列元素个数
INT16 CWarningList::GetLength(void)
{
    return Length;
}

/*---------------------------------------------------------------------------
函数名称: GetHead()
功能描述: 读取列表中的第一个条目，不删除
---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------
函数名称: Get()
功能描述: 读取列表中指定序号的条目，不删除，Index从1开始
---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------
函数名称: IsEmpty()
功能描述: 判断列表是否为空
---------------------------------------------------------------------------*/
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

//===========================================================================
// End of File
//===========================================================================