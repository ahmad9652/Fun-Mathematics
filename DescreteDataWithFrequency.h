#include<stdio.h>
#include<math.h>
struct DescereteData2
{
    float x;
    float frequency;
    float fx;
    float z1;
    float z2;
    float z3;
    float z4;
    float mode_z2;
};
//Function Prototype
float Descerete_Data_with_frequency_moments_function();
float skewness_function_D_w_f(float u3, float u2);
float kurtosis_function_D_w_f(float u2, float u4);
void print_moments_D_w_f(float u1,float u2,float u3, float u4, float u_1, float u_2,float u_3, float u_4, float v1, float v2, float v3, float v4);
float mean_function_D_w_f(float sum_fx, float sum_frequency);
void print_table_mean_D_w_f(struct DescereteData2 Descerete_Data[], int no_of_elements);
float mode_D_w_f(struct DescereteData2 Descerete_Data[], int no_of_elements);
void print_mode_table_D_w_f(struct DescereteData2 Descerete_Data[], int no_of_elements);
float median_function_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements);
float sd_function_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements,float mean1,float sum_frequency);
void print_table_sd_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements);
void print_table_moments_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements);
float variance_function_D_w_f(float sd);
//Function Defination
float Descerete_Data_with_frequency_moments_function()
{
    float mean1,sum_x=0,sum_frequency=0,sum_fx=0;
    int i,no_of_elements,temporary1,temporary2;
    printf("Enter the count of elements : ");
    scanf("%d",&no_of_elements);
    struct DescereteData2 Descerete_Data[no_of_elements];
    for ( i = 0; i < no_of_elements; i++)
    {
        printf("Enter %d.Element: ",i+1);
        scanf("%f",&Descerete_Data[i].x);
        printf("Enter Frequency related to given class : ");
        scanf("%f",&Descerete_Data[i].frequency);
        sum_x = sum_x + Descerete_Data[i].x;
        sum_frequency=sum_frequency+Descerete_Data[i].frequency;
        Descerete_Data[i].fx = Descerete_Data[i].x * Descerete_Data[i].frequency;
        sum_fx=sum_fx+Descerete_Data[i].fx;
    }
    mean1=mean_function_D_w_f( sum_fx,  sum_frequency);
    float sum_z1=0,sum_z2=0,sum_z3=0,sum_z4=0;
    for ( i = 0; i < no_of_elements; i++)
    {
        Descerete_Data[i].z1=Descerete_Data[i].frequency * Descerete_Data[i].x-mean1;
        Descerete_Data[i].z2 =Descerete_Data[i].frequency * pow((Descerete_Data[i].z1),2);
        Descerete_Data[i].z3 =Descerete_Data[i].frequency * pow((Descerete_Data[i].z1),3);
        Descerete_Data[i].z4 =Descerete_Data[i].frequency * pow((Descerete_Data[i].z1),4);
        sum_z1 = sum_z1 + Descerete_Data[i].z1;
        sum_z2 = sum_z2 + Descerete_Data[i].z2;
        sum_z3 = sum_z3 + Descerete_Data[i].z3;
        sum_z4 = sum_z4 + Descerete_Data[i].z4;
    }
    // processing of Centeral moments
    float u1,u2,u3,u4;
    u1=0;
    u2 = sum_z2/sum_frequency;
    u3 = sum_z3/sum_frequency;
    u4 = sum_z4/sum_frequency;
    // processing of Row moments
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
    // processing of skewness and kurtosis
    float gama_1,gama_2;
    gama_1=skewness_function_D_w_f(u3,u2);
    gama_2=kurtosis_function_D_w_f(u2,u4);
    // Standard Deviation 
    float sd;
    sd=sd_function_D_w_f(Descerete_Data,no_of_elements,mean1,sum_frequency);
    int ch,m_y,me_y,S_y,mo_y;
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
            printf("Would you like to print Table press 1 for yes or 0 for no : ");
            scanf("%d",&m_y);
            if(m_y==1)
            {
              printf("************************************* Table *******************************************\n");
              print_table_mean_D_w_f(Descerete_Data,no_of_elements);
            }
            mean_function_D_w_f(sum_fx,sum_frequency);
            break;
        case 2:
            median_function_D_w_f(Descerete_Data,no_of_elements);
            break;
        case 3:
            printf("Would you like to print Table for Median press 1 for yes and 0 for no: ");
            scanf("%d",&me_y);
            if(me_y==1)
            {
                printf("************************************* Table *******************************************\n");
                print_mode_table_D_w_f(Descerete_Data,no_of_elements);
            }
            mode_D_w_f(Descerete_Data,no_of_elements);
            break;
        case 4:
            printf("Would you like to print Table for Standard Deviation press 1 for yes and 0 for no: ");
            scanf("%d",&S_y);
            if(S_y==1)
            {
                printf("************************************* Table *******************************************\n");
                print_table_sd_D_w_f(Descerete_Data,no_of_elements);
            }
            sd_function_D_w_f(Descerete_Data,no_of_elements,mean1,sum_frequency);
            break;
        case 5:
            variance_function_D_w_f(sd);
            break;
        case 6:
            printf("Would you like to print Table press 1 for yes and 0 for no: ");
            scanf("%d",&mo_y);
            if(mo_y==1)
            {
                printf("************************************* Table *******************************************\n");
                print_table_moments_D_w_f(Descerete_Data,no_of_elements);
            }
            print_moments_D_w_f(u1,u2,u3,u4,u_1,u_2,u_3,u_4,v1,v2,v3,v4);
            break;
        case 7:
            skewness_function_D_w_f(u3,u2);
            break;
        case 8:
            kurtosis_function_D_w_f(u2,u4);
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    } while (ch!=9);
    
    return 0;
} 
float skewness_function_D_w_f(float u3, float u2)
{
    float gama_1;
    gama_1 = u3 / sqrt(pow(u2,3));
    if(gama_1<0)
    printf("Distribution of given data is nagatively skewed\n");
    else if(gama_1>0)
    printf("Distribution of given data is positively skewed\n");
    else if(gama_1==0)
    printf("Distribution of given data is Symmetric\n");
    return gama_1;
}
float kurtosis_function_D_w_f(float u2, float u4)
{
    float gama_2;
    gama_2 = u4 / pow(u2,2);
    if(gama_2<0)
    printf("Distribution of given data is platykurtic\n");
    else if(gama_2>0)
    printf("Distribution of given data is Mesokurtic\n");
    else if(gama_2==0)
    printf("Distribution of given data is Leptokurtic\n");
    return gama_2;
}
void print_moments_D_w_f(float u1,float u2,float u3, float u4, float u_1, float u_2,float u_3, float u_4, float v1, float v2, float v3, float v4)
{
    printf("Central moments 1 = %0.2f\n",u1);
    printf("Central moments 2 = %0.2f\n",u2);
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
void print_table_moments_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements)
{
    printf("|%5s|%10s|%10s|%10s|%10s|%10s|\n","X","frequency","fz1","fz2","fz3","fz4");
    int i;
    for ( i = 0; i < no_of_elements; i++)
    {
        printf("|%5.1f|%10.1f|%10.1f|%10.1f|%10.1f|%10.1f|\n",Descerete_Data[i].x,Descerete_Data[i].frequency,Descerete_Data[i].z1,Descerete_Data[i].z2,Descerete_Data[i].z3,Descerete_Data[i].z4);
    }
}
float mean_function_D_w_f(float sum_fx, float sum_frequency)
{
    float mean1;
    mean1 = sum_fx/sum_frequency;
    printf("Mean: %0.2f\n",mean1);
    return mean1;
}
void print_table_mean_D_w_f(struct DescereteData2 Descerete_Data[], int no_of_elements)
{
    printf("|%5s|%10s|%10s|\n","X","frequency","fX");
    int i;
    for ( i = 0; i < no_of_elements; i++)
    {
        printf("|%5.1f|%10.1f|%10.1f|\n",Descerete_Data[i].x,Descerete_Data[i].frequency,Descerete_Data[i].fx);
    }
}
float mode_D_w_f(struct DescereteData2 Descerete_Data[], int no_of_elements)
{
    int i,index;
    float mode_index;
    float mode1;
    mode_index=0;
    for ( i = 0; i < no_of_elements; i++)
    {
        if(mode_index < Descerete_Data[i].frequency)
        {// index=i;
        mode1=Descerete_Data[i].x;    
        printf("mode index: %d\n",i);
        }
        
    }
    printf("Mode: %0.2f\n",mode1);
    return mode1;
}
void print_mode_table_D_w_f(struct DescereteData2 Descerete_Data[], int no_of_elements)
{
    printf("|%5s|%10s|\n","x","frequency");
    int i;
    for ( i = 0; i < no_of_elements; i++)
    {
        printf("|%5.1f|%10.1f|\n",Descerete_Data[i].x,Descerete_Data[i].frequency);
    }
    
}
float median_function_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements)
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
float sd_function_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements,float mean1,float sum_frequency)
{
    float sum_median_z2=0;
    int i;
    for(i=0;i<=no_of_elements;i++)
    {
        Descerete_Data[i].mode_z2=pow((Descerete_Data[i].x-mean1),2);
        sum_median_z2=sum_median_z2+Descerete_Data[i].mode_z2;
    }
    float sd;
    sd=sqrt(sum_median_z2/sum_frequency);
    printf("Standasd Deviation : %0.2f\n",sd);
    return sd;
}
void print_table_sd_D_w_f(struct DescereteData2 Descerete_Data[],int no_of_elements)
{
    printf("|%5s|%10s|%10s|\n","X","frequency","z2");
    int i;
    for ( i = 0; i < no_of_elements; i++)
    {
        printf("|%5.1f|%10.1f|%10.1f|\n",Descerete_Data[i].x,Descerete_Data[i].frequency,Descerete_Data[i].mode_z2);
    }
    
}
float variance_function_D_w_f(float sd)
{
    float variance;
    variance=pow(sd,2);
    printf("Variance : %0.2f\n",variance);
    return variance;
}