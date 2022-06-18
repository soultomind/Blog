using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace UseWebBrowser
{

    public class InternetFeatureControlKeys
    {
        public const string FEATURE_BROWSER_EMULATION = "FEATURE_BROWSER_EMULATION";

        /// <summary>
        /// 현재 프로세스가 64 비트 프로세스인지 여부
        /// </summary>
        public static bool Is64BitProcess = IntPtr.Size == 8;

        public static bool Is64BitOperatingSystem = NativeMethods.InternalCheckIsWow64();

        /// <summary>
        /// FEATURE_BROWSER_EMULATION 값 자동적으로 설정 여부
        /// </summary>
        public bool AutoBrowserEmulation
        {
            get { return _autoBrowserEmulation; }
            set { _autoBrowserEmulation = value; }
        }
        private bool _autoBrowserEmulation;

        /// <summary>
        /// FEATURE_BROWSER_EMULATION 값
        /// </summary>
        public int BrowserEmulation
        {
            get { return _browserEmulation; }
        }
        private int _browserEmulation = 7000;

        /// <summary>
        /// 레지스트리 HKEY 타입
        /// <para><see cref="HKEY.LocalMachine"/> 일때 관리자 권한 아닐 경우 예외발생</para>
        /// </summary>
        /// <exception cref="System.ArgumentException"></exception>
        public HKEY HKey
        {
            get { return _hKey; }
            set 
            {
                if (value == HKEY.LocalMachine)
                {
                    if (!Toolkit.IsExecuteAdministrator())
                    {
                        throw new System.ArgumentException("Usage Execute Administrator");
                    }
                }
                _hKey = value; 
            }
        }
        private HKEY _hKey = HKEY.CurrentUser;

        /// <summary>
        /// Internet Feature Control Keys 
        /// <para>Key,Value</para>
        /// </summary>
        public Dictionary<string, uint> Features
        {
            get { return _features; }
            private set { _features = value; }
        }
        private Dictionary<string, uint> _features;

        public InternetFeatureControlKeys()
        {
            Features = new Dictionary<string, uint>();

            SetBrowserEmulation();
        }

        #region BrowserEmulation
        private int GetRegisterBrowserVersion()
        {
            string ieBrowserVersion = RegistryUtility.GetInternetExplorerVersion();
            int indexOf = ieBrowserVersion.IndexOf('.'), result = 0;
            if (indexOf != -1)
            {
                int.TryParse(ieBrowserVersion.Substring(0, indexOf), out result);
            }
            return result;
        }

        private void SetWebBrowserCtrlVersion(int webBrowserMajorVersion, out int outWebBrowserCtrlVersion)
        {
            Toolkit.TraceWriteLine("WebBrowser Version=" + webBrowserMajorVersion);

            // Set the appropriate Internet Explorer version
            if (webBrowserMajorVersion >= 11)
            {
                outWebBrowserCtrlVersion = (int)BrowserEmulationVersion.Version11Edge;
            }
            else if (webBrowserMajorVersion == 10)
            {
                outWebBrowserCtrlVersion = (int)BrowserEmulationVersion.Version10Standards;
            }
            else if (webBrowserMajorVersion == 9)
            {
                outWebBrowserCtrlVersion = (int)BrowserEmulationVersion.Version9Standards;
            }
            else if (webBrowserMajorVersion == 8)
            {
                outWebBrowserCtrlVersion = (int)BrowserEmulationVersion.Version8Standards;
            }
            else
            {
                outWebBrowserCtrlVersion = (int)BrowserEmulationVersion.Version7;
            }

            Toolkit.TraceWriteLine("BrowserEmulationVersion=" + outWebBrowserCtrlVersion.ToString());
        }

        private void SetBrowserEmulation()
        {
            Toolkit.TraceWriteLine("Start");

            int webBrowserCtrlVersion = 0;
            using (WebBrowser Wb = new WebBrowser())
            {
                SetWebBrowserCtrlVersion(Wb.Version.Major, out webBrowserCtrlVersion);
            }

            int.TryParse(webBrowserCtrlVersion.ToString().Substring(0, 2), out webBrowserCtrlVersion);

            int ieBrowserRegistryVersion = GetRegisterBrowserVersion();
            Toolkit.TraceWriteLine("WebBrowser Version=" + webBrowserCtrlVersion);
            Toolkit.TraceWriteLine("InternetExplorer Registry Version=" + ieBrowserRegistryVersion);

            if (webBrowserCtrlVersion == ieBrowserRegistryVersion)
            {
                Toolkit.TraceWriteLine("Same WebBrowser Version == InternetExplorer Registry Version");
                SetWebBrowserCtrlVersion(webBrowserCtrlVersion, out _browserEmulation);
            }
            else
            {
                Toolkit.TraceWriteLine("Same WebBrowser Version != InternetExplorer Registry Version");
                Toolkit.TraceWriteLine(String.Format("WebBrowser Version={0}, InternetExplorer Registry Version={1}", webBrowserCtrlVersion, ieBrowserRegistryVersion));
                SetWebBrowserCtrlVersion(ieBrowserRegistryVersion, out _browserEmulation);
            }

            Toolkit.TraceWriteLine("End");
        }

        #endregion

        /// <summary>
        /// 레지스트리에 추가할 Internet Feature Control Key를 등록한다.
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void AddFeature(string key, int value)
        {
            _features.Add(key, (uint)value);
        }

        /// <summary>
        /// appName 이름으로 Feature에 있는 내용을 레지스트리에 추가한다.
        /// </summary>
        /// <param name="appName"></param>
        public void WriteRegistry(string appName)
        {
            foreach (var item in _features)
            {
                SetRegistryBrowserFeatureControlKey(
                    appName,
                    item.Key,
                    item.Value
                );
            }

            if (_autoBrowserEmulation)
            {
                SetRegistryBrowserFeatureControlKey(appName, FEATURE_BROWSER_EMULATION, (uint)_browserEmulation);
            }
        }
        public void AddDefaultFeature()
        {
            AddFeature("FEATURE_96DPI_PIXEL", 1);
            AddFeature("FEATURE_BROWSER_EMULATION", _browserEmulation);
            AddFeature("FEATURE_AJAX_CONNECTIONEVENTS", 1);
            AddFeature("FEATURE_ENABLE_CLIPCHILDREN_OPTIMIZATION", 1);
            AddFeature("FEATURE_GPU_RENDERING", 1);
            AddFeature("FEATURE_IVIEWOBJECTDRAW_DMLT9_WITH_GDI", 0);
            AddFeature("FEATURE_NINPUT_LEGACYMODE", 0);
            AddFeature("FEATURE_DISABLE_NAVIGATION_SOUNDS", 1);
            AddFeature("FEATURE_SCRIPTURL_MITIGATION", 1);
            AddFeature("FEATURE_SPELLCHECKING", 0);
            AddFeature("FEATURE_STATUS_BAR_THROTTLING", 1);
            AddFeature("FEATURE_VALIDATE_NAVIGATE_URL", 1);
            AddFeature("FEATURE_WEBOC_DOCUMENT_ZOOM", 1);
            AddFeature("FEATURE_WEBOC_POPUPMANAGEMENT", 0);
            AddFeature("FEATURE_ADDON_MANAGEMENT", 0);
            AddFeature("FEATURE_WEBSOCKET", 1);
            AddFeature("FEATURE_WINDOW_RESTRICTIONS", 0);
            AddFeature("FEATURE_BLOCK_INPUT_PROMPTS", 1);
            AddFeature("FEATURE_BLOCK_LMZ_SCRIPT", 1);

            AddFeature("FEATURE_WEBSOCKET_MAXCONNECTIONSPERSERVER", 128);
        }

        /// <summary>
        /// 레지스트리를 추가한다.
        /// <para>CurrentUser</para>
        /// <para>Software\Microsoft\Internet Explorer\Main\FeatureControl\</para>
        /// <para>LocalMachine</para>
        /// <para>x64 = Software\Wow6432Node\Microsoft\Internet Explorer\Main\FeatureControl\</para>
        /// <para>x86 = Software\Microsoft\Internet Explorer\Main\FeatureControl\</para>
        /// </summary>
        /// <param name="appName"></param>
        /// <param name="feature"></param>
        /// <param name="value"></param>
        public void SetRegistryBrowserFeatureControlKey(string appName, string feature, uint value)
        {
            if (_hKey == HKEY.LocalMachine)
            {
                string subKey = String.Empty;
                if (!Is64BitProcess && Is64BitOperatingSystem)
                {
                    subKey = @"Software\Wow6432Node\Microsoft\Internet Explorer\Main\FeatureControl\";
                }
                else
                {
                    subKey = @"Software\Microsoft\Internet Explorer\Main\FeatureControl\";
                }

                subKey = String.Concat(subKey, feature);
                using (var key = Registry.LocalMachine.CreateSubKey(subKey, RegistryKeyPermissionCheck.ReadWriteSubTree))
                {
                    key.SetValue(appName, (UInt32)value, RegistryValueKind.DWord);
                }
            }
            else
            {
                string subKey = String.Concat(@"Software\Microsoft\Internet Explorer\Main\FeatureControl\", feature);
                using (var key = Registry.CurrentUser.CreateSubKey(subKey, RegistryKeyPermissionCheck.ReadWriteSubTree))
                {
                    key.SetValue(appName, (UInt32)value, RegistryValueKind.DWord);
                }
            }
        }
    }
}
