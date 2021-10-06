using PrimeiroPJ.ViewModels;
using System.ComponentModel;
using Xamarin.Forms;

namespace PrimeiroPJ.Views
{
    public partial class ItemDetailPage : ContentPage
    {
        public ItemDetailPage()
        {
            InitializeComponent();
            BindingContext = new ItemDetailViewModel();
        }
    }
}