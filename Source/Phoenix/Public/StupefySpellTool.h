#pragma once
#include "CoreMinimal.h"
#include "FireOnceThrowSpellTool.h"
#include "Templates/SubclassOf.h"
#include "StupefySpellTool.generated.h"

class AMunitionType_Base;

UCLASS(Blueprintable)
class AStupefySpellTool : public AFireOnceThrowSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> AOEMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterDurationScaleTalent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterDamageTalent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool KillAuthorityFigure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> UpgradedMunitionActor;
    
    AStupefySpellTool();
};

