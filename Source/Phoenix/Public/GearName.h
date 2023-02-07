#pragma once
#include "CoreMinimal.h"
#include "GearName.generated.h"

USTRUCT(BlueprintType)
struct FGearName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FGearName();
};
FORCEINLINE uint32 GetTypeHash(const FGearName) { return 0; }

