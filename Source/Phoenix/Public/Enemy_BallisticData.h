#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackSpecificData.h"
#include "Enemy_BallisticData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_BallisticData : public FEnemy_AttackSpecificData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverrideGravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ArcParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DilateMult;
    
    PHOENIX_API FEnemy_BallisticData();
};

