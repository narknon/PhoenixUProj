#pragma once
#include "CoreMinimal.h"
#include "CharacterStateInfo.h"
#include "BipedStateInfo.generated.h"

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API UBipedStateInfo : public UCharacterStateInfo {
    GENERATED_BODY()
public:
    UBipedStateInfo();
};

