import java.io.*;

class Main_2 {
    void m()throws IOException {
        throw new IOException("device error");  // checked exception
    }

    void n() throws IOException {
        m();
    }

    void p() {
        try {
            n();
        } catch (Exception e) {
            System.out.println("exception handled"+e.getMessage());
        }
    }

    public static void main(String args[]) {
        Main_2 obj = new Main_2();
        obj.p();
        System.out.println("normal flow...");
    }
}