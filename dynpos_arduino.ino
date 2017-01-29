#include <flowSerialArduino.h>
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

class MotorFlowReg{
public:
	MotorFlowReg(){flowReg[0] = 0; flowReg[1] = 0;}
	uint8_t flowReg[4];
	inline uint8_t getMotorFront(){return flowReg[0];}
	inline void setMotorFront(uint8_t motorFront){flowReg[0] = motorFront;}
	inline uint8_t getMotorBack(){return flowReg[1];}
	inline void setMotorBack(uint8_t motorBack){flowReg[1] = motorBack;}
	inline uint8_t getRotationFront(){return flowReg[2];}
	inline void setRotationFront(uint8_t rotationFront){flowReg[2] = rotationFront;}
	inline uint8_t getRotationBack(){return flowReg[3];}
	inline void setRotationBack(uint8_t rotationBack){flowReg[3] = rotationBack;}
}static motorFlowReg;

void setup() {
	motorFront.attach(pinOut.motorFront);
	motorBack.attach(pinOut.motorBack);
	rotationFront.attach(pinOut.rotationFront);
	rotationBack.attach(pinOut.rotationBack);
}

void loop() {
	static FlowSerial flowSerial(115200, motorFlowReg.flowReg, sizeof(motorFlowReg.flowReg) / sizeof(motorFlowReg.flowReg[0]));
	flowSerial.update();
	motorFront.write(motorFlowReg.getMotorFront());
	motorBack.write(motorFlowReg.getMotorBack());
	rotationFront.write(motorFlowReg.getRotationFront());
	rotationBack.write(motorFlowReg.getRotationBack());
}
