package br.com.senai.aryadne.class09.librarySystem;

public class Magazine extends LibrarySource {
	private int edition;
	
	public Magazine(String title, String author, int publicationYear, int edition) {
		super(title, author, publicationYear);
		
		this.edition = edition;
	}
	
	@Override
	public void showDetails() {
		System.out.println("| Name: " + super.getTitle());
		System.out.println("| Author: " + super.getAuthor());
		System.out.println("| Publication Year: " + super.getYear());
		System.out.println("| Edition: " + edition);
	}
}
