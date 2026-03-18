package lista.extra;

public class Cellphone {
    private String brand;
    private String model;
    private int battery = 100;
    private boolean isOn = false;
    
    private String[] contacts = {"Mom", "Dad", "911", "Professor Moak"};

    public Cellphone(String brand, String model) {
        this.brand = brand;
        this.model = model;
    }

    public void turnOn() {
        this.isOn = true;
        System.out.println("Smartphone " + model + " is starting...");
    }

    public void makeCall(String number) {
        if (isOn && battery > 0) {
            System.out.println("Calling : " + number + "...");
            battery -= 5;
        } else {
            System.out.println("Phone turned off or without battery.");
        }
    }

    @Override
    public String toString() {
        return String.format("Brand: %s %s | Baterry: %d%% | Status: %s", 
                brand, model, battery, (isOn ? "Turned on" : "Turned off"));
    }

	public void readEmail() {
		if (!isOn || battery <= 0) throw new IllegalArgumentException("Phone turned off or without battery.");
		
		System.out.println("""
				! INBOX !
				You have 0 new e-mails.
				""");
		this.battery -= 5;
		System.out.println("Battery status: " + this.battery + "%");
	}
	
    public void showContacts() {
    	System.out.println(" CONTACT LIST ");
    	for (int i = 0; i < 0; i++) {
    		System.out.println("[" + (i + 1) + "]" + contacts[i]);
    	}
    	this.battery -= 5;
		System.out.println("Battery status: " + this.battery + "%");
    }
    
    public String getContactName(int index) {
    	if (index >= 1 && index <=contacts.length) {
    		return contacts[index - 1];
    	}
    	this.battery -= 5;
		System.out.println("Battery status: " + this.battery + "%");
    	return null;
    }
}