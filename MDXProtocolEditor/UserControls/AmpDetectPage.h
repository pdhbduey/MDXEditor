#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "PcrProtocol.h"
#include "MdxProtocol.h"
#pragma make_public(MdxProtocol)

namespace UserControls {
	/// <summary>
	/// Summary for AmpDetectPage
	/// </summary>
	public ref class AmpDetectPage : public System::Windows::Forms::UserControl
	{
	public:
		AmpDetectPage()
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
	public: System::Windows::Forms::DataGridView^  ProtocolDataGrid;
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
	public: System::Windows::Forms::DataGridView^  OpticalReadsGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LEDIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LedIntensity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LedStabilizationTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DetectorIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RefDetectorIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DetectorIntegrationTime;
	private: System::Windows::Forms::SaveFileDialog^  saveProtocolDlg;
	private: System::Windows::Forms::OpenFileDialog^  openProtocolDlg;
	private: System::Windows::Forms::FolderBrowserDialog^  SelectDataFolderDlg;
	private: System::Windows::Forms::Timer^  StatusTimer;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::TextBox^  ProtocolName;








	// Handlers
	private:
		MdxProtocol* mdxProtocol;
	public: 
		System::Void PassMdxProtocolObject(MdxProtocol* mdxProtocol) 
		{
			this->mdxProtocol = mdxProtocol;
		}
		event EventHandler ^ OnClickNewStepButton;
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
			this->thermalProfileGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->ProtocolName = (gcnew System::Windows::Forms::TextBox());
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
			this->saveProtocolDlg = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openProtocolDlg = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SelectDataFolderDlg = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->StatusTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->thermalProfileGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProtocolDataGrid))->BeginInit();
			this->opticsGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpticalReadsGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// thermalProfileGroupBox
			// 
			this->thermalProfileGroupBox->Controls->Add(this->ProtocolName);
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
			// ProtocolName
			// 
			this->ProtocolName->Location = System::Drawing::Point(613, 22);
			this->ProtocolName->Name = L"ProtocolName";
			this->ProtocolName->Size = System::Drawing::Size(100, 20);
			this->ProtocolName->TabIndex = 11;
			this->ProtocolName->Visible = false;
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
			this->ProtocolDataGrid->Location = System::Drawing::Point(106, 47);
			this->ProtocolDataGrid->Margin = System::Windows::Forms::Padding(2);
			this->ProtocolDataGrid->Name = L"ProtocolDataGrid";
			this->ProtocolDataGrid->RowTemplate->Height = 24;
			this->ProtocolDataGrid->Size = System::Drawing::Size(763, 261);
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
			this->DeleteStep->Location = System::Drawing::Point(9, 75);
			this->DeleteStep->Margin = System::Windows::Forms::Padding(2);
			this->DeleteStep->Name = L"DeleteStep";
			this->DeleteStep->Size = System::Drawing::Size(85, 23);
			this->DeleteStep->TabIndex = 9;
			this->DeleteStep->Text = L"Delete Step";
			this->DeleteStep->UseVisualStyleBackColor = true;
			this->DeleteStep->Click += gcnew System::EventHandler(this, &AmpDetectPage::DeleteStep_Click);
			// 
			// NewStep
			// 
			this->NewStep->Location = System::Drawing::Point(9, 47);
			this->NewStep->Name = L"NewStep";
			this->NewStep->Size = System::Drawing::Size(85, 23);
			this->NewStep->TabIndex = 0;
			this->NewStep->Text = L"Insert Step";
			this->NewStep->UseVisualStyleBackColor = true;
			this->NewStep->Click += gcnew System::EventHandler(this, &AmpDetectPage::InsertAboveThermal_Click);
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
			this->OpticalReadsGrid->Size = System::Drawing::Size(763, 179);
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
			this->label7->Location = System::Drawing::Point(103, 30);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Optical reads:";
			// 
			// DelOptReadBtn
			// 
			this->DelOptReadBtn->Location = System::Drawing::Point(7, 72);
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
			this->AddOptReadBtn->Location = System::Drawing::Point(7, 45);
			this->AddOptReadBtn->Margin = System::Windows::Forms::Padding(2);
			this->AddOptReadBtn->Name = L"AddOptReadBtn";
			this->AddOptReadBtn->Size = System::Drawing::Size(87, 23);
			this->AddOptReadBtn->TabIndex = 11;
			this->AddOptReadBtn->Text = L"Insert Read";
			this->AddOptReadBtn->UseVisualStyleBackColor = true;
			this->AddOptReadBtn->Click += gcnew System::EventHandler(this, &AmpDetectPage::InsertAbovePhotodiode_Click);
			// 
			// saveProtocolDlg
			// 
			this->saveProtocolDlg->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &AmpDetectPage::saveProtocolDlg_FileOk);
			// 
			// StatusTimer
			// 
			this->StatusTimer->Enabled = true;
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
			this->thermalProfileGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProtocolDataGrid))->EndInit();
			this->opticsGroupBox->ResumeLayout(false);
			this->opticsGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpticalReadsGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void DeleteStep_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int nRowIdx = ProtocolDataGrid->Rows->Count - 1; nRowIdx >= 0; nRowIdx--)
		{
			if (ProtocolDataGrid->Rows[nRowIdx]->Selected)
				ProtocolDataGrid->Rows->RemoveAt(nRowIdx);
		}
	}

	private: System::Void DelOptReadBtn_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int nRowIdx = OpticalReadsGrid->Rows->Count - 1; nRowIdx >= 0; nRowIdx--)
		{
			if (OpticalReadsGrid->Rows[nRowIdx]->Selected)
				OpticalReadsGrid->Rows->RemoveAt(nRowIdx);
		}
	}

	private: System::Void saveProtocolDlg_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
	{

	}

	public: System::Void ClearGrids()
	{
		ProtocolDataGrid->Rows->Clear();
		OpticalReadsGrid->Rows->Clear();
	}

	public: System::Void OpenProtocol()
	{
		ProtocolDataGrid->Rows->Clear();
		OpticalReadsGrid->Rows->Clear();

		openProtocolDlg->FileName = ProtocolName->Text;
		openProtocolDlg->AddExtension = true;
		openProtocolDlg->Filter = "pcr protocols (*.qpcr)|*.qpcr|All files (*.*)|*.*";

		if (openProtocolDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			ProtocolName->Text = openProtocolDlg->FileName;
			System::IO::StreamReader^ file = gcnew System::IO::StreamReader(ProtocolName->Text);
			System::IO::BinaryReader^ binFile = gcnew System::IO::BinaryReader(file->BaseStream);

			array<uint8_t>^ protocolBuf = binFile->ReadBytes((int)binFile->BaseStream->Length);
			uint8_t arTemp[5 * 1024];
			for (int i = 0; i < (int)binFile->BaseStream->Length; i++)
				arTemp[i] = protocolBuf[i];

			PcrProtocol _ampDetect;
			_ampDetect << arTemp;
			WriteAmpDetectToGui(_ampDetect);
			binFile->Close();
		}
	}

	private: System::Void WriteAmpDetectToGui(PcrProtocol& ampDetect)
	{
		ProtocolDataGrid->Rows->Clear();
		OpticalReadsGrid->Rows->Clear();

		//Iterate through all optical reads in this protocol.
		for (int i = 0; i < (int)ampDetect.GetNumOpticalReads(); i++)
		{
			DataGridViewRow^ row = gcnew DataGridViewRow;
			OpticalReadsGrid->Rows->Add(row);
			int nRowIdx = OpticalReadsGrid->RowCount - 1;
			OpticalRead optRead = ampDetect.GetOpticalRead(i);

			OpticalReadsGrid[0, nRowIdx]->Value = optRead.GetLedIdx();
			OpticalReadsGrid[1, nRowIdx]->Value = optRead.GetLedIntensity();
			OpticalReadsGrid[2, nRowIdx]->Value = optRead.GetLedStablizationTime();
			OpticalReadsGrid[3, nRowIdx]->Value = optRead.GetDetectorIdx();
			OpticalReadsGrid[4, nRowIdx]->Value = optRead.GetReferenceIdx();
			OpticalReadsGrid[5, nRowIdx]->Value = optRead.GetDetectorIntegrationTime();
		}

		//Iterate through all segments in this protocol.
		for (int nSegIdx = 0; nSegIdx < (int)ampDetect.GetNumSegs(); nSegIdx++)
		{
			Segment seg = ampDetect.GetSegment(nSegIdx);

			//Iterate through all steps in this segment.
			for (int nStepIdx = 0; nStepIdx < (int)seg.GetNumSteps(); nStepIdx++)
			{
				DataGridViewRow^ row = gcnew DataGridViewRow;
				ProtocolDataGrid->Rows->Add(row);
				int nRowIdx = ProtocolDataGrid->RowCount - 1;
				Step step = seg.GetStep(nStepIdx);

				//If this is the first step in the segment, report number of cycles.
				if (nStepIdx == 0)
					ProtocolDataGrid[0, nRowIdx]->Value = Convert::ToString(seg.GetNumCycles());

				ProtocolDataGrid[1, nRowIdx]->Value = Convert::ToString(nStepIdx + 1);
				ProtocolDataGrid[2, nRowIdx]->Value = Convert::ToString((double)step.GetTargetTemp() / 1000);
				ProtocolDataGrid[3, nRowIdx]->Value = Convert::ToString((double)step.GetHoldTimer() / 1000);
				ProtocolDataGrid[4, nRowIdx]->Value = Convert::ToString((double)step.GetRampRate() / 1000);

				//Optical acquisition.
				ProtocolDataGrid[5, nRowIdx]->Value = step.GetOpticalAcqFlg();

				//Melt
				ProtocolDataGrid[6, nRowIdx]->Value = step.GetMeltFlg();
			}
		}
	}

	public: System::Void SaveProtocol()
	{
		saveProtocolDlg->FileName = ProtocolName->Text;
		saveProtocolDlg->AddExtension = true;
		saveProtocolDlg->OverwritePrompt = true;
		saveProtocolDlg->Filter = "pcr protocols (*.qpcr)|*.qpcr|All files (*.*)|*.*";

		PcrProtocol ampDetect;
		ReadAmpDetectFromGui(&ampDetect);
		if (saveProtocolDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			ProtocolName->Text = saveProtocolDlg->FileName;
			System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter(ProtocolName->Text);
			System::IO::BinaryWriter^ binFile = gcnew System::IO::BinaryWriter(file->BaseStream);

			uint8_t arTemp[5 * 1024];
			ampDetect >> arTemp;
			array<uint8_t>^ protocolBuf = gcnew array<uint8_t>(ampDetect.GetStreamSize());
			for (int i = 0; i < (int)ampDetect.GetStreamSize(); i++)
				protocolBuf[i] = arTemp[i];

			binFile->BaseStream->SetLength(0);
			binFile->Write(protocolBuf);
			binFile->Close();
		}
		WriteAmpDetectToGui(ampDetect);
	}

	private: System::Void ReadAmpDetectFromGui(PcrProtocol* pAmpDetect)
	{
		pAmpDetect->Clear();

		OpticalRead optRead;
		pAmpDetect->SetFluorDetectorType(kPhotoDiode);
		for (int nRowIdx = 0; nRowIdx < OpticalReadsGrid->Rows->Count; nRowIdx++)
		{
			optRead.SetLedIdx(Convert::ToInt32(OpticalReadsGrid[0, nRowIdx]->Value));
			optRead.SetLedIntensity(Convert::ToInt32(OpticalReadsGrid[1, nRowIdx]->Value));
			optRead.SetLedStablizationTime(Convert::ToInt32(OpticalReadsGrid[2, nRowIdx]->Value));
			optRead.SetDetectorIdx(Convert::ToInt32(OpticalReadsGrid[3, nRowIdx]->Value));
			optRead.SetReferenceIdx(Convert::ToInt32(OpticalReadsGrid[4, nRowIdx]->Value));
			optRead.SetDetectorIntegrationTime(Convert::ToInt32(OpticalReadsGrid[5, nRowIdx]->Value));
			pAmpDetect->AddOpticalRead(optRead);
		}

		Segment seg;
		for (int nRowIdx = 0; nRowIdx < ProtocolDataGrid->Rows->Count; nRowIdx++)
		{
			int nNumCycles = Convert::ToInt32(ProtocolDataGrid[0, nRowIdx]->Value);
			if ((nRowIdx == 0) && (!(nNumCycles > 0)))
				nNumCycles = 1;

			if (nNumCycles != 0)
			{
				seg.Clear();
				seg.SetNumCycles(nNumCycles);
			}

			Step step;
			step.SetTargetTemp((int32_t)(Convert::ToDouble(ProtocolDataGrid[2, nRowIdx]->Value) * 1000));
			step.SetHoldTimer((uint32_t)(Convert::ToDouble(ProtocolDataGrid[3, nRowIdx]->Value) * 1000));
			step.SetRampRate((int32_t)(Convert::ToDouble(ProtocolDataGrid[4, nRowIdx]->Value) * 1000));
			step.SetOpticalAcqFlg(Convert::ToBoolean(((DataGridViewCheckBoxCell^)ProtocolDataGrid[5, nRowIdx])->Value) == true);
			step.SetMeltFlg(Convert::ToBoolean(((DataGridViewCheckBoxCell^)ProtocolDataGrid[6, nRowIdx])->Value) == true);
			seg.AddStep(step);

			if ((nRowIdx >= ProtocolDataGrid->Rows->Count - 1) || (Convert::ToInt32(ProtocolDataGrid[0, nRowIdx + 1]->Value) > 0))
				pAmpDetect->AddSegment(seg);
		}
	}

	private: System::Void InsertAbovePhotodiode_Click(System::Object^  sender, System::EventArgs^  e)
	{
		bool rowHadAnySelection = false;
		DataGridViewRow^ row = gcnew DataGridViewRow;

		for (int currentRowIndex = 0; currentRowIndex < OpticalReadsGrid->Rows->Count; currentRowIndex++)
		{
			if (OpticalReadsGrid->Rows[currentRowIndex]->Selected)
			{
				OpticalReadsGrid->Rows->Insert(currentRowIndex + 1);
				rowHadAnySelection = true;
				break;
			}
		}

		if (!rowHadAnySelection)
		{
			OpticalReadsGrid->Rows->Add(row);
		}
	}

	private: System::Void InsertAboveThermal_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		bool rowHadAnySelection = false;
		DataGridViewRow^ row = gcnew DataGridViewRow;

		for (int currentRowIndex = 0; currentRowIndex < ProtocolDataGrid->Rows->Count; currentRowIndex++)
		{
			if (ProtocolDataGrid->Rows[currentRowIndex]->Selected)
			{
				ProtocolDataGrid->Rows->Insert(currentRowIndex + 1);
				rowHadAnySelection = true;
				break;
			}
		}

		if (!rowHadAnySelection)
		{
			ProtocolDataGrid->Rows->Add(row);
		}
	}
};
}
