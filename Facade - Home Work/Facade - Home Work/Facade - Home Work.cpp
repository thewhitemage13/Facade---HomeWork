#include <iostream>
using namespace std;

class Lighting {
	int light_level = 0;
	bool status;
public:
	void On() {
		cout << "Lighting on...\n";
		light_level = 100;
		status = true;
	}
	void Off() {
		cout << "Lighting off...\n";
		light_level = 0;
		status = false;
	}
	void Setting(int level) {
		if (level < 0 || level > 100)
			throw "0 to 100";
		else
			light_level = level;
	}
};

class ClimateControl {
	int temperature = 0;
	bool status;
public:
	void On() {
		cout << "Climate Control on...\n";
		temperature = 16;
		status = true;
	}
	void Off() {
		cout << "Climate Control off...\n";
		temperature = 0;
		status = false;
	}
	void Setting(int level) {
		if (level < 16 || level > 30)
			throw "0 to 30";
		else
			temperature = level;
	}
};

class SecuritySystem {
private:
	bool status;
public:
	void On() {
		cout << "Security System on...\n";
		status = true;
	}
	void Off() {
		cout << "Security System off...\n";
		status = false;
	}
	bool GetStatus() {
		return status;
	}
};

class Multimedia {
private:
	bool status;
	int volume = 0;
public:
	void On() {
		cout << "Multimedia on...\n";
		volume = 100;
		status = true;
	}
	void Off() {
		cout << "Multimedia off...\n";
		volume = 0;
		status = false;
	}
	void Setting(int level) {
		if (level < 0 || level > 100)
			throw "0 to 100";
		else
			volume = level;
	}
};

class SmartHome {
private:
	Lighting lighting;
	ClimateControl climate_control;
	SecuritySystem security_system;
	Multimedia multimedia;
public:
	void Morning() {
		lighting.On();
		lighting.Setting(25);
		climate_control.On();
		climate_control.Setting(20);
		security_system.Off();
		multimedia.Off();
	}

	void Night() {
		lighting.Off();
		climate_control.On();
		climate_control.Setting(22);
		security_system.On();
		multimedia.Off();
	}

	void LeaveHome() {
		lighting.Off();
		climate_control.Off();
		security_system.On();
		multimedia.Off();
	}

	void ComeHome() {
		lighting.On();
		lighting.Setting(50);
		climate_control.On();
		climate_control.Setting(20);
		security_system.Off();
		multimedia.On();
		multimedia.Setting(35);
	}
};

int main() {
	SmartHome smarthome;
	smarthome.Morning();
	cout << "\n===========================================\n";
	smarthome.ComeHome();
	cout << "\n===========================================\n";
	smarthome.LeaveHome();
	cout << "\n===========================================\n";
	smarthome.Night();
}