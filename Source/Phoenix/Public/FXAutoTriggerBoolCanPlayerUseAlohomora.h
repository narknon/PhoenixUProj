#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBoolLockable.h"
#include "FXAutoTriggerBoolCanPlayerUseAlohomora.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolCanPlayerUseAlohomora : public UFXAutoTriggerBoolLockable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckIfLockedFirst;
    
    UFXAutoTriggerBoolCanPlayerUseAlohomora();
};

