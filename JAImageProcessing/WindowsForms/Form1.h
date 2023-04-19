#ifndef FORM1_H
#define FORM1_H

#include "Controller.h"

void MarshalString(System::String^ s, std::string& os) {
	const char* chars =
		static_cast<const char*>((System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer());
	os = chars;
	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

void MarshalString(System::String^ s, std::wstring& os) {
	const wchar_t* chars =
		static_cast<const wchar_t*>((System::Runtime::InteropServices::Marshal::StringToHGlobalUni(s)).ToPointer());
	os = chars;
	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

namespace CppCLRWinFormsProject {
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// uncomment to execute the rk1-utils:
			//    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::RadioButton^ Cpp_Mode;

	private: System::Windows::Forms::RadioButton^ Asm_Mode;




	protected:

	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::Windows::Forms::TrackBar^ Thread_Bar;
	private: System::Windows::Forms::TextBox^ Text_number;
	private: System::Windows::Forms::TextBox^ Threads_number;




	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ Time_text;

	private: System::Windows::Forms::PictureBox^ Image_in;
	private: System::Windows::Forms::PictureBox^ Image_out;
	private: System::Windows::Forms::Button^ Load_Button;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ time_measured;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;













	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->Cpp_Mode = (gcnew System::Windows::Forms::RadioButton());
			this->Asm_Mode = (gcnew System::Windows::Forms::RadioButton());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->Thread_Bar = (gcnew System::Windows::Forms::TrackBar());
			this->Text_number = (gcnew System::Windows::Forms::TextBox());
			this->Threads_number = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Time_text = (gcnew System::Windows::Forms::TextBox());
			this->Image_in = (gcnew System::Windows::Forms::PictureBox());
			this->Image_out = (gcnew System::Windows::Forms::PictureBox());
			this->Load_Button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->time_measured = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Thread_Bar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Image_in))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Image_out))->BeginInit();
			this->SuspendLayout();
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(450, 487);
			this->startButton->Margin = System::Windows::Forms::Padding(2);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(97, 23);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// Cpp_Mode
			// 
			this->Cpp_Mode->AutoSize = true;
			this->Cpp_Mode->Checked = true;
			this->Cpp_Mode->Location = System::Drawing::Point(11, 487);
			this->Cpp_Mode->Margin = System::Windows::Forms::Padding(2);
			this->Cpp_Mode->Name = L"Cpp_Mode";
			this->Cpp_Mode->Size = System::Drawing::Size(69, 17);
			this->Cpp_Mode->TabIndex = 2;
			this->Cpp_Mode->TabStop = true;
			this->Cpp_Mode->Text = L"CPP DLL";
			this->Cpp_Mode->UseVisualStyleBackColor = true;
			this->Cpp_Mode->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_CppDLL);
			// 
			// Asm_Mode
			// 
			this->Asm_Mode->AutoSize = true;
			this->Asm_Mode->Location = System::Drawing::Point(11, 507);
			this->Asm_Mode->Margin = System::Windows::Forms::Padding(2);
			this->Asm_Mode->Name = L"Asm_Mode";
			this->Asm_Mode->Size = System::Drawing::Size(71, 17);
			this->Asm_Mode->TabIndex = 3;
			this->Asm_Mode->Text = L"ASM DLL";
			this->Asm_Mode->UseVisualStyleBackColor = true;
			this->Asm_Mode->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_AsmDLL);
			// 
			// Thread_Bar
			// 
			this->Thread_Bar->Location = System::Drawing::Point(134, 389);
			this->Thread_Bar->Margin = System::Windows::Forms::Padding(2);
			this->Thread_Bar->Maximum = 64;
			this->Thread_Bar->Minimum = 1;
			this->Thread_Bar->Name = L"Thread_Bar";
			this->Thread_Bar->Size = System::Drawing::Size(200, 45);
			this->Thread_Bar->TabIndex = 4;
			this->Thread_Bar->Value = 1;
			this->Thread_Bar->Scroll += gcnew System::EventHandler(this, &Form1::threadCountTrackBar_Scroll);
			// 
			// Text_number
			// 
			this->Text_number->BackColor = System::Drawing::SystemColors::Control;
			this->Text_number->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_number->Location = System::Drawing::Point(168, 438);
			this->Text_number->Margin = System::Windows::Forms::Padding(2);
			this->Text_number->Name = L"Text_number";
			this->Text_number->Size = System::Drawing::Size(122, 13);
			this->Text_number->TabIndex = 5;
			this->Text_number->Text = L"Wybrana liczba w¹tków:";
			this->Text_number->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// Threads_number
			// 
			this->Threads_number->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Threads_number->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Threads_number->Location = System::Drawing::Point(301, 438);
			this->Threads_number->Margin = System::Windows::Forms::Padding(2);
			this->Threads_number->Name = L"Threads_number";
			this->Threads_number->Size = System::Drawing::Size(54, 13);
			this->Threads_number->TabIndex = 6;
			this->Threads_number->Text = L"1";
			this->Threads_number->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// Time_text
			// 
			this->Time_text->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Time_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Time_text->Location = System::Drawing::Point(840, 497);
			this->Time_text->Margin = System::Windows::Forms::Padding(2);
			this->Time_text->Name = L"Time_text";
			this->Time_text->Size = System::Drawing::Size(140, 13);
			this->Time_text->TabIndex = 7;
			this->Time_text->Text = L"Czas dzia³ania programu :";
			this->Time_text->TextChanged += gcnew System::EventHandler(this, &Form1::TextTime_TextChanged_1);
			// 
			// Image_in
			// 
			this->Image_in->Location = System::Drawing::Point(48, 28);
			this->Image_in->Name = L"Image_in";
			this->Image_in->Size = System::Drawing::Size(369, 301);
			this->Image_in->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Image_in->TabIndex = 8;
			this->Image_in->TabStop = false;
			this->Image_in->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// Image_out
			// 
			this->Image_out->Location = System::Drawing::Point(655, 28);
			this->Image_out->Name = L"Image_out";
			this->Image_out->Size = System::Drawing::Size(369, 301);
			this->Image_out->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Image_out->TabIndex = 9;
			this->Image_out->TabStop = false;
			// 
			// Load_Button
			// 
			this->Load_Button->Location = System::Drawing::Point(48, 357);
			this->Load_Button->Name = L"Load_Button";
			this->Load_Button->Size = System::Drawing::Size(109, 23);
			this->Load_Button->TabIndex = 10;
			this->Load_Button->Text = L"Zmieñ zdjêcie!";
			this->Load_Button->UseVisualStyleBackColor = true;
			this->Load_Button->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(465, 366);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 11;
			// 
			// time_measured
			// 
			this->time_measured->AutoSize = true;
			this->time_measured->Location = System::Drawing::Point(986, 496);
			this->time_measured->Name = L"time_measured";
			this->time_measured->Size = System::Drawing::Size(0, 13);
			this->time_measured->TabIndex = 12;
			this->time_measured->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(45, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Zdjêcie wejœciowe :";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(652, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Zdjêcie wyjœciowe :";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1079, 544);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->time_measured);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Load_Button);
			this->Controls->Add(this->Image_out);
			this->Controls->Add(this->Image_in);
			this->Controls->Add(this->Time_text);
			this->Controls->Add(this->Threads_number);
			this->Controls->Add(this->Text_number);
			this->Controls->Add(this->Thread_Bar);
			this->Controls->Add(this->Asm_Mode);
			this->Controls->Add(this->Cpp_Mode);
			this->Controls->Add(this->startButton);
			this->Name = L"Form1";
			this->Text = L"Rozmycie obrazu";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Thread_Bar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Image_in))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Image_out))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// You can call the functions at a button click. If you prefer,
		 // you can call them by clicking a menu item.

	

	private: System::Void radioButton_CppDLL(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton_AsmDLL(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void threadCountTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
		Threads_number->Text = Thread_Bar->Value.ToString();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int mode = 0;

		if (Cpp_Mode->Checked == true)
		{
			mode = 1;
		}

		/*const char* file_in = "kratos.bmp";
		Image_in->Load("kratos.bmp");
		Image_in->Show();*/
		//const char* file_in = "";
		/*if (label1->Text != "")
		{*/
			std::string ifilename;
			MarshalString(openFileDialog1->FileName->ToString(), ifilename);
			const char* file_in = ifilename.c_str();
		//}


		Controller controller(mode, file_in);

		float time = 0;

		time += controller.smooth_func(Thread_Bar->Value);


		Image_out->Load("c.bmp");
		Image_out->Show();

		Load_Button->Hide();

		System::String^ text = gcnew System::String(time + " " + " ms");
		this->time_measured->Text = text;
	}
	private: System::Void loadButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextTime_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ShowTime_TextChanged_2(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void CheckLoad_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void textBox1_TextChanged_2(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if (openFileDialog1->FileName != nullptr) {
			this->label1->Text = "Zdjêcie zosta³o wczytane poprawnie";
		}
		else
		{
			openFileDialog1->FileName = "kratos.bmp";
		}
	}

	Image_in->Load(openFileDialog1->FileName);
	Image_in->Show();
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

#endif
