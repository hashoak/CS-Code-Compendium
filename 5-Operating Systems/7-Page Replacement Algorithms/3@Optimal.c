#include <stdio.h>

int optimalPageFaults(int frameCount,int pageCount,int* frames,int* pages)
{
    int i, j, k, m, fault = 0;
    int flag = 0;
    int future[10];
    int index = 0;
    int max = 0;
    for (i = 0; i < frameCount; ++i) frames[i] = -1;
    j = 0;
    printf("\nPage Replacement Order (Optimal): ");
    for (i = 0; i < pageCount; ++i)
    {
        flag = 0;
        for (k = 0; k < frameCount; ++k)
        {
            if (frames[k] == pages[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            if (j < frameCount)
            {
                frames[j++] = pages[i];
                fault++;
            }
            else
            {
                for (k = 0; k < frameCount; ++k)
                {
                    future[k] = 0;
                    for (m = i + 1; m < pageCount; ++m)
                    {
                        if (pages[m] == frames[k])
                        {
                            future[k] = m - i;
                            break;
                        }
                    }
                    if (future[k] == 0)
                    {
                        index = k;
                        break;
                    }
                }
                frames[index] = pages[i];
                fault++;
            }
            printf("%d ", pages[i]);
        }
    }
    printf("\n");
    return fault;
}

int main()
{
    int frameCount, pageCount;
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);
    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);
    int frames[frameCount];
    int pages[pageCount];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < pageCount; ++i) scanf("%d", &pages[i]);
    int pagefaults;
    float hitratio, missratio;

    pagefaults = optimalPageFaults(frameCount,pageCount,frames,pages);
    hitratio = (pageCount - pagefaults) / (float)pageCount;
    missratio = 1 - hitratio;
    printf("Page Faults (Optimal): %d\n", pagefaults);
    printf("Hit percentage: %f\n", hitratio * 100);
    printf("Miss percentage: %f\n", missratio * 100);
    
    return 0;
}