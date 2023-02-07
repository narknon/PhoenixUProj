#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SocialAgent.generated.h"

USTRUCT(BlueprintType)
struct SOCIALDISPLAY_API FSocialAgent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_alertOnApproach;
    
public:
    FSocialAgent();
};

