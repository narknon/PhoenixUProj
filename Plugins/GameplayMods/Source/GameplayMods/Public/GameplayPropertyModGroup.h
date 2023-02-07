#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayPropertyModGroup.generated.h"

class UGameplayPropertyMod;
class UObject;

UCLASS(Blueprintable)
class UGameplayPropertyModGroup : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameplayPropertyMod*> Modifiers;
    
    UGameplayPropertyModGroup();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRemoved(UObject* TargetObject) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAdded(UObject* TargetObject) const;
    
};

