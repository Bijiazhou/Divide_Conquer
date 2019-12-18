//
// Created by 岳晨阳 on 2019/12/18.
//

int BinarySerach(int iDatas[],int iLen,int &k){
    int iLeft = 0,iRight = iLen - 1,iMid = 0;
    while (iLeft <= iRight){
        iMid = (iLeft + iRight)/2;
        if(k == iDatas[iMid])
            return iMid;
        if(k < iDatas[iMid])
            iRight = iMid - 1;
        else
            iLeft = iMid + 1;
    }
    return -1;
}