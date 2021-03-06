/*
 * APIStructures.h
 *
 *  Created on: Apr 19, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_APISTRUCTURES_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_APISTRUCTURES_H_

/* number of handles the system can support */
#define NO_HANDLES				0xFF

/* Reply definitions */
#define REPLY_ERROR				0x00
#define REPLY_OKAY				0x01
#define REPLY_RESET				0x02
#define REPLY_OTHER				0x04
#define REPLY_BADCRC			0x08
#define REPLY_WARNING			0x10
#define REPLY_INVALID			0x20

/* command variables */
#define CARRIAGE_RETURN			0xD

/*
 * Since the introduction of NDI enhanced Tool Interface Unit
 * and Tool Docking Station, upto 20 port handles can now be
 * allocated and maximum reply message length shall be increased.
 *
 * Command message length shall be made different from the reply
 * message and the command message is much shorter.
 */
#define MAX_REPLY_MSG			4096

#define MAX_COMMAND_MSG			1024
#define LINE_FEED    			0xA

/* transform return values */
#define TRANSFORM_VALID			0x0000
#define	TRANSFORM_MISSING		0x1000
#define TRANSFORM_UNOCCUPIED	0x2000
#define TRANSFORM_DISABLED		0x3000
#define TRANSFORM_ERROR			0x4000

/* timeout returns */
#define ERROR_TIMEOUT_CLOSE		0
#define ERROR_TIMEOUT_RESTART	1
#define ERROR_TIMEOUT_CONT		2

/* math numbers */
#define BAD_FLOAT    (float)-3.697314E28
#define MAX_NEGATIVE (float)-3.0E28

/* message handler */
#define WM_COM_PORT_TO			WM_USER+2

/*****************************************************************
 Structures
 *****************************************************************/
/* POSITION 3D Structure */
typedef struct Position3dStruct {
	float fTx;
	float fTy;
	float fTz;
} Position3d;

/* QUATERNION Structure */
typedef struct QuatRotationStruct {
	float fQ0;
	float fQx;
	float fQy;
	float fQz;
} QuatRotation;

typedef struct QuatTransformationStruct {
	QuatRotation dtRotation;
	Position3d dtTranslation;
} QuatTransformation;

typedef float RotationMatrix[3][3];

typedef struct Rotation {

	float fRoll, /* rotation about the object's z-axis (Euler angle) */
	fPitch, /* rotation about the object's y-axis (Euler angle) */
	fYaw; /* rotation about the object's x-axis (Euler angle) */
} Rotation;

/* Transformation Information Structure */
typedef struct {
	unsigned long ulFlags, ulFrameNumber;
	QuatRotation dtRotation;
	Position3d dtTranslation;
	float fError;
} TransformInformation;

/* Handle Status Structure */
typedef struct {
	int nToolInPort, nGPIO1, nGPIO2, nGPIO3, nInitialized, nEnabled,
			nOutOfVolume, nPartiallyOutOfVolume, nDisturbanceDet,
			nSignalTooSmall, nSignalTooBig, nProcessingException,
			nHardwareFailure, TIPCurrentSensing;
} HandleStatus;

/* Handle Information Structure */
typedef struct {
	char pchrPhysicalPort[20], pchrToolType[9], pchrManufact[13],
			pchrSerialNo[9], pchrRev[4], pchrChannel[3], pchrPartNumber[21];
	TransformInformation dtXfrms;
	HandleStatus dtHandleInfo;
} HandleInformation;

/*System Information Structure*/
typedef struct {
	int nTypeofSystem;
	char pchrVersionInfo[1024];
	int nActivePortsAvail, nPassivePortsAvail, nMultiVolumeParms, nTIPSensing,
			nActiveWirelessAvail, nMagneticPortsAvail, nFieldGeneratorAvail;
	/* POLARIS ONLY FIELDS */
	int nNoActivePorts, nNoPassivePorts, nNoActTIPPorts, nNoActWirelessPorts;
	/* AURORA ONLY FIELDS */
	int nNoMagneticPorts, nNoFGCards, nNoFGs;
	/* TRACKING INFORMATION */
	int nCommunicationSyncError;
	int nTooMuchInterference;
	int nSystemCRCError;
	int nRecoverableException;
	int nHardwareFailure;
	int nHardwareChange;
	int nPortOccupied;
	int nPortUnoccupied;
	int nDiagnosticsPending;
	int nTemperatureOutOfRange;
} SystemInformation;

/*System Information Structure*/
typedef struct {
	int nFatalParamterFault, nSensorParameterFault, nMainVoltageFault,
			nSensorVoltageFault, nIlluminatorVoltageFault,
			nIlluminatorCurrentFault, nLeftSensorTempFault,
			nRightSensorTempFault, nMainBoardTempFault, nBatteryFaultAlarm,
			nBumpDetectedAlarm, nCableFaultAlarm, nFirmwareIncompatible,
			nNonFatalParamFault, nInternalFlashFull, nLaserBatteryFaultAlarm,
			nTempTooHigh, nTempTooLow;
} DiagNewAlertFlags;

#define ALERT_FATAL_PARAM_FAULT		0x00000001
#define ALERT_SENSOR_PARAM_FAULT	0x00000002
#define ALERT_MAIN_VOLTAGE_FAULT	0x00000004
#define ALERT_SENSOR_VOLTAGE_FAULT	0x00000008
#define ALERT_ILLUM_VOLTAGE_FAULT	0x00000010
#define ALERT_ILLUM_CURRENT_FAULT	0x00000020
#define ALERT_LEFT_SENSOR_TEMP		0x00000040
#define ALERT_RIGHT_SENSOR_TEMP		0x00000080
#define ALERT_MAIN_BOARD_TEMP		0x00000100
#define ALERT_BATTERY_FAULT			0x00100000
#define ALERT_BUMP_DETECTED			0x00200000
#define ALERT_CABLE_FAULT			0x00400000
#define ALERT_FIRMWARE_INCOMPAT		0x00800000
#define ALERT_NON_FATAL_PARAM_FAULT	0x01000000
#define ALERT_INTERNAL_FLASH_FULL   0x02000000
#define ALERT_LASER_BATTERY_FAULT   0x04000000
#define ALERT_TEMP_TOO_HIGH			0x20000000
#define ALERT_TEMP_TOO_LOW			0x40000000

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_APISTRUCTURES_H_ */
