#pragma once
#include "CoreMinimal.h"
#include "DB_Character.h"
#include "PillarPlaque_Character.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API APillarPlaque_Character : public ADB_Character {
    GENERATED_BODY()
public:
    APillarPlaque_Character(const FObjectInitializer& ObjectInitializer);
};

