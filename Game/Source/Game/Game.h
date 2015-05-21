#pragma once
#include <vector>

using namespace std;

#include <Core/World.h>
#include <Event/EventListener.h>

class Camera;
class ThirdPersonCamera;
class CameraInput;
class CameraDebugInput;
class ColorPicking;
class DirectionalLight;
class SpotLight;
class FrameBuffer;
class GameObject;
class Overlay;
class Player;
class SSAO;
class CSM;
class Texture;

class Game : public World,
			public EventListener
{
	public:
		Game();
		~Game();
		void Init();
		void Update(float elapsedTime, float deltaTime);

		void BarrelPhysicsTest(bool pointLights);

	private:
		void OnEvent(EventType Event, Object *data);
		void OnEvent(const char* eventID, Object *data);
		void InitSceneCameras();

	public:
		Camera				*activeCamera;

	private:
		Camera				*freeCamera;
		Camera				*gameCamera;
		ThirdPersonCamera	*thirdPersonCamera;
		CameraInput			*cameraInput;
		CameraDebugInput	*cameraDebugInput;

		DirectionalLight	*Sun;
		SpotLight			*Spot;

		FrameBuffer			*FBO;
		FrameBuffer			*FBO_Light;

		GameObject			*ScreenQuad;
		GameObject			*DebugPanel;
		Player				*player;

		SSAO				*ssao;
		CSM					*csm;

		ColorPicking		*colorPicking;

		vector<Camera*>		sceneCameras;
		unsigned int		activeSceneCamera;
};