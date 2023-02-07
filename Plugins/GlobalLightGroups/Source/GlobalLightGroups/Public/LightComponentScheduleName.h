#pragma once
#include "CoreMinimal.h"
#include "LightComponentScheduleName.generated.h"

USTRUCT(BlueprintType)
struct FLightComponentScheduleName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    GLOBALLIGHTGROUPS_API FLightComponentScheduleName();
};

