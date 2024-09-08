import java.util.*;

public class Main_3 {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        float arr[]=new float[5];
        float sum=0,avg;
        for(int i=0;i<5;i++)
        {
            arr[i]=sc.nextFloat();
            sum+=arr[i];
        }
        avg=sum/5;
        System.out.println("Sum of the five numbers: "+sum);
        System.out.println("Average of the five numbers: "+avg);
        sc.close();
        return;
    }
}
