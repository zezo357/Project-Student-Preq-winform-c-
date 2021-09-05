#pragma once

#include "source.cpp"
#include "logic.h"



btree* tree = new btree();

output qwe;
namespace ProjectStudentPreq {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			
			
			
			string course, preq;
			int courses;
			if (freopen("file.out", "r", stdin) != NULL) {
				cin >> courses;
				cin.ignore();
				for (int i = 1; i <= courses; i++) {
					getline(cin, preq);
					getline(cin, course);
					tree->insert(course, preq);
					String^ str2 = gcnew String(course.c_str());
					this->comboBox1->Items->Add(str2);
				}
			}
			else {
				MessageBox::Show("Make sure that the course list is in the same folder and named 'file.out' closing after Ok");
				exit(0);
			}
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListView^ taken;

	private: System::Windows::Forms::ColumnHeader^ can1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListView^ wanted;

	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ListView^ cant;

	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ListView^ can;

	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->taken = (gcnew System::Windows::Forms::ListView());
			this->can1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->wanted = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->cant = (gcnew System::Windows::Forms::ListView());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->can = (gcnew System::Windows::Forms::ListView());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Location = System::Drawing::Point(152, 384);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// taken
			// 
			this->taken->Activation = System::Windows::Forms::ItemActivation::TwoClick;
			this->taken->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->taken->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->can1 });
			this->taken->HideSelection = false;
			this->taken->Location = System::Drawing::Point(6, 35);
			this->taken->Name = L"taken";
			this->taken->Size = System::Drawing::Size(246, 348);
			this->taken->TabIndex = 1;
			this->taken->UseCompatibleStateImageBehavior = false;
			this->taken->View = System::Windows::Forms::View::Details;
			this->taken->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// can1
			// 
			this->can1->Text = L"The courses that the student have taken";
			this->can1->Width = 330;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Location = System::Drawing::Point(6, 384);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 37);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Remove";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->AllowDrop = true;
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(6, 8);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(508, 21);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button3->Location = System::Drawing::Point(268, 384);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(102, 37);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Remove";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// wanted
			// 
			this->wanted->Activation = System::Windows::Forms::ItemActivation::TwoClick;
			this->wanted->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->wanted->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->columnHeader1 });
			this->wanted->HideSelection = false;
			this->wanted->Location = System::Drawing::Point(268, 35);
			this->wanted->Name = L"wanted";
			this->wanted->Size = System::Drawing::Size(246, 348);
			this->wanted->TabIndex = 7;
			this->wanted->UseCompatibleStateImageBehavior = false;
			this->wanted->View = System::Windows::Forms::View::Details;
			this->wanted->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView2_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"The courses that the student want to take";
			this->columnHeader1->Width = 330;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button4->Location = System::Drawing::Point(407, 384);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(107, 37);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Add";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// cant
			// 
			this->cant->Activation = System::Windows::Forms::ItemActivation::TwoClick;
			this->cant->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->cant->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->columnHeader2 });
			this->cant->HideSelection = false;
			this->cant->Location = System::Drawing::Point(793, 12);
			this->cant->Name = L"cant";
			this->cant->Size = System::Drawing::Size(246, 371);
			this->cant->TabIndex = 10;
			this->cant->UseCompatibleStateImageBehavior = false;
			this->cant->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"The courses that the student can not take";
			this->columnHeader2->Width = 450;
			// 
			// can
			// 
			this->can->Activation = System::Windows::Forms::ItemActivation::TwoClick;
			this->can->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->can->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->columnHeader3 });
			this->can->HideSelection = false;
			this->can->Location = System::Drawing::Point(525, 12);
			this->can->Name = L"can";
			this->can->Size = System::Drawing::Size(246, 371);
			this->can->TabIndex = 9;
			this->can->UseCompatibleStateImageBehavior = false;
			this->can->View = System::Windows::Forms::View::Details;
			this->can->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::can_SelectedIndexChanged);
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"The courses that the student can take";
			this->columnHeader3->Width = 330;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button5->Location = System::Drawing::Point(557, 384);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(214, 37);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Check";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(946, 384);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(92, 37);
			this->button6->TabIndex = 12;
			this->button6->Text = L"About";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(821, 384);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(103, 37);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Clear";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(1050, 421);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->cant);
			this->Controls->Add(this->can);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->wanted);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->taken);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"ProjectStudentPreq";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	
		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->comboBox1->Items->Contains(this->comboBox1->Text)&& !(this->taken->FindItemWithText((this->comboBox1->Text)))) {
			
		this->taken->Items->Add(this->comboBox1->Text);
	}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if(this->taken->SelectedItems->Count !=0){
			if (this->taken->FindItemWithText((this->taken->SelectedItems[0]->Text))) {
				this->taken->Items->Remove(this->taken->SelectedItems[0]);
				
			}
		}
	}
private: System::Void listView2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->wanted->SelectedItems->Count != 0) {
		if (this->wanted->FindItemWithText((this->wanted->SelectedItems[0]->Text))) {
			this->wanted->Items->Remove(this->wanted->SelectedItems[0]);

		}
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	if (this->comboBox1->Items->Contains(this->comboBox1->Text) && !(this->wanted->FindItemWithText((this->comboBox1->Text)))) {

		this->wanted->Items->Add(this->comboBox1->Text);
	}
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	qwe.clear();
	tree->clearstatus();
	this->can->Items->Clear();
	this->cant->Items->Clear();
	String^ str2;
	string line;
	
	for (int i = 0; i < this->taken->Items->Count; i++) {
		str2 = gcnew String(this->taken->Items[i]->Text);
		MarshalString(str2, line);
		tree->changestatus(line);

	}
	
	for (int i = 0; i < this->wanted->Items->Count; i++) {
		str2 = gcnew String(this->wanted->Items[i]->Text);
		MarshalString(str2, line);
		if (!(this->taken->FindItemWithText(str2))) {
			qwe.wanted.insert(qwe.wanted.end(), line);
		}
		else { qwe.wanted.insert(qwe.wanted.end(), line+" this course has been already taken"); }
		
	}
	
	tree->checkcanbetaken(qwe);
	qwe.org();
	for (int i = 0; i < qwe.can.size(); i++) {
		str2 = gcnew String(qwe.can.at(i).c_str());
		this->can->Items->Add(str2);
	}
	for (int i = 0; i < qwe.cant.size(); i++) {
		str2 = gcnew String(qwe.cant.at(i).c_str());
		this->cant->Items->Add(str2);
	}
	
	

	
}
private: System::Void can_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("created by abdelaziz hossameldin date: 1/22/2020");
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	this->taken->Items->Clear();
	this->wanted->Items->Clear();
	this->can->Items->Clear();
	this->cant->Items->Clear();
}
		private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			/*
				if (this->taken->SelectedItems->Count != 0) {
					if (this->taken->FindItemWithText((this->taken->SelectedItems[0]->Text))) {
						this->taken->Items->Remove(this->taken->SelectedItems[0]);

					}
				}*/

		}
};
}
