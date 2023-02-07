#pragma once
#include "CoreMinimal.h"
#include "BaseStateComponent.h"
#include "ObjectStateData.h"
#include "ObjectStateComponent.generated.h"

class UAkAudioEvent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UObjectStateComponent : public UBaseStateComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectStateData ObjectStateData;
    
public:
    UObjectStateComponent();
    UFUNCTION(BlueprintCallable)
    void SetTargetable(bool bTargetable);
    
    UFUNCTION(BlueprintCallable)
    void SetStartBroken(bool StartBroken);
    
    UFUNCTION(BlueprintCallable)
    void SetNeverAffectNavmesh(bool NeverAffectNavmesh);
    
    UFUNCTION(BlueprintCallable)
    void SetImportant(bool bImportant);
    
    UFUNCTION(BlueprintCallable)
    void SetHitSfx(UAkAudioEvent* InSfx);
    
    UFUNCTION(BlueprintCallable)
    void SetDamageable(bool bDamageable);
    
    UFUNCTION(BlueprintCallable)
    void SetCanHighlight(bool bCanHighlight);
    
    UFUNCTION(BlueprintCallable)
    void SetBaseHealth(float baseHealth);
    
};

