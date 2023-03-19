#include "ASCIIRenderer.h"



ASCIIRenderer::ASCIIRenderer(GameObject* go, char ascii, int renderPriority) : Component(go), asciiValue(ascii), priority(renderPriority) {

}
char ASCIIRenderer::getAsciiValue() const {
	return asciiValue;
}

void ASCIIRenderer::setAsciiValue(char val) {
	asciiValue = val;
}

int ASCIIRenderer::getPriority() const {
	return priority;
}

void ASCIIRenderer::setPriority(int val) {
	priority = val;
}

void ASCIIRenderer::Start() {}

void ASCIIRenderer::Update() {}

void ASCIIRenderer::FixedUpdate() {}

void ASCIIRenderer::LateUpdate() {}
