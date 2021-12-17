using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UseWebBrowser
{
    partial class WebNativeManager
    {
        public object InvokeScript(string scriptName, object[] args)
        {
            return _WebBrowser.Document.InvokeScript(scriptName, args);
        }
    }
}
