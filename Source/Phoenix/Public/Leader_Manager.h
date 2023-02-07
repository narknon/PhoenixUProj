#pragma once
#include "CoreMinimal.h"
#include "Enemy_Manager.h"
#include "Leader_Manager.generated.h"

UCLASS(Blueprintable)
class ULeader_Manager : public UEnemy_Manager {
    GENERATED_BODY()
public:
    ULeader_Manager();
};

