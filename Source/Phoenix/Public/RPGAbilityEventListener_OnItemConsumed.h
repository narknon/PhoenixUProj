#pragma once
#include "CoreMinimal.h"
#include "ItemFilter.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnItemConsumed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnItemConsumed : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseItemTypeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemFilter ItemTypeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseItemUsageTypeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemFilter ItemUsageTypeFilter;
    
public:
    URPGAbilityEventListener_OnItemConsumed();
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemConsumed(FName CharacterID, FName ItemId, FName Variation, FName ItemType, FName ItemUsageType);
    
};

