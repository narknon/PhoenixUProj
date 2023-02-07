#pragma once
#include "CoreMinimal.h"
#include "AblCollisionShape.h"
#include "AblCollisionShapeCapsule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCollisionShapeCapsule : public UAblCollisionShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_radius;
    
public:
    UAblCollisionShapeCapsule();
};

