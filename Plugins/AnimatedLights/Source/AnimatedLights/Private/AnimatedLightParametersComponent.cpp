#include "AnimatedLightParametersComponent.h"

class UMaterialInstanceDynamic;
class UNiagaraComponent;

bool UAnimatedLightParametersComponent::RemoveAnimatedLightParameters() {
    return false;
}

bool UAnimatedLightParametersComponent::RemoveAnimatedLightParameter(FName Parameter) {
    return false;
}

bool UAnimatedLightParametersComponent::RemoveAnimatedLightNiagaraParameters(UNiagaraComponent* NiagaraComponent) {
    return false;
}

bool UAnimatedLightParametersComponent::RemoveAnimatedLightNiagaraParameter(FName Parameter) {
    return false;
}

bool UAnimatedLightParametersComponent::RemoveAnimatedLightMaterialParameters(UMaterialInstanceDynamic* MaterialInstanceDynamic) {
    return false;
}

bool UAnimatedLightParametersComponent::RemoveAnimatedLightMaterialParameter(FName Parameter) {
    return false;
}

bool UAnimatedLightParametersComponent::AddAnimatedLightNiagaraParameters(UNiagaraComponent* NiagaraComponent, TArray<FAnimatedLightExtraParameter> ParameterList) {
    return false;
}

bool UAnimatedLightParametersComponent::AddAnimatedLightNiagaraParameter(UNiagaraComponent* NiagaraComponent, FAnimatedLightExtraParameter Parameter) {
    return false;
}

bool UAnimatedLightParametersComponent::AddAnimatedLightMaterialParameters(UMaterialInstanceDynamic* MaterialInstanceDynamic, TArray<FAnimatedLightExtraParameter> ParameterList) {
    return false;
}

bool UAnimatedLightParametersComponent::AddAnimatedLightMaterialParameter(UMaterialInstanceDynamic* MaterialInstanceDynamic, FAnimatedLightExtraParameter Parameter) {
    return false;
}

UAnimatedLightParametersComponent::UAnimatedLightParametersComponent() {
}

