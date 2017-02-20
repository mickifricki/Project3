#ifndef __MODULECAR_H__
#define __MODULECAR_H__

#include "Module.h"
#include "Globals.h"
#include <vector>


using namespace std;

class ModuleCar : public Module
{
public:
	
	ModuleCar(const char* name, bool start_enabled = true);
	~ModuleCar();

	bool Init(Data& config);
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	
};

#endif // !__MODULECAR_H__
