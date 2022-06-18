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

        [DllImport("kernel32", SetLastError = true, CallingConvention = CallingConvention.Winapi)]
        public extern static IntPtr LoadLibrary(string libraryName);

        [DllImport("kernel32", SetLastError = true, CallingConvention = CallingConvention.Winapi)]
        public extern static IntPtr GetProcAddress(IntPtr hwnd, string procedureName);

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

        private delegate bool IsWow64ProcessDelegate([In] IntPtr handle, [Out] out bool isWow64Process);

        public static bool IsOS64Bit()
        {
            if (IntPtr.Size == 8 || (IntPtr.Size == 4 && Is32BitProcessOn64BitProcessor()))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private static IsWow64ProcessDelegate GetIsWow64ProcessDelegate()
        {
            IntPtr handle = LoadLibrary("kernel32");

            if (handle != IntPtr.Zero)
            {
                IntPtr fnPtr = GetProcAddress(handle, "IsWow64Process");

                if (fnPtr != IntPtr.Zero)
                {
                    return (IsWow64ProcessDelegate)Marshal.GetDelegateForFunctionPointer((IntPtr)fnPtr, typeof(IsWow64ProcessDelegate));
                }
            }

            return null;
        }

        private static bool Is32BitProcessOn64BitProcessor()
        {
            IsWow64ProcessDelegate fnDelegate = GetIsWow64ProcessDelegate();

            if (fnDelegate == null)
            {
                return false;
            }

            bool isWow64;
            bool retVal = fnDelegate.Invoke(Process.GetCurrentProcess().Handle, out isWow64);

            if (retVal == false)
            {
                return false;
            }

            return isWow64;
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
