package br.com.senai.aryadne.class09.librarySystem;

public class Newspaper extends LibrarySource {
	private String editionDate;
	
	public Newspaper(String title, String author, int publicationYear, String editionDate) {
		super(title, author, publicationYear);
		
		this.editionDate = editionDate;
	}
	
	@Override
	public void showDetails() {
		System.out.println("| Name: " + super.getTitle());
		System.out.println("| Author: " + super.getAuthor());
		System.out.println("| Publication Year: " + super.getYear());
		System.out.println("| Edition date: " + editionDate);
	}
}
