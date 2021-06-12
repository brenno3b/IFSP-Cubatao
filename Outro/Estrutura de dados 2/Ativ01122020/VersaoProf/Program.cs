using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Vendas
{
    class Program
    {
        static void Main(string[] args)
        {
            bool sair = false;
            int opt;

            Vendedores v = new Vendedores();

            do
            {
                Console.WriteLine("0. Sair");
                Console.WriteLine("1. Cadastrar vendedor");
                Console.WriteLine("2. Consultar vendedor");
                Console.WriteLine("3. Excluir vendedor");
                Console.WriteLine("4. Registrar venda");
                Console.WriteLine("5. Listar vendedores");

                opt = Convert.ToInt32(Console.ReadLine());

                switch(opt)
                {
                    case 0:
                        sair = true;
                        break;

                    case 1:
                        int id;
                        string nome;
                        double comissao;

                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o nome do vendedor: ");
                        nome = Console.ReadLine();

                        Console.WriteLine("Digite a comissão do vendedor: ");
                        comissao = Convert.ToDouble(Console.ReadLine());

                        v.addVendedor(new Vendedor(id, nome, comissao));

                        break;

                    case 2:
                        Vendedor v1;
                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o nome do vendedor: ");
                        nome = Console.ReadLine();

                        Console.WriteLine("Digite a comissão do vendedor: ");
                        comissao = Convert.ToDouble(Console.ReadLine());

                        v1 = v.searchVendedor(new Vendedor(id, nome, comissao));

                        Console.WriteLine("Id: " + v1.Id + "\nNome: " + v1.Nome + "\nValor total de vendas: " + v1.valorVendas() + "\nValor da comissão devida: " + v1.valorComissao() + "\nValor médio das vendas: " + v1.valorMedio());
                        break;

                    case 3:
                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o nome do vendedor: ");
                        nome = Console.ReadLine();

                        Console.WriteLine("Digite a comissão do vendedor: ");
                        comissao = Convert.ToDouble(Console.ReadLine());

                        v.delVendedor(new Vendedor(id, nome, comissao));
                        break;

                    case 4:
                        int qtde, dia;
                        double valor;

                        Console.WriteLine("Digite a quantidade da venda: ");
                        qtde = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o valor da venda: ");
                        valor = Convert.ToDouble(Console.ReadLine());

                        Console.WriteLine("Digite o dia da venda: ");
                        dia = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o nome do vendedor: ");
                        nome = Console.ReadLine();

                        Console.WriteLine("Digite a comissão do vendedor: ");
                        comissao = Convert.ToDouble(Console.ReadLine());

                        v.searchVendedor(new Vendedor(id, nome, comissao)).registrarVenda(dia, new Venda(qtde, valor));
                        break;

                    case 5:
                        Console.WriteLine(v.mostraVendedores());
                        break;

                    default:
                        Console.WriteLine("Opção não encontrada !");
                        break;

                }

            } while (!sair);
        }
    }
}
