#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DecalPointLightInfo.h"
#include "PointLightDecalLibrary.generated.h"

class UPointLightComponent;

UCLASS(Blueprintable)
class FXUTIL_API UPointLightDecalLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPointLightDecalLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDecalPointLightInfo MakeDecalPointLightInfo(UPointLightComponent* PointLightComponent);
    
};

