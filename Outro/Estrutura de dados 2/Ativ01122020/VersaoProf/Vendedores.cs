using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Vendas
{
    class Vendedores
    {
        private Vendedor[] osVendedores;
        private int max = 10, qtde = 0;

        public string mostraVendedores()
        {
            string ret = "";
            foreach (Vendedor c in this.osVendedores)
            {
                ret += c.dados();
            }
            ret += "-------------------------";
            return ret;
        }

        public bool addVendedor(Vendedor v)
        {
            bool podeAdicionar = (this.qtde < this.max);
            if (podeAdicionar)
            {
                this.osVendedores[this.qtde] = v;
                this.qtde++;
            }

            return podeAdicionar;
        }

        public bool delVendedor(Vendedor v)
        {
            bool temVendedor = false;
            foreach(Vendedor vendedor in this.osVendedores)
            {
                if (vendedor.Equals(v))
                {
                    v.Id = -1;
                    v.Nome = "";
                    v.PercComissao = 0;
                    temVendedor = true;
                }
            }

            return temVendedor;
        }

        public Vendedor searchVendedor(Vendedor v)
        {
            Vendedor vendedorAchado = new Vendedor(-1, "", 0.0);

            int i = 0;

            while (i < this.max && !this.osVendedores[i].Equals(v))
            {
                i++;
            }
            if (i < this.max)
            {
                vendedorAchado = this.osVendedores[i];
            }

            return vendedorAchado;
        }

        public double valorVendas()
        {
            double valorTotal = 0;

            for(int i = 0; i < osVendedores.Length; i++)
            {
                valorTotal += osVendedores[i].valorVendas();
            }

            return valorTotal;
        }

        public double valorComissao()
        {
            double comissaoTotal = 0;

            for(int i = 0; i < osVendedores.Length; i++)
            {
                comissaoTotal = osVendedores[i].valorComissao();
            }

            return comissaoTotal;
        }
    }
}
