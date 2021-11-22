using Microsoft.Win32;
using System;

namespace UseWebBrowser
{
    public class RegistryUtility
    {
        private const string InternetExplorerRootKey = @"Software\Microsoft\Internet Explorer";
        public static string GetInternetExplorerVersion()
        {
            // Windows 10 OpenSubKey name svcVersion
            string name = InternetExplorerRootKey, version = String.Empty;
            using (RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(name))
            {
                if (registryKey != null)
                {
                    object value = registryKey.GetValue("svcVersion");
                    if (value != null)
                    {
                        version = value.ToString();
                    }

                    if (String.IsNullOrEmpty(version))
                    {
                        value = registryKey.GetValue("Version");
                        if (value != null)
                        {
                            version = value.ToString();
                        }
                    }
                }
            }

            return version;
        }
    }
}
