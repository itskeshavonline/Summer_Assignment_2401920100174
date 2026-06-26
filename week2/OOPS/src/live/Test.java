package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {
    public static void main(String[] args) {
        
        // a. Create an instance of Veena and call play() method
        System.out.println("--- Part A ---");
        Veena veena = new Veena();
        veena.play();

        // b. Create an instance of Saxophone and call play() method
        System.out.println("\n--- Part B ---");
        Saxophone saxophone = new Saxophone();
        saxophone.play();

        // c. Place the above instances in a variable of type Playable and then call play()
        System.out.println("\n--- Part C (Polymorphism) ---");
        Playable p;

        p = veena;       // Pointing to the Veena instance
        p.play();

        p = saxophone;   // Pointing to the Saxophone instance
        p.play();
    }
}