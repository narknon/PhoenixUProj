#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapRules.h"
#include "ESkinFXEffectEndStyle.h"
#include "SkinFXASREnvelope.h"
#include "SkinFXDynamicEventDelegateDelegate.h"
#include "SkinFXExternalContext.h"
#include "SkinFXRunningEffectInstance.h"
#include "Templates/SubclassOf.h"
#include "SkinFXComponent.generated.h"

class ASkinFXDefinition;
class ASkinFXDefinitionGraph;
class UTexture;

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SKINFX_API USkinFXComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkinFXDynamicEventDelegate DynamicEventDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXRunningEffectInstance> EffectStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXExternalContext> ExternalContexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName FXSignalKillOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bOwnerKilled;
    
public:
    USkinFXComponent();
    UFUNCTION(BlueprintCallable)
    bool SkinFXUpdateRules(FName FX, FMaterialSwapRules newRules);
    
    UFUNCTION(BlueprintCallable)
    bool SkinFXStartWithRulesAndEnvelope(TSubclassOf<ASkinFXDefinition> FX, FMaterialSwapRules swapRules, FSkinFXASREnvelope UseEnvelope);
    
    UFUNCTION(BlueprintCallable)
    bool SkinFXStartWithRules(TSubclassOf<ASkinFXDefinition> FX, FMaterialSwapRules swapRules);
    
    UFUNCTION(BlueprintCallable)
    bool SkinFXStartWithEnvelope(TSubclassOf<ASkinFXDefinition> FX, FSkinFXASREnvelope UseEnvelope);
    
    UFUNCTION(BlueprintCallable)
    bool SkinFXStart(TSubclassOf<ASkinFXDefinition> FX);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetTimeFactor(TSubclassOf<ASkinFXDefinition> FX, float TimeFactor, bool& Success);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetExternalVectorParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, FVector Value, float packAlpha);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetExternalTextureParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetExternalScalarParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetExternalParameters(TSubclassOf<ASkinFXDefinition> FX, const FMaterialSwapParameters& parameterValues);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetExternalColorParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool SkinFXIsRunning(TSubclassOf<ASkinFXDefinition> FX) const;
    
    UFUNCTION(BlueprintCallable)
    void SkinFXGetTimeFactor(TSubclassOf<ASkinFXDefinition> FX, float& TimeFactor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetEffectBlueprintGraph(TSubclassOf<ASkinFXDefinition> FX, ASkinFXDefinitionGraph*& EffectDefinitionGraph) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetCurrentScalarParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, float& ParameterValue, bool& bParameterFound) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetCurrentParameters(TSubclassOf<ASkinFXDefinition> FX, FMaterialSwapParameters& CurrentParameters) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetCurrentColorParameter(TSubclassOf<ASkinFXDefinition> FX, FName ParameterName, FLinearColor& ParameterValue, bool& bParameterFound) const;
    
    UFUNCTION(BlueprintCallable)
    bool SkinFXEndAll(ESkinFXEffectEndStyle EndStyle);
    
    UFUNCTION(BlueprintCallable)
    bool SkinFXEnd(TSubclassOf<ASkinFXDefinition> FX, ESkinFXEffectEndStyle EndStyle);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXClearExternalParameters(TSubclassOf<ASkinFXDefinition> FX);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool SkinFXAnyRunning() const;
    
};

