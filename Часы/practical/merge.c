#include <stdio.h>

int main()
{
	//������� ���� ��������������� ��������	
    int left[4]={27,73,128,211};
    int right[4]={42,55,142,715};
	
	int merge[8]={0};							//������ - ��������� �������
	
	int lidx=0,ridx=0,midx=0;					//������� ��� �������� �������� � ����������
	
	for (;midx<8;midx++)						//������ - ������� ����� ���������
	{
	    if (left[lidx]<right[ridx])
	    {
	        merge[midx]=left[lidx];lidx++;
	    }
	    else
	    {
	        merge[midx]=right[ridx];ridx++;
	    }
	    if (lidx==4 || ridx==4) break;			//���� ���� ���� ������ "�������" �� �����, ������� �� �����
	}
    midx++;										//������ �� ��������� ������� � �������-����������
    
    if (lidx==4)								//���� "�������" ���� ����� ������, �������� ������� �� ������
        for(;midx<8;midx++)
        	merge[midx]=right[ridx++]; 
    else
        for(;midx<8;midx++)						//����� "�������" ���� ������� ������, �������� ������� �� �����
        	merge[midx]=left[lidx++]; 

	for(midx=0;midx<8;midx++)					//������� ���������
	    printf("[%d] %d\n",midx,merge[midx]);
	
    return 0;
}

