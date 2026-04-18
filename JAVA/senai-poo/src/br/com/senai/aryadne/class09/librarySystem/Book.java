package br.com.senai.aryadne.class09.librarySystem;

public class Book extends LibrarySource {
	private int numPages;

	public Book(String title, String author, int publicationYear, int numPages) {
		super(title, author, publicationYear);
		setPages(numPages);
	}

	public void setPages(int numPages) {
		if(numPages < 0) 
			throw new IllegalArgumentException("Please insert a valid number of pages for this book.");
		this.numPages = numPages;
	}
	
	public int getPages() {
		return numPages;
	}
	
	@Override
	void showDetails() {
		System.out.println("Title: " + title);
		System.out.println("Author: " + author);
		System.out.println("Year of Publication: " + publicationYear);
		System.out.println("Number of Pages: " + numPages);
	}
}