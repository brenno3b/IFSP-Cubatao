public class Empresa {

    //Constructor
    public Empresa (double _divAnual, double _valorUnit, double _lucroAcao, long _valorEmpresa, long _patriLiq) {
        this.divAnual = _divAnual;
        this.valorUnit = _valorUnit;
        this.lucroAcao = _lucroAcao;
        this.valorEmpresa = _valorEmpresa;
        this.patriLiq = _patriLiq;

        CalcDy();
        CalcPl();
        CalcPvp();
    }

    public double divAnual, valorUnit, dy, pl, pvp, lucroAcao;
    public long valorEmpresa, patriLiq;

    /**
     * Metodo que calcula o Dividend Yield (DY) - Dividendo Anual / Valor unitario da acao
     */
    public void CalcDy() {
        this.dy = (divAnual/valorUnit) * 100;
    }

    /**
     * Metodo que calcula o preco sobre lucro (PL) - Valor unitario da acao / Lucro da acao
     */
    public void CalcPl() {
        this.pl = valorUnit/lucroAcao;
    }

    /**
     * Metodo que calcula o P/VP - Valor da empresa / Patrimonio liquido
     */
    public void CalcPvp() {
        this.pvp = valorEmpresa/patriLiq;
    }

    /**
     * Mostra as estatisticas DY, P/PL e P/VP
     */
    public void showStats() {
        System.out.printf(
                "O dividend Yield é: %f\n" +
                "O P/PL é: %f\n" +
                "O P/VP é: %f\n\n", dy, pl, pvp);
    }
}
