/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ns3/basic-simulation.h"
#include "ns3/test.h"
#include "end-to-end-test.h"
#include "manual-two-sat-two-gs-test.h"
#include "satellite-info-test.h"
#include "ground-station-info-test.h"

using namespace ns3;

class SatelliteNetworkTestSuite : public TestSuite {
public:
    SatelliteNetworkTestSuite() : TestSuite("satellite-network", UNIT) {

        // Manual end-to-end, which means the application helpers are used
        // directly instead of the schedulers reading from files
        AddTestCase(new EndToEndTestCase, TestCase::QUICK);
        AddTestCase(new ManualTwoSatTwoGsFirstTest, TestCase::QUICK);
        AddTestCase(new ManualTwoSatTwoGsUpSharedTest, TestCase::QUICK);
        AddTestCase(new ManualTwoSatTwoGsDownBothFullTest, TestCase::QUICK);

        // Simple info wrappers
        AddTestCase(new SatelliteInfoTestCase, TestCase::QUICK);
        AddTestCase(new GroundStationInfoTestCase, TestCase::QUICK);

    }
};
static SatelliteNetworkTestSuite SatelliteNetworkTestSuite;
