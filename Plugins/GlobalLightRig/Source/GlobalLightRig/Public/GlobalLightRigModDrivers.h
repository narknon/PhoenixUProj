#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModDrivers.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightRigModDrivers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> ModDrivers;
    
    GLOBALLIGHTRIG_API FGlobalLightRigModDrivers();
};

