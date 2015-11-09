#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    printf("Please enter your credit card number without spaces or hypens.\nNumber:");
    long long ccnumber = GetLongLong();
    
    int checksum1, checksum2, cclength;
    checksum1 = 0;
    checksum2 = 0;
    cclength = 0;
        
    for (long long i = ccnumber; i > 0;)
    {
        printf("%lld\n", i);
        checksum1 += i % 10;
        printf("%d\n", checksum1);
        if(i > 0) {
            cclength++;
        }
        i = i / 10;
        checksum2 += (2*(i % 10))%10;
        checksum2 += ((2*(i % 10))/10)%10;
        printf("%d\n", checksum2);
        if(i > 0) {
            cclength++;
        }
        i = i / 10;
    }
    int cccheck = checksum1 + checksum2;
    for (int i = 0; i < (cclength - 1); i++)
    {
        ccnumber = ccnumber / 10;
    }
    printf("checksum1 = %d\nchecksum2 = %d\ncccheck = %d\n", checksum1, checksum2, cccheck);
    printf("cclength = %d\n", cclength);
    printf("ccnumber = %lld\n", ccnumber);
    
    if ( (cccheck % 10 == 0) && (12 < cclength < 17) )
    {        
        switch(ccnumber) {
            case 3:
                printf("AMEX\n");
                break;
            case 4:
                printf("VISA\n");
                break;
            case 5:
                printf("MASTERCARD\n");
                break;
            default:
                printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    };
        
    return 0;
}
