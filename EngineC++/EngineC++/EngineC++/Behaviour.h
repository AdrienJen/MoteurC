#pragma once

	__declspec(dllexport) class Behaviour
	{
		virtual void Start() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Awake() = 0;
	};


