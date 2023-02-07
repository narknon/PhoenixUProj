#pragma once
#include "CoreMinimal.h"
#include "AblCollisionShape.h"
#include "AblCollisionShapeCone.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCollisionShapeCone : public UAblCollisionShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Is2DQuery;
    
public:
    UAblCollisionShapeCone();
};

