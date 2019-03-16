/**
* @file       WarningList.cpp
* @brief      �澯�б�
* @details    �ö���ʵ�ָ澯�б�
* @note       ������еĳ��Ȳ�����������ȷ����С,���������е�Ԫ�����ݵ����ͷ����仯���������������Ҫ�޸�
* @author     Felix Lu
* @date       2018.11.13
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#include "WarningList.h"

/**
* @brief   Init()
* @details ��ʼ���澯�б�
* @param   /
* @return  ����״̬
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
* @details �����澯��Ŀ���б����
* @param   x Ҫ���ӵĸ澯��Ŀ
* @return  ����״̬
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
* @details ��ȡ��ɾ���б��еĸ澯��Ŀ
* @param   *y ɾ����ȡ���ĸ澯��Ŀ
* @return  ����״̬
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
* @details ��ȡ�б��е���Ŀ����
* @param   /
* @return  �б��еĸ澯��Ŀ����
*/
INT16 CWarningList::GetLength(void)
{
    return Length;
}

/**
* @brief   GetHead()
* @details ��ȡ�б��еĵ�һ����Ŀ����ɾ��
* @param   *y ��ȡ����Ŀ
* @return  ����״̬
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
* @details ��ȡ�б���ָ����ŵ���Ŀ����ɾ����Index��1��ʼ
* @param   *y ��ȡ�ĸ澯��Ŀ
* @param   Index �澯��Ŀ���
* @return  ����״̬
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
* @details �ж��б��Ƿ�Ϊ��
* @param   /
* @return  �б�շ���TRUE�����򷵻�FALSE
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