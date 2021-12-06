using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UseDebugView
{
    class Program
    {
        static void Main(string[] args)
        {
            Toolkit.UseNowToString = true;
            Toolkit.DebugWriteLine("Debug!");
            Toolkit.TraceWriteLine("Trace!");

            Console.WriteLine("Press any key to continue..");
            Console.ReadKey();
        }
    }
}
