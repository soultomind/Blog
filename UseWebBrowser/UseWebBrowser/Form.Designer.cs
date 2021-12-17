namespace UseWebBrowser
{
    partial class Form
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this._WebBrowser = new System.Windows.Forms.WebBrowser();
            this._TableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this._PanelTop = new System.Windows.Forms.Panel();
            this._ButtonExecInvokeScript = new System.Windows.Forms.Button();
            this._TextBoxUrl = new System.Windows.Forms.TextBox();
            this._ButtonNavigate = new System.Windows.Forms.Button();
            this._PanelFill = new System.Windows.Forms.Panel();
            this._GroupBoxMousePosition = new System.Windows.Forms.GroupBox();
            this._LabelPosX = new System.Windows.Forms.Label();
            this._LabelPosY = new System.Windows.Forms.Label();
            this._TextBoxPosX = new System.Windows.Forms.TextBox();
            this._TextBoxPosY = new System.Windows.Forms.TextBox();
            this._ButtonLButtonDown = new System.Windows.Forms.Button();
            this._TableLayoutPanel.SuspendLayout();
            this._PanelTop.SuspendLayout();
            this._PanelFill.SuspendLayout();
            this._GroupBoxMousePosition.SuspendLayout();
            this.SuspendLayout();
            // 
            // _WebBrowser
            // 
            this._WebBrowser.Dock = System.Windows.Forms.DockStyle.Fill;
            this._WebBrowser.Location = new System.Drawing.Point(0, 0);
            this._WebBrowser.MinimumSize = new System.Drawing.Size(20, 20);
            this._WebBrowser.Name = "_WebBrowser";
            this._WebBrowser.Size = new System.Drawing.Size(678, 362);
            this._WebBrowser.TabIndex = 0;
            this._WebBrowser.Url = new System.Uri("", System.UriKind.Relative);
            // 
            // _TableLayoutPanel
            // 
            this._TableLayoutPanel.ColumnCount = 1;
            this._TableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this._TableLayoutPanel.Controls.Add(this._PanelTop, 0, 0);
            this._TableLayoutPanel.Controls.Add(this._PanelFill, 0, 1);
            this._TableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this._TableLayoutPanel.Location = new System.Drawing.Point(0, 0);
            this._TableLayoutPanel.Name = "_TableLayoutPanel";
            this._TableLayoutPanel.RowCount = 2;
            this._TableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 28F));
            this._TableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 72F));
            this._TableLayoutPanel.Size = new System.Drawing.Size(684, 511);
            this._TableLayoutPanel.TabIndex = 1;
            // 
            // _PanelTop
            // 
            this._PanelTop.Controls.Add(this._GroupBoxMousePosition);
            this._PanelTop.Controls.Add(this._ButtonExecInvokeScript);
            this._PanelTop.Controls.Add(this._TextBoxUrl);
            this._PanelTop.Controls.Add(this._ButtonNavigate);
            this._PanelTop.Dock = System.Windows.Forms.DockStyle.Fill;
            this._PanelTop.Location = new System.Drawing.Point(3, 3);
            this._PanelTop.Name = "_PanelTop";
            this._PanelTop.Size = new System.Drawing.Size(678, 137);
            this._PanelTop.TabIndex = 4;
            // 
            // _ButtonExecInvokeScript
            // 
            this._ButtonExecInvokeScript.Location = new System.Drawing.Point(518, 7);
            this._ButtonExecInvokeScript.Name = "_ButtonExecInvokeScript";
            this._ButtonExecInvokeScript.Size = new System.Drawing.Size(151, 26);
            this._ButtonExecInvokeScript.TabIndex = 4;
            this._ButtonExecInvokeScript.Text = "스크립트 실행";
            this._ButtonExecInvokeScript.UseVisualStyleBackColor = true;
            this._ButtonExecInvokeScript.Click += new System.EventHandler(this.ButtonExecInvokeScript_Click);
            // 
            // _TextBoxUrl
            // 
            this._TextBoxUrl.Location = new System.Drawing.Point(9, 9);
            this._TextBoxUrl.Name = "_TextBoxUrl";
            this._TextBoxUrl.Size = new System.Drawing.Size(422, 23);
            this._TextBoxUrl.TabIndex = 2;
            this._TextBoxUrl.Text = "http://demo.clipsoft.co.kr";
            // 
            // _ButtonNavigate
            // 
            this._ButtonNavigate.Location = new System.Drawing.Point(437, 7);
            this._ButtonNavigate.Name = "_ButtonNavigate";
            this._ButtonNavigate.Size = new System.Drawing.Size(75, 26);
            this._ButtonNavigate.TabIndex = 3;
            this._ButtonNavigate.Text = "연결";
            this._ButtonNavigate.UseVisualStyleBackColor = true;
            this._ButtonNavigate.Click += new System.EventHandler(this.ButtonNavigate_Click);
            // 
            // _PanelFill
            // 
            this._PanelFill.AutoScroll = true;
            this._PanelFill.Controls.Add(this._WebBrowser);
            this._PanelFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this._PanelFill.Location = new System.Drawing.Point(3, 146);
            this._PanelFill.Name = "_PanelFill";
            this._PanelFill.Size = new System.Drawing.Size(678, 362);
            this._PanelFill.TabIndex = 5;
            // 
            // _GroupBoxMousePosition
            // 
            this._GroupBoxMousePosition.Controls.Add(this._ButtonLButtonDown);
            this._GroupBoxMousePosition.Controls.Add(this._TextBoxPosY);
            this._GroupBoxMousePosition.Controls.Add(this._TextBoxPosX);
            this._GroupBoxMousePosition.Controls.Add(this._LabelPosY);
            this._GroupBoxMousePosition.Controls.Add(this._LabelPosX);
            this._GroupBoxMousePosition.Location = new System.Drawing.Point(9, 46);
            this._GroupBoxMousePosition.Name = "_GroupBoxMousePosition";
            this._GroupBoxMousePosition.Size = new System.Drawing.Size(422, 72);
            this._GroupBoxMousePosition.TabIndex = 5;
            this._GroupBoxMousePosition.TabStop = false;
            this._GroupBoxMousePosition.Text = "Mouse Position";
            // 
            // _LabelPosX
            // 
            this._LabelPosX.AutoSize = true;
            this._LabelPosX.Location = new System.Drawing.Point(20, 28);
            this._LabelPosX.Name = "_LabelPosX";
            this._LabelPosX.Size = new System.Drawing.Size(22, 15);
            this._LabelPosX.TabIndex = 0;
            this._LabelPosX.Text = "X=";
            // 
            // _LabelPosY
            // 
            this._LabelPosY.AutoSize = true;
            this._LabelPosY.Location = new System.Drawing.Point(160, 28);
            this._LabelPosY.Name = "_LabelPosY";
            this._LabelPosY.Size = new System.Drawing.Size(22, 15);
            this._LabelPosY.TabIndex = 1;
            this._LabelPosY.Text = "Y=";
            // 
            // _TextBoxPosX
            // 
            this._TextBoxPosX.Location = new System.Drawing.Point(43, 24);
            this._TextBoxPosX.Name = "_TextBoxPosX";
            this._TextBoxPosX.Size = new System.Drawing.Size(100, 23);
            this._TextBoxPosX.TabIndex = 2;
            // 
            // _TextBoxPosY
            // 
            this._TextBoxPosY.Location = new System.Drawing.Point(183, 23);
            this._TextBoxPosY.Name = "_TextBoxPosY";
            this._TextBoxPosY.Size = new System.Drawing.Size(100, 23);
            this._TextBoxPosY.TabIndex = 3;
            // 
            // _ButtonLButtonDown
            // 
            this._ButtonLButtonDown.Location = new System.Drawing.Point(322, 23);
            this._ButtonLButtonDown.Name = "_ButtonLButtonDown";
            this._ButtonLButtonDown.Size = new System.Drawing.Size(94, 23);
            this._ButtonLButtonDown.TabIndex = 6;
            this._ButtonLButtonDown.Text = "LButtonDown";
            this._ButtonLButtonDown.UseVisualStyleBackColor = true;
            this._ButtonLButtonDown.Click += new System.EventHandler(this.ButtonLButtonDown_Click);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 511);
            this.Controls.Add(this._TableLayoutPanel);
            this.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form";
            this.Text = "WebBrowser 사용하기";
            this.Load += new System.EventHandler(this.Form_Load);
            this.Shown += new System.EventHandler(this.Form_Shown);
            this._TableLayoutPanel.ResumeLayout(false);
            this._PanelTop.ResumeLayout(false);
            this._PanelTop.PerformLayout();
            this._PanelFill.ResumeLayout(false);
            this._GroupBoxMousePosition.ResumeLayout(false);
            this._GroupBoxMousePosition.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.WebBrowser _WebBrowser;
        private System.Windows.Forms.TableLayoutPanel _TableLayoutPanel;
        private System.Windows.Forms.TextBox _TextBoxUrl;
        private System.Windows.Forms.Button _ButtonNavigate;
        private System.Windows.Forms.Panel _PanelTop;
        private System.Windows.Forms.Panel _PanelFill;
        private System.Windows.Forms.Button _ButtonExecInvokeScript;
        private System.Windows.Forms.GroupBox _GroupBoxMousePosition;
        private System.Windows.Forms.TextBox _TextBoxPosY;
        private System.Windows.Forms.TextBox _TextBoxPosX;
        private System.Windows.Forms.Label _LabelPosY;
        private System.Windows.Forms.Label _LabelPosX;
        private System.Windows.Forms.Button _ButtonLButtonDown;
    }
}

