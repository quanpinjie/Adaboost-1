#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"ada.h"

void Evaluation2(int argc, char *argv[]){

 	int i,j;
	FILE *fp,*fp2,*fp_inputd,*fp_inputl;
	double s_y=0,thore;
	int *ym;
	data *L_data;
	int *s_flag;
	double *sepa,*alpha;
        
	if ((fp = fopen("class_p_2", "w+")) == NULL) {
                printf("file open error!!\n");
        }

        if ((fp2 = fopen("class_m_2", "w+")) == NULL) {
                printf("file open error!!\n");
        }


	fp_inputd = fopen( argv[1], "r" );
	if( fp_inputd == NULL )
	{
		printf( "%s is dont open\n",argv[1]);
	}
	
	fp_inputl = fopen( argv[2], "r" );
	if( fp_inputl == NULL )
	{
		printf( "%s is dont open\n",argv[2]);
	}
	
	fseek(fp_inputd,  0L, SEEK_END);
	i = ftell(fp_inputd);
     L_data = (struct data*)malloc(sizeof(struct data)*i);
     if (L_data == NULL) {
         printf( "memory allocation error\n" );
         exit(EXIT_FAILURE);
     }

	fseek(fp_inputl,  0L, SEEK_END);
	i = ftell(fp_inputl);
	sepa=(double *)malloc(sizeof(double)*i);
	s_flag=(int *)malloc(sizeof(int)*i);
	alpha=(double *)malloc(sizeof(double)*i);

	fseek(fp_inputd, 0L,SEEK_SET);
	fseek(fp_inputl, 0L,SEEK_SET);
	i=0;	
	while((fscanf( fp_inputd, "%lf %lf %d", &L_data[i].x, &L_data[i].y, &L_data[i].qul )) != EOF)
        {
        i++;
        }
	i=0;

	while((fscanf( fp_inputl, "%d %lf %lf", &s_flag[i], &sepa[i], &alpha[i] )) != EOF)
        {
        i++;
        }

	L_data[0].num = i;

	ym = (int *)malloc(sizeof(int)*L_data[0].num);

	for(i=0;i<L_data[0].num;i++){
                        for(j=0;j<L_data[0].num;j++){
                                if(s_flag[j] == 1)
                                {
                                thore = sepa[j];
                                s_y += alpha[j] * w_func_x_p2(thore,L_data,i) ;
//                                printf("x %lf y %lf label %d thore %lf alpha %lf w_f_x_p %lf s_y1 %lf\n",L_data[i].x,L_data[i].y,L_data[i].qul,thore,alpha[j],w_func_x_p2(thore,L_data,i),s_y);
                                }
                                if(s_flag[j] == 2)
                                {
                                thore = sepa[j];
                                s_y += alpha[j] * w_func_x_m2(thore,L_data,i) ;
//                                printf("x %lf y %lf label %d thore %lf alpha %lf w_f_x_m %lf s_y2 %lf\n",L_data[i].x,L_data[i].y,L_data[i].qul,thore,alpha[j],w_func_x_m2(thore,L_data,i),s_y);
                                }
                                if(s_flag[j] == 3)
                                {
                                thore = sepa[j];
                                s_y += alpha[j] * w_func_y_p2(thore,L_data,i) ;
//                                 printf("x %lf y %lf label %d thore %lf alpha %lf w_f_y_p %lf s_y3 %lf\n",L_data[i].x,L_data[i].y,L_data[i].qul,thore,alpha[j],w_func_y_p2(thore,L_data,i),s_y);
                                }
                                if(s_flag[j] == 4)
                                {
                                thore = sepa[j];
                                s_y += alpha[j] * w_func_y_m2(thore,L_data,i) ;
//                                printf("x %lf y %lf label %d thore %lf alpha %lf w_f_y_m %lf s_y4 %lf\n",L_data[i].x,L_data[i].y,L_data[i].qul,thore,alpha[j],w_func_y_m2(thore,L_data,i),s_y);
                                }
                        }
                printf("s_y %lf\n",s_y);
                if(s_y > 0){
                        ym[i] = 1;
                }
                else{
                        ym[i] = -1;
                }
                if(ym[i] ==1)
                {
			 fprintf(fp,"%lf %lf %d\n",L_data[i].x,L_data[i].y,ym[i]);
                }
                else if(ym[i] == -1)
                {
                        fprintf(fp2,"%lf %lf %d\n",L_data[i].x,L_data[i].y,ym[i]);
                }
                s_y = 0;
                }
                
	free(L_data);
	free(ym);        
}
int main(int argc, char *argv[]){
	
 Evaluation2(argc, argv);
}
