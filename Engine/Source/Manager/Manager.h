#pragma once

#include <include/dll_export.h>
#include <string>

class AudioManager;
class ColorManager;
class DebugInfo;
class EventSystem;
class FontManager;
class MenuSystem;
class ResourceManager;
class TextureManager;
class SceneManager;
class ShaderManager;
class ConfigFile;
class RenderingSystem;

#ifdef PHYSICS_ENGINE
class HavokCore;
class PhysicsManager;
#endif

using namespace std;

class Manager
{
	private:
		Manager() {};
		~Manager() {};

	public:
		DLLExport static void Init();
		DLLExport static void LoadConfig();
		DLLExport static AudioManager*		GetAudio();
		DLLExport static DebugInfo*			GetDebug();
		DLLExport static SceneManager*		GetScene();
		DLLExport static ResourceManager*	GetResource();
		DLLExport static ShaderManager*		GetShader();
		DLLExport static RenderingSystem*	GetRenderSys();
		DLLExport static EventSystem*		GetEvent();
		DLLExport static MenuSystem*		GetMenu();
		DLLExport static TextureManager*	GetTexture();
		DLLExport static ConfigFile*		GetConfig();

		#ifdef PHYSICS_ENGINE
		DLLExport static HavokCore* GetHavok();
		DLLExport static PhysicsManager* GetPhysics();
		#endif

	public:
		static AudioManager		*Audio;
		static ColorManager		*Color;
		static DebugInfo		*Debug;
		static EventSystem		*Event;
		static FontManager		*Font;
		static MenuSystem		*Menu;
		static ResourceManager	*Resource;
		static TextureManager	*Texture;
		static SceneManager		*Scene;
		static ShaderManager	*Shader;
		static ConfigFile		*Config;
		static RenderingSystem	*RenderSys;

		#ifdef PHYSICS_ENGINE
		static HavokCore *Havok;
		static PhysicsManager *Physics;
		#endif

};