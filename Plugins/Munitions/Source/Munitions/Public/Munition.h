#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Munition.generated.h"

UCLASS(Abstract, Blueprintable, MinimalAPI)
class UMunition : public UDataAsset {
    GENERATED_BODY()
public:
    UMunition();
};

