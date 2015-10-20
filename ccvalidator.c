#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Please enter the number on the front of your credit card\n");
    string ccnumber = GetString();
    
    int cclength = strlen( ccnumber );
    
    printf("The credit card number entered was is %d characters long\n", cclength);

//  Remove spaces from ccnumber
//  for ( i = 0; i < cclength - 1; i++ )
//  {
//      if ( ccnumber[i] == ' ' )
//      {
//          while ( i < cclength )
//          {
//              ccnumber[i] = ccnumber[i + 
//          }
//      }
//  }
    
    // Check that ccnumber falls with correct length if so proceed with program
    if ( (cclength > 12) && (cclength < 17) )
    {
        int ccchecksum1, ccchecksum2;
        ccchecksum1 = 0;
        ccchecksum2 = 0;
        
        // Starting with the second last digit, multiply every
        // other digit by two and sum the results together in ccchecksum1
        for (int i = (cclength - 2); i > -1; i = i - 2)
        {
            printf("%c %d\n", ccnumber[i], (ccnumber[i] - '0'));
            int x = (ccnumber[i] - '0') * 2;
            printf("x = %d\n", x );
            if ( x > 9 )
            {
                ccchecksum1 = ccchecksum1 + ( x % 10 ) + ( x / 10 % 10 );
                printf("ccchecksum currently equals %d\n", ccchecksum1 );
            } else {
                ccchecksum1 = ccchecksum1 + x;
                printf("ccchecksum currently equals %d\n", ccchecksum1 );
            }
        }
        
        // Starting with the last digit sum every other digit together in ccchecksum1
        for (int i = (cclength - 1); i > -1; i = i - 2 )
        {
            printf("%c %d\n", ccnumber[i], (ccnumber[i] - '0'));
            int x = (ccnumber[i] - '0');
            printf("x = %d\n", x );
            ccchecksum2 = ccchecksum2 + x; 
            printf("ccchecksum currently equals %d\n", ccchecksum2);
        }
        
        // Sum the checksums together and to see if card validates
        if((ccchecksum1 + ccchecksum2) % 10 == 0)
        {
            printf("Your credit card number is valid!.\n");
        } else {
            printf("Sorry your credit card number is not valid! Please enter a valid credit card number.\n");
        }
            
    } else {
        printf("Your credit card number is too long or too short. Please enter a valid credit card number without spaces.\n");
    }
}
