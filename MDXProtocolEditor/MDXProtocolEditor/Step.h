#ifndef  __Step_H
#define  __Step_H

#include <cstdint>
#include <vector>
#include "StreamingObj.h"

class Step : public StreamingObj
{
public:
	Step()
		:StreamingObj(MakeObjId('S', 't', 'e', 'p'))
		, _nTargetTemp_mC(0)
		, _nHoldTimer_ms(0)
		, _bOpticalAcquisition(0)
		, _bMelt(0)
		, _nRampRate_mCPerSec(0)
	{
	}

	void        SetTargetTemp(int32_t nTargetTemp_mC) { _nTargetTemp_mC = nTargetTemp_mC; }
	int32_t     GetTargetTemp() const { return _nTargetTemp_mC; }
	void        SetHoldTimer(uint32_t nHoldTime_ms) { _nHoldTimer_ms = nHoldTime_ms; }
	uint32_t    GetHoldTimer() const { return _nHoldTimer_ms; }
	void        SetOpticalAcqFlg(bool b) { _bOpticalAcquisition = b ? 1 : 0; }
	bool        GetOpticalAcqFlg() const { return _bOpticalAcquisition != 0; }
	void        SetMeltFlg(bool b) { _bMelt = b ? 1 : 0; }
	bool        GetMeltFlg() const { return _bMelt != 0; }
	void        SetRampRate(int32_t nRampRate_mCPerSec) { _nRampRate_mCPerSec = nRampRate_mCPerSec; }
	int32_t     GetRampRate() const { return _nRampRate_mCPerSec; }

	void        SetTargetTemp(int32_t nTargetTemp_mC, uint32_t nHoldTime_ms,
		bool bOpticalAcq = false, bool bMelt = false, int32_t nRampRate_mCPerSec = 0)
	{
		_nTargetTemp_mC = nTargetTemp_mC;
		_nHoldTimer_ms = nHoldTime_ms;
		_bOpticalAcquisition = bOpticalAcq != 0;
		_bMelt = bMelt != 0;
		_nRampRate_mCPerSec = nRampRate_mCPerSec;
	}

	virtual uint32_t GetStreamSize() const
	{
		uint32_t nSize = StreamingObj::GetStreamSize();
		nSize += sizeof(_nTargetTemp_mC);
		nSize += sizeof(_nHoldTimer_ms);
		nSize += sizeof(_bOpticalAcquisition);
		nSize += sizeof(_bMelt);
		nSize += sizeof(_nRampRate_mCPerSec);
		return nSize;
	}

	virtual void    operator<<(const uint8_t* pData)
	{
		StreamingObj::operator<<(pData);
		uint32_t*   pSrc = (uint32_t*)(pData + StreamingObj::GetStreamSize());
		_nTargetTemp_mC = swap_uint32(*pSrc++);
		_nHoldTimer_ms = swap_uint32(*pSrc++);
		_bOpticalAcquisition = swap_uint32(*pSrc++);
		_bMelt = swap_uint32(*pSrc++);
		_nRampRate_mCPerSec = swap_uint32(*pSrc++);
	}

	virtual void    operator>>(uint8_t* pData)
	{
		StreamingObj::operator>>(pData);
		uint32_t*   pDst = (uint32_t*)(&pData[StreamingObj::GetStreamSize()]);
		*pDst++ = swap_uint32(_nTargetTemp_mC);
		*pDst++ = swap_uint32(_nHoldTimer_ms);
		*pDst++ = swap_uint32(_bOpticalAcquisition);
		*pDst++ = swap_uint32(_bMelt);
		*pDst++ = swap_uint32(_nRampRate_mCPerSec);
	}

protected:

private:
	int32_t     _nTargetTemp_mC;
	uint32_t    _nHoldTimer_ms;
	uint32_t    _bOpticalAcquisition;
	uint32_t    _bMelt;
	int32_t     _nRampRate_mCPerSec;
};

#endif // __Step_H