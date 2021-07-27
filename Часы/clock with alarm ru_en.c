#include <stdio.h>
#include <time.h>

#define ENGLISH

#ifdef  ENGLISH
#define ALARM_HOUR "Alarm hour "
#define ALARM_MINS "Alarm minutes "
#define TIME_LANG "Current time is %d%s%d.%d \r"
#define RING "RINNNG \a"
#else
#define ALARM_HOUR "Ѕудильник час "
#define ALARM_MINS "Ѕудильник минута "
#define TIME_LANG "“екущее врем€ %d%s%d.%d \r"
#define RING "«вонок \a"
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
    int				prev_sec=0;											//последнее значение минут
	time_t			current_time;										//получение текущего времени
	struct tm *		info;												//здесь храним текущее врем€
    int 			sec_colon=0;
    
    AlarmSet ();
    
	do
	{
		time(&current_time);
		info=localtime(&current_time);
		
		if (prev_sec!=info->tm_sec)										//при переходе через "границу" секунд, мен€ем картинку ":" - " "
		{
			sec_colon=100-sec_colon;
			printf(TIME_LANG,info->tm_hour,(sec_colon?(char*)":":(char*)" "),info->tm_min,info->tm_sec);
			prev_sec=info->tm_sec;
		}	
		sleep(1); 
	} while(!AlarmCheck(info->tm_hour,info->tm_min));														//бесконечный цикл
	
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


