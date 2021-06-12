using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Venda
{
    class Vendedor
    {
        private int id;
        private string name;
        private double percComissao;
        private List<Venda> vendas = new List<Venda>();

        public int Id
        {
            get => id;
            set => id = value;
        }

        public string Name
        {
            get => name;
            set => name = value;
        }

        public double PercComissao
        {
            get => percComissao;
            set => percComissao = value;
        }

        public List<Venda> Vendas
        {
            get => vendas;
        }

        public void AddVenda(Venda v)
        {
            vendas.Add(v);
        }

        public Vendedor(int id, string name, double percComissao, Venda[] v)
        {
            this.id = id;
            this.name = name;
            this.percComissao = percComissao;
            
            foreach(Venda venda in v)
            {
                vendas.Add(venda);
            }
        }
        public Vendedor(int id, string name, double percComissao)
        {
            this.id = id;
            this.name = name;
            this.percComissao = percComissao;
        }

        public Vendedor(): this(0, "", 0)
        {
        }

        public double TotalVendas()
        {
            double total = 0;

            foreach(Venda v in vendas)
            {
                total += v.Valor;
            }

            return total;
        }

        public double ValorComissao()
        {
            if(TotalVendas() == 0)
            {
                return 0;
            }
            else
            {
                return TotalVendas() * (percComissao / 100);
            }
        }

        public override string ToString()
        {
            string str = "";

            foreach(Venda v in Vendas)
            {
                str += v.ToString() + "\n\n";
            }

            return "id: " + this.id
                + "\nname: " + this.name
                + "\npercComissao: " + this.PercComissao + "%"
                + "\n\nvendas: \n" + str;
        }

        public double ValorMedio()
        {
            if (vendas.Count <= 0)
            {
                return TotalVendas();
            }
            else
            {
                return TotalVendas() / vendas.Count;
            }
 
        }

        public string infoVendedor()
        {
            return "Id: " + this.id
                + "\nNome: " + this.name
                + "\nValor total de vendas: R$" + TotalVendas().ToString("0.00")
                + "\nValor da comissão devida: R$" + ValorComissao().ToString("0.00")
                + "\nValor médio das vendas: R$" + ValorMedio().ToString("0.00");
        }
    }
}
