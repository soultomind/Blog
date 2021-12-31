using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Reflection;

namespace UseDesignMode
{
    public partial class MyUserControl : UserControl
    {
        public MyUserControl()
        {
            InitializeComponent();
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            if (!DesignMode)
            {
                // 디버그실행(F5), 실행(Ctrl + F5)
                Toolkit.TraceWriteLine("Execute");
            }

            // 디자인모드시 EntryAssembly NULL
            if (Assembly.GetEntryAssembly() == null)
            {
                // 해당 케이스는 프로젝트 컴파일시에 호출되어 짐
                Toolkit.TraceWriteLine("DesignMode=" + DesignMode);
                string executingAssemblyLocation = Assembly.GetExecutingAssembly().Location;
                Toolkit.TraceWriteLine("Assembly.GetExecutingAssembly().Location=" + executingAssemblyLocation);
                string executablePath = Application.ExecutablePath;
                Toolkit.TraceWriteLine("Application.ExecutablePath=" + executablePath);
            }
            else
            {
                Toolkit.TraceWriteLine("DesignMode=" + DesignMode);
                string entryAssemblyLocation = Assembly.GetEntryAssembly().Location;
                Toolkit.TraceWriteLine("Assembly.GetEntryAssembly().Location=" + entryAssemblyLocation);
            }
        }

        // 1. DesignerSerializationVisibility Attribute
        // MainForm.Designer.cs 파일에 컨트롤이 추가되면서 속성 설정코드가 추가되지 않음
        // [DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
        // [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]

        // MainForm.Designer.cs 파일에 컨트롤이 추가되면서 속성 설정코드가 추가됨
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]


        // 2. Browsable Attribute
        // [Browsable(false)] // 해당 속성을 해당 컨트롤을 사용하는 폼 디자인모드에 표시 하지 않음
        [Browsable(true)] // 해당 속성을 해당 컨트롤을 사용하는 폼 디자인모드에 표시함

        // 3. Displayname Attribute
        // 폼 디자인모드시 속성 창에 표시되는 속성명
        [DisplayName("UseCallback")]

        // 4. Description Attribute
        // 폼 디자인모드시 속성 창에 표시되는 속성 설명을 지정(속성, 이벤트)
        [Description("콜백 여부를 지정합니다.")]

        // 5. Category Attribute
        // 폼 디자인모드시 속성 창에 표시되는 속성이 위치 해 있는 카테고리
        [Category("라이브러리 속성")]
        public bool UseCallback { get; set; } = false;
    }
}
