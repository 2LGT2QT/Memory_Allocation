#include<stdio.h>

int main() {

    int i, j, nb, nf, b[50], f[50], frag[50], ind[50], ch, temp;

    printf("Enter the no of blocks : ");
    scanf("%d", &nb);

    for (i = 0; i < nb; i++) {
        printf("Enter size of block #%d : ", (i + 1));
        scanf("%d", &b[i]);
    }


    printf("\n\nEnter the no of files : ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++) {
        printf("Enter size of file #%d : ", (i + 1));
        scanf("%d", &f[i]);
    }

    printf("\n1.First Fit\n2.Best Fit\n3.Worst Fit\nEnter your choice : ");
    scanf("%d",&ch);

    switch(ch){
        case 1:
            printf("\n\nFirst First Allocation");
            break;

        case 2:
            printf("\n\nBest First Allocation");

            for (i = 0; i < nb; ++i)
            {
                for (j = i + 1; j < nb; ++j)
                {
                    if (b[i] > b[j])
                    {
                        temp =  b[i];
                        b[i] = b[j];
                        b[j] = temp;
                    }
                }
            }
            break;

        case 3:
            printf("\n\nWorst First Allocation");
            for (i = 0; i < nb; ++i)
            {
                for (j = i + 1; j < nb; ++j)
                {
                    if (b[i] < b[j])
                    {
                        temp =  b[i];
                        b[i] = b[j];
                        b[j] = temp;
                    }
                }
            }
            break;
    }

    for (i = 0; i < nb; i++) {
        frag[i] = b[i];
    }


    for (i = 0; i < nf; i++) {
        for (j = 0; j < nb; j++) {
            if (frag[j] >= f[i] && frag[j] == b[j]) {
                frag[j] -= f[i];
                ind[i] = j;
                break;
            }
            if (j == nb - 1) {
                ind[i] = -1;

            }
        }
    }


    printf("\n\nFILE NO\t\t\tFILE SIZE\t\tBLOCK NO\t\tBLOCK SIZE\t\tFRAGMENT");
    for (i = 0; i < nf; i++) {
        if (ind[i] != -1)
            printf("\n%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d", (i + 1), f[i], ind[i], b[ind[i]], frag[ind[i]]);
        else
            printf("\n%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d", (i + 1), f[i], 0, 0, 0);
    }

    return 0;
}
