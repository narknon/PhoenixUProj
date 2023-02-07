#pragma once
#include "CoreMinimal.h"
#include "AblTargetingBase.h"
#include "AblTargetingCone.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTargetingCone : public UAblTargetingBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_2DQuery;
    
public:
    UAblTargetingCone();
};

