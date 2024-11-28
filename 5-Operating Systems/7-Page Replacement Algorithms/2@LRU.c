#include <stdio.h>

int lruPageFaults(int frameCount,int pageCount,int* frames,int* pages)
{
    int i, j, k, m, fault = 0;
    int flag = 0;
    int least[10];
    int unusedCount = 0;
    int leastIndex = 0;
    for (i = 0; i < frameCount; ++i) frames[i] = -1;
    j = 0;
    printf("\nPage Replacement Order (LRU): ");
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
            if (unusedCount < frameCount)
            {
                frames[j] = pages[i];
                j = (j + 1) % frameCount;
                fault++;
                unusedCount++;
            }
            else
            {
                for (k = 0; k < frameCount; ++k)
                {
                    least[k] = 0;
                    for (m = i - 1; m >= 0; --m)
                    {
                        if (pages[m] == frames[k])
                        {
                            least[k] = 1;
                            break;
                        }
                    }
                }
                for (k = 0; k < frameCount; ++k)
                {
                    if (least[k] == 0)
                    {
                        leastIndex = k;
                        break;
                    }
                }
                frames[leastIndex] = pages[i];
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

    pagefaults = lruPageFaults(frameCount,pageCount,frames,pages);
    hitratio = (pageCount - pagefaults) / (float)pageCount;
    missratio = 1 - hitratio;
    printf("Page Faults (LRU): %d\n", pagefaults);
    printf("Hit percentage: %f\n", hitratio * 100);
    printf("Miss percentage: %f\n", missratio * 100);
    
    return 0;
}