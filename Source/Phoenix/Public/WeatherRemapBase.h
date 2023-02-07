#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeatherRemapBase.generated.h"

class UPhoenixPhysicalMaterial;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UWeatherRemapBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhoenixPhysicalMaterial* RemapPPM;
    
    UWeatherRemapBase();
};

