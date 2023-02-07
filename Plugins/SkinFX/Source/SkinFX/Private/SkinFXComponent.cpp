#include "SkinFXComponent.h"
#include "Templates/SubclassOf.h"

class ASkinFXDefinition;
class ASkinFXDefinitionGraph;
class UTexture;

bool USkinFXComponent::SkinFXUpdateRules(FName FX, FMaterialSwapRules newRules) {
    return false;
}

bool USkinFXComponent::SkinFXStartWithRulesAndEnvelope(TSubclassOf<ASkinFXDefinition> FX, FMaterialSwapRules swapRules, FSkinFXASREnvelope UseEnvelope) {
    return false;
}

bool USkinFXComponent::SkinFXStartWithRules(TSubclassOf<ASkinFXDefinition> FX, FMaterialSwapRules swapRules) {
    return false;
}

bool USkinFXComponent::SkinFXStartWithEnvelope(TSubclassOf<ASkinFXDefinition> FX, FSkinFXASREnvelope UseEnvelope) {
    return false;
}

bool USkinFXComponent::SkinFXStart(TSubclassOf<ASkinFXDefinition> FX) {
    return false;
}

void USkinFXComponent::SkinFXSetTimeFactor(TSubclassOf<ASkinFXDefinition> FX, float TimeFactor, bool& Success) {
}

void USkinFXComponent::SkinFXSetExternalVectorParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, FVector Value, float packAlpha) {
}

void USkinFXComponent::SkinFXSetExternalTextureParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, UTexture* Value) {
}

void USkinFXComponent::SkinFXSetExternalScalarParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, float Value) {
}

void USkinFXComponent::SkinFXSetExternalParameters(TSubclassOf<ASkinFXDefinition> FX, const FMaterialSwapParameters& parameterValues) {
}

void USkinFXComponent::SkinFXSetExternalColorParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, FLinearColor Value) {
}

bool USkinFXComponent::SkinFXIsRunning(TSubclassOf<ASkinFXDefinition> FX) const {
    return false;
}

void USkinFXComponent::SkinFXGetTimeFactor(TSubclassOf<ASkinFXDefinition> FX, float& TimeFactor) {
}

void USkinFXComponent::SkinFXGetEffectBlueprintGraph(TSubclassOf<ASkinFXDefinition> FX, ASkinFXDefinitionGraph*& EffectDefinitionGraph) const {
}

void USkinFXComponent::SkinFXGetCurrentScalarParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, float& ParameterValue, bool& bParameterFound) const {
}

void USkinFXComponent::SkinFXGetCurrentParameters(TSubclassOf<ASkinFXDefinition> FX, FMaterialSwapParameters& CurrentParameters) const {
}

void USkinFXComponent::SkinFXGetCurrentColorParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, FLinearColor& ParameterValue, bool& bParameterFound) const {
}

bool USkinFXComponent::SkinFXEndAll(ESkinFXEffectEndStyle EndStyle) {
    return false;
}

bool USkinFXComponent::SkinFXEnd(TSubclassOf<ASkinFXDefinition> FX, ESkinFXEffectEndStyle EndStyle) {
    return false;
}

void USkinFXComponent::SkinFXClearExternalParameters(TSubclassOf<ASkinFXDefinition> FX) {
}

bool USkinFXComponent::SkinFXAnyRunning() const {
    return false;
}

USkinFXComponent::USkinFXComponent() {
    this->bOwnerKilled = false;
}

