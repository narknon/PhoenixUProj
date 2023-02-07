#pragma once
#include "CoreMinimal.h"
#include "Enemy_Manager.h"
#include "Companion_Manager.generated.h"

UCLASS(Blueprintable)
class UCompanion_Manager : public UEnemy_Manager {
    GENERATED_BODY()
public:
    UCompanion_Manager();
};

