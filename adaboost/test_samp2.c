#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.14159
#define FOMULA(X) 10*1/sqrt(2*PI)*1*exp(-1*pow(((X)-(1)),2)*1/(2*pow(1,2)))

int main(int *argc, char *argv[])
{
  int i,samp;
  double x,y,samp2;
  samp = atoi(argv[1]);
  samp2 = atof(argv[1]);
  FILE *fp,*fp2;

	if ((fp = fopen("smpl_p", "w+")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	
	}

	if ((fp2 = fopen("smpl_m", "w+")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	
	}
  srand( (unsigned int)time( NULL ) );

  for( i=0; i<samp/4; i++ ){
    
		x = 5*(rand()%samp)/samp2;
                y = 5*(rand()%samp)/samp2;  
                if(y > FOMULA(x)){
			fprintf(fp, "%lf\t", x );
			fprintf(fp, "%lf\t", y );
			fprintf(fp,"1");
			fprintf(fp,"\n");
		}
		 else {
			fprintf(fp2, "%lf\t", x );
                        fprintf(fp2, "%lf\t", y );
                        fprintf(fp2,"-1");
			fprintf(fp2,"\n");
                }
  	
   }
  for( i=0; i<samp/4; i++ ){

                x = -5*(rand()%samp)/samp2;
                y = 5*(rand()%samp)/samp2;
                if(y > FOMULA(x)){
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"1");
                        fprintf(fp,"\n");
                }
                 else {
                        fprintf(fp2, "%lf\t", x );
                        fprintf(fp2, "%lf\t", y );
                        fprintf(fp2,"-1");
                        fprintf(fp2,"\n");
                } 

   } 
  
   for( i=0; i<samp/4; i++ ){

                x = 5*(rand()%samp)/samp2;
                y = -5*(rand()%samp)/samp2;
                if(y > FOMULA(x)){
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"1");
                        fprintf(fp,"\n");
                }
                 else {
                        fprintf(fp2, "%lf\t", x );
                        fprintf(fp2, "%lf\t", y );
                        fprintf(fp2,"-1");
                        fprintf(fp2,"\n");
                } 

   } 

  for( i=0; i<samp/4; i++ ){

                x = -5*(rand()%samp)/samp2; 
                y = -5*(rand()%samp)/samp2;
         
                if(y > FOMULA(x)){
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"1");
                        fprintf(fp,"\n");
                }
                 else {
                        fprintf(fp2, "%lf\t", x );
                        fprintf(fp2, "%lf\t", y );
                        fprintf(fp2,"-1");
                        fprintf(fp2,"\n");
                }
	
 	}
  return 0;
}
