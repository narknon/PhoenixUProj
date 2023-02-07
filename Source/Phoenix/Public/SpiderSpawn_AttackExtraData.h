#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackExtraData.h"
#include "SpiderSpawn_AttackExtraData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpiderSpawn_AttackExtraData : public UEnemy_AttackExtraData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinToAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnEligibleWaitTime;
    
    USpiderSpawn_AttackExtraData();
};

