#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "UablResetReset_ClothingTeleportMode.h"
#include "ablClothResetTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablClothResetTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UablResetReset_ClothingTeleportMode ClothTeleportMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExecuteOnStart;
    
public:
    UablClothResetTask();
};

