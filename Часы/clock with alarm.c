#include <stdio.h>
#include <time.h>

int al_h,al_m;

void AlarmSet()
{
    printf(ALARM_HOUR);scanf("%d",&al_h);
    printf(ALARM_MINS);scanf("%d",&al_m);
}

int AlarmCheck(int h,int m)
{
	if (h==al_h && m==al_m) return 1;
	return 0;
}

int main()
{
	struct tm *		info;												//здесь храним текущее время
    int 			sec_colon=0;
	int				prev_sec=0;											//последнее значение минут
    
    AlarmSet();

	do
	{
		info=GetTime();
		
		if (prev_sec!=info->tm_sec)
		{
			sec_colon=100-sec_colon;
			printf(TIME_LANG,info->tm_hour,(sec_colon?(char*)":":(char*)" "),info->tm_min,info->tm_sec);
			prev_sec=info->tm_sec;
	
		}
		sleep(1);	
		
	} while(!AlarmCheck(info->tm_hour,info->tm_min));
	
	//сработал будильник
	printf("\n RING \n");
	
	return 0;
}


