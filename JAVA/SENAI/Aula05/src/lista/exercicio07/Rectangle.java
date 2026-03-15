package lista.exercicio07;

public class Rectangle {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        setWidth(width);
        setHeight(height);
    }

    public void setWidth(double width) {
        if (width <= 0) throw new IllegalArgumentException("Width must be positive.");
        this.width = width;
    }

    public void setHeight(double height) {
        if (height <= 0) throw new IllegalArgumentException("Height must be positive.");
        this.height = height;
    }

    public double calculateArea() {
        return width * height;
    }

    public double calculatePerimeter() {
        return (width + height) * 2;
    }
    
    public boolean isSquare() {
    	return width == height;
    }
    
    public void displayInfo() {
        System.out.println("Rectangle " + width + "x" + height);
        System.out.println("Area: " + calculateArea());
        System.out.println("Perimeter: " + calculatePerimeter());
        
        if (isSquare()) System.out.println("This is a square.");
        else System.out.println("Not a square.");
    }
}