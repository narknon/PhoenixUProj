#pragma once
#include "CoreMinimal.h"
#include "EMapLocTypes.h"
#include "MapLocItem.generated.h"

USTRUCT(BlueprintType)
struct FMapLocItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMapLocTypes::Type> MapAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ButtonKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocKey;
    
    PHOENIX_API FMapLocItem();
};

