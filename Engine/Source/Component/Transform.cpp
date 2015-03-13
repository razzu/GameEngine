//#include <pch.h>
#include "Transform.h"
#include <include/math.h>

Transform::Transform() {
	position = glm::vec3(0);
	eulerAngles = glm::vec3(0.0f, 0.0f, 0.0f);
	rotationQ = glm::quat(1.0f, 0, 0, 0);
	scale = glm::vec3(1.0f);
	rotateSpeed = 2.5f;
	moveSpeed = 2.5f;
	scaleSpeed = 0.02f;
}

Transform::Transform(const Transform &transform) {
	position = transform.position;
	rotationQ = transform.rotationQ;
	eulerAngles = transform.eulerAngles;
	scale = transform.scale;
	Update();
}

Transform& Transform::operator=(const Transform &transform) {
	position = transform.position;
	rotationQ = transform.rotationQ;
	eulerAngles = transform.eulerAngles;
	scale = transform.scale;
	Update();
	return *this;
}

Transform::~Transform() {
}

void Transform::Update() {
	glm::mat4 rotationMatrix = glm::toMat4(rotationQ);
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
	model = translationMatrix * rotationMatrix;
	model = glm::scale(model, scale);
}

void Transform::Move(const glm::vec3 dir, float deltaTime) {
	position += glm::normalize(dir) * moveSpeed * deltaTime;
	Update();
}

void Transform::RotateRoll(float deltaTime) {
	eulerAngles.x += rotateSpeed * deltaTime;
	rotationQ = glm::quat(eulerAngles);
	Update();
}

void Transform::RotateYaw(float deltaTime) {
	eulerAngles.y += rotateSpeed * deltaTime;
	rotationQ = glm::quat(eulerAngles);
	Update();
}

void Transform::RotatePitch(float deltaTime) {
	eulerAngles.z += rotateSpeed * deltaTime;
	rotationQ = glm::quat(eulerAngles);
	Update();
}

void Transform::SetPosition(glm::vec3 position)
{
	this->position = position;
	Update();
}

void Transform::SetRotation(glm::vec3 eulerAngles) {
	this->eulerAngles = glm::vec3(eulerAngles) * (glm::pi<float>() / 180);
	rotationQ = glm::quat(this->eulerAngles);
	Update();
}

void Transform::SetRotation(glm::quat roationQ)
{
	this->rotationQ = roationQ;
	Update();
}

void Transform::SetRotationRadians(glm::vec3 eulerAngles) {
	this->eulerAngles = glm::vec3(eulerAngles);
	rotationQ = glm::quat(this->eulerAngles);
	Update();
}

void Transform::Scale(float deltaTime) {
	scale += scaleSpeed * glm::vec3(deltaTime);
	Update();
}

glm::vec3 Transform::GetRotationVector()
{
	glm::vec3 forward;
	forward.x = cos(eulerAngles.y) * cos(eulerAngles.z);
	forward.z = -sin(eulerAngles.y) * cos(eulerAngles.z);
	forward.y = sin(eulerAngles.z);
	return forward;
}