#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModDrivers.h"
#include "GlobalLightRigWorldModDrivers.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FGlobalLightRigWorldModDrivers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightRigModDrivers Defaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, FGlobalLightRigModDrivers> WorldMap;
    
    GLOBALLIGHTRIG_API FGlobalLightRigWorldModDrivers();
};

