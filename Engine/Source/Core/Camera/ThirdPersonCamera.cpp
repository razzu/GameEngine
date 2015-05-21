//#include <pch.h>
#include "ThirdPersonCamera.h"

#include <include/math.h>

#include <Component/Transform.h>
#include <Component/Mesh.h>


ThirdPersonCamera::ThirdPersonCamera()
	: GameObject("3rd-camera")
{
	targetMaxDist = 200.0f;	
	limitUpTPS =  0.95f * (float) M_PI / 2;
	targetDist = 50.0f; //TEMPORARY!
}

ThirdPersonCamera::~ThirdPersonCamera() {

}

void ThirdPersonCamera::RotateOX(float deltaTime) {
	if (deltaTime == 0)
		return;

	SetPosition(transform->position + glm::normalize(forward) * targetDist);
	UpdatePitch(-deltaTime * sensitivityOX);
	SetPosition(transform->position - glm::normalize(forward) * targetDist);
}

void ThirdPersonCamera::RotateOY(float deltaTime) {
	if (deltaTime == 0)
		return;

	SetPosition(transform->position + glm::normalize(forward) * targetDist);
	SetYaw(-deltaTime * sensitivityOY);
	SetPosition(transform->position - glm::normalize(forward) * targetDist);
}

void ThirdPersonCamera::RotateOZ(float deltaTime) {

}

void ThirdPersonCamera::MoveCloser(float add) {
	if (type == CameraType::FirstPerson)	
		return;

	if (targetDist + add <= 0.5f)
		return;

	if (targetDist + add > targetMaxDist)
		return;

	targetDist += add;
	transform->position -= forward * add;
}

void ThirdPersonCamera::SwitchView(CameraType cameraType)
{
	// Switch to FirstPerson
	if (type == CameraType::ThirdPerson) {
		type = CameraType::FirstPerson;
		transform->position = transform->position + forward * targetDist;
		UpdatePitch(-transform->eulerAngles.x);
		return;
	}
}
