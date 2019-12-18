//
// Created by 岳晨阳 on 2019/12/18.
//


//输入：每测试用例包括两行，第一行输入整数个数，第二行输入n个整数，数与数之间用空格隔开。最后一行包含-1，表示输入结束。
//输出：每组测试数据的结果输出占一行，输出按升序排列的n个整数。
//
//7
//49 38 65 97 76 13 27
//-1

//思路为 基准数
#include <stdio.h>

void swap(int &iValue1,int &iValue2){
    int temp = iValue1;
    iValue1 = iValue2;
    iValue2 = temp;
}

int partion(int iDatas[],int iLeft, int iRight){
//    i是正向指针 j是反向指针
    int i= iLeft+1, j = iRight;
//    每次取最左边的为基准值
    int iAnchor = iDatas[iLeft];

    while (i <= j){
        while ((iDatas[i] <= iAnchor)&& (i <= iRight))
            i++;
        while (iDatas[j] > iAnchor)
            j--;
        if(i<j){
            swap(iDatas[i],iDatas[j]);
            i++;
            j--;
        }
    }
//    重新划分基准值
    swap(iDatas[iLeft],iDatas[j]);
    return j;
}

//典型的分治
void quickSort(int iDatas[],int iLeft, int iRight){
    if(iRight > iLeft){
        int k  = partion(iDatas,iLeft,iRight);
        quickSort(iDatas,iLeft,k-1);
        quickSort(iDatas,k,iRight);
    }
}

int main(){

    int iDatas[10000];
    int iNum = 0,i = 0;

    scanf("%d",&iNum);

    while (iNum != 0){
        for (int i = 0; i < iNum; ++i)
            scanf("%d",&iDatas[i]);

        quickSort(iDatas,0,iNum-1);

        for (int i = 0; i <= iNum; ++i)
            printf("%d ",iDatas[i]);

        scanf("%d",&iNum);
    }
    return 0;
}