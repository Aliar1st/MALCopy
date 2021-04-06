#pragma once

#include "TestVehicleCommandCollection.h"

/**
 * @brief	A command that performs the following series of commands automatically:
 *				Guided
 *				Arm
 *				Takeoff
 *				Land
 */
class TestVehicleCommandMission1 : public TestVehicleCommandCollection
{
private:

	constexpr static const float TAKE_OFF_ALTITUDE = 0.5f;

protected:

	virtual const std::vector<VehicleCommand*> getCommands(Vehicle* vehicle) override;

public:

	virtual const char* GetName() override;

	virtual const char* GetDescription() override;
};