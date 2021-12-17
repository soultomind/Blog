using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UseWebBrowser
{
    [PermissionSet(SecurityAction.Demand, Name = "FullTrust")]
    [ComVisible(true)]
    public partial class WebNativeManager
    {
        private WebBrowser _WebBrowser;
        public WebNativeManager(WebBrowser webBrowser)
        {
            _WebBrowser = webBrowser;
        }

        public void CallNative(object arg0)
        {
            Toolkit.TraceWriteLine("Arg0=" + arg0);
        }
    }
}
