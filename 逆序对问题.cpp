//
// Created by 岳晨阳 on 2019/12/18.
//

#include <stdio.h>

long reverseOrderParis(int iDatas[10000], int iBuffers[10000], int iLow, int iHigh);

//long MergeReverse(int *pInt, int *pInt1, int low, int mid, int high);

int main(){
    int iDatas[10000],iBuffers[10000],iNum = 0,i = 0;

    long iReversePariNums = 0;
    scanf("%d",&iNum);

    while (iNum != -1){
        for (int i = 0; i < iNum; ++i) {
            scanf("%d",&iDatas[i]);
        }

        iReversePariNums = reverseOrderParis(iDatas,iBuffers,0,iNum-1);
        printf("%d",iReversePariNums);
        scanf("%d",&iNum);
    }
}

long MergeReverse(int iDatas[], int iBuffers[], int iLow, int iMid, int iHigh) {
    int i = iLow,j = iMid +1,k = iLow;

    long iCrossPairs = 0;

    while (i <= iMid && j <= iHigh){
        if(iDatas[i] < iDatas[j])
            iBuffers[k++]=iDatas[i++];
        else{
            iCrossPairs += iMid -i + 1;
            iBuffers[k++]=iDatas[j++];
        }
    }

    if(i <= iMid)
        for (int ii = i; ii <= iMid; ++ii) {
            iBuffers[k++] = iDatas[ii];
        }
    else
        for (int jj = j; jj <= iHigh; ++jj) {
            iBuffers[k++] = iDatas[jj];
        }
    return iCrossPairs;
}

long reverseOrderParis(int iDatas[10000], int iBuffers[10000], int iLow, int iHigh) {
//    递归边界
    if(iLow == iHigh)
        return 0;

    int iMid = (iLow + iHigh)/2;
    long C1,C2,C3;
    C1 = reverseOrderParis(iDatas,iBuffers,iLow,iMid);
    C2 = reverseOrderParis(iDatas,iBuffers,iMid+1,iHigh);
    C3 = MergeReverse(iDatas,iBuffers,iLow,iMid,iHigh);

    for (int i = iLow; i <= iHigh; ++i) {
        iDatas[i] = iBuffers[i];
    }
    return C1+C2+C3;
}


