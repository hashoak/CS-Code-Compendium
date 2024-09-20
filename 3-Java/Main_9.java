import java.io.IOException;

class Main_9 {
    void m() throws IOException {
        throw new IOException("device error");// checked exception
    }
    void n() throws IOException {
        m();
    }
    void p() {
        try {
            n();
        } catch (Exception e) {
            System.out.println(e+" exception handled");
        }
    }
    public static void main(String args[]) {
        Main_9 obj = new Main_9();
        obj.p();
        System.out.println("normal flow...");
    }
}