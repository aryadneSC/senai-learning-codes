package br.com.senai.aryadne.class02.activity04;

import java.util.Scanner;

public class ControleTV {
	public int canal;
	public int volume;
 public boolean ligado;

	int getCanal() {
		return canal;
	}

	public void setCanal(int canal) {
		this.canal = canal;
	}

	int getVolume() {
		return volume;
	}

	public void setVolume(int volume) {
		this.volume = volume;
	}

	boolean getLigado() {
		return ligado;
	}

	public void setLigado(boolean ligado) {
		this.ligado = ligado;
	}

	void ligar() {
		this.ligado = true;
	}

	void desligar() {
		this.ligado = false;
	}

	void aumentarVolume() {
		if (this.volume < 100) {
			this.volume++;
		}
	}

	void diminuirVolume() {
		if (this.volume > 0) {
			this.volume--;
		}
	}

	void proximoCanal() {
		this.canal++;
	}

	void canalAnterior() {
		if (this.canal > 1) {
			this.canal--;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		ControleTV tv = new ControleTV();

		System.out.println("TV ligada? (true/false):");
		boolean ligado = sc.nextBoolean();
		tv.setLigado(ligado);

		System.out.println("Canal:);
		int canal = sc.nextInt();
		tv.setCanal(canal);

		System.out.println("Volume:);
		int volume = sc.nextInt();
		tv.setVolume(volume);

		System.out.println("-- TV --");
		System.out.println("Estado: " + tv.getLigado());
		System.out.println("Canal: " + tv.getCanal());
		System.out.println("Volume: " + tv.getVolume());

		tv.aumentarVolume();
		System.out.println("\nNovo volume: " + tv.getVolume());

		tv.proximoCanal();
		System.out.println("Novo canal: " + tv.getCanal());

		sc.close();
	}

}