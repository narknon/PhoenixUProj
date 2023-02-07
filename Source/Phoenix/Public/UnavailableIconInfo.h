#pragma once
#include "CoreMinimal.h"
#include "UnavailableIconInfo.generated.h"

USTRUCT(BlueprintType)
struct FUnavailableIconInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IconAssetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LockId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DescTextKey;
    
    PHOENIX_API FUnavailableIconInfo();
};

