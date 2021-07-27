#include <stdio.h>
#include <time.h>

#define ENGLISH

#ifdef  ENGLISH
#define ALARM_HOUR "Alarm hour "
#define ALARM_MINS "Alarm minutes "
#define TIME_LANG "Current time is %d%s%d.%d \r"
#define RING "RINNNG \a"
#else
#define ALARM_HOUR "��������� ��� "
#define ALARM_MINS "��������� ������ "
#define TIME_LANG "������� ����� %d%s%d.%d \r"
#define RING "������ \a"
#endif


int al_h,al_m;

void AlarmSet()
{
	printf(ALARM_HOUR);scanf("%d",&al_h);
	printf(ALARM_MINS);scanf("%d",&al_m);
}

int AlarmCheck(int h, int m)
{
	if (al_h==h && al_m==m) return 1;
	return 0;
}

int main()
{
    int				prev_sec=0;											//��������� �������� �����
	time_t			current_time;										//��������� �������� �������
	struct tm *		info;												//����� ������ ������� �����
    int 			sec_colon=0;
    
    AlarmSet ();
    
	do
	{
		time(&current_time);
		info=localtime(&current_time);
		
		if (prev_sec!=info->tm_sec)										//��� �������� ����� "�������" ������, ������ �������� ":" - " "
		{
			sec_colon=100-sec_colon;
			printf(TIME_LANG,info->tm_hour,(sec_colon?(char*)":":(char*)" "),info->tm_min,info->tm_sec);
			prev_sec=info->tm_sec;
		}	
		sleep(1); 
	} while(!AlarmCheck(info->tm_hour,info->tm_min));														//����������� ����
	
	printf("\n");
	
 	sec_colon=0;
	do
	{
		printf("%s\r", ((sec_colon&1)? (char*)RING : (char*)"           "));
	    sleep(1);
	}
	while(++sec_colon<6);
	
	
	return 0;
}


