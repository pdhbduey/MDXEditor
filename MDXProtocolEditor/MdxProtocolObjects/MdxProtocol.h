#ifndef  __MdxProtocol_H
#define  __MdxProtocol_H

#include "PcrProtocol.h"
#include "MixingProtocol.h"
#include "SamplePrepProtocol.h"

class MdxProtocol
{
	private: 
		PcrProtocol _pcrProtocol;
		MixingProtocol _mixingProtocol;
		SamplePrepProtocol _samplePrepProtocol;

	public:
		MdxProtocol()
		{
		};

		~MdxProtocol() 
		{
		}

		PcrProtocol* GetPcrProtocol() 
		{
			return &_pcrProtocol;
		}

		void SetPcrProtocol(PcrProtocol& newPcrProtocol)
		{
			_pcrProtocol = newPcrProtocol;
		}
};

#endif // __MdxProtocolBase_H