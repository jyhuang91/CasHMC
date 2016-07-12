/*********************************************************************************
*  CasHMC v1.0 - 2016.05.07
*  A Cycle-accurate Simulator for Hybrid Memory Cube
*
*  Copyright (c) 2016, Dong-Ik Jeon
*                      Ki-Se/*********************************************************************************
*  CasHMC v1.0 - 2016.05.07
*  A Cycle-accurate Simulator for Hybrid Memory Cube
*
*  Copyright (c) 2016, Dong-Ik Jeon
*                      Ki-Seok Chung
*                      Hanyang University
*                      estwings57 [at] gmail [dot] com
*  All rights reserved.
*********************************************************************************/

#ifndef CROSSBARSWITCH_H
#define CROSSBARSWITCH_H

//CrossbarSwitch.h

#include <vector>		//vector

#include "DualVectorObject.h"
#include "SimConfig.h"
#include "DRAMConfig.h"
#include "LinkMaster.h"

using namespace std;

static unsigned maxSize=0;

namespace CasHMC
{
	
class CrossbarSwitch : public DualVectorObject<Packet, Packet>
{
public:
	//
	//Functions
	//
	CrossbarSwitch(ofstream &debugOut_, ofstream &stateOut_);
	virtual ~CrossbarSwitch();
	void CallbackReceiveDown(Packet *downEle, bool chkReceive);
	void CallbackReceiveUp(Packet *upEle, bool chkReceive);
	void Update();
	void PrintState();

	//
	//Fields
	//
	vector<DualVectorObject<Packet, Packet> *> downBufferDest;
	vector<LinkMaster *> upBufferDest;
	int inServiceLink;
	bool bufOverflow;
};

}

#endif