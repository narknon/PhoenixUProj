#pragma once
#include "CoreMinimal.h"
#include "AblCollisionSweepShape.h"
#include "AblCollisionSweepSphere.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionSweepSphere : public UAblCollisionSweepShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_radius;
    
public:
    UAblCollisionSweepSphere();
};

