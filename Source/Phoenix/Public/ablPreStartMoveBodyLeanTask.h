#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablPreStartMoveBodyLeanTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablPreStartMoveBodyLeanTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PlayOnChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* BodyLeanAbilityClass;
    
public:
    UablPreStartMoveBodyLeanTask();
};

