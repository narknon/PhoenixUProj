#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LightMobilityManager.generated.h"

class UWorld;

UCLASS(Blueprintable, Transient)
class LIGHTCULLING_API ULightMobilityManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoManageMobility;
    
public:
    ULightMobilityManager();
};

