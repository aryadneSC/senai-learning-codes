public class Carro {
    private double combustivel = 0;
    private double consumo;

    public Carro(double consumo) {
        this.consumo = consumo;
    }

    public double getCombustivel() {
        return combustivel;
    }

    public void setCombustivel(double combustivel) {
        this.combustivel = combustivel;
    }

    public double getConsumo() {
        return consumo;
    }

    public void setConsumo(double consumo) {
        this.consumo = consumo;
    }

    public void andar(double distancia) {
        double combustivelGasto = distancia / this.consumo;
        if (combustivelGasto <= this.combustivel) {
            this.combustivel -= combustivelGasto;
        }
    }

    public void abastecer(double quantidade) {
        this.combustivel += quantidade;
    }
}

public class Main {
    public static void main(String[] args) {
        Carro meuFusca = new Carro(10.0);

        meuFusca.abastecer(50.0);
        meuFusca.andar(100.0);
        
        System.out.println("Combustível restante: " + meuFusca.getCombustivel() + " litros");
        
        meuFusca.andar(50.0);
        System.out.println("Combustível após segunda viagem: " + meuFusca.getCombustivel());
    }
}