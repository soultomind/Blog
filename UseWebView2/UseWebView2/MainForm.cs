﻿using Microsoft.Web.WebView2.Core;
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

namespace WebView2
{
    public partial class MainForm : Form
    {
        private bool _initializeCoreWebView2;
        public MainForm()
        {
            InitializeComponent();
            InitializeWebView2Core();

            Text = Text + " " + AppDomain.CurrentDomain.SetupInformation.TargetFrameworkName;
        }

        private void InitializeWebView2Core()
        {
            _WebView2.EnsureCoreWebView2Async();
            _WebView2.CoreWebView2InitializationCompleted += WebView2_CoreWebView2InitializationCompleted;

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

                _WebView2.WebMessageReceived += new System.EventHandler<Microsoft.Web.WebView2.Core.CoreWebView2WebMessageReceivedEventArgs>(this.CoreWebView2_WebMessageReceived);

                //https://chromedevtools.github.io/devtools-protocol/
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
                Debug.WriteLine("MainForm_DevToolsProtocolEventReceived=" + e.ParameterObjectAsJson);
            }
        }

        private void CoreWebView2_NavigationStarting(object sender, Microsoft.Web.WebView2.Core.CoreWebView2NavigationStartingEventArgs e)
        {
            if (Debugger.IsAttached)
                Debug.WriteLine("1. CoreWebView2_NavigationStarting");
        }

        private void CoreWebView2_SourceChanged(object sender, Microsoft.Web.WebView2.Core.CoreWebView2SourceChangedEventArgs e)
        {
            if (Debugger.IsAttached)
                Debug.WriteLine("2. CoreWebView2_SourceChanged");
        }

        private void CoreWebView2_ContentLoading(object sender, Microsoft.Web.WebView2.Core.CoreWebView2ContentLoadingEventArgs e)
        {
            if (Debugger.IsAttached)
                Debug.WriteLine("3. CoreWebView2_ContentLoading");
        }

        private void CoreWebView2_HistoryChanged(object sender, object e)
        {
            if (Debugger.IsAttached)
                Debug.WriteLine("4. CoreWebView2_HistoryChanged");
        }

        private void CoreWebView2_NavigationCompleted(object sender, Microsoft.Web.WebView2.Core.CoreWebView2NavigationCompletedEventArgs e)
        {
            if (Debugger.IsAttached)
                Debug.WriteLine("5. CoreWebView2_NavigationCompleted");
        }

        private void CoreWebView2_WebMessageReceived(object sender, CoreWebView2WebMessageReceivedEventArgs e)
        {            
            if (Debugger.IsAttached)
            {
                Debug.WriteLine("CoreWebView2_WebMessageReceived e.Source=" + e.Source);
                Debug.WriteLine("CoreWebView2_WebMessageReceived e.WebMessageAsJson=" + e.WebMessageAsJson);
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