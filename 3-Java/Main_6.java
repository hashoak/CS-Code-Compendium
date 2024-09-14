public class Main_6 {
    public static void main(String args[])
    {
        int i=10;
        int n=i++%5;
        System.out.println("i="+i+" n="+n);
        i=10;
        n = ++i%5;
        System.out.println("i="+i+" n="+n);
        return;
    }
}
