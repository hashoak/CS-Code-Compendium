import java.util.*;

public class Main_4 {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        float a,b,c;
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();
        if(a==b && b==c)
        {
            System.out.println("All numbers are equal");
        }
        else if(a!=b && b!=c)
        {
            System.out.println("All numbers are different");
        }
        else
        {
            System.out.println("Neither all are equal or different");
        }
        sc.close();
        return;
    }
}
