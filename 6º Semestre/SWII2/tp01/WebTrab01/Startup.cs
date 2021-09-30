using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.DependencyInjection;
//Douglas Willian CB3005348
//João Vitor Gino CB3005488
namespace WebTrab01
{
    public class Startup
    {
        // This method gets called by the runtime. Use this method to add services to the container.
        // For more information on how to configure your application, visit https://go.microsoft.com/fwlink/?LinkID=398940
        public void ConfigureServices(IServiceCollection services)
        {
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IHostingEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }
            var _repo = new FakeBookRepository();

            app.Run(async (context) =>
            {
                await context.Response.WriteAsync(_repo.ToRead.ToString());
                await context.Response.WriteAsync(_repo.Reading.ToString());
                await context.Response.WriteAsync(_repo.Read.ToString());
            });
        }

        static void ImprimeLista(BookList lista)
        {
            Console.WriteLine(lista);
        }
    }
}
