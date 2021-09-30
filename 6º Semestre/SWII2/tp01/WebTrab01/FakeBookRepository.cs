using System;
using System.Collections.Generic;
using System.Text;
//Douglas Willian CB3005348
//João Vitor Gino CB3005488
namespace WebTrab01
{
    class FakeBookRepository : IRepositoryBook
    {
        private BookList _ToRead;

        private BookList _Reading;

        private BookList _Read;


        public FakeBookRepository()
        {
            FakeAuthorRepository fakeAuthor = new FakeAuthorRepository();
            Author[] aupl1 = new Author[2];
            Author[] aupl2 = new Author[1];
            Author[] aule1 = new Author[1];
            Author[] aule2 = new Author[1];
            Author[] auli1 = new Author[2];
            Author[] auli2 = new Author[1];

            aupl1[0] = fakeAuthor.authors[0];
            aupl1[1] = fakeAuthor.authors[1];
            aupl2[0] = fakeAuthor.authors[2];
            aule1[0] = fakeAuthor.authors[3];
            aule2[0] = fakeAuthor.authors[1];
            auli1[0] = fakeAuthor.authors[0];
            auli1[1] = fakeAuthor.authors[2];
            auli2[0] = fakeAuthor.authors[3];


            var l1 = new Book("testepl1", aupl1, 20.00, 10);
            var l2 = new Book("testepl2", aupl2, 28.00, 6);
            var l3 = new Book("testele1", aule1, 32.00, 14);
            var l4 = new Book("testele2", aule2, 12.00, 3);
            var l5 = new Book("testeli1", auli1, 49.00, 11);
            var l6 = new Book("testeli2", auli2, 33.00, 5);

            _ToRead = new BookList("Para Ler", l1, l2);
            _Reading = new BookList("Lendo", l3, l4);
            _Read = new BookList("Lidos", l5, l6);

        }

        public BookList ToRead => _ToRead;
        public BookList Reading => _Reading;
        public BookList Read => _Read;

        public IEnumerable<Book> All => throw new System.NotImplementedException();

        public void Add(Book book)
        {
            throw new System.NotImplementedException();
        }

    }
}
