#include <stdio.h>
#include <time.h>

int main()
{
    int				prev_sec=0;											//��������� �������� �����
	time_t			current_time;										//��������� �������� �������
	struct tm *		info;												//����� ������ ������� �����
    int 			sec_colon=0;
    
	do
	{
		time(&current_time);
		info=localtime(&current_time);
		
		if (prev_sec!=info->tm_sec)										//��� �������� ����� "�������" ������, ������ �������� ":" - " "
		{
			sec_colon=100-sec_colon;
			printf("Current time is %d %s %d.%d \r",info->tm_hour,(sec_colon?(char*)":":(char*)" "),info->tm_min,info->tm_sec);
			prev_sec=info->tm_sec;
		}	
		
	} while(1);															//����������� ����
	
	return 0;
}


