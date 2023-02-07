#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EWandCastType.h"
#include "FrameToContexts.h"
#include "ablWandCastContextsTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablWandCastContextsTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<EWandCastType::Type>, FFrameToContexts> WandCastTypeToContextMap;
    
public:
    UablWandCastContextsTask();
};

