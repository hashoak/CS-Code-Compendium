import java.util.*;

public class Main_7 {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int aNumber=sc.nextInt();
        if (aNumber>=0)
        {
            if (aNumber==0)
            {
                System.out.println("First String");
            }
            else System.out.println("Second String");
        }
        System.out.println("Third String");
        sc.close();
        return;
    }
}
