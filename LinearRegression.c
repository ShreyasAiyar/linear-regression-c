// Super Simple implementation of Linear Regression In C using Batch Gradient Descent
// Parameters : X, Y, W1, B
// Learning Rate : 0.01
// Loss Function : Squared (MSE)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float* regression(int *, int *, float, int, float *, float *);
float batch_gradient_descent(int *, int *, int, float, float*, float*);
float predict(int, float*, float *);

int main(int argc, char *argv[]){


	//Input Data
	int x[10] = {1,2,3,4,5,6,7,8,9,10};
	int y[10] = {2,4,6,9,15,12,15,17,20,30};

	//Parameters
	float learning_rate = 0.01;
	int num_iterations = 100;

	//Initialize Parameters
	srand(time(NULL));
	float w = rand() % (1 - 0 + 1) + 0;
	float b = 0;

	printf("Inital Value Of w %f \n", w);
	printf("Initial Value Of b %f \n", b);

	float *cost = regression(x, y, learning_rate, num_iterations, &w, &b);

	printf("Final Value Of w %f \n", w);
	printf("Final Value Of b %f \n \n", b);

	printf("Predicted Value For 10 is %f \n",predict(10,&w,&b));

	printf("Cost Values \n");
	for(int i=0; i<num_iterations; i++){
		printf("Cost %d %f \n",i,cost[i]);
	}


	exit(0);

}


float* regression(int *x, int *y, float learning_rate, int num_iterations, float *w, float *b){

	float *cost = (float*) malloc(sizeof(float)*num_iterations);
	int n = 10;

	for(int i=0; i<num_iterations; i++){
		cost[i] = batch_gradient_descent(x, y, n, learning_rate, w, b);
	}

	return cost;
}


float batch_gradient_descent(int *x, int *y, int n, float learning_rate, float *w, float *b){

	float db = 0.0;
	float dw = 0.0;
	float cost = 0.0;

	for(int i=0; i<n; i++){

		cost += pow(((*w * x[i] + *b) - y[i]),2);
		db += (*w * x[i] + *b) - y[i];
		dw += ((*w * x[i] + *b) - y[i])*x[i];
	}

	cost /= n;
	*w = *w - learning_rate*(dw)/n;
	*b = *b - learning_rate*(db)/n;

	return cost;
}


float predict(int x, float *w, float *b){

	float y = *w * x + *b;
	return y;

}




