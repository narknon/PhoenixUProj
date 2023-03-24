#pragma once
#include "CoreMinimal.h"
#include "MaterialPreLoadKeysActor.h"
#include "MaterialPreLoadKeysAllActor.generated.h"

UCLASS(Blueprintable)
class AMaterialPreLoadKeysAllActor : public AMaterialPreLoadKeysActor {
    GENERATED_BODY()
public:
    AMaterialPreLoadKeysAllActor(const FObjectInitializer& ObjectInitializer);
};

