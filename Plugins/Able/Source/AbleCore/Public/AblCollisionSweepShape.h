#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "AblAbilityTargetTypeLocation.h"
#include "AblCollisionSweepShape.generated.h"

UCLASS(Abstract, Blueprintable)
class ABLECORE_API UAblCollisionSweepShape : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblAbilityTargetTypeLocation m_SweepLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> m_CollisionChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_OnlyReturnBlockingHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_UseAsyncQuery;
    
public:
    UAblCollisionSweepShape();
};

