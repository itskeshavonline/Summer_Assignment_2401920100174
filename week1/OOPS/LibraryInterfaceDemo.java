public class LibraryInterfaceDemo {
    public static void main(String[] args) {
        
        // Test Case #1: KidUser=======================
        System.out.println("--- Testing KidUser ---");
        KidUsers kid = new KidUsers();
        
        // Test Age 10
        kid.age = 10;
        kid.registerAccount();
        
        // Test Age 18
        kid.age = 18;
        kid.registerAccount();
        
        // Test BookType "Kids"
        kid.bookType = "Kids";
        kid.requestBook();
        
        // Test BookType "Fiction"
        kid.bookType = "Fiction";
        kid.requestBook();
        
        System.out.println(); // Blank line for spacing

        // Test Case #2: AdultUser=======================
        System.out.println("--- Testing AdultUser ---");
        AdultUser adult = new AdultUser();
        
        // Test Age 5
        adult.age = 5;
        adult.registerAccount();
        
        // Test Age 23
        adult.age = 23;
        adult.registerAccount();
        
        // Test BookType "Kids"
        adult.bookType = "Kids";
        adult.requestBook();
        
        // Test BookType "Fiction"
        adult.bookType = "Fiction";
        adult.requestBook();
    }
}
