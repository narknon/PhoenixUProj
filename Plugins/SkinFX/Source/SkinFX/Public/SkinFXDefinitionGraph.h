#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MaterialSwapParameters.h"
#include "ESkinFXDelegateEvent.h"
#include "ESkinFXEffectEndStyle.h"
#include "SkinFXDefinition.h"
#include "SkinFXDefinitionGraph.generated.h"

class AActor;
class USkinFXComponent;
class UTexture;

UCLASS(Blueprintable)
class SKINFX_API ASkinFXDefinitionGraph : public ASkinFXDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWantPerTickUpdateEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSignalFinished;
    
    ASkinFXDefinitionGraph(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void WantPerTickUpdateEvent(bool tickMe);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SkinFXUpdateTick(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSignalFinished();
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetVectorParameter(FName ParameterName, FVector Value, float packAlpha);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetTextureParameter(FName ParameterName, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetScalarParameter(FName ParameterName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetParameters(const FMaterialSwapParameters& parameterValues);
    
    UFUNCTION(BlueprintCallable)
    void SkinFXSetColorParameter(FName ParameterName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SkinFXNotifyStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SkinFXNotifyRetrigger(float CurrentTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SkinFXNotifyKill();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SkinFXNotifyEnd(ESkinFXEffectEndStyle EndStyle, float CurrentTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SkinFXInitialUpdate();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetSkinFXComponent(USkinFXComponent*& RunningSkinFXComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetMyEffectName(FName& MyEffectName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float SkinFXGetEnvelopeValueLinear() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float SkinFXGetEnvelopeValueCurve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetCurrentScalarParameter(FName ParameterName, float& ParameterValue, bool& bParameterFound) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetCurrentParameters(FMaterialSwapParameters& CurrentParameters) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetCurrentColorParameter(FName ParameterName, FLinearColor& ParameterValue, bool& bParameterFound) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SkinFXGetAffectedActor(AActor*& AffectedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SkinFXEventNotify(USkinFXComponent* RunningSkinFXComponent, ESkinFXDelegateEvent Event);
    
    UFUNCTION(BlueprintCallable)
    bool SkinFXApplyParameters();
    
};

