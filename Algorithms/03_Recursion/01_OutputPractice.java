// Learning recursion by printing numbers from n to 1 and then from 1 to n
class Test {
    public static void main(String[] args) {
        print(5);
    }

    public static void print(int n) {
        if (n == 0) {
            return;
        }
        System.out.println(n);
        print(n - 1);
        System.out.println(n);
    }
}