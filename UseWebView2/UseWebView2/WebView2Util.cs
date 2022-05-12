using Microsoft.Web.WebView2.Core;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UseWebView2
{
    class WebView2Util
    {
        public static bool Is64BitOperatingSystem = Environment.Is64BitOperatingSystem;
        public static readonly string ClientsSubId = "{F3017226-FE2A-4295-8BDF-00C3A9A7E4C5}";

        public static bool InstalledAvailableWebView2Runtime(string browserExecutableFolder = null)
        {
            string version = String.Empty;
            try
            {
                // WebView2Loader.dll 안에 함수를 내부적으로 호출
                version = CoreWebView2Environment.GetAvailableBrowserVersionString(browserExecutableFolder);
            }
            catch (Exception)
            {

            }
            if (String.IsNullOrEmpty(version))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        public static bool InstalledRegistryEdgeWebView2Runtime()
        {
            if (Toolkit.IsCurrentProcessExecuteAdministrator())
            {
                Toolkit.TraceWriteLine("관리자 권한으로 체크합니다. LocalMahcine,CurrentUser");
                return InstalledEdgeWebView2LoaclMachine() || InstalledEdgeWebView2CurrentUser();
            }
            else
            {
                Toolkit.TraceWriteLine("일반 실행 권한으로 체크합니다. CurrentUser");
                return InstalledEdgeWebView2CurrentUser();
            }
        }

        public static bool InstalledEdgeWebView2LoaclMachine()
        {
            bool installed = false;

            string name = String.Empty;
            if (Is64BitOperatingSystem)
            {
                name = @"SOFTWARE\WOW6432Node\Microsoft\EdgeUpdate\Clients\" + ClientsSubId;
            }
            else
            {
                name = @"SOFTWARE\Microsoft\EdgeUpdate\Clients\" + ClientsSubId;
            }

            using (var targetRegistry = Registry.LocalMachine.OpenSubKey(name, RegistryKeyPermissionCheck.ReadWriteSubTree))
            {
                installed = (targetRegistry != null);
                if (installed)
                {
                    Toolkit.TraceWriteLine("===== Registry Information ======");
                    foreach (var valueName in targetRegistry.GetValueNames())
                    {
                        object value = targetRegistry.GetValue(valueName);
                        string text = String.Format("{0}={1}", valueName, value);

                        Toolkit.TraceWriteLine(text);
                    }
                    Toolkit.TraceWriteLine("===== Registry Information ======");
                }
            }
            return installed;
        }

        public static bool InstalledEdgeWebView2CurrentUser()
        {
            bool installed = false;
            using (var targetRegistry = Registry.CurrentUser.OpenSubKey(@"Software\Microsoft\EdgeUpdate\Clients\" + ClientsSubId, RegistryKeyPermissionCheck.ReadWriteSubTree))
            {
                installed = (targetRegistry != null);
                if (installed)
                {
                    Toolkit.TraceWriteLine("===== Registry Information ======");
                    foreach (var name in targetRegistry.GetValueNames())
                    {
                        object value = targetRegistry.GetValue(name);
                        string text = String.Format("{0}={1}", name, value);

                        Toolkit.TraceWriteLine(text);
                    }
                    Toolkit.TraceWriteLine("===== Registry Information ======");
                }
            }

            return installed;
        }
    }
}
