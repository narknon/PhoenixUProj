#pragma once
#include "CoreMinimal.h"
#include "StaticVendorEntry.generated.h"

USTRUCT(BlueprintType)
struct FStaticVendorEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableBeacon;
    
    PHOENIX_API FStaticVendorEntry();
};

