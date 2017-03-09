#ifndef __COMPONENT_SCRIPT_H__
#define __COMPONENT_SCRIPT_H__

#include "Component.h"
#include "Globals.h"
#include <string>
#include <map>

class Application;
class GameObject;

using namespace std;

typedef void(*f_Start)(Application* engine_app, GameObject* game_object);
typedef void(*f_Update)(Application* engine_app, GameObject* game_object);
typedef void(*f_GetPublics)(map<const char*, string>* public_chars, map<const char*, int>* public_ints, map<const char*, float>* public_float, map<const char*, bool>* public_bools);

class ComponentScript : public Component
{
public:
	ComponentScript(ComponentType type, GameObject* game_object, const char* path);
	ComponentScript(ComponentType type, GameObject* game_object);
	~ComponentScript();

	void Update();

	void OnInspector(bool debug);

	void Save(Data& file)const;
	void Load(Data& conf);

	void SetPath(const char* path);

private:
	string path;

	bool started = false;
	bool finded_start;
	bool finded_update;
	int script_num;

	DWORD error;

public:
	map<const char*, string> public_chars;
	map<const char*, int> public_ints;
	map<const char*, float> public_floats;
	map<const char*, bool> public_bools;
};
#endif // !__COMPONENT_SCRIPT_H__
