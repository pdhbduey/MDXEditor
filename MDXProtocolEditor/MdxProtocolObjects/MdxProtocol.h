#ifndef  __MdxProtocol_H
#define  __MdxProtocol_H

#include "PcrProtocol.h"
#include "MixingProtocol.h"
#include "SamplePrepProtocol.h"

class MdxProtocol
{
private: PcrProtocol* pcrProtocol;
		 MixingProtocol* mixingProtocol;
		 SamplePrepProtocol* samplePrepProtocol;

	public:
		MdxProtocol()
		{
			pcrProtocol = new PcrProtocol();
			mixingProtocol = new MixingProtocol();
			samplePrepProtocol = new SamplePrepProtocol();
		};

		~MdxProtocol() 
		{
			delete pcrProtocol;
			delete mixingProtocol;
			delete samplePrepProtocol;
		}

		PcrProtocol* GetPcrProtocol() 
		{
			return pcrProtocol;
		}

		void UpdatePcrProtocol(PcrProtocol newPcrProtocol)
		{
			pcrProtocol = &newPcrProtocol;
		}

		MixingProtocol* GetMixingProtocol()
		{
			return mixingProtocol;
		}

		void UpdateMixingProtocol(MixingProtocol newMixingProtocol)
		{
			mixingProtocol = &newMixingProtocol;
		}

		SamplePrepProtocol* GetSamplePrepProtocol()
		{
			return samplePrepProtocol;
		}

		void UpdateSamplePrepProtocol(SamplePrepProtocol newSamplePrepProtocol)
		{
			samplePrepProtocol = &newSamplePrepProtocol;
		}
};

#endif // __MdxProtocolBase_H