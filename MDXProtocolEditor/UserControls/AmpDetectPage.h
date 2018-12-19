#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UserControls {
	/// <summary>
	/// Summary for AmpDetectPage
	/// </summary>
	public ref class AmpDetectPage : public System::Windows::Forms::UserControl
	{
	public:
		AmpDetectPage(void)
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
		~AmpDetectPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  thermalProfileGroupBox;
	private: System::Windows::Forms::GroupBox^  opticsGroupBox;
	private: System::Windows::Forms::Button^  NewStep;

	// Form handlers
	public: 

		event EventHandler ^ OnClickNewStepButton;
	protected:

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
			this->thermalProfileGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->NewStep = (gcnew System::Windows::Forms::Button());
			this->opticsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->thermalProfileGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// thermalProfileGroupBox
			// 
			this->thermalProfileGroupBox->Controls->Add(this->NewStep);
			this->thermalProfileGroupBox->Location = System::Drawing::Point(3, 3);
			this->thermalProfileGroupBox->Name = L"thermalProfileGroupBox";
			this->thermalProfileGroupBox->Size = System::Drawing::Size(886, 295);
			this->thermalProfileGroupBox->TabIndex = 0;
			this->thermalProfileGroupBox->TabStop = false;
			this->thermalProfileGroupBox->Text = L"Thermal Profile";
			// 
			// NewStep
			// 
			this->NewStep->Location = System::Drawing::Point(7, 20);
			this->NewStep->Name = L"NewStep";
			this->NewStep->Size = System::Drawing::Size(75, 23);
			this->NewStep->TabIndex = 0;
			this->NewStep->Text = L"New Step";
			this->NewStep->UseVisualStyleBackColor = true;
			this->NewStep->Click += gcnew System::EventHandler(this, &AmpDetectPage::NewStep_Click);
			// 
			// opticsGroupBox
			// 
			this->opticsGroupBox->Location = System::Drawing::Point(3, 304);
			this->opticsGroupBox->Name = L"opticsGroupBox";
			this->opticsGroupBox->Size = System::Drawing::Size(886, 272);
			this->opticsGroupBox->TabIndex = 1;
			this->opticsGroupBox->TabStop = false;
			this->opticsGroupBox->Text = L"Optics";
			// 
			// AmpDetectPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->opticsGroupBox);
			this->Controls->Add(this->thermalProfileGroupBox);
			this->Name = L"AmpDetectPage";
			this->Size = System::Drawing::Size(901, 666);
			this->thermalProfileGroupBox->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void NewStep_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		OnClickNewStepButton(this, nullptr);
	}
	};
}
