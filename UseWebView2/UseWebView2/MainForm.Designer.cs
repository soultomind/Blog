
namespace WebView2
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this._WebView2 = new Microsoft.Web.WebView2.WinForms.WebView2();
            this._TableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this._Panel1 = new System.Windows.Forms.Panel();
            this._LabelWebView2Version = new System.Windows.Forms.Label();
            this._TextBoxUri = new System.Windows.Forms.TextBox();
            this._ButtonWebView2Navigate = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this._WebView2)).BeginInit();
            this._TableLayoutPanel.SuspendLayout();
            this._Panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // _WebView2
            // 
            this._WebView2.CreationProperties = null;
            this._WebView2.DefaultBackgroundColor = System.Drawing.Color.White;
            this._WebView2.Dock = System.Windows.Forms.DockStyle.Fill;
            this._WebView2.Location = new System.Drawing.Point(3, 64);
            this._WebView2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this._WebView2.Name = "_WebView2";
            this._WebView2.Size = new System.Drawing.Size(778, 793);
            this._WebView2.TabIndex = 0;
            this._WebView2.ZoomFactor = 1D;
            // 
            // _TableLayoutPanel
            // 
            this._TableLayoutPanel.ColumnCount = 1;
            this._TableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this._TableLayoutPanel.Controls.Add(this._Panel1, 0, 0);
            this._TableLayoutPanel.Controls.Add(this._WebView2, 0, 1);
            this._TableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this._TableLayoutPanel.Location = new System.Drawing.Point(0, 0);
            this._TableLayoutPanel.Name = "_TableLayoutPanel";
            this._TableLayoutPanel.RowCount = 2;
            this._TableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 7F));
            this._TableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 93F));
            this._TableLayoutPanel.Size = new System.Drawing.Size(784, 861);
            this._TableLayoutPanel.TabIndex = 1;
            // 
            // _Panel1
            // 
            this._Panel1.Controls.Add(this._LabelWebView2Version);
            this._Panel1.Controls.Add(this._TextBoxUri);
            this._Panel1.Controls.Add(this._ButtonWebView2Navigate);
            this._Panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this._Panel1.Location = new System.Drawing.Point(3, 3);
            this._Panel1.Name = "_Panel1";
            this._Panel1.Size = new System.Drawing.Size(778, 54);
            this._Panel1.TabIndex = 2;
            // 
            // _LabelWebView2Version
            // 
            this._LabelWebView2Version.AutoSize = true;
            this._LabelWebView2Version.Location = new System.Drawing.Point(9, 34);
            this._LabelWebView2Version.Name = "_LabelWebView2Version";
            this._LabelWebView2Version.Size = new System.Drawing.Size(124, 15);
            this._LabelWebView2Version.TabIndex = 3;
            this._LabelWebView2Version.Text = "Edge 브라우저 버전 : ";
            // 
            // _TextBoxUri
            // 
            this._TextBoxUri.Location = new System.Drawing.Point(9, 6);
            this._TextBoxUri.Name = "_TextBoxUri";
            this._TextBoxUri.Size = new System.Drawing.Size(683, 23);
            this._TextBoxUri.TabIndex = 2;
            this._TextBoxUri.Text = "http://www.google.com";
            // 
            // _ButtonWebView2Navigate
            // 
            this._ButtonWebView2Navigate.Location = new System.Drawing.Point(698, 6);
            this._ButtonWebView2Navigate.Name = "_ButtonWebView2Navigate";
            this._ButtonWebView2Navigate.Size = new System.Drawing.Size(75, 23);
            this._ButtonWebView2Navigate.TabIndex = 1;
            this._ButtonWebView2Navigate.Text = "Go";
            this._ButtonWebView2Navigate.UseVisualStyleBackColor = true;
            this._ButtonWebView2Navigate.Click += new System.EventHandler(this.ButtonWebView2Navigate_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 861);
            this.Controls.Add(this._TableLayoutPanel);
            this.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.Shown += new System.EventHandler(this.MainForm_Shown);
            ((System.ComponentModel.ISupportInitialize)(this._WebView2)).EndInit();
            this._TableLayoutPanel.ResumeLayout(false);
            this._Panel1.ResumeLayout(false);
            this._Panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private Microsoft.Web.WebView2.WinForms.WebView2 _WebView2;
        private System.Windows.Forms.TableLayoutPanel _TableLayoutPanel;
        private System.Windows.Forms.Panel _Panel1;
        private System.Windows.Forms.Button _ButtonWebView2Navigate;
        private System.Windows.Forms.TextBox _TextBoxUri;
        private System.Windows.Forms.Label _LabelWebView2Version;
    }
}