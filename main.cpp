#include "stdafx.h"
#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>



const int MAX_COUNT = 10000000000;

byte pData[MAX_COUNT];

void TestNoLoopFor()

{

	clock_t startTime = clock();

	pData[MAX_COUNT - 1] = 1;



	for (int i = 0; i < MAX_COUNT; i++) {

		if (pData[i] == 1) {

			printf("찾았다! : %d\n", i);

		}

	}



	printf("TestNoLoopFor 소요시간: %d\n", clock() - startTime);

}

void TestLoopFor()

{

	clock_t startTime = clock();

	pData[MAX_COUNT - 1] = 1;



#pragma omp parallel //shared(pData)

	{
#pragma omp for

		for (int i = 0; i < MAX_COUNT; i++) {

			if (pData[i] == 1) {

				printf("찾았다! : %d\n", i);

			}

		}

	}
	printf("TestLoopFor 소요시간: %d\n", clock() - startTime);

}

int _tmain(int argc, _TCHAR* argv[])

{

	printf("OpenMP version %d:\n", _OPENMP);



	TestNoLoopFor();

	TestLoopFor();



	return 0;

}