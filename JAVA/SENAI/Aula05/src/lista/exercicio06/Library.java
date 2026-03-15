package lista.exercicio06;

public class Library { 
    private String title;
    private String author;
    private int numOfPages;
    private boolean isAvailable;
    
    public Library(String title, String author, int numOfPages, boolean isAvailable) {
        setTitle(title); 
        setAuthor(author);
        setPages(numOfPages);
        setIsAvailable(isAvailable);
    }
    
    public void setTitle(String title) {
        if (title == null || title.trim().isEmpty()) 
            throw new IllegalArgumentException("Title invalid.");
        this.title = title;
    }
    
    public void setAuthor(String author) {
        if (author == null || author.trim().isEmpty()) 
            throw new IllegalArgumentException("Author's name invalid.");
        this.author = author;
    }
    
    public void setPages(int numOfPages) {
        if (numOfPages <= 0) 
            throw new IllegalArgumentException("Number of pages invalid.");
        this.numOfPages = numOfPages;
    }
    
    public void setIsAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }
    
    public void borrowBook() {
        if (this.isAvailable) {
            this.isAvailable = false;
            System.out.println("The book '" + title + "' was successfully borrowed!");
        } else {
            System.out.println("Sorry, the book '" + title + "' is already borrowed.");
        }
    }

    public void returnBook() {
        if (!this.isAvailable) {
            this.isAvailable = true;
            System.out.println("The book'" + title + "' was returned. Thank you!");
        } else {
            System.out.println("This book is already at our library.");
        }
    }
    
    public void displayInfo() {
        System.out.println("Title: " + title + " | Author: " + author);
        System.out.println("Number of pages: " + numOfPages);
        System.out.println("Status: " + (isAvailable ? "Available" : "Borrowed"));
        System.out.println("----------------------------");
    }
}