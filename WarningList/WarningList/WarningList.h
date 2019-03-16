/**
* @file       WarningList.h
* @brief      �澯�б�
* @details    �ö���ʵ�ָ澯�б�
* @note       ������еĳ��Ȳ�����������ȷ����С,���������е�Ԫ�����ݵ����ͷ����仯���������������Ҫ�޸�
* @author     Felix Lu
* @date       2018.11.13
* @version    /
* @par Copyright (c):
*             2016-2019 XXX All rights reserved.
*/
#ifndef WARNINGLIST_H
#define WARNINGLIST_H

#include "DataTypes.h" 

#define LIST_CAPACITY 8

// ����Ԫ�ص�����
typedef INT16 TListElem; 

enum
{
    WL_SUCCESS = 0, ///< �����ɹ�
    WL_FAIL = 1,    ///< ����ʧ��
    WL_FULL = -1,   ///< ��������
    WL_EMPTY = 2    ///< ���п�
}; 

/**
* @brief   CWarningList
* @details �澯�б�ʵ��
*/
class CWarningList
{
public:
    INT16 Init(void);                   ///< ��ʼ���澯�б�
    INT16 Append(TListElem);            ///< �����澯��Ŀ���б����
    INT16 Delete(TListElem*);           ///< ��ȡ��ɾ���б��еĸ澯��Ŀ
    INT16 GetLength(void);              ///< ��ȡ�б��е���Ŀ����
    INT16 GetHead(TListElem*);          ///< ��ȡ�б��еĵ�һ����Ŀ����ɾ��
    INT16 Get(TListElem*, INT16 Index); ///< ��ȡ�б���ָ����ŵ���Ŀ����ɾ����Index��1��ʼ
    INT16 IsEmpty(void);                ///< �ж��б��Ƿ�Ϊ�� 

private:
    TListElem Data[LIST_CAPACITY];
    INT16 Front;
    INT16 Rear;
    INT16 Length;
    INT16 Capacity;
};

#endif

/// End of File