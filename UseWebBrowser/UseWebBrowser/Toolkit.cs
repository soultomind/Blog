﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

namespace UseWebBrowser
{
    public static class Toolkit
    {
        public static bool IsDebugEnabled;
        public static bool IsTraceEnabled;

        static Toolkit()
        {

#if DEBUG
            IsDebugEnabled = true;
            IsTraceEnabled = true;
#else
            IsDebugEnabled = false;
            IsTraceEnabled = true;
#endif

        }

        public static void DebugWriteLine(string message)
        {
            if (IsDebugEnabled)
            {
                string className = new StackFrame(1).GetMethod().ReflectedType.Name;
                string methodName = new StackFrame(1, true).GetMethod().Name;
                string header = String.Format("{0} :: {1}", className, methodName);
                message = String.Format("[{0}] DEBUG - {1}", header, message);
                Debug.WriteLine(message);
            }
        }

        public static void TraceWriteLine(string message)
        {
            if (IsTraceEnabled)
            {
                string className = new StackFrame(1).GetMethod().ReflectedType.Name;
                string methodName = new StackFrame(1, true).GetMethod().Name;
                string header = String.Format("{0} :: {1}", className, methodName);
                message = String.Format("[{0}] TRACE - {1}", header, message);
                Trace.WriteLine(message);
            }
        }

        public static bool IsExecuteAdministrator()
        {
            bool flag;

            WindowsIdentity identity = null;
            try
            {
                identity = WindowsIdentity.GetCurrent();
                WindowsPrincipal principal = new WindowsPrincipal(identity);
                flag = principal.IsInRole(WindowsBuiltInRole.Administrator);
            }
            catch (Exception)
            {
                flag = false;
            }
            finally
            {
                if (identity != null)
                {
                    identity.Dispose();
                }
            }

            return flag;
        }
    }
}
