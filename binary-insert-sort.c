#include<stdio.h>

int sorted[100000];
int len = 0;

//no duplications, only sort the last element
void bi_insert_sort(int sorted[], int len)
{
    int i,j;
    int low,high,mid;
    int tmp;
    switch(len) {
    case 0:
    case 1:
        return;
    case 2:
        if(sorted[0]<sorted[1])
            sorted[0] ^= sorted[1];
            sorted[1] ^= sorted[0];
            sorted[0] ^= sorted[1];
        break;
    default:
        low = 0;
        tmp = sorted[len-1];
        high = len-2;
#if 1
        if(sorted[0]>tmp)
        {
            for(j=len-1;j>0;j--)
                sorted[j] = sorted[j-1];
            sorted[0] = tmp;
            return;
        }
        else if(sorted[len-2]<tmp)
            return;
#endif
        mid = (low+high)/2;
        printf("mid=%d\n",mid);
        while(low<=high)
        {           
            if(sorted[mid]>tmp)
                high = mid-1;
            else
                low = mid+1;
            mid = (low+high)/2;       
            printf("mid=%d\n",mid);
        }
        printf("high=%d\n",high);
        for(j=len-1;j>high+1;j--)
        {
            printf("sorted[j-1]=%d\n",sorted[j-1]);
            sorted[j] = sorted[j-1];
        }
        sorted[high+1] = tmp;
    }
    return;
}

int main()
{
    int i;
    len = 5;
    sorted[0] = 22;
    sorted[1] = 50;
    sorted[2] = 60;
    sorted[3] = 80;
    sorted[4] = 40;
    bi_insert_sort(sorted, len);
    for(i=0;i<len;i++)
        printf("%d ", sorted[i]);
    printf("\n");
}
