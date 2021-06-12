using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Venda
{
    class Vendedores
    {
        private int qnt = 0;
        private List<Vendedor> vendedores = new List<Vendedor>();

        public List<Vendedor> Vendedor
        {
            get => Vendedor;
        }

        public void AddVendedor(Vendedor v)
        {
            if(qnt == 2)
            {
                Console.WriteLine("Não é possível adicionar mais vendedores !\n" +
                    "Número de vendedores cadastrados: " + qnt);
            }
            else
            {
                vendedores.Add(v);
                ++qnt;
            }
        }

        public void DelVendedor(int id)
        {
            try
            {
                if(vendedores.Find(v => v.Id == id).Vendas.Count == 0 )
                {
                    vendedores.RemoveAll(v => v.Id == id);
                }
                else if (vendedores.Find(v => v.Id == id).Vendas.Count > 0)
                {
                    Console.WriteLine("Não é possível deletar este vendedor !\n" +
                        "Delete todas suas vendas para deletar este vendedor.");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Vendedor não encontrado !");
            }
        }

        public Vendedor SearchVendedor(int id)
        {
            if(vendedores.Find(x => x.Id == id) == null)
            {
                Console.WriteLine("Vendedor não encontrado !");
            }
            return vendedores.Find(x => x.Id == id);
        }

        public Vendedores(Vendedor[] v)
        {
            foreach(Vendedor vendedor in v)
            {
                vendedores.Add(vendedor);
            }
        }

        public Vendedores()
        {
            vendedores.Add(new Vendedor());
        }

        public double totalDasVendas()
        {
            double total = 0;

            foreach(Vendedor v in vendedores)
            {
                total += v.TotalVendas();   
            }

            return total;
        }

        public double totalDeComissao()
        {
            double total = 0;

            foreach(Vendedor v in vendedores)
            {
                total += v.ValorComissao();
            }

            return total;
        }

        public string infoVendedores()
        {
            string str = "";

            foreach(Vendedor v in vendedores)
            {
                if(v.Name != "")
                {
                    str += v.infoVendedor() + "\n";
                }
            }

            return str 
                + "\nValor total de todas as vendas de todos os vendedores: R$" + totalDasVendas().ToString("0.00")
                + "\nValor total de comissão de todos os vendedores: R$" + totalDeComissao().ToString("0.00");
        }
    }
}
