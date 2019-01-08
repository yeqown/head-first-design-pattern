public class Testcase {
    public static void main(String[] args) {
        Coffee cof = new Coffee();
        Tea tea = new Tea();

        System.out.println("Making coffee...");
        cof.prepareRecipe();
        System.out.println("\nMaking tea...");
        tea.prepareRecipe();
    }
}