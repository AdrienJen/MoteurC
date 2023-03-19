#pragma once

#include <chrono>
#include <vector>
#include <functional>
#include <chrono>
#include <vector>
#include <functional>
#include <algorithm>

namespace Time {
	// Variables qui stockent les temps d'ex�cution
	static std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime, fixedStartTime, fixedEndTime;
	// Dur�e �coul�e depuis le dernier appel de la fonction Update()
	static std::chrono::duration<float> elapsedTime, fixedElapsedTime;

	/**
	 * D�marre la mesure du temps
	 */
	static void Start() {
		// Initialise les temps de d�marrage
		startTime = endTime = fixedStartTime = fixedEndTime = std::chrono::high_resolution_clock::now();
	}

	/**
	 * Calcule la dur�e �coul�e depuis le dernier appel de la fonction Update()
	 */
	static void Update() {
		// Enregistre le temps de fin de frame pr�c�dent
		startTime = std::chrono::high_resolution_clock::now();
		// Calcule la dur�e �coul�e entre le temps de fin et le temps de d�but
		elapsedTime = startTime - endTime;
		// Met � jour le temps de fin pour la prochaine frame
		endTime = startTime;
	}

	/**
	 * Retourne le temps �coul� en secondes depuis la derni�re mise � jour
	 * @return Temps �coul� en secondes
	 */
	static float DeltaTime() {
		// Limite la valeur retourn�e entre 0.001 et 0.1 secondes
		return std::clamp(elapsedTime.count(), 0.001f, 0.1f);
	}

	/**
	 * Met � jour le temps fixe
	 */
	static void FixedUpdate() {
		// Enregistre le temps de fin du dernier FixedUpdate()
		fixedStartTime = std::chrono::high_resolution_clock::now();
		// Calcule la dur�e �coul�e depuis le dernier FixedUpdate()
		fixedElapsedTime = fixedStartTime - fixedEndTime;
		// Met � jour le temps de fin pour le prochain FixedUpdate()
		fixedEndTime = fixedStartTime;
	}

	/**
	 * Retourne la dur�e en secondes entre chaque appel de FixedUpdate()
	 * @return Temps �coul� en secondes
	 */
	static float FixedDeltaTime() {
		// Limite la valeur retourn�e entre 0.001 et 0.1 secondes
		return std::clamp(fixedElapsedTime.count(), 0.001f, 0.1f);
	}
}