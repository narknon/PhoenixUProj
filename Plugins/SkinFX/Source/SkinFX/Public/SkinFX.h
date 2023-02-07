#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialPermuterKey.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapRules.h"
#include "ESkinFXEffectEndStyle.h"
#include "Templates/SubclassOf.h"
#include "SkinFX.generated.h"

class AActor;
class ASkinFXDefinition;
class USkinFXComponent;
class UTexture;

UCLASS(Blueprintable)
class SKINFX_API USkinFX : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USkinFX();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey SkinFXNameMaterialPermuterKey(FName FX);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SkinFXName(TSubclassOf<ASkinFXDefinition> FX, FName& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey SkinFXMaterialPermuterKey(TSubclassOf<ASkinFXDefinition> FX);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey SkinFXEffectMaterialPermuterKey(const ASkinFXDefinition* Effect);
    
    UFUNCTION(BlueprintCallable)
    static void EffectName(TSubclassOf<ASkinFXDefinition> FX, FName& Name);
    
    UFUNCTION(BlueprintCallable)
    static void ActorUpdateSkinFXRules(AActor* Actor, FName FX, FMaterialSwapRules newRules, bool& Result);
    
    UFUNCTION(BlueprintCallable)
    static void ActorStartSkinFXWithRulesAndInitialParameters(AActor* Actor, USkinFXComponent*& SkinFXComponent, FName StartFX, FMaterialSwapRules swapRules, UPARAM(Ref) FMaterialSwapParameters& parameterValues, bool detachAndDestroyWhenDone);
    
    UFUNCTION(BlueprintCallable)
    static void ActorStartSkinFXWithRules(AActor* Actor, USkinFXComponent*& SkinFXComponent, FName StartFX, FMaterialSwapRules swapRules, bool detachAndDestroyWhenDone);
    
    UFUNCTION(BlueprintCallable)
    static void ActorStartSkinFXWithInitialParameters(AActor* Actor, FName StartFX, UPARAM(Ref) FMaterialSwapParameters& parameterValues, USkinFXComponent*& SkinFXComponent, bool detachAndDestroyWhenDone);
    
    UFUNCTION(BlueprintCallable)
    static void ActorStartSkinFX(AActor* Actor, USkinFXComponent*& SkinFXComponent, FName StartFX, bool detachAndDestroyWhenDone);
    
    UFUNCTION(BlueprintCallable)
    static void ActorSetSkinFXTimeFactor(AActor* Actor, FName FXName, float TimeFactor, bool& Success);
    
    UFUNCTION(BlueprintCallable)
    static void ActorSetExternalVectorParameter(AActor* Actor, FName FXName, FName ParameterName, FVector Value, float packAlpha);
    
    UFUNCTION(BlueprintCallable)
    static void ActorSetExternalTextureParameter(AActor* Owner, FName FXName, FName ParameterName, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    static void ActorSetExternalScalarParameter(AActor* Actor, FName FXName, FName ParameterName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void ActorSetExternalParameters(AActor* Actor, FName FXName, UPARAM(Ref) FMaterialSwapParameters& parameterValues);
    
    UFUNCTION(BlueprintCallable)
    static void ActorSetExternalColorParameter(AActor* Actor, FName FXName, FName ParameterName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorIsSkinFXRunning(AActor* Actor, FName FXName, bool& IsRunning);
    
    UFUNCTION(BlueprintCallable)
    static void ActorGetSkinFXTimeFactor(AActor* Actor, FName FXName, float& TimeFactor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorGetSkinFX(AActor* Actor, USkinFXComponent*& SkinFXComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ActorEndSkinFX(AActor* Actor, FName endFX, ESkinFXEffectEndStyle EndStyle);
    
    UFUNCTION(BlueprintCallable)
    static void ActorEndAllSkinFX(AActor* Actor, ESkinFXEffectEndStyle EndStyle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorAnySkinFXRunning(AActor* Actor, bool& IsRunning);
    
    UFUNCTION(BlueprintCallable)
    static void ActorAddSkinFXComponent(AActor* Actor, USkinFXComponent*& SkinFXComponent, bool detachAndDestroyWhenDone);
    
};

