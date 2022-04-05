using Microsoft.Web.WebView2.Core;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UseWebView2
{
    public partial class MainForm : Form
    {
        private CoreWebView2Environment _env;
        private bool _initializeCoreWebView2;
        public MainForm(CoreWebView2Environment env)
        {
            InitializeComponent();

            this._env = env;

            // 원래 해당 부분은 관리자실행으로 하여 LocalMahcine, CurrentUser 둘다 체크해야함
            // TODO: CurrentUser 에 레지스트리가 왜 등록이 안되는지 찾아봐야함
            if (WebView2Util.InstalledEdgeWebView2Runtime())
            {
                Toolkit.TraceWriteLine("Edge WebView2 런타임이 설치되어 있습니다.");
            }
            else
            {
                Toolkit.TraceWriteLine("Edge WebView2 런타임이 설치되어 있지 않습니다.");
            }

            InitializeWebView2Core();
            Text = Text + " " + AppDomain.CurrentDomain.SetupInformation.TargetFrameworkName;
        }

        private async void InitializeWebView2Core()
        {
            _WebView2.CoreWebView2InitializationCompleted += WebView2_CoreWebView2InitializationCompleted;
            await _WebView2.EnsureCoreWebView2Async(_env);

            _LabelWebView2Version.Text = _LabelWebView2Version.Text + " " + _WebView2.ProductVersion.ToString();
        }

        #region MainForm Event
        private void MainForm_Load(object sender, EventArgs e)
        {
            
        }

        private void MainForm_Shown(object sender, EventArgs e)
        {
            
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            
        }
        #endregion

        #region WebView2 Event

        private void WebView2_CoreWebView2InitializationCompleted(object sender, CoreWebView2InitializationCompletedEventArgs e)
        {
            if (e.IsSuccess)
            {
                _WebView2.CoreWebView2.NavigationStarting += CoreWebView2_NavigationStarting;
                _WebView2.CoreWebView2.SourceChanged += CoreWebView2_SourceChanged;
                _WebView2.CoreWebView2.ContentLoading += CoreWebView2_ContentLoading;
                _WebView2.CoreWebView2.HistoryChanged += CoreWebView2_HistoryChanged;
                _WebView2.CoreWebView2.NavigationCompleted += CoreWebView2_NavigationCompleted;

                _WebView2.WebMessageReceived += new EventHandler<CoreWebView2WebMessageReceivedEventArgs>(CoreWebView2_WebMessageReceived);

                // https://chromedevtools.github.io/devtools-protocol/
                _WebView2.CoreWebView2.GetDevToolsProtocolEventReceiver("Log.entryAdded").DevToolsProtocolEventReceived += MainForm_DevToolsProtocolEventReceived;
                _WebView2.CoreWebView2.CallDevToolsProtocolMethodAsync("Log.enable", "{}");

                _WebView2.CoreWebView2.GetDevToolsProtocolEventReceiver("Runtime.consoleAPICalled").DevToolsProtocolEventReceived += MainForm_DevToolsProtocolEventReceived;
                _WebView2.CoreWebView2.GetDevToolsProtocolEventReceiver("Runtime.exceptionThrown").DevToolsProtocolEventReceived += MainForm_DevToolsProtocolEventReceived;
                _WebView2.CoreWebView2.CallDevToolsProtocolMethodAsync("Runtime.enable", "{}");

                _initializeCoreWebView2 = true;
            }
            else
            {
                MessageBox.Show(e.InitializationException.Message, "[ WebView2 에러 발생 ]");
            }
            
        }

        private void MainForm_DevToolsProtocolEventReceived(object sender, CoreWebView2DevToolsProtocolEventReceivedEventArgs e)
        {
            if (e != null && e.ParameterObjectAsJson != null)
            {
                Toolkit.DebugWriteLine("MainForm_DevToolsProtocolEventReceived=" + e.ParameterObjectAsJson);
            }
        }

        private void CoreWebView2_NavigationStarting(object sender, CoreWebView2NavigationStartingEventArgs e)
        {
            if (Debugger.IsAttached)
            {
                Toolkit.DebugWriteLine("1. CoreWebView2_NavigationStarting");
            }
        }

        private void CoreWebView2_SourceChanged(object sender, CoreWebView2SourceChangedEventArgs e)
        {
            if (Debugger.IsAttached)
            {
                Toolkit.DebugWriteLine("2. CoreWebView2_SourceChanged");
            }
        }

        private void CoreWebView2_ContentLoading(object sender, CoreWebView2ContentLoadingEventArgs e)
        {
            if (Debugger.IsAttached)
            {
                Toolkit.DebugWriteLine("3. CoreWebView2_ContentLoading");
            }
        }

        private void CoreWebView2_HistoryChanged(object sender, object e)
        {
            if (Debugger.IsAttached)
            {
                Toolkit.DebugWriteLine("4. CoreWebView2_HistoryChanged");
            }
        }

        private void CoreWebView2_NavigationCompleted(object sender, CoreWebView2NavigationCompletedEventArgs e)
        {
            if (Debugger.IsAttached)
            {
                Toolkit.DebugWriteLine("5. CoreWebView2_NavigationCompleted");
            }
        }

        private void CoreWebView2_WebMessageReceived(object sender, CoreWebView2WebMessageReceivedEventArgs e)
        {            
            if (Debugger.IsAttached)
            {
                Toolkit.DebugWriteLine("CoreWebView2_WebMessageReceived e.Source=" + e.Source);
                Toolkit.DebugWriteLine("CoreWebView2_WebMessageReceived e.WebMessageAsJson=" + e.WebMessageAsJson);
            }
        }

        #endregion

        private void ButtonWebView2Navigate_Click(object sender, EventArgs e)
        {
            if (_initializeCoreWebView2 && _TextBoxUri.Text.Length > 1)
            {
                _WebView2.CoreWebView2.Navigate(_TextBoxUri.Text);
            }
        }
    }
}
