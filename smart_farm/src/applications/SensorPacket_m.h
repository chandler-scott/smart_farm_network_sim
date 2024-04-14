//
// Generated file, do not edit! Created by opp_msgtool 6.0 from applications/SensorPacket.msg.
//

#ifndef __SENSORPACKET_M_H
#define __SENSORPACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class SensorPacket;
#include "inet/common/packet/Packet_m.h" // import inet.common.packet.Packet

/**
 * Class generated from <tt>applications/SensorPacket.msg:18</tt> by opp_msgtool.
 * <pre>
 * packet SensorPacket extends inet::Packet
 * {
 *     double soilMoistureLevel;
 * }
 * </pre>
 */
class SensorPacket : public ::inet::Packet
{
  protected:
    double soilMoistureLevel = 0;

  private:
    void copy(const SensorPacket& other);

  protected:
    bool operator==(const SensorPacket&) = delete;

  public:
    SensorPacket(const char *name=nullptr, short kind=0);
    SensorPacket(const SensorPacket& other);
    virtual ~SensorPacket();
    SensorPacket& operator=(const SensorPacket& other);
    virtual SensorPacket *dup() const override {return new SensorPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual double getSoilMoistureLevel() const;
    virtual void setSoilMoistureLevel(double soilMoistureLevel);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SensorPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SensorPacket& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline SensorPacket *fromAnyPtr(any_ptr ptr) { return check_and_cast<SensorPacket*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __SENSORPACKET_M_H

