using Microsoft.Web.WebView2.Core;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UseWebView2
{
    static class Program
    {
        /// <summary>
        /// 해당 애플리케이션의 주 진입점입니다.
        /// </summary>
        [STAThread]
        static void Main()
        {
            /*
            Process process = Process.GetCurrentProcess();
            string currentDirectory = Path.GetDirectoryName(process.MainModule.FileName);
            Directory.SetCurrentDirectory(currentDirectory);
            */

            // String userDataFolder = Path.GetTempPath() + @"WebView2UserData";
            String userDataFolder = null;

            // 실행인자로도 AdditionalBrowserArguments, AllowSingleSignOnUsingOSPrimaryAccount, Language, TargetCompatibleBrowserVersion
            // 설정 가능하게 해야함 이때 Name1=Value1;Name2=Value2 형식으로 Base64 인코딩 처리

            CoreWebView2EnvironmentOptions options = new CoreWebView2EnvironmentOptions();

            // TODO: 필요한 설정 옵션
            // - options.Language=ko,en

            // userDataFolder = EBWebView 캐쉬 디렉토리를 의미합니다.
            // 명시를 하지 않을경우 실행파일 위치 기준으로 
            // 어셈블리이름.exe.WebView2 디렉토리 생성하여 EBWebView 캐쉬 디렉토리 생성
            CoreWebView2Environment env = CoreWebView2Environment.CreateAsync("", userDataFolder, options).GetAwaiter().GetResult();

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm(env));
        }
    }
}
