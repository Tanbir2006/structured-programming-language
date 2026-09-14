# include <stdio.h>
# include <stdlib.h>
int main()
{
    int n,i;
    printf("System of Linear Equation Solver\n");
    printf("Number of Variable(2 or 3): ");
    scanf("%d", &n);
    float *ptr_1,*ptr_2,*ptr_3,*ptr_4;

    if(n==2)
    {
         printf("X: \n");
      ptr_1 = (float*) malloc(n * sizeof(float));
       for(i=0;i<n;i++)
    {
        printf("a%d: ",i+1);
        scanf(" %f", &ptr_1[i]);
    }
    printf("Y: \n");
       ptr_2 = (float*) malloc(n * sizeof(float));
       for(i=0;i<n;i++)
    {
        printf("b%d: ",i+1);
        scanf(" %f", &ptr_2[i]);
    }
    printf("Constant: \n");
    ptr_4 = (float*) malloc(n * sizeof(float));
       for(i=0;i<n;i++)
    {
        printf("c%d: ",i+1);
        scanf(" %f", &ptr_4[i]);
    }

    }
    else
    {
         printf("X: \n");
       ptr_1 = (float*) malloc(n * sizeof(float));
       for(i=0;i<n;i++)
    {
        printf("a%d: ",i+1);
        scanf(" %f", &ptr_1[i]);
    }
    printf("Y: \n");
    ptr_2 = (float*) malloc(n * sizeof(float));
       for(i=0;i<n;i++)
    {
        printf("b%d: ",i+1);
        scanf(" %f", &ptr_2[i]);
    }
    printf("Z: \n");
   ptr_3 = (float*) malloc(n * sizeof(float));
       for(i=0;i<n;i++)
    {
        printf("c%d: ",i+1);
        scanf(" %f", &ptr_3[i]);
    }
    printf("Constant: \n");
  ptr_4= (float*) malloc(n * sizeof(float));
       for(i=0;i<n;i++)
    {
        printf("d%d: ",i+1);
        scanf(" %f", &ptr_4[i]);
    }

    }
    float D,Dx,Dy,Dz;
    if(n==3)
    {
       D =  ptr_1[0] * (ptr_2[1] * ptr_3[2] - ptr_2[2] * ptr_3[1])
            - ptr_1[1] * (ptr_2[0] * ptr_3[2] - ptr_2[2] * ptr_3[0])
            + ptr_1[2] * (ptr_2[0] * ptr_3[1] - ptr_2[1] * ptr_3[0]);


        Dx = ptr_4[0] * (ptr_2[1] * ptr_3[2] - ptr_2[2] * ptr_3[1])
            - ptr_4[1] * (ptr_2[0] * ptr_3[2] - ptr_2[2] * ptr_3[0])
            + ptr_4[2] * (ptr_2[0] * ptr_3[1] - ptr_2[1] * ptr_3[0]);


        Dy = ptr_1[0] * (ptr_4[1] * ptr_3[2] - ptr_4[2] * ptr_3[1])
            - ptr_1[1] * (ptr_4[0] * ptr_3[2] - ptr_4[2] * ptr_3[0])
            + ptr_1[2] * (ptr_4[0] * ptr_3[1] - ptr_4[1] * ptr_3[0]);


        Dz = ptr_1[0] * (ptr_2[1] * ptr_4[2] - ptr_2[2] * ptr_4[1])
            - ptr_1[1] * (ptr_2[0] * ptr_4[2] - ptr_2[2] * ptr_4[0])
            + ptr_1[2] * (ptr_2[0] * ptr_4[1] - ptr_2[1] * ptr_4[0]);

    if(D==0&&Dx==0&&Dy==0&&Dz==0)
    {
        printf("Infinite Solution\n");
    }
    else if(D==0){ printf(" No Solution");}
    else{ printf("X= %.2f\nY= %.2f\nZ= %.2f\n",Dx/D, Dy/D, Dz/D);
    }

    }
    else{
        D = ptr_1[0] * ptr_2[1] - ptr_1[1] * ptr_2[0];

        Dx = ptr_4[0] * ptr_2[1] - ptr_4[1] * ptr_2[0];

        Dy = ptr_1[0] * ptr_4[1] - ptr_1[1] * ptr_4[0];
        if(D==0&& Dx==0&&Dy==0)
        {
            printf("Infinite Solution");
        }
        else if(D==0)
            {
                printf("No Solution");
            }
             else{ printf("X= %.2f\nY= %.2f\n ", Dx/D, Dy/D);}
            }
            free(ptr_1);
            free(ptr_2);
            free(ptr_4);

            if(n == 3)
            {
                free(ptr_3);
            }

return 0;

}
