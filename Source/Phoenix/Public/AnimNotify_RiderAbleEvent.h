#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_RiderAbleEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_RiderAbleEvent : public UAnimNotify {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
public:
    UAnimNotify_RiderAbleEvent();
};

