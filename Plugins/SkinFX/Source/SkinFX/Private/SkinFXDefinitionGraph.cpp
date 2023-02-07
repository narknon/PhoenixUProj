#include "SkinFXDefinitionGraph.h"

class AActor;
class USkinFXComponent;
class UTexture;

void ASkinFXDefinitionGraph::WantPerTickUpdateEvent(bool tickMe) {
}


void ASkinFXDefinitionGraph::SkinFXSignalFinished() {
}

void ASkinFXDefinitionGraph::SkinFXSetVectorParameter(FName ParameterName, FVector Value, float packAlpha) {
}

void ASkinFXDefinitionGraph::SkinFXSetTextureParameter(FName ParameterName, UTexture* Value) {
}

void ASkinFXDefinitionGraph::SkinFXSetScalarParameter(FName ParameterName, float Value) {
}

void ASkinFXDefinitionGraph::SkinFXSetParameters(const FMaterialSwapParameters& parameterValues) {
}

void ASkinFXDefinitionGraph::SkinFXSetColorParameter(FName ParameterName, FLinearColor Value) {
}






void ASkinFXDefinitionGraph::SkinFXGetSkinFXComponent(USkinFXComponent*& RunningSkinFXComponent) const {
}

void ASkinFXDefinitionGraph::SkinFXGetMyEffectName(FName& MyEffectName) const {
}

float ASkinFXDefinitionGraph::SkinFXGetEnvelopeValueLinear() const {
    return 0.0f;
}

float ASkinFXDefinitionGraph::SkinFXGetEnvelopeValueCurve() const {
    return 0.0f;
}

void ASkinFXDefinitionGraph::SkinFXGetCurrentScalarParameter(FName ParameterName, float& ParameterValue, bool& bParameterFound) const {
}

void ASkinFXDefinitionGraph::SkinFXGetCurrentParameters(FMaterialSwapParameters& CurrentParameters) const {
}

void ASkinFXDefinitionGraph::SkinFXGetCurrentColorParameter(FName ParameterName, FLinearColor& ParameterValue, bool& bParameterFound) const {
}

void ASkinFXDefinitionGraph::SkinFXGetAffectedActor(AActor*& AffectedActor) {
}


bool ASkinFXDefinitionGraph::SkinFXApplyParameters() {
    return false;
}

ASkinFXDefinitionGraph::ASkinFXDefinitionGraph() {
    this->bWantPerTickUpdateEvent = false;
    this->bSignalFinished = true;
}

