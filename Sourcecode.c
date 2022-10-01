// Automated Math solution of moments
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include"continuousData.h"
#include"DescreteDataWithFrequency.h"
#include"DescreteDataWithoutFrequency.h"
void main()
{
    int i,ch;
    do
    {
        printf("Choose Which type of Data Do you Want to Enter\n");
        printf("Press 1 To Enter Continuous Data\n");
        printf("Press 2 To Enter Descrete Data Without Frequency\n");
        printf("Press 3 To Enter Descrete Data With Frequency\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("*********************************** Continuous Data ***********************************\n");
            continuous_moments_function();
            break;
        case 2:
            printf("*********************************** Descrete Data Without Frequency ***********************************\n");
            Descerete_Data_without_frequency_moments_function();
            break;
        case 3:
            printf("*********************************** Descrete Data With Frequency ***********************************\n");
            Descerete_Data_with_frequency_moments_function();
            break;
        case 4:
            printf("*********************************** Exited ***********************************\n");
            break;
        
        default:
            printf("Invalid Selesction\n");
        }
    } while (ch!=4);
    
}