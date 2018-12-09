#ifndef  __Segment_H
#define  __Segment_H

#include <cstdint>
#include <vector>
#include "StreamingObj.h"
#include "Step.h"

class Segment : public StreamingObj
{
public:
	Segment()
		:StreamingObj(MakeObjId('S', 'e', 'g', ' '))
		, _nNumCycles(0)
	{
	}

	virtual ~Segment()
	{
		Clear();
	}

	void        SetNumCycles(uint32_t nNumCycs) { _nNumCycles = nNumCycs; }
	uint32_t    GetNumCycles() const { return _nNumCycles; }
	uint32_t    GetNumSteps() const { return (uint32_t)_vSteps.size(); }
	const Step& GetStep(uint32_t stpIdx) const { return _vSteps[stpIdx]; }
	void        Clear() { _vSteps.clear(); }

	void AddStep(const Step& step)
	{
		_vSteps.push_back(step);
	}

	virtual uint32_t GetStreamSize() const
	{
		uint32_t nSize = StreamingObj::GetStreamSize();
		nSize += sizeof(_nNumCycles);
		nSize += sizeof(uint32_t);	//Number of steps.
		for (int i = 0; i < (int)_vSteps.size(); i++)
			nSize += _vSteps[i].GetStreamSize();

		return nSize;
	}

	virtual void    operator<<(const uint8_t* pData)
	{
		StreamingObj::operator<<(pData);
		uint32_t*   pSrc = (uint32_t*)(&pData[StreamingObj::GetStreamSize()]);
		_nNumCycles = swap_uint32(*pSrc++);

		_vSteps.clear();
		int nNumSteps = swap_uint32(*pSrc++);
		_vSteps.resize(nNumSteps);
		for (int i = 0; i < nNumSteps; i++)
		{
			_vSteps[i] << (uint8_t*)pSrc;
			pSrc += _vSteps[i].GetStreamSize() / sizeof(uint32_t);
		}
	}

	virtual void    operator>>(uint8_t* pData)
	{
		StreamingObj::operator>>(pData);
		uint32_t*   pDst = (uint32_t*)(&pData[StreamingObj::GetStreamSize()]);
		*pDst++ = swap_uint32(_nNumCycles);
		*pDst++ = swap_uint32((uint32_t)_vSteps.size());

		for (int i = 0; i < (int)_vSteps.size(); i++)
		{
			_vSteps[i] >> (uint8_t*)pDst;
			pDst += _vSteps[i].GetStreamSize() / sizeof(uint32_t);
		}
	}

	Segment& operator=(const Segment& rhs)
	{
		Clear();
		_vSteps.resize(rhs.GetNumSteps());
		_nNumCycles = rhs.GetNumCycles();
		for (int nStepIdx = 0; nStepIdx < (int)rhs.GetNumSteps(); nStepIdx++)
			_vSteps[nStepIdx] = rhs.GetStep(nStepIdx);

		return *this;
	}

protected:

private:
	uint32_t            _nNumCycles;
	std::vector<Step>   _vSteps;
};

#endif // __Segment_H