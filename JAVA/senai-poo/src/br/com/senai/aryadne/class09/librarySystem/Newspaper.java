package br.com.senai.aryadne.class09.librarySystem;

public class Newspaper extends LibrarySource {
	private String editionYear;

	public Newspaper(String title, String author, int publicationYear, String editionYear) {
		super(title, author, publicationYear);
		setEditionYear(editionYear);
	}

	public void setEditionYear(String editionYear) {
		if(editionYear == null || editionYear.trim().isEmpty())
			throw new IllegalArgumentException("Please set a valid edition year for this newspaper.");
		this.editionYear = editionYear;
	}
	
	@Override
	void showDetails() {
		System.out.println("Title: " + title);
		System.out.println("Author: " + author);
		System.out.println("Year of Publication: " + publicationYear);
		System.out.println("Edition Year: " + editionYear);
	}
	
}