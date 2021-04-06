#include "TestVehicleCommandMission5.h"

#include "Vehicles/Commands/VehicleCommandArm.h"
#include "Vehicles/Commands/VehicleCommandGuided.h"
#include "Vehicles/Commands/VehicleCommandLand.h"
#include "Vehicles/Commands/VehicleCommandMoveUpward.h"
#include "Vehicles/Commands/VehicleCommandRotateByCCW.h"
#include "Vehicles/Commands/VehicleCommandRotateByCW.h"
#include "Vehicles/Commands/VehicleCommandTakeOff.h"

const char* TestVehicleCommandMission5::GetName()
{
	return "mission5";
}

const char* TestVehicleCommandMission5::GetDescription()
{
	return "Takes off, rotates, ascends, rotates, lands";
}

const std::vector<VehicleCommand*> TestVehicleCommandMission5::getCommands(Vehicle* vehicle)
{
	const float multiplier = (vehicle->IsOutdoor() ? 10.0f : 1.0f);

	const float takeOffAltitude = TAKE_OFF_ALTITUDE * multiplier;
	const float upDownMovement = UP_DOWN_MOVEMENT * multiplier;

	return std::vector<VehicleCommand*>
		   {
			   new VehicleCommandGuided(),
			   new VehicleCommandArm(),
			   new VehicleCommandTakeOff(takeOffAltitude),
			   new VehicleCommandRotateByCW(ROTATION_MOVEMENT),
			   new VehicleCommandRotateByCCW(2 * ROTATION_MOVEMENT),
			   new VehicleCommandRotateByCW(ROTATION_MOVEMENT),
			   new VehicleCommandMoveUpward(upDownMovement),
			   new VehicleCommandRotateByCW(ROTATION_MOVEMENT),
			   new VehicleCommandRotateByCCW(2 * ROTATION_MOVEMENT),
			   new VehicleCommandRotateByCW(ROTATION_MOVEMENT),
			   new VehicleCommandLand()
		   };
}