using PrimeiroPJ.Services;
using PrimeiroPJ.Views;
using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace PrimeiroPJ
{
    public partial class App : Application
    {

        public App()
        {
            InitializeComponent();

            DependencyService.Register<MockDataStore>();
            MainPage = new PrimeiraPagina();
        }

        protected override void OnStart()
        {
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }
}
