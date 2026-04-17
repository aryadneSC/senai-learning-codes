package br.com.senai.librarySystem;

public class Magazine extends LibrarySource {
	private int edition;

	public Magazine(String title, String author, int publicationYear, int edition) {
		super(title, author, publicationYear);
		setEdition(edition);
	}

	public void setEdition(int edition) {
		if(edition < 0)
			throw new IllegalArgumentException("Please set a valid magazine edition.");
		this.edition = edition;
	}
	
	@Override
	void showDetails() {
		System.out.println("Title: " + title);
		System.out.println("Author: " + author);
		System.out.println("Year of Publication: " + publicationYear);
		System.out.println("Edition: " + edition);
	}
}