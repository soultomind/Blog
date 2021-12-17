using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace UseWebBrowser
{
    public partial class Form : System.Windows.Forms.Form
    {
        private WebNativeManager _WebNativeManager;
        public Form()
        {
            InitializeComponent();
        }

        private void Form_Load(object sender, EventArgs e)
        {
            InternetFeatureControlKeys featureControlKeys = new InternetFeatureControlKeys();
            Assembly assembly = System.Reflection.Assembly.GetEntryAssembly();
            string path = Path.GetDirectoryName(assembly.Location) + Path.DirectorySeparatorChar + "InternetFeatureControlKeys.xml";
            if (File.Exists(path))
            {
                try
                {
                    XmlDocument doc = new XmlDocument();
                    doc.Load(path);
                    XmlNodeList xmlNodeList = doc.SelectNodes("InternetFeatureControlKeys/InternetFeature");
                    foreach (XmlNode xmlNode in xmlNodeList)
                    {
                        string name = (string)xmlNode.Attributes["name"].Value;
                        if (name == InternetFeatureControlKeys.FEATURE_BROWSER_EMULATION && xmlNode.InnerText == "%Auto%")
                        {
                            featureControlKeys.AutoBrowserEmulation = true;
                            continue;
                        }

                        uint value = (uint)int.Parse(xmlNode.InnerText);
                        featureControlKeys.Features.Add(name, value);
                    }
                }
                catch (Exception ex)
                {
                    Toolkit.TraceWriteLine(ex.Message);
                    Toolkit.TraceWriteLine(ex.StackTrace);

                    featureControlKeys.AddDefaultFeature();
                }
            }
            else
            {
                featureControlKeys.AddDefaultFeature();
            }

            string appName = String.Empty;
            if (Debugger.IsAttached)
            {
                // Debug [F5 실행]
                Process process = Process.GetCurrentProcess();
                appName = Path.GetFileName(process.MainModule.FileName);
                featureControlKeys.WriteRegistry(appName);
                Toolkit.DebugWriteLine("Debugger.IsAttached InternetFeatureControlKeys WriteRegistry appName - " + appName);
            }

            if (!appName.Equals(Application.ProductName + ".exe"))
            {
                // Execute
                appName = Application.ProductName + ".exe";
                featureControlKeys.WriteRegistry(appName);
                Toolkit.TraceWriteLine("InternetFeatureControlKeys WriteRegistry appName - " + appName);
            }

            _WebNativeManager = new WebNativeManager(_WebBrowser);
            _WebBrowser.ObjectForScripting = _WebNativeManager;
        }

        private void Form_Shown(object sender, EventArgs e)
        {
            _WebBrowser.Navigate(_TextBoxUrl.Text);
        }

        private void ButtonNavigate_Click(object sender, EventArgs e)
        {
            if (!_TextBoxUrl.Text.StartsWith("http"))
            {
                string currentDirectory = Environment.CurrentDirectory;
                string file = _TextBoxUrl.Text;
                _WebBrowser.Navigate(new Uri(String.Format("file:///{0}/{1}", currentDirectory, file)));
            }
            else
            {
                _WebBrowser.Navigate(_TextBoxUrl.Text);
            }
        }

        private void ButtonExecInvokeScript_Click(object sender, EventArgs e)
        {
            string data = "{eventName:\"exec\"}";
            _WebNativeManager.InvokeScript("receiveNative", new object[] { data });
        }

        private void ButtonLButtonDown_Click(object sender, EventArgs e)
        {
            if (_TextBoxPosX.Text.Length > 0 && _TextBoxPosY.Text.Length > 0)
            {
                int posX = int.Parse(_TextBoxPosX.Text);
                int posY = int.Parse(_TextBoxPosX.Text);

                IntPtr handle = NativeMethods.FindWindowEx(_WebBrowser.Handle, IntPtr.Zero, "Shell Embedding", "");

                handle = NativeMethods.FindWindowEx(handle, IntPtr.Zero, "Shell DocObject View", "");
                handle = NativeMethods.FindWindowEx(handle, IntPtr.Zero, "Internet Explorer_Server", "");

                const int WM_LBUTTONDOWN = 0x0201;
                NativeMethods.PostMessage(handle, WM_LBUTTONDOWN, 0, NativeMethods.PointToLParam(posX, posY));
            }
        }
    }
}
