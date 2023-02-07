#pragma once
#include "CoreMinimal.h"
#include "MunitionToInstigatorData.h"
#include "RPGAbilityCustomTargetEventListener.h"
#include "Templates/SubclassOf.h"
#include "RPGAbilityEventListener_OnTargetHitWithMunition.generated.h"

class AMunitionType_Base;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnTargetHitWithMunition : public URPGAbilityCustomTargetEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> MunitionTypeFilter;
    
public:
    URPGAbilityEventListener_OnTargetHitWithMunition();
protected:
    UFUNCTION(BlueprintCallable)
    void OnMunitionHit(const UObject* Caller, const FMunitionToInstigatorData& MunitionData);
    
};

