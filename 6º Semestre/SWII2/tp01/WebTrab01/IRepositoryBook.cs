using System;
using System.Collections.Generic;
using System.Text;
//Douglas Willian CB3005348
//João Vitor Gino CB3005488
namespace WebTrab01
{
    interface IRepositoryBook
    {
        BookList ToRead { get; }

        BookList Reading { get; }

        BookList Read { get; }

        IEnumerable<Book> All { get; }

        void Add(Book book);
    }
}
