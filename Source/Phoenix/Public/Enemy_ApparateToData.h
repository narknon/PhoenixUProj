#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackApparateMode.h"
#include "Enemy_AttackSpecificData.h"
#include "Templates/SubclassOf.h"
#include "Enemy_ApparateToData.generated.h"

class UAblAbility;

USTRUCT(BlueprintType)
struct FEnemy_ApparateToData : public FEnemy_AttackSpecificData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AttackApparateMode ApparateMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetZDist;
    
    PHOENIX_API FEnemy_ApparateToData();
};

