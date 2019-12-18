//
// Created by 岳晨阳 on 2019/12/18.
//

//输入：每测试用例包括两行，第一行输入整数个数，第二行输入n个整数，数与数之间用空格隔开。最后一行包含-1，表示输入结束。
//输出：每组测试数据的结果输出占一行，输出按升序排列的n个整数。
//
//7
//49 38 65 97 76 13 27
//-1

#include <stdio.h>

void merge(int[],int[],int,int,int);
void mergrSort(int[],int[],int,int);

int main(){

    int iDatas[10000];
    int iBuffers[10000];

    int iNum = 0,i = 0;

    scanf("%d",&iNum);

    while (iNum != 0){
        for (int i = 0; i < iNum; ++i)
            scanf("%d",&iDatas[i]);

        mergrSort(iDatas,iBuffers,0,iNum-1);

        for (int i = 0; i <= iNum; ++i)
            printf("%d ",iDatas[i]);

        scanf("%d",&iNum);
    }
    return 0;
}

void mergrSort(int iDatas[],int iBuffer[],int iLow,int iHigh){
    if(iHigh > iLow){
        int iMid = (iLow + iHigh)/2;
        //划分一波
        mergrSort(iDatas,iBuffer,iLow,iMid);
        mergrSort(iDatas,iBuffer,iMid+1,iHigh);
//        合并一波
        merge(iDatas,iBuffer,iLow,iMid,iHigh);
        for (int i = iLow; i <= iHigh; ++i) {
            iDatas[i] =  iBuffer[i];
        }
    }
}

//合并iData的两段到ibuffer里面去
void merge(int iDatas[],int iBuffer[],int iLow,int iMid,int iHigh){
    int i = iLow,j=iMid+1,k=iLow;
    //挨个对比存入
    while ((i<iMid) && (j<= iHigh)){
        if(iDatas[i]<=iDatas[j])
            iBuffer[k++]=iDatas[i++];
        else
            iBuffer[k++]=iDatas[j++];
    }
//    没有存完的部分
    if (i <= iMid){
        for (int ii = i; ii <= iMid; ++ii) {
            iBuffer[k++]=iDatas[ii++];
        }
    } else{
        for (int jj = j; jj <= iHigh; ++jj) {
            iBuffer[k++]=iDatas[jj++];
        }
    }
}