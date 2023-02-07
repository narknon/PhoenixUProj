#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AdaptationOverrideInterface.h"
#include "EEmissiveAdaptationOverrideState.h"
#include "EmissiveAdaptationOverrideComponent.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEmissiveAdaptationOverrideComponent : public UActorComponent, public IAdaptationOverrideInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SustainTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInfiniteSustain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePriority;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StateStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EEmissiveAdaptationOverrideState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bRegisteredAdaptationInterface;
    
public:
    UEmissiveAdaptationOverrideComponent();
    UFUNCTION(BlueprintCallable)
    void SetState(EEmissiveAdaptationOverrideState NewState);
    
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetState(EEmissiveAdaptationOverrideState& CurrentState) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

