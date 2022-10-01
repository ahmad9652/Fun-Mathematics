#include<stdio.h>
#include<math.h>
//All heads of Table
struct ContinuousData
{
    float lower_limit;
    float upper_limit;
    float x;
    float frequency;
    float commulative_frequency;
    float deviation;
    float fd;
    float fz1;
    float fz2;
    float fz3;
    float fz4;
};
// Function Prototype
void print_table_moments(struct ContinuousData mean[], int no_of_row);
float median_function(struct ContinuousData mean[],float m_l,float m_i, float m_f, float median_class, float m_c,float m_u,int no_of_row );
void print_table_median(struct ContinuousData mean[], int no_of_row);
float mean_function(struct ContinuousData mean[], int no_of_row,float sum_fd, float sum_frequency);
float print_table_mean(struct ContinuousData mean[],int no_of_row);
float mode_function(struct ContinuousData mean[], int no_of_row);
void print_table_mode(struct ContinuousData mean[], int no_of_row);
float standerd_deviation_function(struct ContinuousData mean[], int no_of_row,float sum_frequency);
float variance_function(float sd);
void print_centeral_moments(float u1,float u2,float u3,float u4);
void print_row_moments(float u_1,float u_2,float u_3,float u_4);
void print_moments_about_origin_function(float v1,float v2,float v3,float v4);
float skewness_function(float gama_1);
float kurtosis_function(float gama_2);
//Function Defination
float continuous_moments_function()
{
    float a,sum_x=0,sum_fd=0,sum_frequency=0,mean1,sum_fz1=0,sum_fz2=0,sum_fz3=0,sum_fz4=0,u_1,u_2,u_3,u_4;
    int i,ch,no_of_row,temporary1,me_y,mo_y;
    printf("Enter how many Row do you want: ");
    scanf("%d",&no_of_row);
    struct ContinuousData mean[no_of_row];
    for ( i = 0; i < no_of_row; i++)
    {
        printf("Enter %d. Lower limit and %d. Upper limit\n",i+1,i+1);
        scanf("%f%f",&mean[i].lower_limit,&mean[i].upper_limit);
        mean[i].x=(mean[i].lower_limit+mean[i].upper_limit)/2;
        printf("Enter Frequency related to given class : ");
        scanf("%f",&mean[i].frequency);
        sum_frequency=sum_frequency+mean[i].frequency;
        if (i==0)
        {
            mean[i].commulative_frequency=mean[i].frequency;
        }
        else
        {
            mean[i].commulative_frequency = mean[i-1].commulative_frequency+mean[i].frequency;
        }
        // printf("Commulative frequency: %0.2f\n",mean[i].commulative_frequency);
    }
    standerd_deviation_function(mean,no_of_row,sum_frequency);
    int M_y;
    float c,m_c,m_f,m_l,m_u,median,m_i, median_class;;
    c=mean[temporary1-1].commulative_frequency;
    median_class = sum_frequency/2;
    // Median and Mean
    median=median_function( mean,m_l,m_i,m_f,median_class,m_c,m_u,no_of_row );
    mean1=mean_function(mean,no_of_row,sum_fd,sum_frequency);
    // Centeral Moments processing
    for ( i = 0; i < no_of_row; i++)
    {
        mean[i].fz1 = mean[i].frequency * (mean[i].x-mean1);
        mean[i].fz2 = mean[i].frequency *( pow((mean[i].x-mean1),2));
        mean[i].fz3 = mean[i].frequency *( pow((mean[i].x-mean1),3));
        mean[i].fz4 = mean[i].frequency *( pow((mean[i].x-mean1),4));
        sum_fz1=sum_fz1+mean[i].fz1;
        sum_fz2=sum_fz2+mean[i].fz2;
        sum_fz3=sum_fz3+mean[i].fz3;
        sum_fz4=sum_fz4+mean[i].fz4;
    }
    // Centeral Moments processing
    float u1,u2,u3,u4;
    u1=0;
    u2 = sum_fz2/no_of_row;
    u3 = sum_fz3/no_of_row;
    u4 = sum_fz4/no_of_row;
    // Row moments processing
    u_1 = mean1 - a;
    u_2 = u2+pow(u_1,2);
    u_3 = u3 + 3*u_2*u_1 - 2* pow(u_1,3);
    u_4 = u4 + 4*u_3*u_1 - 6*u_2*pow(u_1,2) + 3*pow(u_1,4);
    // Moments about origin processing
    float v1,v2,v3,v4;
    v1=mean1;
    v2=u2+mean1;
    v3=u3 + 3*u2*mean1 + pow(mean1,3);
    v4=u4+ 4*u3*mean1 + pow(mean1,4);
    // Skewness Processing
    float gama_1,gama_2;
    gama_1 = u3 / sqrt(pow(u2,3));
    // Kurtosis processing
    gama_2 = u4 / pow(u2,2);
    int m_y;
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
              print_table_mean(mean,no_of_row);
            }
            printf("Mean : %f\n",mean1);
            break;
        case 2:
            printf("Would you like to print Table for Median press 1 for yes and 0 for no: ");
            scanf("%d",&me_y);
            if(me_y==1)
            {
                printf("************************************* Table *******************************************\n");
                print_table_median(mean,no_of_row);
            }
            printf("Median=%0.2f\n",median);
            break;
        case 3:
            printf("Would you like to print Table for Mode press 1 for yes and 0 for no: ");
            scanf("%d",&M_y);
            if(M_y==1)
            {
                printf("************************************* Table *******************************************\n");
                print_table_mode(mean,no_of_row);
            }
            mode_function(mean,no_of_row);
            break;
        case 4:
            standerd_deviation_function(mean,no_of_row,sum_frequency);
            break;
        case 5:
            variance_function(standerd_deviation_function(mean,no_of_row,sum_frequency));
            break;
        case 6:
            printf("Would you like to print Table press 1 for yes and 0 for no: ");
            scanf("%d",&mo_y);
            if(mo_y==1)
            {
                printf("************************************* Table *******************************************\n");
                print_table_moments(mean,no_of_row);
            }
            print_row_moments(u_1,u_2,u_3,u_4);
            print_centeral_moments(u1,u2,u3,u4);
            print_moments_about_origin_function(v1,v2,v3,v4);
            break;
        case 7:
            skewness_function(gama_1);
            break;
        case 8:
            kurtosis_function(gama_2);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch!=9);
    
    return 0;
}
// Function Definations

void print_table_moments(struct ContinuousData mean[], int no_of_row)
{
    printf("|%-10s|%-10s|%-5s|%-10s|%-10s|%-10s|%-10s|\n","Class","Frequency","X","fz1","fz2","fz3","fz4");
    int i;
    for(i=0;i<no_of_row;i++)
    {
        printf("|%-5.1f%-5.1f|%-10.1f|%-5.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|\n",mean[i].lower_limit,mean[i].upper_limit,mean[i].frequency,mean[i].x,mean[i].fz1,mean[i].fz2,mean[i].fz3,mean[i].fz4);
    }
}

float median_function(struct ContinuousData mean[],float m_l,float m_i, float m_f, float median_class, float m_c,float m_u,int no_of_row )
{
    float median;
    int i;
    for ( i = 0; i < no_of_row; i++)
    {
        if(median_class>mean[i].commulative_frequency)
        {
            m_c = mean[i].commulative_frequency;
            m_f = mean[i+1].frequency;
            m_l = mean[i+1].lower_limit;
            m_u = mean[i+1].upper_limit;
        }
    }
    m_i=m_u-m_l;
    median=m_l+(m_i/m_f)*((median_class)-m_c);
    return median;
}
void print_table_median(struct ContinuousData mean[], int no_of_row)
{
   printf("|%-10s|%-10s|%-5s|%-10s|\n","Class","Frequency","X","C");
    int i;
    for(i=0;i<no_of_row;i++)
    {
        printf("|%-5.1f%-5.1f|%-10.1f|%-5.1f|%-10.1f|\n",mean[i].lower_limit,mean[i].upper_limit,mean[i].frequency,mean[i].x,mean[i].commulative_frequency);
    } 
}
float mean_function(struct ContinuousData mean[], int no_of_row,float sum_fd, float sum_frequency)
{
    float a,mean1;
    int i;
    a=mean[no_of_row/2].x;
    for ( i = 0; i < no_of_row; i++)
    {
        mean[i].deviation=mean[i].x-a;
        mean[i].fd=mean[i].frequency*mean[i].deviation;
        sum_fd=sum_fd+mean[i].fd;
    }
    mean1=a+(sum_fd/sum_frequency);
    return mean1;
}
float print_table_mean(struct ContinuousData mean[],int no_of_row)
{
    printf("|%10s|%10s|%10s|%5s|%10s|%10s|\n","Class","frequency","x","Deviation","fd");
    int i;
    for(i=0;i<no_of_row;i++)
    {
        printf("|%5.1s%5.1s|%10.1s|%10.1s|%5.1s|%10.1s|%10.1s|\n",mean[i].lower_limit,mean[i].upper_limit,mean[i].frequency,mean[i].x,mean[i].deviation,mean[i].fd);
    }
}
float mode_function(struct ContinuousData mean[], int no_of_row)
{
    float temp_index,M,M_l,M_i,M_f_p,M_f,M_f_n;
    int i,flag;
    M_f=mean[0].frequency;
    for ( i = 0; i < no_of_row; i++)
    {
        if(M_f<mean[i].frequency)
        {
            M_f=mean[i].frequency;
            M_l=mean[i].lower_limit;
            M_i=mean[i].upper_limit-M_l;
            flag=i;
        }
    }
    M_f_p=mean[flag-1].frequency;
    M_f_n=mean[flag+1].frequency;
    M=M_l+(M_i*((M_f-M_f_p)/(2*M_f-M_f_p-M_f_n)));
    printf("Mode: %0.2f",M);
    return M;
}
void print_table_mode(struct ContinuousData mean[], int no_of_row)
{
    printf("|%-10s|%-10s|%-5s|\n","Class","Frequency");
    int i;
    for(i=0;i<no_of_row;i++)
    {
        printf("|%-5.1f%-5.1f|%-10.1f|%-5.1f|\n",mean[i].lower_limit,mean[i].upper_limit,mean[i].frequency,mean[i].x,mean[i].commulative_frequency);
    }   
}
float standerd_deviation_function(struct ContinuousData mean[], int no_of_row,float sum_frequency)
{
    float sd,sum_z2=0;
    int i;
    for ( i = 0; i < no_of_row; i++)
    {
        sum_z2=sum_z2+(mean[i].fz2/mean[i].frequency);
    }
    
    sd=sqrt(sum_z2/sum_frequency);
    printf("Standard Deviation = %0.2f",sd);
    return sd;
}
float variance_function(float sd)
{
    float vr;
    vr=sqrt(sd);
    printf("Variance = %0.2f",vr);
    return vr;
}
void print_centeral_moments(float u1,float u2,float u3,float u4)
{
    printf("Central moments 1 = %0.2f\n",u1);
    printf("Central moments 2 = %0.2f\n",u2);
    printf("Central moments 3 = %0.2f\n",u3);
    printf("Central moments 4 = %0.2f\n",u4);
}
void print_row_moments(float u_1,float u_2,float u_3,float u_4)
{
    printf("Row moments 1 = %0.2f\n",u_1);
    printf("Row moments 2 = %0.2f\n",u_2);
    printf("Row moments 3 = %0.2f\n",u_3);
    printf("Row moments 4 = %0.2f\n",u_4);
}
void print_moments_about_origin_function(float v1,float v2,float v3,float v4)
{
    printf("Moments about origin 1 = %0.2f\n",v1);
    printf("Moments about origin 2 = %0.2f\n",v2);
    printf("Moments about origin 3 = %0.2f\n",v3);
    printf("Moments about origin 4 = %0.2f\n",v4);
    
}
float skewness_function(float gama_1)
{
    if(gama_1<0)
    printf("Distribution of given data is nagatively skewed\n");
    else if(gama_1>0)
    printf("Distribution of given data is positively skewed\n");
    else if(gama_1==0)
    printf("Distribution of given data is Symmetric\n");
    return 0;
}
float kurtosis_function(float gama_2)
{
    if(gama_2<0)
    printf("Distribution of given data is platykurtic\n");
    else if(gama_2>0)
    printf("Distribution of given data is Mesokurtic\n");
    else if(gama_2==0)
    printf("Distribution of given data is Leptokurtic\n");
    return 0 ;
}