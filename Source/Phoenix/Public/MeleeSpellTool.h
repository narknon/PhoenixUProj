#pragma once
#include "CoreMinimal.h"
#include "SpellTool.h"
#include "MeleeSpellTool.generated.h"

UCLASS(Blueprintable)
class AMeleeSpellTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeHalfAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HitMultipleTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OnlyAffectCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CastAtTarget;
    
    AMeleeSpellTool(const FObjectInitializer& ObjectInitializer);
};

