#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <malloc.h>

int comp(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}

void e1(int n)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end;
	int i, j, r;
	int** f, ** g, ** t;
	int elem_c;
	float time_spent;

	srand(time(NULL));


	f = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{

		f[i] = (int*)malloc(n * sizeof(int));

		for (j = 0; j < n; j++)
		{

			f[i][j] = rand() % 100 + 1;

		}
	}

	g = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{

		g[i] = (int*)malloc(n * sizeof(int));

		for (j = 0; j < n; j++)
		{

			g[i][j] = rand() % 100 + 1;

		}
	}

	start = clock();
	t = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		t[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + f[i][r] * g[r][j];
				t[i][j] = elem_c;
			}

		}
	}
	end = clock();

	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time =%.10f ", time_spent / 1000);

	for (i = 0; i < n; i++)
	{
		free(f[i]);
		free(g[i]);
		free(t[i]);
	}
	free(f);
	free(g);
	free(t);

}



void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}

}


void qs(int* items, int left, int right)
{

	int i, j;
	int x, y;

	i = left; j = right;

	x = items[(left + right) / 2];



	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);



}


int main()
{
	int k, h, i, r, x1, y1, x2, y2;
	int* a, * b;
	clock_t start, end;
	float time_spent;
	srand(time(NULL));
	//e1--------------------------------------------------------------------

	do
	{

		printf("1 dlya raboti, 0 vihod\n");
		scanf("%d", &k);
		if (k == 0)
		{
			printf("end\n\n");
			break;
		}
		if (k == 1)
		{
			printf("Vvedite razmer matrici ");
			scanf("%d", &k);
			e1(k);
			printf("\n\n");
		}

	} while (true);

	//e2--------------------------------------------------------------------

	printf("shell 1 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &h);

	a = (int*)malloc(h * sizeof(int));
	for (i = 0; i < h; i++)
	{
		a[i] = rand() % 100;
	}

	start = clock();
	shell(a, h);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(a);
	printf("\n");


	printf("qs 1 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);

	b = (int*)malloc(r * sizeof(int));
	for (i = 0; i < r; i++)
	{
		b[i] = rand() % 100;
	}

	start = clock();
	qs(b, 0, r - 1);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);
	printf("\n");


	//e3--------------------------------------------------------------------

	printf("shell 2 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &h);

	a = (int*)malloc(h * sizeof(int));
	x1 = 1;
	for (i = 0; i < h; i++)
	{
		a[i] = x1;
		x1++;
	}

	start = clock();
	shell(a, h);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(a);
	printf("\n");


	printf("qs 2 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);

	b = (int*)malloc(r * sizeof(int));
	y1 = 1;
	for (i = 0; i < r; i++)
	{
		b[i] = y1;
		y1++;
	}

	start = clock();
	qs(b, 0, r - 1);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);
	printf("\n");


	//e4--------------------------------------------------------------------

	printf("shell 3 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &h);

	a = (int*)malloc(h * sizeof(int));
	x1 = h;
	for (i = 0; i < h; i++)
	{
		a[i] = x1;
		x1--;
	}

	start = clock();
	shell(a, h);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(a);
	printf("\n");


	printf("qs 3 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);

	b = (int*)malloc(r * sizeof(int));
	y1 = r;
	for (i = 0; i < r; i++)
	{
		b[i] = y1;
		y1--;
	}

	start = clock();
	qs(b, 0, r - 1);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);
	printf("\n");


	//e5--------------------------------------------------------------------

	printf("shell 4 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &h);

	a = (int*)malloc(h * sizeof(int));
	x1 = 1;
	x2 = h;
	for (i = 0; i < h; i++)
	{
		if ((h / 2) < h)
		{
			a[i] = x1;
			x1++;
		}
		else
		{
			a[i] = x2;
			x2--;
		}

	}

	start = clock();
	shell(a, h);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(a);
	printf("\n");


	printf("qs 4 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);

	b = (int*)malloc(r * sizeof(int));
	y1 = 1;
	y2 = r;
	for (i = 0; i < r; i++)
	{
		if ((r / 2) < r)
		{
			b[i] = y1;
			y1++;
		}
		else
		{
			b[i] = y2;
			y2--;
		}

	}

	start = clock();
	qs(b, 0, r - 1);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);
	printf("\n");


	//e6--------------------------------------------------------------------



	printf("qs 5 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);
	b = (int*)malloc(r * sizeof(int));
	for (i = 0; i < r; i++)
	{
		b[i] = rand() % 100;
	}
	start = clock();
	qsort(b, r, sizeof(int), comp);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);
	printf("\n");


	printf("qs 6 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);
	b = (int*)malloc(r * sizeof(int));
	y1 = 1;
	for (i = 0; i < r; i++)
	{
		b[i] = y1;
		y1++;
	}
	start = clock();
	qsort(b, r, sizeof(int), comp);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);
	printf("\n");


	printf("qs 7 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);
	b = (int*)malloc(r * sizeof(int));
	y1 = r;
	for (i = 0; i < r; i++)
	{
		b[i] = y1;
		y1--;
	}
	start = clock();
	qsort(b, r, sizeof(int), comp);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);
	printf("\n");


	printf("qs 8 sort\n");
	printf("razmer massiva\n");

	scanf("%d", &r);
	b = (int*)malloc(r * sizeof(int));
	y1 = 1;
	y2 = r;
	for (i = 0; i < r; i++)
	{
		if ((r / 2) < r)
		{
			b[i] = y1;
			y1++;
		}
		else
		{
			b[i] = y2;
			y2--;
		}

	}
	start = clock();
	qsort(b, r, sizeof(int), comp);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time = %.10f\n ", time_spent / 1000);
	free(b);

	return 0;
}