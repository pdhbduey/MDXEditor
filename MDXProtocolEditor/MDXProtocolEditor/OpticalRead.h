#ifndef  __OpticalRead_H
#define  __OpticalRead_H

#include <cstdint>
#include <vector>
#include "StreamingObj.h"
#include "Common.h"

class OpticalRead : public StreamingObj
{
public:
	OpticalRead()
		: StreamingObj(MakeObjId('O', 'p', 'C', 'h'))
		, _nLedIdx(0)
		, _nLedIntensity(0)
		, _nLedStablizationTime_us(0)
		, _nDetectorIdx(0)
		, _nDetectorIntegrationTime_us(0)
		, _nReferenceIdx(0)
	{
	}

	virtual ~OpticalRead()
	{
	}

	void        SetLedIdx(uint32_t idx) { _nLedIdx = idx; }
	uint32_t    GetLedIdx() const { return _nLedIdx; }
	void        SetLedIntensity(uint32_t nIntensity) { _nLedIntensity = nIntensity; }
	uint32_t    GetLedIntensity() const { return _nLedIntensity; }
	void        SetLedStablizationTime(uint32_t nTime_us) { _nLedStablizationTime_us = nTime_us; }
	uint32_t    GetLedStablizationTime() const { return _nLedStablizationTime_us; }
	void        SetDetectorIdx(uint32_t idx) { _nDetectorIdx = idx; }
	uint32_t    GetDetectorIdx() const { return _nDetectorIdx; }
	void        SetDetectorIntegrationTime(uint32_t nTime_us) { _nDetectorIntegrationTime_us = nTime_us; }
	uint32_t    GetDetectorIntegrationTime() const { return _nDetectorIntegrationTime_us; }
	void        SetReferenceIdx(uint32_t idx) { _nReferenceIdx = idx; }
	uint32_t    GetReferenceIdx() const { return _nReferenceIdx; }


	virtual uint32_t GetStreamSize() const
	{
		uint32_t nSize = StreamingObj::GetStreamSize();
		nSize += sizeof(_nLedIdx);
		nSize += sizeof(_nLedIntensity);
		nSize += sizeof(_nLedStablizationTime_us);
		nSize += sizeof(_nDetectorIdx);
		nSize += sizeof(_nDetectorIntegrationTime_us);
		nSize += sizeof(_nReferenceIdx);
		return nSize;
	}

	virtual void    operator<<(const uint8_t* pData)
	{
		StreamingObj::operator<<(pData);
		uint32_t*   pSrc = (uint32_t*)(&pData[StreamingObj::GetStreamSize()]);
		_nLedIdx = swap_uint32(*pSrc++);
		_nLedIntensity = swap_uint32(*pSrc++);
		_nLedStablizationTime_us = swap_uint32(*pSrc++);
		_nDetectorIdx = swap_uint32(*pSrc++);
		_nDetectorIntegrationTime_us = swap_uint32(*pSrc++);
		_nReferenceIdx = swap_uint32(*pSrc++);
	}

	virtual void    operator>>(uint8_t* pData)
	{
		StreamingObj::operator>>(pData);
		uint32_t*   pDst = (uint32_t*)(&pData[StreamingObj::GetStreamSize()]);
		*pDst++ = swap_uint32(_nLedIdx);
		*pDst++ = swap_uint32(_nLedIntensity);
		*pDst++ = swap_uint32(_nLedStablizationTime_us);
		*pDst++ = swap_uint32(_nDetectorIdx);
		*pDst++ = swap_uint32(_nDetectorIntegrationTime_us);
		*pDst++ = swap_uint32(_nReferenceIdx);
	}

protected:

private:
	uint32_t	_nLedIdx;
	uint32_t	_nLedIntensity;
	uint32_t	_nLedStablizationTime_us;
	uint32_t	_nDetectorIdx;
	uint32_t	_nDetectorIntegrationTime_us;
	uint32_t    _nReferenceIdx;
};

#endif // __OpticalRead_H