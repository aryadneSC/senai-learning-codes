public class Carro {
    double combustivel = 0;
    double consumo;

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