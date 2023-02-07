#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackGroup.h"
#include "NPC_Manager.h"
#include "Enemy_Manager.generated.h"

UCLASS(Blueprintable)
class UEnemy_Manager : public UNPC_Manager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_AttackGroup> AttackGroupList;
    
public:
    UEnemy_Manager();
};

