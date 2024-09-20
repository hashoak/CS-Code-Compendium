import java.util.*;

public class Main_8 {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int firstDigit=a/10000;
        int secondLastDigit=a/10%10;
        System.out.println(firstDigit+secondLastDigit);
        sc.close();
        return;
    }
}
