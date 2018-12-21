#ifndef  __MdxProtocol_H
#define  __MdxProtocol_H

#include "PcrProtocol.h"

class MdxProtocol
{
private: PcrProtocol* pcrProtocol;

	public:
		MdxProtocol()
		{
		};

		PcrProtocol* GetPcrProtocol() 
		{
			return pcrProtocol;
		}

		void UpdatePcrProtocol(PcrProtocol newPcrProtocol)
		{
			pcrProtocol = &newPcrProtocol;
		}
};

#endif // __MdxProtocolBase_H