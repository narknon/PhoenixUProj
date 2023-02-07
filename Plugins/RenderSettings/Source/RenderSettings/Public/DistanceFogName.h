#pragma once
#include "CoreMinimal.h"
#include "DistanceFogName.generated.h"

USTRUCT(BlueprintType)
struct FDistanceFogName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FDistanceFogName();
};

