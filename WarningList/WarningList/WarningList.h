/*===========================================================================
* File        : WarningList.h
* Description : ������еĳ��Ȳ�����������ȷ����С,���������е�Ԫ�����ݵ����ͷ����仯���������������Ҫ�޸�
* Author      : Felix
* Date        : 2018.11.13
===========================================================================*/
#ifndef WARNINGLIST_H
#define WARNINGLIST_H

#include "DataTypes.h" 

#define LIST_CAPACITY 8

// ����Ԫ�ص�����
typedef INT16 TListElem; 

enum
{
    WL_SUCCESS = 0,
    WL_FAIL = 1,
    WL_FULL = -1,
    WL_EMPTY = 2
}; 

class CWarningList
{
public:
    INT16 Init(void);                   // ��ʼ���澯�б�
    INT16 Append(TListElem);            // �����澯��Ŀ���б����
    INT16 Delete(TListElem*);           // ��ȡ��ɾ���б��еĸ澯��Ŀ
    INT16 GetLength(void);              // ��ȡ�б��е���Ŀ����
    INT16 GetHead(TListElem*);          // ��ȡ�б��еĵ�һ����Ŀ����ɾ��
    INT16 Get(TListElem*, INT16 Index); // ��ȡ�б���ָ����ŵ���Ŀ����ɾ����Index��1��ʼ
    INT16 IsEmpty(void);                // �ж��б��Ƿ�Ϊ�� 

private:
    TListElem Data[LIST_CAPACITY];
    INT16 Front;
    INT16 Rear;
    INT16 Length;
    INT16 Capacity;
};

#endif
//===========================================================================
// End of File
//===========================================================================