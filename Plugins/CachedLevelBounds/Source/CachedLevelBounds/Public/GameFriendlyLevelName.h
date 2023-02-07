#pragma once
#include "CoreMinimal.h"
#include "GameFriendlyLevelName.generated.h"

USTRUCT(BlueprintType)
struct CACHEDLEVELBOUNDS_API FGameFriendlyLevelName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RawName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GameFriendlyName;
    
    FGameFriendlyLevelName();
};

