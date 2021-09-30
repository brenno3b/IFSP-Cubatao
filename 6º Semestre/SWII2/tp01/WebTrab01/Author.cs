using System;
using System.Collections.Generic;
using System.Text;
//Douglas Willian CB3005348
//João Vitor Gino CB3005488
namespace WebTrab01
{
    class Author
    {
        public string name { get; set; }
        public string email { get; set; }
        public char gender { get; set; }

        public Author(string n, string e, char g)
        {
            name = n;
            email = e;
            gender = g;

        }
        public Author()
        {
            name = "nomeTeste";
            email = "EmailTeste";
            gender = 'T';

        }
    }
}
