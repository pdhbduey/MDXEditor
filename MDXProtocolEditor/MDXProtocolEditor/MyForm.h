#pragma once

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <msclr\marshal.h>

#include "PcrProtocol.h"
#include "StreamingObj.h"

using namespace System::IO::Ports;
using namespace msclr::interop;

typedef struct {
	uint8_t _nCameraIndex;
	uint8_t _nCameraCaptureStart;
	uint8_t _nCameraCaptureDone;
}CameraStatus;

typedef struct {
	HANDLE hFileMap;
	CameraStatus *camCaptureStatus;
	char MapName[256];
	size_t size;
}CameraStatusHeader;

CameraStatusHeader camStatusHdr;
CameraStatus camStatus;

//bool GrabSucceddedStatus(void);
typedef bool (WINAPI* GrabSucceededStatus)(void);
//void CameraCapture(int cameraID, int exposure);
typedef void (WINAPI* CameraCapture)(int cameraID, int exposure, int ledIntensity);
// int GetCameraCaptureError(void);
typedef int (WINAPI* GetCameraCaptureError)(void);
GrabSucceededStatus imageCaptureStatus;
CameraCapture captureImage;
GetCameraCaptureError cameraError;
bool dllFuncValid = false;

namespace MDXProtocolEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum StatusGridColIdx
	{
		kSiteNumIdx,
		kStateIdx,
		kSelectedProtocolIdx,
		kSelProtocolBtnIdx,
		kSegmentIdx,
		kCycleIdx,
		kStepIdx,
		kTimeIdx,
		kTemperatureIdx
	};

	enum SeriesId
	{
		kSample,
		kBlock,
		kTopHeater,
		kCurrent,
		kLight,
		kDark,
		kNumSeries
	};

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			OpticsTypeCombo->SelectedIndex = 0;
			this->Text = this->Text + " (" + Application::ProductVersion + ")";
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
	private: System::Windows::Forms::TabControl^  ProtocolTabs;
	private: System::Windows::Forms::TabPage^  AmpDetectPage;
	private: System::Windows::Forms::TabPage^  MixingStationPage;
	private: System::Windows::Forms::TabPage^  SamplePrepPage;
	protected:

	protected:

	protected:



	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  DeleteStep;
	private: System::Windows::Forms::Button^  NewStep;
	private: System::Windows::Forms::Button^  OpenProtocol;

	private: System::Windows::Forms::RichTextBox^  ProtocolName;

	private: System::Windows::Forms::DataGridView^  ProtocolDataGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Cycles;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Steps;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Setpoint;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RampRate;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  OpticalAcq;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Melt;
	private: System::Windows::Forms::Button^  SaveProtocol;
	private: System::Windows::Forms::SaveFileDialog^  saveProtocolDlg;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  DelOptReadBtn;
	private: System::Windows::Forms::Button^  AddOptReadBtn;
	private: System::Windows::Forms::DataGridView^  OpticalReadsGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LEDIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LedIntensity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LedStabilizationTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DetectorIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RefDetectorIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DetectorIntegrationTime;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  OpticsTypeCombo;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Timer^  StatusTimer;
	private: System::Windows::Forms::FolderBrowserDialog^  SelectDataFolderDlg;
	private: System::Windows::Forms::OpenFileDialog^  openProtocolDlg;
	private: System::ComponentModel::IContainer^  components;

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
			this->ProtocolTabs = (gcnew System::Windows::Forms::TabControl());
			this->AmpDetectPage = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->DelOptReadBtn = (gcnew System::Windows::Forms::Button());
			this->AddOptReadBtn = (gcnew System::Windows::Forms::Button());
			this->OpticalReadsGrid = (gcnew System::Windows::Forms::DataGridView());
			this->LEDIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LedIntensity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LedStabilizationTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DetectorIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RefDetectorIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DetectorIntegrationTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->OpticsTypeCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SaveProtocol = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
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
			this->OpenProtocol = (gcnew System::Windows::Forms::Button());
			this->ProtocolName = (gcnew System::Windows::Forms::RichTextBox());
			this->MixingStationPage = (gcnew System::Windows::Forms::TabPage());
			this->SamplePrepPage = (gcnew System::Windows::Forms::TabPage());
			this->saveProtocolDlg = (gcnew System::Windows::Forms::SaveFileDialog());
			this->StatusTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SelectDataFolderDlg = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openProtocolDlg = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ProtocolTabs->SuspendLayout();
			this->AmpDetectPage->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpticalReadsGrid))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProtocolDataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// ProtocolTabs
			// 
			this->ProtocolTabs->Controls->Add(this->SamplePrepPage);
			this->ProtocolTabs->Controls->Add(this->MixingStationPage);
			this->ProtocolTabs->Controls->Add(this->AmpDetectPage);
			this->ProtocolTabs->Location = System::Drawing::Point(13, 13);
			this->ProtocolTabs->Name = L"ProtocolTabs";
			this->ProtocolTabs->SelectedIndex = 0;
			this->ProtocolTabs->Size = System::Drawing::Size(1192, 787);
			this->ProtocolTabs->TabIndex = 0;
			// 
			// AmpDetectPage
			// 
			this->AmpDetectPage->BackColor = System::Drawing::Color::Transparent;
			this->AmpDetectPage->Controls->Add(this->groupBox1);
			this->AmpDetectPage->Controls->Add(this->SaveProtocol);
			this->AmpDetectPage->Controls->Add(this->groupBox2);
			this->AmpDetectPage->Controls->Add(this->OpenProtocol);
			this->AmpDetectPage->Controls->Add(this->ProtocolName);
			this->AmpDetectPage->Location = System::Drawing::Point(4, 25);
			this->AmpDetectPage->Name = L"AmpDetectPage";
			this->AmpDetectPage->Padding = System::Windows::Forms::Padding(3);
			this->AmpDetectPage->Size = System::Drawing::Size(1184, 758);
			this->AmpDetectPage->TabIndex = 0;
			this->AmpDetectPage->Text = L"Amp Detect";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DelOptReadBtn);
			this->groupBox1->Controls->Add(this->AddOptReadBtn);
			this->groupBox1->Controls->Add(this->OpticalReadsGrid);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->OpticsTypeCombo);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Location = System::Drawing::Point(7, 504);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(1157, 262);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Optics";
			// 
			// DelOptReadBtn
			// 
			this->DelOptReadBtn->Location = System::Drawing::Point(51, 151);
			this->DelOptReadBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DelOptReadBtn->Name = L"DelOptReadBtn";
			this->DelOptReadBtn->Size = System::Drawing::Size(160, 28);
			this->DelOptReadBtn->TabIndex = 11;
			this->DelOptReadBtn->Text = L"Delete";
			this->DelOptReadBtn->UseVisualStyleBackColor = true;
			this->DelOptReadBtn->Click += gcnew System::EventHandler(this, &MyForm::DelOptReadBtn_Click);
			// 
			// AddOptReadBtn
			// 
			this->AddOptReadBtn->Location = System::Drawing::Point(51, 103);
			this->AddOptReadBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AddOptReadBtn->Name = L"AddOptReadBtn";
			this->AddOptReadBtn->Size = System::Drawing::Size(160, 28);
			this->AddOptReadBtn->TabIndex = 10;
			this->AddOptReadBtn->Text = L"Add";
			this->AddOptReadBtn->UseVisualStyleBackColor = true;
			this->AddOptReadBtn->Click += gcnew System::EventHandler(this, &MyForm::AddOptReadBtn_Click);
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
			this->OpticalReadsGrid->Location = System::Drawing::Point(233, 54);
			this->OpticalReadsGrid->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->OpticalReadsGrid->Name = L"OpticalReadsGrid";
			this->OpticalReadsGrid->RowTemplate->Height = 24;
			this->OpticalReadsGrid->Size = System::Drawing::Size(757, 186);
			this->OpticalReadsGrid->TabIndex = 3;
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
			this->label7->Location = System::Drawing::Point(229, 34);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 17);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Optical reads:";
			// 
			// OpticsTypeCombo
			// 
			this->OpticsTypeCombo->FormattingEnabled = true;
			this->OpticsTypeCombo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Photodiode", L"Camera" });
			this->OpticsTypeCombo->Location = System::Drawing::Point(12, 54);
			this->OpticsTypeCombo->Margin = System::Windows::Forms::Padding(4);
			this->OpticsTypeCombo->Name = L"OpticsTypeCombo";
			this->OpticsTypeCombo->Size = System::Drawing::Size(197, 24);
			this->OpticsTypeCombo->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 34);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 17);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Type:";
			// 
			// SaveProtocol
			// 
			this->SaveProtocol->Location = System::Drawing::Point(988, 21);
			this->SaveProtocol->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SaveProtocol->Name = L"SaveProtocol";
			this->SaveProtocol->Size = System::Drawing::Size(160, 28);
			this->SaveProtocol->TabIndex = 10;
			this->SaveProtocol->Text = L"Save Protocol";
			this->SaveProtocol->UseVisualStyleBackColor = true;
			this->SaveProtocol->Click += gcnew System::EventHandler(this, &MyForm::SaveProtocol_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox2->Controls->Add(this->ProtocolDataGrid);
			this->groupBox2->Controls->Add(this->DeleteStep);
			this->groupBox2->Controls->Add(this->NewStep);
			this->groupBox2->Location = System::Drawing::Point(7, 89);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(1164, 430);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Thermal Profile";
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
			this->ProtocolDataGrid->Location = System::Drawing::Point(21, 88);
			this->ProtocolDataGrid->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ProtocolDataGrid->Name = L"ProtocolDataGrid";
			this->ProtocolDataGrid->RowTemplate->Height = 24;
			this->ProtocolDataGrid->Size = System::Drawing::Size(1136, 321);
			this->ProtocolDataGrid->TabIndex = 9;
			// 
			// Cycles
			// 
			this->Cycles->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Cycles->HeaderText = L"Cycles";
			this->Cycles->Name = L"Cycles";
			this->Cycles->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Cycles->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Cycles->Width = 55;
			// 
			// Steps
			// 
			this->Steps->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Steps->HeaderText = L"Step";
			this->Steps->Name = L"Steps";
			this->Steps->ReadOnly = true;
			this->Steps->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Steps->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Steps->Width = 43;
			// 
			// Setpoint
			// 
			this->Setpoint->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Setpoint->HeaderText = L"Setpoint (C)";
			this->Setpoint->Name = L"Setpoint";
			this->Setpoint->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Setpoint->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Setpoint->Width = 89;
			// 
			// Time
			// 
			this->Time->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Time->HeaderText = L"Time (s)";
			this->Time->Name = L"Time";
			this->Time->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Time->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Time->Width = 66;
			// 
			// RampRate
			// 
			this->RampRate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->RampRate->HeaderText = L"Ramp (C/s)";
			this->RampRate->Name = L"RampRate";
			this->RampRate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->RampRate->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->RampRate->Width = 85;
			// 
			// OpticalAcq
			// 
			this->OpticalAcq->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->OpticalAcq->HeaderText = L"Optical Read";
			this->OpticalAcq->Name = L"OpticalAcq";
			this->OpticalAcq->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->OpticalAcq->Width = 96;
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
			this->DeleteStep->Location = System::Drawing::Point(187, 42);
			this->DeleteStep->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DeleteStep->Name = L"DeleteStep";
			this->DeleteStep->Size = System::Drawing::Size(160, 28);
			this->DeleteStep->TabIndex = 8;
			this->DeleteStep->Text = L"Delete Step";
			this->DeleteStep->UseVisualStyleBackColor = true;
			this->DeleteStep->Click += gcnew System::EventHandler(this, &MyForm::DeleteStep_Click);
			// 
			// NewStep
			// 
			this->NewStep->Location = System::Drawing::Point(21, 42);
			this->NewStep->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->NewStep->Name = L"NewStep";
			this->NewStep->Size = System::Drawing::Size(160, 28);
			this->NewStep->TabIndex = 7;
			this->NewStep->Text = L"New Step";
			this->NewStep->UseVisualStyleBackColor = true;
			this->NewStep->Click += gcnew System::EventHandler(this, &MyForm::NewStep_Click);
			// 
			// OpenProtocol
			// 
			this->OpenProtocol->Location = System::Drawing::Point(300, 20);
			this->OpenProtocol->Name = L"OpenProtocol";
			this->OpenProtocol->Size = System::Drawing::Size(56, 31);
			this->OpenProtocol->TabIndex = 1;
			this->OpenProtocol->Text = L"...";
			this->OpenProtocol->UseVisualStyleBackColor = true;
			this->OpenProtocol->Click += gcnew System::EventHandler(this, &MyForm::OpenProtocol_Click);
			// 
			// ProtocolName
			// 
			this->ProtocolName->Location = System::Drawing::Point(6, 20);
			this->ProtocolName->Name = L"ProtocolName";
			this->ProtocolName->Size = System::Drawing::Size(278, 32);
			this->ProtocolName->TabIndex = 0;
			this->ProtocolName->Text = L"";
			// 
			// MixingStationPage
			// 
			this->MixingStationPage->Location = System::Drawing::Point(4, 25);
			this->MixingStationPage->Name = L"MixingStationPage";
			this->MixingStationPage->Padding = System::Windows::Forms::Padding(3);
			this->MixingStationPage->Size = System::Drawing::Size(1184, 758);
			this->MixingStationPage->TabIndex = 1;
			this->MixingStationPage->Text = L"Mixing Station";
			this->MixingStationPage->UseVisualStyleBackColor = true;
			// 
			// SamplePrepPage
			// 
			this->SamplePrepPage->Location = System::Drawing::Point(4, 25);
			this->SamplePrepPage->Name = L"SamplePrepPage";
			this->SamplePrepPage->Size = System::Drawing::Size(1184, 758);
			this->SamplePrepPage->TabIndex = 2;
			this->SamplePrepPage->Text = L"Sample Prep";
			this->SamplePrepPage->UseVisualStyleBackColor = true;
			// 
			// StatusTimer
			// 
			this->StatusTimer->Enabled = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1205, 798);
			this->Controls->Add(this->ProtocolTabs);
			this->Name = L"MyForm";
			this->Text = L"MDX Protocol Editor";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ProtocolTabs->ResumeLayout(false);
			this->AmpDetectPage->ResumeLayout(false);
			this->AmpDetectPage->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OpticalReadsGrid))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProtocolDataGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void SaveProtocol_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveProtocolDlg->FileName = ProtocolName->Text;
		saveProtocolDlg->AddExtension = true;
		saveProtocolDlg->OverwritePrompt = true;
		saveProtocolDlg->Filter = "pcr protocols (*.qpcr)|*.qpcr|All files (*.*)|*.*";

		PcrProtocol	pcrProtocol;
		ReadPcrProtocolFromGui(&pcrProtocol);
		if (saveProtocolDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			ProtocolName->Text = saveProtocolDlg->FileName;
			System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter(ProtocolName->Text);
			System::IO::BinaryWriter^ binFile = gcnew System::IO::BinaryWriter(file->BaseStream);

			uint8_t arTemp[5 * 1024];
			pcrProtocol >> arTemp;
			array<uint8_t>^ protocolBuf = gcnew array<uint8_t>(pcrProtocol.GetStreamSize());
			for (int i = 0; i < (int)pcrProtocol.GetStreamSize(); i++)
				protocolBuf[i] = arTemp[i];

			binFile->BaseStream->SetLength(0);
			binFile->Write(protocolBuf);
			binFile->Close();
		}
		WritePcrProtocolToGui(pcrProtocol);
	}

	private: System::Void WritePcrProtocolToGui(PcrProtocol& pcrProtocol)
	{
		ProtocolDataGrid->Rows->Clear();
		OpticalReadsGrid->Rows->Clear();

		//Iterate through all optical reads in this protocol.
		OpticsTypeCombo->SelectedIndex = pcrProtocol.GetFluorDetectorType();
		for (int i = 0; i < (int)pcrProtocol.GetNumOpticalReads(); i++)
		{
			DataGridViewRow^ row = gcnew DataGridViewRow;
			OpticalReadsGrid->Rows->Add(row);
			int nRowIdx = OpticalReadsGrid->RowCount - 1;
			OpticalRead optRead = pcrProtocol.GetOpticalRead(i);

			OpticalReadsGrid[0, nRowIdx]->Value = optRead.GetLedIdx();
			OpticalReadsGrid[1, nRowIdx]->Value = optRead.GetLedIntensity();
			OpticalReadsGrid[2, nRowIdx]->Value = optRead.GetLedStablizationTime();
			OpticalReadsGrid[3, nRowIdx]->Value = optRead.GetDetectorIdx();
			OpticalReadsGrid[4, nRowIdx]->Value = optRead.GetReferenceIdx();
			OpticalReadsGrid[5, nRowIdx]->Value = optRead.GetDetectorIntegrationTime();
		}

		//Iterate through all segments in this protocol.
		for (int nSegIdx = 0; nSegIdx < (int)pcrProtocol.GetNumSegs(); nSegIdx++)
		{
			Segment seg = pcrProtocol.GetSegment(nSegIdx);

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

	private: System::Void ReadPcrProtocolFromGui(PcrProtocol* pPcrProtocol)
	{
		pPcrProtocol->Clear();

		OpticalRead optRead;
		pPcrProtocol->SetFluorDetectorType((FluorDetectorType)OpticsTypeCombo->SelectedIndex);
		for (int nRowIdx = 0; nRowIdx < OpticalReadsGrid->Rows->Count; nRowIdx++)
		{
			optRead.SetLedIdx(Convert::ToInt32(OpticalReadsGrid[0, nRowIdx]->Value));
			optRead.SetLedIntensity(Convert::ToInt32(OpticalReadsGrid[1, nRowIdx]->Value));
			optRead.SetLedStablizationTime(Convert::ToInt32(OpticalReadsGrid[2, nRowIdx]->Value));
			optRead.SetDetectorIdx(Convert::ToInt32(OpticalReadsGrid[3, nRowIdx]->Value));
			optRead.SetReferenceIdx(Convert::ToInt32(OpticalReadsGrid[4, nRowIdx]->Value));
			optRead.SetDetectorIntegrationTime(Convert::ToInt32(OpticalReadsGrid[5, nRowIdx]->Value));
			pPcrProtocol->AddOpticalRead(optRead);
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
				pPcrProtocol->AddSegment(seg);
		}
	}

	private: System::Void OpenProtocol_Click(System::Object^  sender, System::EventArgs^  e) 
	{
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

			PcrProtocol pcrProtocol;
			pcrProtocol << arTemp;
			WritePcrProtocolToGui(pcrProtocol);
			binFile->Close();
		}
	}

	private: System::Void DeleteStep_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int nRowIdx = ProtocolDataGrid->Rows->Count - 1; nRowIdx >= 0; nRowIdx--)
		{
			if (ProtocolDataGrid->Rows[nRowIdx]->Selected)
				ProtocolDataGrid->Rows->RemoveAt(nRowIdx);
		}
	}

	private: System::Void NewStep_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DataGridViewRow^ row = gcnew DataGridViewRow;
		ProtocolDataGrid->Rows->Add(row);
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
