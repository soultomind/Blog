using System;

namespace UseDebugView
{
    class Program
    {
        static void Main(string[] args)
        {
            Toolkit.DebugWriteLine("Debug!");
            Toolkit.TraceWriteLine("Trace!");

            Console.WriteLine("Press any key to continue..");
            Console.ReadKey();
        }
    }
}
