#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
enum ErrCode : uint32_t
{
	kNoError = 0,
	kDeviceCommErr,
	kRunInProgressErr,
	kInvalidCmdParamsErr,
	kWriteToFlashErr,
	kNodeNotConnectedErr,
	kFileNotFound
};

