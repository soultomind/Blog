﻿namespace UseWebBrowser
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
            this.SuspendLayout();
            // 
            // _WebBrowser
            // 
            this._WebBrowser.Dock = System.Windows.Forms.DockStyle.Fill;
            this._WebBrowser.Location = new System.Drawing.Point(0, 0);
            this._WebBrowser.MinimumSize = new System.Drawing.Size(20, 20);
            this._WebBrowser.Name = "_WebBrowser";
            this._WebBrowser.Size = new System.Drawing.Size(284, 261);
            this._WebBrowser.TabIndex = 0;
            this._WebBrowser.Url = new System.Uri("http://demo.clipsoft.co.kr", System.UriKind.Absolute);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this._WebBrowser);
            this.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form";
            this.Text = "WebBrowser 사용하기";
            this.Load += new System.EventHandler(this.Form_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.WebBrowser _WebBrowser;
    }
}

