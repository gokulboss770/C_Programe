#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin;
    FILE *fout;
    int temp[100];
    int i = 0, count = 0;

    // Open the input file in read mode
    fin = fopen("temperature.csv", "r");

    if (fin == NULL)
        {
        printf("The input file is not available\n");
        }
    else
        {
        // Read integers from the file into the array
        while(!feof(fin))
        {
            fscanf(fin, "%d", &temp[i]);
            printf("%d.%d\n",i+1,temp[i]);
            i++;
            count++;
        }
        fclose(fin);
    }

    // Open the output file in write mode
    fout = fopen("output.csv", "w");

    if (fout == NULL)
        {
        printf("The output file is not available\n");

        }
    else
        {
        fprintf(fout, "Temperatures greater than 95 degrees:\n");

        for (i = 0; i < count; i++)
            {
            if (temp[i] > 95)
                {
                    fprintf(fout, "%d\n", temp[i]);
                }
            }
            fclose(fout);
    }

    printf("Processing complete. Check output.csv\n");

    return 0;
}
