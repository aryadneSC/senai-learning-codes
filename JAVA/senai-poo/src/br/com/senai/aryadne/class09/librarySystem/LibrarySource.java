package br.com.senai.aryadne.class09.librarySystem;

abstract class LibrarySource {
	protected String title;
	protected String author;
	protected int publicationYear;
	
	public LibrarySource(String title, String author, int publicationYear) {
		setTitle(title);
		setAuthor(author);
		setPublicationYear(publicationYear);
	}

	protected void setPublicationYear(int publicationYear) {
		if(publicationYear < 0) 
			throw new IllegalArgumentException("Please insert a valid year of publication.");
		this.publicationYear = publicationYear;
	}

	protected void setAuthor(String author) {
		if(author == null || author.trim().isEmpty()) 
			throw new IllegalArgumentException("Please insert a valid author name.");
		this.author = author;
	}

	protected void setTitle(String title) {
		if(title == null || title.trim().isEmpty())
			throw new IllegalArgumentException("Please insert a valid title.");
		this.title = title;
	}
	
	protected int getPublicationYear() {
		return publicationYear;
	}
	
	protected String getAuthor() {
		return author;
	}
	
	protected String getTitle() {
		return title;
	}
	
	void showDetails() {
		System.out.println("Title: " + title);
		System.out.println("Author: " + author);
		System.out.println("Year of Publication: " + publicationYear);
	}
	
	public void borrow() {
		System.out.println("Borrowed title: " + title);	
		
	}
}
