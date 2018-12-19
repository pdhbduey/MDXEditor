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
	private: System::Windows::Forms::Button^  DeleteStep;
	private: System::Windows::Forms::DataGridView^  ProtocolDataGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Cycles;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Steps;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Setpoint;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RampRate;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  OpticalAcq;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Melt;
	private: System::Windows::Forms::Button^  AddOptReadBtn;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  DelOptReadBtn;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridView^  OpticalReadsGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LEDIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LedIntensity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LedStabilizationTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DetectorIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RefDetectorIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DetectorIntegrationTime;

	// Form handlers
	public: 

		//event EventHandler ^ OnClickNewStepButton;
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
			this->ProtocolDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Cycles = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Steps = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Setpoint = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RampRate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OpticalAcq = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Melt = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->DeleteStep = (gcnew System::Windows::Forms::Button());
			this->NewStep = (gcnew System::Windows::Forms::Button());
			this->opticsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->OpticalReadsGrid = (gcnew System::Windows::Forms::DataGridView());
			this->LEDIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LedIntensity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LedStabilizationTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DetectorIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RefDetectorIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DetectorIntegrationTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->DelOptReadBtn = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->AddOptReadBtn = (gcnew System::Windows::Forms::Button());
			this->thermalProfileGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProtocolDataGrid))->BeginInit();
			this->opticsGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpticalReadsGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// thermalProfileGroupBox
			// 
			this->thermalProfileGroupBox->Controls->Add(this->ProtocolDataGrid);
			this->thermalProfileGroupBox->Controls->Add(this->DeleteStep);
			this->thermalProfileGroupBox->Controls->Add(this->NewStep);
			this->thermalProfileGroupBox->Location = System::Drawing::Point(3, 3);
			this->thermalProfileGroupBox->Name = L"thermalProfileGroupBox";
			this->thermalProfileGroupBox->Size = System::Drawing::Size(886, 322);
			this->thermalProfileGroupBox->TabIndex = 0;
			this->thermalProfileGroupBox->TabStop = false;
			this->thermalProfileGroupBox->Text = L"Thermal Profile";
			// 
			// ProtocolDataGrid
			// 
			this->ProtocolDataGrid->AllowUserToAddRows = false;
			this->ProtocolDataGrid->AllowUserToDeleteRows = false;
			this->ProtocolDataGrid->AllowUserToResizeColumns = false;
			this->ProtocolDataGrid->AllowUserToResizeRows = false;
			this->ProtocolDataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->ProtocolDataGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->ProtocolDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ProtocolDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Cycles,
					this->Steps, this->Setpoint, this->Time, this->RampRate, this->OpticalAcq, this->Melt
			});
			this->ProtocolDataGrid->Location = System::Drawing::Point(17, 47);
			this->ProtocolDataGrid->Margin = System::Windows::Forms::Padding(2);
			this->ProtocolDataGrid->Name = L"ProtocolDataGrid";
			this->ProtocolDataGrid->RowTemplate->Height = 24;
			this->ProtocolDataGrid->Size = System::Drawing::Size(852, 261);
			this->ProtocolDataGrid->TabIndex = 10;
			// 
			// Cycles
			// 
			this->Cycles->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Cycles->HeaderText = L"Cycles";
			this->Cycles->Name = L"Cycles";
			this->Cycles->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Cycles->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Cycles->Width = 44;
			// 
			// Steps
			// 
			this->Steps->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Steps->HeaderText = L"Step";
			this->Steps->Name = L"Steps";
			this->Steps->ReadOnly = true;
			this->Steps->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Steps->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Steps->Width = 35;
			// 
			// Setpoint
			// 
			this->Setpoint->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Setpoint->HeaderText = L"Setpoint (C)";
			this->Setpoint->Name = L"Setpoint";
			this->Setpoint->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Setpoint->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Setpoint->Width = 68;
			// 
			// Time
			// 
			this->Time->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Time->HeaderText = L"Time (s)";
			this->Time->Name = L"Time";
			this->Time->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Time->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Time->Width = 50;
			// 
			// RampRate
			// 
			this->RampRate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->RampRate->HeaderText = L"Ramp (C/s)";
			this->RampRate->Name = L"RampRate";
			this->RampRate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->RampRate->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->RampRate->Width = 67;
			// 
			// OpticalAcq
			// 
			this->OpticalAcq->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->OpticalAcq->HeaderText = L"Optical Read";
			this->OpticalAcq->Name = L"OpticalAcq";
			this->OpticalAcq->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->OpticalAcq->Width = 75;
			// 
			// Melt
			// 
			this->Melt->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Melt->HeaderText = L"Melt";
			this->Melt->Name = L"Melt";
			this->Melt->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// DeleteStep
			// 
			this->DeleteStep->Location = System::Drawing::Point(97, 20);
			this->DeleteStep->Margin = System::Windows::Forms::Padding(2);
			this->DeleteStep->Name = L"DeleteStep";
			this->DeleteStep->Size = System::Drawing::Size(75, 23);
			this->DeleteStep->TabIndex = 9;
			this->DeleteStep->Text = L"Delete Step";
			this->DeleteStep->UseVisualStyleBackColor = true;
			this->DeleteStep->Click += gcnew System::EventHandler(this, &AmpDetectPage::DeleteStep_Click);
			// 
			// NewStep
			// 
			this->NewStep->Location = System::Drawing::Point(17, 20);
			this->NewStep->Name = L"NewStep";
			this->NewStep->Size = System::Drawing::Size(75, 23);
			this->NewStep->TabIndex = 0;
			this->NewStep->Text = L"New Step";
			this->NewStep->UseVisualStyleBackColor = true;
			this->NewStep->Click += gcnew System::EventHandler(this, &AmpDetectPage::NewStep_Click);
			// 
			// opticsGroupBox
			// 
			this->opticsGroupBox->Controls->Add(this->OpticalReadsGrid);
			this->opticsGroupBox->Controls->Add(this->label7);
			this->opticsGroupBox->Controls->Add(this->DelOptReadBtn);
			this->opticsGroupBox->Controls->Add(this->label6);
			this->opticsGroupBox->Controls->Add(this->AddOptReadBtn);
			this->opticsGroupBox->Location = System::Drawing::Point(3, 331);
			this->opticsGroupBox->Name = L"opticsGroupBox";
			this->opticsGroupBox->Size = System::Drawing::Size(886, 245);
			this->opticsGroupBox->TabIndex = 1;
			this->opticsGroupBox->TabStop = false;
			this->opticsGroupBox->Text = L"Optics";
			// 
			// OpticalReadsGrid
			// 
			this->OpticalReadsGrid->AllowUserToAddRows = false;
			this->OpticalReadsGrid->AllowUserToDeleteRows = false;
			this->OpticalReadsGrid->AllowUserToResizeColumns = false;
			this->OpticalReadsGrid->AllowUserToResizeRows = false;
			this->OpticalReadsGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->OpticalReadsGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OpticalReadsGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->LEDIndex,
					this->LedIntensity, this->LedStabilizationTime, this->DetectorIndex, this->RefDetectorIndex, this->DetectorIntegrationTime
			});
			this->OpticalReadsGrid->Location = System::Drawing::Point(106, 45);
			this->OpticalReadsGrid->Margin = System::Windows::Forms::Padding(2);
			this->OpticalReadsGrid->Name = L"OpticalReadsGrid";
			this->OpticalReadsGrid->RowTemplate->Height = 24;
			this->OpticalReadsGrid->Size = System::Drawing::Size(694, 179);
			this->OpticalReadsGrid->TabIndex = 15;
			// 
			// LEDIndex
			// 
			this->LEDIndex->HeaderText = L"LED Index";
			this->LEDIndex->Name = L"LEDIndex";
			this->LEDIndex->Width = 75;
			// 
			// LedIntensity
			// 
			this->LedIntensity->HeaderText = L"LED Intensity";
			this->LedIntensity->Name = L"LedIntensity";
			// 
			// LedStabilizationTime
			// 
			this->LedStabilizationTime->HeaderText = L"LED Stabilization Time (us)";
			this->LedStabilizationTime->Name = L"LedStabilizationTime";
			// 
			// DetectorIndex
			// 
			this->DetectorIndex->HeaderText = L"Detector Index";
			this->DetectorIndex->Name = L"DetectorIndex";
			this->DetectorIndex->Width = 75;
			// 
			// RefDetectorIndex
			// 
			this->RefDetectorIndex->HeaderText = L"RefDetector Index";
			this->RefDetectorIndex->Name = L"RefDetectorIndex";
			this->RefDetectorIndex->Width = 75;
			// 
			// DetectorIntegrationTime
			// 
			this->DetectorIntegrationTime->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->DetectorIntegrationTime->HeaderText = L"Detector Integration Time (us)";
			this->DetectorIntegrationTime->Name = L"DetectorIntegrationTime";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(146, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Optical reads:";
			// 
			// DelOptReadBtn
			// 
			this->DelOptReadBtn->Location = System::Drawing::Point(5, 72);
			this->DelOptReadBtn->Margin = System::Windows::Forms::Padding(2);
			this->DelOptReadBtn->Name = L"DelOptReadBtn";
			this->DelOptReadBtn->Size = System::Drawing::Size(87, 23);
			this->DelOptReadBtn->TabIndex = 13;
			this->DelOptReadBtn->Text = L"Delete";
			this->DelOptReadBtn->UseVisualStyleBackColor = true;
			this->DelOptReadBtn->Click += gcnew System::EventHandler(this, &AmpDetectPage::DelOptReadBtn_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Type: Photodiode";
			// 
			// AddOptReadBtn
			// 
			this->AddOptReadBtn->Location = System::Drawing::Point(5, 45);
			this->AddOptReadBtn->Margin = System::Windows::Forms::Padding(2);
			this->AddOptReadBtn->Name = L"AddOptReadBtn";
			this->AddOptReadBtn->Size = System::Drawing::Size(87, 23);
			this->AddOptReadBtn->TabIndex = 11;
			this->AddOptReadBtn->Text = L"Add";
			this->AddOptReadBtn->UseVisualStyleBackColor = true;
			this->AddOptReadBtn->Click += gcnew System::EventHandler(this, &AmpDetectPage::AddOptReadBtn_Click);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProtocolDataGrid))->EndInit();
			this->opticsGroupBox->ResumeLayout(false);
			this->opticsGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpticalReadsGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void NewStep_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		DataGridViewRow^ row = gcnew DataGridViewRow;
		ProtocolDataGrid->Rows->Add(row);
	}

	private: System::Void DeleteStep_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int nRowIdx = ProtocolDataGrid->Rows->Count - 1; nRowIdx >= 0; nRowIdx--)
		{
			if (ProtocolDataGrid->Rows[nRowIdx]->Selected)
				ProtocolDataGrid->Rows->RemoveAt(nRowIdx);
		}
	}

	private: System::Void AddOptReadBtn_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		DataGridViewRow^ row = gcnew DataGridViewRow;
		OpticalReadsGrid->Rows->Add(row);
	}


	private: System::Void DelOptReadBtn_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int nRowIdx = OpticalReadsGrid->Rows->Count - 1; nRowIdx >= 0; nRowIdx--)
		{
			if (OpticalReadsGrid->Rows[nRowIdx]->Selected)
				OpticalReadsGrid->Rows->RemoveAt(nRowIdx);
		}
	}
};
}
