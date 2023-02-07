#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_MotionTableEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_MotionTableEvent : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UAnimNotify_MotionTableEvent();
};

