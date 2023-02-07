#pragma once
#include "CoreMinimal.h"
#include "MapLocDataItem.generated.h"

USTRUCT(BlueprintType)
struct FMapLocDataItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ButtonKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocKey;
    
    PHOENIX_API FMapLocDataItem();
};

