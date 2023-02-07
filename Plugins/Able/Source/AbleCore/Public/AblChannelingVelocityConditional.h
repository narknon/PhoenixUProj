#pragma once
#include "CoreMinimal.h"
#include "AblChannelingBase.h"
#include "AblChannelingVelocityConditional.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblChannelingVelocityConditional : public UAblChannelingBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_VelocityThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_UseXYSpeed;
    
public:
    UAblChannelingVelocityConditional();
};

