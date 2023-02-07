#pragma once
#include "CoreMinimal.h"
#include "AblCollisionShape.h"
#include "AblCollisionShapeSphere.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCollisionShapeSphere : public UAblCollisionShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_radius;
    
public:
    UAblCollisionShapeSphere();
};

