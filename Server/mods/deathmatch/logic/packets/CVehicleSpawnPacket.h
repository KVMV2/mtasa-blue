/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/packets/CVehicleSpawnPacket.h
 *  PURPOSE:     Vehicle spawn packet class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

class CVehicleSpawnPacket;

#ifndef __CVEHICLESPAWNPACKET_H
#define __CVEHICLESPAWNPACKET_H

#include "CPacket.h"
#include <vector>

class CVehicle;

class CVehicleSpawnPacket : public CPacket
{
public:
    ePacketID     GetPacketID(void) const { return PACKET_ID_VEHICLE_SPAWN; };
    unsigned long GetFlags(void) const { return PACKET_HIGH_PRIORITY | PACKET_RELIABLE | PACKET_SEQUENCED; };

    bool Write(NetBitStreamInterface& BitStream) const;

    void Add(CVehicle* pVehicle) { m_List.push_back(pVehicle); };
    void Clear(void) { m_List.clear(); };

private:
    std::vector<CVehicle*> m_List;
};

#endif
