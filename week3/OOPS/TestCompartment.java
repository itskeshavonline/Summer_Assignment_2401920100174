import java.util.Random;

// Abstract class representing a rail coach
abstract class Compartment {
    // Abstract method to be implemented by subclasses
    public abstract String notice();
}

// FirstClass compartment implementation
class FirstClass extends Compartment {
    @Override
    public String notice() {
        return "First Class: Premium seating. Please ensure you have a valid First Class ticket.";
    }
}

// Ladies compartment implementation
class Ladies extends Compartment {
    @Override
    public String notice() {
        return "Ladies: Reserved exclusively for female passengers. Safe travels!";
    }
}

// General compartment implementation
class General extends Compartment {
    @Override
    public String notice() {
        return "General: Open seating for all valid ticket holders. Expect heavy rush.";
    }
}

// Luggage compartment implementation
class Luggage extends Compartment {
    @Override
    public String notice() {
        return "Luggage: Strictly for cargo and heavy baggage. Passengers not allowed.";
    }
}

// Main Test Class
public class TestCompartment {
    public static void main(String[] args) {
        // Declare an array of Compartment of size 10
        Compartment[] compartments = new Compartment[10];
        Random random = new Random();

        System.out.println("=== Generating Random Train Configuration ===");
        
        // Populate the array with random compartments (1 to 4)
        for (int i = 0; i < compartments.length; i++) {
            // nextInt(4) gives 0-3, adding 1 shifts the range to 1-4
            int randomType = random.nextInt(4) + 1; 

            switch (randomType) {
                case 1:
                    compartments[i] = new FirstClass();
                    break;
                case 2:
                    compartments[i] = new Ladies();
                    break;
                case 3:
                    compartments[i] = new General();
                    break;
                case 4:
                    compartments[i] = new Luggage();
                    break;
            }
        }

        // Check and demonstrate the polymorphic behavior of the notice method
        for (int i = 0; i < compartments.length; i++) {
            System.out.println("Coach " + (i + 1) + " -> " + compartments[i].notice());
        }
    }
}

//question
// Create an abstract class Compartment to represent a rail coach. Provide an abstract function
// notice in this class.
// public abstract String notice();
// Derive FirstClass, Ladies, General, Luggage classes from the compartment class. Override the
// notice function in each of them to print notice message that is suitable to the specific type of
// compartment.
// Create a class TestCompartment.Write main function to do the following:
// Declare an array of Compartment of size 10.
// Create a compartment of a type as decided by a randomly generated integer in the range 1 to 4.
// Check the polymorphic behavior of the notice method.
// [i.e based on the random number genererated, the first compartment can be Luggage, the
// second one could be Ladies and so on..]
