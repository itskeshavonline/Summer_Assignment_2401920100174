// QUESTION 1: INTERFACE & IMPLEMENTATION
interface Test {
    int square(int num);
}

class Arithmetic implements Test {
    @Override
    public int square(int num) {
        return num * num;
    }
}

class ToTestInt {
    public void runTest() {
        Arithmetic arithmeticObj = new Arithmetic();
        System.out.println("Q1: Square of 5 using Arithmetic object: " + arithmeticObj.square(5));
    }
}

// QUESTION 2: OUTER & INNER CLASSES
class Outer {
    public void display() {
        System.out.println("Q2: Display method from Outer class.");
    }

    class Inner {
        public void display() {
            System.out.println("Q2: Display method from Inner class.");
        }
    }
}

// QUESTION 3: POINT CLASS WITH ENCAPSULATION & CONSTRUCTORS
class Point {
    private int x;
    private int y;

    // Default Constructor
    public Point() {
        this.x = 0;
        this.y = 0;
    }

    // Parameterized Constructor
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Quick helper to display point values
    public void printPoint() {
        System.out.println("Q3: Point coordinates -> X: " + x + ", Y: " + y);
    }
}

// QUESTION 4: INHERITANCE (BOX & BOX3D)
class Box {
    // Making fields protected so the subclass can access them directly
    protected double length;
    protected double breadth;

    // Constructor
    public Box(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public double findArea() {
        return length * breadth;
    }
}

class Box3d extends Box {
    private double height;

    // Constructor calling the super class constructor
    public Box3d(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    public double findVolume() {
        // Volume = length * breadth * height (or area * height)
        return findArea() * height;
    }
}

// MAIN EXECUTION CLASS 
public class Main {
    public static void main(String[] args) {
        
        System.out.println("--- Executing Program 1 ---");
        ToTestInt tester = new ToTestInt();
        tester.runTest();

        System.out.println("\n--- Executing Program 2 ---");
        Outer outerObj = new Outer();
        outerObj.display(); // Calls Outer's display
        
        // Syntax to instantiate an inner class object
        Outer.Inner innerObj = outerObj.new Inner();
        innerObj.display(); // Calls Inner's display

        System.out.println("\n--- Executing Program 3 ---");
        Point p1 = new Point(); // Uses default constructor
        p1.setXY(10, 20);
        p1.printPoint();
        
        Point p2 = new Point(50, 60); // Uses parameterized constructor
        p2.printPoint();

        System.out.println("\n--- Executing Program 4 ---");
        // Creating a 3D Box with Length=5, Breadth=4, Height=3
        Box3d myBox = new Box3d(5.0, 4.0, 3.0);
        System.out.println("Box Surface Area (Base): " + myBox.findArea());
        System.out.println("Box Volume: " + myBox.findVolume());
    }
}


// Problem Statement
// 1. Write a program to create interface named test. In this interface the member function is
// square. Implement this interface in arithmetic class. Create one new class called ToTestInt in this
// class use the object of arithmetic class.
// 2. Create an outer class with a function display, again create another class inside the outer class
// named inner with a function called display and call the two functions in the main class.
// 3. Create class point with following instance variable and methods.
// Instance variable: private int x,y
// Constructors : public Point(), Point(int x, int y)
// Methods : public void setX(int x), setY(int y), setXY(int x, int y)
// 4. Create class box and box3d. box3d is extended class of box. The above
// two classes going to pull fill following requirement
// Include constructor.
// set value of length, breadth, height Find out area and volume.
// Note: Base class and sub classes have respective methods and instance variables.