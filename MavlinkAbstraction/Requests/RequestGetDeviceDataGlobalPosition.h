#pragma once

#include "MavlinkAbstraction/Responses/ResponseGetDeviceDataGlobalPosition.h"
#include "RequestGetDeviceDataBase.h"

/**
 * @brief	Class to handle the response of the "GetDeviceData" request which retrieves device data about the global position
 */
class RequestGetDeviceDataGlobalPosition : public RequestGetDeviceDataBase
{
private:

	ResponseGetDeviceDataGlobalPosition* response;

public:

	/**
	 * @brief	The constructor of RequestGetDeviceDataGlobalPosition.
	 *
	 * @param[in]	logger		Logger
	 * @param[in]	response	Response to write the data into
	 */
	RequestGetDeviceDataGlobalPosition(Logger* logger, ResponseGetDeviceDataGlobalPosition* response);

	/**
	 * @brief	The destructor of RequestGetDeviceDataGlobalPosition.
	 */
	virtual ~RequestGetDeviceDataGlobalPosition();

	virtual uint16_t GetRequestedMessageID() override;

	virtual void SetResponseSuccess(bool success) override;

	virtual void OnResponseReceived(mavlink_message_t* message) override;
};