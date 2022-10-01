#include<stdio.h>
#include<math.h>
// All Heads of Table
struct DescereteData1
{
    float x;
    float z1;
    float z2;
    float z3;
    float z4;
};
//Function Prototype
float Descerete_Data_without_frequency_moments_function();
void print_table_moments_Descerete(struct DescereteData1 Descerete_Data[],int no_of_elements);
float median_function_descerete(struct DescereteData1 Descerete_Data[],int no_of_elements);
void print_moments_function_descerete(float u1,float u2,float u3,float u4,float u_1,float u_2,float u_3,float u_4,float v1,float v2,float v3,float v4);
void print_kurtosis_function_descerete(float gama_2);
void print_skewness_function_descerete(float gama_1);
float mean_function_descerete(float sum_x,int no_of_elements);
float standard_deviation_function_descerete(float sum_z2,int no_of_elements);
float variance_function_descerete(float standerddeviation);
void mode_function_descerete();

// Fumction Defination
float Descerete_Data_without_frequency_moments_function()
{
    float mean1,sum_x=0;
    int i,no_of_elements,temporary1,temporary2;
    printf("Enter the count of elements : ");
    scanf("%d",&no_of_elements);
    struct DescereteData1 Descerete_Data[no_of_elements];
    for ( i = 0; i < no_of_elements; i++)
    {
        printf("Enter %d.Element: ",i+1);
        scanf("%f",&Descerete_Data[i].x);
        sum_x = sum_x + Descerete_Data[i].x;
    }
    float median,standerddeviation_main;
    median=median_function_descerete(Descerete_Data,no_of_elements);
    mean1 = mean_function_descerete(sum_x,no_of_elements);
    float sum_z1=0,sum_z2=0,sum_z3=0,sum_z4=0;
    for ( i = 0; i < no_of_elements; i++)
    {
        Descerete_Data[i].z1=Descerete_Data[i].x-mean1;
        Descerete_Data[i].z2 =pow((Descerete_Data[i].z1),2);
        Descerete_Data[i].z3 =pow((Descerete_Data[i].z1),3);
        Descerete_Data[i].z4 =pow((Descerete_Data[i].z1),4);
        sum_z1 = sum_z1 + Descerete_Data[i].z1;
        sum_z2 = sum_z2 + Descerete_Data[i].z2;
        sum_z3 = sum_z3 + Descerete_Data[i].z3;
        sum_z4 = sum_z4 + Descerete_Data[i].z4;
    }
    standerddeviation_main=standard_deviation_function_descerete(sum_z2,no_of_elements);
    // processing of row moents
    float u1,u2,u3,u4;
    u1=0;
    u2 = sum_z2/no_of_elements;
    u3 = sum_z3/no_of_elements;
    u4 = sum_z4/no_of_elements;
    // processing of moments about origin
    float u_1,u_2,u_3,u_4,a;
    a=Descerete_Data[no_of_elements / 2].x;
    u_1 = mean1 - a;
    u_2 = u2+pow(u_1,2);
    u_3 = u3 + 3*u_2*u_1 - 2* pow(u_1,3);
    u_4 = u4 + 4*u_3*u_1 - 6*u_2*pow(u_1,2) + 3*pow(u_1,4);
    // processing of moments about origin
    float v1,v2,v3,v4;
    v1=mean1;
    v2=u2+mean1;
    v3=u3 + 3*u2*mean1 + pow(mean1,3);
    v4=u4+ 4*u3*mean1 + pow(mean1,4);
    // Processing of skewness and curtosis
    float gama_1,gama_2;
    gama_1 = u3 / sqrt(pow(u2,3));
    gama_2 = u4 / pow(u2,2);
    
    int ch,mo_y;
    do
    {
        printf("\nWhat You want to print\n");
        printf("Press 1 for Mean\n");
        printf("Press 2 for Median\n");
        printf("Press 3 for Mode\n");
        printf("Press 4 for standard Deviation\n");
        printf("Press 5 for Variance\n");
        printf("Press 6 for Moments\n");
        printf("Press 7 for Skewness\n");
        printf("Press 8 for Kurtosis\n");
        printf("Press 9 for Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            mean_function_descerete(sum_x,no_of_elements);
            break;
        case 2:
            median_function_descerete(Descerete_Data,no_of_elements);
            break;
        case 3:
            mode_function_descerete();
            break;
        case 4:
            standard_deviation_function_descerete(sum_z2,no_of_elements);
            break;
        case 5:
            variance_function_descerete(standerddeviation_main);
            break;
        case 6:
            printf("Would you like to print Table press 1 for yes and 0 for no: ");
            scanf("%d",&mo_y);
            if(mo_y==1)
            {
                printf("************************************* Table *******************************************\n");
                print_table_moments_Descerete(Descerete_Data,no_of_elements);
            }
            print_moments_function_descerete(u1,u2,u3,u4,u_1,u_2,u_3,u_4,v1,v2,v3,v4);
            break;
        case 7:
            print_skewness_function_descerete(gama_1);
            break;
        case 8:
            print_kurtosis_function_descerete(gama_2);
            break;
        case 9:
            break;
        default:
            printf("Invalid Choice!!");
            break;
        }
    } while (ch!=9);
    
    return 0;
} 
void print_table_moments_Descerete(struct DescereteData1 Descerete_Data[],int no_of_elements)
{
    printf("|%5s|%10s|%10s|%10s|%10s|\n","X","z1","z2","z3","z4");
    int i;
    for ( i = 0; i < no_of_elements; i++)
    {
        printf("|%5.1f|%10.1f|%10.1f|%10.1f|%10.1f|\n",Descerete_Data[i].x,Descerete_Data[i].z1,Descerete_Data[i].z2,Descerete_Data[i].z3,Descerete_Data[i].z4);
    }
    
}
float median_function_descerete(struct DescereteData1 Descerete_Data[],int no_of_elements)
{
    float median;
    if(no_of_elements % 2 !=0)
    {
        median=Descerete_Data[(no_of_elements+1)/2].x;
    }
    else if (no_of_elements % 2 == 0)
    {
        median=(Descerete_Data[no_of_elements/2].x+Descerete_Data[(no_of_elements/2)+1].x)/2;
    }
    printf("Median : %0.2f\n",median);
    return median;
}
void print_moments_function_descerete(float u1,float u2,float u3,float u4,float u_1,float u_2,float u_3,float u_4,float v1,float v2,float v3,float v4)
{
    printf("Central moments 2 = %0.2f\n",u2);
    printf("Central moments 1 = %0.2f\n",u1);
    printf("Central moments 3 = %0.2f\n",u3);
    printf("Central moments 4 = %0.2f\n",u4);
    printf("Row moments 1 = %0.2f\n",u_1);
    printf("Row moments 2 = %0.2f\n",u_2);
    printf("Row moments 3 = %0.2f\n",u_3);
    printf("Row moments 4 = %0.2f\n",u_4);
    printf("Moments about origin 1 = %0.2f\n",v1);
    printf("Moments about origin 2 = %0.2f\n",v2);
    printf("Moments about origin 3 = %0.2f\n",v3);
    printf("Moments about origin 4 = %0.2f\n",v4);
}
void print_skewness_function_descerete(float gama_1)
{
    if(gama_1<0)
    printf("Distribution of given data is nagatively skewed\n");
    else if(gama_1>0)
    printf("Distribution of given data is positively skewed\n");
    else if(gama_1==0)
    printf("Distribution of given data is Symmetric\n");
}
void print_kurtosis_function_descerete(float gama_2)
{
    if(gama_2<0)
    printf("Distribution of given data is platykurtic\n");
    else if(gama_2>0)
    printf("Distribution of given data is Mesokurtic\n");
    else if(gama_2==0)
    printf("Distribution of given data is Leptokurtic\n");
}
float mean_function_descerete(float sum_x,int no_of_elements)
{
    float mean;
    mean=sum_x/no_of_elements;
    printf("Mean : %0.2f\n",mean);
    return mean;
}
void mode_function_descerete()
{
    printf("Mode can not be determined because every element is unique here\n");
}
float standard_deviation_function_descerete(float sum_z2,int no_of_elements)
{
    float standerddeviation;
    standerddeviation=sqrt(sum_z2/no_of_elements);
    printf("Standard Deviation : %0.2f\n",standerddeviation);
    return standerddeviation;
}
float variance_function_descerete(float standerddeviation)
{
    float variance;
    variance=pow(standerddeviation,2);
    printf("Standard Deviation : %0.2f\n",standerddeviation);
    return variance;
}