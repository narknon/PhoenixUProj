#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LightOnOffFX.h"
#include "LightOnOffFXList.generated.h"

UCLASS(Blueprintable)
class ULightOnOffFXList : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLightOnOffFX> FXList;
    
    ULightOnOffFXList();
};

