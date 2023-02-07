#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CloudDefinitions.generated.h"

class UCloudParams;

UCLASS(Blueprintable)
class WEATHER_API UCloudDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCloudParams*> Definitions;
    
    UCloudDefinitions();
};

