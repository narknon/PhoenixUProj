#pragma once
#include "CoreMinimal.h"
#include "SimpleBoneInfo.h"
#include "SimpleBoneInfoCache.generated.h"

USTRUCT(BlueprintType)
struct FSimpleBoneInfoCache {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FSimpleBoneInfo> BoneCache;
    
public:
    PHOENIX_API FSimpleBoneInfoCache();
};

