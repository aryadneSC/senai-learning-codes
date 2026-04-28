package br.com.senai.aryadne.class09.librarySystem;

public class Book extends LibrarySource {
	private int numPages;
	
	public Book(String title, String author, int publicationYear, int numPages) {
		super(title, author, publicationYear);
		
		this.numPages = numPages;
	}
	
	@Override
	public void showDetails() {
		System.out.println("| Name: " + super.getTitle());
		System.out.println("| Author: " + super.getAuthor());
		System.out.println("| Publication Year: " + super.getYear());
		System.out.println("| Number of pages: " + numPages);
	}
}
