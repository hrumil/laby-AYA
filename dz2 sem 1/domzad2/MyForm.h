#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

namespace domzad2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		void e1 (int k, int *f)
			{ 
				if ((int)k >= 128)
				{
 					f[0]=1;
					k =k-128; 
				} 
				else f[0]=0;

				if ((int)k >= 64)
				{
					f[1]=1;
					k=k-64;
				}
				else f[1]=0;

				if ((int)k >= 32)
				{
					f[2]=1;
					k=k-32;
				} 
				else f[2]=0;

				if ((int)k >= 16)
				{
					f[3]=1;
					k=k-16;
				}
				else f[3]=0;

				if ((int)k >= 8)
				{
					f[4]=1;
					k=k-8;
				}
				else f[4]=0;

				if ((int)k >= 4)
				{
					f[5] = 1;
					k=k-4;
				}
				else f[5]=0;

				if ((int)k >= 2)
				{
					f[6]=1;
					k=k-2;
				}
				else f[6]=0;

				if ((int)k==1)
					f[7] = 1;
				else f[7]=0;
			}

		void g (char &k,int *f)
			{ 
				int h=0;
				if (f[0]==1)
					h+=128;
				if (f[1]==1)
					h+=64;
				if (f[2]==1)
					h+=32;
				if (f[3]==1)
					h+=16;
				if (f[4]==1)
					h+=8;
				if (f[5]==1)
					h+=4;
				if (f[6]==1)
					h+=2;
				if (f[7]==1)	
					h+=1;
				k=(char)h;
			}

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  сохранитьToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  открытьДанныеToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;











	private: System::ComponentModel::IContainer^  components;

	protected: 

	protected: 

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьДанныеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(304, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Зашифровать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(433, 260);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Расшифровать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(58, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(231, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите данные для шифрования:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(186, 195);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Введите ключ:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(304, 37);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(240, 125);
			this->textBox1->TabIndex = 4;
			this->textBox1->Tag = L"k";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(304, 195);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(241, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(304, 300);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox3->Size = System::Drawing::Size(241, 76);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(208, 301);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Результат:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->файлToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(599, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->сохранитьToolStripMenuItem, 
				this->открытьДанныеToolStripMenuItem, this->выходToolStripMenuItem});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить данные";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripMenuItem_Click);
			// 
			// открытьДанныеToolStripMenuItem
			// 
			this->открытьДанныеToolStripMenuItem->Name = L"открытьДанныеToolStripMenuItem";
			this->открытьДанныеToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->открытьДанныеToolStripMenuItem->Text = L"Открыть данные";
			this->открытьДанныеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьДанныеToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::saveFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(599, 415);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Шифрование данных";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		

	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
			 {
				if (textBox1->Text == L"")
				{
				MessageBox::Show("Введите текст!",
						"ВНИМАНИЕ", MessageBoxButtons::OK,
					 MessageBoxIcon::Asterisk);
				}
				else
				if (textBox2->Text == L"")
				{
				 MessageBox::Show("Введите пароль!",
					 "ВНИМАНИЕ", MessageBoxButtons::OK,
					 MessageBoxIcon::Asterisk);
				}
				else
				{
				int gamma=0, a=0, b[8], c[8], d[8];
				String^str = textBox1->Text->ToString();
				array<Char>^message = str ->ToCharArray();
				int n = textBox1->Text->Length;				// Длина строки
				int q = System::Convert::ToInt32(textBox2->Text);
				srand(q);
				gamma=rand();
				char *hop = new char [n];
				for(int i=0; i<n; i++)
				{
					a=(int)message[i]^(int)gamma;
					hop[i]=(char)a;
				}
				e1((int)hop[n-1],b);
				// делаем сдвиг на 4 бита
				for(int i=0; i<4; i++)					
					c[i]=b[4+i];
				for(int i=7; i>3; i--)
					b[i]=b[i-4];

				if(n==1)
				{
					for(int i=0; i<4; i++)
						b[i]=c[i];
					g(hop[0],b);
				}
				else
				{
					e1((int) hop[n-2], d);
					for(int i=0; i<4; i++)
						b[i]=d[i+4];
					g(hop[n-1],b);
					for(int i=7; i>3; i--)
						b[i]=d[i-4];
					
					a=10;
					int j=n-2;
					for (j=j-1; j>-1; j--) 
					{
						if ( (a==10) )
						{
							e1((int)hop[j],b);  
							for (int i=0; i<4; i++)
								d[3-i]=b[7-i];
							g(hop[j+1],d);
							for(int i=7; i>3; i--)
								b[i]=b[i-4];
							a=9;
						}
						else 
						{
							e1((int) hop[j],d);
							for (int i=0; i<4; i++)
								b[3-i]=d[7-i];
							g(hop[j+1],b);
							for(int i=7; i>3; i--)
								d[i]=d[i-4];
							a=10;
						}
					}
			
					j=n;
					if ( ((a==10)&(j!=1)) ) 
					{
						for (int i=0; i<4; i++)
							d[i]=c[i];
						e1(hop[0],d);
					}
					if (((a!=10)&(j!=1)))
					{
						for (int i=0; i<4; i++)
							b[i]=c[i];
						e1(hop[0],b);
					}
				}
		
				for(int i=0; i<n; i++)
					message[i] = hop[i];				 
			
				String^ res = gcnew  String(message);
				textBox3->Text = res;	
				}
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				if (textBox1->Text == L"")
				{
				MessageBox::Show("необходимо ввести текст",
						"ВНИМАНИЕ", MessageBoxButtons::OK,
					 MessageBoxIcon::Asterisk);
				}
				else
				if (textBox2->Text == L"")
				{
				 MessageBox::Show("необходимо ввести пароль",
					 "ВНИМАНИЕ", MessageBoxButtons::OK,
					 MessageBoxIcon::Asterisk);
				}
				else
				{
				int gamma=0, a=0, b[8], c[8], d[8];
				String^str = textBox1->Text->ToString();
				array<Char>^message = str ->ToCharArray();
				int n = textBox1->Text->Length;				// Длина строки
				int q = System::Convert::ToInt32(textBox2->Text);
				srand(q);
				gamma=rand();
				char *hop = new char [n];
				for(int i=0; i<n; i++)
					hop[i]=message[i];
				e1((int)hop[0],b);

				for(int i=0; i<4; i++)
					c[4+i]=b[i];
				for(int i=0; i<4; i++)
					b[i]=b[i+4];
				
				if(n==1)
				{
					for(int i=7; i>3; i--)
						b[i]=c[i];
					g(hop[0],b);
					a=(int)hop[0]^(int)gamma;
					message[0]=(char)a;
					String^res=gcnew String(message);
					textBox3->Text=res;
				}
				else
				{
					e1((int) hop[1], d);
					for(int i=0; i<4; i++)
						b[i+4]=d[i];
					g(hop[0],b);
					for(int i=0; i<4; i++)
						b[i]=d[i+4];
					
					a=10;
					int j=2;
					for (j=2; j<n; j++) 
					{
						if ( (a==10) )
						{
							e1((int)hop[j],b);
							for (int i=0; i<4; i++)
								d[i+4]=b[i];
							g(hop[j-1], d);
							for(int i=0; i<4; i++)
								b[i]=b[i+4];
							a=9;
						}
						else 
						{
							e1((int) hop[j],d);
							for (int i=0; i<4; i++)
								b[i+4]=d[i];
							g(hop[j-1],b);
							for(int i=0; i<4; i++)
								d[i]=d[i+4];
							a=10;
						}
					}
			
					j=n;
					if ( ((a==10)&(j!=1)) ) 
					{
						for (int i=7; i>3; i--)
							d[i]=c[i];
						g(hop[n-1],d);
					}
					if (((a!=10)&(j!=1)))
					{
						for (int i=7; i>3; i--)
							b[i]=c[i];
						g(hop[n-1],b);
					}
				}
		
				for(int i=0; i<n; i++)
				{
					a=((int)hop[i])^((int)gamma);
					hop[i]=(char)a;
				}
				for (int i=0; i<n; i++)
					message[i]=hop[i];
				String^ res = gcnew  String(message);
				textBox3->Text = res;	
				}
			}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)  {
			}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
			}
private: System::Void открытьДанныеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			OpenFileDialog^ dig= gcnew OpenFileDialog();
			dig->Filter = "Text Files|*.txt";
			if (dig->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				textBox1->Text = IO::File::ReadAllText(dig->FileName);
			}
		 }
private: System::Void сохранитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			SaveFileDialog ^saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "Text Files|*.txt"  ;
			saveFileDialog1->FilterIndex = 2 ;
			saveFileDialog1->RestoreDirectory = true ;
			if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{        
				IO::File::WriteAllText(saveFileDialog1->FileName,textBox3->Text);
			}
		}
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		}
};
}

