using System;
using System.Diagnostics;
using System.Reflection;

namespace UseDebugView
{
    class Toolkit
    {
        // DebugView Filter 시 해당 값으로 
        public static string IncludeFilterName
        {
            get { return _sIncludeFilterName; }
            set
            {
                if (!String.IsNullOrEmpty(value))
                {
                    _sIncludeFilterName = value;
                }
            }
        }
        public static string _sIncludeFilterName;
        public static bool IsDebugEnabled;
        public static bool IsTraceEnabled;
        public static bool UseNowToString;
        static Toolkit()
        {
            _sIncludeFilterName = CreateNamespace();
#if DEBUG
            IsDebugEnabled = true;
#endif
            IsTraceEnabled = true;
            UseNowToString = true;
        }
        private static string CreateNamespace()
        {
            Assembly assembly = Assembly.GetAssembly(typeof(Toolkit));
            return assembly.GetName().Name;
        }

        private static string NowToString(string format = "yyyy/MM/dd HH:mm:ss")
        {
            return DateTime.Now.ToString(format);
        }

        public static void DebugWriteLine(string message)
        {
            if (IsDebugEnabled)
            {
                string className = new StackFrame(1).GetMethod().ReflectedType.Name;
                string methodName = new StackFrame(1, true).GetMethod().Name;
                if (UseNowToString)
                {
                    message = String.Format("[{0}] [{1}.{2}] {3} DEBUG - {4}", 
                        _sIncludeFilterName, className, methodName, NowToString(), message);
                }
                else
                {
                    message = String.Format("[{0}] [{1}.{2}] DEBUG - {3}", _sIncludeFilterName, className, methodName, message);
                }
                
                Debug.WriteLine(message);
            }
        }
        public static void TraceWriteLine(string message)
        {
            if (IsTraceEnabled)
            {
                string className = new StackFrame(1).GetMethod().ReflectedType.Name;
                string methodName = new StackFrame(1, true).GetMethod().Name;
                if (UseNowToString)
                {
                    message = String.Format("[{0}] [{1}.{2}] {3} DEBUG - {4}",
                        _sIncludeFilterName, className, methodName, NowToString(), message);
                }
                else
                {
                    message = String.Format("[{0}] [{1}.{2}] DEBUG - {3}", _sIncludeFilterName, className, methodName, message);
                }
                Trace.WriteLine(message);
            }
        }
        
    }
}
