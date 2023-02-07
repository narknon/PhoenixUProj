#pragma once
#include "CoreMinimal.h"
#include "SetProperty_PropertyName.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSetProperty_PropertyName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSetProperty_PropertyName();
};

