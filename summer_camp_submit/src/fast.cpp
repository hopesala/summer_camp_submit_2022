#include <iostream>
using namespace std;
#include <math.h>
#include "fast.h"

bool judge_1(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i-r)*cols+j]) > threshold;
}
bool judge_2(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i-r)*cols+j+1]) > threshold;
}
bool judge_3(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i-r+1)*cols+j+2]) > threshold;
}

bool judge_4(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i-1)*cols+j+r]) > threshold;
}
bool judge_5(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[i*cols+j+r]) > threshold;
}
bool judge_6(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i+1)*cols+j+r]) > threshold;
}

bool judge_7(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i+2)*cols+j+r-1]) > threshold;
}

bool judge_8(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i+r)*cols+j+1]) > threshold;
}
bool judge_9(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i+r)*cols+j]) > threshold;
}
bool judge_10(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i+r)*cols+j-1]) > threshold;
}
bool judge_11(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i+r-1)*cols+j-2]) > threshold;
}

bool judge_12(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i+1)*cols+j-r]) > threshold;
}

bool judge_13(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[i*cols+j-r]) > threshold;
}
bool judge_14(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i-1)*cols+j-r]) > threshold;
}
bool judge_15(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i-2)*cols+j-r+1]) > threshold;
}

bool judge_16(DTYPE* img_in, int threshold, int rows, int cols, int i, int j)
{
	int r=3;
	return abs(img_in[i*cols+j] - img_in[(i-r)*cols+j-1]) > threshold;
}

void fast_accel(DTYPE* img_in, int threshold, DTYPE* img_out, int rows, int cols)
{
#pragma HLS INTERFACE s_axilite port=rows  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=cols  bundle=CTRL
    //Write your code here
	int r=3;

	for(int i=r;i<rows-r;i++)
	{
		for(int j=r;j<cols-r;j++)
		{
			int satiffied_cnt=0;
//			printf("=====%d %d %d\n",img_in[i*cols+j], img_in[(i-r)*cols+j], abs(img_in[i*cols+j] - img_in[(i-r)*cols+j]));
			if(judge_1(img_in, threshold,rows,cols,i,j))
			{
				satiffied_cnt++;
			}
			if(judge_5(img_in, threshold,rows,cols,i,j))
			{
				satiffied_cnt++;
			}
			if(judge_9(img_in, threshold,rows,cols,i,j))
			{
				satiffied_cnt++;
			}
			if(judge_13(img_in, threshold,rows,cols,i,j))
			{
				satiffied_cnt++;
			}

			if(satiffied_cnt>=3)
			{
				if(judge_2(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_3(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_4(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_6(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_7(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_8(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_10(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_11(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_12(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_14(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_15(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(judge_16(img_in, threshold,rows,cols,i,j))
							{
								satiffied_cnt++;
							}
				if(satiffied_cnt>=12)
				{
					img_out[i*cols+j]=255;
					printf("Found a corner point @ %d\n", i*cols+j);
				}
			}
		}
	}
}
