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

                    featureControlKeys.DefaultHtml5Feature();
                }
            }
            else
            {
                featureControlKeys.DefaultHtml5Feature();
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
        }
    }
}
