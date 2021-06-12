//Componentes da dupla:
//Brenno Barbosa Bezerra CB3007219
//Diego Pereira Gonzalez Natalo CB3005585

public class Dividend_Yeild {
    public static void main(String[] args) {
        //Dividendo: 16/04/2020 Valor: R$0,02
        //ValorUnitAção: 31/08/2020 16:39 Valor: R$11,31
        //LucroAção: 31/08/2020 Valor: R$1.31
        //Valor da empresa: 31/08/2020 Valor: R$3.002.224.510
        //Patrimônio Líquido: 31/08/2020 Valor: R$2.910.699.000
        Empresa ENAT3 = new Empresa(1.142694, 11.31, 1.31, 3002224510L, 2910699000L);

        //Dividendo: 25/05/2020 Valor: R$0,02
        //ValorUnitAção: 31/08/2020 16:39 Valor: R$9,52
        //LucroAção: 31/08/2020 Valor: R$0,86
        //Valor da empresa: 31/08/2020 Valor: R$83.761.850.789
        //Patrimônio Líquido: 31/08/2020 Valor: R$52.896.000.000
        Empresa ITSA4 = new Empresa(0.02, 9.52, 0.86, 83761850789L, 52896000000L);

        //Dividendo: 21/07/2020 Valor: R$0,126801
        //ValorUnitAção: 31/08/2020 16:39 Valor: R$65,80
        //LucroAção: 31/08/2020 Valor: R$0,91
        //Valor da empresa: 31/08/2020 Valor: R$138.175.708.494
        //Patrimônio Líquido: 31/08/2020 Valor: R$10.362.308.000
        Empresa WEGE3 = new Empresa(0.126801, 65.80, 0.91, 138175708494L, 10362308000L);

        ENAT3.showStats();
        ITSA4.showStats();
        WEGE3.showStats();
    }
}
