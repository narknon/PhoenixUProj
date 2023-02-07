#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBoolLockable.h"
#include "FXAutoTriggerBoolCanPlayerOpenLockable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolCanPlayerOpenLockable : public UFXAutoTriggerBoolLockable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckIfLockedFirst;
    
    UFXAutoTriggerBoolCanPlayerOpenLockable();
};

