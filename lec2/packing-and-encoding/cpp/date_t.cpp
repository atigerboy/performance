#include <stdio.h>
#include<stdlib.h>
#include<ctime>
#include<cstring>
using namespace std;
typedef struct
{
    int year:13;
    int month:4;
    int day:4;
}date_t;

int cmp_date( date_t& d1, date_t& d2)
{
    int daysOf1 = d1.year * 365 + d1.month * 30 + d1.day;
    int daysOf2 = d2.year * 365 + d2.month * 30 + d2.day;
    if( daysOf1 > daysOf2 )return 1;
    else if( daysOf1 < daysOf2 ) return -1;
    else return 0;
}
const char filename[]="date_t_w.dat";
void test_save( int n )
{
    if( n == 1 ) n++;
    FILE* pFile = fopen(filename,"wb");
    if( pFile != NULL )
    {
        time_t now  = time(0);
        tm * ltm = localtime(&now);
        date_t date ;
        int day = 0;
        for( int i=0; i<n;i++)
        {
            date.year = 1900 + ltm->tm_year + day/365;
            date.month = 1+ltm->tm_mon + (day%365)/30;
            date.day = 1+ ltm->tm_mday + (day%365)%30;
            fwrite(&date, sizeof(date_t),1, pFile);
            day++;
        }
    }
    fclose(pFile);
}

int test_read()
{
    FILE* pFile = fopen(filename,"rb");
    int n = 0;
    if( pFile != NULL )
    {
        date_t date1;
        date_t date2;
        fread(&date1,sizeof(date_t), 1, pFile );
        n++;
        while( !feof( pFile ))
        {
            fread(&date2,sizeof(date_t), 1, pFile );
            if( cmp_date(date1, date2 ) != 0 )
            {
                n++;
            }
            date1 = date2;
        }
    }
    fclose(pFile);
    return n;
}

int main(int argc, const char* argv[])
{
    if( argc == 1 )
    {
        printf("struct size:%d, int size :%d",sizeof(date_t),sizeof(int));
    }
    else if( argc == 2 && strcmp("r",argv[1]) == 0 ) 
    {
        printf("read file %d",test_read());
    }
    else if( argc == 3 && strcmp("w",argv[1]) == 0  ) 
    {
        int n = atoi(argv[2]);
        test_save(n);
    }

}