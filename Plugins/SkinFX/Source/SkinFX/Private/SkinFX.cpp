#include "SkinFX.h"
#include "Templates/SubclassOf.h"

class AActor;
class ASkinFXDefinition;
class USkinFXComponent;
class UTexture;

FMaterialPermuterKey USkinFX::SkinFXNameMaterialPermuterKey(FName FX) {
    return FMaterialPermuterKey{};
}

void USkinFX::SkinFXName(TSubclassOf<ASkinFXDefinition> FX, FName& Name) {
}

FMaterialPermuterKey USkinFX::SkinFXMaterialPermuterKey(TSubclassOf<ASkinFXDefinition> FX) {
    return FMaterialPermuterKey{};
}

FMaterialPermuterKey USkinFX::SkinFXEffectMaterialPermuterKey(const ASkinFXDefinition* Effect) {
    return FMaterialPermuterKey{};
}

void USkinFX::EffectName(TSubclassOf<ASkinFXDefinition> FX, FName& Name) {
}

void USkinFX::ActorUpdateSkinFXRules(AActor* Actor, FName FX, FMaterialSwapRules newRules, bool& Result) {
}

void USkinFX::ActorStartSkinFXWithRulesAndInitialParameters(AActor* Actor, USkinFXComponent*& SkinFXComponent, FName StartFX, FMaterialSwapRules swapRules, FMaterialSwapParameters& parameterValues, bool detachAndDestroyWhenDone) {
}

void USkinFX::ActorStartSkinFXWithRules(AActor* Actor, USkinFXComponent*& SkinFXComponent, FName StartFX, FMaterialSwapRules swapRules, bool detachAndDestroyWhenDone) {
}

void USkinFX::ActorStartSkinFXWithInitialParameters(AActor* Actor, FName StartFX, FMaterialSwapParameters& parameterValues, USkinFXComponent*& SkinFXComponent, bool detachAndDestroyWhenDone) {
}

void USkinFX::ActorStartSkinFX(AActor* Actor, USkinFXComponent*& SkinFXComponent, FName StartFX, bool detachAndDestroyWhenDone) {
}

void USkinFX::ActorSetSkinFXTimeFactor(AActor* Actor, FName FXName, float TimeFactor, bool& Success) {
}

void USkinFX::ActorSetExternalVectorParameter(AActor* Actor, FName FXName, FName ParameterName, FVector Value, float packAlpha) {
}

void USkinFX::ActorSetExternalTextureParameter(AActor* Owner, FName FXName, FName ParameterName, UTexture* Value) {
}

void USkinFX::ActorSetExternalScalarParameter(AActor* Actor, FName FXName, FName ParameterName, float Value) {
}

void USkinFX::ActorSetExternalParameters(AActor* Actor, FName FXName, FMaterialSwapParameters& parameterValues) {
}

void USkinFX::ActorSetExternalColorParameter(AActor* Actor, FName FXName, FName ParameterName, FLinearColor Value) {
}

void USkinFX::ActorIsSkinFXRunning(AActor* Actor, FName FXName, bool& IsRunning) {
}

void USkinFX::ActorGetSkinFXTimeFactor(AActor* Actor, FName FXName, float& TimeFactor) {
}

void USkinFX::ActorGetSkinFX(AActor* Actor, USkinFXComponent*& SkinFXComponent) {
}

void USkinFX::ActorEndSkinFX(AActor* Actor, FName endFX, ESkinFXEffectEndStyle EndStyle) {
}

void USkinFX::ActorEndAllSkinFX(AActor* Actor, ESkinFXEffectEndStyle EndStyle) {
}

void USkinFX::ActorAnySkinFXRunning(AActor* Actor, bool& IsRunning) {
}

void USkinFX::ActorAddSkinFXComponent(AActor* Actor, USkinFXComponent*& SkinFXComponent, bool detachAndDestroyWhenDone) {
}

USkinFX::USkinFX() {
}

