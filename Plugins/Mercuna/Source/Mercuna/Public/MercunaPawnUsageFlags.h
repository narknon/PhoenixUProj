#pragma once
#include "CoreMinimal.h"
#include "MercunaNavUsageTypes.h"
#include "MercunaPawnUsageFlags.generated.h"

USTRUCT(BlueprintType)
struct MERCUNA_API FMercunaPawnUsageFlags {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaNavUsageTypes RequiredUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaNavUsageTypes AllowedUsageFlags;
    
    FMercunaPawnUsageFlags();
};

