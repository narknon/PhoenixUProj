#pragma once
#include "CoreMinimal.h"
#include "AnimateProperty_PropertyName.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FAnimateProperty_PropertyName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FAnimateProperty_PropertyName();
};

