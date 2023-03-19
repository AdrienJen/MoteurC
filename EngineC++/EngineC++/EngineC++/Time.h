#pragma once

#include <chrono>
#include <vector>
#include <functional>
#include <chrono>
#include <vector>
#include <functional>
#include <algorithm>

namespace Time {
	// Variables qui stockent les temps d'exécution
	static std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime, fixedStartTime, fixedEndTime;
	// Durée écoulée depuis le dernier appel de la fonction Update()
	static std::chrono::duration<float> elapsedTime, fixedElapsedTime;

	/**
	 * Démarre la mesure du temps
	 */
	static void Start() {
		// Initialise les temps de démarrage
		startTime = endTime = fixedStartTime = fixedEndTime = std::chrono::high_resolution_clock::now();
	}

	/**
	 * Calcule la durée écoulée depuis le dernier appel de la fonction Update()
	 */
	static void Update() {
		// Enregistre le temps de fin de frame précédent
		startTime = std::chrono::high_resolution_clock::now();
		// Calcule la durée écoulée entre le temps de fin et le temps de début
		elapsedTime = startTime - endTime;
		// Met à jour le temps de fin pour la prochaine frame
		endTime = startTime;
	}

	/**
	 * Retourne le temps écoulé en secondes depuis la dernière mise à jour
	 * @return Temps écoulé en secondes
	 */
	static float DeltaTime() {
		// Limite la valeur retournée entre 0.001 et 0.1 secondes
		return std::clamp(elapsedTime.count(), 0.001f, 0.1f);
	}

	/**
	 * Met à jour le temps fixe
	 */
	static void FixedUpdate() {
		// Enregistre le temps de fin du dernier FixedUpdate()
		fixedStartTime = std::chrono::high_resolution_clock::now();
		// Calcule la durée écoulée depuis le dernier FixedUpdate()
		fixedElapsedTime = fixedStartTime - fixedEndTime;
		// Met à jour le temps de fin pour le prochain FixedUpdate()
		fixedEndTime = fixedStartTime;
	}

	/**
	 * Retourne la durée en secondes entre chaque appel de FixedUpdate()
	 * @return Temps écoulé en secondes
	 */
	static float FixedDeltaTime() {
		// Limite la valeur retournée entre 0.001 et 0.1 secondes
		return std::clamp(fixedElapsedTime.count(), 0.001f, 0.1f);
	}
}