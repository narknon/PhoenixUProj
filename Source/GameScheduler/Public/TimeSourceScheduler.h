#pragma once
#include "CoreMinimal.h"
#include "TimeSourceVolume.h"
#include "TimeSourceScheduler.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GAMESCHEDULER_API UTimeSourceScheduler : public UTimeSourceVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisable;
    
    UTimeSourceScheduler();
};

