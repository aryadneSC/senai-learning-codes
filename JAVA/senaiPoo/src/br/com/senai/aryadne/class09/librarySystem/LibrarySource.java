package br.com.senai.aryadne.class09.librarySystem;

public abstract class LibrarySource {
	private String title;
	private String author;
	private int publicationYear;
	
	public LibrarySource(String title, String author, int publicationYear) {
		setTitle(title);
		setAuthor(author);
		setYear(publicationYear);
	}
	
	public void setTitle(String title) {
		if(title == null || title.trim().isEmpty())
			throw new IllegalArgumentException("Invalid title!");
		this.title = title;
	}
	
	public void setAuthor(String author) {
		if(author == null || author.trim().isEmpty())
			throw new IllegalArgumentException("Invalid name!");
		this.author = author;
	}
	
	public void setYear(int publicationYear) {
		if(publicationYear < 0)
			throw new IllegalArgumentException("Invalid publication year!");
		this.publicationYear = publicationYear;
	}
	
	public String getTitle() {
		return title;
	}
	
	public String getAuthor() {
		return author;
	}
	
	public int getYear() {
		return publicationYear;
	}
	
	public abstract void showDetails();
	
	public void lend() {
		System.out.println("| Material on loan: " + "[" + title + "]");

	}
}