using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Vendas
{
    class Vendedor
    {
        private int id;
        private string nome;
        private double percComissao;
        private Venda[] asVendas;

        public int Id
        {
            get => id;
            set => id = value;
        }

        public string Nome
        {
            get => nome;
            set => nome = value;
        }

        public double PercComissao
        {
            get => percComissao;
            set => percComissao = value;
        }

        public Vendedor(int id, string nome, double percComissao)
        {
            this.id = id;
            this.nome = nome;
            this.percComissao = percComissao;
            this.asVendas = new Venda[31];

            for (int i = 0; i < 31; i++)
            {
                this.asVendas[i] = new Venda();
            }
        }

        public void registrarVenda(int dia, Venda venda)
        {
            this.asVendas[dia - 1] = venda;
        }

        public double valorVendas()
        {
            double valorTotal = 0;

            for(int i = 0; i < asVendas.Length; i++)
            {
                valorTotal += asVendas[i].Valor;
            }

            return valorTotal;
        }

        public double valorComissao()
        {
            return valorVendas() * (percComissao / 100);
        }

        public string dados()
        {
            return this.id.ToString() + " - " + this.Nome + " - " + this.PercComissao + "%" + '\n';
        }

        public double valorMedio()
        {
            int qtd = 0;
            double valor = 0;

            foreach(Venda v in asVendas)
            {
                if(v.Valor != 0.0)
                {
                    qtd++;
                }

                valor += v.Valor;
            }

            return valor / qtd;
        }
    }
}