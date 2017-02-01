#include <flowSerialArduino.h>
#include "FlowRegDefine.h"
#include <Servo.h>

struct PinOut{
	uint8_t motorFront = 11;
	uint8_t motorBack = 10;
	uint8_t rotationFront = 6;
	uint8_t rotationBack = 5;
}static const pinOut;

Servo motorFront;
Servo motorBack;
Servo rotationFront;
Servo rotationBack;

static FlowRegDefine flowRegDefine;

void setup() {
	motorFront.attach(pinOut.motorFront);
	motorBack.attach(pinOut.motorBack);
	rotationFront.attach(pinOut.rotationFront);
	rotationBack.attach(pinOut.rotationBack);
}

void loop() {
	static FlowSerial flowSerial(115200, flowRegDefine.flowReg, flowRegDefine.flowRegSize);
	flowSerial.update();
	motorFront.write(flowRegDefine.getMotorFront());
	motorBack.write(flowRegDefine.getMotorBack());
	rotationFront.write(flowRegDefine.getRotationFront());
	rotationBack.write(flowRegDefine.getRotationBack());
}
