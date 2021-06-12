using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Venda
{
    class Program
    {
        static void Main(string[] args)
        {
            /*Venda[] venda =
            {
                new Venda(25.00, 25),
                new Venda(30.50, 30)
            };

            Vendedor vendedor = new Vendedor(1, "Brenno", 5, venda);

            Console.WriteLine(vendedor.ToString());*/

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
                Console.WriteLine("5. Listar vendedores\n");

                opt = Convert.ToInt32(Console.ReadLine());

                switch (opt)
                {
                    case 0:
                        sair = true;
                        break;

                    case 1:
                        Console.Clear();

                        int id;
                        string nome;
                        double comissao;

                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o nome do vendedor: ");
                        nome = Console.ReadLine();

                        Console.WriteLine("Digite a comissão do vendedor: ");
                        comissao = Convert.ToDouble(Console.ReadLine());

                        v.AddVendedor(new Vendedor(id, nome, comissao));

                        Console.WriteLine("Pressione qualquer tecla para continuar...");

                        Console.ReadKey();

                        Console.Clear();

                        break;

                    case 2:
                        Console.Clear();

                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine(v.SearchVendedor(id));
                        Console.WriteLine("Pressione qualquer tecla para continuar...");

                        Console.ReadKey();

                        Console.Clear();

                        break;

                    case 3:
                        Console.Clear();

                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        v.DelVendedor(id);

                        Console.WriteLine("Pressione qualquer tecla para continuar...");

                        Console.ReadKey();

                        Console.Clear();

                        break;

                    case 4:
                        Console.Clear();

                        int dia;
                        double valor;

                        Console.WriteLine("Digite o valor da venda: ");
                        valor = Convert.ToDouble(Console.ReadLine());

                        Console.WriteLine("Digite o dia da venda: ");
                        dia = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Digite o id do vendedor: ");
                        id = Convert.ToInt32(Console.ReadLine());

                        v.SearchVendedor(id).AddVenda(new Venda(valor, dia));

                        Console.WriteLine("Pressione qualquer tecla para continuar...");

                        Console.ReadKey();

                        Console.Clear();

                        break;

                    case 5:
                        Console.Clear();

                        Console.WriteLine(v.infoVendedores());
                        Console.WriteLine("Pressione qualquer tecla para continuar...");

                        Console.ReadKey();

                        Console.Clear();

                        break;

                    default:
                        Console.Clear();

                        Console.WriteLine("Opção não encontrada !");
                        Console.WriteLine("Pressione qualquer tecla para continuar...");

                        Console.ReadKey();

                        Console.Clear();

                        break;

                }

            } while (!sair);
        }
    }
}
