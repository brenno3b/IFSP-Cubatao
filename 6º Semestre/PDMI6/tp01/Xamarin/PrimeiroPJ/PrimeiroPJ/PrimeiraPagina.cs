using Java.Sql;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace PrimeiroPJ
{
    public partial class PrimeiraPagina : ContentPage
    {
        void btnOk_Clicked(object sender, EventArgs e)
        {
            var username = entryUsername.Text;
            var password = entryPassword.Text;

            if (username=="admin" && password=="@admin")
            {
                DisplayAlert("Alerta:", "Login realizado com sucesso!", "OK");
            }
            else
            {
                DisplayAlert("Alerta:", "Login não autorizado", "OK");
            }
        }
        void btnLimpar_Clicked(object sender, System.EventArgs e)
        {
            entryUsername.Text = "";
            entryPassword.Text = "";
        }
        void btnCreditos_Clicked(object sender, System.EventArgs e)
        {
            DisplayAlert("Autores:", "Brenno CB3007219 e Diego CB3005585", "OK");
        }
    }
}
