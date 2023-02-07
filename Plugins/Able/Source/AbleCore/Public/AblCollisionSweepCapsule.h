#pragma once
#include "CoreMinimal.h"
#include "AblCollisionSweepShape.h"
#include "AblCollisionSweepCapsule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionSweepCapsule : public UAblCollisionSweepShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Height;
    
public:
    UAblCollisionSweepCapsule();
};

