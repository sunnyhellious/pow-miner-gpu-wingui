#pragma once

namespace tonpowminergpuwingui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FoundsAllForm
	/// </summary>
	public ref class FoundsAllForm : public System::Windows::Forms::Form
	{
	public:
		FoundsAllForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FoundsAllForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::TextBox^  FoundsAllTextBox;
	private: System::ComponentModel::IContainer^  components;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FoundsAllForm::typeid));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->FoundsAllTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// FoundsAllTextBox
			// 
			this->FoundsAllTextBox->Location = System::Drawing::Point(12, 12);
			this->FoundsAllTextBox->Multiline = true;
			this->FoundsAllTextBox->Name = L"FoundsAllTextBox";
			this->FoundsAllTextBox->ReadOnly = true;
			this->FoundsAllTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->FoundsAllTextBox->Size = System::Drawing::Size(626, 237);
			this->FoundsAllTextBox->TabIndex = 33;
			// 
			// FoundsAllForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 261);
			this->Controls->Add(this->FoundsAllTextBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(666, 300);
			this->MinimumSize = System::Drawing::Size(666, 300);
			this->Name = L"FoundsAllForm";
			this->Text = L"Founds";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: TextBox^ GetFoundsAllTextBox(void) {
			return this->FoundsAllTextBox;
		}

	};
}
