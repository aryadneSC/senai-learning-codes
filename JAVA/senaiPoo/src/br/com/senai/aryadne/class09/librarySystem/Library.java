package br.com.senai.aryadne.class09.librarySystem;

import java.util.ArrayList;

public class Library {
	ArrayList<LibrarySource> source = new ArrayList<>();
	
	public void addMaterial(LibrarySource material) {
		source.add(material);
	}
	
	public void readMaterial() {
		if(source.isEmpty()) {
			System.out.println("Library is empty.");
			return;
		}
		
		for(LibrarySource s : source) {
			s.showDetails();
		}
	}
	
	public LibrarySource readByTitle(String title) {	
		for(LibrarySource t : source) {
			if(title.equals(t.getTitle())) {
				return t;
			}
		}
		return null;
	}
	
	public void lendMaterial(LibrarySource material) {
		material.lend();
		source.remove(material);
	}
}
