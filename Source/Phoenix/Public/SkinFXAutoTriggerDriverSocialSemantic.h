#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkinFXAutoTriggerDriver.h"
#include "SkinFXAutoTriggerEffectInfo.h"
#include "SocialSemanticIDs.h"
#include "SkinFXAutoTriggerDriverSocialSemantic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXAutoTriggerDriverSocialSemantic : public USkinFXAutoTriggerDriver {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SemanticID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SemanticInputStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D OutputStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SkinFXStrengthParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bZeroNonZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXAutoTriggerEffectInfo EffectInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
public:
    USkinFXAutoTriggerDriverSocialSemantic();
};

