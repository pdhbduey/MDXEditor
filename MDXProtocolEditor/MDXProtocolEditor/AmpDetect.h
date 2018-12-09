#ifndef  __AmpDetect_H
#define  __AmpDetect_H

#include <cstdint>
#include <vector>
#include "MdxProtocolBase.h"
#include "StreamingObj.h"
#include "OpticalRead.h"
#include "Segment.h"
#include "Common.h"

class AmpDetect : public StreamingObj, public MdxProtocolBase
{
public:
	AmpDetect()
		:StreamingObj(MakeObjId('P', 'r', 'o', 't'))
		, _nFluorDetectorType(FluorDetectorType::kPhotoDiode)
	{
	}

	virtual ~AmpDetect()
	{
	}

	void				SetFluorDetectorType(FluorDetectorType n) { _nFluorDetectorType = n; }
	FluorDetectorType   GetFluorDetectorType() const { return _nFluorDetectorType; }

	uint32_t			GetNumOpticalReads() const { return (uint32_t)_vOpticalReads.size(); }
	const OpticalRead&	GetOpticalRead(uint32_t idx) const { return _vOpticalReads[idx]; }
	void				ClearOpticalReads() { _vOpticalReads.clear(); }

	void AddOpticalRead(const OpticalRead& chn)
	{
		_vOpticalReads.push_back(chn);
	}

	uint32_t			GetNumSegs() const { return (uint32_t)_vSegments.size(); }
	const Segment&		GetSegment(uint32_t idx) const { return _vSegments[idx]; }
	void				ClearSegments() { _vSegments.clear(); }

	void AddSegment(const Segment& seg)
	{
		_vSegments.push_back(seg);
	}

	void Clear()
	{
		ClearOpticalReads();
		ClearSegments();
	}

	virtual uint32_t        GetStreamSize() const
	{
		uint32_t nSize = StreamingObj::GetStreamSize();
		nSize += sizeof(_nFluorDetectorType);

		nSize += sizeof(uint32_t); //Number of optics channels.
		for (int i = 0; i < (int)_vOpticalReads.size(); i++)
			nSize += _vOpticalReads[i].GetStreamSize();

		nSize += sizeof(uint32_t); //Number of segments.
		for (int i = 0; i < (int)_vSegments.size(); i++)
			nSize += _vSegments[i].GetStreamSize();

		return nSize;
	}

	virtual void    operator<<(const uint8_t* pData)
	{
		StreamingObj::operator<<(pData);
		uint32_t*   pSrc = (uint32_t*)(&pData[StreamingObj::GetStreamSize()]);

		_nFluorDetectorType = (FluorDetectorType)(swap_uint32(*pSrc++));
		_vOpticalReads.clear();
		int nNumOpticalReads = swap_uint32(*pSrc++);
		_vOpticalReads.resize(nNumOpticalReads);
		for (int nIdx = 0; nIdx < nNumOpticalReads; nIdx++)
		{
			_vOpticalReads[nIdx] << (uint8_t*)pSrc;
			pSrc += _vOpticalReads[nIdx].GetStreamSize() / sizeof(uint32_t);
		}

		_vSegments.clear();
		int nNumSegs = swap_uint32(*pSrc++);
		_vSegments.resize(nNumSegs);
		for (int nSegIdx = 0; nSegIdx < nNumSegs; nSegIdx++)
		{
			_vSegments[nSegIdx] << (uint8_t*)pSrc;
			pSrc += _vSegments[nSegIdx].GetStreamSize() / sizeof(uint32_t);
		}
	}

	virtual void    operator>>(uint8_t* pData)
	{
		StreamingObj::operator>>(pData);
		uint32_t*   pDst = (uint32_t*)(&pData[StreamingObj::GetStreamSize()]);

		*pDst++ = swap_uint32(_nFluorDetectorType);
		*pDst++ = swap_uint32((uint32_t)_vOpticalReads.size());
		for (int i = 0; i < (int)_vOpticalReads.size(); i++)
		{
			_vOpticalReads[i] >> (uint8_t*)pDst;
			pDst += _vOpticalReads[i].GetStreamSize() / sizeof(uint32_t);
		}

		*pDst++ = swap_uint32((uint32_t)_vSegments.size());
		for (int i = 0; i < (int)_vSegments.size(); i++)
		{
			_vSegments[i] >> (uint8_t*)pDst;
			pDst += _vSegments[i].GetStreamSize() / sizeof(uint32_t);
		}
	}

	AmpDetect& operator=(const AmpDetect& rhs)
	{
		_nFluorDetectorType = rhs._nFluorDetectorType;
		_vOpticalReads.clear();
		_vOpticalReads.resize(rhs.GetNumOpticalReads());
		for (int nIdx = 0; nIdx < (int)rhs.GetNumOpticalReads(); nIdx++)
			_vOpticalReads[nIdx] = rhs.GetOpticalRead(nIdx);

		_vSegments.clear();
		_vSegments.resize(rhs.GetNumSegs());
		for (int nSegIdx = 0; nSegIdx < (int)rhs.GetNumSegs(); nSegIdx++)
			_vSegments[nSegIdx] = rhs.GetSegment(nSegIdx);

		return *this;
	}

protected:

private:
	FluorDetectorType			_nFluorDetectorType;
	std::vector<OpticalRead>	_vOpticalReads;
	std::vector<Segment>		_vSegments;
};

#endif // __AmpDetect_H