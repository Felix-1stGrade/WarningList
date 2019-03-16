/**
* @file       WarningList.h
* @brief      告警列表
* @details    用队列实现告警列表
* @note       数组队列的长度不能在运行中确定大小,如果数组队列的元素数据的类型发生变化，数组队列类型需要修改
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

// 队列元素的类型
typedef INT16 TListElem; 

enum
{
    WL_SUCCESS = 0, ///< 操作成功
    WL_FAIL = 1,    ///< 操作失败
    WL_FULL = -1,   ///< 队列已满
    WL_EMPTY = 2    ///< 队列空
}; 

/**
* @brief   CWarningList
* @details 告警列表实现
*/
class CWarningList
{
public:
    INT16 Init(void);                   ///< 初始化告警列表
    INT16 Append(TListElem);            ///< 新增告警条目到列表最后
    INT16 Delete(TListElem*);           ///< 读取并删除列表中的告警条目
    INT16 GetLength(void);              ///< 获取列表中的条目数量
    INT16 GetHead(TListElem*);          ///< 读取列表中的第一个条目，不删除
    INT16 Get(TListElem*, INT16 Index); ///< 读取列表中指定序号的条目，不删除，Index从1开始
    INT16 IsEmpty(void);                ///< 判断列表是否为空 

private:
    TListElem Data[LIST_CAPACITY];
    INT16 Front;
    INT16 Rear;
    INT16 Length;
    INT16 Capacity;
};

#endif

/// End of File