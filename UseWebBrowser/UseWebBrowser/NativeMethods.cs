using System;
using System.Diagnostics;
using System.Drawing;
using System.Runtime.InteropServices;

namespace UseWebBrowser
{
    public class NativeMethods
    {
        #region Kernel32

        [DllImport("kernel32.dll", SetLastError = true, CallingConvention = CallingConvention.Winapi)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool IsWow64Process(
            [In] IntPtr hProcess,
            [Out] out bool wow64Process
        );

        #endregion

        #region User32
        [DllImport("user32.dll")]
        public static extern IntPtr FindWindowEx(IntPtr parentHandle, IntPtr hWndChildAfter, string className, string windowTitle);
        
        [DllImport("user32.dll")]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool PostMessage(IntPtr WindowHandle, UInt32 Msg, Int32 wParam, Int32 lParam);
        #endregion

        public static bool InternalCheckIsWow64()
        {
            int major = Environment.OSVersion.Version.Major, minor = Environment.OSVersion.Version.Minor;
            if ((major == 5 && minor >= 1) || major >= 6)
            {
                using (Process process = Process.GetCurrentProcess())
                {
                    bool retVal;
                    if (!IsWow64Process(process.Handle, out retVal))
                    {
                        return false;
                    }
                    return retVal;
                }
            }
            else
            {
                return false;
            }
        }

        public static int PointToLParam(int x, int y)
        {
            return ((y << 16) | (x & 0xFFFF));
        }
        public static int PointToLParam(Point point)
        {
            return PointToLParam(point.X, point.Y);
        }
    }
}
