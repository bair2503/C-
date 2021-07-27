#include <stdio.h>

int main()
{
	//слияние двух отсортированных массивов	
    int left[4]={27,73,128,211};
    int right[4]={42,55,142,715};
	
	int merge[8]={0};							//массив - результат слияния
	
	int lidx=0,ridx=0,midx=0;					//индексы для исходных массивов и результата
	
	for (;midx<8;midx++)						//логика - слияние через сравнение
	{
	    if (left[lidx]<right[ridx])
	    {
	        merge[midx]=left[lidx];lidx++;
	    }
	    else
	    {
	        merge[midx]=right[ridx];ridx++;
	    }
	    if (lidx==4 || ridx==4) break;			//если хоть один массив "выбрали" до конца, выходим из цикла
	}
    midx++;										//встали на следующий элемент в массиве-результате
    
    if (lidx==4)								//если "выбрали" весь левый массив, копируем остаток из правог
        for(;midx<8;midx++)
        	merge[midx]=right[ridx++]; 
    else
        for(;midx<8;midx++)						//иначе "выбрали" весь правого массив, копируем остаток из левый
        	merge[midx]=left[lidx++]; 

	for(midx=0;midx<8;midx++)					//покажем результат
	    printf("[%d] %d\n",midx,merge[midx]);
	
    return 0;
}

