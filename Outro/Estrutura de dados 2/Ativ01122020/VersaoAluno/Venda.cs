using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Venda
{
    class Venda
    {
        private double valor;
        private int dia;

        public double Valor
        {
            get => valor;
            set => valor = value;
        }

        public int Dia
        {
            get => dia;
            set => dia = value;
        }

        public Venda(double valor, int dia)
        {
            this.valor = valor;
            this.dia = dia;
        }

        public Venda(): this(0.0, 1)
        {
        }

        public override string ToString()
        {
            return "valor: " + this.valor.ToString("0.00")
                + "\ndia: " + this.dia;
        }
    }
}
