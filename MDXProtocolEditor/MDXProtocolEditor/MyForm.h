#pragma once

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <msclr\marshal.h>

#include "PcrProtocol.h"
#include "MdxProtocol.h"

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


	class AmpDetectPage;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->Text = this->Text + " (" + Application::ProductVersion + ")";
			this->ampDetectPage1->PassMdxProtocolObject(new MdxProtocol());
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






	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  fileMenuDropdown;
	private: System::Windows::Forms::ToolStripMenuItem^  openProtocolDropdown;
	private: System::Windows::Forms::ToolStripMenuItem^  saveProtocolDropdown;
	private: System::Windows::Forms::ToolStripMenuItem^  closeDropdown;






	private: UserControls::AmpDetectPage^  ampDetectPage1;



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
			this->ProtocolTabs = (gcnew System::Windows::Forms::TabControl());
			this->SamplePrepPage = (gcnew System::Windows::Forms::TabPage());
			this->MixingStationPage = (gcnew System::Windows::Forms::TabPage());
			this->AmpDetectPage = (gcnew System::Windows::Forms::TabPage());
			this->ampDetectPage1 = (gcnew UserControls::AmpDetectPage());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileMenuDropdown = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openProtocolDropdown = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveProtocolDropdown = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeDropdown = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProtocolTabs->SuspendLayout();
			this->AmpDetectPage->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// ProtocolTabs
			// 
			this->ProtocolTabs->Controls->Add(this->SamplePrepPage);
			this->ProtocolTabs->Controls->Add(this->MixingStationPage);
			this->ProtocolTabs->Controls->Add(this->AmpDetectPage);
			this->ProtocolTabs->Location = System::Drawing::Point(9, 39);
			this->ProtocolTabs->Margin = System::Windows::Forms::Padding(2);
			this->ProtocolTabs->Name = L"ProtocolTabs";
			this->ProtocolTabs->SelectedIndex = 0;
			this->ProtocolTabs->Size = System::Drawing::Size(894, 639);
			this->ProtocolTabs->TabIndex = 0;
			this->ProtocolTabs->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ProtocolTabs_TabIndexChanged);
			this->ProtocolTabs->TabIndexChanged += gcnew System::EventHandler(this, &MyForm::ProtocolTabs_TabIndexChanged);
			// 
			// SamplePrepPage
			// 
			this->SamplePrepPage->Location = System::Drawing::Point(4, 22);
			this->SamplePrepPage->Margin = System::Windows::Forms::Padding(2);
			this->SamplePrepPage->Name = L"SamplePrepPage";
			this->SamplePrepPage->Size = System::Drawing::Size(886, 613);
			this->SamplePrepPage->TabIndex = 2;
			this->SamplePrepPage->Text = L"Sample Prep";
			this->SamplePrepPage->UseVisualStyleBackColor = true;
			// 
			// MixingStationPage
			// 
			this->MixingStationPage->Location = System::Drawing::Point(4, 22);
			this->MixingStationPage->Margin = System::Windows::Forms::Padding(2);
			this->MixingStationPage->Name = L"MixingStationPage";
			this->MixingStationPage->Padding = System::Windows::Forms::Padding(2);
			this->MixingStationPage->Size = System::Drawing::Size(886, 613);
			this->MixingStationPage->TabIndex = 1;
			this->MixingStationPage->Text = L"Mixing Station";
			this->MixingStationPage->UseVisualStyleBackColor = true;
			// 
			// AmpDetectPage
			// 
			this->AmpDetectPage->BackColor = System::Drawing::Color::Transparent;
			this->AmpDetectPage->Controls->Add(this->ampDetectPage1);
			this->AmpDetectPage->Location = System::Drawing::Point(4, 22);
			this->AmpDetectPage->Margin = System::Windows::Forms::Padding(2);
			this->AmpDetectPage->Name = L"AmpDetectPage";
			this->AmpDetectPage->Padding = System::Windows::Forms::Padding(2);
			this->AmpDetectPage->Size = System::Drawing::Size(886, 613);
			this->AmpDetectPage->TabIndex = 0;
			this->AmpDetectPage->Text = L"Amp Detect";
			// 
			// ampDetectPage1
			// 
			this->ampDetectPage1->Location = System::Drawing::Point(4, 4);
			this->ampDetectPage1->Name = L"ampDetectPage1";
			this->ampDetectPage1->Size = System::Drawing::Size(901, 666);
			this->ampDetectPage1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Location = System::Drawing::Point(0, 24);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(904, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileMenuDropdown });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip2->Size = System::Drawing::Size(904, 24);
			this->menuStrip2->TabIndex = 2;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// fileMenuDropdown
			// 
			this->fileMenuDropdown->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openProtocolDropdown,
					this->saveProtocolDropdown, this->closeDropdown
			});
			this->fileMenuDropdown->Name = L"fileMenuDropdown";
			this->fileMenuDropdown->Size = System::Drawing::Size(37, 20);
			this->fileMenuDropdown->Text = L"File";
			// 
			// openProtocolDropdown
			// 
			this->openProtocolDropdown->Enabled = false;
			this->openProtocolDropdown->Name = L"openProtocolDropdown";
			this->openProtocolDropdown->Size = System::Drawing::Size(114, 22);
			this->openProtocolDropdown->Text = L"Open ";
			// 
			// saveProtocolDropdown
			// 
			this->saveProtocolDropdown->Enabled = false;
			this->saveProtocolDropdown->Name = L"saveProtocolDropdown";
			this->saveProtocolDropdown->Size = System::Drawing::Size(114, 22);
			this->saveProtocolDropdown->Text = L"Save As";
			// 
			// closeDropdown
			// 
			this->closeDropdown->Name = L"closeDropdown";
			this->closeDropdown->Size = System::Drawing::Size(114, 22);
			this->closeDropdown->Text = L"Close";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(904, 648);
			this->Controls->Add(this->ProtocolTabs);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MDX Protocol Editor";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ProtocolTabs->ResumeLayout(false);
			this->AmpDetectPage->ResumeLayout(false);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	//private: System::Void SaveProtocol_Click(System::Object^  sender, System::EventArgs^  e)
	//{
	//	//saveProtocolDlg->FileName = AmpDetectPage->ProtocolName->Text;
	//	saveProtocolDlg->AddExtension = true;
	//	saveProtocolDlg->OverwritePrompt = true;
	//	saveProtocolDlg->Filter = "pcr protocols (*.qpcr)|*.qpcr|All files (*.*)|*.*";

	//	PcrProtocol ampDetect;
	//	ReadAmpDetectFromGui(&ampDetect);
	//	if (saveProtocolDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	//	{
	//		//ProtocolName->Text = saveProtocolDlg->FileName;
	//		System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter(ProtocolName->Text);
	//		System::IO::BinaryWriter^ binFile = gcnew System::IO::BinaryWriter(file->BaseStream);

	//		uint8_t arTemp[5 * 1024];
	//		ampDetect >> arTemp;
	//		array<uint8_t>^ protocolBuf = gcnew array<uint8_t>(ampDetect.GetStreamSize());
	//		for (int i = 0; i < (int)ampDetect.GetStreamSize(); i++)
	//			protocolBuf[i] = arTemp[i];

	//		binFile->BaseStream->SetLength(0);
	//		binFile->Write(protocolBuf);
	//		binFile->Close();
	//	}
	//	WriteAmpDetectToGui(ampDetect);
	//}

	//private: System::Void WriteAmpDetectToGui(PcrProtocol& ampDetect)
	//{
	//	AmpDetectPage->ProtocolDataGrid->Rows->Clear();
	//	AmpDetectPage->OpticalReadsGrid->Rows->Clear();

	//	//Iterate through all optical reads in this protocol.
	//	for (int i = 0; i < (int)ampDetect.GetNumOpticalReads(); i++)
	//	{
	//		DataGridViewRow^ row = gcnew DataGridViewRow;
	//		OpticalReadsGrid->Rows->Add(row);
	//		int nRowIdx = OpticalReadsGrid->RowCount - 1;
	//		OpticalRead optRead = ampDetect.GetOpticalRead(i);

	//		OpticalReadsGrid[0, nRowIdx]->Value = optRead.GetLedIdx();
	//		OpticalReadsGrid[1, nRowIdx]->Value = optRead.GetLedIntensity();
	//		OpticalReadsGrid[2, nRowIdx]->Value = optRead.GetLedStablizationTime();
	//		OpticalReadsGrid[3, nRowIdx]->Value = optRead.GetDetectorIdx();
	//		OpticalReadsGrid[4, nRowIdx]->Value = optRead.GetReferenceIdx();
	//		OpticalReadsGrid[5, nRowIdx]->Value = optRead.GetDetectorIntegrationTime();
	//	}

	//	//Iterate through all segments in this protocol.
	//	for (int nSegIdx = 0; nSegIdx < (int)ampDetect.GetNumSegs(); nSegIdx++)
	//	{
	//		Segment seg = ampDetect.GetSegment(nSegIdx);

	//		//Iterate through all steps in this segment.
	//		for (int nStepIdx = 0; nStepIdx < (int)seg.GetNumSteps(); nStepIdx++)
	//		{
	//			DataGridViewRow^ row = gcnew DataGridViewRow;
	//			ProtocolDataGrid->Rows->Add(row);
	//			int nRowIdx = ProtocolDataGrid->RowCount - 1;
	//			Step step = seg.GetStep(nStepIdx);

	//			//If this is the first step in the segment, report number of cycles.
	//			if (nStepIdx == 0)
	//				ProtocolDataGrid[0, nRowIdx]->Value = Convert::ToString(seg.GetNumCycles());

	//			ProtocolDataGrid[1, nRowIdx]->Value = Convert::ToString(nStepIdx + 1);
	//			ProtocolDataGrid[2, nRowIdx]->Value = Convert::ToString((double)step.GetTargetTemp() / 1000);
	//			ProtocolDataGrid[3, nRowIdx]->Value = Convert::ToString((double)step.GetHoldTimer() / 1000);
	//			ProtocolDataGrid[4, nRowIdx]->Value = Convert::ToString((double)step.GetRampRate() / 1000);

	//			//Optical acquisition.
	//			ProtocolDataGrid[5, nRowIdx]->Value = step.GetOpticalAcqFlg();

	//			//Melt
	//			ProtocolDataGrid[6, nRowIdx]->Value = step.GetMeltFlg();
	//		}
	//	}
	//}

	//private: System::Void ReadAmpDetectFromGui(PcrProtocol* pAmpDetect)
	//{
	//	pAmpDetect->Clear();

	//	OpticalRead optRead;
	//	pAmpDetect->SetFluorDetectorType(kPhotoDiode);
	//	for (int nRowIdx = 0; nRowIdx < OpticalReadsGrid->Rows->Count; nRowIdx++)
	//	{
	//		optRead.SetLedIdx(Convert::ToInt32(OpticalReadsGrid[0, nRowIdx]->Value));
	//		optRead.SetLedIntensity(Convert::ToInt32(OpticalReadsGrid[1, nRowIdx]->Value));
	//		optRead.SetLedStablizationTime(Convert::ToInt32(OpticalReadsGrid[2, nRowIdx]->Value));
	//		optRead.SetDetectorIdx(Convert::ToInt32(OpticalReadsGrid[3, nRowIdx]->Value));
	//		optRead.SetReferenceIdx(Convert::ToInt32(OpticalReadsGrid[4, nRowIdx]->Value));
	//		optRead.SetDetectorIntegrationTime(Convert::ToInt32(OpticalReadsGrid[5, nRowIdx]->Value));
	//		pAmpDetect->AddOpticalRead(optRead);
	//	}

	//	Segment seg;
	//	for (int nRowIdx = 0; nRowIdx < ProtocolDataGrid->Rows->Count; nRowIdx++)
	//	{
	//		int nNumCycles = Convert::ToInt32(ProtocolDataGrid[0, nRowIdx]->Value);
	//		if ((nRowIdx == 0) && (!(nNumCycles > 0)))
	//			nNumCycles = 1;

	//		if (nNumCycles != 0)
	//		{
	//			seg.Clear();
	//			seg.SetNumCycles(nNumCycles);
	//		}

	//		Step step;
	//		step.SetTargetTemp((int32_t)(Convert::ToDouble(ProtocolDataGrid[2, nRowIdx]->Value) * 1000));
	//		step.SetHoldTimer((uint32_t)(Convert::ToDouble(ProtocolDataGrid[3, nRowIdx]->Value) * 1000));
	//		step.SetRampRate((int32_t)(Convert::ToDouble(ProtocolDataGrid[4, nRowIdx]->Value) * 1000));
	//		step.SetOpticalAcqFlg(Convert::ToBoolean(((DataGridViewCheckBoxCell^)ProtocolDataGrid[5, nRowIdx])->Value) == true);
	//		step.SetMeltFlg(Convert::ToBoolean(((DataGridViewCheckBoxCell^)ProtocolDataGrid[6, nRowIdx])->Value) == true);
	//		seg.AddStep(step);

	//		if ((nRowIdx >= ProtocolDataGrid->Rows->Count - 1) || (Convert::ToInt32(ProtocolDataGrid[0, nRowIdx + 1]->Value) > 0))
	//			pAmpDetect->AddSegment(seg);
	//	}
	//}

	//private: System::Void OpenProtocol_Click(System::Object^  sender, System::EventArgs^  e) 
	//{
	//	
	//}

	// Handle menu items being enabled and disabled based on tab
	private: System::Void ProtocolTabs_TabIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (ProtocolTabs->SelectedTab->Name == "AmpDetectPage")
		{
			openProtocolDropdown->Enabled = true;
			saveProtocolDropdown->Enabled = true;
			closeDropdown->Enabled = true;
		}
		else 
		{
			openProtocolDropdown->Enabled = false;
			saveProtocolDropdown->Enabled = false;
			closeDropdown->Enabled = false;
		}
	}

	
};
}
