using System;
using System.Collections.Generic;
using System.Text;
//Douglas Willian CB3005348
//João Vitor Gino CB3005488
namespace WebTrab01
{
    class Book
    {
        private string name { get; set; }
        private Author[] authors { get; set; }
        private double price { get; set; }
        private int qty { get; set; } = 0;

        public BookList list { get; set; }

        public Book(string n, Author[] aus, double p)
        {
            name = n;
            authors = aus;
            price = p;
        }

        //public Book()
        //{
        //}

        public Book(string n, Author[] aus, double p, int q)
        {
            name = n;
            authors = aus;
            price = p;
            qty = q;
        }

        public string GetName()
        {
            return name;
        }

        public Author[] GetAuthors()
        {
            return authors;
        }

        public double GetPrice()
        {
            return price;
        }

        public int GetQty()
        {
            return qty;
        }


        public void SetName(string n)
        {
            name = n;
        }

        public void SetAuthors(Author[] aus)
        {
            authors = aus;
        }

        public void SetPrice(double p)
        {
            price = p;
        }

        public void SetQty(int q)
        {
            qty = q;
        }

        public string getAuthorsNames()
        {
            string names = "";
            foreach (Author a in authors)
            {
                names = names + a.name + ", ";
            }
            return names;
        }

        public override string ToString()
        {
            string over = "";
            over = over + "name= " + name + ", ";
            if (authors.Length > 0)
            {
                over = over + "authors= { ";
                foreach (Author a in authors)
                {
                    over = over + "Author [name= " + a.name + ", email= " + a.email + ", gender= " + a.gender + "], ";
                }
                over = over + "}, ";
            }
            
            over = over + "price= " + price + ", ";
            over = over + "qty= " + qty + ", ";
            return over;
        }

    }
}
