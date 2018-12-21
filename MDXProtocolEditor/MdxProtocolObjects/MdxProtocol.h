#ifndef  __MdxProtocol_H
#define  __MdxProtocol_H

#include "PcrProtocol.h"
#include "MixingProtocol.h"
#include "SamplePrepProtocol.h"

class MdxProtocol
{
	private: 
		PcrProtocol pcrProtocol;
		MixingProtocol mixingProtocol;
		SamplePrepProtocol samplePrepProtocol;

	public:
		MdxProtocol()
		{
		};

		~MdxProtocol() 
		{
		}

		PcrProtocol* GetPcrProtocol() 
		{
			return &pcrProtocol;
		}

		void SetPcrProtocol(PcrProtocol& newPcrProtocol)
		{
			pcrProtocol = newPcrProtocol;
		}
};

#endif // __MdxProtocolBase_H